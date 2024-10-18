/*
 * Copyright 2023 - 2024 Watech Electronics
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/*!
 * \file   HS32F7D377_usb.h
 * \brief  HS32F7D377 USB register file
 * \version Windows demo, not used svn
 */

#ifndef HS32F7D377_USB_H
#define HS32F7D377_USB_H

/*!
 * \addtogroup   HS32F7D377_USB_REGISTER HS32F7D377 USB Register
 * \ingroup HS32F7D377_REGISTER
 *
 * \brief  USB register layout, bitfield and address definitions
 *
 * @{
 */

/* clang-format off */

/*!
 * \name USB Register Layout
 *
 *
 * @{
 */

/*! \brief USB register layout */
typedef struct {
    union
    {
       __IOM uint32_t GOTGCTL;  /*!< 0x00000000 */ 
       
       struct
       {
                uint32_t RSV_0                     : 2 ;     /*!< [1:0] : reserved */
          __IOM uint32_t VBVALID_OV_EN             : 1 ;     /*!< [2:2] : Mode: Host only VBUS Valid Override Enable (VbvalidOvEn) This bit is used to enable/disable the software to override the  Bvalid signal using the GOTGCTL.VbvalidOvVal. <br><li> 1'b1 : Internally Bvalid received from the PHY is  overridden with GOTGCTL.VbvalidOvVal. <br><li> 1'b0 : Override is disabled and bvalid signal from the  respective PHY selected is used internally by the controller. Values:  <br><li> 0x0 (DISABLED): Override is disabled and bvalid signal  from the respective PHY selected is used internally by the controller <br><li> 0x1 (ENABLED): The vbus-valid signal received from the  PHY is overridden with GOTGCTL.VbvalidOvVal Value After Reset: * Varies based on Configuration */
          __IOM uint32_t VBVALID_OV_VAL            : 1 ;     /*!< [3:3] : Mode: Host only VBUS Valid OverrideValue (VbvalidOvVal) This bit is used to set Override value for vbusvalid signal  when GOTGCTL.VbvalidOvEn is set. <br><li> 1'b0 : vbusvalid value is 1'b0 when GOTGCTL.VbvalidOvEn =1 <br><li> 1'b1 : vbusvalid value is 1'b1 when GOTGCTL.VbvalidOvEn =1 Values:  <br><li> 0x0 (SET0): vbusvalid value when GOTGCTL.VbvalidOvEn = 1 <br><li> 0x1 (SET1): vbusvalid value when GOTGCTL.VbvalidOvEn is 1 Value After Reset: * Varies based on Configuration */
          __IOM uint32_t AVALID_OV_EN              : 1 ;     /*!< [4:4] : Mode: Host only A-Peripheral Session Valid Override Enable (AvalidOvEn) This bit is used to enable/disable the software to override the  Avalid signal using the GOTGCTL.AvalidOvVal. <br><li> 1'b1: Internally Avalid received from the PHY is  overridden with GOTGCTL.AvalidOvVal. <br><li> 1'b0: Override is disabled and avalid signal from the  respective PHY selected is used internally by the core Values:  <br><li> 0x0 (DISABLED): Derive AValid from PHY <br><li> 0x1 (ENABLED): Derive Avalid from GOTGCTL.AvalidOvVal Value After Reset: * Varies based on Configuration */
          __IOM uint32_t AVALID_OV_VAL             : 1 ;     /*!< [5:5] : Mode: Host only A-Peripheral Session Valid OverrideValue (AvalidOvVal) This bit is used to set Override value for Avalid signal when  GOTGCTL.AvalidOvEn is set. <br><li> 1'b0 : Avalid value is 1'b0 when GOTGCTL.AvalidOvEn =1 <br><li> 1'b1 : Avalid value is 1'b1 when GOTGCTL.AvalidOvEn =1 Values:  <br><li> 0x0 (VALUE0): Avalid value is 1'b0 when GOTGCTL.AvalidOvEn =1 <br><li> 0x1 (VALUE1): Avalid value is 1'b1 when GOTGCTL.AvalidOvEn =1 Value After Reset: * Varies based on Configuration */
          __IOM uint32_t BVALID_OV_EN              : 1 ;     /*!< [6:6] : Mode: Device only B-Peripheral Session Valid Override Value (BvalidOvEn) This bit is used to enable/disable the software to override the  Bvalid signal using the GOTGCTL.BvalidOvVal.  <br><li> 1'b1 : Internally Bvalid received from the PHY is  overridden with GOTGCTL.BvalidOvVal. <br><li> 1'b0 : Override is disabled and bvalid signal from the  respective PHY selected is used internally by the force Values:  <br><li> 0x0 (DISABLED): Override is disabled and bvalid signal  from the respective PHY selected is used internally by the core <br><li> 0x1 (ENABLED): Internally Bvalid received from the PHY  is overridden with GOTGCTL.BvalidOvVal Value After Reset: * Varies based on Configuration */
          __IOM uint32_t BVALID_OV_VAL             : 1 ;     /*!< [7:7] : Mode: Device only B-Peripheral Session Valid OverrideValue (BvalidOvVal) This bit is used to set Override value for Bvalid signal when  GOTGCTL.BvalidOvEn is set. Values:  <br><li> 0x0 (VALUE0): Bvalid value when GOTGCTL.BvalidOvEn =1 <br><li> 0x1 (VALUE1): Bvalid value when GOTGCTL.BvalidOvEn =1 Value After Reset: * Varies based on Configuration */
                uint32_t RSV_1                     : 8 ;     /*!< [15:8] : reserved */
          __IM  uint32_t CON_ID_STS                : 1 ;     /*!< [16:16] : Mode: Host and Device  Connector ID Status (ConIDSts) Indicates the connector ID status on a connect event. <br><li> 1'b0: The core is in A-Device mode. <br><li> 1'b1: The core is in B-Device mode. Note: The reset value of this register field can be read only  after the PHY clock is stable, or if IDDIG_FILTER is enabled,  wait for the filter timer to expire to read the correct reset  value which ever event is later.  Reset: <br><li> 1'b0: in host only mode (OTG_MODE = 5 or 6) <br><li> 1'b1: in all other configurations Value After Reset: * Varies based on Configuration */
          __IM  uint32_t DBNC_TIME                 : 1 ;     /*!< [17:17] : Mode: Host only  Long/Short Debounce Time (DbncTime) Indicates the debounce time of a detected connection. <br><li> 1'b0: Long debounce time, used for physical connections  (100 ms + 2.5 micro-sec) <br><li> 1'b1: Short debounce time, used for soft connections (2.5 micro-sec) Values:  <br><li> 0x0 (LONG): Long debounce time, used for physical  connections (100 ms + 2.5 micro-sec) <br><li> 0x1 (SHORT): Short debounce time, used for soft  connections (2.5 micro-sec) Value After Reset: * Varies based on Configuration */
          __IM  uint32_t ASES_VLD                  : 1 ;     /*!< [18:18] : Mode: Host only  A-Session Valid (ASesVld) Indicates the Host mode transceiver status. <br><li> 1'b0: A-session is not valid <br><li> 1'b1: A-session is valid Note: If you do not enabled OTG features (such as SRP and  HNP), the read reset value will be 1. The vbus assigns the  values internally for non-SRP or non-HNP configurations. In case of OTG_MODE=0, the reset value of this bit is 1'b0. Values:  <br><li> 0x0 (NOTVALID): A-session is not valid. <br><li> 0x1 (VALID): A-session is valid. Value After Reset: * Varies based on Configuration */
          __IM  uint32_t BSES_VLD                  : 1 ;     /*!< [19:19] : Mode: Device only  B-Session Valid (BSesVld) Indicates the Device mode transceiver status. <br><li> 1'b0: B-session is not valid. <br><li> 1'b1: B-session is valid. In OTG mode, you can use this bit to determine if the device  is connected or disconnected. Note: <br><li> If you do not enable OTG features (such as SRP and  HNP), the read reset value will be 1.The vbus assigns the  values internally for non- SRP or non-HNP configurations.  <br><li> In case of OTG_MODE=0, the reset value of this bit is 1'b0. <br><li> The reset value of this register field can be read only after  the PHY clock is stable, or if IDDIG_FILTER is enabled,  wait for the filter timer to expire to read the correct reset  value which ever event is later. Values:  <br><li> 0x0 (NOTVALID): B-session is not valid. <br><li> 0x1 (VALID): B-session is valid. Value After Reset: * Varies based on Configuration */
          __IOM uint32_t OTG_VER                   : 1 ;     /*!< [20:20] : OTG Version (OTGVer) Indicates the OTG revision. <br><li> 1'b0: OTG Version 1.3. In this version the core supports  Data line pulsing and VBus pulsing for SRP. <br><li> 1'b1: OTG Version 2.0. In this version the core supports  only Data line pulsing for SRP. Value After Reset: * Varies based on Configuration */
          __IM  uint32_t CUR_MOD                   : 1 ;     /*!< [21:21] : Current Mode of Operation (CurMod) Mode: Host and Device Indicates the current mode. <br><li> 1'b0: Device mode <br><li> 1'b1: Host mode Reset: <br><li> 1'b1 in Host-only mode (OTG_MODE=5 or 6) <br><li> 1'b0 in all other configurations Note: The reset value of this register field can be read only  after the PHY clock is stable, or if IDDIG_FILTER is enabled,  wait for the filter timer to expire to read the correct reset  value which ever event is later. Values:  <br><li> 0x0 (DEVICEMODE): Current mode is device mode. <br><li> 0x1 (HOSTMODE): Current mode is host mode. */
                uint32_t RSV_2                     : 10;     /*!< [31:22] : reserved */
       } GOTGCTLb;
    };

    union
    {
       __IOM uint32_t GOTGINT;  /*!< 0x00000004 */ 
       
       struct
       {
                uint32_t RSV_3                     : 2 ;     /*!< [1:0] : reserved */
          __IOM uint32_t SES_END_DET               : 1 ;     /*!< [2:2] : Mode: Host and Device Session End Detected (SesEndDet) The controller sets this bit when the utmiotg_bvalid signal is  deasserted. This bit can be set only by the core and the  application should write 1 to clear it. Values:  <br><li> 0x0 (INACTIVE): Session is Active <br><li> 0x1 (ACTIVE): SessionEnd utmiotg_bvalid signal is deasserted */
                uint32_t RSV_4                     : 5 ;     /*!< [7:3] : reserved */
          __IOM uint32_t SES_REQ_SUC_STS_CHNG      : 1 ;     /*!< [8:8] : Mode: Host and Device Session Request Success Status Change (SesReqSucStsChng) The core sets this bit on the success or failure of a session  request. The application must read the Session Request  Success bit in the OTG Control and Status register  (GOTGCTL.SesReqScs) to check for success or failure. This  bit can be set only by the core and the application should  write 1 to clear it. Values:  <br><li> 0x0 (INACTIVE): No Change in Session Request Status <br><li> 0x1 (ACTIVE): Session Request Status has changed */
          __IOM uint32_t HST_NEG_SUC_STS_CHNG      : 1 ;     /*!< [9:9] : Mode: Host and Device Host Negotiation Success Status Change  (HstNegSucStsChng) The core sets this bit on the success or failure of a USB host  negotiation request. The application must read the Host  Negotiation Success bit of the OTG Control and Status  register (GOTGCTL.HstNegScs) to check for success or  failure. This bit can be set only by the core and the  application should write 1 to clear it. Values:  <br><li> 0x0 (INACTIVE): No Change <br><li> 0x1 (ACTIVE): Host Negotiation Status Change */
                uint32_t RSV_5                     : 7 ;     /*!< [16:10] : reserved */
          __IOM uint32_t HST_NEG_DET               : 1 ;     /*!< [17:17] : Mode:Host and Device Host Negotiation Detected (HstNegDet) The core sets this bit when it detects a host negotiation  request on the USB. This bit can be set only by the core and  the application should write 1 to clear it. Values:  <br><li> 0x0 (INACTIVE): No Active HNP Request <br><li> 0x1 (ACTIVE): Active HNP request detected */
          __IOM uint32_t ADEV_TOUT_CHG             : 1 ;     /*!< [18:18] : Mode: Host and Device A-Device Timeout Change (ADevTOUTChg) The core sets this bit to indicate that the A-device has timed  out while waiting for the B-device to connect.This bit can be  set only by the core and the application should write 1 to clear it. Values:  <br><li> 0x0 (INACTIVE): No A-Device Timeout <br><li> 0x1 (ACTIVE): A-Device Timeout */
          __IOM uint32_t DBNCE_DONE                : 1 ;     /*!< [19:19] : Mode: Host only Debounce Done (DbnceDone) The core sets this bit when the debounce is completed after  the device connect. The application can start driving USB  reset after seeing this interrupt. This bit is only valid when the  HNP Capable or SRP Capable bit is SET in the Core USB  Configuration register (GUSBCFG.HNPCap or  GUSBCFG.SRPCap, respectively). This bit can be set only  by the core and the application should write 1 to clear it. Values:  <br><li> 0x0 (INACTIVE): After Connect waiting for Debounce to complete <br><li> 0x1 (ACTIVE): Debounce completed */
                uint32_t RSV_6                     : 12;     /*!< [31:20] : reserved */
       } GOTGINTb;
    };

    union
    {
       __IOM uint32_t GAHBCFG;  /*!< 0x00000008 */ 
       
       struct
       {
          __IOM uint32_t GLBL_INTR_MSK             : 1 ;     /*!< [0:0] : Mode: Host and device Global Interrupt Mask (GlblIntrMsk) The application uses this bit to mask or unmask the interrupt  line assertion to itself. Irrespective of this bit's setting, the  interrupt status registers are updated by the controller. <br><li> 1'b0: Mask the interrupt assertion to the application. <br><li> 1'b1: Unmask the interrupt assertion to the application. Values:  <br><li> 0x0 (MASK): Mask the interrupt assertion to the application <br><li> 0x1 (NOMASK): Unmask the interrupt assertion to the application. */
          __IOM uint32_t HBST_LEN                  : 4 ;     /*!< [4:1] : Mode: Host and device Burst Length/Type (HBstLen) This field is used in both External and Internal DMA modes.  In External DMA mode, these bits appear on dma_burst[3:0]  ports, which can be used by an external wrapper to interface  the External DMA Controller interface to Synopsys  DW_ahb_dmac or ARM PrimeCell. External DMA Mode defines the DMA burst length in terms of 32-bit words: <br><li> 4'b0000: 1 word <br><li> 4'b0001: 4 words <br><li> 4'b0010: 8 words <br><li> 4'b0011: 16 words <br><li> 4'b0100: 32 words <br><li> 4'b0101: 64 words <br><li> 4'b0110: 128 words <br><li> 4'b0111: 256 words <br><li> Others: Reserved Internal DMA Mode AHB Master burst type: <br><li> 4'b0000 Single <br><li> 4'b0001 INCR <br><li> 4'b0011 INCR4 <br><li> 4'b0101 INCR8 <br><li> 4'b0111 INCR16 <br><li> Others: Reserved Values:  <br><li> 0x0 (WORD1ORSINGLE): 1 word or single <br><li> 0x1 (WORD4ORINCR): 4 words or INCR <br><li> 0x2 (WORD8): 8 words <br><li> 0x3 (WORD16ORINCR4): 16 words or INCR4 <br><li> 0x4 (WORD32): 32 words <br><li> 0x5 (WORD64ORINCR8): 64 words or INCR8 <br><li> 0x6 (WORD128): 128 words <br><li> 0x7 (WORD256ORINCR16): 256 words or INCR16 <br><li> 0x8 (WORDX): Others reserved */
          __IOM uint32_t DMA_EN                    : 1 ;     /*!< [5:5] : Mode: Host and device DMA Enable (DMAEn) This bit is always 0 when Slave-Only mode has been selected. Values:  <br><li> 0x0 (SLAVEMODE): Core operates in Slave mode <br><li> 0x1 (DMAMODE): Core operates in a DMA mode */
                uint32_t RSV_7                     : 1 ;     /*!< [6:6] : reserved */
          __IOM uint32_t NP_TXF_EMP_LVL            : 1 ;     /*!< [7:7] : Mode: Host and device Non-Periodic TxFIFO Empty Level (NPTxFEmpLvl) This bit is used only in Slave mode. In host mode and with  Shared FIFO with device mode, this bit indicates when the  Non-Periodic TxFIFO Empty Interrupt bit in the Core  Interrupt register (GINTSTS.NPTxFEmp) is triggered. With dedicated FIFO in device mode, this bit indicates when  IN endpoint Transmit FIFO empty interrupt  (DIEPINTn.TxFEmp) is triggered. Host mode and with Shared FIFO with device mode: <br><li> 1'b0: GINTSTS.NPTxFEmp interrupt indicates that the  Non-Periodic TxFIFO is half empty <br><li> 1'b1: GINTSTS.NPTxFEmp interrupt indicates that the  Non-Periodic TxFIFO is completely empty  Dedicated FIFO in device mode: <br><li> 1'b0: DIEPINTn.TxFEmp interrupt indicates that the IN  Endpoint TxFIFO is half empty <br><li> 1'b1: DIEPINTn.TxFEmp interrupt indicates that the IN  Endpoint TxFIFO is completely empty Values:  <br><li> 0x0 (HALFEMPTY): DIEPINTn.TxFEmp interrupt  indicates that the Non-Periodic TxFIFO is half empty or  that the IN Endpoint TxFIFO is half empty. <br><li> 0x1 (EMPTY): GINTSTS.NPTxFEmp interrupt indicates  that the Non-Periodic TxFIFO is completely empty or that  the IN Endpoint TxFIFO is completely empty. */
          __IOM uint32_t PTXF_EMP_LVL              : 1 ;     /*!< [8:8] : Mode: Host only Periodic TxFIFO Empty Level (PTxFEmpLvl) Indicates when the Periodic TxFIFO Empty Interrupt bit in  the Core Interrupt register (GINTSTS.PTxFEmp) is  triggered. This bit is used only in Slave mode. <br><li> 1'b0: GINTSTS.PTxFEmp interrupt indicates that the  Periodic TxFIFO is half empty <br><li> 1'b1: GINTSTS.PTxFEmp interrupt indicates that the  Periodic TxFIFO is completely empty Values:  <br><li> 0x0 (HALFEMPTY): GINTSTS.PTxFEmp interrupt  indicates that the Periodic TxFIFO is half empty. <br><li> 0x1 (EMPTY): GINTSTS.PTxFEmp interrupt indicates  that the Periodic TxFIFO is completely empty. */
                uint32_t RSV_8                     : 12;     /*!< [20:9] : reserved */
          __IOM uint32_t REM_MEM_SUPP              : 1 ;     /*!< [21:21] : Mode: Host and Device Remote Memory Support (RemMemSupp) This bit is programmed to enable the functionality to wait for  the system DMA Done Signal for the DMA Write Transfers. <br><li> GAHBCFG.RemMemSupp=1 The int_dma_req output signal is asserted when the DMA  starts write transfer to the external memory. When the  core is done with the Transfers it asserts int_dma_done  signal to flag the completion of DMA writes from the  controller. The core then waits for sys_dma_done signal  from the system to proceed further and complete the  Data Transfer corresponding to a particular Channel/Endpoint.  <br><li> GAHBCFG.RemMemSupp=0 The int_dma_req and int_dma_done signals are not  asserted and the core proceeds with the assertion of the XferComp interrupt as soon as the DMA write transfer is  done at the Core Boundary and it does not wait for the  sys_dma_done signal to complete the DATA transfers. Values:  <br><li> 0x0 (DISABLED): Remote Memory Support Feature disabled <br><li> 0x1 (ENABLED): Remote Memory Support Feature enabled */
          __IOM uint32_t NOTI_ALL_DMA_WRIT         : 1 ;     /*!< [22:22] : Mode: Host and Device Notify All DMA Write Transactions (NotiAllDmaWrit) This bit is programmed to enable the System DMA Done  functionality for all the DMA write Transactions  corresponding to the Channel/Endpoint. This bit is valid only  when GAHBCFG.RemMemSupp is set to 1. <br><li> GAHBCFG.NotiAllDmaWrit = 1 The core asserts int_dma_req for all the DMA write  transactions on the AHB interface along with  int_dma_done, chep_last_transact and chep_number  signal informations. The core waits for sys_dma_done  signal for all the DMA write transactions in order to  complete the transfer of a particular Channel/Endpoint. <br><li> GAHBCFG.NotiAllDmaWrit = 0 The core asserts int_dma_req signal only for the last  transaction of DMA write transfer corresponding to a  particular Channel/Endpoint. Similarly, the core waits for  sys_dma_done signal only for that transaction of DMA  write to complete the transfer of a particular Channel/Endpoint. Values:  <br><li> 0x1 (ALLTRANS): The core asserts int_dma_req for all  the DMA write transactions on the AHB interface along  with int_dma_done, chep_last_transact and  chep_number signal informations. The core waits for  sys_dma_done signal for all the DMA write transactions  in order to complete the transfer of a particular Channel/Endpoint <br><li> 0x0 (LASTTRANS) */
          __IOM uint32_t AHB_SINGLE                : 1 ;     /*!< [23:23] : Mode: Host and Device AHB Single Support (AHBSingle) This bit when programmed supports Single transfers for the  remaining data in a transfer when the core is operating in DMA mode.  <br><li> 1'b0: The remaining data in the transfer is sent using INCR burst size. <br><li> 1'b1: The remaining data in the transfer is sent using Single burst size.  Note: If this feature is enabled, the AHB RETRY and SPLIT  transfers still have INCR burst type. Enable this feature when  the AHB Slave connected to the core does not support INCR  burst (and when Split, and Retry transactions are not being used in the bus). Values:  <br><li> 0x0 (INCRBURST): The remaining data in the transfer is  sent using INCR burst size <br><li> 0x1 (SINGLEBURST): The remaining data in the transfer  is sent using Single burst size */
                uint32_t RSV_9                     : 8 ;     /*!< [31:24] : reserved */
       } GAHBCFGb;
    };

    union
    {
       __IOM uint32_t GUSBCFG;  /*!< 0x0000000c */ 
       
       struct
       {
          __IOM uint32_t TOUT_CAL                  : 3 ;     /*!< [2:0] : Mode: Host and Device HS/FS Timeout Calibration (TOutCal) The number of PHY clocks that the application programs in  this field is added to the high-speed/full-speed interpacket  timeout duration in the core to account for any additional  delays introduced by the PHY. This can be required, because  the delay introduced by the PHY in generating the linestate  condition can vary from one PHY to another. The USB standard timeout value for high-speed operation is  736 to 816 (inclusive) bit times. The USB standard timeout  value for full-speed operation is 16 to 18 (inclusive) bit times.  The application must program this field based on the speed  of enumeration. The number of bit times added per PHY  clock are as follows: High-speed operation: <br><li> One 30-MHz PHY clock = 16 bit times <br><li> One 60-MHz PHY clock = 8 bit times Full-speed operation: <br><li> One 30-MHz PHY clock = 0.4 bit times <br><li> One 60-MHz PHY clock = 0.2 bit times <br><li> One 48-MHz PHY clock = 0.25 bit times Value After Reset: * Varies based on Configuration */
          __IOM uint32_t PHY_IF                    : 1 ;     /*!< [3:3] : Mode: Host and Device PHY Interface (PHYIf) The application uses this bit to configure the core to support  a UTMI+ PHY with an 8- or 16-bit interface. When a ULPI  PHY is chosen, this must be Set to 8-bit mode. <br><li> 1'b0: 8 bits <br><li> 1'b1: 16 bits This bit is writable only If UTMI+ and ULPI were selected.  Otherwise, this bit returns the value for the power-on  interface selected during configuration. Values:  <br><li> 0x0 (BITS8): PHY 8bit Mode <br><li> 0x1 (BITS16): PHY 16bit Mode Value After Reset: * Varies based on Configuration */
                uint32_t RSV_10                    : 1 ;     /*!< [4:4] : reserved */
          __IOM uint32_t FS_INTF                   : 1 ;     /*!< [5:5] : Mode: Host and Device Full-Speed Serial Interface Select (FSIntf) The application uses this bit to select either a unidirectional  or bidirectional USB 1.1 full-speed serial transceiver interface. <br><li> 1'b0: 6-pin unidirectional full-speed serial interface <br><li> 1'b1: 3-pin bidirectional full-speed serial interface If a USB 1.1 Full-Speed Serial Transceiver interface was not  selected, this bit is always 0, with Write Only access. If a  USB 1.1 FS interface was selected, Then the application can  Set this bit to select between the 3- and 6-pin interfaces, and  access is Read and Write. Note: For supporting the new 4-pin bi-directional interface,  you need to select 6-pin unidirectional FS serial mode, and  add an external control to convert it to a 4-pin interface. Values:  <br><li> 0x0 (FS6PIN): 6-pin unidirectional full-speed serial interface <br><li> 0x1 (FS3PIN): 3-pin bidirectional full-speed serial interface Value After Reset: * Varies based on Configuration */
          __IM  uint32_t PHY_SEL                   : 1 ;     /*!< [6:6] : PHYSel Mode: Host and Device USB 2.0 High-Speed PHY or USB 1.1 Full-Speed Serial  Transceiver Select (PHYSel) The application uses this bit to select either a high-speed  UTMI+ or ULPI PHY, or a full-speed transceiver. <br><li> 1'b0: USB 2.0 high-speed UTMI+ or ULPI PHY <br><li> 1'b1: USB 1.1 full-speed serial transceiver If a USB 1.1 Full-Speed Serial Transceiver interface was not  selected in, this bit is always 0, with Write Only access. If a high-speed PHY interface was not selected in, this bit is  always 1, with Write Only access. If both interface types were selected (parameters have non- zero values), the application uses this bit to select which  interface is active, and access is Read and Write. Values:  <br><li> 0x0 (USB20): USB 2.0 high-speed UTMI+ or ULPI PHY is selected <br><li> 0x1 (USB11): USB 1.1 full-speed serial transceiver is selected Value After Reset: * Varies based on Configuration */
                uint32_t RSV_11                    : 3 ;     /*!< [9:7] : reserved */
          __IOM uint32_t USB_TRD_TIM               : 4 ;     /*!< [13:10] : Mode: Device only USB Turnaround Time (USBTrdTim) Sets the turnaround time in PHY clocks. Specifies the  response time for a MAC request to the Packet FIFO  Controller (PFC) to fetch data from the DFIFO (SPRAM).  This must be programmed to  <br><li> 4'h5: When the MAC interface is 16-bit UTMI+ . <br><li> 4'h9: When the MAC interface is 8-bit UTMI+ . Note: The previous values are calculated for the minimum  AHB frequency of 30 MHz. USB turnaround time is critical for  certification where long cables and 5-Hubs are used. If you  need the AHB to run at less than 30 MHz, and if USB  turnaround time is not critical, these bits can be programmed  to a larger value. Values:  <br><li> 0x9 (TURNTIME8BIT): MAC interface is 8-bit UTMI+. <br><li> 0x5 (TURNTIME16BIT): MAC interface is 16-bit UTMI+. Value After Reset: * Varies based on Configuration */
                uint32_t RSV_12                    : 8 ;     /*!< [21:14] : reserved */
          __IM  uint32_t TERM_SEL_DLPULSE          : 1 ;     /*!< [22:22] : Mode: Device only TermSel DLine Pulsing Selection (TermSelDLPulse) This bit selects utmi_termselect to drive data line pulse  during SRP. <br><li> 1'b0: Data line pulsing using utmi_txvalid (Default). <br><li> 1'b1: Data line pulsing using utmi_termsel. Values:  <br><li> 0x0 (TXVALID): Data line pulsing using utmi_txvalid <br><li> 0x1 (TERMSEL): Data line pulsing using utmi_termsel Value After Reset: * Varies based on Configuration */
                uint32_t RSV_13                    : 3 ;     /*!< [25:23] : reserved */
          __IM  uint32_t IC_USB_CAP                : 1 ;     /*!< [26:26] : Mode: Host and Device IC_USB-Capable (IC_USBCap) The application uses this bit to control the core's IC_USB  capabilities. <br><li> 1'b0: IC_USB PHY Interface is not selected. <br><li> 1'b1: IC_USB PHY Interface is selected. This bit is writable only if OTG_ENABLE_IC_USB=1 and  OTG_FSPHY_INTERFACE!=0. The reset value depends on the configuration parameter  OTG_SELECT_IC_USB when OTG_ENABLE_IC_USB = 1.  In all other cases, this bit is set to 1'b0 and the bit is read  only. Values:  <br><li> 0x0 (NOTSELECTED): IC_USB PHY Interface is not  selected <br><li> 0x1 (SELECTED): IC_USB PHY Interface is selected Value After Reset: * Varies based on Configuration */
                uint32_t RSV_14                    : 1 ;     /*!< [27:27] : reserved */
          __IOM uint32_t TX_END_DELAY              : 1 ;     /*!< [28:28] : Mode: Device only Tx End Delay (TxEndDelay) Writing 1'b1 to this bit enables the controller to follow the  TxEndDelay timings as per UTMI+ specification 1.05 section  4.1.5 for opmode signal during remote wakeup.   <br><li> 1'b0 : Normal Mode. <br><li> 1'b1 : Tx End delay. Values:  <br><li> 0x0 (DISABLED): Normal Mode <br><li> 0x1 (ENABLED): Tx End delay Value After Reset: * Varies based on Configuration */
          __IOM uint32_t FORCE_HST_MODE            : 1 ;     /*!< [29:29] : Mode: Host and device Force Host Mode (ForceHstMode) Writing a 1 to this bit forces the core to host mode  irrespective of utmiotg_iddig input pin. <br><li> 1'b0 : Normal Mode. <br><li> 1'b1 : Force Host Mode. After setting the force bit, the application must wait at least  25 ms before the change to take effect. When the simulation  is in scale down mode, waiting for 500 micro sec is sufficient.  This bit is valid only when OTG_MODE = 0, 1 or 2. In all  other cases, this bit reads 0. Values:  <br><li> 0x0 (DISABLED): Normal Mode <br><li> 0x1 (ENABLED): Force Host Mode Value After Reset: * Varies based on Configuration */
          __IOM uint32_t FORCE_DEV_MODE            : 1 ;     /*!< [30:30] : Mode:Host and device Force Device Mode (ForceDevMode) Writing a 1 to this bit forces the controller to device mode  irrespective of utmiotg_iddig input pin. <br><li> 1'b0 : Normal Mode. <br><li> 1'b1 : Force Device Mode. After setting the force bit, the application must wait at least  25 ms before the change to take effect. When the simulation  is in scale down mode, waiting for 500 micro sec is sufficient.  This bit is valid only when OTG_MODE = 0, 1 or 2. In all  other cases, this bit reads 0. Values:  <br><li> 0x0 (DISABLED): Normal Mode <br><li> 0x1 (ENABLED): Force Device Mode Value After Reset: * Varies based on Configuration */
          __OM  uint32_t CORRUPT_TX_PKT            : 1 ;     /*!< [31:31] : Mode: Host and device Corrupt Tx packet (CorruptTxPkt) This bit is for debug purposes only. Never Set this bit to 1.  The application should always write 1'b0 to this bit. Values:  <br><li> 0x0 (NODEBUG): Normal Mode <br><li> 0x1 (DEBUG): Debug Mode Value After Reset: * Varies based on Configuration */
       } GUSBCFGb;
    };

    union
    {
       __IOM uint32_t GRSTCTL;  /*!< 0x00000010 */ 
       
       struct
       {
          __IOM uint32_t CSFT_RST                  : 1 ;     /*!< [0:0] : Mode: Host and Device Core Soft Reset (CSftRst) Resets the hclk and phy_clock domains as follows: <br><li> Clears the interrupts and all the CSR registers except the  following register bits: - PCGCCTL.RstPdwnModule - PCGCCTL.GateHclk - PCGCCTL.PwrClmp - PCGCCTL.StopPPhyLPwrClkSelclk - GUSBCFG.ForceDevMode - GUSBCFG.ForceHstMode - GUSBCFG.PhyLPwrClkSel - GUSBCFG.DDRSel - GUSBCFG.PHYSel - GUSBCFG.FSIntf - GUSBCFG.ULPI_UTMI_Sel - GUSBCFG.PHYIf - GUSBCFG.TxEndDelay - GUSBCFG.TermSelDLPulse - GUSBCFG.ULPIClkSusM - GUSBCFG.ULPIAutoRes - GUSBCFG.ULPIFsLs - G G P I O - GPWRDN - GADPCTL - HCFG.FSLSPclkSel - DCFG.DevSpd - DCTL.SftDiscon <br><li> All module state machines <br><li> All module state machines (except the AHB Slave Unit)  are reset to the IDLE state, and all the transmit FIFOs  and the receive FIFO are flushed. <br><li> Any transactions on the AHB Master are terminated as  soon as possible, after gracefully completing the last data  phase of an AHB transfer. Any transactions on the USB  are terminated immediately. <br><li> When Hibernation or ADP feature is enabled, the PMU  module is not reset by the Core Soft Reset. The application can write to this bit any time it wants to reset  the core. This is a self-clearing bit and the core clears this bit  after all the necessary logic is reset in the core, which can  take several clocks, depending on the current state of the  core. Once this bit is cleared software must wait at least 3  PHY clocks before doing any access to the PHY domain  (synchronization delay). Software must also must check that  bit 31 of this register is 1 (AHB Master is IDLE) before  starting any operation. Typically software reset is used during software development  and also when you dynamically change the PHY selection  bits in the USB configuration registers listed above. When  you change the PHY, the corresponding clock for the PHY is  selected and used in the PHY domain. Once a new clock is  selected, the PHY domain has to be reset for proper operation. Values:  <br><li> 0x0 (NOTACTIVE): No reset <br><li> 0x1 (ACTIVE): Resets hclk and phy_clock domains */
          __IOM uint32_t PIU_FS_SFT_RST            : 1 ;     /*!< [1:1] : Mode: Host and Device PIU FS Dedicated Controller Soft Reset (PIUFSSftRst) Resets the PIU FS Dedicated Controller All module state machines in FS Dedicated Controller of PIU  are reset to the IDLE state. Used to reset the FS Dedicated  controller in PIU in case of any PHY Errors like Loss of  activity or Babble Error resulting in the PHY remaining in RX  state for more than one frame boundary. This is a self clearing bit and core clears this bit after all the  necessary logic is reset in the core. Values:  <br><li> 0x0 (RESET_INACTIVE): No Reset <br><li> 0x1 (RESET_ACTIVE): PIU FS Dedicated Controller Soft Reset */
          __IOM uint32_t FRM_CNTR_RST              : 1 ;     /*!< [2:2] : Mode: Host only Host Frame Counter Reset (FrmCntrRst) The application writes this bit to reset the (micro)Frame  number counter inside the core. When the (micro)Frame  counter is reset, the subsequent SOF sent out by the core  has a (micro)Frame number of 0. When application writes 1 to the bit, it might not be able to  read back the value as it will get cleared by the core in a few clock cycles. Values:  <br><li> 0x0 (NOTACTIVE): No reset <br><li> 0x1 (ACTIVE): Host Frame Counter Reset */
                uint32_t RSV_15                    : 1 ;     /*!< [3:3] : reserved */
          __IOM uint32_t RXF_FLSH                  : 1 ;     /*!< [4:4] : Mode: Host and Device RxFIFO Flush (RxFFlsh) The application can flush the entire RxFIFO using this bit, but  must first ensure that the core is not in the middle of a transaction. The application must only write to this bit after checking that  the controller is neither reading from the RxFIFO nor writing to the RxFIFO. The application must wait until the bit is cleared before  performing any other operations. This bit requires eight  clocks (slowest of PHY or AHB clock) to clear. Values:  <br><li> 0x0 (INACTIVE): Does not flush the entire RxFIFO <br><li> 0x1 (ACTIVE): Flushes the entire RxFIFO */
          __IOM uint32_t TXF_FLSH                  : 1 ;     /*!< [5:5] : Mode: Host and Device TxFIFO Flush (TxFFlsh) This bit selectively flushes a single or all transmit FIFOs, but  cannot do so If the core is in the midst of a transaction. The application must write this bit only after checking that the  core is neither writing to the TxFIFO nor reading from the TxFIFO. Verify using these registers: <br><li> ReadNAK Effective Interrupt ensures the core is not  reading from the FIFO <br><li> WriteGRSTCTL.AHBIdle ensures the core is not writing  anything to the FIFO. Flushing is normally recommended when FIFOs are  reconfigured or when switching between Shared FIFO and  Dedicated Transmit FIFO operation. FIFO flushing is also  recommended during device endpoint disable. The  application must wait until the core clears this bit before  performing any operations. This bit takes eight clocks to  clear, using the slower clock of phy_clk or hclk. Values:  <br><li> 0x0 (INACTIVE): No Flush <br><li> 0x1 (ACTIVE): Selectively flushes a single or all transmit FIFOs */
          __IOM uint32_t TXF_NUM                   : 5 ;     /*!< [10:6] : Mode: Host and Device TxFIFO Number (TxFNum) This is the FIFO number that must be flushed using the  TxFIFO Flush bit. This field must not be changed until the  core clears the TxFIFO Flush bit. <br><li> 5'h0: - Non-periodic TxFIFO flush in Host mode - Non-periodic TxFIFO flush in device mode when in shared FIFO operation - Tx FIFO 0 flush in device mode when in dedicated FIFO mode <br><li> 5'h1: - Periodic TxFIFO flush in Host mode  - Periodic TxFIFO 1 flush in Device mode when in shared FIFO operation - TXFIFO 1 flush in device mode when in dedicated FIFO mode <br><li> 5'h2: - Periodic TxFIFO 2 flush in Device mode when in shared FIFO operation - TXFIFO 2 flush in device mode when in dedicated FIFO mode ... <br><li> 5'hF - Periodic TxFIFO 15 flush in Device mode when in shared FIFO operation - TXFIFO 15 flush in device mode when in dedicated FIFO mode <br><li> 5'h10: Flush all the transmit FIFOs in device or host mode */
                uint32_t RSV_16                    : 19;     /*!< [29:11] : reserved */
          __IM  uint32_t DMA_REQ                   : 1 ;     /*!< [30:30] : Mode: Host and Device DMA Request Signal (DMAReq) Indicates that the DMA request is in progress. Used for debug. Values:  <br><li> 0x0 (INACTIVE): No DMA request <br><li> 0x1 (ACTIVE): DMA request is in progress */
          __IM  uint32_t AHB_IDLE                  : 1 ;     /*!< [31:31] : Mode: Host and Device AHB Master Idle (AHBIdle) Indicates that the AHB Master State Machine is in the IDLE condition. Values:  <br><li> 0x0 (INACTIVE): Not Idle <br><li> 0x1 (ACTIVE): AHB Master Idle */
       } GRSTCTLb;
    };

    union
    {
       __IOM uint32_t GINTSTS;  /*!< 0x00000014 */ 
       
       struct
       {
          __IM  uint32_t GIN_TSTS_CUR_MOD          : 1 ;     /*!< [0:0] : Mode: Host and Device           Current Mode of Operation (CurMod)  Indicates the current mode.  <br><li> 1'b0: Device mode  <br><li> 1'b1: Host mode   Note: The reset value of this register field can be read only  after the PHY clock is stable, or if IDDIG_FILTER is enabled,  wait for the filter timer to expire to read the correct reset  value which ever event is later.  Values:  <br><li> 0x0 (DEVICE): Device mode <br><li> 0x1 (HOST): Host mode Value After Reset: * Varies based on Configuration */
          __IOM uint32_t MODE_MIS                  : 1 ;     /*!< [1:1] : Mode: Host and Device           Mode Mismatch Interrupt (ModeMis) The core sets this bit when the application is trying to access: <br><li> A Host mode register, when the controller is operating in Device mode <br><li> A Device mode register, when the controller is operating in Host mode The register access is completed on the AHB with an OKAY  response, but is ignored by the controller internally and does  not affect the operation of the controller. This bit can be set only by the core and the application  should write 1 to clear it. Values:  <br><li> 0x0 (INACTIVE): No Mode Mismatch Interrupt <br><li> 0x1 (ACTIVE): Mode Mismatch Interrupt Value After Reset: * Varies based on Configuration */
          __IM  uint32_t OTG_INT                   : 1 ;     /*!< [2:2] : Mode: Host and Device   OTG Interrupt (OTGInt)  The controller sets this bit to indicate an OTG protocol event.  The application must read the OTG Interrupt Status  (GOTGINT) register to determine the exact event that  caused this interrupt. The application must clear the  appropriate status bit in the GOTGINT register to clear this bit. Values:  <br><li> 0x0 (INACTIVE): No Interrupt <br><li> 0x1 (ACTIVE): OTG Interrupt Value After Reset: * Varies based on Configuration */
          __IOM uint32_t SOF                       : 1 ;     /*!< [3:3] : Mode: Host and Device   Start of (micro)Frame (Sof) In Host mode, the core sets this bit to indicate that an SOF  (FS), micro-SOF (HS), or Keep-Alive (LS) is transmitted on  the USB. The application must write a 1 to this bit to clear the interrupt. In Device mode, the controller sets this bit to indicate that an  SOF token has been received on the USB. The application  can read the Device Status register to get the current  (micro)Frame number. This interrupt is seen only when the  core is operating at either HS or FS. This bit can be set only  by the core and the application must write 1 to clear it. Note: This register may return 1'b1 if read immediately after  power-on reset. If the register bit reads 1'b1 immediately  after power-on reset, it does not indicate that an SOF has  been sent (in case of host mode) or SOF has been received  (in case of device mode). The read value of this interrupt is  valid only after a valid connection between host and device is  established. If the bit is set after power on reset the  application can clear the bit. Values:  <br><li> 0x0 (INTACTIVE): No Start of Frame <br><li> 0x1 (ACTIVE): Start of Frame Value After Reset: * Varies based on Configuration */
          __IM  uint32_t RXF_LVL                   : 1 ;     /*!< [4:4] : Mode: Host and Device   RxFIFO Non-Empty (RxFLvl) Indicates that there is at least one packet pending to be read from the RxFIFO. Values:  <br><li> 0x0 (INACTIVE): Rx Fifo is empty <br><li> 0x1 (ACTIVE): Rx Fifo is not empty Value After Reset: * Varies based on Configuration */
          __IM  uint32_t NP_TXF_EMP                : 1 ;     /*!< [5:5] : Mode: Host and Device   Non-periodic TxFIFO Empty (NPTxFEmp)  This interrupt is asserted when the Non-periodic TxFIFO is  either half or completely empty, and there is space for at  least one Entry to be written to the Non-periodic Transmit  Request Queue. The half or completely empty status is  determined by the Non-periodic TxFIFO Empty Level bit in  the Core AHB Configuration register  (GAHBCFG.NPTxFEmpLvl). In host mode, the application can use GINTSTS.NPTxFEmp  with the OTG_EN_DED_TX_FIFO parameter set to either 1 or 0. In device mode, the application uses GINTSTS.NPTxFEmp  when OTG_EN_DED_TX_FIFO=0. When  OTG_EN_DED_TX_FIFO=1, the application uses DIEPINTn.TxFEmp. Values:  <br><li> 0x0 (INACTIVE): Non-periodic TxFIFO is not empty <br><li> 0x1 (ACTIVE): Non-periodic TxFIFO is empty Value After Reset: * Varies based on Configuration */
          __IM  uint32_t GIN_NAK_EFF               : 1 ;     /*!< [6:6] : Mode: Device only       Global IN Non-periodic NAK Effective (GINNakEff)  Indicates that the Set Global Non-periodic IN NAK bit in the  Device Control register (DCTL.SGNPInNak) set by the  application, has taken effect in the core. That is, the core has  sampled the Global IN NAK bit Set by the application. This  bit can be cleared by clearing the Clear Global Non-periodic  IN NAK bit in the Device Control register  (DCTL.CGNPInNak). This interrupt does not necessarily  mean that a NAK handshake is sent out on the USB. The  STALL bit takes precedence over the NAK bit. Values:  <br><li> 0x0 (INACTIVE): Global Non-periodic IN NAK not active <br><li> 0x1 (ACTIVE): Set Global Non-periodic IN NAK bit Value After Reset: * Varies based on Configuration */
          __IM  uint32_t GOUT_NAK_EFF              : 1 ;     /*!< [7:7] : Mode: Device only       Global OUT NAK Effective (GOUTNakEff)  Indicates that the Set Global OUT NAK bit in the Device  Control register (DCTL.SGOUTNak), Set by the application,  has taken effect in the core. This bit can be cleared by writing  the Clear Global OUT NAK bit in the Device Control register (DCTL.CGOUTNak). Values:  <br><li> 0x0 (INACTIVE): Not Active  <br><li> 0x1 (ACTIVE): Global OUT NAK Effective  Value After Reset: * Varies based on Configuration */
                uint32_t RSV_17                    : 2 ;     /*!< [9:8] : reserved */
          __IOM uint32_t ERLY_SUSP                 : 1 ;     /*!< [10:10] : Mode: Device only       Early Suspend (ErlySusp)  The controller sets this bit to indicate that an Idle state has  been detected on the USB for 3 ms. Values:  <br><li> 0x0 (INACTIVE): No Idle state detected <br><li> 0x1 (ACTIVE): 3ms of Idle state detected Value After Reset: * Varies based on Configuration */
          __IOM uint32_t USB_SUSP                  : 1 ;     /*!< [11:11] : Mode: Device only       USB Suspend (USBSusp)  The controller sets this bit to indicate that a suspend was  detected on the USB. The controller enters the Suspended  state when there is no activity on the linestate signal for an  extended period of time. Values:  <br><li> 0x0 (INACTIVE): Not Active <br><li> 0x1 (ACTIVE): USB Suspend Value After Reset: * Varies based on Configuration */
          __IOM uint32_t USB_RST                   : 1 ;     /*!< [12:12] : Mode: Device only       USB Reset (USBRst)  The controller sets this bit to indicate that a reset is detected on the USB. Values:  <br><li> 0x0 (INACTIVE): Not active <br><li> 0x1 (ACTIVE): USB Reset Value After Reset: * Varies based on Configuration */
          __IOM uint32_t ENUM_DONE                 : 1 ;     /*!< [13:13] : Mode: Device only  Enumeration Done (EnumDone)  The core sets this bit to indicate that speed enumeration is  complete. The application must read the Device Status  (DSTS) register to obtain the enumerated speed. Values:  <br><li> 0x0 (INACTIVE): Not active <br><li> 0x1 (ACTIVE): Enumeration Done Value After Reset: * Varies based on Configuration */
          __IOM uint32_t ISO_OUT_DROP              : 1 ;     /*!< [14:14] : Mode: Device only  Isochronous OUT Packet Dropped Interrupt (ISOOutDrop)  The controller sets this bit when it fails to write an  isochronous OUT packet into the RxFIFO because the  RxFIFO does not have enough space to accommodate a  maximum packet size packet for the isochronous OUT endpoint.  Values:  <br><li> 0x0 (INACTIVE): Not active  <br><li> 0x1 (ACTIVE): Isochronous OUT Packet Dropped Interrupt Value After Reset: * Varies based on Configuration */
          __IOM uint32_t EOPF                      : 1 ;     /*!< [15:15] : Mode: Device only End of Periodic Frame Interrupt (EOPF) Indicates that the period specified in the Periodic Frame  Interval field of the Device Configuration register  (DCFG.PerFrInt) has been reached in the current  microframe. In case of Non-Ignore Frame Number  Scatter/Gather (Descriptor DMA) mode, the controller  internally handles the following scenarios based on EOPF:  Read Flush: At the EOPF, the controller checks if there are  any pending packets in the FIFO corresponding to the  current (micro)Frame.  <br><li> If there are any pending packets, then the controller  initiates read flush, due to which the read pointer is  updated to the starting location of the next micro-frame packet.  <br><li> If there are no pending packets corresponding to the  current (micro)Frame, the controller does not take any action. Write Flush: At the EOPF, if the controller is still fetching the  current micro-frame data, then the controller stops pushing  data into the TXFIFO but keeps fetching the complete packet  from the System Memory. After completing the scheduled  packet size fetch, the controller updates the Status Quadlet  Fields (Transmit Status to BUFFLUSH) and closes the  Descriptor.  During the descriptor close, the controller  initiates write flush, due to which the write pointer is updated  to the starting location of the next micro-frame packet.  Because the controller stops pushing the packet to the  TxFIFO after EOPF, to bring the write pointer to the starting  location of the next micro-frame, write flush is done. Values:  <br><li> 0x0 (INACTIVE): Not active <br><li> 0x1 (ACTIVE): End of Periodic Frame Interrupt Value After Reset: * Varies based on Configuration */
                uint32_t RSV_18                    : 1 ;     /*!< [16:16] : reserved */
          __IOM uint32_t EP_MIS                    : 1 ;     /*!< [17:17] : Mode: Device only Endpoint Mismatch Interrupt (EPMis) Note: This interrupt is valid only in shared FIFO operation. Indicates that an IN token has been received for a non- periodic endpoint, but the data for another endpoint is  present in the top of the Non-periodic Transmit FIFO and the  IN endpoint mismatch count programmed by the application has expired. Values:  <br><li> 0x0 (INACTIVE): Not active <br><li> 0x1 (ACTIVE): Endpoint Mismatch Interrupt Value After Reset: * Varies based on Configuration */
          __IM  uint32_t IEP_INT                   : 1 ;     /*!< [18:18] : Mode: Device only IN Endpoints Interrupt (IEPInt) The core sets this bit to indicate that an interrupt is pending  on one of the IN endpoints of the core (in Device mode). The  application must read the Device All Endpoints Interrupt  (DAINT) register to determine the exact number of the IN  endpoint on Device IN Endpoint-n Interrupt (DIEPINTn)  register to determine the exact cause of the interrupt. The  application must clear the appropriate status bit in the  corresponding DIEPINTn register to clear this bit. Values:  <br><li> 0x0 (INACTIVE): Not active <br><li> 0x1 (ACTIVE): IN Endpoints Interrupt Value After Reset: * Varies based on Configuration */
          __IM  uint32_t OEP_INT                   : 1 ;     /*!< [19:19] : Mode: Device only OUT Endpoints Interrupt (OEPInt) The controller sets this bit to indicate that an interrupt is  pending on one of the OUT endpoints of the core (in Device  mode). The application must read the Device All Endpoints  Interrupt (DAINT) register to determine the exact number of  the OUT endpoint on which the interrupt occurred, and then  read the corresponding Device OUT Endpoint-n Interrupt  (DOEPINTn) register to determine the exact cause of the  interrupt. The application must clear the appropriate status  bit in the corresponding DOEPINTn register to clear this bit. Values:  <br><li> 0x0 (INACTIVE): Not active <br><li> 0x1 (ACTIVE): OUT Endpoints Interrupt Value After Reset: * Varies based on Configuration */
          __IOM uint32_t INCOMP_ISO_IN             : 1 ;     /*!< [20:20] : Mode: Device only Incomplete Isochronous IN Transfer (incompISOIN) The core sets this interrupt to indicate that there is at least  one isochronous IN endpoint on which the transfer is not  completed in the current microframe. This interrupt is  asserted along with the End of Periodic Frame Interrupt  (EOPF) bit in this register. Note: This interrupt is not asserted in Scatter/Gather DMA mode. Values:  <br><li> 0x0 (INACTIVE): Not active <br><li> 0x1 (ACTIVE): Incomplete Isochronous IN Transfer Value After Reset: * Varies based on Configuration */
          __IOM uint32_t INCOMPL_P                 : 1 ;     /*!< [21:21] : Incomplete Periodic Transfer (incomplP) Mode: Host only In Host mode, the core sets this interrupt bit when there are  incomplete periodic transactions still pending which are  scheduled for the current microframe. Incomplete Isochronous OUT Transfer (incompISOOUT) Mode: Device only The Device mode, the core sets this interrupt to indicate that  there is at least one isochronous OUT endpoint on which the  transfer is not completed in the current microframe. This  interrupt is asserted along with the End of Periodic Frame  Interrupt (EOPF) bit in this register. Values:  <br><li> 0x0 (INACTIVE): Not active <br><li> 0x1 (ACTIVE): Incomplete Periodic Transfer Value After Reset: * Varies based on Configuration */
          __IOM uint32_t FET_SUSP                  : 1 ;     /*!< [22:22] : Mode: Device only Data Fetch Suspended (FetSusp) This interrupt is valid only in DMA mode. This interrupt  indicates that the core has stopped fetching data. For IN  endpoints due to the unavailability of TxFIFO space or  Request Queue space. This interrupt is used by the  application for an endpoint mismatch algorithm. For example, after detecting an endpoint mismatch, the application: <br><li> Sets a Global non-periodic IN NAK handshake <br><li> Disables IN endpoints <br><li> Flushes the FIFO <br><li> Determines the token sequence from the IN Token  Sequence Learning Queue <br><li> Re-enables the endpoints <br><li> Clears the Global non-periodic IN NAK handshake If the Global non-periodic IN NAK is cleared, the core has  not yet fetched data for the IN endpoint, and the IN token is  received. The core generates an 'IN token received when  FIFO empty' interrupt. It then sends the host a NAK  response. To avoid this scenario, the application can check  the GINTSTS.FetSusp interrupt, which ensures that the  FIFO is full before clearing a Global NAK handshake. Alternatively, the application can mask the IN token received  when FIFO empty interrupt when clearing a Global IN NAK handshake. Values:  <br><li> 0x0 (INACTIVE): Not active <br><li> 0x1 (ACTIVE): Data Fetch Suspended Value After Reset: * Varies based on Configuration */
          __IOM uint32_t RESET_DET                 : 1 ;     /*!< [23:23] : Mode: Device only Reset detected Interrupt (ResetDet) In Device mode, this interrupt is asserted when a reset is  detected on the USB in partial power-down mode when the  device is in Suspend. In Host mode, this interrupt is not asserted. Values:  <br><li> 0x0 (INACTIVE): Not active <br><li> 0x1 (ACTIVE): Reset detected Interrupt Value After Reset: * Varies based on Configuration */
          __IM  uint32_t PRT_INT                   : 1 ;     /*!< [24:24] : Mode: Host only Host Port Interrupt (PrtInt) The core sets this bit to indicate a change in port status of  one of the controller ports in Host mode. The application  must read the Host Port Control and Status (HPRT) register  to determine the exact event that caused this interrupt. The  application must clear the appropriate status bit in the Host  Port Control and Status register to clear this bit. Values:  <br><li> 0x0 (INACTIVE): Not active <br><li> 0x1 (ACTIVE): Host Port Interrupt Value After Reset: * Varies based on Configuration */
          __IM  uint32_t HCH_INT                   : 1 ;     /*!< [25:25] : Mode: Host only Host Channels Interrupt (HChInt) The core sets this bit to indicate that an interrupt is pending  on one of the channels of the core (in Host mode). The  application must read the Host All Channels Interrupt  (HAINT) register to determine the exact number of the  channel on which the interrupt occurred, and Then read the  corresponding Host Channel-n Interrupt (HCINTn) register to  determine the exact cause of the interrupt. The application  must clear the appropriate status bit in the HCINTn register  to clear this bit. Values:  <br><li> 0x0 (INACTIVE): Not active <br><li> 0x1 (ACTIVE): Host Channels Interrupt Value After Reset: * Varies based on Configuration */
          __IM  uint32_t PTXF_EMP                  : 1 ;     /*!< [26:26] : Mode: Host only Periodic TxFIFO Empty (PTxFEmp) This interrupt is asserted when the Periodic Transmit FIFO is  either half or completely empty and there is space for at least  one entry to be written in the Periodic Request Queue. The  half or completely empty status is determined by the Periodic  TxFIFO Empty Level bit in the Core AHB Configuration  register (GAHBCFG.PTxFEmpLvl). Values:  <br><li> 0x0 (INACTIVE): Not active <br><li> 0x1 (ACTIVE): Periodic TxFIFO Empty Value After Reset: * Varies based on Configuration */
                uint32_t RSV_19                    : 1 ;     /*!< [27:27] : reserved */
          __IOM uint32_t CON_ID_STS_CHNG           : 1 ;     /*!< [28:28] : Mode: Host and Device Connector ID Status Change (ConIDStsChng) The core sets this bit when there is a change in connector ID status. Values:  <br><li> 0x0 (INACTIVE): Not Active <br><li> 0x1 (ACTIVE): Connector ID Status Change Value After Reset: * Varies based on Configuration */
          __IOM uint32_t DISCONN_INT               : 1 ;     /*!< [29:29] : Mode: Host only Disconnect Detected Interrupt (DisconnInt) Asserted when a device disconnect is detected. Values:  <br><li> 0x0 (INACTIVE): Not active <br><li> 0x1 (ACTIVE): Disconnect Detected Interrupt Value After Reset: * Varies based on Configuration */
          __IOM uint32_t SESS_REQ_INT              : 1 ;     /*!< [30:30] : Mode: Host and Device Session Request/New Session Detected Interrupt (SessReqInt) In Host mode, this interrupt is asserted when a session  request is detected from the device.  In Device mode, this interrupt is asserted when the  utmisrp_bvalid signal goes high. For more information on how to use this interrupt, see 'Partial  Power-Down and Clock Gating Programming Model' in the Programming Guide. Values:  <br><li> 0x0 (INACTIVE): Not active <br><li> 0x1 (ACTIVE): Session Request New Session Detected Interrupt Value After Reset: * Varies based on Configuration */
          __IOM uint32_t WK_UP_INT                 : 1 ;     /*!< [31:31] : Mode: Host and Device Resume/Remote Wakeup Detected Interrupt (WkUpInt) Wakeup Interrupt during Suspend(L2) or LPM(L1) state. <br><li> During Suspend(L2): - Device Mode: This interrupt is asserted only when  Host Initiated Resume is detected on USB. - Host Mode: This interrupt is asserted only when  Device Initiated Remote Wakeup is detected on USB.  For more information, see 'Partial Power-Down and Clock  Gating Programming Model' in the Programming Guide. <br><li> During LPM(L1): - Device Mode: This interrupt is asserted for either Host  Initiated Resume or Device Initiated Remote Wakeup on USB. - Host Mode: This interrupt is asserted for either Host  Initiated Resume or Device Initiated Remote Wakeup on USB. For more information, see 'LPM Entry and Exit Programming  Model' in the Programming Guide. Values:  <br><li> 0x0 (INACTIVE): Not active <br><li> 0x1 (ACTIVE): Resume or Remote Wakeup Detected Interrupt Value After Reset: * Varies based on Configuration */
       } GINTSTSb;
    };

    union
    {
       __IOM uint32_t GINTMSK;  /*!< 0x00000018 */ 
       
       struct
       {
                uint32_t RSV_20                    : 1 ;     /*!< [0:0] : reserved */
          __IOM uint32_t MODE_MIS_MSK              : 1 ;     /*!< [1:1] : Mode: Host and Device   Mode Mismatch Interrupt Mask (ModeMisMsk) Values:  <br><li> 0x0 (MASK): Mode Mismatch Interrupt Mask <br><li> 0x1 (NOMASK): No Mode Mismatch Interrupt Mask */
          __IOM uint32_t OTG_INT_MSK               : 1 ;     /*!< [2:2] : Mode: Host and Device   OTG Interrupt Mask (OTGIntMsk) Values:  <br><li> 0x0 (MASK): OTG Interrupt Mask <br><li> 0x1 (NOMASK): No OTG Interrupt Mask */
          __IOM uint32_t SOF_MSK                   : 1 ;     /*!< [3:3] : Mode: Host and Device   Start of (micro)Frame Mask (SofMsk) Values:  <br><li> 0x0 (MASK): Start of Frame Mask <br><li> 0x1 (NOMASK): No Start of Frame Mask */
          __IOM uint32_t RXF_LVL_MSK               : 1 ;     /*!< [4:4] : Mode: Host and Device   Receive FIFO Non-Empty Mask (RxFLvlMsk) Values:  <br><li> 0x0 (MASK): Receive FIFO Non-Empty Mask <br><li> 0x1 (NOMASK): No Receive FIFO Non-Empty Mask */
          __IOM uint32_t NP_TXF_EMP_MSK            : 1 ;     /*!< [5:5] : Mode: Host and Device   Non-periodic TxFIFO Empty Mask (NPTxFEmpMsk) Values:  <br><li> 0x0 (MASK): Non-periodic TxFIFO Empty Mask <br><li> 0x1 (NOMASK): No Non-periodic TxFIFO Empty Mask */
          __IOM uint32_t GIN_NAK_EFF_MSK           : 1 ;     /*!< [6:6] : Mode: Device only,       Global Non-periodic IN NAK Effective Mask (GINNakEffMsk) Values:  <br><li> 0x0 (MASK): Global Non-periodic IN NAK Effective Mask <br><li> 0x1 (NOMASK): No Global Non-periodic IN NAK Effective Mask */
          __IOM uint32_t GOUT_NAK_EFF_MSK          : 1 ;     /*!< [7:7] : Mode: Device only       Global OUT NAK Effective Mask (GOUTNakEffMsk) Values:  <br><li> 0x0 (MASK): Global OUT NAK Effective Mask <br><li> 0x1 (NOMASK): No Global OUT NAK Effective Mask */
                uint32_t RSV_21                    : 2 ;     /*!< [9:8] : reserved */
          __IOM uint32_t ERLY_SUSP_MSK             : 1 ;     /*!< [10:10] : Mode: Device only       Early Suspend Mask (ErlySuspMsk)  Values:  <br><li> 0x0 (MASK): Early Suspend Mask <br><li> 0x1 (NOMASK): No Early Suspend Mask */
          __IOM uint32_t USB_SUSP_MSK              : 1 ;     /*!< [11:11] : Mode: Device only       USB Suspend Mask (USBSuspMsk) Values:  <br><li> 0x0 (MASK): USB Suspend Mask <br><li> 0x1 (NOMASK): No USB Suspend Mask */
          __IOM uint32_t USB_RST_MSK               : 1 ;     /*!< [12:12] : Mode: Device only       USB Reset Mask (USBRstMsk) Values:  <br><li> 0x0 (MASK): USB Reset Mask <br><li> 0x1 (NOMASK): No USB Reset Mask */
          __IOM uint32_t ENUM_DONE_MSK             : 1 ;     /*!< [13:13] : Mode: Device only Enumeration Done Mask (EnumDoneMsk) Values:  <br><li> 0x0 (MASK): Enumeration Done Mask <br><li> 0x1 (NOMASK): No Enumeration Done Mask */
          __IOM uint32_t ISO_OUT_DROP_MSK          : 1 ;     /*!< [14:14] : Mode: Device only       Isochronous OUT Packet Dropped Interrupt Mask  (ISOOutDropMsk) Values:  <br><li> 0x0 (MASK): Isochronous OUT Packet Dropped Interrupt Mask <br><li> 0x1 (NOMASK): No Isochronous OUT Packet Dropped Interrupt Mask */
          __IOM uint32_t EOPFMSK                   : 1 ;     /*!< [15:15] : Mode: Device only       End of Periodic Frame Interrupt Mask (EOPFMsk) Values:  <br><li> 0x0 (MASK): End of Periodic Frame Interrupt Mask <br><li> 0x1 (NOMASK): No End of Periodic Frame Interrupt Mask */
                uint32_t RSV_22                    : 1 ;     /*!< [16:16] : reserved */
          __IOM uint32_t EP_MIS_MSK                : 1 ;     /*!< [17:17] : Mode: Device only       Endpoint Mismatch Interrupt Mask (EPMisMsk) Values:  <br><li> 0x0 (MASK): Endpoint Mismatch Interrupt Mask <br><li> 0x1 (NOMASK): No Endpoint Mismatch Interrupt Mask */
          __IOM uint32_t IEP_INT_MSK               : 1 ;     /*!< [18:18] : Mode: Device only       IN Endpoints Interrupt Mask (IEPIntMsk) Values:  <br><li> 0x0 (MASK): IN Endpoints Interrupt Mask <br><li> 0x1 (NOMASK): No IN Endpoints Interrupt Mask */
          __IOM uint32_t OEP_INT_MSK               : 1 ;     /*!< [19:19] : Mode: Device only       OUT Endpoints Interrupt Mask (OEPIntMsk) Values:  <br><li> 0x0 (MASK): OUT Endpoints Interrupt Mask <br><li> 0x1 (NOMASK): No OUT Endpoints Interrupt Mask */
                uint32_t RSV_23                    : 1 ;     /*!< [20:20] : reserved */
          __IOM uint32_t INCOMPL_PMS_K             : 1 ;     /*!< [21:21] : Incomplete Periodic Transfer Mask (incomplPMsk)  Mode: Host only          Incomplete Isochronous OUT Transfer Interrupt Mask (incompISOOUTMsk) Mode: Device only   Values:  <br><li> 0x0 (MASK):  Host mode: Incomplete Periodic Transfer Mask Device mode: Incomplete Isochronous OUT Transfer Mask <br><li> 0x1 (NOMASK):  Host mode: No Incomplete Periodic Transfer Mask Device mode: No Incomplete Isochronous OUT Transfer Mask */
          __IOM uint32_t FET_SUSP_MSK              : 1 ;     /*!< [22:22] : Mode: Device only       Data Fetch Suspended Mask (FetSuspMsk) Values:  <br><li> 0x0 (MASK): Data Fetch Suspended Mask <br><li> 0x1 (NOMASK): No Data Fetch Suspended Mask */
          __IOM uint32_t RESET_DET_MSK             : 1 ;     /*!< [23:23] : Mode: Device only  Reset detected Interrupt Mask (ResetDetMsk)  Values:  <br><li> 0x0 (MASK): Reset detected Interrupt Mask  <br><li> 0x1 (NOMASK): No Reset detected Interrupt Mask */
          __IOM uint32_t PRT_INT_MSK               : 1 ;     /*!< [24:24] : Mode: Host only   Host Port Interrupt Mask (PrtIntMsk) Values:  <br><li> 0x0 (MASK): Host Port Interrupt Mask <br><li> 0x1 (NOMASK): No Host Port Interrupt Mask */
          __IOM uint32_t HCH_INT_MSK               : 1 ;     /*!< [25:25] : Mode: Host only         Host Channels Interrupt Mask (HChIntMsk)  Values:  <br><li> 0x0 (MASK): Host Channels Interrupt Mask  <br><li> 0x1 (NOMASK): No Host Channels Interrupt Mask */
          __IOM uint32_t PTXF_EMP_MSK              : 1 ;     /*!< [26:26] : Mode: Host only         Periodic TxFIFO Empty Mask (PTxFEmpMsk) Values:  <br><li> 0x0 (MASK): Periodic TxFIFO Empty Mask <br><li> 0x1 (NOMASK): No Periodic TxFIFO Empty Mask */
                uint32_t RSV_24                    : 1 ;     /*!< [27:27] : reserved */
          __IOM uint32_t CON_ID_STS_CHNG_MSK       : 1 ;     /*!< [28:28] : Mode: Host and Device   Connector ID Status Change Mask (ConIDStsChngMsk)  Values:  <br><li> 0x0 (MASK): Connector ID Status Change Mask  <br><li> 0x1 (NOMASK): No Connector ID Status Change Mask */
          __IOM uint32_t DISCONN_INT_MSK           : 1 ;     /*!< [29:29] : Disconnect Detected Interrupt Mask (DisconnIntMsk) Values:  <br><li> 0x0 (MASK): Disconnect Detected Interrupt Mask <br><li> 0x1 (NOMASK): No Disconnect Detected Interrupt Mask */
          __IOM uint32_t SESS_REQ_INT_MSK          : 1 ;     /*!< [30:30] : Mode: Host and Device   Session Request/New Session Detected Interrupt Mask (SessReqIntMsk) Values:  <br><li> 0x0 (MASK): Session Request or New Session Detected Interrupt Mask <br><li> 0x1 (NOMASK): No Session Request or New Session Detected Interrupt Mask */
          __IOM uint32_t WK_UP_INT_MSK             : 1 ;     /*!< [31:31] : Mode: Host and Device   Resume/Remote Wakeup Detected Interrupt Mask (WkUpIntMsk) The WakeUp bit is used for LPM state wake up in a way  similar to that of wake up in suspend state. Values:  <br><li> 0x0 (MASK): Resume or Remote Wakeup Detected Interrupt Mask <br><li> 0x1 (NOMASK): Unmask Resume Remote Wakeup Detected Interrupt */
       } GINTMSKb;
    };

    union
    {
       __IM uint32_t GRXSTSR;  /*!< 0x0000001c */ 
       
       struct
       {
          __IM  uint32_t GRXSTSR_CH_NUM            : 4 ;     /*!< [3:0] : Channel Number (ChNum) Mode: Host only Indicates the channel number to which the current received packet belongs. Endpoint Number (EPNum) Mode: Device only Indicates the endpoint number to which the current received packet belongs. */
          __IM  uint32_t GRXSTSR_BCNT              : 11;     /*!< [14:4] : Byte Count (BCnt) In host mode, indicates the byte count of the received IN data packet. In device mode, indicates the byte count of the received data packet. */
          __IM  uint32_t GRXSTSR_DPID              : 2 ;     /*!< [16:15] : Data PID (DPID) In host mode, indicates the Data PID of the received packet.  In device mode, indicates the Data PID of the received OUT  data packet. <br><li> 2'b00: DATA0 <br><li> 2'b10: DATA1 <br><li> 2'b01: DATA2 <br><li> 2'b11: MDATA  Reset: 2'h0 Values:  <br><li> 0x0 (DATA0): DATA0 <br><li> 0x2 (DATA1): DATA1 <br><li> 0x1 (DATA2): DATA2 <br><li> 0x3 (MDATA): MDATA */
          __IM  uint32_t GRXSTSR_PKT_STS           : 4 ;     /*!< [20:17] : Packet Status (PktSts) indicates the status of the received packet.  In host mode,  <br><li> 4'b0010: IN data packet received <br><li> 4'b0011: IN transfer completed (triggers an interrupt) <br><li> 4'b0101: Data toggle error (triggers an interrupt) <br><li> 4'b0111: Channel halted (triggers an interrupt) <br><li> Others: Reserved Reset:4'b0 In device mode, <br><li> 4'b0001: Global OUT NAK (triggers an interrupt) <br><li> 4'b0010: OUT data packet received <br><li> 4'b0011: OUT transfer completed (triggers an interrupt) <br><li> 4'b0100: SETUP transaction completed (triggers an interrupt) <br><li> 4'b0110: SETUP data packet received <br><li> Others: Reserved Reset:4'h0 Values:  <br><li> 0x1 (OUTNAK): Global OUT NAK in device mode (triggers an interrupt) <br><li> 0x2 (INOUTDPRX): IN data packet received in host mode and OUT data packet received in device mode <br><li> 0x3 (INOUTTRCOM): IN or OUT transfer completed in both host and device mode (triggers an interrupt) <br><li> 0x4 (DSETUPCOM): SETUP transaction completed in device mode (triggers an interrupt) <br><li> 0x5 (DTTOG): Data toggle error (triggers an interrupt) in host mode <br><li> 0x6 (DSETUPRX): SETUP data packet received in device mode <br><li> 0x7 (CHHALT): Channel halted in host mode (triggers an interrupt) */
          __IM  uint32_t GRXSTSR_FN                : 4 ;     /*!< [24:21] : Mode: Device only       Frame Number (FN)        This is the least significant 4 bits of the (micro)Frame number  in which the packet is received on the USB. This field is  supported only when isochronous OUT endpoints are supported. */
                uint32_t RSV_25                    : 7 ;     /*!< [31:25] : reserved */
       } GRXSTSRb;
    };

    union
    {
       __IM uint32_t GRXSTSP;  /*!< 0x00000020 */ 
       
       struct
       {
          __IM  uint32_t GRXSTSP_CH_NUM            : 4 ;     /*!< [3:0] : Channel Number (ChNum)  Mode: Host only Indicates the channel number to which the current received packet belongs. Endpoint Number (EPNum) Mode: Device only Indicates the endpoint number to which the current received packet belongs. Values:  <br><li> 0x0 (CHEP0): Channel or EndPoint 0 <br><li> 0x1 (CHEP1): Channel or EndPoint 1 <br><li> 0x2 (CHEP2): Channel or EndPoint 2 <br><li> 0x3 (CHEP3): Channel or EndPoint 3 <br><li> 0x4 (CHEP4): Channel or EndPoint 4 <br><li> 0x5 (CHEP5): Channel or EndPoint 5 <br><li> 0x6 (CHEP6): Channel or EndPoint 6 <br><li> 0x7 (CHEP7): Channel or EndPoint 7 <br><li> 0x8 (CHEP8): Channel or EndPoint 8 <br><li> 0x9 (CHEP9): Channel or EndPoint 9 <br><li> 0xa (CHEP10): Channel or EndPoint 10 <br><li> 0xb (CHEP11): Channel or EndPoint 11 <br><li> 0xc (CHEP12): Channel or EndPoint 12 <br><li> 0xd (CHEP13): Channel or EndPoint 13 <br><li> 0xe (CHEP14): Channel or EndPoint 14 <br><li> 0xf (CHEP15): Channel or EndPoint 15 */
          __IM  uint32_t GRXSTSP_BCNT              : 11;     /*!< [14:4] : Byte Count (BCnt)       In host mode, indicates the byte count of the received IN data packet. In device mode, indicates the byte count of the received data packet. */
          __IM  uint32_t GRXSTSP_DPID              : 2 ;     /*!< [16:15] : Data PID (DPID). In host mode, indicates the Data PID of the received packet.  In device mode, indicates the Data PID of the received OUT  data packet. <br><li> 2'b00: DATA0 <br><li> 2'b10: DATA1 <br><li> 2'b01: DATA2 <br><li> 2'b11: MDATA  Reset: 2'h0 Values:  <br><li> 0x0 (DATA0): DATA0 <br><li> 0x2 (DATA1): DATA1 <br><li> 0x1 (DATA2): DATA2 <br><li> 0x3 (MDATA): MDATA */
          __IM  uint32_t GRXSTSP_PKT_STS           : 4 ;     /*!< [20:17] : Packet Status (PktSts) indicates the status of the received packet.  In host mode,  <br><li> 4'b0010: IN data packet received <br><li> 4'b0011: IN transfer completed (triggers an interrupt) <br><li> 4'b0101: Data toggle error (triggers an interrupt) <br><li> 4'b0111: Channel halted (triggers an interrupt) <br><li> Others: Reserved Reset:4'b0 In device mode, <br><li> 4'b0001: Global OUT NAK (triggers an interrupt) <br><li> 4'b0010: OUT data packet received <br><li> 4'b0011: OUT transfer completed (triggers an interrupt) <br><li> 4'b0100: SETUP transaction completed (triggers an interrupt) <br><li> 4'b0110: SETUP data packet received <br><li> Others: Reserved Reset:4'h0 Values:  <br><li> 0x1 (OUTNAK): Global OUT NAK in device mode (triggers an interrupt) <br><li> 0x2 (INOUTDPRX): IN data packet received in host mode and OUT data packet received in device mode <br><li> 0x3 (INOUTTRCOM): IN or OUT transfer completed in both host and device mode (triggers an interrupt) <br><li> 0x4 (DSETUPCOM): SETUP transaction completed in device mode (triggers an interrupt) <br><li> 0x5 (DTTOG): Data toggle error (triggers an interrupt) in host mode */
          __IM  uint32_t GRXSTSP_FN                : 4 ;     /*!< [24:21] : Mode: Device only       Frame Number (FN)  This is the least significant 4 bits of the (micro)Frame number  in which the packet is received on the USB. This field is  supported only when isochronous OUT endpoints are supported. */
                uint32_t RSV_26                    : 7 ;     /*!< [31:25] : reserved */
       } GRXSTSPb;
    };

    union
    {
       __IOM uint32_t GRXFSIZ;  /*!< 0x00000024 */ 
       
       struct
       {
          __IOM uint32_t RXF_DEP                   : 11;     /*!< [10:0] : Mode: Host and Device   RxFIFO Depth (RxFDep) This value is in terms of 32-bit words. <br><li> Minimum value is 16 <br><li> Maximum value is 32,768 The power-on reset value of this register is specified as the  Largest Rx Data FIFO Depth during configuration. If Enable Dynamic FIFO Sizing is selected in coreConsultant,  these flops are optimized, and reads return the power-on value. If Enable Dynamic FIFO Sizing is selected in coreConsultant,  you can write a new value in this field. Programmed values  must not exceed the power-on value. Value After Reset: * Varies based on Configuration */
                uint32_t RSV_27                    : 21;     /*!< [31:11] : reserved */
       } GRXFSIZb;
    };

    union
    {
       __IOM uint32_t GNPTXFSIZ;  /*!< 0x00000028 */ 
       
       struct
       {
          __IOM uint32_t NP_TXF_ST_ADDR            : 11;     /*!< [10:0] : Non-periodic Transmit RAM Start Address (NPTxFStAddr) The NPTxFStAddr field description is valid only for host  mode.  This field contains the memory start address for Non- periodic Transmit FIFO RAM.  This field is determined during coreConsultant configuration  by Enable Dynamic FIFO Sizing?(OTG_DFIFO_DYNAMIC). <br><li> OTG_DFIFO_DYNAMIC = 0: These flops are optimized,  and reads return the power-on value. <br><li> OTG_DFIFO_DYNAMIC = 1: The application can write a  new value in this field. Programmed values must not  exceed the power-on value set in coreConsultant. Programmed values must not exceed the power-on value set  in coreConsultant. The power-on reset value of this field is specified during  coreConsultant configuration by Largest Rx Data FIFO  Depth (parameter OTG_RX_DFIFO_DEPTH). IN Endpoint FIFO0 Transmit RAM Start  Address(INEPTxF0StAddr) The INEPTxF0StAddr field description is valid only for device  mode when OTG_EN_DED_TX_FIFO=1. This field contains the memory start address for IN Endpoint  Transmit FIFO# 0. Programmed values must not exceed the power-on value. Value After Reset: * Varies based on Configuration */
                uint32_t RSV_28                    : 5 ;     /*!< [15:11] : reserved */
          __IOM uint32_t NP_TXF_DEP                : 11;     /*!< [26:16] : Non-periodic TxFIFO Depth (NPTxFDep) The NPTxFDep field description is valid only for, <br><li> host mode  <br><li> device mode when OTG_EN_DED_TX_FIFO=0  This value is in terms of 32-bit words.  <br><li> Minimum value is 16 <br><li> Maximum value is 32,768 This attribute of field is determined during coreConsultant  configuration by "Enable Dynamic FIFO Sizing?"  (OTG_DFIFO_DYNAMIC): <br><li> OTG_DFIFO_DYNAMIC = 0: These flops are optimized,  and reads return the power-on value. <br><li> OTG_DFIFO_DYNAMIC = 1: The application can write a  new value in this field. Programmed values must not  exceed the power-on value set in coreConsultant. The power-on reset value of this field is specified during  coreConsultant configuration: <br><li> Host: - The reset value is  OTG_TX_HNPERIO_DFIFO_DEPTH parameter  when OTG_EN_DED_TX_FIFO == 0. - The reset value is  OTG_TX_DINEP_DFIFO_DEPTH_0 parameter when  OTG_EN_DED_TX_FIFO == 1.  <br><li> Device Shared FIFO mode: The reset value is the Largest  Non-periodic Tx Data FIFO Depth parameter,  OTG_TX_NPERIO_DFIFO_DEPTH, when  OTG_EN_DED_TX_FIFO == 0. ---IN Endpoint TxFIFO 0 Depth (INEPTxF0Dep) The INEPTxF0Dep field description is valid only for device  mode when OTG_EN_DED_TX_FIFO=1. This value is in  terms of 32-bit words. <br><li> Minimum value is 16 <br><li> Maximum value is 32,768 The attribute of this field is determined during  coreConsultant configuration by Enable Dynamic FIFO  Sizing? (OTG_DFIFO_DYNAMIC): <br><li> OTG_DFIFO_DYNAMIC = 0: These flops are optimized,  and reads return the power-on value. Value After Reset: * Varies based on Configuration */
                uint32_t RSV_29                    : 5 ;     /*!< [31:27] : reserved */
       } GNPTXFSIZb;
    };

    union
    {
       __IM uint32_t GNPTXSTS;  /*!< 0x0000002c */ 
       
       struct
       {
          __IM  uint32_t NP_TXF_SPC_AVAIL          : 16;     /*!< [15:0] : Non-periodic TxFIFO Space Avail (NPTxFSpcAvail) Indicates the amount of free space available in the Non-periodic TxFIFO. Values are in terms of 32-bit words. <br><li> 16'h0: Non-periodic TxFIFO is full <br><li> 16'h1: 1 word available <br><li> 16'h2: 2 words available <br><li> 16'hn: n words available (where 0 <= n <= 32,768) <br><li> 16'h8000: 32,768 words available <br><li> Others: Reserved Reset: Configurable Value After Reset: * Varies based on Configuration */
          __IM  uint32_t NP_TX_QSPC_AVAIL          : 8 ;     /*!< [23:16] : Non-periodic Transmit Request Queue Space Available (NPTxQSpcAvail) Indicates the amount of free space available in the Non- periodic Transmit Request Queue. This queue holds both IN  and OUT requests in Host mode. Device mode has only IN  requests. <br><li> 8'h0: Non-periodic Transmit Request Queue is full <br><li> 8'h1: 1 location available <br><li> 8'h2: 2 locations available <br><li> n: n locations available (0 <= n <= 8) <br><li> Others: Reserved Reset: Configurable Values:  <br><li> 0x0 (FULL): Non-periodic Transmit Request Queue is full <br><li> 0x1 (QUE1): 1 location available <br><li> 0x2 (QUE2): 2 locations available <br><li> 0x3 (QUE3): 3 locations available <br><li> 0x4 (QUE4): 4 locations available <br><li> 0x5 (QUE5): 5 locations available <br><li> 0x6 (QUE6): 6 locations available <br><li> 0x7 (QUE7): 7 locations available <br><li> 0x8 (QUE8): 8 locations available Value After Reset: * Varies based on Configuration */
          __IM  uint32_t NP_TX_QTOP                : 7 ;     /*!< [30:24] : Top of the Non-periodic Transmit Request Queue (NPTxQTop) Entry in the Non-periodic Tx Request Queue that is currently  being processed by the MAC. <br><li> Bits [30:27]: Channel/endpoint number <br><li> Bits [26:25]: <br><li> 2'b00: IN/OUT token - 2'b01: Zero-length transmit packet (device IN/host  OUT) - 2'b10: PING/CSPLIT token - 2'b11: Channel halt command <br><li> Bit [24]: Terminate (last Entry for selected  channel/endpoint) Reset: 7'h0 Values:  <br><li> 0x0 (INOUTTK): IN/OUT token <br><li> 0x1 (ZEROTX): Zero-length transmit packet (device  IN/host OUT) <br><li> 0x2 (PINGCSPLIT): PING/CSPLIT token <br><li> 0x3 (CHNHALT): Channel halt command Value After Reset: * Varies based on Configuration */
                uint32_t RSV_30                    : 1 ;     /*!< [31:31] : reserved */
       } GNPTXSTSb;
    };

    uint8_t              RSV_0X30[16]                  ;   /*!< 0x00000030~0x0000003f : reserved */

    union
    {
       __IM uint32_t GSNPSID;  /*!< 0x00000040 */ 
       
       struct
       {
          __IM  uint32_t SYNOPSYS_ID               : 32;     /*!< [31:0] : Release number of the controller being used currently. Value After Reset: * Varies based on Configuration */
       } GSNPSIDb;
    };

    union
    {
       __IM uint32_t GHWCFG1;  /*!< 0x00000044 */ 
       
       struct
       {
          __IM  uint32_t EP_DIR                    : 32;     /*!< [31:0] : This 32-bit field uses two bits per  endpoint to determine the  endpoint direction. Endpoint <br><li> Bits [31:30]: Endpoint 15 direction <br><li> Bits [29:28]: Endpoint 14 direction ... <br><li> Bits [3:2]: Endpoint 1 direction <br><li> Bits[1:0]: Endpoint 0 direction (always BIDIR) Direction <br><li> 2'b00: BIDIR (IN and OUT) endpoint <br><li> 2'b01: IN endpoint <br><li> 2'b10: OUT endpoint <br><li> 2'b11: Reserved Note: This field is configured using the OTG_EP_DIR_1(n)  parameter. Value After Reset: * Varies based on Configuration */
       } GHWCFG1b;
    };

    union
    {
       __IM uint32_t GHWCFG2;  /*!< 0x00000048 */ 
       
       struct
       {
          __IM  uint32_t OTG_MODE                  : 3 ;     /*!< [2:0] : Note: This field is configured using the OTG_MODE parameter. */
          __IM  uint32_t OTG_ARCH                  : 2 ;     /*!< [4:3] : Architecture (OtgArch) <br><li> 2'b00: Slave-Only <br><li> 2'b01: External DMA <br><li> 2'b10: Internal DMA <br><li> Others: Reserved Note: This field is configured using the  OTG_ARCHITECTURE parameter. Values:  <br><li> 0x0 (SLAVEMODE): Slave Mode <br><li> 0x1 (EXTERNALDMA): External DMA Mode <br><li> 0x2 (INTERNALDMA): Internal DMA Mode Value After Reset: * Varies based on Configuration */
          __IM  uint32_t SING_PNT                  : 1 ;     /*!< [5:5] : Point-to-Point (SingPnt) <br><li> 1'b0: Multi-point application  (hub and split support) <br><li> 1'b1: Single-point application (no hub and split support) Note: This field is configured using the  OTG_SINGLE_POINT parameter. Values:  <br><li> 0x0 (MULTIPOINT): Multi-point application (hub and split  support) <br><li> 0x1 (SINGLEPOINT): Single-point application (no hub  and split support) Value After Reset: * Varies based on Configuration */
          __IM  uint32_t HSPHY_TYPE                : 2 ;     /*!< [7:6] : High-Speed PHY Interface Type (HSPhyType) <br><li> 2'b00: High-Speed interface not supported <br><li> 2'b01: UTMI+ <br><li> 2'b10: ULPI <br><li> 2'b11: UTMI+ and ULPI Note: This field is configured using the  OTG_HSPHY_INTERFACE parameter. Values:  <br><li> 0x0 (NOHS): High-Speed interface not supported <br><li> 0x1 (UTMIPLUS): High Speed Interface UTMI+ is  supported <br><li> 0x2 (ULPI): High Speed Interface ULPI is supported <br><li> 0x3 (UTMIPUSULPI): High Speed Interfaces UTMI+ and  ULPI is supported Value After Reset: * Varies based on Configuration */
          __IM  uint32_t FS_PHY_TYPE               : 2 ;     /*!< [9:8] : Full-Speed PHY Interface Type (FSPhyType) <br><li> 2'b00: Full-speed interface not supported <br><li> 2'b01: Dedicated full-speed interface <br><li> 2'b10: FS pins shared with UTMI+ pins <br><li> 2'b11: FS pins shared with ULPI pins Note: This field is configured using the  OTG_FSPHY_INTERFACE parameter. Values:  <br><li> 0x0 (NO_FS): Full-speed interface not supported <br><li> 0x1 (FS): Dedicated full-speed interface is supported <br><li> 0x2 (FSPLUSUTMI): FS pins shared with UTMI+ pins is  supported <br><li> 0x3 (FSPLUSULPI): FS pins shared with ULPI pins is  supported Value After Reset: * Varies based on Configuration */
          __IM  uint32_t NUM_DEV_EPS               : 4 ;     /*!< [13:10] : Number of Device Endpoints (NumDevEps) Indicates the number of device endpoints supported by the  core in Device mode. The range of this field is 0-15. Note: This field is configured using the OTG_NUM_EPS  parameter. Values:  <br><li> 0x0 (ENDPT0): End point 0 <br><li> 0x1 (ENDPT1): End point 1 <br><li> 0x2 (ENDPT2): End point 2 <br><li> 0x3 (ENDPT3): End point 3 <br><li> 0x4 (ENDPT4): End point 4 <br><li> 0x5 (ENDPT5): End point 5 <br><li> 0x6 (ENDPT6): End point 6 <br><li> 0x7 (ENDPT7): End point 7 <br><li> 0x8 (ENDPT8): End point 8 <br><li> 0x9 (ENDPT9): End point 9 <br><li> 0xa (ENDPT10): End point 10 <br><li> 0xb (ENDPT11): End point 11 <br><li> 0xc (ENDPT12): End point 12 <br><li> 0xd (ENDPT13): End point 13 <br><li> 0xe (ENDPT14): End point 14 <br><li> 0xf (ENDPT15): End point 15 Value After Reset: * Varies based on Configuration */
          __IM  uint32_t NUM_HST_CHNL              : 4 ;     /*!< [17:14] : Number of Host Channels (NumHstChnl) Indicates the number of host channels supported by the core  in Host mode. The range of this field is 0-15: 0 specifies 1  channel, 15 specifies 16 channels. Note: This field is configured using the  OTG_NUM_HOST_CHAN parameter. Values:  <br><li> 0x0 (HOSTCH0): Host Channel 1 <br><li> 0x1 (HOSTCH1): Host Channel 2 <br><li> 0x2 (HOSTCH2): Host Channel 3 <br><li> 0x3 (HOSTCH3): Host Channel 4 <br><li> 0x4 (HOSTCH4): Host Channel 5 <br><li> 0x5 (HOSTCH5): Host Channel 6 <br><li> 0x6 (HOSTCH6): Host Channel 7 <br><li> 0x7 (HOSTCH7): Host Channel 8 <br><li> 0x8 (HOSTCH8): Host Channel 9 <br><li> 0x9 (HOSTCH9): Host Channel 10 <br><li> 0xa (HOSTCH10): Host Channel 11 <br><li> 0xb (HOSTCH11): Host Channel 12 <br><li> 0xc (HOSTCH12): Host Channel 13 <br><li> 0xd (HOSTCH13): Host Channel 14 <br><li> 0xe (HOSTCH14): Host Channel 15 <br><li> 0xf (HOSTCH15): Host Channel 16 Value After Reset: * Varies based on Configuration */
          __IM  uint32_t PERIO_SUPPORT             : 1 ;     /*!< [18:18] : Periodic OUT Channels Supported in Host Mode  (PerioSupport) <br><li> 1'b0: No <br><li> 1'b1: Yes Note: This field is configured using the  OTG_EN_PERIO_HOST parameter. Values:  <br><li> 0x0 (DISABLED): Periodic OUT Channels is not  supported in Host Mode <br><li> 0x1 (ENABLED): Periodic OUT Channels Supported in  Host Mode Supported Value After Reset: * Varies based on Configuration */
          __IM  uint32_t DYN_FIFO_SIZING           : 1 ;     /*!< [19:19] : Dynamic FIFO Sizing Enabled (DynFifoSizing) <br><li> 1'b0: No <br><li> 1'b1: Yes Note: This field is configured using the  OTG_DFIFO_DYNAMIC parameter. Values:  <br><li> 0x0 (DISABLED): Dynamic FIFO Sizing Disabled <br><li> 0x1 (ENABLED): Dynamic FIFO Sizing Enabled Value After Reset: * Varies based on Configuration */
          __IM  uint32_t MULTI_PROC_INTRPT         : 1 ;     /*!< [20:20] : Multi Processor Interrupt Enabled (MultiProcIntrpt) <br><li> 1'b0: No <br><li> 1'b1: Yes Note: This field is configured using the  OTG_MULTI_PROC_INTRPT parameter. Values:  <br><li> 0x0 (DISABLED): No Multi Processor Interrupt Enabled <br><li> 0x1 (ENABLED): Multi Processor Interrupt Enabled Value After Reset: * Varies based on Configuration */
                uint32_t RSV_31                    : 1 ;     /*!< [21:21] : reserved */
          __IM  uint32_t NP_TX_QDEPTH              : 2 ;     /*!< [23:22] : Non-periodic Request Queue Depth (NPTxQDepth) <br><li> 2'b00: 2 <br><li> 2'b01: 4 <br><li> 2'b10: 8 <br><li> Others: Reserved Note: This field is configured using the  OTG_NPERIO_TX_QUEUE_DEPTH parameter. Values:  <br><li> 0x0 (TWO): Queue size 2 <br><li> 0x1 (FOUR): Queue size 4 <br><li> 0x2 (EIGHT): Queue size 8 Value After Reset: * Varies based on Configuration */
          __IM  uint32_t PTX_QDEPTH                : 2 ;     /*!< [25:24] : Host Mode Periodic Request Queue Depth (PTxQDepth) <br><li> 2'b00: 2 <br><li> 2'b01: 4 <br><li> 2'b10: 8 <br><li> 2'b11:16 Note: This field is configured using the  OTG_PERIO_TX_QUEUE_DEPTH parameter. Values:  <br><li> 0x0 (QUE2): Queue Depth 2 <br><li> 0x1 (QUE4): Queue Depth 4 <br><li> 0x2 (QUE8): Queue Depth 8 <br><li> 0x3 (QUE16): Queue Depth 16 Value After Reset: * Varies based on Configuration */
          __IM  uint32_t TKN_QDEPTH                : 5 ;     /*!< [30:26] : Device Mode IN Token Sequence Learning Queue Depth (TknQDepth) Range: 0-30 Note: This field is configured using the  OTG_TOKEN_QUEUE_DEPTH parameter. Value After Reset: * Varies based on Configuration */
                uint32_t RSV_32                    : 1 ;     /*!< [31:31] : reserved */
       } GHWCFG2b;
    };

    union
    {
       __IM uint32_t GHWCFG3;  /*!< 0x0000004c */ 
       
       struct
       {
          __IM  uint32_t XFER_SIZE_WIDTH           : 4 ;     /*!< [3:0] : Width of Transfer Size Counters (XferSizeWidth) <br><li> 4'b0000: 11 bits <br><li> 4'b0001: 12 bits ... <br><li> 4'b1000: 19 bits <br><li> Others: Reserved Note: This field is configured using the  OTG_TRANS_COUNT_WIDTH parameter. Values:  <br><li> 0x0 (WIDTH11): Width of Transfer Size Counter 11 bits <br><li> 0x1 (WIDTH12): Width of Transfer Size Counter 12 bits <br><li> 0x2 (WIDTH13): Width of Transfer Size Counter 13 bits <br><li> 0x3 (WIDTH14): Width of Transfer Size Counter 14 bits <br><li> 0x4 (WIDTH15): Width of Transfer Size Counter 15 bits <br><li> 0x5 (WIDTH16): Width of Transfer Size Counter 16 bits <br><li> 0x6 (WIDTH17): Width of Transfer Size Counter 17 bits <br><li> 0x7 (WIDTH18): Width of Transfer Size Counter 18 bits <br><li> 0x8 (WIDTH19): Width of Transfer Size Counter 19 bits Value After Reset: * Varies based on Configuration */
          __IM  uint32_t PKT_SIZE_WIDTH            : 3 ;     /*!< [6:4] : Width of Packet Size Counters (PktSizeWidth) <br><li> 3'b000: 4 bits <br><li> 3'b001: 5 bits <br><li> 3'b010: 6 bits <br><li> 3'b011: 7 bits <br><li> 3'b100: 8 bits <br><li> 3'b101: 9 bits <br><li> 3'b110: 10 bits <br><li> Others: Reserved Note: This field is configured using the  OTG_PACKET_COUNT_WIDTH parameter. Values:  <br><li> 0x0 (BITS4): Width of Packet Size Counter 4 <br><li> 0x1 (BITS5): Width of Packet Size Counter 5 <br><li> 0x2 (BITS6): Width of Packet Size Counter 6 <br><li> 0x3 (BITS7): Width of Packet Size Counter 7 <br><li> 0x4 (BITS8): Width of Packet Size Counter 8 <br><li> 0x5 (BITS9): Width of Packet Size Counter 9 <br><li> 0x6 (BITS10): Width of Packet Size Counter 10 Value After Reset: * Varies based on Configuration */
          __IM  uint32_t OTG_EN                    : 1 ;     /*!< [7:7] : Note: This field is configured using the OTG_MODE parameter. */
          __IM  uint32_t I2CINT_SEL                : 1 ;     /*!< [8:8] : Note: This field is configured using the OTG_I2C_INTERFACE parameter. */
          __IM  uint32_t VNDCTL_SUPT               : 1 ;     /*!< [9:9] : Vendor Control Interface Support (VndctlSupt) <br><li> 1'b0: Vendor Control Interface is not available on the core. <br><li> 1'b1: Vendor Control Interface is available. Note: This field is configured using the  OTG_VENDOR_CTL_INTERFACE parameter. Values:  <br><li> 0x0 (DISABLED): Vendor Control Interface is not  available. <br><li> 0x1 (ENABLED): Vendor Control Interface is available. Value After Reset: * Varies based on Configuration */
          __IM  uint32_t OPT_FEATURE               : 1 ;     /*!< [10:10] : Optional Features Removed (OptFeature) Indicates whether the User ID register, GPIO interface ports,  and SOF toggle and counter ports were removed for gate  count optimization by enabling Remove Optional Features. <br><li> 1'b0: No <br><li> 1'b1: Yes Note: This field is configured using the  OTG_RM_OPT_FEATURES parameter. Values:  <br><li> 0x0 (DISABLED): Optional features were not Removed <br><li> 0x1 (ENABLED): Optional Features have been Removed Value After Reset: * Varies based on Configuration */
          __IM  uint32_t RST_TYPE                  : 1 ;     /*!< [11:11] : Reset Style for Clocked always Blocks in RTL (RstType) <br><li> 1'b0: Asynchronous reset is used in the controller <br><li> 1'b1: Synchronous reset is used in the controller Note: This field is configured using the  OTG_SYNC_RESET_TYPE parameter. Values:  <br><li> 0x0 (ASYNCRST): Asynchronous reset is used in the  core <br><li> 0x1 (SYNCRST): Synchronous reset is used in the core Value After Reset: * Varies based on Configuration */
          __IM  uint32_t ADPSUPPORT                : 1 ;     /*!< [12:12] : This bit indicates whether ADP logic is present within or  external to the controller <br><li> 0: No ADP logic present with the controller <br><li> 1: ADP logic is present along with the controller. Values:  <br><li> 0x0 (DISABLED): ADP logic is not present along with the  controller <br><li> 0x1 (ENABLED): ADP logic is present along with the  controller Value After Reset: * Varies based on Configuration */
          __IM  uint32_t HSICMODE                  : 1 ;     /*!< [13:13] : HSIC mode specified for Mode of Operation Value Range: 0 - 1 <br><li> 1: HSIC-capable with shared UTMI PHY interface <br><li> 0: Non-HSIC-capable Values:  <br><li> 0x0 (DISABLED): No HSIC capability <br><li> 0x1 (ENABLED): HSIC-capable with shared UTMI PHY  interface Value After Reset: * Varies based on Configuration */
          __IM  uint32_t BCSUPPORT                 : 1 ;     /*!< [14:14] : This bit indicates the controller support for Battery Charger. <br><li> 0 - No Battery Charger Support <br><li> 1 - Battery Charger support present Values:  <br><li> 0x0 (DISABLED): No Battery Charger Support <br><li> 0x1 (ENABLED): Battery Charger Support present Value After Reset: * Varies based on Configuration */
          __IM  uint32_t LPMMODE                   : 1 ;     /*!< [15:15] : LPM mode specified for Mode of Operation. Values:  <br><li> 0x0 (DISABLED): LPM disabled <br><li> 0x1 (ENABLED): LPM enabled Value After Reset: * Varies based on Configuration */
          __IM  uint32_t DFIFO_DEPTH               : 16;     /*!< [31:16] : DFIFO Depth (DfifoDepth - EP_LOC_CNT) This value is in terms of 32-bit words. <br><li> Minimum value is 32 <br><li> Maximum value is 32,768 Note: This field is configured using the  OTG_DFIFO_DEPTH parameter. For more information on  EP_LOC_CNT, see the "Endpoint Information Controller  (EPINFO_CTL)" section. Value After Reset: * Varies based on Configuration */
       } GHWCFG3b;
    };

    union
    {
       __IM uint32_t GHWCFG4;  /*!< 0x00000050 */ 
       
       struct
       {
          __IM  uint32_t NUM_DEV_PERIO_EPS         : 4 ;     /*!< [3:0] : Number of Device Mode Periodic IN Endpoints (NumDevPerioEps) Range: 0-15 Value After Reset: * Varies based on Configuration */
          __IM  uint32_t PARTIAL_PWR_DN            : 1 ;     /*!< [4:4] : Enable Partial Power Down (PartialPwrDn) <br><li> 1'b0: Partial Power Down Not Enabled <br><li> 1'b1: Partial Power Down Enabled Values:  <br><li> 0x0 (DISABLED): Partial Power Down disabled <br><li> 0x1 (ENABLED): Partial Power Down enabled Value After Reset: * Varies based on Configuration */
          __IM  uint32_t AHB_FREQ                  : 1 ;     /*!< [5:5] : Minimum AHB Frequency Less Than 60 MHz (AhbFreq) <br><li> 1'b0: No <br><li> 1'b1: Yes Values:  <br><li> 0x0 (DISABLED): Minimum AHB Frequency More Than 60 MHz <br><li> 0x1 (ENABLED): Minimum AHB Frequency Less Than 60 MHz Value After Reset: * Varies based on Configuration */
          __IM  uint32_t HIBERNATION               : 1 ;     /*!< [6:6] : Enable Hibernation (Hibernation) <br><li> 1'b0: Hibernation feature not enabled <br><li> 1'b1: Hibernation feature enabled Values:  <br><li> 0x0 (DISABLED): Hibernation feature disabled <br><li> 0x1 (ENABLED): Hibernation feature enabled Value After Reset: * Varies based on Configuration */
          __IM  uint32_t EXTENDED_HIBERNATION      : 1 ;     /*!< [7:7] : Enable Hibernation <br><li> 1'b0: Extended Hibernation feature not enabled <br><li> 1'b1: Extended Hibernation feature enabled Values:  <br><li> 0x0 (DISABLED): Extended Hibernation feature not  enabled <br><li> 0x1 (ENABLED): Extended Hibernation feature enabled Value After Reset: * Varies based on Configuration */
                uint32_t RSV_33                    : 1 ;     /*!< [8:8] : reserved */
          __IM  uint32_t ENHANCED_LPMSUPT1         : 1 ;     /*!< [9:9] : Enhanced LPM Support1 (EnhancedLPMSupt1) <br><li> This bit indicates that the controller supports L1 entry  based on FIFO status. <br><li> Accept L1 Request even if Bulk/Interrupt TxFIFO is not  empty. Values:  <br><li> 0x0 (DISABLED): Reject L1 Request even if Non-Periodic  (Bulk/Interrupt) TxFIFO is not empty. <br><li> 0x1 (ENABLED): Accept L1 Request even if Non-Periodic  (Bulk/Interrupt) TxFIFO is not empty Value After Reset: * Varies based on Configuration */
          __IM  uint32_t SERV_INT_FLOW             : 1 ;     /*!< [10:10] : Service Interval Flow  This bit indicates that the controller supports Service-Interval  based scheduling flow for ISOC IN EPs. Values:  <br><li> 0x0 (DISABLED): Service Interval Flow not supported <br><li> 0x1 (ENABLED): Service Interval Flow supported Value After Reset: * Varies based on Configuration */
          __IM  uint32_t IPGISOC_SUPT              : 1 ;     /*!< [11:11] : Interpacket Gap ISOC OUT Worst-case Support (ipgisocSupt)  This bit indicates that the controller supports the worst-case  scenario of Rx followed by Rx Inter Packet Gap (IPG) (32-bit  times) as per the UTMI Specification for any token following  an ISOC OUT token. Without this support, when any token  follows an ISOC OUT token with the worst-case IPG, the  controller will not detect the followed token. The worst-case  IPG of the controller without this support depends on the  AHB and PHY clock frequency.By default IPG Support is  enabled. Values:  <br><li> 0x0 (DISABLED): Interpacket Gap ISOC OUT Worst- case Support is Disabled <br><li> 0x1 (ENABLED): Interpacket Gap ISOC OUT Worst-case  Support is Enabled (Default) Value After Reset: * Varies based on Configuration */
          __IM  uint32_t ACGSUPT                   : 1 ;     /*!< [12:12] : Active Clock Gating Support This bit indicates that the controller supports the Dynamic  (Switching) Power Reduction during periods when there is  no USB and AHB Traffic.  <br><li> 1'b0:  Active Clock Gating is not enabled. <br><li> 1'b1:  Active Clock Gating Enabled. Values:  <br><li> 0x0 (DISABLED) <br><li> 0x1 (ENABLED): Active Clock Gating Support Value After Reset: * Varies based on Configuration */
          __IM  uint32_t ENHANCED_LPMSUPT          : 1 ;     /*!< [13:13] : Enhanced LPM Support (EnhancedLPMSupt) This bit indicates that the controller supports the following  behavior: L1 Entry Behavior based on FIFO Status <br><li> TX FIFO <br><li> Accept L1 Request even if ISOC IN TX FIFO is not empty. <br><li> Reject L1 Request if Non-Periodic TX FIFO is not empty. <br><li> Ensure application can flush the TX FIFO while the  Controller is in L1. <br><li> RX FIFO <br><li> Accept L1 Request even if RX FIFO (common to Periodic  and Non-Periodic) is not empty. <br><li> Accept L1 Request but delay SLEEPM assertion until RX  SINK Buffer is empty. Prevent L1 Entry if a Control Transfer is in progress on any  Control Endpoint. Ability to Flush TxFIFO even if PHY Clock  is gated.  Values:  <br><li> 0x1 (ENABLED): Enhanced LPM Support is enabled Value After Reset: * Varies based on Configuration */
          __IM  uint32_t PHY_DATA_WIDTH            : 2 ;     /*!< [15:14] : UTMI+ PHY/ULPI-to-Internal UTMI+ Wrapper Data Width  (PhyDataWidth)<vr>When a ULPI PHY is used, an internal  wrapper converts ULPI to UTMI+. <br><li> 2'b00: 8 bits <br><li> 2'b01: 16 bits <br><li> 2'b10: 8/16 bits, software selectable <br><li> Others: Reserved Values:  <br><li> 0x0 (WIDTH1): 8 bits <br><li> 0x1 (WIDTH2): 16 bits <br><li> 0x2 (WIDTH3): 8/16 bits, software selectable Value After Reset: * Varies based on Configuration */
          __IM  uint32_t NUM_CTL_EPS               : 4 ;     /*!< [19:16] : Number of Device Mode Control Endpoints in Addition to  Endpoint 0 (NumCtlEps) Range: 0-15 Values:  <br><li> 0x0 (ENDPT0): End point 0 <br><li> 0x1 (ENDPT1): End point 1 <br><li> 0x2 (ENDPT2): End point 2 <br><li> 0x3 (ENDPT3): End point 3 <br><li> 0x4 (ENDPT4): End point 4 <br><li> 0x5 (ENDPT5): End point 5 <br><li> 0x6 (ENDPT6): End point 6 <br><li> 0x7 (ENDPT7): End point 7 <br><li> 0x8 (ENDPT8): End point 8 <br><li> 0x9 (ENDPT9): End point 9 <br><li> 0xa (ENDPT10): End point 10 <br><li> 0xb (ENDPT11): End point 11 <br><li> 0xc (ENDPT12): End point 12 <br><li> 0xd (ENDPT13): End point 13 <br><li> 0xe (ENDPT14): End point 14 <br><li> 0xf (ENDPT15): End point 15 Value After Reset: * Varies based on Configuration */
          __IM  uint32_t IDDG_FLTR                 : 1 ;     /*!< [20:20] : IDDIG Filter Enable (IddgFltr) <br><li> 1'b0: No filter <br><li> 1'b1: Filter Values:  <br><li> 0x0 (DISABLED): Iddig Filter Disabled <br><li> 0x1 (ENABLED): Iddig Filter Enabled Value After Reset: * Varies based on Configuration */
          __IM  uint32_t VBUS_VALID_FLTR           : 1 ;     /*!< [21:21] : VBUS Valid Filter Enabled (VBusValidFltr) <br><li> 1'b0: No filter <br><li> 1'b1: Filter Values:  <br><li> 0x0 (DISABLED): Vbus Valid Filter Disabled <br><li> 0x1 (ENABLED): Vbus Valid Filter Enabled Value After Reset: * Varies based on Configuration */
          __IM  uint32_t AVALID_FLTR               : 1 ;     /*!< [22:22] : a_valid Filter Enabled (AValidFltr) <br><li> 1'b0: No filter <br><li> 1'b1: Filter Values:  <br><li> 0x0 (DISABLED): No filter <br><li> 0x1 (ENABLED): Filter Value After Reset: * Varies based on Configuration */
          __IM  uint32_t BVALID_FLTR               : 1 ;     /*!< [23:23] : b_valid Filter Enabled (BValidFltr) <br><li> 1'b0: No filter <br><li> 1'b1: Filter Values:  <br><li> 0x0 (DISABLED): No Filter <br><li> 0x1 (ENABLED): Filter Value After Reset: * Varies based on Configuration */
          __IM  uint32_t SESS_END_FLTR             : 1 ;     /*!< [24:24] : session_end Filter Enabled (SessEndFltr) <br><li> 1'b0: No filter <br><li> 1'b1: Filter Values:  <br><li> 0x0 (DISABLED): No filter <br><li> 0x1 (ENABLED): Filter Value After Reset: * Varies based on Configuration */
          __IM  uint32_t DED_FIFO_MODE             : 1 ;     /*!< [25:25] : Enable Dedicated Transmit FIFO for device IN Endpoints (DedFifoMode) <br><li> 1'b0 : Dedicated Transmit FIFO Operation not enabled. <br><li> 1'b1 : Dedicated Transmit FIFO Operation enabled. Values:  <br><li> 0x0 (DISABLED): Dedicated Transmit FIFO Operation not enabled <br><li> 0x1 (ENABLED): Dedicated Transmit FIFO Operation enabled Value After Reset: * Varies based on Configuration */
          __IM  uint32_t IN_EPS                    : 4 ;     /*!< [29:26] : Number of Device Mode IN Endpoints Including Control  Endpoints (INEps) <br><li> 0: 1 IN Endpoint <br><li> 1: 2 IN Endpoints .... <br><li> 15: 16 IN Endpoints Values:  <br><li> 0x0 (ENDPT1): 1 IN Endpoint <br><li> 0x1 (ENDPT2): 2 IN Endpoints <br><li> 0x2 (ENDPT3): 3 IN Endpoints <br><li> 0x3 (ENDPT4): 4 IN Endpoints <br><li> 0x4 (ENDPT5): 5 IN Endpoints <br><li> 0x5 (ENDPT6): 6 IN Endpoints <br><li> 0x6 (ENDPT7): 7 IN Endpoints <br><li> 0x7 (ENDPT8): 8 IN Endpoints <br><li> 0x8 (ENDPT9): 9 IN Endpoints <br><li> 0x9 (ENDPT10): 10 IN Endpoints <br><li> 0xa (ENDPT11): 11 IN Endpoints <br><li> 0xb (ENDPT12): 12 IN Endpoints <br><li> 0xc (ENDPT13): 13 IN Endpoints <br><li> 0xd (ENDPT14): 14 IN Endpoints <br><li> 0xe (ENDPT15): 15 IN Endpoints <br><li> 0xf (ENDPT16): 16 IN Endpoints Value After Reset: * Varies based on Configuration */
          __IM  uint32_t DESC_DMA_ENABLED          : 1 ;     /*!< [30:30] : Scatter/Gather DMA configuration <br><li> 1'b0: Non-Scatter/Gather DMA configuration <br><li> 1'b1: Scatter/Gather DMA configuration Values:  <br><li> 0x0 (DISABLE): Non-Scatter/Gather DMA configuration <br><li> 0x1 (ENABLE): Scatter/Gather DMA configuration Value After Reset: * Varies based on Configuration */
          __IM  uint32_t GHWCFG4_DESC_DMA          : 1 ;     /*!< [31:31] : Scatter/Gather DMA configuration <br><li> 1'b0: Non Dynamic configuration <br><li> 1'b1: Dynamic configuration Note: This field is configured using the  OTG_EN_DESC_DMA parameter. Values:  <br><li> 0x0 (CONFIG1): Non Dynamic configuration <br><li> 0x1 (CONFIG2): Dynamic configuration Value After Reset: * Varies based on Configuration */
       } GHWCFG4b;
    };

    uint8_t              RSV_0X54[8]                   ;   /*!< 0x00000054~0x0000005b : reserved */

    union
    {
       __IOM uint32_t GDFIFOCFG;  /*!< 0x0000005c */ 
       
       struct
       {
          __IOM uint32_t GDFIFOCFG                 : 16;     /*!< [15:0] : GDFIFOCfg. This field is for dynamic programming of the DFIFO Size.  This value takes effect only when the application programs a  non zero value to this register. The value programmed must  conform to the guidelines described in 'FIFO RAM  Allocation'. The core does not have any corrective logic if the  FIFO sizes are programmed incorrectly. Value After Reset: * Varies based on Configuration */
          __IOM uint32_t EP_INFO_BASE_ADDR         : 16;     /*!< [31:16] : EPInfoBaseAddr. This field provides the start address of the EP info controller. Value After Reset: * Varies based on Configuration */
       } GDFIFOCFGb;
    };

    uint8_t              RSV_0X60[8]                   ;   /*!< 0x00000060~0x00000067 : reserved */

    union
    {
        uint32_t GINTMSK2;  /*!< 0x00000068 */ 
       
       struct
       {
                uint32_t RSV_34                    : 32;     /*!< [31:0] : reserved */
       } GINTMSK2b;
    };

    union
    {
        uint32_t GINTSTS2;  /*!< 0x0000006c */ 
       
       struct
       {
                uint32_t RSV_35                    : 32;     /*!< [31:0] : reserved */
       } GINTSTS2b;
    };

    uint8_t              RSV_0X70[144]                 ;   /*!< 0x00000070~0x000000ff : reserved */

    union
    {
       __IOM uint32_t HPTXFSIZ;  /*!< 0x00000100 */ 
       
       struct
       {
          __IOM uint32_t PTXF_ST_ADDR              : 16;     /*!< [15:0] : Host Periodic TxFIFO Start Address (PTxFStAddr) The power-on reset value of this register is the sum of the  Largest Rx Data FIFO Depth and Largest Non-periodic Tx  Data FIFO Depth.These parameters are: In shared FIFO operation: <br><li> OTG_RX_DFIFO_DEPTH +  OTG_TX_NPERIO_DFIFO_DEPTH  In dedicated FIFO mode: <br><li> OTG_RX_DFIFO_DEPTH +  OTG_TX_HNPERIO_DFIFO_DEPTH If Enable Dynamic  FIFO Sizing? was deselected in coreConsultant  (parameter OTG_DFIFO_DYNAMIC = 0), these flops are  optimized, and reads return the power-on value. If Enable  Dynamic FIFO Sizing? was selected in coreConsultant  (parameter OTG_DFIFO_DYNAMIC = 1), you can write a  new value in this field. Programmed values must not exceed the power-on value set  in coreConsultant. Value After Reset: * Varies based on Configuration */
          __IOM uint32_t PTXF_SIZE                 : 16;     /*!< [31:16] : Host Periodic TxFIFO Depth (PTxFSize) This value is in terms of 32-bit words. <br><li> Minimum value is 16 <br><li> Maximum value is 32,768 The power-on reset value of this register is specified as the  Largest Host Mode Periodic Tx Data FIFO Depth.  <br><li> If Enable Dynamic FIFO Sizing? was deselected in  coreConsultant (parameter OTG_DFIFO_DYNAMIC = 0),  these flops are optimized, and reads return the power-on  value. <br><li> If Enable Dynamic FIFO Sizing? was selected in  coreConsultant (parameter OTG_DFIFO_DYNAMIC = 1),  you can write a new value in this field.  Programmed values must not exceed the power-on value set  in coreConsultant. Value After Reset: * Varies based on Configuration */
       } HPTXFSIZb;
    };

    /*!< 0x00000104~0x00000123 : register for DIEPTXF group */
    union
    {
        union
        {
           __IOM uint32_t DIEPTXF_N[8];  /*!< 0x00000104 */ 
           
           struct
           {
              __IOM uint32_t IN_EP_N_TXF_ST_ADDR       : 11;     /*!< [10:0] : IN Endpoint FIFOn Transmit RAM Start Address (INEPnTxFStAddr) This field contains the memory start address for IN endpoint  Transmit FIFOn (0<n< = 15). The power-on reset value of  this register is specified as the Largest Rx Data FIFO Depth.  The power-on reset value of this register is calculated  according to the following formula:  OTG_RX_DFIFO_DEPTH + SUM of  OTG_TX_DINEP_DFIFO_DEPTH_'i' (where x = 0 to n  1) If  at POR the calculated value (C) exceeds 65535, then the  Reset value becomes Reset Value(A) = (C 65536). Example:  If start address of IN endpoint FIFO 1 is  OTG_RX_DFIFO_DEPTH +  OTG_TX_DINEP_DFIFO_DEPTH_ 0 and start address of IN  endpoint FIFO 2 is OTG_RX_DFIFO_DEPTH +  OTG_TX_DINEP_DFIFO_DEPTH_ 0 +  OTG_TX_DINEP_DFIFO_DEPTH_ 1. <br><li> If Enable Dynamic FIFO Sizing is deselected in  coreConsultant (OTG_DFIFO_DYNAMIC = 0), this field is  read-only and read value is the power-on reset value. <br><li> If Enable Dynamic FIFO Sizing is selected in  coreConsultant (OTG_DFIFO_DYNAMIC = 1), and you  have calculated or programmed a new value for RxFIFO  depth or TX FIFO depths, you can program their values  according to the above formula. Programmed values  must not exceed the power-on value set in coreConsultant. Value After Reset: * Varies based on Configuration */
                    uint32_t RSV_88                    : 5 ;     /*!< [15:11] : reserved */
              __IOM uint32_t IN_EP_N_TXF_DEP           : 9 ;     /*!< [24:16] : IN Endpoint TxFIFO Depth (INEPnTxFDep) This value is in terms of 32-bit words. <br><li> Minimum value is 16 <br><li> Maximum value is 32,768 The power-on reset value of this register is specified as the  Largest IN Endpoint FIFO number Depth (parameter  OTG_TX_DINEP_DFIFO_DEPTH_n) during coreConsultant  configuration (0 < i <= 15). <br><li> If "Enable Dynamic FIFO Sizing?" was deselected in  coreConsultant (parameter OTG_DFIFO_DYNAMIC = 0),  these flops are optimized, and reads return the power-on  value. <br><li> If "Enable Dynamic FIFO Sizing?" was selected in  coreConsultant (parameter OTG_DFIFO_DYNAMIC = 1),  you can write a new value in this field. Programmed values must not exceed the power-on value. Value After Reset: * Varies based on Configuration */
                    uint32_t RSV_89                    : 7 ;     /*!< [31:25] : reserved */
           } DIEPTXF_Nb[8];
        };
    }; 

    uint8_t              RSV_0X124[732]                ;   /*!< 0x00000124~0x000003ff : reserved */

    union
    {
       __IOM uint32_t HCFG;  /*!< 0x00000400 */ 
       
       struct
       {
          __IOM uint32_t FS_LSPCLK_SEL             : 2 ;     /*!< [1:0] : FS/LS PHY Clock Select (FSLSPclkSel) When the core is in FS Host mode <br><li> 2'b00: PHY clock is running at 30/60 MHz <br><li> 2'b01: PHY clock is running at 48 MHz <br><li> Others: Reserved When the core is in LS Host mode <br><li> 2'b00: PHY clock is running at 30/60 MHz. When the  UTMI+/ULPI PHY Low Power mode is not selected, use  30/60 MHz. <br><li> 2'b01: PHY clock is running at 48 MHz. When the UTMI+  PHY Low Power mode is selected, use 48MHz If the PHY  supplies a 48 MHz clock during LS mode. <br><li> 2'b10: PHY clock is running at 6 MHz. In USB 1.1 FS  mode, use 6 MHz when the UTMI+ PHY Low Power  mode is selected and the PHY supplies a 6 MHz clock  during LS mode. If you select a 6 MHz clock during LS  mode, you must do a soft reset. <br><li> 2'b11: Reserved Notes: <br><li> When Core in FS mode, the internal and external clocks  have the same frequency. <br><li> When Core in LS mode, - If FSLSPclkSel = 2'b00: Internal and external clocks  have the same frequency - If FSLSPclkSel = 2'b10: Internal clock is the divided by  eight version of external 48 MHz clock Values:  <br><li> 0x0 (CLK3060): PHY clock is running at 30/60 MHz <br><li> 0x1 (CLK48): PHY clock is running at 48 MHz <br><li> 0x2 (CLK6): PHY clock is running at 6 MHz */
          __IOM uint32_t FS_LSSUPP                 : 1 ;     /*!< [2:2] : FS- and LS-Only Support (FSLSSupp) The application uses this bit to control the core's  enumeration speed. Using this bit, the application can make  the core enumerate as a FS host, even If the connected  device supports HS traffic. Do not make changes to this field  after initial programming. <br><li> 1'b0: HS/FS/LS, based on the maximum speed supported by the connected device <br><li> 1'b1: FS/LS-only, even If the connected device can support HS Values:  <br><li> 0x0 (HSFSLS):  HS/FS/LS, based on the maximum speed supported by the connected device <br><li> 0x1 (FSLS):  FS/LS-only, even if the connected device can support HS */
                uint32_t RSV_36                    : 4 ;     /*!< [6:3] : reserved */
          __IOM uint32_t ENA32KHZ_S                : 1 ;     /*!< [7:7] : Enable 32 KHz Suspend mode (Ena32KHzS) This bit can be set only in FS PHY interface is selected.   Else, this bit needs to be set to zero.  When FS PHY  interface is chosen and this bit is set,  the core expects that  the PHY clock during Suspend is switched  from 48 MHz to 32 KHz. Values:  <br><li> 0x0 (DISABLED): 32 KHz Suspend mode disabled <br><li> 0x1 (ENABLED): 32 KHz Suspend mode enabled */
          __IOM uint32_t HCFG_RES_VALID            : 8 ;     /*!< [15:8] : Resume Validation Period  (ResValid) This field is effective only when HCFG.Ena32KHzS is set. It  will control the resume period when the core resumes from  suspend.  The core counts for 'ResValid' number of clock  cycles to detect a  valid resume when this is set. */
                uint32_t RSV_37                    : 7 ;     /*!< [22:16] : reserved */
          __IOM uint32_t HCFG_DESC_DMA             : 1 ;     /*!< [23:23] : Enable Scatter/gather DMA in Host mode (DescDMA) When the Scatter/Gather DMA option selected during  configuration of the RTL, the application can set this bit  during initialization to enable the Scatter/Gather DMA operation. Note: This bit must be modified only once after a reset. The following combinations are available for programming: <br><li> GAHBCFG.DMAEn=0,HCFG.DescDMA=0 => Slave mode  <br><li> GAHBCFG.DMAEn=0,HCFG.DescDMA=1 => Invalid <br><li> GAHBCFG.DMAEn=1,HCFG.DescDMA=0 => Buffered DMA mode  <br><li> GAHBCFG.DMAEn=1,HCFG.DescDMA=1 => Scatter/Gather DMA mode Values:  <br><li> 0x0 (DISABLED): Scatter/Gather DMA in Host mode is disabled <br><li> 0x1 (ENABLED): Scatter/Gather DMA selected */
          __IOM uint32_t FR_LIST_EN                : 2 ;     /*!< [25:24] : Frame List Entries(FrListEn) The value in the register specifies the number of entries in  the Frame list. This field is valid only in Scatter/Gather DMA mode. <br><li> 2'b00: 8 Entries  <br><li> 2'b01: 16 Entries <br><li> 2'b10: 32 Entries <br><li> 2'b11: 64 Entries Values:  <br><li> 0x0 (ENTRY8): 8 Entries <br><li> 0x1 (ENTRY16): 16 Entries <br><li> 0x2 (ENTRY32): 32 Entries <br><li> 0x3 (ENTRY63): 64 Entries */
          __IOM uint32_t PER_SCHED_ENA             : 1 ;     /*!< [26:26] : Enable Periodic Scheduling (PerSchedEna): Applicable in host DDMA mode only. Enables periodic  scheduling within the core. Initially, the bit is reset. The core  will not process any periodic channels. As soon as this bit is set, the core will get ready to start  scheduling periodic channels and  sets  HCFG.PerSchedStat. The setting of HCFG.PerSchedStat  indicates the core has enabled periodic scheduling. Once  HCFG.PerSchedEna is set,  the application is not supposed  to again reset the bit unless HCFG.PerSchedStat is set. As soon as this bit is reset, the core will get ready to stop  scheduling periodic channels and resets HCFG.PerSchedStat. Values:  <br><li> 0x0 (DISABLED): Disables periodic scheduling within the core <br><li> 0x1 (ENABLED): Enables periodic scheduling within the core */
                uint32_t RSV_38                    : 4 ;     /*!< [30:27] : reserved */
          __IOM uint32_t MODE_CH_TIM_EN            : 1 ;     /*!< [31:31] : Mode Change Ready Timer Enable (ModeChTimEn) This bit is used to enable/disable the Host core to wait  200  PHY clock cycles at the end of Resume to change the  opmode signal to the PHY to 00  after Suspend or LPM. <br><li> 1'b0 : The Host core waits for either 200 PHY clock cycles  or a linestate of SE0 at the end of resume to the change  the opmode from 2'b10 to 2'b00 <br><li> 1'b1 : The Host core waits only for a linstate of SE0 at the  end of resume to change the opmode from 2'b10 to 2'b00. Values:  <br><li> 0x0 (ENABLED):  The Host core waits for either 200 PHY clock cycles or a  linestate of SE0 at the end of resume to change the opmode  from 0x2 to 0x0 <br><li> 0x1 (DISABLED):  The Host core waits only for a linestate of SE0 at the end of  resume to change the opmode from 0x2 to 0x0 */
       } HCFGb;
    };

    union
    {
       __IOM uint32_t HFIR;  /*!< 0x00000404 */ 
       
       struct
       {
          __IOM uint32_t FR_INT                    : 16;     /*!< [15:0] : Frame Interval (FrInt) The value that the application programs to this field specifies  the interval between two consecutive SOFs (FS) or micro-  SOFs (HS) or Keep-Alive tokens (HS). This field contains the  number of PHY clocks that constitute the required frame  interval. The Default value set in this field  is for FS operation  when the PHY clock frequency is 60 MHz. The application  can write a value to this register only after the Port Enable bit  of the Host Port Control and Status register  (HPRT.PrtEnaPort) has been Set. If no value is programmed,  the core calculates the value based on the PHY clock  specified in the FS/LS PHY Clock Select field of the Host  Configuration register (HCFG.FSLSPclkSel). Do not change  the value of this field after the initial configuration. <br><li> 125 s * (PHY clock frequency for HS) <br><li> 1 ms * (PHY clock frequency for FS/LS) */
          __IOM uint32_t HFIRRLD_CTRL              : 1 ;     /*!< [16:16] : Reload Control (HFIRRldCtrl) This bit allows dynamic reloading of the HFIR register during run time.  <br><li> 1'b0 : The HFIR cannot be reloaded dynamically <br><li> 1'b1: the HFIR can be dynamically reloaded during runtime.  This bit needs to be programmed during initial configuration  and its value should not be changed during runtime.  Values:  <br><li> 0x0 (DISABLED): The HFIR cannot be reloaded dynamically <br><li> 0x1 (ENABLED):  The HFIR can be dynamically reloaded during runtime */
                uint32_t RSV_39                    : 15;     /*!< [31:17] : reserved */
       } HFIRb;
    };

    union
    {
       __IM uint32_t HFNUM;  /*!< 0x00000408 */ 
       
       struct
       {
          __IM  uint32_t FR_NUM                    : 16;     /*!< [15:0] : Frame Number (FrNum) This field increments when a new SOF is transmitted on the  USB, and is reset to 0 when it reaches 16'h3FFF. Values:  <br><li> 0x0 (INACTIVE): No SOF is transmitted <br><li> 0x1 (ACTIVE): SOF is transmitted */
          __IM  uint32_t FR_REM                    : 16;     /*!< [31:16] : Frame Time Remaining (FrRem) Indicates the amount of time remaining in the current  microframe (HS) or Frame (FS/LS), in terms of PHY clocks.  This field decrements on each PHY clock. When it reaches  zero, this field is reloaded with the value in the Frame Interval  register and a new SOF is transmitted on the USB. */
       } HFNUMb;
    };

    uint8_t              RSV_0X40c[4]                  ;   /*!< 0x0000040c~0x0000040f : reserved */

    union
    {
       __IM uint32_t HPTXSTS;  /*!< 0x00000410 */ 
       
       struct
       {
          __IM  uint32_t PTXF_SPC_AVAIL            : 16;     /*!< [15:0] : Periodic Transmit Data FIFO Space Available (PTxFSpcAvail) Indicates the number of free locations available to be written  to in the Periodic TxFIFO. Values are in terms of 32-bit words <br><li> 16'h0    : Periodic TxFIFO is full <br><li> 16'h1    : 1 word available <br><li> 16'h2    : 2 words available <br><li> 16'hn    : n words available (where 0  n  32,768) <br><li> 16'h8000 : 32,768 words <br><li> Others   : Reserved Value After Reset: * Varies based on Configuration */
          __IM  uint32_t PTX_QSPC_AVAIL            : 8 ;     /*!< [23:16] : Periodic Transmit Request Queue Space Available (PTxQSpcAvail) Indicates the number of free locations available to be written  in the Periodic Transmit Request Queue. This queue holds  both IN and OUT requests. <br><li> 8'h0: Periodic Transmit Request Queue is full <br><li> 8'h1: 1 location available <br><li> 8'h2: 2 locations available <br><li> n: n locations available (0 <= n <= 16) <br><li> Others: Reserved Values:  <br><li> 0x0 (FULL): Periodic Transmit Request Queue is full <br><li> 0x1 (FREE1): 1 location available <br><li> 0x2 (FREE2): 2 locations available <br><li> 0x3 (FREE3): 3 locations available <br><li> 0x4 (FREE4): 4 locations available <br><li> 0x5 (FREE5): 5 locations available <br><li> 0x6 (FREE6): 6 locations available <br><li> 0x7 (FREE7): 7 locations available <br><li> 0x8 (FREE8): 8 locations available <br><li> 0x9 (FREE9): 9 locations available <br><li> 0xa (FREE10): 10 locations available <br><li> 0xb (FREE11): 11 locations available <br><li> 0xc (FREE12): 12 locations available <br><li> 0xd (FREE13): 13 locations available <br><li> 0xe (FREE14): 14 locations available <br><li> 0xf (FREE15): 15 locations available Value After Reset: * Varies based on Configuration */
          __IM  uint32_t PTX_QTOP                  : 8 ;     /*!< [31:24] : Top of the Periodic Transmit Request Queue (PTxQTop) This indicates the Entry in the Periodic Tx Request Queue  that is currently being processes by the MAC. This register is used for debugging. <br><li> Bit [31]: Odd/Even (micro)Frame - 1'b0: send in even (micro)Frame - 1'b1: send in odd (micro)Frame <br><li> Bits [30:27]: Channel/endpoint number <br><li> Bits [26:25]: Type - 2'b00: IN/OUT - 2'b01: Zero-length packet - 2'b10: CSPLIT - 2'b11: Disable channel command <br><li> Bit [24]: Terminate (last Entry for the selected  channel/endpoint) Value After Reset: * Varies based on Configuration */
       } HPTXSTSb;
    };

    union
    {
       __IO uint32_t HAINT;  /*!< 0x00000414 */ 
       
       struct
       {
          __IO  uint32_t HAIN_T                    : 16;     /*!< [15:0] : Channel Interrupt for channel no. Values:  <br><li> 0x0 (INACTIVE): Not active <br><li> 0x1 (ACTIVE): Host Channel Interrupt Range Variable[x]: OTG_NUM_HOST_CHAN - 1 */
                uint32_t RSV_40                    : 16;     /*!< [31:16] : reserved */
       } HAINTb;
    };

    union
    {
       __IOM uint32_t HAINTMSK;  /*!< 0x00000418 */ 
       
       struct
       {
          __IOM uint32_t HAIN_TMSK                 : 16;     /*!< [15:0] : Channel Interrupt Mask (HAINTMsk) One bit per channel: Bit  0 for channel 0, bit 15 for channel 15 Values:  <br><li> 0x0 (UNMASK): Unmask Channel interrupt <br><li> 0x1 (MASK): Mask Channel interrupt */
                uint32_t RSV_41                    : 16;     /*!< [31:16] : reserved */
       } HAINTMSKb;
    };

    union
    {
       __IOM uint32_t HFLBADDR;  /*!< 0x0000041c */ 
       
       struct
       {
          __IOM uint32_t HFLBADDR                  : 32;     /*!< [31:0] : The starting address of the Frame list. This register is used only for Isochronous and Interrupt Channels. */
       } HFLBADDRb;
    };

    uint8_t              RSV_0X420[32]                 ;   /*!< 0x00000420~0x0000043f : reserved */

    union
    {
       __IOM uint32_t HPRT;  /*!< 0x00000440 */ 
       
       struct
       {
          __IM  uint32_t PRT_CONN_STS              : 1 ;     /*!< [0:0] : Port Connect Status (PrtConnSts) <br><li> 0: No device is attached to the port. <br><li> 1: A device is attached to the port. Values:  <br><li> 0x0 (NOTATTACHED): No device is attached to the port <br><li> 0x1 (ATTACHED): A device is attached to the port */
          __IOM uint32_t PRT_CONN_DET              : 1 ;     /*!< [1:1] : Port Connect Detected (PrtConnDet) The core sets this bit when a device connection is detected  to trigger an interrupt to the application using the Host Port  Interrupt bit of the Core Interrupt register  (GINTSTS.PrtInt).This bit can be set only by the core and the  application should write 1 to clear it.The application must  write a 1 to this bit to clear the interrupt. Values:  <br><li> 0x1 (ACTIVE): Device connection detected <br><li> 0x0 (INACTIVE): No device connection detected */
          __IOM uint32_t PRT_ENA                   : 1 ;     /*!< [2:2] : Port Enable (PrtEna) A port is enabled only by the core after a reset sequence,  and is disabled by an overcurrent condition, a disconnect  condition, or by the application clearing this bit. The  application cannot Set this bit by a register write. It can only  clear it to disable the port by writing 1. This bit does not  trigger any interrupt to the application. <br><li> 1'b0: Port disabled <br><li> 1'b1: Port enabled Values:  <br><li> 0x0 (DISABLED): Port disabled <br><li> 0x1 (ENABLED): Port enabled */
          __IOM uint32_t PRT_EN_CHNG               : 1 ;     /*!< [3:3] : Port Enable/Disable Change (PrtEnChng) The core sets this bit when the status of the Port Enable bit  [2] of this register changes.This bit can be set only by the  core and the application should write 1 to clear it. Values:  <br><li> 0x0 (INACTIVE): Port Enable bit 2 has not changed <br><li> 0x1 (ACTIVE): Port Enable bit 2 changed */
          __IM  uint32_t PRT_OVR_CURR_ACT          : 1 ;     /*!< [4:4] : Port Overcurrent Active (PrtOvrCurrAct) Indicates the overcurrent condition of the port. <br><li> 1'b0: No overcurrent condition <br><li> 1'b1: Overcurrent condition Values:  <br><li> 0x0 (INACTIVE): No overcurrent condition <br><li> 0x1 (ACTIVE): Overcurrent condition */
          __IOM uint32_t PRT_OVR_CURR_CHNG         : 1 ;     /*!< [5:5] : Port Overcurrent Change (PrtOvrCurrChng) The core sets this bit when the status of the Port Overcurrent  Active bit (bit 4) in this register changes.This bit can be set  only by the core and the application should write 1 to clear it Values:  <br><li> 0x0 (INACTIVE): Status of port overcurrent status is not  changed <br><li> 0x1 (ACTIVE): Status of port overcurrent changed */
          __IOM uint32_t PRT_RES                   : 1 ;     /*!< [6:6] : Port Resume (PrtRes) The application sets this bit to drive resume signaling on the  port. The core continues to drive the resume signal until the  application clears this bit. If the core detects a USB remote wakeup sequence, as  indicated by the Port Resume/Remote Wakeup Detected  Interrupt bit of the Core Interrupt register  (GINTSTS.WkUpInt), the core starts driving resume  signaling without application intervention and clears this bit  when it detects a disconnect condition. The read value of this  bit indicates whether the core is currently driving resume signaling. <br><li> 1'b0: No resume driven <br><li> 1'b1: Resume driven When LPM is enabled, In L1 state the behavior of this bit is  as follows: The application sets this bit to drive resume  signaling on the port. The core continues to drive the resume  signal until a pre-determined time specified in  GLPMCFG.HIRD_Thres[3:0] field. If the core detects a USB  remote wakeup sequence, as indicated by the Port  L1Resume/Remote L1Wakeup Detected  Interrupt bit of the  Core Interrupt register (GINTSTS.L1WkUpInt),  the core  starts driving resume signaling without application  intervention and clears this bit at the end of resume.This bit  can be set by both core or application and also cleared by  core or application. This bit is cleared by the core even if  there is no device connected to the Host. Values:  <br><li> 0x0 (NORESUME): No resume driven <br><li> 0x1 (RESUME): Resume driven */
          __IOM uint32_t PRT_SUSP                  : 1 ;     /*!< [7:7] : Port Suspend (PrtSusp) The application sets this bit to put this port in Suspend mode.  The core only stops sending SOFs when this is Set. To stop  the PHY clock, the application must Set the Port Clock Stop  bit, which asserts the suspend input pin of the PHY. The read value of this bit reflects the current suspend status  of the port. This bit is cleared by the core after a remote  wakeup signal is detected or the application sets the Port  Reset bit or Port Resume bit in this register or the  Resume/Remote Wakeup Detected Interrupt bit or  Disconnect Detected Interrupt bit in the Core Interrupt  register (GINTSTS.WkUpInt or GINTSTS.DisconnInt,  respectively).This bit is cleared by the core even if there is no  device connected to the Host. <br><li> 1'b0: Port not in Suspend mode <br><li> 1'b1: Port in Suspend mode Values:  <br><li> 0x0 (INACTIVE): Port not in Suspend mode <br><li> 0x1 (ACTIVE): Port in Suspend mode */
          __IOM uint32_t PRT_RST                   : 1 ;     /*!< [8:8] : Port Reset (PrtRst) When the application sets this bit, a reset sequence is  started on this port. The application must time the reset  period and clear this bit after the reset sequence is complete. <br><li> 1'b0: Port not in reset <br><li> 1'b1: Port in reset The application must leave this bit set for at least a minimum  duration mentioned below to start a reset on the port. The  application can leave it set for another 10 ms in addition to  the required minimum duration, before clearing the bit, even  though there is no maximum limit Set by the USB  standard.This bit is cleared by the core even if there is no  device connected to the Host. <br><li> High speed: 50 ms <br><li> Full speed/Low speed: 10 ms Values:  <br><li> 0x0 (DISABLED): Port not in reset <br><li> 0x1 (ENABLED): Port in reset */
                uint32_t RSV_42                    : 1 ;     /*!< [9:9] : reserved */
          __IM  uint32_t PRT_LN_STS                : 2 ;     /*!< [11:10] : Port Line Status (PrtLnSts) Indicates the current logic level USB data lines <br><li> Bit [10]: Logic level of D+ <br><li> Bit [11]: Logic level of D- Values:  <br><li> 0x1 (PLUSD): Logic level of D+ <br><li> 0x2 (MINUSD): Logic level of D- */
          __IOM uint32_t PRT_PWR                   : 1 ;     /*!< [12:12] : Port Power (PrtPwr) The application uses this field to control power to this port  (write 1'b1 to set to 1'b1 and write 1'b0 to set to 1'b0), and  the core can clear this bit on an over current condition. <br><li> 1'b0: Power off <br><li> 1'b1: Power on Note: This bit is interface independent. The application  needs to program this bit for all interfaces as described in the  host programming flow in the Programming Guide. Values:  <br><li> 0x0 (OFF): Power off <br><li> 0x1 (ON): Power on */
          __IOM uint32_t PRT_TST_CTL               : 4 ;     /*!< [16:13] : Port Test Control (PrtTstCtl) The application writes a nonzero value to this field to put the  port into a Test mode, and the corresponding pattern is  signaled on the port. <br><li> 4'b0000: Test mode disabled <br><li> 4'b0001: Test_J mode <br><li> 4'b0010: Test_K mode <br><li> 4'b0011: Test_SE0_NAK mode <br><li> 4'b0100: Test_Packet mode <br><li> 4'b0101: Test_Force_Enable <br><li> Others: Reserved To move the DWC_otg controller to test mode, you must set  this field. Complete the following steps to move the DWC_otg  core to test mode: <br><li> 1. Power on the core. <br><li> 2. Load the DWC_otg driver. <br><li> 3. Connect an HS device and enumerate to HS mode. <br><li> 4. Access the HPRT register to send test packets. <br><li> 5. Remove the device and connect to fixture (OPT) port.  The DWC_otg host core continues sending out test  packets. <br><li> 6. Test the eye diagram. Values:  <br><li> 0x0 (DISABLED): Test mode disabled <br><li> 0x1 (TESTJ): Test_J mode <br><li> 0x2 (TESTK): Test_K mode <br><li> 0x3 (TESTSN): Test_SE0_NAK mode <br><li> 0x4 (TESTPM): Test_Packet mode <br><li> 0x5 (TESTFENB): Test_force_Enable */
          __IM  uint32_t PRT_SPD                   : 2 ;     /*!< [18:17] : Port Speed (PrtSpd) Indicates the speed of the device attached to this port. <br><li> 2'b00: High speed <br><li> 2'b01: Full speed <br><li> 2'b10: Low speed <br><li> 2'b11: Reserved Values:  <br><li> 0x0 (HIGHSPD): High speed <br><li> 0x1 (FULLSPD): Full speed <br><li> 0x2 (LOWSPD): Low speed <br><li> 0x3 (RESERVED): Reserved */
                uint32_t RSV_43                    : 13;     /*!< [31:19] : reserved */
       } HPRTb;
    };

    uint8_t              RSV_0X444[188]                ;   /*!< 0x00000444~0x000004ff : reserved */

    /*!< 0x00000500~0x000006ff : register for hc group */
    struct
    {
            union
            {
               __IOM uint32_t HCCHAR_N;  /*!< 0x00000500 */ 
               
               struct
               {
                  __IOM uint32_t MPS                       : 11;     /*!< [10:0] : Maximum Packet Size (MPS) Indicates the maximum packet size of the associated endpoint. */
                  __IOM uint32_t EP_NUM                    : 4 ;     /*!< [14:11] : Endpoint Number (EPNum) Indicates the endpoint number on the device serving as the  data source or sink. Values:  <br><li> 0x0 (ENDPT0): End point 0 <br><li> 0x1 (ENDPT1): End point 1 <br><li> 0x2 (ENDPT2): End point 2 <br><li> 0x3 (ENDPT3): End point 3 <br><li> 0x4 (ENDPT4): End point 4 <br><li> 0x5 (ENDPT5): End point 5 <br><li> 0x6 (ENDPT6): End point 6 <br><li> 0x7 (ENDPT7): End point 7 <br><li> 0x8 (ENDPT8): End point 8 <br><li> 0x9 (ENDPT9): End point 9 <br><li> 0xa (ENDPT10): End point 10 <br><li> 0xb (ENDPT11): End point 11 <br><li> 0xc (ENDPT12): End point 12 <br><li> 0xd (ENDPT13): End point 13 <br><li> 0xe (ENDPT14): End point 14 <br><li> 0xf (ENDPT15): End point 15 */
                  __IOM uint32_t HCCHAR_N_EP_DIR           : 1 ;     /*!< [15:15] : Endpoint Direction (EPDir) Indicates whether the transaction is IN or OUT. <br><li> 1'b0: OUT <br><li> 1'b1: IN Values:  <br><li> 0x0 (OUT): OUT Direction <br><li> 0x1 (IN): IN Direction */
                        uint32_t RSV_90                    : 1 ;     /*!< [16:16] : reserved */
                  __IOM uint32_t LSPD_DEV                  : 1 ;     /*!< [17:17] : Low-Speed Device (LSpdDev) This field is Set by the application to indicate that this  channel is communicating to a low-speed device. The application must program this bit when a low speed  device is connected to the host through an FS HUB. The  DWC_otg Host core uses this field to drive the  XCVR_SELECT signal to 2'b11 while communicating to the  LS Device through the FS hub. Note: In a peer to peer setup, the DWC_otg Host core  ignores this bit even if it is set by the application software. Values:  <br><li> 0x0 (DISABLED): Not Communicating with low speed  device <br><li> 0x1 (ENABLED): Communicating with low speed device */
                  __IOM uint32_t EP_TYPE                   : 2 ;     /*!< [19:18] : Endpoint Type (EPType) Indicates the transfer type selected. <br><li> 2'b00: Control <br><li> 2'b01: Isochronous <br><li> 2'b10: Bulk <br><li> 2'b11: Interrupt Values:  <br><li> 0x0 (CTRL): Control <br><li> 0x1 (ISOC): Isochronous <br><li> 0x2 (BULK): Bulk <br><li> 0x3 (INTERR): Interrupt */
                  __IOM uint32_t EC                        : 2 ;     /*!< [21:20] : Multi Count (MC) / Error Count (EC) When the Split Enable bit of the Host Channel-n Split Control  register (HCSPLTn.SpltEna) is reset (1'b0), this field  indicates to the host the number of transactions that must be  executed per microframe for this periodic endpoint. For non  periodic transfers, this field is used only in DMA mode, and  specifies the number packets to be fetched for this channel  before the internal DMA engine changes arbitration. <br><li> 2'b00: Reserved This field yields undefined results. <br><li> 2'b01: 1 transaction <br><li> 2'b10: 2 transactions to be issued for this endpoint per  microframe <br><li> 2'b11: 3 transactions to be issued for this endpoint per  microframe When HCSPLTn.SpltEna is Set (1'b1), this field indicates the  number of immediate retries to be performed for a periodic  split transactions on transaction errors. This field must be Set  to at least 2'b01. Values:  <br><li> 0x0 (RESERVED): Reserved. This field yields undefined  result <br><li> 0x1 (TRANSONE): 1 transaction <br><li> 0x2 (TRANSTWO):  2 transactions to be issued for this endpoint per microframe <br><li> 0x3 (TRANSTHREE):  3 transactions to be issued for this endpoint per microframe */
                  __IOM uint32_t HCCHAR_N_DEV_ADDR         : 7 ;     /*!< [28:22] : Device Address (DevAddr) This field selects the specific device serving as the data source or sink. */
                  __IOM uint32_t ODD_FRM                   : 1 ;     /*!< [29:29] : Odd Frame (OddFrm) This field is set (reset) by the application to indicate that the  OTG host must perform  a transfer in an odd (micro)Frame.  This field is applicable for only periodic  (isochronous and  interrupt) transactions. <br><li> 1'b0: Even (micro)Frame <br><li> 1'b1: Odd (micro)Frame Values:  <br><li> 0x0 (EFRAME): Even Frame Transfer <br><li> 0x1 (OFRAME): Odd Frame Transfer */
                  __IOM uint32_t CH_DIS                    : 1 ;     /*!< [30:30] : Channel Disable (ChDis) The application sets this bit to stop transmitting/receiving  data on a channel, even before the transfer for that channel  is complete. The application must wait for the Channel  Disabled interrupt before treating the channel as disabled. Values:  <br><li> 0x0 (INACTIVE): Transmit/Recieve normal <br><li> 0x1 (ACTIVE): Stop transmitting/receiving data on channel */
                  __IOM uint32_t CH_ENA                    : 1 ;     /*!< [31:31] : Channel Enable (ChEna) When Scatter/Gather mode is enabled  <br><li> 1'b0: Indicates that the descriptor structure is not yet  ready.  <br><li> 1'b1:  Indicates  that  the  descriptor  structure  and  data   buffer  with data is setup and this channel can access the  descriptor.  When Scatter/Gather mode is disabled  This field is set by the application and cleared by the OTG  host.   <br><li> 1'b0: Channel disabled   <br><li> 1'b1: Channel enabled */
               } HCCHAR_Nb;
            };
    
            union
            {
               __IOM uint32_t HCSPLT_N;  /*!< 0x00000504 */ 
               
               struct
               {
                  __IOM uint32_t PRT_ADDR                  : 7 ;     /*!< [6:0] : Port Address (PrtAddr) This field is the port number of the recipient transaction translator. */
                  __IOM uint32_t HUB_ADDR                  : 7 ;     /*!< [13:7] : Hub Address (HubAddr) This field holds the device address of the transaction translator's hub. */
                  __IOM uint32_t XACT_POS                  : 2 ;     /*!< [15:14] : Transaction Position (XactPos) This field is used to determine whether to send all, first,  middle, or last payloads with each OUT transaction. <br><li> 2'b11: All. This is the entire data payload is of this  transaction (which is less than or equal to 188 bytes). <br><li> 2'b10: Begin. This is the first data payload of this  transaction (which is larger than 188 bytes). <br><li> 2'b00: Mid. This is the middle payload of this transaction  (which is larger than 188 bytes). <br><li> 2'b01: End. This is the last payload of this transaction  (which is larger than 188 bytes). Values:  <br><li> 0x0 (MIDDLE):  Mid. This is the middle payload of this transaction (which is  larger than 188 bytes) <br><li> 0x1 (END):  End. This is the last payload of this transaction (which is  larger than 188 bytes) <br><li> 0x2 (BEGIN):  Begin. This is the first data payload of this transaction (which  is larger than 188 bytes) <br><li> 0x3 (ALL):  All. This is the entire data payload of this transaction (which  is less than or equal to 188 bytes) */
                  __IOM uint32_t COMP_SPLT                 : 1 ;     /*!< [16:16] : Do Complete Split (CompSplt) The application sets this field to request the OTG host to  perform a complete split transaction. Values:  <br><li> 0x0 (NOSPLIT): No complete split transaction <br><li> 0x1 (SPLIT): Complete Split transaction */
                        uint32_t RSV_91                    : 14;     /*!< [30:17] : reserved */
                  __IOM uint32_t SPLT_ENA                  : 1 ;     /*!< [31:31] : Split Enable (SpltEna) The application sets this field to indicate that this channel is  enabled to perform split transactions. Values:  <br><li> 0x0 (DISABLED): Split not enabled <br><li> 0x1 (ENABLED): Split enabled */
               } HCSPLT_Nb;
            };
    
            union
            {
               __IOM uint32_t HCINT_N;  /*!< 0x00000508 */ 
               
               struct
               {
                  __IOM uint32_t HCIN_T_N_XFER_COMPL       : 1 ;     /*!< [0:0] : Transfer Completed (XferCompl) Transfer completed normally without any errors.This bit can  be set only by the core and the application should write 1 to clear it. <br><li> For Scatter/Gather DMA mode, it indicates that current  descriptor processing got completed with IOC bit set in its descriptor. <br><li> In non Scatter/Gather DMA mode, it indicates that  Transfer completed normally without any errors. Values:  <br><li> 0x0 (INACTIVE): Transfer in progress or No Active Transfer <br><li> 0x1 (ACTIVE): Transfer completed normally without any errors */
                  __IOM uint32_t CH_HLTD                   : 1 ;     /*!< [1:1] : Channel Halted (ChHltd) In non Scatter/Gather DMA mode, it indicates the transfer  completed abnormally either because of any USB  transaction error or in response to disable request by the  application or because of a completed transfer. In Scatter/gather DMA mode, this indicates that transfer  completed due to any of the following <br><li> EOL being set in descriptor <br><li> AHB error <br><li> Excessive transaction errors <br><li> Babble <br><li> Stall Values:  <br><li> 0x0 (INACTIVE): Channel not halted <br><li> 0x1 (ACTIVE): Channel Halted */
                  __IOM uint32_t HCIN_T_N_AHB_ERR          : 1 ;     /*!< [2:2] : AHB Error (AHBErr) This is generated only in Internal DMA mode when there is  an AHB error during AHB read/write. The application can  read the corresponding channel's DMA address register to  get the error address. For details, see "AHB Error Handling"  in the Programming Guide. Values:  <br><li> 0x0 (INACTIVE): No AHB error <br><li> 0x1 (ACTIVE): AHB error during AHB read/write */
                  __IOM uint32_t STALL                     : 1 ;     /*!< [3:3] : STALL Response Received Interrupt (STALL) In Scatter/Gather DMA mode, the interrupt due to this bit is  masked in the core.This bit can be set only by the core and  the application should write 1 to clear it. Values:  <br><li> 0x0 (INACTIVE): No Stall Response Received Interrupt <br><li> 0x1 (ACTIVE): Stall Response Received Interrupt */
                  __IOM uint32_t NAK                       : 1 ;     /*!< [4:4] : NAK Response Received Interrupt (NAK) In Scatter/Gather DMA mode, the interrupt due to this bit is  masked in the core.This bit can be set only by the core and  the application should write 1 to clear it. Values:  <br><li> 0x0 (INACTIVE): No NAK Response Received Interrupt <br><li> 0x1 (ACTIVE): NAK Response Received Interrupt */
                  __IOM uint32_t ACK                       : 1 ;     /*!< [5:5] : ACK Response Received/Transmitted Interrupt (ACK) In Scatter/Gather DMA mode, the interrupt due to this bit is  masked in the core.This bit can be set only by the core and  the application should write 1 to clear it. Values:  <br><li> 0x0 (INACTIVE): No ACK Response Received or  Transmitted Interrupt <br><li> 0x1 (ACTIVE): ACK Response Received or Transmitted Interrup */
                  __IOM uint32_t NYET                      : 1 ;     /*!< [6:6] : NYET Response Received Interrupt (NYET) In Scatter/Gather DMA mode, the interrupt due to this bit is  masked in the core.This bit can be set only by the core and  the application should write 1 to clear it. Values:  <br><li> 0x0 (INACTIVE): No NYET Response Received Interrupt <br><li> 0x1 (ACTIVE): NYET Response Received Interrupt */
                  __IOM uint32_t XACT_ERR                  : 1 ;     /*!< [7:7] : Transaction Error (XactErr) Indicates one of the following errors occurred on the USB. <br><li> CRC check failure <br><li> Timeout <br><li> Bit stuff error <br><li> False EOP In Scatter/Gather DMA mode, the interrupt due to this bit is  masked in the core.This bit can be set only by the core and  the application should write 1 to clear it. Values:  <br><li> 0x0 (INACTIVE): No Transaction Error <br><li> 0x1 (ACTIVE): Transaction Error */
                  __IOM uint32_t BBL_ERR                   : 1 ;     /*!< [8:8] : Babble Error (BblErr) In Scatter/Gather DMA mode, the interrupt due to this bit is  masked in the core. This bit can be set only by the core and  the application should write 1 to clear it. Values:  <br><li> 0x0 (INACTIVE): No Babble Error <br><li> 0x1 (ACTIVE): Babble Error */
                  __IOM uint32_t FRM_OVRUN                 : 1 ;     /*!< [9:9] : Frame Overrun (FrmOvrun). In Scatter/Gather DMA mode, the interrupt due to this bit is  masked  in the core. This bit can be set only by the core and  the application should write 1 to clear it. Values:  <br><li> 0x0 (INACTIVE): No Frame Overrun <br><li> 0x1 (ACTIVE): Frame Overrun */
                  __IOM uint32_t DATA_TGL_ERR              : 1 ;     /*!< [10:10] : Data Toggle Error (DataTglErr).This bit can be set only by  the core and the application should write 1 to clear it.In  Scatter/Gather DMA mode, the interrupt due to this bit is  masked  in the core. Values:  <br><li> 0x0 (INACTIVE): No Data Toggle Error <br><li> 0x1 (ACTIVE): Data Toggle Error */
                  __IOM uint32_t HCIN_T_N_BNAINTR          : 1 ;     /*!< [11:11] : BNA (Buffer Not Available) Interrupt (BNAIntr) This bit is valid only when Scatter/Gather DMA mode is  enabled.  The core generates this interrupt when the  descriptor accessed  is not ready for the Core to process.  BNA will not be generated  for Isochronous channels. For  non Scatter/Gather DMA mode, this bit is reserved. Values:  <br><li> 0x0 (INACTIVE): No BNA Interrupt <br><li> 0x1 (ACTIVE): BNA Interrupt */
                  __IOM uint32_t XCS_XACT_ERR              : 1 ;     /*!< [12:12] : Excessive Transaction Error (XCS_XACT_ERR) This bit is valid only when Scatter/Gather DMA mode is  enabled. The core sets this bit  when 3 consecutive  transaction errors occurred on the USB bus.  XCS_XACT_ERR will  not be generated for Isochronous  channels. For non Scatter/Gather DMA mode, this bit is reserved. Values:  <br><li> 0x0 (INACTIVE): No Excessive Transaction Error <br><li> 0x1 (ACTIVE): Excessive Transaction Error */
                  __IOM uint32_t DESC_LST_ROLLINTR         : 1 ;     /*!< [13:13] : Descriptor rollover interrupt (DESC_LST_ROLLIntr) This bit is valid only when Scatter/Gather DMA mode is  enabled. The core sets this bit  when the corresponding  channel's descriptor list rolls over. For non Scatter/Gather  DMA mode, this bit is reserved. Values:  <br><li> 0x0 (INACTIVE): No Descriptor rollover interrupt <br><li> 0x1 (ACTIVE): Descriptor rollover interrupt */
                        uint32_t RSV_92                    : 18;     /*!< [31:14] : reserved */
               } HCINT_Nb;
            };
    
            union
            {
               __IOM uint32_t HCINTMSK_N;  /*!< 0x0000050c */ 
               
               struct
               {
                  __IOM uint32_t HCIN_TMSK_N_XFER_COMPL_MSK : 1 ;     /*!< [0:0] : Transfer Completed Mask (XferComplMsk) Values:  <br><li> 0x0 (MASK): Transfer Completed Mask <br><li> 0x1 (NOMASK): No Transfer Completed Mask */
                  __IOM uint32_t CH_HLTD_MSK               : 1 ;     /*!< [1:1] : Channel Halted Mask (ChHltdMsk) Values:  <br><li> 0x0 (MASK): Channel Halted Mask <br><li> 0x1 (NOMASK): No Channel Halted Mask */
                  __IOM uint32_t HCIN_TMSK_N_AHB_ERR_MSK   : 1 ;     /*!< [2:2] : AHB Error Mask (AHBErrMsk) In  scatter/gather  DMA  mode   for  host,  interrupts will not be generated due to the  corresponding bits set in  HCINTn. Values:  <br><li> 0x0 (MASK): AHB Error Mask <br><li> 0x1 (NOMASK): No AHB Error Mask */
                  __IOM uint32_t STALLM                    : 1 ;     /*!< [3] : */
                  __IOM uint32_t NAKM                      : 1 ;     /*!< [4] : */
                  __IOM uint32_t ACKM                      : 1 ;     /*!< [5] : */
                  __IOM uint32_t NYET                      : 1 ;     /*!< [6] : */
                  __IOM uint32_t TXERRM                    : 1 ;     /*!< [7] : */
                  __IOM uint32_t BBERRM                    : 1 ;     /*!< [8] : */
                  __IOM uint32_t FRMORM                    : 1 ;     /*!< [9] : */
                  __IOM uint32_t DTERRM                    : 1 ;     /*!< [10] : */
                  __IOM uint32_t BNAINTR_MSK               : 1 ;     /*!< [11:11] : BNA  (Buffer  Not  Available)  Interrupt  mask  register   (BNAIntrMsk)  This bit is valid only when Scatter/Gather  DMA mode is enabled. Values:  <br><li> 0x0 (MASK): BNA Interrupt Masked <br><li> 0x1 (NOMASK): BNA Interrupt not masked */
                        uint32_t RSV_94                    : 1 ;     /*!< [12:12] : reserved */
                  __IOM uint32_t DESC_LST_ROLLINTR_MSK     : 1 ;     /*!< [13:13] : Descriptor List rollover interrupt Mask  register(DESC_LST_ROLLIntrMsk) This bit is valid only  when Scatter/Gather DMA mode is enabled. Values:  <br><li> 0x0 (MASK): Descriptor Rollover Interrupt Mask <br><li> 0x1 (NOMASK): Descriptor Rollover Interrupt not masked */
                        uint32_t RSV_95                    : 18;     /*!< [31:14] : reserved */
               } HCINTMSK_Nb;
            };
    
            union
            {
               __IOM uint32_t HCTSIZ_N;  /*!< 0x00000510 */ 
               
               struct
               {
                  __IOM uint32_t HCTSIZ_N_XFER_SIZE        : 19;     /*!< [18:0] : Transfer Size (XferSize) For an OUT, this field is the number of data bytes the host  sends during the transfer. For an IN, this field is the buffer size that the application has  Reserved for the transfer. The application is expected to  program this field as an integer multiple of the maximum  packet size for IN transactions (periodic and non-periodic). The width of this counter is specified as Width of Transfer  Size Counters during coreConsultant configuration  (parameter OTG_TRANS_COUNT_WIDTH). */
                  __IOM uint32_t HCTSIZ_N_PKT_CNT          : 10;     /*!< [28:19] : Packet Count (PktCnt) This field is programmed by the application with the expected  number of packets to be transmitted (OUT) or received (IN). The host decrements this count on every successful  transmission or reception of an OUT/IN packet. Once this  count reaches zero, the application is interrupted to indicate  normal completion. The width of this counter is specified as Width of Packet  Counters during coreConsultant configuration (parameter  OTG_PACKET_COUNT_WIDTH). */
                  __IOM uint32_t PID                       : 2 ;     /*!< [30:29] : PID (Pid) The application programs this field with the type of PID to  use for the initial transaction. The host maintains this field for  the rest of the transfer. <br><li> 2'b00: DATA0 <br><li> 2'b01: DATA2 <br><li> 2'b10: DATA1 <br><li> 2'b11: MDATA (non-control)/SETUP (control) Values:  <br><li> 0x0 (DATA0): DATA0 <br><li> 0x1 (DATA2): DATA2 <br><li> 0x2 (DATA1): DATA1 <br><li> 0x3 (MDATA): MDATA (non-control)/SETUP (control) */
                  __IOM uint32_t DO_PNG                    : 1 ;     /*!< [31:31] : Do Ping (DoPng) This bit is used only for OUT transfers. Setting this field to 1  directs the host to do PING protocol. Note: Do not set this bit for IN transfers. If this bit is set for for  IN transfers it disables the channel. Values:  <br><li> 0x0 (NOPING): No ping protocol <br><li> 0x1 (PING): Ping protocol */
               } HCTSIZ_Nb;
            };
    
            union
            {
               __IOM uint32_t HCDMA_N;  /*!< 0x00000514 */ 
               
               struct
               {
                  __IOM uint32_t HCDMA_N_DMA_ADDR          : 32;     /*!< [31:0] : In Buffer DMA Mode: [31:0]: DMA Address (DMAAddr) This field holds the start address in the external memory  from which the data for the endpoint must be fetched or to  which it must be stored. This register is incremented on  every AHB transaction. Reset: X if not programmed as the register is in SPRAM. In Scatter-Gather DMA (DescDMA) Mode for Non- Isochronous: [31:9]: DMA Address (DMAAddr) The start address must be 512-bytes aligned. This field holds the start address of the 512 bytes page. The  first descriptor in the list should be located in this address.  The first descriptor may be or may not be ready. The core  starts processing the list from the CTD value.  [8:3]: Current Transfer Desc(CTD) This value is in terms of number of descriptors. The values  can be from 0 to 63.  <br><li> 0 -  1 descriptor.  <br><li> 63 - 64 descriptors.  This field indicates the current descriptor processed in the  list. This field is updated both by application and the core.  For example, if the application enables the channel after  programming CTD=5, then the core will start processing the  sixth descriptor. The address is obtained by adding a value  of (8bytes*5=) 40(decimal) to DMAAddr. Reset: 6'h0 [2:0]: Reserved In Scatter-Gather DMA (DescDMA) Mode for  Isochronous: [31:N]: DMA Address (DMAAddr) The start address must be 512-bytes aligned. This field holds the address of the 2*(nTD+1) bytes of  locations in which the isochronous descriptors are present  where N is based on nTD as follows: <br><li> [31:N]: Base Address <br><li> [N-1:3]: Offset <br><li> [2:0]: 000 For HS ISOC, if nTD is, <br><li> 7, N=6 <br><li> 15, N=7 <br><li> 31, N=8 <br><li> 63, N=9 <br><li> 127, N=10 <br><li> 255, N=11 For FS ISOC, if nTD is,  <br><li> 1, N=4 <br><li> 3, N=5 <br><li> 7, N=6 <br><li> 15, N=7 <br><li> 31, N=8 <br><li> 63, N=9 [N-1:3]: Current Transfer Desc(CTD) CTD for isochronous is based on the current  frame/(micro)frame value. Need to be set to zero by  application. Reset: (N+1:3)'h0 [2:0]: Reserved */
               } HCDMA_Nb;
            };
    
            uint8_t                        RSV_0X518[4]                  ;   /*!< 0x00000518~0x0000051b : reserved */
    
            union
            {
               __IM uint32_t HCDMAB_N;  /*!< 0x0000051c */ 
               
               struct
               {
                  __IM  uint32_t HCDMA_B                   : 32;     /*!< [31:0] : Holds the current buffer address. This register is updated as  and when the data transfer for the corresponding end point   is in progress. This register is present only in Scatter/Gather  DMA mode. Otherwise this  field is reserved. */
               } HCDMAB_Nb;
            };
    } HC_GRPb[16];

    uint8_t              RSV_0X700[256]                ;   /*!< 0x00000700~0x000007ff : reserved */

    union
    {
       __IOM uint32_t DCFG;  /*!< 0x00000800 */ 
       
       struct
       {
          __IOM uint32_t DEV_SPD                   : 2 ;     /*!< [1:0] : Device Speed (DevSpd) Indicates the speed at which the application requires the  core to enumerate, or the maximum speed the application  can support. However, the actual bus speed is determined  only after the connect sequence is completed, and is based  on the speed of the USB host to which the core is connected. Values:  <br><li> 0x0 (USBHS20): High speed USB 2.0 PHY clock is 30 MHz or 60 MHz <br><li> 0x1 (USBFS20): Full speed USB 2.0 PHY clock is 30 MHz or 60 MHz <br><li> 0x2 (USBLS116): Low speed USB 1.1 transceiver clock is 6 MHz <br><li> 0x3 (USBFS1148): Full speed USB 1.1 transceiver clock is 48 MHz */
          __IOM uint32_t NZSTS_OUT_HSHK            : 1 ;     /*!< [2:2] : Non-Zero-Length Status OUT Handshake (NZStsOUTHShk) The application can use this field to select the handshake the  core sends on receiving a nonzero-length data packet during  the OUT transaction of a control transfer's Status stage. <br><li> 1'b1: Send a STALL handshake on a nonzero-length  status OUT transaction and do not send the received  OUT packet to the application. <br><li> 1'b0: Send the received OUT packet to the application  (zerolength or nonzero-length) and send a handshake  based on the NAK and STALL bits for the endpoint in the  Device Endpoint Control register. Values:  <br><li> 0x0 (SENDOUT):  Send the received OUT packet to the application (zero- length or non-zero length) and send a handshake based on  NAK and STALL bits for the endpoint in the Devce Endpoint  Control Register <br><li> 0x1 (SENDSTALL):  Send a STALL handshake on a nonzero-length status OUT  transaction and do not send the received OUT packet to the  application */
          __IOM uint32_t ENA32KHZ_SUSP             : 1 ;     /*!< [3:3] : Enable 32 KHz Suspend mode (Ena32KHzSusp)  This bit can be set only if FS PHY interface is selected.  Otherwise, this bit needs to be set to zero. If FS PHY  interface is chosen and this bit is set, the PHY clock during  Suspend must be switched from 48 MHz to 32 KHz.  Values:  <br><li> 0x0 (DISABLED): USB 1.1 Full-Speed Serial Transceiver  not selected <br><li> 0x1 (ENABLED):  USB 1.1 Full-Speed Serial Transceiver Interface selected */
          __IOM uint32_t DCFG_DEV_ADDR             : 7 ;     /*!< [10:4] : Device Address (DevAddr) The application must program this field after every  SetAddress control command. */
          __IOM uint32_t PER_FR_INT                : 2 ;     /*!< [12:11] : Periodic Frame Interval (PerFrInt) Indicates the time within a (micro)Frame at which the  application must be notified using the End Of Periodic Frame  Interrupt. This can be used to determine If all the  isochronous traffic for that (micro)Frame is complete. <br><li> 2'b00: 80% of the (micro)Frame interval <br><li> 2'b01: 85% of the (micro)Frame interval <br><li> 2'b10: 90% of the (micro)Frame interval <br><li> 2'b11: 95% of the (micro)Frame interval Values:  <br><li> 0x0 (EOPF80): 80% of the (micro)Frame interval <br><li> 0x1 (EOPF85): 85% of the (micro)Frame interval <br><li> 0x2 (EOPF90): 90% of the (micro)Frame interval <br><li> 0x3 (EOPF95): 95% of the (micro)Frame interval */
          __IOM uint32_t EN_DEV_OUT_NAK            : 1 ;     /*!< [13:13] : Enable Device OUT NAK (EnDevOutNak) This bit enables setting NAK for Bulk OUT endpoints after  the transfer is completed for Device mode Descriptor DMA  <br><li> 1'b0 : The core does not set NAK after Bulk OUT transfer  complete <br><li> 1'b1  :  The core sets NAK after Bulk OUT transfer  complete This bit is one time programmable after reset like any other  DCFG register bits. Values:  <br><li> 0x0 (DISABLED):  The core does not set NAK after Bulk OUT transfer complete <br><li> 0x1 (ENABLED): The core sets NAK after Bulk OUT  transfer complete */
          __IOM uint32_t XCVRDLY                   : 1 ;     /*!< [14:14] : XCVRDLY. Enables or disables delay between xcvr_sel and txvalid  during device chirp  Values:  <br><li> 0x0 (DISABLE): No delay between xcvr_sel and txvalid  during Device chirp <br><li> 0x1 (ENABLE): Enable delay between xcvr_sel and  txvalid during Device chirp */
          __IOM uint32_t ERRATIC_INT_MSK           : 1 ;     /*!< [15:15] : Erratic Error Interrupt Mask Values:  <br><li> 0x0 (NOMASK): Early suspend interrupt is generated on  erratic error <br><li> 0x1 (MASK): Mask early suspend interrupt on erratic */
                uint32_t RSV_44                    : 7 ;     /*!< [22:16] : reserved */
          __IOM uint32_t DCFG_DESC_DMA             : 1 ;     /*!< [23:23] : Enable Scatter/gather DMA in device mode (DescDMA). When the Scatter/Gather DMA option selected during  configuration of the RTL, the application can Set this bit  during initialization to enable the Scatter/Gather DMA  operation. Note: This bit must be modified only once after a reset. The  following combinations are available for programming: <br><li> GAHBCFG.DMAEn=0,DCFG.DescDMA=0 => Slave  mode <br><li> GAHBCFG.DMAEn=0,DCFG.DescDMA=1 => Invalid <br><li> GAHBCFG.DMAEn=1,DCFG.DescDMA=0 => Buffered  DMA mode <br><li> GAHBCFG.DMAEn=1,DCFG.DescDMA=1 =>  Scatter/Gather DMA mode Values:  <br><li> 0x0 (DISABLED): Disable Scatter/Gather DMA <br><li> 0x1 (ENABLED): Enable Scatter/Gather DMA */
          __IOM uint32_t PER_SCH_INTVL             : 2 ;     /*!< [25:24] : Periodic Scheduling Interval (PerSchIntvl) PerSchIntvl must be programmed for Scatter/Gather DMA  mode. This field specifies the amount of time the Internal DMA  engine must allocate for fetching periodic IN endpoint data.  Based on the number of periodic endpoints, this value must  be specified as 25,50 or 75% of (micro)Frame. <br><li> When any periodic endpoints are active, the internal DMA  engine allocates the specified amount of time in fetching  periodic IN endpoint data . <br><li> When no periodic endpoints are active, Then the internal  DMA engine services non-periodic endpoints, ignoring  this field. <br><li> After the specified time within a (micro)Frame, the DMA  switches to fetching for non-periodic endpoints. - 2'b00: 25% of (micro)Frame. - 2'b01: 50% of (micro)Frame. - 2'b10: 75% of (micro)Frame. - 2 ' b 1 1 : roe s erov e d . Reset: 2'b00 Values:  <br><li> 0x0 (MF25): 25% of (micro)Frame <br><li> 0x1 (MF50): 50% of (micro)Frame <br><li> 0x2 (MF75): 75% of (micro)Frame <br><li> 0x3 (RESERVED): Reserved */
          __IOM uint32_t DCFG_RES_VALID            : 6 ;     /*!< [31:26] : Resume Validation Period (ResValid) This field is effective only when DCFG.Ena32KHzSusp is  set. It controls the resume period when the core resumes  from suspend. The core counts for ResValid number of clock  cycles  to detect a valid resume when this bit is set */
       } DCFGb;
    };

    union
    {
       __IOM uint32_t DCTL;  /*!< 0x00000804 */ 
       
       struct
       {
          __IOM uint32_t RMT_WK_UP_SIG             : 1 ;     /*!< [0:0] : Remote Wakeup Signaling (RmtWkUpSig) When the application sets this bit, the core initiates remote  signaling to wake up the USB host. The application must Set  this bit to instruct the core to exit the Suspend state. As  specified in the USB 2.0 specification, the application must  clear this bit  1-15 ms after setting it. If LPM is enabled and the core is in the L1 (Sleep) state,  when the application sets this bit, the core initiates L1 remote  signaling to wake up the USB host. The application must set  this bit to instruct the core to exit the Sleep state. As  specified in the LPM specification, the hardware  automatically clears this bit 50 microseconds  (TL1DevDrvResume) after being set by the application. The  application must not set this bit when GLPMCFG  bRemoteWake from the previous LPM transaction is zero. Values:  <br><li> 0x0 (DISABLEDRMWKUP): Core does not send Remote Wakeup Signaling <br><li> 0x1 (ENABLERMWKUP): Core sends Remote Wakeup Signaling */
          __IOM uint32_t SFT_DISCON                : 1 ;     /*!< [1:1] : Soft Disconnect (SftDiscon) The application uses this bit to signal the controller to do a  soft disconnect. As long as this bit is set, the host does not  see that the device is connected, and the device does not  receive signals on the USB. The core stays in the  disconnected state until the application clears this bit. <br><li> 1'b0: Normal operation. When this bit is cleared after a  soft disconnect, the core drives the phy_opmode_o signal  on the    UTMI+ to 2'b00, which generates a device  connect event to the USB host. When the device is  reconnected, the USB host restarts device enumeration. <br><li> 1'b1: The core drives the phy_opmode_o signal on the  UTMI+ to 2'b01, which generates a device disconnect  event to the USB host. The following is the minimum duration under various  conditions for which this bit must be set for the USB host to  detect a device disconnect. To accommodate clock jitter, it is  recommended that the application adds some extra delay to  the specified minimum duration. For high speed, if the device state is,  <br><li> Suspended, the minimum duration is 1ms + 2.5us <br><li> Idle, the minimum duration is 3ms + 2.5us <br><li> Not Idle or Suspended (performing transactions), the  minimum duration 125 us For full speed/low speed, if the device state is,  <br><li> Suspended, the minimum duration is 1ms + 2.5us <br><li> Idle, the minimum duration is 2.5us <br><li> Not Idle or Suspended (performing transactions), the  minimum duration 125 us Note: <br><li> This bit can be also used for ULPI/FS Serial interfaces. <br><li> This bit is not impacted by a soft reset. Values:  <br><li> 0x0 (NODISCONNECT): The core drives the  phy_opmode_o signal on the UTMI+ to 2'b00, which  generates a device connect event to the USB host <br><li> 0x1 (DISCONNECT): The core drives the phy_opmode_o  signal on the UTMI+ to 2'b01, which generates a device  disconnect event to the USB host */
          __IM  uint32_t GNP_IN_NAK_STS            : 1 ;     /*!< [2:2] : Global Non-periodic IN NAK Status (GNPINNakSts) <br><li> 1'b0: A handshake is sent out based on the data  availability in the transmit FIFO. <br><li> 1'b1: A NAK handshake is sent out on all non-periodic IN  endpoints, irrespective of the data availability in the  transmit FIFO. Values:  <br><li> 0x0 (INACTIVE): A handshake is sent out based on the  data availability in the transmit FIFO <br><li> 0x1 (ACTIVE): A NAK handshake is sent out on all non- periodic IN endpoints, irrespective of the data availability  in the transmit FIFO. */
          __IM  uint32_t GOUT_NAK_STS              : 1 ;     /*!< [3:3] : Global OUT NAK Status (GOUTNakSts) <br><li> 1'b0: A handshake is sent based on the FIFO Status and  the NAK and STALL bit settings. <br><li> 1'b1: No data is written to the RxFIFO, irrespective of  space availability. Sends a NAK handshake on all  packets, except on SETUP transactions. All isochronous  OUT packets are dropped. Values:  <br><li> 0x0 (INACTIVE): A handshake is sent based on the FIFO  Status and the NAK and STALL bit settings. <br><li> 0x1 (ACTIVE): No data is written to the RxFIFO,  irrespective of space availability. Sends a NAK  handshake on all packets, except on SETUP  transactions. All isochronous OUT packets are dropped. */
          __IOM uint32_t TST_CTL                   : 3 ;     /*!< [6:4] : Test Control (TstCtl) <br><li> 3'b000: Test mode disabled <br><li> 3'b001: Test_J mode <br><li> 3'b010: Test_K mode <br><li> 3'b011: Test_SE0_NAK mode <br><li> 3'b100: Test_Packet mode <br><li> 3'b101: Test_Force_Enable <br><li> Others: Reserved Values:  <br><li> 0x0 (DISABLED): Test mode disabled <br><li> 0x1 (TESTJ): Test_J mode <br><li> 0x2 (TESTK): Test_K mode <br><li> 0x3 (TESTSN): Test_SE0_NAK mode <br><li> 0x4 (TESTPM): Test_Packet mode <br><li> 0x5 (TESTFE): Test_force_Enable */
          __OM  uint32_t SGNP_IN_NAK               : 1 ;     /*!< [7:7] : Set Global Non-periodic IN NAK (SGNPInNak) A write to this field sets the Global Non-periodic IN NAK.The  application uses this bit to send a NAK handshake on all  non-periodic IN endpoints. The core can also Set this bit  when a timeout condition is detected on a non-periodic  endpoint in shared FIFO operation. The application must Set  this bit only after making sure that the Global IN NAK  Effective bit in the Core Interrupt Register  (GINTSTS.GINNakEff) is cleared Values:  <br><li> 0x0 (DISABLE): Disable Global Non-periodic IN NAK <br><li> 0x1 (ENABLE): Set Global Non-periodic IN NAK */
          __OM  uint32_t CGNP_IN_NAK               : 1 ;     /*!< [8:8] : Clear Global Non-periodic IN NAK (CGNPInNak) A write to this field clears the Global Non-periodic IN NAK. Values:  <br><li> 0x0 (DISABLE): Disable Global Non-periodic IN NAK <br><li> 0x1 (ENABLE): Clear Global Non-periodic IN NAK */
          __OM  uint32_t SGOUT_NAK                 : 1 ;     /*!< [9:9] : Set Global OUT NAK (SGOUTNak) A write to this field sets the Global OUT NAK. The  application uses this bit to send a NAK handshake on all  OUT endpoints. The application must set the this bit only  after making sure that the Global OUT NAK Effective bit in  the Core Interrupt Register (GINTSTS.GOUTNakEff) is cleared. Values:  <br><li> 0x0 (DISABLED): Disable Global OUT NAK <br><li> 0x1 (ENABLED): Set Global OUT NAK */
          __OM  uint32_t CGOUT_NAK                 : 1 ;     /*!< [10:10] : Clear Global OUT NAK (CGOUTNak) A write to this field clears the Global OUT NAK. Values:  <br><li> 0x0 (DISABLED): Disable Clear Global OUT NAK <br><li> 0x1 (ENABLED): Clear Global OUT NAK */
          __IOM uint32_t PWRON_PRG_DONE            : 1 ;     /*!< [11:11] : Power-On Programming Done (PWROnPrgDone) The application uses this bit to indicate that register  programming is completed after a wake-up from Power  Down mode. Values:  <br><li> 0x0 (NOTDONE): Power-On Programming not done <br><li> 0x1 (DONE): Power-On Programming Done */
                uint32_t RSV_45                    : 1 ;     /*!< [12:12] : reserved */
          __IOM uint32_t GMC                       : 2 ;     /*!< [14:13] : Global Multi Count (GMC) GMC must be programmed only once after initialization.  Applicable only for Scatter/Gather DMA mode. This indicates  the number of packets to be serviced for that end point  before moving to the next end point. It is only for non-periodic  endpoints.  <br><li> 2'b00: Invalid. <br><li> 2'b01: 1 packet. <br><li> 2'b10: 2 packets. <br><li> 2'b11: 3 packets. The value of this field automatically changes to 2'h1 when  DCFG.DescDMA is set to 1. When Scatter/Gather DMA  mode is disabled, this field is reserved. and reads 2'b00. Values:  <br><li> 0x0 (NOTVALID): Invalid <br><li> 0x1 (ONEPACKET): 1 packet <br><li> 0x2 (TWOPACKET): 2 packets <br><li> 0x3 (THREEPACKET): 3 packets */
          __IOM uint32_t IGNR_FRM_NUM              : 1 ;     /*!< [15:15] : Ignore Frame Number Feature for Isochronous Endpoints (IgnrFrmNum) This field is also used to control the Periodic Transfer  Interrupt (PTI) feature. Note: Do not program IgnrFrmNum bit to 1'b1 when the core  is operating in threshold mode. Slave Mode (GAHBCFG.DMAEn=0):  This bit is not valid in Slave mode and should not be  programmed to 1. Scatter/Gather DMA Mode  (GAHBCFG.DMAEn=1,DCFG.DescDMA=1):  Note: When Scatter/Gather DMA mode is enabled this  feature is not applicable to High Speed, High bandwidth  transfers. When this bit is enabled, there must be only one packet per  descriptor.  <br><li> 0: The core transmits the packets only in the frame  number in which they are intended to be transmitted.  <br><li> 1: The core ignores the frame number, sending packets  immediately as the packets are ready. In Scatter/Gather DMA mode, if this bit is enabled, the  packets are not flushed when a ISOC IN token is received for  an elapsed frame. Non-Scatter/Gather DMA Mode, that is, Buffer DMA  Mode (GAHBCFG.DMAEn=1,DCFG.DescDMA=0):  When Scatter/Gather DMA mode is disabled, this field is  used by the application to enable Periodic Transfer Interrupt  (PTI) Mode. The application can program Periodic Endpoint transfers for  multiple (micro)Frames. <br><li> 0: Periodic Transfer Interrupt feature is disabled,  application needs to program transfers for periodic  endpoints every (micro)Frame <br><li> 1: Periodic Transfer Interrupt feature is enabled,  application can program transfers for multiple  (micro)Frames for periodic endpoints. In the PTI mode, the application will receive Transfer  Complete Interrupt after transfers for multiple (micro)Frames  are completed. Values:  <br><li> 0x0 (DISABLED): Scatter/Gather DMA Mode: The core  transmits the packets only in the frame number in which  they are intended to be transmitted. Non-Scatter/Gather DMA Mode: Periodic Transfer  Interrupt feature is disabled. <br><li> 0x1 (ENABLED): Scatter/Gather DMA Mode: The core  ignores the frame number, sending packets immediately  as the packets are ready. Non-Scatter/Gather DMA Mode: Periodic Transfer  Interrupt feature is enabled. */
          __IOM uint32_t NAK_ON_BBLE               : 1 ;     /*!< [16:16] : NAK on Babble Error (NakOnBble) Set NAK automatically on babble (NakOnBble). The core  sets NAK automatically for the endpoint on which babble is  received. Values:  <br><li> 0x0 (DISABLED): Disable NAK on Babble Error <br><li> 0x1 (ENABLED): NAK on Babble Error */
          __IOM uint32_t EN_CONT_ON_BNA            : 1 ;     /*!< [17:17] : Enable Continue on BNA (EnContOnBNA) This bit enables the core to continue on BNA for Bulk OUT  endpoints.  With this feature enabled, when a Bulk OUT or  INTR OUT endpoint receives a BNA interrupt the core starts  processing the descriptor that caused the BNA interrupt after   the endpoint re-enables the endpoint.  <br><li> 1'b0: After receiving BNA interrupt,the core disables the  endpoint. When the endpoint is re-enabled by the  application, the core starts processing from the  DOEPDMA descriptor. <br><li> 1'b1: After receiving BNA interrupt, the core disables the  endpoint. When the endpoint is re-enabled by the  application, the core starts processing from the descriptor  that received the BNA interrupt. This bit is valid only when OTG_EN_DESC_DMA == 1'b1. It  is a one-time programmable after reset bit like any other  DCTL register bits. Values:  <br><li> 0x0 (DISABLED): Core disables the endpoint after  receiving BNA interrupt. When application re-enables the  endpoint, core starts processing from the DOEPDMA  descriptor <br><li> 0x1 (ENABLED): Core disables the endpoint after  receiving BNA interrupt. When application re-enables the  endpoint, core starts processing from the descriptor that  received the BNA interrupt. */
                uint32_t RSV_46                    : 1 ;     /*!< [18:18] : reserved */
          __IOM uint32_t SERV_INT                  : 1 ;     /*!< [19:19] : Service Interval based scheduling for Isochronous IN Endpoints This field is used to enable service interval based scheduling  feature for ISOC IN EPs. Note: This bit is applicable only in device mode and when  Scatter/Gather DMA mode is used. This feature should not  be enabled along with DCTL.IgnrFrmNum. Scatter/Gather DMA Mode  (GAHBCFG.DMAEn=1,DCFG.DescDMA=1):  When this bit is enabled, the frame number field in the ISOC  IN descriptor structure is interpreted as the last frame of the  service interval.   In Scatter/Gather DMA mode, if this bit is  enabled, the pending packets are flushed by the controller at  the last frame of the service interval. Values:  <br><li> 0x0 (DISABLED): The controller behavior depends on  DCTL.IgnrFrmNum field. <br><li> 0x1 (ENABLED): Scatter/Gather DMA Mode: The  controller can transmit the packets in any frame of the  service interval. */
                uint32_t RSV_47                    : 12;     /*!< [31:20] : reserved */
       } DCTLb;
    };

    union
    {
       __IM uint32_t DSTS;  /*!< 0x00000808 */ 
       
       struct
       {
          __IM  uint32_t SUSP_STS                  : 1 ;     /*!< [0:0] : Suspend Status (SuspSts) In Device mode, this bit is set as long as a Suspend  condition is detected on the USB. The core enters the  Suspend state when there is no activity on the  phy_line_state_i signal for an extended period of time. The  core comes out of the suspend under the following conditions : <br><li> If there is any activity on the phy_line_state_i signal, or <br><li> If the application writes to the Remote Wakeup Signaling  bit in the Device Control register (DCTL.RmtWkUpSig). When the core comes out of the suspend, this bit is set to 1'b0. Values:  <br><li> 0x0 (INACTIVE): No suspend state <br><li> 0x1 (ACTIVE): Suspend state */
          __IM  uint32_t ENUM_SPD                  : 2 ;     /*!< [2:1] : Enumerated Speed (EnumSpd) Indicates the speed at which the controller has come up after  speed detection through a connect or reset sequence. <br><li> 2'b00: High speed (PHY clock is running at 30 or 60 MHz) <br><li> 2'b01: Full speed (PHY clock is running at 30 or 60 MHz) <br><li> 2'b10: Low speed (PHY clock is running at 6 MHz) <br><li> 2'b11: Full speed (PHY clock is running at 48 MHz) Low speed is not supported for devices using a UTMI+ PHY. Values:  <br><li> 0x0 (HS3060): High speed (PHY clock is running at 30 or 60 MHz) <br><li> 0x1 (FS3060): Full speed (PHY clock is running at 30 or 60 MHz) <br><li> 0x2 (LS6): Low speed (PHY clock is running at 6 MHz) <br><li> 0x3 (FS48): Full speed (PHY clock is running at 48 MHz) */
          __IM  uint32_t ERRTIC_ERR                : 1 ;     /*!< [3:3] : Erratic Error (ErrticErr) The core sets this bit to report any erratic errors  (phy_rxvalid_i/phy_rxvldh_i or phy_rxactive_i is asserted for  at least 2 ms, due to PHY error) seen on the UTMI+. Due to  erratic errors, the core goes into Suspended state and an  interrupt is generated to the application with Early Suspend  bit of the Core Interrupt register (GINTSTS.ErlySusp). If the  early suspend is asserted due to an erratic error, the  application can only perform a soft disconnect recover. Values:  <br><li> 0x0 (INACTIVE): No Erratic Error <br><li> 0x1 (ACTIVE): Erratic Error */
                uint32_t RSV_48                    : 4 ;     /*!< [7:4] : reserved */
          __IM  uint32_t SOFFN                     : 14;     /*!< [21:8] : Frame or Microframe Number of the Received SOF (SOFFN) When the core is operating at high speed, this field contains  a microframe number. When the core is operating at full or  low speed, this field contains a Frame number. Note: This register may return a non-zero value if read  immediately after power-on reset. In case the register bit  reads non-zero immediately after power-on reset, it does not  indicate that SOF has been received from the host. The read  value of this interrupt is valid only after a valid connection  between host and device is established. */
          __IM  uint32_t DEV_LN_STS                : 2 ;     /*!< [23:22] : Device Line Status (DevLnSts)  Indicates the current logic level USB data lines  <br><li> DevLnSts[1]: Logic level of D+  <br><li> DevLnSts[0]: Logic level of D- */
                uint32_t RSV_49                    : 8 ;     /*!< [31:24] : reserved */
       } DSTSb;
    };

    uint8_t              RSV_0X80c[4]                  ;   /*!< 0x0000080c~0x0000080f : reserved */

    union
    {
       __IOM uint32_t DIEPMSK;  /*!< 0x00000810 */ 
       
       struct
       {
          __IOM uint32_t DIEP_MSK_XFER_COMPL_MSK   : 1 ;     /*!< [0:0] : Transfer Completed Interrupt Mask (XferComplMsk) Values:  <br><li> 0x0 (MASK): Mask Transfer Completed Interrupt <br><li> 0x1 (NOMASK): No Transfer Completed Interrupt Mask */
          __IOM uint32_t DIEP_MSK_EP_DISBLD_MSK    : 1 ;     /*!< [1:1] : Endpoint Disabled Interrupt Mask (EPDisbldMsk) Values:  <br><li> 0x0 (MASK): Mask Endpoint Disabled Interrupt <br><li> 0x1 (NOMASK): No Endpoint Disabled Interrupt Mask */
          __IOM uint32_t DIEP_MSK_AHB_ERR_MSK      : 1 ;     /*!< [2:2] : AHB Error Mask (AHBErrMsk) Values:  <br><li> 0x0 (MASK): Mask AHB Error Interrupt <br><li> 0x1 (NOMASK): No AHB Error Interrupt Mask */
          __IOM uint32_t DIEP_MSK_TIME_OUT_MSK     : 1 ;     /*!< [3:3] : Timeout Condition Mask (TimeOUTMsk) (Non-isochronous endpoints) Values:  <br><li> 0x0 (MASK): Mask Timeout Condition Interrupt <br><li> 0x1 (NOMASK): No Timeout Condition Interrupt Mask */
          __IOM uint32_t DIEP_MSK_IN_TKN_TXFEMP_MSK : 1 ;     /*!< [4:4] : IN Token Received When TxFIFO Empty Mask (INTknTXFEmpMsk) Values:  <br><li> 0x0 (MASK): Mask IN Token Received When TxFIFO Empty Interrupt <br><li> 0x1 (NOMASK):  No IN Token Received When TxFIFO Empty Interrupt */
          __IOM uint32_t DIEP_MSK_IN_TKN_EP_MIS_MSK : 1 ;     /*!< [5:5] : IN Token received with EP Mismatch Mask (INTknEPMisMsk) Values:  <br><li> 0x0 (MASK): Mask IN Token received with EP Mismatch Interrupt <br><li> 0x1 (NOMASK):  No Mask IN Token received with EP Mismatch Interrupt */
          __IOM uint32_t DIEP_MSK_IN_EP_NAK_EFF_MSK : 1 ;     /*!< [6:6] : IN Endpoint NAK Effective Mask (INEPNakEffMsk) Values:  <br><li> 0x0 (MASK): Mask IN Endpoint NAK Effective Interrupt <br><li> 0x1 (NOMASK): No IN Endpoint NAK Effective Interrupt Mask */
                uint32_t RSV_50                    : 1 ;     /*!< [7:7] : reserved */
          __IOM uint32_t DIEP_MSK_TXFIFO_UNDRN_MSK : 1 ;     /*!< [8:8] : Fifo Underrun Mask (TxfifoUndrnMsk) Values:  <br><li> 0x0 (MASK): Mask Fifo Underrun Interrupt <br><li> 0x1 (NOMASK): No Fifo Underrun Interrupt Mask */
          __IOM uint32_t DIEP_MSK_BNAIN_INTR_MSK   : 1 ;     /*!< [9:9] : BNA interrupt Mask (BNAInIntrMsk) Values:  <br><li> 0x0 (MASK): Mask BNA Interrupt <br><li> 0x1 (NOMASK): No BNA Interrupt Mask */
                uint32_t RSV_51                    : 3 ;     /*!< [12:10] : reserved */
          __IOM uint32_t DIEP_MSK_NAKMSK           : 1 ;     /*!< [13:13] : NAK interrupt Mask (NAKMsk) Values:  <br><li> 0x0 (MASK): Mask NAK Interrupt <br><li> 0x1 (NOMASK): No Mask NAK Interrupt */
                uint32_t RSV_52                    : 18;     /*!< [31:14] : reserved */
       } DIEPMSKb;
    };

    union
    {
       __IOM uint32_t DOEPMSK;  /*!< 0x00000814 */ 
       
       struct
       {
          __IOM uint32_t DOEP_MSK_XFER_COMPL_MSK   : 1 ;     /*!< [0:0] : Transfer Completed Interrupt Mask (XferComplMsk) Values:  <br><li> 0x0 (MASK): Mask Transfer Completed Interrupt <br><li> 0x1 (NOMASK): No Transfer Completed Interrupt Mask */
          __IOM uint32_t DOEP_MSK_EP_DISBLD_MSK    : 1 ;     /*!< [1:1] : Endpoint Disabled Interrupt Mask (EPDisbldMsk) Values:  <br><li> 0x0 (MASK): Mask Endpoint Disabled Interrupt <br><li> 0x1 (NOMASK): No Endpoint Disabled Interrupt Mask */
          __IOM uint32_t DOEP_MSK_AHB_ERR_MSK      : 1 ;     /*!< [2:2] : AHB Error (AHBErrMsk) Values:  <br><li> 0x0 (MASK): Mask AHB Error Interrupt <br><li> 0x1 (NOMASK): No AHB Error Interrupt Mask */
          __IOM uint32_t DOEP_MSK_SET_UPMSK        : 1 ;     /*!< [3:3] : SETUP Phase Done Mask (SetUPMsk) Applies to control endpoints only. Values:  <br><li> 0x0 (MASK): Mask SETUP Phase Done Interrupt <br><li> 0x1 (NOMASK): No SETUP Phase Done Interrupt Mask */
          __IOM uint32_t DOEP_MSK_OUT_TKN_EP_DIS_MSK : 1 ;     /*!< [4:4] : OUT Token Received when Endpoint Disabled Mask (OUTTknEPdisMsk) Applies to control OUT endpoints only. Values:  <br><li> 0x0 (MASK):  Mask OUT Token Received when Endpoint Disabled Interrupt <br><li> 0x1 (NOMASK):  No OUT Token Received when Endpoint Disabled Interrupt Mask */
          __IOM uint32_t DOEP_MSK_STS_PHSE_RCVD_MSK : 1 ;     /*!< [5:5] : Status Phase Received Mask (StsPhseRcvdMsk) Applies to control OUT endpoints only. Values:  <br><li> 0x0 (MASK): Status Phase Received Mask <br><li> 0x1 (NOMASK): No Status Phase Received Mask */
          __IOM uint32_t DOEP_MSK_BACK2BACK_SETUP  : 1 ;     /*!< [6:6] : Back-to-Back SETUP Packets Received Mask (Back2BackSETup) Applies to control OUT endpoints only. Values:  <br><li> 0x0 (MASK): Mask Back-to-Back SETUP Packets  Received Interrupt <br><li> 0x1 (NOMASK):  No Back-to-Back SETUP Packets Received Interrupt Mask */
                uint32_t RSV_53                    : 1 ;     /*!< [7:7] : reserved */
          __IOM uint32_t DOEP_MSK_OUT_PKT_ERR_MSK  : 1 ;     /*!< [8:8] : OUT Packet Error Mask (OutPktErrMsk) Values:  <br><li> 0x0 (MASK): Mask OUT Packet Error Interrupt <br><li> 0x1 (NOMASK): No OUT Packet Error Interrupt Mask */
          __IOM uint32_t DOEP_MSK_BNA_OUT_INTR_MSK : 1 ;     /*!< [9:9] : BNA interrupt Mask (BnaOutIntrMsk) Values:  <br><li> 0x0 (MASK): Mask BNA Interrupt <br><li> 0x1 (NOMASK): No BNA Interrupt Mask */
                uint32_t RSV_54                    : 2 ;     /*!< [11:10] : reserved */
          __IOM uint32_t DOEP_MSK_BBLE_ERR_MSK     : 1 ;     /*!< [12:12] : Babble Error interrupt Mask (BbleErrMsk) Values:  <br><li> 0x0 (MASK): Mask Babble Error Interrupt <br><li> 0x1 (NOMASK): No Babble Error Interrupt Mask */
          __IOM uint32_t DOEP_MSK_NAKMSK           : 1 ;     /*!< [13:13] : NAK interrupt Mask (NAKMsk) Values:  <br><li> 0x0 (MASK): Mask NAK Interrupt <br><li> 0x1 (NOMASK): No NAK Interrupt Mask */
          __IOM uint32_t DOEP_MSK_NYETMSK          : 1 ;     /*!< [14:14] : NYET interrupt Mask (NYETMsk) Values:  <br><li> 0x0 (MASK): Mask NYET Interrupt <br><li> 0x1 (NOMASK): No NYET Interrupt Mask */
                uint32_t RSV_55                    : 17;     /*!< [31:15] : reserved */
       } DOEPMSKb;
    };

    union
    {
       __IM uint32_t DAINT;  /*!< 0x00000818 */ 
       
       struct
       {
          __IM  uint32_t IN_EP_INT0                : 1 ;     /*!< [0:0] : IN Endpoint 0 Interrupt Bit */
          __IM  uint32_t IN_EP_INT1                : 1 ;     /*!< [1:1] : IN Endpoint 1 Interrupt Bit */
          __IM  uint32_t IN_EP_INT2                : 1 ;     /*!< [2:2] : IN Endpoint 2 Interrupt Bit */
          __IM  uint32_t IN_EP_INT3                : 1 ;     /*!< [3:3] : IN Endpoint 3 Interrupt Bit */
          __IM  uint32_t IN_EP_INT4                : 1 ;     /*!< [4:4] : IN Endpoint 4 Interrupt Bit */
          __IM  uint32_t IN_EP_INT5                : 1 ;     /*!< [5:5] : IN Endpoint 5 Interrupt Bit */
          __IM  uint32_t IN_EP_INT6                : 1 ;     /*!< [6:6] : IN Endpoint 6 Interrupt Bit */
          __IM  uint32_t IN_EP_INT7                : 1 ;     /*!< [7:7] : IN Endpoint 7 Interrupt Bit */
          __IM  uint32_t IN_EP_INT8                : 1 ;     /*!< [8:8] : IN Endpoint 8 Interrupt Bit */
          __IM  uint32_t IN_EP_INT9                : 1 ;     /*!< [9:9] : IN Endpoint 9 Interrupt Bit */
          __IM  uint32_t IN_EP_INT10               : 1 ;     /*!< [10:10] : IN Endpoint 10 Interrupt Bit */
          __IM  uint32_t IN_EP_INT11               : 1 ;     /*!< [11:11] : IN Endpoint 11 Interrupt Bit */
          __IM  uint32_t IN_EP_INT12               : 1 ;     /*!< [12:12] : IN Endpoint 12 Interrupt Bit */
          __IM  uint32_t IN_EP_INT13               : 1 ;     /*!< [13:13] : IN Endpoint 13 Interrupt Bit */
          __IM  uint32_t IN_EP_INT14               : 1 ;     /*!< [14:14] : IN Endpoint 14 Interrupt Bit */
          __IM  uint32_t IN_EP_INT15               : 1 ;     /*!< [15:15] : IN Endpoint 15 Interrupt Bit */
          __IM  uint32_t OUT_EP_INT0               : 1 ;     /*!< [16:16] : OUT Endpoint 0 Interrupt Bit */
          __IM  uint32_t OUT_EP_INT1               : 1 ;     /*!< [17:17] : OUT Endpoint 1 Interrupt Bit */
          __IM  uint32_t OUT_EP_INT2               : 1 ;     /*!< [18:18] : OUT Endpoint 2 Interrupt Bit */
          __IM  uint32_t OUT_EP_INT3               : 1 ;     /*!< [19:19] : OUT Endpoint 3 Interrupt Bit */
          __IM  uint32_t OUT_EP_INT4               : 1 ;     /*!< [20:20] : OUT Endpoint 4 Interrupt Bit */
          __IM  uint32_t OUT_EP_INT5               : 1 ;     /*!< [21:21] : OUT Endpoint 5 Interrupt Bit */
          __IM  uint32_t OUT_EP_INT6               : 1 ;     /*!< [22:22] : OUT Endpoint 6 Interrupt Bit */
          __IM  uint32_t OUT_EP_INT7               : 1 ;     /*!< [23:23] : OUT Endpoint 7 Interrupt Bit */
          __IM  uint32_t OUT_EP_INT8               : 1 ;     /*!< [24:24] : OUT Endpoint 8 Interrupt Bit */
          __IM  uint32_t OUT_EP_INT9               : 1 ;     /*!< [25:25] : OUT Endpoint 9 Interrupt Bit */
          __IM  uint32_t OUT_EP_INT10              : 1 ;     /*!< [26:26] : OUT Endpoint 10 Interrupt Bit */
          __IM  uint32_t OUT_EP_INT11              : 1 ;     /*!< [27:27] : OUT Endpoint 11 Interrupt Bit */
          __IM  uint32_t OUT_EP_INT12              : 1 ;     /*!< [28:28] : OUT Endpoint 12 Interrupt Bit */
          __IM  uint32_t OUT_EP_INT13              : 1 ;     /*!< [29:29] : OUT Endpoint 13 Interrupt Bit */
          __IM  uint32_t OUT_EP_INT14              : 1 ;     /*!< [30:30] : OUT Endpoint 14 Interrupt Bit */
          __IM  uint32_t OUT_EP_INT15              : 1 ;     /*!< [31:31] : OUT Endpoint 15 Interrupt Bit */
       } DAINTb;
    };

    union
    {
       __IOM uint32_t DAINTMSK;  /*!< 0x0000081c */ 
       
       struct
       {
          __IOM uint32_t IEPM                : 16 ;     /*!< [15:0] : IN Endpoint 0~15 Interrupt mask Bit */
          __IOM uint32_t OEPM                : 16 ;     /*!< [31:16] : OUT Endpoint 0~15 Interrupt mask Bit */
       } DAINTMSKb;
    };

    uint8_t              RSV_0X820[8]                  ;   /*!< 0x00000820~0x00000827 : reserved */

    union
    {
       __IOM uint32_t DVBUSDIS;  /*!< 0x00000828 */ 
       
       struct
       {
          __IOM uint32_t DVBUSDIS                  : 16;     /*!< [15:0] : Device VBUS Discharge Time (DVBUSDis) Specifies the VBUS discharge time after VBUS pulsing  during SRP. This value equals (VBUS discharge time in PHY clocks) / 1, 024. The value you use depends whether the PHY is operating at  30MHz (16-bit data width) or 60 MHz (8-bit data width). Depending on your VBUS load, this value can need adjustment. Value After Reset: * Varies based on Configuration */
                uint32_t RSV_56                    : 16;     /*!< [31:16] : reserved */
       } DVBUSDISb;
    };

    union
    {
       __IOM uint32_t DVBUSPULSE;  /*!< 0x0000082c */ 
       
       struct
       {
          __IOM uint32_t DVBUSPULSE                : 12;     /*!< [11:0] : Device VBUS Pulsing Time (DVBUSPulse) Specifies the VBUS pulsing time during SRP. This value  equals (VBUS pulsing time in PHY clocks) / 1, 024 The value you use depends whether the PHY is operating at  30MHz (16-bit data width) or 60 MHz (8-bit data width). Value After Reset: * Varies based on Configuration */
                uint32_t RSV_57                    : 20;     /*!< [31:12] : reserved */
       } DVBUSPULSEb;
    };

    union
    {
       __IOM uint32_t DTHRCTL;  /*!< 0x00000830 */ 
       
       struct
       {
          __IOM uint32_t NON_ISO_THR_EN            : 1 ;     /*!< [0:0] : Non-ISO IN Endpoints Threshold Enable. (NonISOThrEn) When this bit is Set, the core enables thresholding for Non  Isochronous IN endpoints. Values:  <br><li> 0x0 (DISABLED): No thresholding <br><li> 0x1 (ENABLED): Enable thresholding for non- isochronous IN endpoints Value After Reset: * Varies based on Configuration */
          __IOM uint32_t ISO_THR_EN                : 1 ;     /*!< [1:1] : ISO IN Endpoints Threshold Enable. (ISOThrEn)  When this bit is Set, the core enables thresholding for  isochronous IN endpoints. Values:  <br><li> 0x0 (DISABLED): No thresholding <br><li> 0x1 (ENABLED): Enables thresholding for isochronous IN  endpoints Value After Reset: * Varies based on Configuration */
          __IOM uint32_t TX_THR_LEN                : 9 ;     /*!< [10:2] : Transmit Threshold Length (TxThrLen) This field specifies Transmit thresholding size in DWORDS.  This also forms  the MAC threshold and specifies the amount  of data in bytes to be in the  corresponding endpoint transmit  FIFO, before the core can start transmit  on the USB. The  threshold length has to be at least eight DWORDS when the   value of AHBThrRatio is 2'h00. In case the AHBThrRatio is  non zero the  application needs to ensure that the AHB  Threshold value does not go below  the recommended eight  DWORD.  This field controls both isochronous and  non- isochronous IN endpoint thresholds. The recommended  value for ThrLen  is to be the same as the programmed AHB  Burst Length (GAHBCFG.HBstLen). Note: <br><li> When OTG_ARCHITECTURE=0, the reset value of this  register field is 0. <br><li> When OTG_ARCHITECTURE=2, the reset value of this  register field is 8. Value After Reset: * Varies based on Configuration */
          __IOM uint32_t AHB_THR_RATIO             : 2 ;     /*!< [12:11] : AHB Threshold Ratio (AHBThrRatio) These bits define the ratio between the AHB threshold and  the MAC threshold for the transmit path only. The AHB  threshold always remains less than or equal to the USB  threshold, because this does not increase overhead. Both  the AHB and the MAC threshold must be DWORD-aligned.  The application needs to program TxThrLen and the  AHBThrRatio to make the AHB Threshold value DWORD  aligned. If the AHB threshold value is not DWORD aligned,  the core might not behave correctly. When programming the  TxThrLen and AHBThrRatio, the application must ensure  that the minimum AHB threshold value does not go below 8  DWORDS to meet the USB turnaround time requirements. <br><li> 2'b00: AHB threshold = MAC threshold <br><li> 2'b01: AHB threshold = MAC threshold / 2 <br><li> 2'b10: AHB threshold = MAC threshold / 4 <br><li> 2'b11: AHB threshold = MAC threshold / 8 Values:  <br><li> 0x0 (THRESZERO): AHB threshold = MAC threshold <br><li> 0x1 (THRESONE): AHB threshold = MAC threshold /2 <br><li> 0x2 (THRESTWO): AHB threshold = MAC threshold /4 <br><li> 0x3 (THRESTHREE): AHB threshold = MAC threshold /8 Value After Reset: * Varies based on Configuration */
                uint32_t RSV_58                    : 3 ;     /*!< [15:13] : reserved */
          __IOM uint32_t RX_THR_EN                 : 1 ;     /*!< [16:16] : Receive Threshold Enable (RxThrEn) When this bit is set, the core enables thresholding in the  receive direction. Note: We recommends that you do not enable RxThrEn,  because it may cause issues in the RxFIFO especially during  error conditions such as RxError and Babble. Values:  <br><li> 0x0 (DISABLED): Disable thresholding <br><li> 0x1 (ENABLED): Enable thresholding in the receive direction Value After Reset: * Varies based on Configuration */
          __IOM uint32_t RX_THR_LEN                : 9 ;     /*!< [25:17] : Receive Threshold Length (RxThrLen) This field specifies Receive thresholding size in DWORDS.  This field also specifies the amount of data received on the  USB before the core can start transmitting on the AHB. The  threshold length has to be at least eight DWORDS. The  recommended value for ThrLen is to be the same as the  programmed AHB Burst Length (GAHBCFG.HBstLen). Value After Reset: * Varies based on Configuration */
                uint32_t RSV_59                    : 6 ;     /*!< [31:26] : reserved */
       } DTHRCTLb;
    };

    union
    {
       __IOM uint32_t DIEPEMPMSK;  /*!< 0x00000834 */ 
       
       struct
       {
          __IOM uint32_t IN_EP_TXF_EMP_MSK         : 16;     /*!< [15:0] : IN EP Tx FIFO Empty Interrupt Mask Bits (InEpTxfEmpMsk) These bits acts as mask bits for DIEPINTn.TxFEmp  interrupt, one bit per IN Endpoint: Bit 0 for IN EP 0, bit 15 for IN EP 15 Values:  <br><li> 0x1 (EP0_MASK): Mask IN EP0 Tx FIFO Empty Interrupt <br><li> 0x2 (EP1_MASK): Mask IN EP1 Tx FIFO Empty Interrupt <br><li> 0x4 (EP2_MASK): Mask IN EP2 Tx FIFO Empty Interrupt <br><li> 0x8 (EP3_MASK): Mask IN EP3 Tx FIFO Empty Interrupt <br><li> 0x10 (EP4_MASK): Mask IN EP4 Tx FIFO Empty Interrupt <br><li> 0x20 (EP5_MASK): Mask IN EP5 Tx FIFO Empty Interrupt <br><li> 0x40 (EP6_MASK): Mask IN EP6 Tx FIFO Empty Interrupt <br><li> 0x80 (EP7_MASK): Mask IN EP7 Tx FIFO Empty Interrupt <br><li> 0x100 (EP8_MASK): Mask IN EP8 Tx FIFO Empty Interrupt <br><li> 0x200 (EP9_MASK): Mask IN EP9 Tx FIFO Empty Interrupt <br><li> 0x400 (EP10_MASK): Mask IN EP10 Tx FIFO Empty Interrupt <br><li> 0x800 (EP11_MASK): Mask IN EP11 Tx FIFO Empty Interrupt <br><li> 0x1000 (EP12_MASK): Mask IN EP12 Tx FIFO Empty Interrupt <br><li> 0x2000 (EP13_MASK): Mask IN EP13 Tx FIFO Empty Interrupt <br><li> 0x4000 (EP14_MASK): Mask IN EP14 Tx FIFO Empty Interrupt <br><li> 0x8000 (EP15_MASK): Mask IN EP15 Tx FIFO Empty Interrupt */
                uint32_t RSV_60                    : 16;     /*!< [31:16] : reserved */
       } DIEPEMPMSKb;
    };

    union
    {
       __IM uint32_t DEACHINT;  /*!< 0x00000838 */ 
       
       struct
       {
          __IM  uint32_t ECH_IN_EP_INT             : 16;     /*!< [15:0] : Each IN Endpoint Interrupt Bits (EchInEpInt) One bit per IN Endpoint:  Bit 0 for IN endpoint 0, bit 15 for endpoint 15 Values:  <br><li> 0x1 (IEP0_INT): IN EP0 Interrupt <br><li> 0x2 (IEP1_INT): IN EP1 Interrupt <br><li> 0x4 (IEP2_INT): IN EP2 Interrupt <br><li> 0x8 (IEP3_INT): IN EP3 Interrupt <br><li> 0x10 (IEP4_INT): IN EP4 Interrupt <br><li> 0x20 (IEP5_INT): IN EP5 Interrupt <br><li> 0x40 (IEP6_INT): IN EP6 Interrupt <br><li> 0x80 (IEP7_INT): IN EP7 Interrupt <br><li> 0x100 (IEP8_INT): IN EP8 Interrupt <br><li> 0x200 (IEP9_INT): IN EP9 Interrupt <br><li> 0x400 (IEP10_INT): IN EP10 Interrupt <br><li> 0x800 (IEP11_INT): IN EP11 Interrupt <br><li> 0x1000 (IEP12_INT): IN EP12 Interrupt <br><li> 0x2000 (IEP13_INT): IN EP13 Interrupt <br><li> 0x4000 (IEP14_INT): IN EP14 Interrupt <br><li> 0x8000 (IEP15_INT): IN EP15 Interrupt */
          __IM  uint32_t ECH_OUT_EP_INT            : 16;     /*!< [31:16] : Each OUT Endpoint Interrupt Bits (EchOutEPInt) One bit per OUT endpoint:  Bit 16 for OUT endpoint 0, bit 31 for OUT endpoint 15 Values:  <br><li> 0x1 (OEP0_INT): OUT EP0 Interrupt <br><li> 0x2 (OEP1_INT): OUT EP1 Interrupt <br><li> 0x4 (OEP2_INT): OUT EP2 Interrupt <br><li> 0x8 (OEP3_INT): OUT EP3 Interrupt <br><li> 0x10 (OEP4_INT): OUT EP4 Interrupt <br><li> 0x20 (OEP5_INT): OUT EP5 Interrupt <br><li> 0x40 (OEP6_INT): OUT EP6 Interrupt <br><li> 0x80 (OEP7_INT): OUT EP7 Interrupt <br><li> 0x100 (OEP8_INT): OUT EP8 Interrupt <br><li> 0x200 (OEP9_INT): OUT EP9 Interrupt <br><li> 0x400 (OEP10_INT): OUT EP10 Interrupt <br><li> 0x800 (OEP11_INT): OUT EP11 Interrupt <br><li> 0x1000 (OEP12_INT): OUT EP12 Interrupt <br><li> 0x2000 (OEP13_INT): OUT EP13 Interrupt <br><li> 0x4000 (OEP14_INT): OUT EP14 Interrupt <br><li> 0x8000 (OEP15_INT): OUT EP15 Interrupt */
       } DEACHINTb;
    };

    union
    {
       __IOM uint32_t DEACHINTMSK;  /*!< 0x0000083c */ 
       
       struct
       {
          __IOM uint32_t ECH_IN_EP_MSK0            : 1 ;     /*!< [0:0] : IN EP0 Interrupt Mask Bit */
          __IOM uint32_t ECH_IN_EP_MSK1            : 1 ;     /*!< [1:1] : IN EP1 Interrupt Mask Bit */
          __IOM uint32_t ECH_IN_EP_MSK2            : 1 ;     /*!< [2:2] : IN EP2 Interrupt Mask Bit */
          __IOM uint32_t ECH_IN_EP_MSK3            : 1 ;     /*!< [3:3] : IN EP3 Interrupt Mask Bit */
          __IOM uint32_t ECH_IN_EP_MSK4            : 1 ;     /*!< [4:4] : IN EP4 Interrupt Mask Bit */
          __IOM uint32_t ECH_IN_EP_MSK5            : 1 ;     /*!< [5:5] : IN EP5 Interrupt Mask Bit */
          __IOM uint32_t ECH_IN_EP_MSK6            : 1 ;     /*!< [6:6] : IN EP6 Interrupt Mask Bit */
          __IOM uint32_t ECH_IN_EP_MSK7            : 1 ;     /*!< [7:7] : IN EP7 Interrupt Mask Bit */
          __IOM uint32_t ECH_IN_EP_MSK8            : 1 ;     /*!< [8:8] : IN EP8 Interrupt Mask Bit */
          __IOM uint32_t ECH_IN_EP_MSK9            : 1 ;     /*!< [9:9] : IN EP9 Interrupt Mask Bit */
          __IOM uint32_t ECH_IN_EP_MSK10           : 1 ;     /*!< [10:10] : IN EP10 Interrupt Mask Bit */
          __IOM uint32_t ECH_IN_EP_MSK11           : 1 ;     /*!< [11:11] : IN EP11 Interrupt Mask Bit */
          __IOM uint32_t ECH_IN_EP_MSK12           : 1 ;     /*!< [12:12] : IN EP12 Interrupt Mask Bit */
          __IOM uint32_t ECH_IN_EP_MSK13           : 1 ;     /*!< [13:13] : IN EP13 Interrupt Mask Bit */
          __IOM uint32_t ECH_IN_EP_MSK14           : 1 ;     /*!< [14:14] : IN EP14 Interrupt Mask Bit */
          __IOM uint32_t ECH_IN_EP_MSK15           : 1 ;     /*!< [15:15] : IN EP15 Interrupt Mask Bit */
          __IOM uint32_t ECH_OUT_EP_MSK0           : 1 ;     /*!< [16:16] : OUT EP0 Interrupt Mask Bit */
          __IOM uint32_t ECH_OUT_EP_MSK1           : 1 ;     /*!< [17:17] : OUT EP1 Interrupt Mask Bit */
          __IOM uint32_t ECH_OUT_EP_MSK2           : 1 ;     /*!< [18:18] : OUT EP2 Interrupt Mask Bit */
          __IOM uint32_t ECH_OUT_EP_MSK3           : 1 ;     /*!< [19:19] : OUT EP3 Interrupt Mask Bit */
          __IOM uint32_t ECH_OUT_EP_MSK4           : 1 ;     /*!< [20:20] : OUT EP4 Interrupt Mask Bit */
          __IOM uint32_t ECH_OUT_EP_MSK5           : 1 ;     /*!< [21:21] : OUT EP5 Interrupt Mask Bit */
          __IOM uint32_t ECH_OUT_EP_MSK6           : 1 ;     /*!< [22:22] : OUT EP6 Interrupt Mask Bit */
          __IOM uint32_t ECH_OUT_EP_MSK7           : 1 ;     /*!< [23:23] : OUT EP7 Interrupt Mask Bit */
          __IOM uint32_t ECH_OUT_EP_MSK8           : 1 ;     /*!< [24:24] : OUT EP8 Interrupt Mask Bit */
          __IOM uint32_t ECH_OUT_EP_MSK9           : 1 ;     /*!< [25:25] : OUT EP9 Interrupt Mask Bit */
          __IOM uint32_t ECH_OUT_EP_MSK10          : 1 ;     /*!< [26:26] : OUT EP10 Interrupt Mask Bit */
          __IOM uint32_t ECH_OUT_EP_MSK11          : 1 ;     /*!< [27:27] : OUT EP11 Interrupt Mask Bit */
          __IOM uint32_t ECH_OUT_EP_MSK12          : 1 ;     /*!< [28:28] : OUT EP12 Interrupt Mask Bit */
          __IOM uint32_t ECH_OUT_EP_MSK13          : 1 ;     /*!< [29:29] : OUT EP13 Interrupt Mask Bit */
          __IOM uint32_t ECH_OUT_EP_MSK14          : 1 ;     /*!< [30:30] : OUT EP14 Interrupt Mask Bit */
          __IOM uint32_t ECH_OUT_EP_MSK15          : 1 ;     /*!< [31:31] : OUT EP15 Interrupt Mask Bit */
       } DEACHINTMSKb;
    };

    union
    {
       __IOM uint32_t DIEPEACHMSK0;  /*!< 0x00000840 */ 
       
       struct
       {
          __IOM uint32_t DIEP_EACHMSK0_XFER_COMPL_MSK : 1 ;     /*!< [0:0] : Transfer Completed Interrupt Mask (XferComplMsk) Values:  <br><li> 0x0 (MASK): Mask Transfer Completed Interrupt <br><li> 0x1 (NOMASK): No Transfer Completed Interrupt Mask */
          __IOM uint32_t DIEP_EACHMSK0_EP_DISBLD_MSK : 1 ;     /*!< [1:1] : Endpoint Disabled Interrupt Mask (EPDisbldMsk) Values:  <br><li> 0x0 (MASK): Mask Endpoint Disabled Interrupt <br><li> 0x1 (NOMASK): No Endpoint Disabled Interrupt Mask */
          __IOM uint32_t DIEP_EACHMSK0_AHB_ERR_MSK : 1 ;     /*!< [2:2] : AHB Error Mask (AHBErrMsk) Values:  <br><li> 0x0 (MASK): Mask AHB Error <br><li> 0x1 (NOMASK): No AHB Error Mask */
          __IOM uint32_t DIEP_EACHMSK0_TIME_OUT_MSK : 1 ;     /*!< [3:3] : Timeout Condition Mask (TimeOUTMsk) (Non-isochronous endpoints) Values:  <br><li> 0x0 (MASK): Mask Timeout Condition <br><li> 0x1 (NOMASK): No Timeout Condition Mask */
          __IOM uint32_t DIEP_EACHMSK0_IN_TKN_TXFEMP_MSK : 1 ;     /*!< [4:4] : IN Token Received When TxFIFO Empty Mask (INTknTXFEmpMsk) Values:  <br><li> 0x0 (MASK): Mask IN Token received When TxFIFO Empty <br><li> 0x1 (NOMASK): No IN Token received When TxFIFO Empty Mask */
          __IOM uint32_t DIEP_EACHMSK0_IN_TKN_EP_MIS_MSK : 1 ;     /*!< [5:5] : IN Token received with EP Mismatch Mask (INTknEPMisMsk) Values:  <br><li> 0x0 (MASK): Mask IN Token received with EP Mismatch <br><li> 0x1 (NOMASK): No IN Token received with EP Mismatch */
          __IOM uint32_t DIEP_EACHMSK0_IN_EP_NAK_EFF_MSK : 1 ;     /*!< [6:6] : IN Endpoint NAK Effective Mask (INEPNakEffMsk) Values:  <br><li> 0x0 (MASK): Mask IN Endpoint NAK Effective <br><li> 0x1 (NOMASK): No IN Endpoint NAK Effective Mask */
                uint32_t RSV_61                    : 1 ;     /*!< [7:7] : reserved */
          __IOM uint32_t DIEP_EACHMSK0_TXFIFO_UNDRN_MSK : 1 ;     /*!< [8:8] : Fifo Underrun Mask (TxfifoUndrnMsk) Values:  <br><li> 0x0 (MASK): Mask Fifo Underrun <br><li> 0x1 (NOMASK): No Fifo Underrun Mask */
          __IOM uint32_t DIEP_EACHMSK0_BNAIN_INTR_MSK : 1 ;     /*!< [9:9] : BNA interrupt Mask (BNAInIntrMsk) Values:  <br><li> 0x0 (MASK): Mask BNA interrupt <br><li> 0x1 (NOMASK): No BNA interrupt Mask */
                uint32_t RSV_62                    : 3 ;     /*!< [12:10] : reserved */
          __IOM uint32_t DIEP_EACHMSK0_NAKMSK      : 1 ;     /*!< [13:13] : NAK interrupt Mask (NAKMsk) Values:  <br><li> 0x0 (MASK): Mask NAK interrupt <br><li> 0x1 (NOMASK): No NAK interrupt Mask */
                uint32_t RSV_63                    : 18;     /*!< [31:14] : reserved */
       } DIEPEACHMSK0b;
    };

    /*!< 0x00000844~0x0000087f : register for DIEPEACHMSK group */
    union
    {
           __IOM uint32_t DIEPEACHMSK_N[15];  /*!< 0x00000844 */ 
           
           struct
           {
              __IOM uint32_t DIEP_EACHMSK_N_XFER_COMPL_MSK : 1 ;     /*!< [0:0] : Transfer Completed Interrupt Mask (XferComplMsk) */
              __IOM uint32_t DIEP_EACHMSK_N_EP_DISBLD_MSK : 1 ;     /*!< [1:1] : Endpoint Disabled Interrupt Mask (EPDisbldMsk) */
              __IOM uint32_t DIEP_EACHMSK_N_AHB_ERR_MSK : 1 ;     /*!< [2:2] : AHB Error Mask (AHBErrMsk) */
              __IOM uint32_t DIEP_EACHMSK_N_TIME_OUT_MSK : 1 ;     /*!< [3:3] : Timeout Condition Mask (TimeOUTMsk)  (Non-isochronous endpoints) */
              __IOM uint32_t DIEP_EACHMSK_N_IN_TKN_TXFEMP_MSK : 1 ;     /*!< [4:4] : IN Token Received When TxFIFO Empty Mask (INTknTXFEmpMsk) */
              __IOM uint32_t DIEP_EACHMSK_N_IN_TKN_EP_MIS_MSK : 1 ;     /*!< [5:5] : IN Token received with EP Mismatch Mask (INTknEPMisMsk) */
              __IOM uint32_t DIEP_EACHMSK_N_IN_EP_NAK_EFF_MSK : 1 ;     /*!< [6:6] : IN Endpoint NAK Effective Mask (INEPNakEffMsk) */
                    uint32_t RSV_96                    : 1 ;     /*!< [7:7] : reserved */
              __IOM uint32_t DIEP_EACHMSK_N_TXFIFO_UNDRN_MSK : 1 ;     /*!< [8:8] : Fifo Underrun Mask (TxfifoUndrnMsk) */
              __IOM uint32_t DIEP_EACHMSK_N_BNAIN_INTR_MSK : 1 ;     /*!< [9:9] : BNA interrupt Mask (BNAInIntrMsk) */
                    uint32_t RSV_97                    : 3 ;     /*!< [12:10] : reserved */
              __IOM uint32_t DIEP_EACHMSK_N_NAKMSK     : 1 ;     /*!< [13:13] : NAK interrupt Mask (NAKMsk) */
                    uint32_t RSV_98                    : 18;     /*!< [31:14] : reserved */
           } DIEPEACHMSK_Nb[15];
    }; 

    union
    {
       __IOM uint32_t DOEPEACHMSK0;  /*!< 0x00000880 */ 
       
       struct
       {
          __IOM uint32_t DOEP_EACHMSK0_XFER_COMPL_MSK : 1 ;     /*!< [0:0] : Transfer Completed Interrupt Mask (XferComplMsk) */
          __IOM uint32_t DOEP_EACHMSK0_EP_DISBLD_MSK : 1 ;     /*!< [1:1] : Endpoint Disabled Interrupt Mask (EPDisbldMsk) */
          __IOM uint32_t DOEP_EACHMSK0_AHB_ERR_MSK : 1 ;     /*!< [2:2] : AHB Error (AHBErrMsk) */
          __IOM uint32_t DOEP_EACHMSK0_SET_UPMSK   : 1 ;     /*!< [3:3] : SETUP Phase Done Mask (SetUPMsk) Applies to control endpoints only. */
          __IOM uint32_t DOEP_EACHMSK0_OUT_TKN_EP_DIS_MSK : 1 ;     /*!< [4:4] : OUT Token Received when Endpoint Disabled Mask (OUTTknEPdisMsk) */
          __IOM uint32_t DOEP_EACHMSK0_STS_PHS_RCVD_MSK : 1 ;     /*!< [5:5] : Status Phase Received Received Mask (StsPhsRcvdMsk) Applies to control OUT endpoints only. */
          __IOM uint32_t DOEP_EACHMSK0_BACK2BACK_SETUP : 1 ;     /*!< [6:6] : Back-to-Back SETUP Packets Received Mask (Back2BackSETup) */
                uint32_t RSV_64                    : 1 ;     /*!< [7:7] : reserved */
          __IOM uint32_t DOEP_EACHMSK0_OUT_PKT_ERR_MSK : 1 ;     /*!< [8:8] : OUT Packet Error Mask (OutPktErrMsk) */
          __IOM uint32_t DOEP_EACHMSK0_BNA_OUT_INTR_MSK : 1 ;     /*!< [9:9] : BNA interrupt Mask (BnaOutIntrMsk) */
                uint32_t RSV_65                    : 2 ;     /*!< [11:10] : reserved */
          __IOM uint32_t DOEP_EACHMSK0_BBLE_ERR_MSK : 1 ;     /*!< [12:12] : Babble Error interrupt Mask (BbleErrMsk) */
          __IOM uint32_t DOEP_EACHMSK0_NAKMSK      : 1 ;     /*!< [13:13] : NAK interrupt Mask (NAKMsk) */
          __IOM uint32_t DOEP_EACHMSK0_NYETMSK     : 1 ;     /*!< [14:14] : NYET interrupt Mask (NYETMsk) */
                uint32_t RSV_66                    : 17;     /*!< [31:15] : reserved */
       } DOEPEACHMSK0b;
    };

    /*!< 0x00000884~0x000008bf : register for DOEPEACHMSK group */
    union
    {
           __IOM uint32_t DOEPEACHMSK_N[15];  /*!< 0x00000884 */ 
           
           struct
           {
              __IOM uint32_t DOEP_EACHMSK_N_XFER_COMPL_MSK : 1 ;     /*!< [0:0] : Transfer Completed Interrupt Mask (XferComplMsk) */
              __IOM uint32_t DOEP_EACHMSK_N_EP_DISBLD_MSK : 1 ;     /*!< [1:1] : Endpoint Disabled Interrupt Mask (EPDisbldMsk) */
              __IOM uint32_t DOEP_EACHMSK_N_AHB_ERR_MSK : 1 ;     /*!< [2:2] : AHB Error (AHBErrMsk) */
              __IOM uint32_t DOEP_EACHMSK_N_SET_UPMSK  : 1 ;     /*!< [3:3] : SETUP Phase Done Mask (SetUPMsk) Applies to control endpoints only. */
              __IOM uint32_t DOEP_EACHMSK_N_OUT_TKN_EP_DIS_MSK : 1 ;     /*!< [4:4] : OUT Token Received when Endpoint Disabled Mask (OUTTknEPdisMsk) Applies to control OUT endpoints only. */
              __IOM uint32_t DOEP_EACHMSK_N_STS_PHS_RCVD_MSK : 1 ;     /*!< [5:5] : Status Phase Received Received Mask (StsPhsRcvdMsk) Applies to control OUT endpoints only. Values:  <br><li> 0x0 (MASK): Mask Status Phase Received <br><li> 0x1 (NOMASK): No Status Phase Received Received Mask */
              __IOM uint32_t DOEP_EACHMSK_N_BACK2BACK_SETUP : 1 ;     /*!< [6:6] : Back-to-Back SETUP Packets Received Mask (Back2BackSETup) Applies to control OUT endpoints only. */
                    uint32_t RSV_99                    : 1 ;     /*!< [7:7] : reserved */
              __IOM uint32_t DOEP_EACHMSK_N_OUT_PKT_ERR_MSK : 1 ;     /*!< [8:8] : OUT Packet Error Mask (OutPktErrMsk) */
              __IOM uint32_t DOEP_EACHMSK_N_BNA_OUT_INTR_MSK : 1 ;     /*!< [9:9] : BNA interrupt Mask (BnaOutIntrMsk) */
                    uint32_t RSV_100                   : 2 ;     /*!< [11:10] : reserved */
              __IOM uint32_t DOEP_EACHMSK_N_BBLE_ERR_MSK : 1 ;     /*!< [12:12] : Babble Error interrupt Mask (BbleErrMsk) */
              __IOM uint32_t DOEP_EACHMSK_N_NAKMSK     : 1 ;     /*!< [13:13] : NAK interrupt Mask (NAKMsk) */
              __IOM uint32_t DOEP_EACHMSK_N_NYETMSK    : 1 ;     /*!< [14:14] : NYET interrupt Mask (NYETMsk) */
                    uint32_t RSV_101                   : 17;     /*!< [31:15] : reserved */
           } DOEPEACHMSK_Nb[15];
    }; 

    uint8_t              RSV_0X8c0[64]                 ;   /*!< 0x000008c0~0x000008ff : reserved */

    /*!< 0x00000900~0x00000aff : register for Device IN Endpoint group */
    struct
    {
            union
            {
               __IOM uint32_t DIEPCTL_N;  /*!< 0x00000900 */ 
               
               struct
               {
                  __IOM uint32_t DIEP_CTL_N_MPS            : 11;     /*!< [10:0] : Maximum Packet Size (MPS) The application must program this field with the maximum  packet size for the current logical endpoint. This value is in bytes. */
                        uint32_t RSV_102                   : 4 ;     /*!< [14:11] : reserved */
                  __IOM uint32_t DIEP_CTL_N_USB_ACT_EP     : 1 ;     /*!< [15:15] : USB Active Endpoint (USBActEP) Indicates whether this endpoint is active in the current  configuration and interface. The core clears this bit for all  endpoints (other than EP 0) after detecting a USB reset.  After receiving the SetConfiguration and SetInterface  commands, the application must program endpoint registers  accordingly and set this bit. Values:  <br><li> 0x0 (DISABLED): Not Active <br><li> 0x1 (ENABLED): USB Active Endpoint */
                  __IM  uint32_t DIEP_CTL_N_DPID           : 1 ;     /*!< [16:16] : Endpoint Data PID (DPID) Applies to interrupt/bulk IN and OUT endpoints only. Contains the PID of the packet to be received or transmitted  on this endpoint. The application must program the PID of  the first packet to be received or transmitted on this endpoint,  after the endpoint is activated. The applications use the  SetD1PID and SetD0PID fields of this register to program  either DATA0 or DATA1 PID. <br><li> 1'b0: DATA0 <br><li> 1'b1: DATA1 This field is applicable both for Scatter/Gather DMA mode  and non-Scatter/Gather DMA mode. Even/Odd (Micro)Frame (EO_FrNum) In non-Scatter/Gather DMA mode: Applies to isochronous IN and OUT endpoints only. Indicates the (micro)frame number in which the core  transmits/receives isochronous data for this endpoint. The  application must program the even/odd (micro)frame number  in which it intends to transmit/receive isochronous data for  this endpoint using the SetEvnFr and SetOddFr fields in this register. <br><li> 1'b0: Even (micro)frame <br><li> 1'b1: Odd (micro)frame When Scatter/Gather DMA mode is enabled, this field is  reserved. The frame number in which to send data is  provided in the transmit descriptor structure. The frame in  which data is received is updated in receive descriptor structure. Values:  <br><li> 0x0 (DATA0EVENFRM): DATA0 or Even Frame <br><li> 0x1 (DATA1ODDFRM): DATA1 or Odd Frame */
                  __IM  uint32_t DIEP_CTL_N_NAKSTS         : 1 ;     /*!< [17:17] : NAK Status (NAKSts) Indicates the following: <br><li> 1'b0: The core is transmitting non-NAK handshakes  based on the FIFO status. <br><li> 1'b1: The core is transmitting NAK handshakes on this endpoint. When either the application or the core sets this bit: <br><li> The core stops receiving any data on an OUT endpoint,  even if there is space in the RxFIFO to accommodate the  incoming packet. <br><li> For non-isochronous IN endpoints: The core stops  transmitting any data on an IN endpoint, even if there  data is available in the TxFIFO. <br><li> For isochronous IN endpoints: The core sends out a zero- length data packet, even if there data is available in the TxFIFO. Irrespective of this bit's setting, the core always responds to  SETUP data packets with an ACK handshake. Values:  <br><li> 0x0 (NONNAK):  The core is transmitting non-NAK handshakes based on the FIFO status <br><li> 0x1 (NAK):  The core is transmitting NAK handshakes on this endpoint */
                  __IOM uint32_t DIEP_CTL_N_EP_TYPE        : 2 ;     /*!< [19:18] : Endpoint Type (EPType) This is the transfer type supported  by this logical endpoint. <br><li> 2'b00: Control <br><li> 2'b01: Isochronous <br><li> 2'b10: Bulk <br><li> 2'b11: Interrupt Values:  <br><li> 0x0 (CONTROL): Control <br><li> 0x1 (ISOCHRONOUS): Isochronous <br><li> 0x2 (BULK): Bulk <br><li> 0x3 (INTERRUP): Interrupt */
                        uint32_t RSV_103                   : 1 ;     /*!< [20:20] : reserved */
                  __IOM uint32_t DIEP_CTL_N_STALL          : 1 ;     /*!< [21:21] : STALL Handshake (Stall) Applies to non-control, non-isochronous IN and OUT endpoints only. The application sets this bit to stall all tokens from the USB  host to this endpoint. If a NAK bit, Global Non-periodic IN  NAK, or Global OUT NAK is set along with this bit, the  STALL bit takes priority. Only the application can clear this  bit, never the core. Applies to control endpoints only. The application can only set this bit, and the core clears it,  when a SETUP token is received for this endpoint. If a NAK  bit, Global Non-periodic IN NAK, or Global OUT NAK is set  along with this bit, the STALL bit takes priority. Irrespective of  this bit's setting, the core always responds to SETUP data  packets with an ACK handshake. Values:  <br><li> 0x0 (INACTIVE): STALL All non-active tokens <br><li> 0x1 (ACTIVE): STALL All Active Tokens */
                  __IOM uint32_t DIEP_CTL_N_TXF_NUM        : 4 ;     /*!< [25:22] : TxFIFO Number (TxFNum) Shared FIFO Operation non-periodic endpoints must set this  bit to zero. Periodic endpoints must map this to the  corresponding Periodic TxFIFO number. <br><li> 4'h0: Non-Periodic TxFIFO <br><li> Others: Specified Periodic TxFIFO.number Note: An interrupt IN endpoint can be configured as a non- periodic endpoint for applications such as mass storage. The  core treats an IN endpoint as a non-periodic endpoint if the  TxFNum field is set to 0. Otherwise, a separate periodic  FIFO must be allocated for an interrupt IN endpoint, and the  number of this FIFO must be programmed into the TxFNum  field. Configuring an interrupt IN endpoint as a non-periodic  endpoint saves the extra periodic FIFO area. Dedicated FIFO Operation: These bits specify the FIFO  number associated with this endpoint. Each active IN  endpoint must be programmed to a separate FIFO number.  This field is valid only for IN endpoints. */
                  __OM  uint32_t DIEP_CTL_N_CNAK           : 1 ;     /*!< [26:26] : Clear NAK (CNAK) A write to this bit clears the NAK bit for the endpoint. Values:  <br><li> 0x0 (INACTIVE): No Clear NAK <br><li> 0x1 (ACTIVE): Clear NAK */
                  __OM  uint32_t DIEP_CTL_N_SNAK           : 1 ;     /*!< [27:27] : Set NAK (SNAK) A write to this bit sets the NAK bit for the endpoint. Using this bit, the application can control the transmission of  NAK handshakes on an endpoint. The core can also Set this  bit for an endpoint after a SETUP packet is received on that endpoint. Values:  <br><li> 0x0 (INACTIVE): No Set NAK <br><li> 0x1 (ACTIVE): Set NAK */
                  __OM  uint32_t DIEP_CTL_N_SET_D0PID      : 1 ;     /*!< [28:28] : SetD0PID <br><li> Set DATA0 PID (SetD0PID) - Applies to interrupt/bulk IN and OUT endpoints only. - Writing to this field sets the Endpoint Data PID (DPID)  field in this register to DATA0. - This field is applicable both for Scatter/Gather DMA  mode and non-Scatter/Gather DMA mode. In non-Scatter/Gather DMA mode: Set Even (micro)Frame  (SetEvenFr) -- Applies to isochronous IN and OUT endpoints only. -- Writing to this field sets the Even/Odd (micro)Frame  (EO_FrNum) field to even (micro)Frame. When  Scatter/Gather DMA mode is enabled, this field is reserved.  The frame number in which to send data is in the transmit  descriptor structure. The frame in which to receive data is  updated in receive descriptor structure. Values:  <br><li> 0x0 (DISABLED): Disables Set DATA0 PID <br><li> 0x1 (ENABLED): Endpoint Data PID to DATA0) */
                  __OM  uint32_t DIEP_CTL_N_SET_D1PID      : 1 ;     /*!< [29:29] : SetD1PID <br><li> Set DATA1 PID (SetD1PID) - Applies to interrupt and bulk IN and OUT endpoints  only. - Writing to this field sets the Endpoint Data PID (DPID)  field in this register to DATA1. - This field is applicable both for Scatter-Gather DMA  mode and non Scatter-Gather DMA mode. <br><li> Set odd (micro)Frame (SetOddFr) - Applies to isochronous IN and OUT endpoints only. - Writing to this field sets the even and odd  (micro)Frame (EO_FrNum) field to odd (micro)Frame. - This field is not applicable for Scatter-Gather DMA  mode. Values:  <br><li> 0x0 (DISABLED): Disables Set DATA1 PID <br><li> 0x1 (ENABLED): Enables Set DATA1 PID */
                  __IOM uint32_t DIEP_CTL_N_EP_DIS         : 1 ;     /*!< [30:30] : Endpoint Disable (EPDis) Applies to IN and OUT endpoints. The application sets this bit to stop transmitting/receiving  data on an endpoint, even before the transfer for that  endpoint is complete. The application must wait for the  Endpoint Disabled interrupt before treating the endpoint as  disabled. The core clears this bit before setting the Endpoint  Disabled interrupt. The application must set this bit only if  Endpoint Enable is already set for this endpoint. Values:  <br><li> 0x0 (INACTIVE): No Action <br><li> 0x1 (ACTIVE): Disable Endpoint */
                  __IOM uint32_t DIEP_CTL_N_EP_ENA         : 1 ;     /*!< [31:31] : Endpoint Enable (EPEna) Applies to IN and OUT endpoints. <br><li> When Scatter/Gather DMA mode is enabled, - For IN endpoints this bit indicates that the descriptor  structure and data buffer with data ready to transmit is  setup. - For OUT endpoint it indicates that the descriptor  structure and data buffer to receive data is setup. <br><li> When Scatter/Gather DMA mode is enabled such as for  buffer-pointer based DMA mode: - For IN endpoints, this bit indicates that data is ready to  be transmitted on the endpoint. - For OUT endpoints, this bit indicates that the  application has allocated the memory to start  receiving data from the USB. <br><li> The core clears this bit before setting any of the following  interrupts on this endpoint: - SETUP Phase Done - Endpoint Disabled - Transfer Completed Note: For control endpoints in DMA mode, this bit must be  set to be able to transfer SETUP data packets in memory. Values:  <br><li> 0x0 (INACTIVE): No Action <br><li> 0x1 (ACTIVE): Enable Endpoint */
               } DIEPCTL_Nb;
            };
    
            uint8_t                        RSV_0X904[4]                  ;   /*!< 0x00000904~0x00000907 : reserved */
    
            union
            {
               __IOM uint32_t DIEPINT_N;  /*!< 0x00000908 */ 
               
               struct
               {
                  __IOM uint32_t DIEP_IN_T_N_XFER_COMPL    : 1 ;     /*!< [0:0] : Transfer Completed Interrupt (XferCompl) Applies to IN and OUT endpoints. <br><li> When Scatter/Gather DMA mode is enabled - For IN endpoint this field indicates that the requested  data from the descriptor is moved from external  system memory to internal FIFO. - For OUT endpoint this field indicates that the  requested data from the internal FIFO is moved to  external system memory. This interrupt is generated  only when the corresponding endpoint descriptor is  closed, and the IOC bit for the corresponding  descriptor is set. <br><li> When Scatter/Gather DMA mode is disabled, this field  indicates that the programmed transfer is complete on the  AHB as well as on the USB, for this endpoint. Values:  <br><li> 0x0 (INACTIVE): No Transfer Complete Interrupt <br><li> 0x1 (ACTIVE): Transfer Complete Interrupt */
                  __IOM uint32_t DIEP_IN_T_N_EP_DISBLD     : 1 ;     /*!< [1:1] : Endpoint Disabled Interrupt (EPDisbld) Applies to IN and OUT endpoints. This bit indicates that the endpoint is disabled per the  application's request. Values:  <br><li> 0x0 (INACTIVE): No Endpoint Disabled Interrupt <br><li> 0x1 (ACTIVE): Endpoint Disabled Interrupt */
                  __IOM uint32_t DIEP_IN_T_N_AHB_ERR       : 1 ;     /*!< [2:2] : AHB Error (AHBErr) Applies to IN and OUT endpoints. This is generated only in Internal DMA mode when there is  an AHB error during an AHB read/write. The application can  read the corresponding endpoint DMA address register to  get the error address. For details, see "AHB Error Handling"  in the Programming Guide. Values:  <br><li> 0x0 (INACTIVE): No AHB Error Interrupt <br><li> 0x1 (ACTIVE): AHB Error interrupt */
                  __IOM uint32_t DIEP_IN_T_N_TIME_OUT      : 1 ;     /*!< [3:3] : Timeout Condition (TimeOUT) <br><li> In shared TX FIFO mode, applies to non-isochronous IN endpoints only. <br><li> In dedicated FIFO mode, applies only to Control IN endpoints. <br><li> In Scatter/Gather DMA mode, the TimeOUT interrupt is not asserted. Indicates that the core has detected a timeout condition on  the USB for the last IN token on this endpoint. Values:  <br><li> 0x0 (INACTIVE): No Timeout interrupt <br><li> 0x1 (ACTIVE): Timeout interrupt */
                  __IOM uint32_t DIEP_IN_T_N_IN_TKN_TXFEMP : 1 ;     /*!< [4:4] : IN Token Received When TxFIFO is Empty (INTknTXFEmp) Applies to non-periodic IN endpoints only. Indicates that an IN token was received when the associated  TxFIFO (periodic/non-periodic) was empty. This interrupt is  asserted on the endpoint for which the IN token was received. Values:  <br><li> 0x0 (INACTIVE): No IN Token Received interrupt <br><li> 0x1 (ACTIVE): IN Token Received Interrupt */
                  __IOM uint32_t DIEP_IN_T_N_IN_TKN_EP_MIS : 1 ;     /*!< [5:5] : IN Token Received with EP Mismatch (INTknEPMis) Applies to non-periodic IN endpoints only. Indicates that the data in the top of the non-periodic TxFIFO  belongs to an endpoint other than the one for which the IN  token was received. This interrupt is asserted on the  endpoint for which the IN token was received. Values:  <br><li> 0x0 (INACTIVE): No IN Token Received with EP Mismatch interrupt <br><li> 0x1 (ACTIVE): IN Token Received with EP Mismatch interrupt */
                  __IOM uint32_t DIEP_IN_T_N_IN_EP_NAK_EFF : 1 ;     /*!< [6:6] : IN Endpoint NAK Effective (INEPNakEff) Applies to periodic IN endpoints only. This bit can be cleared when the application clears the IN  endpoint NAK by writing to DIEPCTLn.CNAK. This interrupt indicates that the core has sampled the NAK bit Set (either by the application or by the core). The interrupt  indicates that the IN endpoint NAK bit Set by the application  has taken effect in the core. This interrupt does not guarantee that a NAK handshake is  sent on the USB. A STALL bit takes priority over a NAK bit. Values:  <br><li> 0x0 (INACTIVE): No Endpoint NAK Effective interrupt <br><li> 0x1 (ACTIVE): IN Endpoint NAK Effective interrupt */
                  __IM  uint32_t DIEP_IN_T_N_TXF_EMP       : 1 ;     /*!< [7:7] : Transmit FIFO Empty (TxFEmp) This bit is valid only for IN endpoints This interrupt is asserted when the TxFIFO for this endpoint  is either half or completely empty. The half or completely  empty status is determined by the TxFIFO Empty Level bit in  the Core AHB Configuration register  (GAHBCFG.NPTxFEmpLvl)). Values:  <br><li> 0x0 (INACTIVE): No Transmit FIFO Empty interrupt <br><li> 0x1 (ACTIVE): Transmit FIFO Empty interrupt */
                  __IOM uint32_t DIEP_IN_T_N_TXFIFO_UNDRN  : 1 ;     /*!< [8:8] : Fifo Underrun (TxfifoUndrn) Applies to IN endpoints Only This bit is valid only If thresholding is enabled. The core  generates this interrupt when it detects a transmit FIFO  underrun condition for this endpoint. Values:  <br><li> 0x0 (INACTIVE): No Tx FIFO Underrun interrupt <br><li> 0x1 (ACTIVE): TxFIFO Underrun interrupt */
                  __IOM uint32_t DIEP_IN_T_N_BNAINTR       : 1 ;     /*!< [9:9] : BNA (Buffer Not Available) Interrupt (BNAIntr) This bit is valid only when Scatter/Gather DMA mode is enabled. The core generates this interrupt when the descriptor  accessed is not ready for the Core to process, such as Host  busy or DMA done. Values:  <br><li> 0x0 (INACTIVE): No BNA interrupt <br><li> 0x1 (ACTIVE): BNA interrupt */
                        uint32_t RSV_104                   : 1 ;     /*!< [10:10] : reserved */
                  __IOM uint32_t DIEP_IN_T_N_PKT_DRP_STS   : 1 ;     /*!< [11:11] : Packet Drop Status (PktDrpSts) This bit indicates to the application that an ISOC OUT packet  has been dropped. This bit does not have an associated  mask bit and does not generate an interrupt. Dependency: This bit is valid in non Scatter/Gather DMA  mode when periodic transfer interrupt feature is selected. Values:  <br><li> 0x0 (INACTIVE): No interrupt <br><li> 0x1 (ACTIVE): Packet Drop Status interrupt */
                  __IOM uint32_t DIEP_IN_T_N_BBLE_ERR      : 1 ;     /*!< [12:12] : NAK Interrupt (BbleErr) The core generates this interrupt when babble is received for the endpoint. Values:  <br><li> 0x0 (INACTIVE): No interrupt <br><li> 0x1 (ACTIVE): BbleErr interrupt */
                  __IOM uint32_t DIEP_IN_T_N_NAKINTRPT     : 1 ;     /*!< [13:13] : NAK Interrupt (NAKInterrupt) The core generates this interrupt when a NAK is transmitted  or received by the device. In case of isochronous IN  endpoints the interrupt gets generated when a zero length  packet is transmitted due to un-availability of data in the TXFifo. Values:  <br><li> 0x0 (INACTIVE): No NAK interrupt <br><li> 0x1 (ACTIVE): NAK Interrupt */
                        uint32_t RSV_105                   : 18;     /*!< [31:14] : reserved */
               } DIEPINT_Nb;
            };
    
            uint8_t                        RSV_0X90c[4]                  ;   /*!< 0x0000090c~0x0000090f : reserved */
    
            union
            {
               __IOM uint32_t DIEPTSIZ_N;  /*!< 0x00000910 */ 
               
               struct
               {
                  __IOM uint32_t DIEP_TSIZ_N_XFER_SIZE     : 10;     /*!< [9:0] : Transfer Size (XferSize) Indicates the transfer size in bytes for endpoint 0. The core  interrupts the application only after it has exhausted the  transfer size amount of data. The transfer size can be Set to  the maximum packet size of the endpoint, to be interrupted  at the end of each packet. The core decrements this field every time a packet from the  external memory is written to the TxFIFO. */
                        uint32_t RSV_1                     : 9 ;     /*!< [18:10] : reserved. */
                  __IOM uint32_t DIEP_TSIZ_N_PKT_CNT       : 10;     /*!< [28:19] : Packet Count (PktCnt) Indicates the total number of USB packets that constitute the  Transfer Size amount of data for endpoint 0. This field is decremented every time a packet (maximum size  or short packet) is read from the TxFIFO. */
                  __IOM uint32_t MC                        : 2 ;     /*!< [30:29] : MC Applies to IN endpoints only. For periodic IN endpoints, this field indicates the number of  packets that must be transmitted per microframe on the  USB. The core uses this field to calculate the data PID for  isochronous IN endpoints.  <br><li> 2'b01: 1 packet  <br><li> 2'b10: 2 packets  <br><li> 2'b11: 3 packets  For non-periodic IN endpoints, this field is valid only in  Internal DMA mode. It specifies the number of packets the  core must fetchfor an IN endpoint before it switches to the  endpoint pointed to by the Next Endpoint field of the Device  Endpoint-n Control register (DIEPCTLn.NextEp) Values:  <br><li> 0x1 (PACKETONE): 1 packet <br><li> 0x2 (PACKETTWO): 2 packets <br><li> 0x3 (PACKETTHREE): 3 packets */
                        uint32_t RSV_107                   : 1 ;     /*!< [31:31] : reserved */
               } DIEPTSIZ_Nb;
            };
    
            union
            {
               __IOM uint32_t DIEPDMA_N;  /*!< 0x00000914 */ 
               
               struct
               {
                  __IOM uint32_t DIEP_DMA_N_DMA_ADDR       : 32;     /*!< [31:0] : Holds the start address of the external memory for storing or  fetching endpoint data. Note: For control endpoints, this field stores control OUT  data packets as well as SETUP transaction data packets.  When more than three SETUP packets are received back-to- back, the SETUP data packet in the memory is overwritten. This register is incremented on every AHB transaction. The  application can give only a DWORD-aligned address. <br><li> When Scatter/Gather DMA mode is not enabled, the  application programs the start address value in this field. <br><li> When Scatter/Gather DMA mode is enabled, this field  indicates the base pointer for the descriptor list. */
               } DIEPDMA_Nb;
            };
    
            union
            {
               __IM uint32_t DTXFSTS_N;  /*!< 0x00000918 */ 
               
               struct
               {
                  __IM  uint32_t IN_EP_TXF_SPC_AVAIL       : 16;     /*!< [15:0] : IN Endpoint TxFIFO Space Avail (INEPTxFSpcAvail) Indicates the amount of free space available in the Endpoint TxFIFO. Values are in terms of 32-bit words. <br><li> 16'h0: Endpoint TxFIFO is full <br><li> 16'h1: 1 word available <br><li> 16'h2: 2 words available <br><li> 16'hn: n words available (where 0  n  32,768) <br><li> 16'h8000: 32,768 words available <br><li> Others: Reserved In DRD configurations (OTG_MODE = 0, 1, or 2) with  dynamic fifo sizing feature enabled  (OTG_DFIFO_DYNAMIC=1), the value of this field is, <br><li> the maximum value of (OTG_TX_HNPERIO_DFIFO_DEPTH, OTG_TX_DINEP_DFIFO_DEPTH_0) during reset, and  <br><li> OTG_TX_DINEP_DFIFO_DEPTH_0, immediately after reset deassertion Value After Reset: * Varies based on Configuration */
                        uint32_t RSV_108                   : 16;     /*!< [31:16] : reserved */
               } DTXFSTS_Nb;
            };
    
            union
            {
               __IM uint32_t DIEPDMAB_N;  /*!< 0x0000091c */ 
               
               struct
               {
                  __IM  uint32_t DIEP_DMA_B_N_DMA_BUFFER_ADDR : 32;     /*!< [31:0] : Holds the current buffer address.This register is updated as  and when the data transfer for the corresponding end point is in progress. This register is present only in Scatter/Gather DMA mode.  Otherwise this field is reserved. */
               } DIEPDMAB_Nb;
            };
    } DIEP_GRPb[16];
    
    
    /*!< 0x00000b00~0x00000cff : register for Device Endpoint group */
    struct
    {
            union
            {
               __IOM uint32_t DOEPCTL_N;  /*!< 0x00000b00 */ 
               
               struct
               {
                  __IOM uint32_t DOEP_CTL_N_MPS            : 11;     /*!< [10:0] : Maximum Packet Size (MPS) The application must program this field with the maximum  packet size for the current logical endpoint. This value is in bytes. */
                        uint32_t RSV_109                   : 4 ;     /*!< [14:11] : reserved */
                  __IOM uint32_t DOEP_CTL_N_USB_ACT_EP     : 1 ;     /*!< [15:15] : USB Active Endpoint (USBActEP) Indicates whether this endpoint is active in the current  configuration and interface. The core clears this bit for all  endpoints (other than EP 0) after detecting a USB reset.  After receiving the SetConfiguration and SetInterface  commands, the application must program endpoint registers  accordingly and set this bit. Values:  <br><li> 0x0 (DISABLED): Not Active <br><li> 0x1 (ENABLED): USB Active Endpoint */
                  __IM  uint32_t DOEP_CTL_N_DPID           : 1 ;     /*!< [16:16] : Endpoint Data PID (DPID) Applies to interrupt/bulk IN and OUT endpoints only. Contains the PID of the packet to be received or transmitted  on this endpoint. The application must program the PID of  the first packet to be received or transmitted on this endpoint,  after the endpoint is activated. The applications use the  SetD1PID and SetD0PID fields of this register to program  either DATA0 or DATA1 PID. <br><li> 1'b0: DATA0 <br><li> 1'b1: DATA1 This field is applicable for both Scatter/Gather DMA mode  and non-Scatter/Gather DMA mode. Reset: 1'b0 Even/Odd (Micro)Frame (EO_FrNum) In non-Scatter/Gather DMA mode: <br><li> Applies to isochronous IN and OUT endpoints only. <br><li> Indicates the (micro)frame number in which the core  transmits/receives isochronous data for this endpoint.  The application must program the even/odd (micro)frame  number in which it intends to transmit/receive  isochronous data for this endpoint using the SetEvnFr  and SetOddFr fields in this register. - 1'b0: Even (micro)frame - 1'b1: Odd (micro)frame <br><li> When Scatter/Gather DMA mode is enabled, this field is  reserved. The frame number in which to send data is  provided in the transmit descriptor structure. The frame in  which data is received is updated in receive descriptor  structure. Reset: 1'b0 Values:  <br><li> 0x0 (INACTIVE): Endpoint Data PID not active <br><li> 0x1 (ACTIVE): Endpoint Data PID active */
                  __IM  uint32_t DOEP_CTL_N_NAKSTS         : 1 ;     /*!< [17:17] : NAK Status (NAKSts) Indicates the following: <br><li> 1'b0: The core is transmitting non-NAK handshakes based on the FIFO status. <br><li> 1'b1: The core is transmitting NAK handshakes on this endpoint. When either the application or the core sets this bit: <br><li> The core stops receiving any data on an OUT endpoint,  even if there is space in the RxFIFO to accommodate the incoming packet. <br><li> For non-isochronous IN endpoints: The core stops  transmitting any data on an IN endpoint, even if there  data is available in the TxFIFO. <br><li> For isochronous IN endpoints: The core sends out a zero- length data packet, even if there data is available in the TxFIFO. Irrespective of this bit's setting, the core always responds to  SETUP data packets with an ACK handshake. Values:  <br><li> 0x0 (NONNAK):  The core is transmitting non-NAK handshakes based on the FIFO status <br><li> 0x1 (NAK):  The core is transmitting NAK handshakes on this endpoint */
                  __IOM uint32_t DOEP_CTL_N_EP_TYPE        : 2 ;     /*!< [19:18] : Endpoint Type (EPType) This is the transfer type supported by this logical endpoint. <br><li> 2'b00: Control <br><li> 2'b01: Isochronous <br><li> 2'b10: Bulk <br><li> 2'b11: Interrupt Values:  <br><li> 0x0 (CONTROL): Control <br><li> 0x1 (ISOCHRONOUS): Isochronous <br><li> 0x2 (BULK): Bulk <br><li> 0x3 (INTERRUPT): Interrupt */
                  __IOM uint32_t DOEP_CTL_N_SNP            : 1 ;     /*!< [20:20] : RESERVED Values:  <br><li> 0x0 (RESERVED0): Reserved 0 <br><li> 0x1 (RESERVED1): Reserved 1 */
                  __IOM uint32_t DOEP_CTL_N_STALL          : 1 ;     /*!< [21:21] : STALL Handshake (Stall) Applies to non-control, non-isochronous IN and OUT  endpoints only. The application sets this bit to stall all tokens from the USB  host to this endpoint. If a NAK bit, Global Non-periodic IN  NAK, or Global OUT NAK is set along with this bit, the  STALL bit takes priority. Only the application can clear this  bit, never the core. Applies to control endpoints only. The application can only set this bit, and the core clears it,  when a SETUP token is received for this endpoint. If a NAK  bit, Global Non-periodic IN NAK, or Global OUT NAK is set  along with this bit, the STALL bit takes priority. Irrespective of  this bit's setting, the core always responds to SETUP data  packets with an ACK handshake. Values:  <br><li> 0x0 (INACTIVE): STALL All non-active tokens <br><li> 0x1 (ACTIVE): STALL All Active Tokens */
                        uint32_t RSV_110                   : 4 ;     /*!< [25:22] : reserved */
                  __OM  uint32_t DOEP_CTL_N_CNAK           : 1 ;     /*!< [26:26] : Clear NAK (CNAK) A write to this bit clears the NAK bit for the endpoint. Values:  <br><li> 0x0 (INACTIVE): No Clear NAK <br><li> 0x1 (ACTIVE): Clear NAK */
                  __OM  uint32_t DOEP_CTL_N_SNAK           : 1 ;     /*!< [27:27] : Set NAK (SNAK) A write to this bit sets the NAK bit for the endpoint. Using this bit, the application can control the transmission of  NAK handshakes on an endpoint. The core can also set this  bit for an endpoint after a SETUP packet is received on that  endpoint. Values:  <br><li> 0x0 (INACTIVE): No Set NAK <br><li> 0x1 (ACTIVE): Set NAK */
                  __OM  uint32_t DOEP_CTL_N_SET_D0PID      : 1 ;     /*!< [28:28] : Set DATA0 PID (SetD0PID) <br><li> Applies to interrupt/bulk IN and OUT endpoints only. <br><li> Writing to this field sets the Endpoint Data PID (DPID)  field in this register to DATA0. <br><li> This field is applicable both for Scatter/Gather DMA mode  and non-Scatter/Gather DMA mode. Reset: 1'b0 In non-Scatter/Gather DMA mode: Set Even (micro)frame  (SetEvenFr) <br><li> Applies to isochronous IN and OUT endpoints only. <br><li> Writing to this field sets the Even/Odd (micro)frame  (EO_FrNum) field to even (micro)frame. <br><li> When Scatter/Gather DMA mode is enabled, this field is  reserved. The frame number in which to send data is in  the transmit descriptor structure. The frame in which to  receive data is updated in receive descriptor structure. Reset: 1'b0 Values:  <br><li> 0x0 (DISABLED): Disables Set DATA0 PID or Do not  force Even Frame <br><li> 0x1 (ENABLED): Set Endpoint Data PID to DATA0 or  Sets EO_FrNum field to odd (micro)Frame */
                  __OM  uint32_t DOEP_CTL_N_SET_D1PID      : 1 ;     /*!< [29:29] : Set DATA1 PID (SetD1PID) <br><li> Applies to interrupt and bulk IN and OUT endpoints only. <br><li> Writing to this field sets the Endpoint Data PID (DPID)  field in this register to DATA1. <br><li> This field is applicable both for scatter-gather DMA mode  and non scatter-gather DMA mode. Reset: 1'b0 Set Odd (micro)frame (SetOddFr) <br><li> Applies to isochronous IN and OUT endpoints only. <br><li> Writing to this field sets the even and odd (micro)frame  (EO_FrNum) field to odd (micro)frame. Reset: 1'b0 Values:  <br><li> 0x0 (DISABLED): Disables Set DATA1 PID or Do not  force Odd Frame <br><li> 0x1 (ENABLED): Set Endpoint Data PID to DATA1 or  Sets EO_FrNum field to odd (micro)Frame */
                  __IOM uint32_t DOEP_CTL_N_EP_DIS         : 1 ;     /*!< [30:30] : Endpoint Disable (EPDis) Applies to IN and OUT endpoints. The application sets this bit to stop transmitting/receiving  data on an endpoint, even before the transfer for that  endpoint is complete. The application must wait for the  Endpoint Disabled interrupt before treating the endpoint as  disabled. The core clears this bit before setting the Endpoint  Disabled interrupt. The application must set this bit only if  Endpoint Enable is already set for this endpoint. Values:  <br><li> 0x0 (INACTIVE): No Action <br><li> 0x1 (ACTIVE): Disable Endpoint */
                  __IOM uint32_t DOEP_CTL_N_EP_ENA         : 1 ;     /*!< [31:31] : Endpoint Enable (EPEna) Applies to IN and OUT endpoints. When Scatter/Gather DMA mode is enabled, <br><li> For IN endpoints this bit indicates that the descriptor  structure and data buffer with data ready to transmit is setup. <br><li> For OUT endpoint it indicates that the descriptor structure  and data buffer to receive data is setup. When Scatter/Gather DMA mode is enabled such as for  buffer-pointer based DMA mode: <br><li> For IN endpoints, this bit indicates that data is ready to be  transmitted on the endpoint. <br><li> For OUT endpoints, this bit indicates that the application  has allocated the memory to start receiving data from the USB. The core clears this bit before setting any of the following  interrupts on this endpoint: <br><li> SETUP Phase Done <br><li> Endpoint Disabled <br><li> Transfer Completed  Note: For control endpoints in DMA mode, this bit must be  set for the controller to transfer SETUP data packets to the  memory. This bit will not be cleared on Transfer Completed  interrupt of the SETUP packet. Values:  <br><li> 0x0 (INACTIVE): No Action <br><li> 0x1 (ACTIVE): Enable Endpoint */
               } DOEPCTL_Nb;
            };
    
            uint8_t                        RSV_0Xb24[4]                  ;   /*!< 0x00000b04~0x00000b07 : reserved */
    
            union
            {
               __IOM uint32_t DOEPINT_N;  /*!< 0x00000b08 */ 
               
               struct
               {
                  __IOM uint32_t DOEP_IN_T_N_XFER_COMPL    : 1 ;     /*!< [0:0] : Transfer Completed Interrupt (XferCompl) Applies to IN and OUT endpoints. <br><li> When Scatter/Gather DMA mode is enabled - For IN endpoint this field indicates that the requested  data from the descriptor is moved from external  system memory to internal FIFO. - For OUT endpoint this field indicates that the  requested data from the internal FIFO is moved to  external system memory. This interrupt is generated  only when the corresponding endpoint descriptor is  closed, and the IOC bit for the corresponding  descriptor is Set. <br><li> When Scatter/Gather DMA mode is disabled, this field  indicates that the programmed transfer is complete on the  AHB as well as on the USB, for this endpoint. Values:  <br><li> 0x0 (INACTIVE): No Transfer Complete Interrupt <br><li> 0x1 (ACTIVE): Transfer Complete Interrupt */
                  __IOM uint32_t DOEP_IN_T_N_EP_DISBLD     : 1 ;     /*!< [1:1] : Endpoint Disabled Interrupt (EPDisbld) Applies to IN and OUT endpoints. This bit indicates that the endpoint is disabled per the  application's request. Values:  <br><li> 0x0 (INACTIVE): No Endpoint Disabled Interrupt <br><li> 0x1 (ACTIVE): Endpoint Disabled Interrupt */
                  __IOM uint32_t DOEP_IN_T_N_AHB_ERR       : 1 ;     /*!< [2:2] : AHB Error (AHBErr) Applies to IN and OUT endpoints. This is generated only in Internal DMA mode when there is  an AHB error during an AHB read/write. The application can  read the corresponding endpoint DMA address register to  get the error address. For details, see "AHB Error Handling"  section in the Programming Guide. Values:  <br><li> 0x0 (INACTIVE): No AHB Error Interrupt <br><li> 0x1 (ACTIVE): AHB Error interrupt */
                  __IOM uint32_t DOEP_IN_T_N_SET_UP        : 1 ;     /*!< [3:3] : SETUP Phase Done (SetUp) Applies to control OUT endpoints only. Indicates that the SETUP phase for the control endpoint is  complete and no more back-to-back SETUP packets were  received for the current control transfer. On this interrupt, the  application can decode the received SETUP data packet. Values:  <br><li> 0x0 (INACTIVE): No SETUP Phase Done <br><li> 0x1 (ACTIVE): SETUP Phase Done */
                  __IOM uint32_t DOEP_IN_T_N_OUT_TKN_EP_DIS : 1 ;     /*!< [4:4] : OUT Token Received When Endpoint Disabled (OUTTknEPdis) Applies only to control OUT endpoints. Indicates that an OUT token was received when the endpoint  was not yet enabled. This interrupt is asserted on the  endpoint for which the OUT token was received. Values:  <br><li> 0x0 (INACTIVE): No OUT Token Received When Endpoint Disabled <br><li> 0x1 (ACTIVE): OUT Token Received When Endpoint Disabled */
                  __IOM uint32_t DOEP_IN_T_N_STS_PHSE_RCVD : 1 ;     /*!< [5:5] : Status Phase Received for Control Write (StsPhseRcvd) This interrupt is valid only for Control OUT endpoints. This interrupt is generated only after the core has transferred  all the data that the host has sent during the data phase of a  control write transfer, to the system memory buffer. The interrupt indicates to the application that the host has  switched from data phase to the status phase of a Control  Write transfer. The application can use this interrupt to ACK  or STALL the Status phase, after it has decoded the data  phase. This is applicable only in Case of Scatter Gather DMA mode. Values:  <br><li> 0x0 (INACTIVE): No Status Phase Received for Control Write <br><li> 0x1 (ACTIVE): Status Phase Received for Control Write */
                  __IOM uint32_t DOEP_IN_T_N_BACK2BACK_SETUP : 1 ;     /*!< [6:6] : Back-to-Back SETUP Packets Received (Back2BackSETup) Applies to Control OUT endpoints only. This bit indicates that the core has received more than three  back-to-back SETUP packets for this particular endpoint. For  information about handling this interrupt, Values:  <br><li> 0x0 (INACTIVE): No Back-to-Back SETUP Packets Received <br><li> 0x1 (ACTIVE): Back-to-Back SETUP Packets Received */
                        uint32_t RSV_111                   : 1 ;     /*!< [7:7] : reserved */
                  __IOM uint32_t DOEP_IN_T_N_OUT_PKT_ERR   : 1 ;     /*!< [8:8] : OUT Packet Error (OutPktErr) Applies to OUT endpoints Only This interrupt is valid only when thresholding is enabled. This  interrupt is asserted when the core detects an overflow or a  CRC error for non-Isochronous OUT packet. Values:  <br><li> 0x0 (INACTIVE): No OUT Packet Error <br><li> 0x1 (ACTIVE): OUT Packet Error */
                  __IOM uint32_t DOEP_IN_T_N_BNAINTR       : 1 ;     /*!< [9:9] : BNA (Buffer Not Available) Interrupt (BNAIntr) This bit is valid only when Scatter/Gather DMA mode is enabled. The core generates this interrupt when the descriptor  accessed is not ready for the Core to process, such as Host  busy or DMA done Values:  <br><li> 0x0 (INACTIVE): No BNA interrupt <br><li> 0x1 (ACTIVE): BNA interrupt */
                        uint32_t RSV_112                   : 1 ;     /*!< [10:10] : reserved */
                  __IOM uint32_t DOEP_IN_T_N_PKT_DRP_STS   : 1 ;     /*!< [11:11] : Packet Drop Status (PktDrpSts) This bit indicates to the application that an ISOC OUT packet  has been dropped. This bit does not have an associated  mask bit and does not generate an interrupt. Dependency: This bit is valid in non Scatter/Gather DMA  mode when periodic transfer interrupt feature is selected. Values:  <br><li> 0x0 (INACTIVE): No interrupt <br><li> 0x1 (ACTIVE): Packet Drop Status interrupt */
                  __IOM uint32_t DOEP_IN_T_N_BBLE_ERR      : 1 ;     /*!< [12:12] : NAK Interrupt (BbleErr) The core generates this interrupt when babble is received for the endpoint. Values:  <br><li> 0x0 (INACTIVE): No BbleErr interrupt <br><li> 0x1 (ACTIVE): BbleErr interrupt */
                  __IOM uint32_t DOEP_IN_T_N_NAKINTRPT     : 1 ;     /*!< [13:13] : NAK Interrupt (NAKInterrupt) The core generates this interrupt when a NAK is transmitted  or received by the device. In case of isochronous IN endpoints the interrupt gets  generated when a zero length packet is transmitted due to  un-availability of data in the TXFifo. Values:  <br><li> 0x0 (INACTIVE): No NAK interrupt <br><li> 0x1 (ACTIVE): NAK Interrupt */
                  __IOM uint32_t DOEP_IN_T_N_NYETINTRPT    : 1 ;     /*!< [14:14] : NYET Interrupt (NYETIntrpt) The core generates this interrupt when a NYET response is  transmitted for a non isochronous OUT endpoint. Values:  <br><li> 0x0 (INACTIVE): No NYET interrupt <br><li> 0x1 (ACTIVE): NYET Interrupt */
                  __IOM uint32_t DOEP_IN_T_N_STUP_PKT_RCVD : 1 ;     /*!< [15:15] : Setup Packet Received Applicable for Control OUT Endpoints in only in the Buffer  DMA Mode Set by the controller, this bit indicates that this buffer holds 8  bytes of setup data. There is only one Setup packet per  buffer. On receiving a Setup packet, the controller closes the  buffer and disables the corresponding endpoint. The  application has to re-enable the endpoint to receive any OUT  data for the Control Transfer and reprogram the buffer start  address. Note: Because of the above behavior, the controller can  receive any number of back to back setup packets and one  buffer for every setup packet is used. <br><li> 1'b0: No Setup packet received <br><li> 1'b1: Setup packet received Reset: 1'b0 Values:  <br><li> 0x0 (NOT_RCVD): No Setup packet received <br><li> 0x1 (RCVD): Setup packet received */
                        uint32_t RSV_113                   : 16;     /*!< [31:16] : reserved */
               } DOEPINT_Nb;
            };
    
            uint8_t                        RSV_0Xb0c[4]                  ;   /*!< 0x00000b0c~0x00000b0f : reserved */
    
            union
            {
               __IOM uint32_t DOEPTSIZ_N;  /*!< 0x00000b10 */ 
               
               struct
               {
                  __IOM uint32_t DOEP_TSIZ_N_XFER_SIZE     : 19;     /*!< [18:0] : Transfer Size (XferSize) Indicates the transfer size in bytes for endpoint 0. The core  interrupts the application only after it has exhausted the  transfer size amount of data. The transfer size can be Set to  the maximum packet size of the endpoint, to be interrupted  at the end of each packet. The core decrements this field every time a packet is read  from the RxFIFO and written to the external memory. */
                  __IOM uint32_t DOEP_TSIZ_N_PKT_CNT       : 10;     /*!< [28:19] : Packet Count (PktCnt) This field is decremented to zero after  a packet is written into the RxFIFO. */
                  __IM  uint32_t RX_DPID                   : 2 ;     /*!< [30:29] : RxDPID. Applies to isochronous OUT endpoints only. This is the data PID received in the last packet for this  endpoint. <br><li> 2'b00: DATA0 <br><li> 2'b01: DATA2 <br><li> 2'b10: DATA1 <br><li> 2'b11: MDATA SETUP Packet Count (SUPCnt) Applies to control OUT Endpoints only. This field specifies the number of back-to-back SETUP data  packets the endpoint can receive. <br><li> 2'b01: 1 packet <br><li> 2'b10: 2 packets <br><li> 2'b11: 3 packets Values:  <br><li> 0x0 (DATA0): DATA0 <br><li> 0x1 (DATA2PACKET1): DATA2 or 1 packet <br><li> 0x2 (DATA1PACKET2): DATA1 or 2 packets <br><li> 0x3 (MDATAPACKET3): MDATA or 3 packets */
                        uint32_t RSV_114                   : 1 ;     /*!< [31:31] : reserved */
               } DOEPTSIZ_Nb;
            };
    
            union
            {
               __IOM uint32_t DOEPDMA_N;  /*!< 0x00000b14 */ 
               
               struct
               {
                  __IOM uint32_t DOEP_DMA_N_DMA_ADDR       : 32;     /*!< [31:0] : Holds the start address of the external memory for storing or  fetching endpoint data. Note: For control endpoints, this field stores control OUT  data packets as well as SETUP transaction data packets.  When more than three SETUP packets are received back-to- back, the SETUP data packet in the memory is overwritten. This register is incremented on every AHB transaction. The  application can give only a DWORD-aligned address. <br><li> When Scatter/Gather DMA mode is not enabled, the  application programs the start address value in this field. <br><li> When Scatter/Gather DMA mode is enabled, this field  indicates the base pointer for the descriptor list. */
               } DOEPDMA_Nb;
            };
    
            uint8_t                        RSV_0Xb38[4]                  ;   /*!< 0x00000b18~0x00000b1b : reserved */
    
            union
            {
               __IM uint32_t DOEPDMAB_N;  /*!< 0x00000b1c */ 
               
               struct
               {
                  __IM  uint32_t DOEP_DMA_B_N_DMA_BUFFER_ADDR : 32;     /*!< [31:0] : Holds the current buffer address.This register is updated as  and when the data transfer for the corresponding end point is in progress. This register is present only in Scatter/Gather DMA mode.  Otherwise this field is reserved. */
               } DOEPDMAB_Nb;
            };
    } DOEP_GRPb[16];

    uint8_t              RSV_0Xd00[256]                ;   /*!< 0x00000d00~0x00000dff : reserved */

    union
    {
       __IOM uint32_t PCGCCTL;  /*!< 0x00000e00 */ 
       
       struct
       {
          __IOM uint32_t STOP_PCLK                 : 1 ;     /*!< [0:0] : Stop Pclk (StopPclk) <br><li> The application sets this bit to stop the PHY clock  (phy_clk) when the USB is suspended, the session is not  valid, or the device is disconnected. <br><li> The application clears this bit when the USB is resumed  or a new session starts. Values:  <br><li> 0x0 (DISABLED): Disable Stop Pclk <br><li> 0x1 (ENABLED): Enable Stop Pclk Value After Reset: * Varies based on Configuration */
          __IOM uint32_t GATE_HCLK                 : 1 ;     /*!< [1:1] : Gate Hclk (GateHclk) <br><li> The application sets this bit to gate hclk to modules other  than the AHB Slave and Master and wakeup logic when  the USB is suspended or the session is not valid. <br><li> The application clears this bit when the USB is resumed  or a new session starts. Values:  <br><li> 0x0 (DISABLED): Clears this bit when the USB is  resumed or a new session starts <br><li> 0x1 (ENABLED): Sets this bit to gate hclk to modules  when the USB is suspended or the session is not valid Value After Reset: * Varies based on Configuration */
          __IOM uint32_t PWR_CLMP                  : 1 ;     /*!< [2:2] : Power Clamp (PwrClmp) This bit is valid only in Partial Power-Down mode <br><li> The application sets this bit before the power is turned off  to clamp the signals between the power-on modules and  the power-off modules.  <br><li> The application clears the bit to disable the clamping  before the power is turned on. Values:  <br><li> 0x0 (DISABLED): Clears this bit to disable the clamping  before the power is turned on <br><li> 0x1 (ENABLED): In only Partial Power-Down mode, sets  this bit to clamp the signals between the power-on  modules and the power-off modules before the power is turned off Value After Reset: * Varies based on Configuration */
          __IOM uint32_t RST_PDWN_MODULE           : 1 ;     /*!< [3:3] : Reset Power-Down Modules (RstPdwnModule) This bit is valid only in Partial Power-Down mode.  <br><li> The application sets this bit when the power is turned off.  <br><li> The application clears this bit after the power is turned on  and the PHY clock is up. Note: The R/W of all core registers are possible only when  this bit is set to 1b0. Values:  <br><li> 0x0 (ON): Power is turned on <br><li> 0x1 (OFF): Power is turned off Value After Reset: * Varies based on Configuration */
                uint32_t RSV_86                    : 1 ;     /*!< [4:4] : reserved */
          __IOM uint32_t ENBL_L1GATING             : 1 ;     /*!< [5:5] : Enable Sleep Clock Gating  If this bit is set, core internal clock gating is enabled sleep  state  if utmi_l1_suspend_n cannot be asserted by the core. The PHY clock will not be gated in sleep state if  Enbl_L1Gating is not set. Values:  <br><li> 0x0 (DISABLED): The PHY clock is not gated in Sleep  state <br><li> 0x1 (ENABLED): The Core internal clock gating is  enabled in Sleep state Value After Reset: * Varies based on Configuration */
          __IM  uint32_t PHY_SLEEP                 : 1 ;     /*!< [6:6] : PHY In Sleep  Indicates that the PHY is in Sleep State. Values:  <br><li> 0x0 (INACTIVE): Phy not in Sleep state <br><li> 0x1 (ACTIVE): Phy in Sleep state Value After Reset: * Varies based on Configuration */
          __IM  uint32_t L1SUSPENDED               : 1 ;     /*!< [7:7] : L1 Deep Sleep  Indicates that the PHY is in deep sleep when in L1 state. Values:  <br><li> 0x0 (INACTIVE): Non Deep Sleep <br><li> 0x1 (ACTIVE): Deep Sleep Value After Reset: * Varies based on Configuration */
          __IOM uint32_t RESET_AFTER_SUSP          : 1 ;     /*!< [8:8] : Reset after suspend  Applicable in Partial power-down mode In partial power-down mode of operation, this bit needs to be  set in host mode before clamp is removed if the host needs  to issue reset after suspend. If this bit is not set, then the  host issues resume after suspend. This bit is not applicable in device mode and non-partial  power-down mode. In Hibernation mode, this bit needs to be  set at RESTORE_POINT before  PCGCCTL.EssRegRestored is set. In this case,  PCGCCTL.restore_mode needs to be set to wait_restore. Values:  <br><li> 0x0 (DISABLED): In Host-only mode, host issues  Resume after Suspend <br><li> 0x1 (ENABLED): In Host-only mode, host sets this bit  before clamp is removed if the host needs to issue Reset  after Suspend Value After Reset: * Varies based on Configuration */
                uint32_t RSV_87                    : 23;     /*!< [31:9] : reserved */
       } PCGCCTLb;
    };

} USB_Type;

/*!
 * @}
 */

/*!
 * \name USB Base Address Definitions
 *
 * @{
 */

/*! \brief USBA base address */
#define USBA_BASE (0x42000000UL)
/*! \brief USBA base pointer */
#define USBA ((USB_Type *) USBA_BASE)

/*!
 * @}
 */

 
/*!
 * \name USB Register Bitfield Definitions
 *
 * @{
 */

 /* DIEPTXF_N bitfield */
#define USB_DIEPTXF_N_IN_EP_N_TXF_DEP_Pos    (16U)                                                                       /*!< IN_EP_N_TXF_DEP Postion   */ 
#define USB_DIEPTXF_N_IN_EP_N_TXF_DEP_Msk    (0x1ffU << USB_DIEPTXF_N_IN_EP_N_TXF_DEP_Pos)                               /*!< IN_EP_N_TXF_DEP Mask      */
#define USB_DIEPTXF_N_IN_EP_N_TXF_DEP_Set(x) (((uint32_t) (x) << USB_DIEPTXF_N_IN_EP_N_TXF_DEP_Pos) & USB_DIEPTXF_N_IN_EP_N_TXF_DEP_Msk) /*!< IN_EP_N_TXF_DEP Set Value */
#define USB_DIEPTXF_N_IN_EP_N_TXF_DEP_Get(x) (((uint32_t) (x) & USB_DIEPTXF_N_IN_EP_N_TXF_DEP_Msk) >> USB_DIEPTXF_N_IN_EP_N_TXF_DEP_Pos) /*!< IN_EP_N_TXF_DEP Get Value */


#define USB_DIEPTXF_N_IN_EP_N_TXF_ST_ADDR_Pos    (0U)                                                                        /*!< IN_EP_N_TXF_ST_ADDR Postion   */ 
#define USB_DIEPTXF_N_IN_EP_N_TXF_ST_ADDR_Msk    (0x7ffU << USB_DIEPTXF_N_IN_EP_N_TXF_ST_ADDR_Pos)                           /*!< IN_EP_N_TXF_ST_ADDR Mask      */
#define USB_DIEPTXF_N_IN_EP_N_TXF_ST_ADDR_Set(x) (((uint32_t) (x) << USB_DIEPTXF_N_IN_EP_N_TXF_ST_ADDR_Pos) & USB_DIEPTXF_N_IN_EP_N_TXF_ST_ADDR_Msk) /*!< IN_EP_N_TXF_ST_ADDR Set Value */
#define USB_DIEPTXF_N_IN_EP_N_TXF_ST_ADDR_Get(x) (((uint32_t) (x) & USB_DIEPTXF_N_IN_EP_N_TXF_ST_ADDR_Msk) >> USB_DIEPTXF_N_IN_EP_N_TXF_ST_ADDR_Pos) /*!< IN_EP_N_TXF_ST_ADDR Get Value */


/* HCCHAR_N bitfield */
#define USB_HCCHAR_N_CH_ENA_Pos    (31U)                                                                       /*!< CH_ENA Postion   */ 
#define USB_HCCHAR_N_CH_ENA_Msk    (0x1U << USB_HCCHAR_N_CH_ENA_Pos)                                           /*!< CH_ENA Mask      */
#define USB_HCCHAR_N_CH_ENA_Set(x) (((uint32_t) (x) << USB_HCCHAR_N_CH_ENA_Pos) & USB_HCCHAR_N_CH_ENA_Msk)     /*!< CH_ENA Set Value */
#define USB_HCCHAR_N_CH_ENA_Get(x) (((uint32_t) (x) & USB_HCCHAR_N_CH_ENA_Msk) >> USB_HCCHAR_N_CH_ENA_Pos)     /*!< CH_ENA Get Value */


#define USB_HCCHAR_N_CH_DIS_Pos    (30U)                                                                       /*!< CH_DIS Postion   */ 
#define USB_HCCHAR_N_CH_DIS_Msk    (0x1U << USB_HCCHAR_N_CH_DIS_Pos)                                           /*!< CH_DIS Mask      */
#define USB_HCCHAR_N_CH_DIS_Set(x) (((uint32_t) (x) << USB_HCCHAR_N_CH_DIS_Pos) & USB_HCCHAR_N_CH_DIS_Msk)     /*!< CH_DIS Set Value */
#define USB_HCCHAR_N_CH_DIS_Get(x) (((uint32_t) (x) & USB_HCCHAR_N_CH_DIS_Msk) >> USB_HCCHAR_N_CH_DIS_Pos)     /*!< CH_DIS Get Value */


#define USB_HCCHAR_N_ODD_FRM_Pos    (29U)                                                                       /*!< ODD_FRM Postion   */ 
#define USB_HCCHAR_N_ODD_FRM_Msk    (0x1U << USB_HCCHAR_N_ODD_FRM_Pos)                                          /*!< ODD_FRM Mask      */
#define USB_HCCHAR_N_ODD_FRM_Set(x) (((uint32_t) (x) << USB_HCCHAR_N_ODD_FRM_Pos) & USB_HCCHAR_N_ODD_FRM_Msk)   /*!< ODD_FRM Set Value */
#define USB_HCCHAR_N_ODD_FRM_Get(x) (((uint32_t) (x) & USB_HCCHAR_N_ODD_FRM_Msk) >> USB_HCCHAR_N_ODD_FRM_Pos)   /*!< ODD_FRM Get Value */


#define USB_HCCHAR_N_HCCHAR_N_DEV_ADDR_Pos    (22U)                                                                       /*!< HCCHAR_N_DEV_ADDR Postion   */ 
#define USB_HCCHAR_N_HCCHAR_N_DEV_ADDR_Msk    (0x7fU << USB_HCCHAR_N_HCCHAR_N_DEV_ADDR_Pos)                               /*!< HCCHAR_N_DEV_ADDR Mask      */
#define USB_HCCHAR_N_HCCHAR_N_DEV_ADDR_Set(x) (((uint32_t) (x) << USB_HCCHAR_N_HCCHAR_N_DEV_ADDR_Pos) & USB_HCCHAR_N_HCCHAR_N_DEV_ADDR_Msk) /*!< HCCHAR_N_DEV_ADDR Set Value */
#define USB_HCCHAR_N_HCCHAR_N_DEV_ADDR_Get(x) (((uint32_t) (x) & USB_HCCHAR_N_HCCHAR_N_DEV_ADDR_Msk) >> USB_HCCHAR_N_HCCHAR_N_DEV_ADDR_Pos) /*!< HCCHAR_N_DEV_ADDR Get Value */


#define USB_HCCHAR_N_EC_Pos    (20U)                                                                       /*!< EC Postion   */ 
#define USB_HCCHAR_N_EC_Msk    (0x3U << USB_HCCHAR_N_EC_Pos)                                               /*!< EC Mask      */
#define USB_HCCHAR_N_EC_Set(x) (((uint32_t) (x) << USB_HCCHAR_N_EC_Pos) & USB_HCCHAR_N_EC_Msk)             /*!< EC Set Value */
#define USB_HCCHAR_N_EC_Get(x) (((uint32_t) (x) & USB_HCCHAR_N_EC_Msk) >> USB_HCCHAR_N_EC_Pos)             /*!< EC Get Value */


#define USB_HCCHAR_N_EP_TYPE_Pos    (18U)                                                                       /*!< EP_TYPE Postion   */ 
#define USB_HCCHAR_N_EP_TYPE_Msk    (0x3U << USB_HCCHAR_N_EP_TYPE_Pos)                                          /*!< EP_TYPE Mask      */
#define USB_HCCHAR_N_EP_TYPE_Set(x) (((uint32_t) (x) << USB_HCCHAR_N_EP_TYPE_Pos) & USB_HCCHAR_N_EP_TYPE_Msk)   /*!< EP_TYPE Set Value */
#define USB_HCCHAR_N_EP_TYPE_Get(x) (((uint32_t) (x) & USB_HCCHAR_N_EP_TYPE_Msk) >> USB_HCCHAR_N_EP_TYPE_Pos)   /*!< EP_TYPE Get Value */


#define USB_HCCHAR_N_LSPD_DEV_Pos    (17U)                                                                       /*!< LSPD_DEV Postion   */ 
#define USB_HCCHAR_N_LSPD_DEV_Msk    (0x1U << USB_HCCHAR_N_LSPD_DEV_Pos)                                         /*!< LSPD_DEV Mask      */
#define USB_HCCHAR_N_LSPD_DEV_Set(x) (((uint32_t) (x) << USB_HCCHAR_N_LSPD_DEV_Pos) & USB_HCCHAR_N_LSPD_DEV_Msk) /*!< LSPD_DEV Set Value */
#define USB_HCCHAR_N_LSPD_DEV_Get(x) (((uint32_t) (x) & USB_HCCHAR_N_LSPD_DEV_Msk) >> USB_HCCHAR_N_LSPD_DEV_Pos) /*!< LSPD_DEV Get Value */


#define USB_HCCHAR_N_HCCHAR_N_EP_DIR_Pos    (15U)                                                                       /*!< HCCHAR_N_EP_DIR Postion   */ 
#define USB_HCCHAR_N_HCCHAR_N_EP_DIR_Msk    (0x1U << USB_HCCHAR_N_HCCHAR_N_EP_DIR_Pos)                                  /*!< HCCHAR_N_EP_DIR Mask      */
#define USB_HCCHAR_N_HCCHAR_N_EP_DIR_Set(x) (((uint32_t) (x) << USB_HCCHAR_N_HCCHAR_N_EP_DIR_Pos) & USB_HCCHAR_N_HCCHAR_N_EP_DIR_Msk) /*!< HCCHAR_N_EP_DIR Set Value */
#define USB_HCCHAR_N_HCCHAR_N_EP_DIR_Get(x) (((uint32_t) (x) & USB_HCCHAR_N_HCCHAR_N_EP_DIR_Msk) >> USB_HCCHAR_N_HCCHAR_N_EP_DIR_Pos) /*!< HCCHAR_N_EP_DIR Get Value */


#define USB_HCCHAR_N_EP_NUM_Pos    (11U)                                                                       /*!< EP_NUM Postion   */ 
#define USB_HCCHAR_N_EP_NUM_Msk    (0xfU << USB_HCCHAR_N_EP_NUM_Pos)                                           /*!< EP_NUM Mask      */
#define USB_HCCHAR_N_EP_NUM_Set(x) (((uint32_t) (x) << USB_HCCHAR_N_EP_NUM_Pos) & USB_HCCHAR_N_EP_NUM_Msk)     /*!< EP_NUM Set Value */
#define USB_HCCHAR_N_EP_NUM_Get(x) (((uint32_t) (x) & USB_HCCHAR_N_EP_NUM_Msk) >> USB_HCCHAR_N_EP_NUM_Pos)     /*!< EP_NUM Get Value */


#define USB_HCCHAR_N_MPS_Pos    (0U)                                                                        /*!< MPS Postion   */ 
#define USB_HCCHAR_N_MPS_Msk    (0x7ffU << USB_HCCHAR_N_MPS_Pos)                                            /*!< MPS Mask      */
#define USB_HCCHAR_N_MPS_Set(x) (((uint32_t) (x) << USB_HCCHAR_N_MPS_Pos) & USB_HCCHAR_N_MPS_Msk)           /*!< MPS Set Value */
#define USB_HCCHAR_N_MPS_Get(x) (((uint32_t) (x) & USB_HCCHAR_N_MPS_Msk) >> USB_HCCHAR_N_MPS_Pos)           /*!< MPS Get Value */


/* HCSPLT_N bitfield */
#define USB_HCSPLT_N_SPLT_ENA_Pos    (31U)                                                                       /*!< SPLT_ENA Postion   */ 
#define USB_HCSPLT_N_SPLT_ENA_Msk    (0x1U << USB_HCSPLT_N_SPLT_ENA_Pos)                                         /*!< SPLT_ENA Mask      */
#define USB_HCSPLT_N_SPLT_ENA_Set(x) (((uint32_t) (x) << USB_HCSPLT_N_SPLT_ENA_Pos) & USB_HCSPLT_N_SPLT_ENA_Msk) /*!< SPLT_ENA Set Value */
#define USB_HCSPLT_N_SPLT_ENA_Get(x) (((uint32_t) (x) & USB_HCSPLT_N_SPLT_ENA_Msk) >> USB_HCSPLT_N_SPLT_ENA_Pos) /*!< SPLT_ENA Get Value */


#define USB_HCSPLT_N_COMP_SPLT_Pos    (16U)                                                                       /*!< COMP_SPLT Postion   */ 
#define USB_HCSPLT_N_COMP_SPLT_Msk    (0x1U << USB_HCSPLT_N_COMP_SPLT_Pos)                                        /*!< COMP_SPLT Mask      */
#define USB_HCSPLT_N_COMP_SPLT_Set(x) (((uint32_t) (x) << USB_HCSPLT_N_COMP_SPLT_Pos) & USB_HCSPLT_N_COMP_SPLT_Msk) /*!< COMP_SPLT Set Value */
#define USB_HCSPLT_N_COMP_SPLT_Get(x) (((uint32_t) (x) & USB_HCSPLT_N_COMP_SPLT_Msk) >> USB_HCSPLT_N_COMP_SPLT_Pos) /*!< COMP_SPLT Get Value */


#define USB_HCSPLT_N_XACT_POS_Pos    (14U)                                                                       /*!< XACT_POS Postion   */ 
#define USB_HCSPLT_N_XACT_POS_Msk    (0x3U << USB_HCSPLT_N_XACT_POS_Pos)                                         /*!< XACT_POS Mask      */
#define USB_HCSPLT_N_XACT_POS_Set(x) (((uint32_t) (x) << USB_HCSPLT_N_XACT_POS_Pos) & USB_HCSPLT_N_XACT_POS_Msk) /*!< XACT_POS Set Value */
#define USB_HCSPLT_N_XACT_POS_Get(x) (((uint32_t) (x) & USB_HCSPLT_N_XACT_POS_Msk) >> USB_HCSPLT_N_XACT_POS_Pos) /*!< XACT_POS Get Value */


#define USB_HCSPLT_N_HUB_ADDR_Pos    (7U)                                                                        /*!< HUB_ADDR Postion   */ 
#define USB_HCSPLT_N_HUB_ADDR_Msk    (0x7fU << USB_HCSPLT_N_HUB_ADDR_Pos)                                        /*!< HUB_ADDR Mask      */
#define USB_HCSPLT_N_HUB_ADDR_Set(x) (((uint32_t) (x) << USB_HCSPLT_N_HUB_ADDR_Pos) & USB_HCSPLT_N_HUB_ADDR_Msk) /*!< HUB_ADDR Set Value */
#define USB_HCSPLT_N_HUB_ADDR_Get(x) (((uint32_t) (x) & USB_HCSPLT_N_HUB_ADDR_Msk) >> USB_HCSPLT_N_HUB_ADDR_Pos) /*!< HUB_ADDR Get Value */


#define USB_HCSPLT_N_PRT_ADDR_Pos    (0U)                                                                        /*!< PRT_ADDR Postion   */ 
#define USB_HCSPLT_N_PRT_ADDR_Msk    (0x7fU << USB_HCSPLT_N_PRT_ADDR_Pos)                                        /*!< PRT_ADDR Mask      */
#define USB_HCSPLT_N_PRT_ADDR_Set(x) (((uint32_t) (x) << USB_HCSPLT_N_PRT_ADDR_Pos) & USB_HCSPLT_N_PRT_ADDR_Msk) /*!< PRT_ADDR Set Value */
#define USB_HCSPLT_N_PRT_ADDR_Get(x) (((uint32_t) (x) & USB_HCSPLT_N_PRT_ADDR_Msk) >> USB_HCSPLT_N_PRT_ADDR_Pos) /*!< PRT_ADDR Get Value */


/* HCINT_N bitfield */
#define USB_HCINT_N_DESC_LST_ROLLINTR_Pos    (13U)                                                                       /*!< DESC_LST_ROLLINTR Postion   */ 
#define USB_HCINT_N_DESC_LST_ROLLINTR_Msk    (0x1U << USB_HCINT_N_DESC_LST_ROLLINTR_Pos)                                 /*!< DESC_LST_ROLLINTR Mask      */
#define USB_HCINT_N_DESC_LST_ROLLINTR_Set(x) (((uint32_t) (x) << USB_HCINT_N_DESC_LST_ROLLINTR_Pos) & USB_HCINT_N_DESC_LST_ROLLINTR_Msk) /*!< DESC_LST_ROLLINTR Set Value */
#define USB_HCINT_N_DESC_LST_ROLLINTR_Get(x) (((uint32_t) (x) & USB_HCINT_N_DESC_LST_ROLLINTR_Msk) >> USB_HCINT_N_DESC_LST_ROLLINTR_Pos) /*!< DESC_LST_ROLLINTR Get Value */


#define USB_HCINT_N_XCS_XACT_ERR_Pos    (12U)                                                                       /*!< XCS_XACT_ERR Postion   */ 
#define USB_HCINT_N_XCS_XACT_ERR_Msk    (0x1U << USB_HCINT_N_XCS_XACT_ERR_Pos)                                      /*!< XCS_XACT_ERR Mask      */
#define USB_HCINT_N_XCS_XACT_ERR_Set(x) (((uint32_t) (x) << USB_HCINT_N_XCS_XACT_ERR_Pos) & USB_HCINT_N_XCS_XACT_ERR_Msk) /*!< XCS_XACT_ERR Set Value */
#define USB_HCINT_N_XCS_XACT_ERR_Get(x) (((uint32_t) (x) & USB_HCINT_N_XCS_XACT_ERR_Msk) >> USB_HCINT_N_XCS_XACT_ERR_Pos) /*!< XCS_XACT_ERR Get Value */


#define USB_HCINT_N_HCIN_T_N_BNAINTR_Pos    (11U)                                                                       /*!< HCIN_T_N_BNAINTR Postion   */ 
#define USB_HCINT_N_HCIN_T_N_BNAINTR_Msk    (0x1U << USB_HCINT_N_HCIN_T_N_BNAINTR_Pos)                                  /*!< HCIN_T_N_BNAINTR Mask      */
#define USB_HCINT_N_HCIN_T_N_BNAINTR_Set(x) (((uint32_t) (x) << USB_HCINT_N_HCIN_T_N_BNAINTR_Pos) & USB_HCINT_N_HCIN_T_N_BNAINTR_Msk) /*!< HCIN_T_N_BNAINTR Set Value */
#define USB_HCINT_N_HCIN_T_N_BNAINTR_Get(x) (((uint32_t) (x) & USB_HCINT_N_HCIN_T_N_BNAINTR_Msk) >> USB_HCINT_N_HCIN_T_N_BNAINTR_Pos) /*!< HCIN_T_N_BNAINTR Get Value */


#define USB_HCINT_N_DATA_TGL_ERR_Pos    (10U)                                                                       /*!< DATA_TGL_ERR Postion   */ 
#define USB_HCINT_N_DATA_TGL_ERR_Msk    (0x1U << USB_HCINT_N_DATA_TGL_ERR_Pos)                                      /*!< DATA_TGL_ERR Mask      */
#define USB_HCINT_N_DATA_TGL_ERR_Set(x) (((uint32_t) (x) << USB_HCINT_N_DATA_TGL_ERR_Pos) & USB_HCINT_N_DATA_TGL_ERR_Msk) /*!< DATA_TGL_ERR Set Value */
#define USB_HCINT_N_DATA_TGL_ERR_Get(x) (((uint32_t) (x) & USB_HCINT_N_DATA_TGL_ERR_Msk) >> USB_HCINT_N_DATA_TGL_ERR_Pos) /*!< DATA_TGL_ERR Get Value */


#define USB_HCINT_N_FRM_OVRUN_Pos    (9U)                                                                        /*!< FRM_OVRUN Postion   */ 
#define USB_HCINT_N_FRM_OVRUN_Msk    (0x1U << USB_HCINT_N_FRM_OVRUN_Pos)                                         /*!< FRM_OVRUN Mask      */
#define USB_HCINT_N_FRM_OVRUN_Set(x) (((uint32_t) (x) << USB_HCINT_N_FRM_OVRUN_Pos) & USB_HCINT_N_FRM_OVRUN_Msk) /*!< FRM_OVRUN Set Value */
#define USB_HCINT_N_FRM_OVRUN_Get(x) (((uint32_t) (x) & USB_HCINT_N_FRM_OVRUN_Msk) >> USB_HCINT_N_FRM_OVRUN_Pos) /*!< FRM_OVRUN Get Value */


#define USB_HCINT_N_BBL_ERR_Pos    (8U)                                                                        /*!< BBL_ERR Postion   */ 
#define USB_HCINT_N_BBL_ERR_Msk    (0x1U << USB_HCINT_N_BBL_ERR_Pos)                                           /*!< BBL_ERR Mask      */
#define USB_HCINT_N_BBL_ERR_Set(x) (((uint32_t) (x) << USB_HCINT_N_BBL_ERR_Pos) & USB_HCINT_N_BBL_ERR_Msk)     /*!< BBL_ERR Set Value */
#define USB_HCINT_N_BBL_ERR_Get(x) (((uint32_t) (x) & USB_HCINT_N_BBL_ERR_Msk) >> USB_HCINT_N_BBL_ERR_Pos)     /*!< BBL_ERR Get Value */


#define USB_HCINT_N_XACT_ERR_Pos    (7U)                                                                        /*!< XACT_ERR Postion   */ 
#define USB_HCINT_N_XACT_ERR_Msk    (0x1U << USB_HCINT_N_XACT_ERR_Pos)                                          /*!< XACT_ERR Mask      */
#define USB_HCINT_N_XACT_ERR_Set(x) (((uint32_t) (x) << USB_HCINT_N_XACT_ERR_Pos) & USB_HCINT_N_XACT_ERR_Msk)   /*!< XACT_ERR Set Value */
#define USB_HCINT_N_XACT_ERR_Get(x) (((uint32_t) (x) & USB_HCINT_N_XACT_ERR_Msk) >> USB_HCINT_N_XACT_ERR_Pos)   /*!< XACT_ERR Get Value */


#define USB_HCINT_N_NYET_Pos    (6U)                                                                        /*!< NYET Postion   */ 
#define USB_HCINT_N_NYET_Msk    (0x1U << USB_HCINT_N_NYET_Pos)                                              /*!< NYET Mask      */
#define USB_HCINT_N_NYET_Set(x) (((uint32_t) (x) << USB_HCINT_N_NYET_Pos) & USB_HCINT_N_NYET_Msk)           /*!< NYET Set Value */
#define USB_HCINT_N_NYET_Get(x) (((uint32_t) (x) & USB_HCINT_N_NYET_Msk) >> USB_HCINT_N_NYET_Pos)           /*!< NYET Get Value */


#define USB_HCINT_N_ACK_Pos    (5U)                                                                        /*!< ACK Postion   */ 
#define USB_HCINT_N_ACK_Msk    (0x1U << USB_HCINT_N_ACK_Pos)                                               /*!< ACK Mask      */
#define USB_HCINT_N_ACK_Set(x) (((uint32_t) (x) << USB_HCINT_N_ACK_Pos) & USB_HCINT_N_ACK_Msk)             /*!< ACK Set Value */
#define USB_HCINT_N_ACK_Get(x) (((uint32_t) (x) & USB_HCINT_N_ACK_Msk) >> USB_HCINT_N_ACK_Pos)             /*!< ACK Get Value */


#define USB_HCINT_N_NAK_Pos    (4U)                                                                        /*!< NAK Postion   */ 
#define USB_HCINT_N_NAK_Msk    (0x1U << USB_HCINT_N_NAK_Pos)                                               /*!< NAK Mask      */
#define USB_HCINT_N_NAK_Set(x) (((uint32_t) (x) << USB_HCINT_N_NAK_Pos) & USB_HCINT_N_NAK_Msk)             /*!< NAK Set Value */
#define USB_HCINT_N_NAK_Get(x) (((uint32_t) (x) & USB_HCINT_N_NAK_Msk) >> USB_HCINT_N_NAK_Pos)             /*!< NAK Get Value */


#define USB_HCINT_N_STALL_Pos    (3U)                                                                        /*!< STALL Postion   */ 
#define USB_HCINT_N_STALL_Msk    (0x1U << USB_HCINT_N_STALL_Pos)                                             /*!< STALL Mask      */
#define USB_HCINT_N_STALL_Set(x) (((uint32_t) (x) << USB_HCINT_N_STALL_Pos) & USB_HCINT_N_STALL_Msk)         /*!< STALL Set Value */
#define USB_HCINT_N_STALL_Get(x) (((uint32_t) (x) & USB_HCINT_N_STALL_Msk) >> USB_HCINT_N_STALL_Pos)         /*!< STALL Get Value */


#define USB_HCINT_N_HCIN_T_N_AHB_ERR_Pos    (2U)                                                                        /*!< HCIN_T_N_AHB_ERR Postion   */ 
#define USB_HCINT_N_HCIN_T_N_AHB_ERR_Msk    (0x1U << USB_HCINT_N_HCIN_T_N_AHB_ERR_Pos)                                  /*!< HCIN_T_N_AHB_ERR Mask      */
#define USB_HCINT_N_HCIN_T_N_AHB_ERR_Set(x) (((uint32_t) (x) << USB_HCINT_N_HCIN_T_N_AHB_ERR_Pos) & USB_HCINT_N_HCIN_T_N_AHB_ERR_Msk) /*!< HCIN_T_N_AHB_ERR Set Value */
#define USB_HCINT_N_HCIN_T_N_AHB_ERR_Get(x) (((uint32_t) (x) & USB_HCINT_N_HCIN_T_N_AHB_ERR_Msk) >> USB_HCINT_N_HCIN_T_N_AHB_ERR_Pos) /*!< HCIN_T_N_AHB_ERR Get Value */


#define USB_HCINT_N_CH_HLTD_Pos    (1U)                                                                        /*!< CH_HLTD Postion   */ 
#define USB_HCINT_N_CH_HLTD_Msk    (0x1U << USB_HCINT_N_CH_HLTD_Pos)                                           /*!< CH_HLTD Mask      */
#define USB_HCINT_N_CH_HLTD_Set(x) (((uint32_t) (x) << USB_HCINT_N_CH_HLTD_Pos) & USB_HCINT_N_CH_HLTD_Msk)     /*!< CH_HLTD Set Value */
#define USB_HCINT_N_CH_HLTD_Get(x) (((uint32_t) (x) & USB_HCINT_N_CH_HLTD_Msk) >> USB_HCINT_N_CH_HLTD_Pos)     /*!< CH_HLTD Get Value */


#define USB_HCINT_N_HCIN_T_N_XFER_COMPL_Pos    (0U)                                                                        /*!< HCIN_T_N_XFER_COMPL Postion   */ 
#define USB_HCINT_N_HCIN_T_N_XFER_COMPL_Msk    (0x1U << USB_HCINT_N_HCIN_T_N_XFER_COMPL_Pos)                               /*!< HCIN_T_N_XFER_COMPL Mask      */
#define USB_HCINT_N_HCIN_T_N_XFER_COMPL_Set(x) (((uint32_t) (x) << USB_HCINT_N_HCIN_T_N_XFER_COMPL_Pos) & USB_HCINT_N_HCIN_T_N_XFER_COMPL_Msk) /*!< HCIN_T_N_XFER_COMPL Set Value */
#define USB_HCINT_N_HCIN_T_N_XFER_COMPL_Get(x) (((uint32_t) (x) & USB_HCINT_N_HCIN_T_N_XFER_COMPL_Msk) >> USB_HCINT_N_HCIN_T_N_XFER_COMPL_Pos) /*!< HCIN_T_N_XFER_COMPL Get Value */


/* HCINTMSK_N bitfield */
#define USB_HCINTMSK_N_DESC_LST_ROLLINTR_MSK_Pos    (13U)                                                                       /*!< DESC_LST_ROLLINTR_MSK Postion   */ 
#define USB_HCINTMSK_N_DESC_LST_ROLLINTR_MSK_Msk    (0x1U << USB_HCINTMSK_N_DESC_LST_ROLLINTR_MSK_Pos)                          /*!< DESC_LST_ROLLINTR_MSK Mask      */
#define USB_HCINTMSK_N_DESC_LST_ROLLINTR_MSK_Set(x) (((uint32_t) (x) << USB_HCINTMSK_N_DESC_LST_ROLLINTR_MSK_Pos) & USB_HCINTMSK_N_DESC_LST_ROLLINTR_MSK_Msk) /*!< DESC_LST_ROLLINTR_MSK Set Value */
#define USB_HCINTMSK_N_DESC_LST_ROLLINTR_MSK_Get(x) (((uint32_t) (x) & USB_HCINTMSK_N_DESC_LST_ROLLINTR_MSK_Msk) >> USB_HCINTMSK_N_DESC_LST_ROLLINTR_MSK_Pos) /*!< DESC_LST_ROLLINTR_MSK Get Value */

#define USB_HCINTMSK_N_BNAINTR_MSK_Pos    (11U)                                                                       /*!< BNAINTR_MSK Postion   */ 
#define USB_HCINTMSK_N_BNAINTR_MSK_Msk    (0x1U << USB_HCINTMSK_N_BNAINTR_MSK_Pos)                                    /*!< BNAINTR_MSK Mask      */
#define USB_HCINTMSK_N_BNAINTR_MSK_Set(x) (((uint32_t) (x) << USB_HCINTMSK_N_BNAINTR_MSK_Pos) & USB_HCINTMSK_N_BNAINTR_MSK_Msk) /*!< BNAINTR_MSK Set Value */
#define USB_HCINTMSK_N_BNAINTR_MSK_Get(x) (((uint32_t) (x) & USB_HCINTMSK_N_BNAINTR_MSK_Msk) >> USB_HCINTMSK_N_BNAINTR_MSK_Pos) /*!< BNAINTR_MSK Get Value */

#define USB_HCINTMSK_N_DTERRM_Pos              (10U)
#define USB_HCINTMSK_N_DTERRM_Msk              (0x1UL << USB_HCINTMSK_N_DTERRM_Pos) /*!< 0x00000400 */
#define USB_HCINTMSK_N_DTERRM                  USB_HCINTMSK_N_DTERRM_Msk   /*!< Data toggle error mask */
#define USB_HCINTMSK_N_DTERRM_Set(x) (((uint32_t) (x) << USB_HCINTMSK_N_DTERRM_Pos) & USB_HCINTMSK_N_DTERRM_Msk) 
#define USB_HCINTMSK_N_DTERRM_Get(x) (((uint32_t) (x) & USB_HCINTMSK_N_DTERRM_Msk) >> USB_HCINTMSK_N_DTERRM_Pos) 


#define USB_HCINTMSK_N_FRMORM_Pos              (9U)
#define USB_HCINTMSK_N_FRMORM_Msk              (0x1UL << USB_HCINTMSK_N_FRMORM_Pos) /*!< 0x00000200 */
#define USB_HCINTMSK_N_FRMORM                  USB_HCINTMSK_N_FRMORM_Msk   /*!< Frame overrun mask */
#define USB_HCINTMSK_N_FRMORM_Set(x) (((uint32_t) (x) << USB_HCINTMSK_N_FRMORM_Pos) & USB_HCINTMSK_N_FRMORM_Msk) 
#define USB_HCINTMSK_N_FRMORM_Get(x) (((uint32_t) (x) & USB_HCINTMSK_N_FRMORM_Msk) >> USB_HCINTMSK_N_FRMORM_Pos) 

#define USB_HCINTMSK_N_BBERRM_Pos              (8U)
#define USB_HCINTMSK_N_BBERRM_Msk              (0x1UL << USB_HCINTMSK_N_BBERRM_Pos) /*!< 0x00000100 */
#define USB_HCINTMSK_N_BBERRM                  USB_HCINTMSK_N_BBERRM_Msk   /*!< Babble error mask */
#define USB_HCINTMSK_N_BBERRM_Set(x) (((uint32_t) (x) << USB_HCINTMSK_N_BBERRM_Pos) & USB_HCINTMSK_N_BBERRM_Msk) 
#define USB_HCINTMSK_N_BBERRM_Get(x) (((uint32_t) (x) & USB_HCINTMSK_N_BBERRM_Msk) >> USB_HCINTMSK_N_BBERRM_Pos) 

#define USB_HCINTMSK_N_TXERRM_Pos              (7U)
#define USB_HCINTMSK_N_TXERRM_Msk              (0x1UL << USB_HCINTMSK_N_TXERRM_Pos) /*!< 0x00000080 */
#define USB_HCINTMSK_N_TXERRM                  USB_HCINTMSK_N_TXERRM_Msk   /*!< Transaction error mask */
#define USB_HCINTMSK_N_TXERRM_Set(x) (((uint32_t) (x) << USB_HCINTMSK_N_TXERRM_Pos) & USB_HCINTMSK_N_TXERRM_Msk) 
#define USB_HCINTMSK_N_TXERRM_Get(x) (((uint32_t) (x) & USB_HCINTMSK_N_TXERRM_Msk) >> USB_HCINTMSK_N_TXERRM_Pos) 


#define USB_HCINTMSK_N_NYET_Pos                (6U)
#define USB_HCINTMSK_N_NYET_Msk                (0x1UL << USB_HCINTMSK_N_NYET_Pos) /*!< 0x00000040 */
#define USB_HCINTMSK_N_NYET                    USB_HCINTMSK_N_NYET_Msk     /*!< response received interrupt mask */
#define USB_HCINTMSK_N_NYET_Set(x) (((uint32_t) (x) << USB_HCINTMSK_N_NYET_Pos) & USB_HCINTMSK_N_NYET_Msk) 
#define USB_HCINTMSK_N_NYET_Get(x) (((uint32_t) (x) & USB_HCINTMSK_N_NYET_Msk) >> USB_HCINTMSK_N_NYET_Pos) 


#define USB_HCINTMSK_N_ACKM_Pos                (5U)
#define USB_HCINTMSK_N_ACKM_Msk                (0x1UL << USB_HCINTMSK_N_ACKM_Pos) /*!< 0x00000020 */
#define USB_HCINTMSK_N_ACKM                    USB_HCINTMSK_N_ACKM_Msk     /*!< ACK response received/transmitted interrupt mask */
#define USB_HCINTMSK_N_ACKM_Set(x) (((uint32_t) (x) << USB_HCINTMSK_N_ACKM_Pos) & USB_HCINTMSK_N_ACKM_Msk) 
#define USB_HCINTMSK_N_ACKM_Get(x) (((uint32_t) (x) & USB_HCINTMSK_N_ACKM_Msk) >> USB_HCINTMSK_N_ACKM_Pos) 

#define USB_HCINTMSK_N_NAKM_Pos                (4U)
#define USB_HCINTMSK_N_NAKM_Msk                (0x1UL << USB_HCINTMSK_N_NAKM_Pos) /*!< 0x00000010 */
#define USB_HCINTMSK_N_NAKM                    USB_HCINTMSK_N_NAKM_Msk     /*!< NAK response received interrupt mask */
#define USB_HCINTMSK_N_NAKM_Set(x) (((uint32_t) (x) << USB_HCINTMSK_N_NAKM_Pos) & USB_HCINTMSK_N_NAKM_Msk) 
#define USB_HCINTMSK_N_NAKM_Get(x) (((uint32_t) (x) & USB_HCINTMSK_N_NAKM_Msk) >> USB_HCINTMSK_N_NAKM_Pos) 

#define USB_HCINTMSK_N_STALLM_Pos              (3U)
#define USB_HCINTMSK_N_STALLM_Msk              (0x1UL << USB_HCINTMSK_N_STALLM_Pos) /*!< 0x00000008 */
#define USB_HCINTMSK_N_STALLM                  USB_HCINTMSK_N_STALLM_Msk   /*!< STALL response received interrupt mask */
#define USB_HCINTMSK_N_STALLM_Set(x) (((uint32_t) (x) << USB_HCINTMSK_N_STALLM_Pos) & USB_HCINTMSK_N_STALLM_Msk) 
#define USB_HCINTMSK_N_STALLM_Get(x) (((uint32_t) (x) & USB_HCINTMSK_N_STALLM_Msk) >> USB_HCINTMSK_N_STALLM_Pos) 

#define USB_HCINTMSK_N_HCIN_TMSK_N_AHB_ERR_MSK_Pos    (2U)                                                                        /*!< HCIN_TMSK_N_AHB_ERR_MSK Postion   */ 
#define USB_HCINTMSK_N_HCIN_TMSK_N_AHB_ERR_MSK_Msk    (0x1U << USB_HCINTMSK_N_HCIN_TMSK_N_AHB_ERR_MSK_Pos)                        /*!< HCIN_TMSK_N_AHB_ERR_MSK Mask      */
#define USB_HCINTMSK_N_HCIN_TMSK_N_AHB_ERR_MSK_Set(x) (((uint32_t) (x) << USB_HCINTMSK_N_HCIN_TMSK_N_AHB_ERR_MSK_Pos) & USB_HCINTMSK_N_HCIN_TMSK_N_AHB_ERR_MSK_Msk) /*!< HCIN_TMSK_N_AHB_ERR_MSK Set Value */
#define USB_HCINTMSK_N_HCIN_TMSK_N_AHB_ERR_MSK_Get(x) (((uint32_t) (x) & USB_HCINTMSK_N_HCIN_TMSK_N_AHB_ERR_MSK_Msk) >> USB_HCINTMSK_N_HCIN_TMSK_N_AHB_ERR_MSK_Pos) /*!< HCIN_TMSK_N_AHB_ERR_MSK Get Value */


#define USB_HCINTMSK_N_CH_HLTD_MSK_Pos    (1U)                                                                        /*!< CH_HLTD_MSK Postion   */ 
#define USB_HCINTMSK_N_CH_HLTD_MSK_Msk    (0x1U << USB_HCINTMSK_N_CH_HLTD_MSK_Pos)                                    /*!< CH_HLTD_MSK Mask      */
#define USB_HCINTMSK_N_CH_HLTD_MSK_Set(x) (((uint32_t) (x) << USB_HCINTMSK_N_CH_HLTD_MSK_Pos) & USB_HCINTMSK_N_CH_HLTD_MSK_Msk) /*!< CH_HLTD_MSK Set Value */
#define USB_HCINTMSK_N_CH_HLTD_MSK_Get(x) (((uint32_t) (x) & USB_HCINTMSK_N_CH_HLTD_MSK_Msk) >> USB_HCINTMSK_N_CH_HLTD_MSK_Pos) /*!< CH_HLTD_MSK Get Value */


#define USB_HCINTMSK_N_HCIN_TMSK_N_XFER_COMPL_MSK_Pos    (0U)                                                                        /*!< HCIN_TMSK_N_XFER_COMPL_MSK Postion   */ 
#define USB_HCINTMSK_N_HCIN_TMSK_N_XFER_COMPL_MSK_Msk    (0x1U << USB_HCINTMSK_N_HCIN_TMSK_N_XFER_COMPL_MSK_Pos)                     /*!< HCIN_TMSK_N_XFER_COMPL_MSK Mask      */
#define USB_HCINTMSK_N_HCIN_TMSK_N_XFER_COMPL_MSK_Set(x) (((uint32_t) (x) << USB_HCINTMSK_N_HCIN_TMSK_N_XFER_COMPL_MSK_Pos) & USB_HCINTMSK_N_HCIN_TMSK_N_XFER_COMPL_MSK_Msk) /*!< HCIN_TMSK_N_XFER_COMPL_MSK Set Value */
#define USB_HCINTMSK_N_HCIN_TMSK_N_XFER_COMPL_MSK_Get(x) (((uint32_t) (x) & USB_HCINTMSK_N_HCIN_TMSK_N_XFER_COMPL_MSK_Msk) >> USB_HCINTMSK_N_HCIN_TMSK_N_XFER_COMPL_MSK_Pos) /*!< HCIN_TMSK_N_XFER_COMPL_MSK Get Value */


/* HCTSIZ_N bitfield */
#define USB_HCTSIZ_N_DO_PNG_Pos    (31U)                                                                       /*!< DO_PNG Postion   */ 
#define USB_HCTSIZ_N_DO_PNG_Msk    (0x1U << USB_HCTSIZ_N_DO_PNG_Pos)                                           /*!< DO_PNG Mask      */
#define USB_HCTSIZ_N_DO_PNG_Set(x) (((uint32_t) (x) << USB_HCTSIZ_N_DO_PNG_Pos) & USB_HCTSIZ_N_DO_PNG_Msk)     /*!< DO_PNG Set Value */
#define USB_HCTSIZ_N_DO_PNG_Get(x) (((uint32_t) (x) & USB_HCTSIZ_N_DO_PNG_Msk) >> USB_HCTSIZ_N_DO_PNG_Pos)     /*!< DO_PNG Get Value */


#define USB_HCTSIZ_N_PID_Pos    (29U)                                                                       /*!< PID Postion   */ 
#define USB_HCTSIZ_N_PID_Msk    (0x3U << USB_HCTSIZ_N_PID_Pos)                                              /*!< PID Mask      */
#define USB_HCTSIZ_N_PID_Set(x) (((uint32_t) (x) << USB_HCTSIZ_N_PID_Pos) & USB_HCTSIZ_N_PID_Msk)           /*!< PID Set Value */
#define USB_HCTSIZ_N_PID_Get(x) (((uint32_t) (x) & USB_HCTSIZ_N_PID_Msk) >> USB_HCTSIZ_N_PID_Pos)           /*!< PID Get Value */


#define USB_HCTSIZ_N_HCTSIZ_N_PKT_CNT_Pos    (19U)                                                                       /*!< HCTSIZ_N_PKT_CNT Postion   */ 
#define USB_HCTSIZ_N_HCTSIZ_N_PKT_CNT_Msk    (0x3ffU << USB_HCTSIZ_N_HCTSIZ_N_PKT_CNT_Pos)                               /*!< HCTSIZ_N_PKT_CNT Mask      */
#define USB_HCTSIZ_N_HCTSIZ_N_PKT_CNT_Set(x) (((uint32_t) (x) << USB_HCTSIZ_N_HCTSIZ_N_PKT_CNT_Pos) & USB_HCTSIZ_N_HCTSIZ_N_PKT_CNT_Msk) /*!< HCTSIZ_N_PKT_CNT Set Value */
#define USB_HCTSIZ_N_HCTSIZ_N_PKT_CNT_Get(x) (((uint32_t) (x) & USB_HCTSIZ_N_HCTSIZ_N_PKT_CNT_Msk) >> USB_HCTSIZ_N_HCTSIZ_N_PKT_CNT_Pos) /*!< HCTSIZ_N_PKT_CNT Get Value */


#define USB_HCTSIZ_N_HCTSIZ_N_XFER_SIZE_Pos    (0U)                                                                        /*!< HCTSIZ_N_XFER_SIZE Postion   */ 
#define USB_HCTSIZ_N_HCTSIZ_N_XFER_SIZE_Msk    (0x7ffffU << USB_HCTSIZ_N_HCTSIZ_N_XFER_SIZE_Pos)                           /*!< HCTSIZ_N_XFER_SIZE Mask      */
#define USB_HCTSIZ_N_HCTSIZ_N_XFER_SIZE_Set(x) (((uint32_t) (x) << USB_HCTSIZ_N_HCTSIZ_N_XFER_SIZE_Pos) & USB_HCTSIZ_N_HCTSIZ_N_XFER_SIZE_Msk) /*!< HCTSIZ_N_XFER_SIZE Set Value */
#define USB_HCTSIZ_N_HCTSIZ_N_XFER_SIZE_Get(x) (((uint32_t) (x) & USB_HCTSIZ_N_HCTSIZ_N_XFER_SIZE_Msk) >> USB_HCTSIZ_N_HCTSIZ_N_XFER_SIZE_Pos) /*!< HCTSIZ_N_XFER_SIZE Get Value */


/* HCDMA_N bitfield */
#define USB_HCDMA_N_HCDMA_N_DMA_ADDR_Pos    (0U)                                                                        /*!< HCDMA_N_DMA_ADDR Postion   */ 
#define USB_HCDMA_N_HCDMA_N_DMA_ADDR_Msk    (0xffffffffU << USB_HCDMA_N_HCDMA_N_DMA_ADDR_Pos)                           /*!< HCDMA_N_DMA_ADDR Mask      */
#define USB_HCDMA_N_HCDMA_N_DMA_ADDR_Set(x) (((uint32_t) (x) << USB_HCDMA_N_HCDMA_N_DMA_ADDR_Pos) & USB_HCDMA_N_HCDMA_N_DMA_ADDR_Msk) /*!< HCDMA_N_DMA_ADDR Set Value */
#define USB_HCDMA_N_HCDMA_N_DMA_ADDR_Get(x) (((uint32_t) (x) & USB_HCDMA_N_HCDMA_N_DMA_ADDR_Msk) >> USB_HCDMA_N_HCDMA_N_DMA_ADDR_Pos) /*!< HCDMA_N_DMA_ADDR Get Value */


/* HCDMAB_N bitfield */
#define USB_HCDMAB_N_HCDMA_B_Pos    (0U)                                                                        /*!< HCDMA_B Postion   */ 
#define USB_HCDMAB_N_HCDMA_B_Msk    (0xffffffffU << USB_HCDMAB_N_HCDMA_B_Pos)                                   /*!< HCDMA_B Mask      */
#define USB_HCDMAB_N_HCDMA_B_Set(x) (((uint32_t) (x) << USB_HCDMAB_N_HCDMA_B_Pos) & USB_HCDMAB_N_HCDMA_B_Msk)   /*!< HCDMA_B Set Value */
#define USB_HCDMAB_N_HCDMA_B_Get(x) (((uint32_t) (x) & USB_HCDMAB_N_HCDMA_B_Msk) >> USB_HCDMAB_N_HCDMA_B_Pos)   /*!< HCDMA_B Get Value */


/* DIEPEACHMSK_N bitfield */
#define USB_DIEPEACHMSK_N_DIEP_EACHMSK_N_NAKMSK_Pos    (13U)                                                                       /*!< DIEP_EACHMSK_N_NAKMSK Postion   */ 
#define USB_DIEPEACHMSK_N_DIEP_EACHMSK_N_NAKMSK_Msk    (0x1U << USB_DIEPEACHMSK_N_DIEP_EACHMSK_N_NAKMSK_Pos)                       /*!< DIEP_EACHMSK_N_NAKMSK Mask      */
#define USB_DIEPEACHMSK_N_DIEP_EACHMSK_N_NAKMSK_Set(x) (((uint32_t) (x) << USB_DIEPEACHMSK_N_DIEP_EACHMSK_N_NAKMSK_Pos) & USB_DIEPEACHMSK_N_DIEP_EACHMSK_N_NAKMSK_Msk) /*!< DIEP_EACHMSK_N_NAKMSK Set Value */
#define USB_DIEPEACHMSK_N_DIEP_EACHMSK_N_NAKMSK_Get(x) (((uint32_t) (x) & USB_DIEPEACHMSK_N_DIEP_EACHMSK_N_NAKMSK_Msk) >> USB_DIEPEACHMSK_N_DIEP_EACHMSK_N_NAKMSK_Pos) /*!< DIEP_EACHMSK_N_NAKMSK Get Value */


#define USB_DIEPEACHMSK_N_DIEP_EACHMSK_N_BNAIN_INTR_MSK_Pos    (9U)                                                                        /*!< DIEP_EACHMSK_N_BNAIN_INTR_MSK Postion   */ 
#define USB_DIEPEACHMSK_N_DIEP_EACHMSK_N_BNAIN_INTR_MSK_Msk    (0x1U << USB_DIEPEACHMSK_N_DIEP_EACHMSK_N_BNAIN_INTR_MSK_Pos)               /*!< DIEP_EACHMSK_N_BNAIN_INTR_MSK Mask      */
#define USB_DIEPEACHMSK_N_DIEP_EACHMSK_N_BNAIN_INTR_MSK_Set(x) (((uint32_t) (x) << USB_DIEPEACHMSK_N_DIEP_EACHMSK_N_BNAIN_INTR_MSK_Pos) & USB_DIEPEACHMSK_N_DIEP_EACHMSK_N_BNAIN_INTR_MSK_Msk) /*!< DIEP_EACHMSK_N_BNAIN_INTR_MSK Set Value */
#define USB_DIEPEACHMSK_N_DIEP_EACHMSK_N_BNAIN_INTR_MSK_Get(x) (((uint32_t) (x) & USB_DIEPEACHMSK_N_DIEP_EACHMSK_N_BNAIN_INTR_MSK_Msk) >> USB_DIEPEACHMSK_N_DIEP_EACHMSK_N_BNAIN_INTR_MSK_Pos) /*!< DIEP_EACHMSK_N_BNAIN_INTR_MSK Get Value */


#define USB_DIEPEACHMSK_N_DIEP_EACHMSK_N_TXFIFO_UNDRN_MSK_Pos    (8U)                                                                        /*!< DIEP_EACHMSK_N_TXFIFO_UNDRN_MSK Postion   */ 
#define USB_DIEPEACHMSK_N_DIEP_EACHMSK_N_TXFIFO_UNDRN_MSK_Msk    (0x1U << USB_DIEPEACHMSK_N_DIEP_EACHMSK_N_TXFIFO_UNDRN_MSK_Pos)             /*!< DIEP_EACHMSK_N_TXFIFO_UNDRN_MSK Mask      */
#define USB_DIEPEACHMSK_N_DIEP_EACHMSK_N_TXFIFO_UNDRN_MSK_Set(x) (((uint32_t) (x) << USB_DIEPEACHMSK_N_DIEP_EACHMSK_N_TXFIFO_UNDRN_MSK_Pos) & USB_DIEPEACHMSK_N_DIEP_EACHMSK_N_TXFIFO_UNDRN_MSK_Msk) /*!< DIEP_EACHMSK_N_TXFIFO_UNDRN_MSK Set Value */
#define USB_DIEPEACHMSK_N_DIEP_EACHMSK_N_TXFIFO_UNDRN_MSK_Get(x) (((uint32_t) (x) & USB_DIEPEACHMSK_N_DIEP_EACHMSK_N_TXFIFO_UNDRN_MSK_Msk) >> USB_DIEPEACHMSK_N_DIEP_EACHMSK_N_TXFIFO_UNDRN_MSK_Pos) /*!< DIEP_EACHMSK_N_TXFIFO_UNDRN_MSK Get Value */


#define USB_DIEPEACHMSK_N_DIEP_EACHMSK_N_IN_EP_NAK_EFF_MSK_Pos    (6U)                                                                        /*!< DIEP_EACHMSK_N_IN_EP_NAK_EFF_MSK Postion   */ 
#define USB_DIEPEACHMSK_N_DIEP_EACHMSK_N_IN_EP_NAK_EFF_MSK_Msk    (0x1U << USB_DIEPEACHMSK_N_DIEP_EACHMSK_N_IN_EP_NAK_EFF_MSK_Pos)            /*!< DIEP_EACHMSK_N_IN_EP_NAK_EFF_MSK Mask      */
#define USB_DIEPEACHMSK_N_DIEP_EACHMSK_N_IN_EP_NAK_EFF_MSK_Set(x) (((uint32_t) (x) << USB_DIEPEACHMSK_N_DIEP_EACHMSK_N_IN_EP_NAK_EFF_MSK_Pos) & USB_DIEPEACHMSK_N_DIEP_EACHMSK_N_IN_EP_NAK_EFF_MSK_Msk) /*!< DIEP_EACHMSK_N_IN_EP_NAK_EFF_MSK Set Value */
#define USB_DIEPEACHMSK_N_DIEP_EACHMSK_N_IN_EP_NAK_EFF_MSK_Get(x) (((uint32_t) (x) & USB_DIEPEACHMSK_N_DIEP_EACHMSK_N_IN_EP_NAK_EFF_MSK_Msk) >> USB_DIEPEACHMSK_N_DIEP_EACHMSK_N_IN_EP_NAK_EFF_MSK_Pos) /*!< DIEP_EACHMSK_N_IN_EP_NAK_EFF_MSK Get Value */


#define USB_DIEPEACHMSK_N_DIEP_EACHMSK_N_IN_TKN_EP_MIS_MSK_Pos    (5U)                                                                        /*!< DIEP_EACHMSK_N_IN_TKN_EP_MIS_MSK Postion   */ 
#define USB_DIEPEACHMSK_N_DIEP_EACHMSK_N_IN_TKN_EP_MIS_MSK_Msk    (0x1U << USB_DIEPEACHMSK_N_DIEP_EACHMSK_N_IN_TKN_EP_MIS_MSK_Pos)            /*!< DIEP_EACHMSK_N_IN_TKN_EP_MIS_MSK Mask      */
#define USB_DIEPEACHMSK_N_DIEP_EACHMSK_N_IN_TKN_EP_MIS_MSK_Set(x) (((uint32_t) (x) << USB_DIEPEACHMSK_N_DIEP_EACHMSK_N_IN_TKN_EP_MIS_MSK_Pos) & USB_DIEPEACHMSK_N_DIEP_EACHMSK_N_IN_TKN_EP_MIS_MSK_Msk) /*!< DIEP_EACHMSK_N_IN_TKN_EP_MIS_MSK Set Value */
#define USB_DIEPEACHMSK_N_DIEP_EACHMSK_N_IN_TKN_EP_MIS_MSK_Get(x) (((uint32_t) (x) & USB_DIEPEACHMSK_N_DIEP_EACHMSK_N_IN_TKN_EP_MIS_MSK_Msk) >> USB_DIEPEACHMSK_N_DIEP_EACHMSK_N_IN_TKN_EP_MIS_MSK_Pos) /*!< DIEP_EACHMSK_N_IN_TKN_EP_MIS_MSK Get Value */


#define USB_DIEPEACHMSK_N_DIEP_EACHMSK_N_IN_TKN_TXFEMP_MSK_Pos    (4U)                                                                        /*!< DIEP_EACHMSK_N_IN_TKN_TXFEMP_MSK Postion   */ 
#define USB_DIEPEACHMSK_N_DIEP_EACHMSK_N_IN_TKN_TXFEMP_MSK_Msk    (0x1U << USB_DIEPEACHMSK_N_DIEP_EACHMSK_N_IN_TKN_TXFEMP_MSK_Pos)            /*!< DIEP_EACHMSK_N_IN_TKN_TXFEMP_MSK Mask      */
#define USB_DIEPEACHMSK_N_DIEP_EACHMSK_N_IN_TKN_TXFEMP_MSK_Set(x) (((uint32_t) (x) << USB_DIEPEACHMSK_N_DIEP_EACHMSK_N_IN_TKN_TXFEMP_MSK_Pos) & USB_DIEPEACHMSK_N_DIEP_EACHMSK_N_IN_TKN_TXFEMP_MSK_Msk) /*!< DIEP_EACHMSK_N_IN_TKN_TXFEMP_MSK Set Value */
#define USB_DIEPEACHMSK_N_DIEP_EACHMSK_N_IN_TKN_TXFEMP_MSK_Get(x) (((uint32_t) (x) & USB_DIEPEACHMSK_N_DIEP_EACHMSK_N_IN_TKN_TXFEMP_MSK_Msk) >> USB_DIEPEACHMSK_N_DIEP_EACHMSK_N_IN_TKN_TXFEMP_MSK_Pos) /*!< DIEP_EACHMSK_N_IN_TKN_TXFEMP_MSK Get Value */


#define USB_DIEPEACHMSK_N_DIEP_EACHMSK_N_TIME_OUT_MSK_Pos    (3U)                                                                        /*!< DIEP_EACHMSK_N_TIME_OUT_MSK Postion   */ 
#define USB_DIEPEACHMSK_N_DIEP_EACHMSK_N_TIME_OUT_MSK_Msk    (0x1U << USB_DIEPEACHMSK_N_DIEP_EACHMSK_N_TIME_OUT_MSK_Pos)                 /*!< DIEP_EACHMSK_N_TIME_OUT_MSK Mask      */
#define USB_DIEPEACHMSK_N_DIEP_EACHMSK_N_TIME_OUT_MSK_Set(x) (((uint32_t) (x) << USB_DIEPEACHMSK_N_DIEP_EACHMSK_N_TIME_OUT_MSK_Pos) & USB_DIEPEACHMSK_N_DIEP_EACHMSK_N_TIME_OUT_MSK_Msk) /*!< DIEP_EACHMSK_N_TIME_OUT_MSK Set Value */
#define USB_DIEPEACHMSK_N_DIEP_EACHMSK_N_TIME_OUT_MSK_Get(x) (((uint32_t) (x) & USB_DIEPEACHMSK_N_DIEP_EACHMSK_N_TIME_OUT_MSK_Msk) >> USB_DIEPEACHMSK_N_DIEP_EACHMSK_N_TIME_OUT_MSK_Pos) /*!< DIEP_EACHMSK_N_TIME_OUT_MSK Get Value */


#define USB_DIEPEACHMSK_N_DIEP_EACHMSK_N_AHB_ERR_MSK_Pos    (2U)                                                                        /*!< DIEP_EACHMSK_N_AHB_ERR_MSK Postion   */ 
#define USB_DIEPEACHMSK_N_DIEP_EACHMSK_N_AHB_ERR_MSK_Msk    (0x1U << USB_DIEPEACHMSK_N_DIEP_EACHMSK_N_AHB_ERR_MSK_Pos)                  /*!< DIEP_EACHMSK_N_AHB_ERR_MSK Mask      */
#define USB_DIEPEACHMSK_N_DIEP_EACHMSK_N_AHB_ERR_MSK_Set(x) (((uint32_t) (x) << USB_DIEPEACHMSK_N_DIEP_EACHMSK_N_AHB_ERR_MSK_Pos) & USB_DIEPEACHMSK_N_DIEP_EACHMSK_N_AHB_ERR_MSK_Msk) /*!< DIEP_EACHMSK_N_AHB_ERR_MSK Set Value */
#define USB_DIEPEACHMSK_N_DIEP_EACHMSK_N_AHB_ERR_MSK_Get(x) (((uint32_t) (x) & USB_DIEPEACHMSK_N_DIEP_EACHMSK_N_AHB_ERR_MSK_Msk) >> USB_DIEPEACHMSK_N_DIEP_EACHMSK_N_AHB_ERR_MSK_Pos) /*!< DIEP_EACHMSK_N_AHB_ERR_MSK Get Value */


#define USB_DIEPEACHMSK_N_DIEP_EACHMSK_N_EP_DISBLD_MSK_Pos    (1U)                                                                        /*!< DIEP_EACHMSK_N_EP_DISBLD_MSK Postion   */ 
#define USB_DIEPEACHMSK_N_DIEP_EACHMSK_N_EP_DISBLD_MSK_Msk    (0x1U << USB_DIEPEACHMSK_N_DIEP_EACHMSK_N_EP_DISBLD_MSK_Pos)                /*!< DIEP_EACHMSK_N_EP_DISBLD_MSK Mask      */
#define USB_DIEPEACHMSK_N_DIEP_EACHMSK_N_EP_DISBLD_MSK_Set(x) (((uint32_t) (x) << USB_DIEPEACHMSK_N_DIEP_EACHMSK_N_EP_DISBLD_MSK_Pos) & USB_DIEPEACHMSK_N_DIEP_EACHMSK_N_EP_DISBLD_MSK_Msk) /*!< DIEP_EACHMSK_N_EP_DISBLD_MSK Set Value */
#define USB_DIEPEACHMSK_N_DIEP_EACHMSK_N_EP_DISBLD_MSK_Get(x) (((uint32_t) (x) & USB_DIEPEACHMSK_N_DIEP_EACHMSK_N_EP_DISBLD_MSK_Msk) >> USB_DIEPEACHMSK_N_DIEP_EACHMSK_N_EP_DISBLD_MSK_Pos) /*!< DIEP_EACHMSK_N_EP_DISBLD_MSK Get Value */


#define USB_DIEPEACHMSK_N_DIEP_EACHMSK_N_XFER_COMPL_MSK_Pos    (0U)                                                                        /*!< DIEP_EACHMSK_N_XFER_COMPL_MSK Postion   */ 
#define USB_DIEPEACHMSK_N_DIEP_EACHMSK_N_XFER_COMPL_MSK_Msk    (0x1U << USB_DIEPEACHMSK_N_DIEP_EACHMSK_N_XFER_COMPL_MSK_Pos)               /*!< DIEP_EACHMSK_N_XFER_COMPL_MSK Mask      */
#define USB_DIEPEACHMSK_N_DIEP_EACHMSK_N_XFER_COMPL_MSK_Set(x) (((uint32_t) (x) << USB_DIEPEACHMSK_N_DIEP_EACHMSK_N_XFER_COMPL_MSK_Pos) & USB_DIEPEACHMSK_N_DIEP_EACHMSK_N_XFER_COMPL_MSK_Msk) /*!< DIEP_EACHMSK_N_XFER_COMPL_MSK Set Value */
#define USB_DIEPEACHMSK_N_DIEP_EACHMSK_N_XFER_COMPL_MSK_Get(x) (((uint32_t) (x) & USB_DIEPEACHMSK_N_DIEP_EACHMSK_N_XFER_COMPL_MSK_Msk) >> USB_DIEPEACHMSK_N_DIEP_EACHMSK_N_XFER_COMPL_MSK_Pos) /*!< DIEP_EACHMSK_N_XFER_COMPL_MSK Get Value */


/* DOEPEACHMSK_N bitfield */
#define USB_DOEPEACHMSK_N_DOEP_EACHMSK_N_NYETMSK_Pos    (14U)                                                                       /*!< DOEP_EACHMSK_N_NYETMSK Postion   */ 
#define USB_DOEPEACHMSK_N_DOEP_EACHMSK_N_NYETMSK_Msk    (0x1U << USB_DOEPEACHMSK_N_DOEP_EACHMSK_N_NYETMSK_Pos)                      /*!< DOEP_EACHMSK_N_NYETMSK Mask      */
#define USB_DOEPEACHMSK_N_DOEP_EACHMSK_N_NYETMSK_Set(x) (((uint32_t) (x) << USB_DOEPEACHMSK_N_DOEP_EACHMSK_N_NYETMSK_Pos) & USB_DOEPEACHMSK_N_DOEP_EACHMSK_N_NYETMSK_Msk) /*!< DOEP_EACHMSK_N_NYETMSK Set Value */
#define USB_DOEPEACHMSK_N_DOEP_EACHMSK_N_NYETMSK_Get(x) (((uint32_t) (x) & USB_DOEPEACHMSK_N_DOEP_EACHMSK_N_NYETMSK_Msk) >> USB_DOEPEACHMSK_N_DOEP_EACHMSK_N_NYETMSK_Pos) /*!< DOEP_EACHMSK_N_NYETMSK Get Value */


#define USB_DOEPEACHMSK_N_DOEP_EACHMSK_N_NAKMSK_Pos    (13U)                                                                       /*!< DOEP_EACHMSK_N_NAKMSK Postion   */ 
#define USB_DOEPEACHMSK_N_DOEP_EACHMSK_N_NAKMSK_Msk    (0x1U << USB_DOEPEACHMSK_N_DOEP_EACHMSK_N_NAKMSK_Pos)                       /*!< DOEP_EACHMSK_N_NAKMSK Mask      */
#define USB_DOEPEACHMSK_N_DOEP_EACHMSK_N_NAKMSK_Set(x) (((uint32_t) (x) << USB_DOEPEACHMSK_N_DOEP_EACHMSK_N_NAKMSK_Pos) & USB_DOEPEACHMSK_N_DOEP_EACHMSK_N_NAKMSK_Msk) /*!< DOEP_EACHMSK_N_NAKMSK Set Value */
#define USB_DOEPEACHMSK_N_DOEP_EACHMSK_N_NAKMSK_Get(x) (((uint32_t) (x) & USB_DOEPEACHMSK_N_DOEP_EACHMSK_N_NAKMSK_Msk) >> USB_DOEPEACHMSK_N_DOEP_EACHMSK_N_NAKMSK_Pos) /*!< DOEP_EACHMSK_N_NAKMSK Get Value */


#define USB_DOEPEACHMSK_N_DOEP_EACHMSK_N_BBLE_ERR_MSK_Pos    (12U)                                                                       /*!< DOEP_EACHMSK_N_BBLE_ERR_MSK Postion   */ 
#define USB_DOEPEACHMSK_N_DOEP_EACHMSK_N_BBLE_ERR_MSK_Msk    (0x1U << USB_DOEPEACHMSK_N_DOEP_EACHMSK_N_BBLE_ERR_MSK_Pos)                 /*!< DOEP_EACHMSK_N_BBLE_ERR_MSK Mask      */
#define USB_DOEPEACHMSK_N_DOEP_EACHMSK_N_BBLE_ERR_MSK_Set(x) (((uint32_t) (x) << USB_DOEPEACHMSK_N_DOEP_EACHMSK_N_BBLE_ERR_MSK_Pos) & USB_DOEPEACHMSK_N_DOEP_EACHMSK_N_BBLE_ERR_MSK_Msk) /*!< DOEP_EACHMSK_N_BBLE_ERR_MSK Set Value */
#define USB_DOEPEACHMSK_N_DOEP_EACHMSK_N_BBLE_ERR_MSK_Get(x) (((uint32_t) (x) & USB_DOEPEACHMSK_N_DOEP_EACHMSK_N_BBLE_ERR_MSK_Msk) >> USB_DOEPEACHMSK_N_DOEP_EACHMSK_N_BBLE_ERR_MSK_Pos) /*!< DOEP_EACHMSK_N_BBLE_ERR_MSK Get Value */


#define USB_DOEPEACHMSK_N_DOEP_EACHMSK_N_BNA_OUT_INTR_MSK_Pos    (9U)                                                                        /*!< DOEP_EACHMSK_N_BNA_OUT_INTR_MSK Postion   */ 
#define USB_DOEPEACHMSK_N_DOEP_EACHMSK_N_BNA_OUT_INTR_MSK_Msk    (0x1U << USB_DOEPEACHMSK_N_DOEP_EACHMSK_N_BNA_OUT_INTR_MSK_Pos)             /*!< DOEP_EACHMSK_N_BNA_OUT_INTR_MSK Mask      */
#define USB_DOEPEACHMSK_N_DOEP_EACHMSK_N_BNA_OUT_INTR_MSK_Set(x) (((uint32_t) (x) << USB_DOEPEACHMSK_N_DOEP_EACHMSK_N_BNA_OUT_INTR_MSK_Pos) & USB_DOEPEACHMSK_N_DOEP_EACHMSK_N_BNA_OUT_INTR_MSK_Msk) /*!< DOEP_EACHMSK_N_BNA_OUT_INTR_MSK Set Value */
#define USB_DOEPEACHMSK_N_DOEP_EACHMSK_N_BNA_OUT_INTR_MSK_Get(x) (((uint32_t) (x) & USB_DOEPEACHMSK_N_DOEP_EACHMSK_N_BNA_OUT_INTR_MSK_Msk) >> USB_DOEPEACHMSK_N_DOEP_EACHMSK_N_BNA_OUT_INTR_MSK_Pos) /*!< DOEP_EACHMSK_N_BNA_OUT_INTR_MSK Get Value */


#define USB_DOEPEACHMSK_N_DOEP_EACHMSK_N_OUT_PKT_ERR_MSK_Pos    (8U)                                                                        /*!< DOEP_EACHMSK_N_OUT_PKT_ERR_MSK Postion   */ 
#define USB_DOEPEACHMSK_N_DOEP_EACHMSK_N_OUT_PKT_ERR_MSK_Msk    (0x1U << USB_DOEPEACHMSK_N_DOEP_EACHMSK_N_OUT_PKT_ERR_MSK_Pos)              /*!< DOEP_EACHMSK_N_OUT_PKT_ERR_MSK Mask      */
#define USB_DOEPEACHMSK_N_DOEP_EACHMSK_N_OUT_PKT_ERR_MSK_Set(x) (((uint32_t) (x) << USB_DOEPEACHMSK_N_DOEP_EACHMSK_N_OUT_PKT_ERR_MSK_Pos) & USB_DOEPEACHMSK_N_DOEP_EACHMSK_N_OUT_PKT_ERR_MSK_Msk) /*!< DOEP_EACHMSK_N_OUT_PKT_ERR_MSK Set Value */
#define USB_DOEPEACHMSK_N_DOEP_EACHMSK_N_OUT_PKT_ERR_MSK_Get(x) (((uint32_t) (x) & USB_DOEPEACHMSK_N_DOEP_EACHMSK_N_OUT_PKT_ERR_MSK_Msk) >> USB_DOEPEACHMSK_N_DOEP_EACHMSK_N_OUT_PKT_ERR_MSK_Pos) /*!< DOEP_EACHMSK_N_OUT_PKT_ERR_MSK Get Value */


#define USB_DOEPEACHMSK_N_DOEP_EACHMSK_N_BACK2BACK_SETUP_Pos    (6U)                                                                        /*!< DOEP_EACHMSK_N_BACK2BACK_SETUP Postion   */ 
#define USB_DOEPEACHMSK_N_DOEP_EACHMSK_N_BACK2BACK_SETUP_Msk    (0x1U << USB_DOEPEACHMSK_N_DOEP_EACHMSK_N_BACK2BACK_SETUP_Pos)              /*!< DOEP_EACHMSK_N_BACK2BACK_SETUP Mask      */
#define USB_DOEPEACHMSK_N_DOEP_EACHMSK_N_BACK2BACK_SETUP_Set(x) (((uint32_t) (x) << USB_DOEPEACHMSK_N_DOEP_EACHMSK_N_BACK2BACK_SETUP_Pos) & USB_DOEPEACHMSK_N_DOEP_EACHMSK_N_BACK2BACK_SETUP_Msk) /*!< DOEP_EACHMSK_N_BACK2BACK_SETUP Set Value */
#define USB_DOEPEACHMSK_N_DOEP_EACHMSK_N_BACK2BACK_SETUP_Get(x) (((uint32_t) (x) & USB_DOEPEACHMSK_N_DOEP_EACHMSK_N_BACK2BACK_SETUP_Msk) >> USB_DOEPEACHMSK_N_DOEP_EACHMSK_N_BACK2BACK_SETUP_Pos) /*!< DOEP_EACHMSK_N_BACK2BACK_SETUP Get Value */


#define USB_DOEPEACHMSK_N_DOEP_EACHMSK_N_STS_PHS_RCVD_MSK_Pos    (5U)                                                                        /*!< DOEP_EACHMSK_N_STS_PHS_RCVD_MSK Postion   */ 
#define USB_DOEPEACHMSK_N_DOEP_EACHMSK_N_STS_PHS_RCVD_MSK_Msk    (0x1U << USB_DOEPEACHMSK_N_DOEP_EACHMSK_N_STS_PHS_RCVD_MSK_Pos)             /*!< DOEP_EACHMSK_N_STS_PHS_RCVD_MSK Mask      */
#define USB_DOEPEACHMSK_N_DOEP_EACHMSK_N_STS_PHS_RCVD_MSK_Set(x) (((uint32_t) (x) << USB_DOEPEACHMSK_N_DOEP_EACHMSK_N_STS_PHS_RCVD_MSK_Pos) & USB_DOEPEACHMSK_N_DOEP_EACHMSK_N_STS_PHS_RCVD_MSK_Msk) /*!< DOEP_EACHMSK_N_STS_PHS_RCVD_MSK Set Value */
#define USB_DOEPEACHMSK_N_DOEP_EACHMSK_N_STS_PHS_RCVD_MSK_Get(x) (((uint32_t) (x) & USB_DOEPEACHMSK_N_DOEP_EACHMSK_N_STS_PHS_RCVD_MSK_Msk) >> USB_DOEPEACHMSK_N_DOEP_EACHMSK_N_STS_PHS_RCVD_MSK_Pos) /*!< DOEP_EACHMSK_N_STS_PHS_RCVD_MSK Get Value */


#define USB_DOEPEACHMSK_N_DOEP_EACHMSK_N_OUT_TKN_EP_DIS_MSK_Pos    (4U)                                                                        /*!< DOEP_EACHMSK_N_OUT_TKN_EP_DIS_MSK Postion   */ 
#define USB_DOEPEACHMSK_N_DOEP_EACHMSK_N_OUT_TKN_EP_DIS_MSK_Msk    (0x1U << USB_DOEPEACHMSK_N_DOEP_EACHMSK_N_OUT_TKN_EP_DIS_MSK_Pos)           /*!< DOEP_EACHMSK_N_OUT_TKN_EP_DIS_MSK Mask      */
#define USB_DOEPEACHMSK_N_DOEP_EACHMSK_N_OUT_TKN_EP_DIS_MSK_Set(x) (((uint32_t) (x) << USB_DOEPEACHMSK_N_DOEP_EACHMSK_N_OUT_TKN_EP_DIS_MSK_Pos) & USB_DOEPEACHMSK_N_DOEP_EACHMSK_N_OUT_TKN_EP_DIS_MSK_Msk) /*!< DOEP_EACHMSK_N_OUT_TKN_EP_DIS_MSK Set Value */
#define USB_DOEPEACHMSK_N_DOEP_EACHMSK_N_OUT_TKN_EP_DIS_MSK_Get(x) (((uint32_t) (x) & USB_DOEPEACHMSK_N_DOEP_EACHMSK_N_OUT_TKN_EP_DIS_MSK_Msk) >> USB_DOEPEACHMSK_N_DOEP_EACHMSK_N_OUT_TKN_EP_DIS_MSK_Pos) /*!< DOEP_EACHMSK_N_OUT_TKN_EP_DIS_MSK Get Value */


#define USB_DOEPEACHMSK_N_DOEP_EACHMSK_N_SET_UPMSK_Pos    (3U)                                                                        /*!< DOEP_EACHMSK_N_SET_UPMSK Postion   */ 
#define USB_DOEPEACHMSK_N_DOEP_EACHMSK_N_SET_UPMSK_Msk    (0x1U << USB_DOEPEACHMSK_N_DOEP_EACHMSK_N_SET_UPMSK_Pos)                    /*!< DOEP_EACHMSK_N_SET_UPMSK Mask      */
#define USB_DOEPEACHMSK_N_DOEP_EACHMSK_N_SET_UPMSK_Set(x) (((uint32_t) (x) << USB_DOEPEACHMSK_N_DOEP_EACHMSK_N_SET_UPMSK_Pos) & USB_DOEPEACHMSK_N_DOEP_EACHMSK_N_SET_UPMSK_Msk) /*!< DOEP_EACHMSK_N_SET_UPMSK Set Value */
#define USB_DOEPEACHMSK_N_DOEP_EACHMSK_N_SET_UPMSK_Get(x) (((uint32_t) (x) & USB_DOEPEACHMSK_N_DOEP_EACHMSK_N_SET_UPMSK_Msk) >> USB_DOEPEACHMSK_N_DOEP_EACHMSK_N_SET_UPMSK_Pos) /*!< DOEP_EACHMSK_N_SET_UPMSK Get Value */


#define USB_DOEPEACHMSK_N_DOEP_EACHMSK_N_AHB_ERR_MSK_Pos    (2U)                                                                        /*!< DOEP_EACHMSK_N_AHB_ERR_MSK Postion   */ 
#define USB_DOEPEACHMSK_N_DOEP_EACHMSK_N_AHB_ERR_MSK_Msk    (0x1U << USB_DOEPEACHMSK_N_DOEP_EACHMSK_N_AHB_ERR_MSK_Pos)                  /*!< DOEP_EACHMSK_N_AHB_ERR_MSK Mask      */
#define USB_DOEPEACHMSK_N_DOEP_EACHMSK_N_AHB_ERR_MSK_Set(x) (((uint32_t) (x) << USB_DOEPEACHMSK_N_DOEP_EACHMSK_N_AHB_ERR_MSK_Pos) & USB_DOEPEACHMSK_N_DOEP_EACHMSK_N_AHB_ERR_MSK_Msk) /*!< DOEP_EACHMSK_N_AHB_ERR_MSK Set Value */
#define USB_DOEPEACHMSK_N_DOEP_EACHMSK_N_AHB_ERR_MSK_Get(x) (((uint32_t) (x) & USB_DOEPEACHMSK_N_DOEP_EACHMSK_N_AHB_ERR_MSK_Msk) >> USB_DOEPEACHMSK_N_DOEP_EACHMSK_N_AHB_ERR_MSK_Pos) /*!< DOEP_EACHMSK_N_AHB_ERR_MSK Get Value */


#define USB_DOEPEACHMSK_N_DOEP_EACHMSK_N_EP_DISBLD_MSK_Pos    (1U)                                                                        /*!< DOEP_EACHMSK_N_EP_DISBLD_MSK Postion   */ 
#define USB_DOEPEACHMSK_N_DOEP_EACHMSK_N_EP_DISBLD_MSK_Msk    (0x1U << USB_DOEPEACHMSK_N_DOEP_EACHMSK_N_EP_DISBLD_MSK_Pos)                /*!< DOEP_EACHMSK_N_EP_DISBLD_MSK Mask      */
#define USB_DOEPEACHMSK_N_DOEP_EACHMSK_N_EP_DISBLD_MSK_Set(x) (((uint32_t) (x) << USB_DOEPEACHMSK_N_DOEP_EACHMSK_N_EP_DISBLD_MSK_Pos) & USB_DOEPEACHMSK_N_DOEP_EACHMSK_N_EP_DISBLD_MSK_Msk) /*!< DOEP_EACHMSK_N_EP_DISBLD_MSK Set Value */
#define USB_DOEPEACHMSK_N_DOEP_EACHMSK_N_EP_DISBLD_MSK_Get(x) (((uint32_t) (x) & USB_DOEPEACHMSK_N_DOEP_EACHMSK_N_EP_DISBLD_MSK_Msk) >> USB_DOEPEACHMSK_N_DOEP_EACHMSK_N_EP_DISBLD_MSK_Pos) /*!< DOEP_EACHMSK_N_EP_DISBLD_MSK Get Value */


#define USB_DOEPEACHMSK_N_DOEP_EACHMSK_N_XFER_COMPL_MSK_Pos    (0U)                                                                        /*!< DOEP_EACHMSK_N_XFER_COMPL_MSK Postion   */ 
#define USB_DOEPEACHMSK_N_DOEP_EACHMSK_N_XFER_COMPL_MSK_Msk    (0x1U << USB_DOEPEACHMSK_N_DOEP_EACHMSK_N_XFER_COMPL_MSK_Pos)               /*!< DOEP_EACHMSK_N_XFER_COMPL_MSK Mask      */
#define USB_DOEPEACHMSK_N_DOEP_EACHMSK_N_XFER_COMPL_MSK_Set(x) (((uint32_t) (x) << USB_DOEPEACHMSK_N_DOEP_EACHMSK_N_XFER_COMPL_MSK_Pos) & USB_DOEPEACHMSK_N_DOEP_EACHMSK_N_XFER_COMPL_MSK_Msk) /*!< DOEP_EACHMSK_N_XFER_COMPL_MSK Set Value */
#define USB_DOEPEACHMSK_N_DOEP_EACHMSK_N_XFER_COMPL_MSK_Get(x) (((uint32_t) (x) & USB_DOEPEACHMSK_N_DOEP_EACHMSK_N_XFER_COMPL_MSK_Msk) >> USB_DOEPEACHMSK_N_DOEP_EACHMSK_N_XFER_COMPL_MSK_Pos) /*!< DOEP_EACHMSK_N_XFER_COMPL_MSK Get Value */


/* DIEPCTL_N bitfield */
#define USB_DIEPCTL_N_DIEP_CTL_N_EP_ENA_Pos    (31U)                                                                       /*!< DIEP_CTL_N_EP_ENA Postion   */ 
#define USB_DIEPCTL_N_DIEP_CTL_N_EP_ENA_Msk    (0x1U << USB_DIEPCTL_N_DIEP_CTL_N_EP_ENA_Pos)                               /*!< DIEP_CTL_N_EP_ENA Mask      */
#define USB_DIEPCTL_N_DIEP_CTL_N_EP_ENA_Set(x) (((uint32_t) (x) << USB_DIEPCTL_N_DIEP_CTL_N_EP_ENA_Pos) & USB_DIEPCTL_N_DIEP_CTL_N_EP_ENA_Msk) /*!< DIEP_CTL_N_EP_ENA Set Value */
#define USB_DIEPCTL_N_DIEP_CTL_N_EP_ENA_Get(x) (((uint32_t) (x) & USB_DIEPCTL_N_DIEP_CTL_N_EP_ENA_Msk) >> USB_DIEPCTL_N_DIEP_CTL_N_EP_ENA_Pos) /*!< DIEP_CTL_N_EP_ENA Get Value */


#define USB_DIEPCTL_N_DIEP_CTL_N_EP_DIS_Pos    (30U)                                                                       /*!< DIEP_CTL_N_EP_DIS Postion   */ 
#define USB_DIEPCTL_N_DIEP_CTL_N_EP_DIS_Msk    (0x1U << USB_DIEPCTL_N_DIEP_CTL_N_EP_DIS_Pos)                               /*!< DIEP_CTL_N_EP_DIS Mask      */
#define USB_DIEPCTL_N_DIEP_CTL_N_EP_DIS_Set(x) (((uint32_t) (x) << USB_DIEPCTL_N_DIEP_CTL_N_EP_DIS_Pos) & USB_DIEPCTL_N_DIEP_CTL_N_EP_DIS_Msk) /*!< DIEP_CTL_N_EP_DIS Set Value */
#define USB_DIEPCTL_N_DIEP_CTL_N_EP_DIS_Get(x) (((uint32_t) (x) & USB_DIEPCTL_N_DIEP_CTL_N_EP_DIS_Msk) >> USB_DIEPCTL_N_DIEP_CTL_N_EP_DIS_Pos) /*!< DIEP_CTL_N_EP_DIS Get Value */


#define USB_DIEPCTL_N_DIEP_CTL_N_SET_D1PID_Pos    (29U)                                                                       /*!< DIEP_CTL_N_SET_D1PID Postion   */ 
#define USB_DIEPCTL_N_DIEP_CTL_N_SET_D1PID_Msk    (0x1U << USB_DIEPCTL_N_DIEP_CTL_N_SET_D1PID_Pos)                            /*!< DIEP_CTL_N_SET_D1PID Mask      */
#define USB_DIEPCTL_N_DIEP_CTL_N_SET_D1PID_Set(x) (((uint32_t) (x) << USB_DIEPCTL_N_DIEP_CTL_N_SET_D1PID_Pos) & USB_DIEPCTL_N_DIEP_CTL_N_SET_D1PID_Msk) /*!< DIEP_CTL_N_SET_D1PID Set Value */
#define USB_DIEPCTL_N_DIEP_CTL_N_SET_D1PID_Get(x) (((uint32_t) (x) & USB_DIEPCTL_N_DIEP_CTL_N_SET_D1PID_Msk) >> USB_DIEPCTL_N_DIEP_CTL_N_SET_D1PID_Pos) /*!< DIEP_CTL_N_SET_D1PID Get Value */


#define USB_DIEPCTL_N_DIEP_CTL_N_SET_D0PID_Pos    (28U)                                                                       /*!< DIEP_CTL_N_SET_D0PID Postion   */ 
#define USB_DIEPCTL_N_DIEP_CTL_N_SET_D0PID_Msk    (0x1U << USB_DIEPCTL_N_DIEP_CTL_N_SET_D0PID_Pos)                            /*!< DIEP_CTL_N_SET_D0PID Mask      */
#define USB_DIEPCTL_N_DIEP_CTL_N_SET_D0PID_Set(x) (((uint32_t) (x) << USB_DIEPCTL_N_DIEP_CTL_N_SET_D0PID_Pos) & USB_DIEPCTL_N_DIEP_CTL_N_SET_D0PID_Msk) /*!< DIEP_CTL_N_SET_D0PID Set Value */
#define USB_DIEPCTL_N_DIEP_CTL_N_SET_D0PID_Get(x) (((uint32_t) (x) & USB_DIEPCTL_N_DIEP_CTL_N_SET_D0PID_Msk) >> USB_DIEPCTL_N_DIEP_CTL_N_SET_D0PID_Pos) /*!< DIEP_CTL_N_SET_D0PID Get Value */


#define USB_DIEPCTL_N_DIEP_CTL_N_SNAK_Pos    (27U)                                                                       /*!< DIEP_CTL_N_SNAK Postion   */ 
#define USB_DIEPCTL_N_DIEP_CTL_N_SNAK_Msk    (0x1U << USB_DIEPCTL_N_DIEP_CTL_N_SNAK_Pos)                                 /*!< DIEP_CTL_N_SNAK Mask      */
#define USB_DIEPCTL_N_DIEP_CTL_N_SNAK_Set(x) (((uint32_t) (x) << USB_DIEPCTL_N_DIEP_CTL_N_SNAK_Pos) & USB_DIEPCTL_N_DIEP_CTL_N_SNAK_Msk) /*!< DIEP_CTL_N_SNAK Set Value */
#define USB_DIEPCTL_N_DIEP_CTL_N_SNAK_Get(x) (((uint32_t) (x) & USB_DIEPCTL_N_DIEP_CTL_N_SNAK_Msk) >> USB_DIEPCTL_N_DIEP_CTL_N_SNAK_Pos) /*!< DIEP_CTL_N_SNAK Get Value */


#define USB_DIEPCTL_N_DIEP_CTL_N_CNAK_Pos    (26U)                                                                       /*!< DIEP_CTL_N_CNAK Postion   */ 
#define USB_DIEPCTL_N_DIEP_CTL_N_CNAK_Msk    (0x1U << USB_DIEPCTL_N_DIEP_CTL_N_CNAK_Pos)                                 /*!< DIEP_CTL_N_CNAK Mask      */
#define USB_DIEPCTL_N_DIEP_CTL_N_CNAK_Set(x) (((uint32_t) (x) << USB_DIEPCTL_N_DIEP_CTL_N_CNAK_Pos) & USB_DIEPCTL_N_DIEP_CTL_N_CNAK_Msk) /*!< DIEP_CTL_N_CNAK Set Value */
#define USB_DIEPCTL_N_DIEP_CTL_N_CNAK_Get(x) (((uint32_t) (x) & USB_DIEPCTL_N_DIEP_CTL_N_CNAK_Msk) >> USB_DIEPCTL_N_DIEP_CTL_N_CNAK_Pos) /*!< DIEP_CTL_N_CNAK Get Value */


#define USB_DIEPCTL_N_DIEP_CTL_N_TXF_NUM_Pos    (22U)                                                                       /*!< DIEP_CTL_N_TXF_NUM Postion   */ 
#define USB_DIEPCTL_N_DIEP_CTL_N_TXF_NUM_Msk    (0xfU << USB_DIEPCTL_N_DIEP_CTL_N_TXF_NUM_Pos)                              /*!< DIEP_CTL_N_TXF_NUM Mask      */
#define USB_DIEPCTL_N_DIEP_CTL_N_TXF_NUM_Set(x) (((uint32_t) (x) << USB_DIEPCTL_N_DIEP_CTL_N_TXF_NUM_Pos) & USB_DIEPCTL_N_DIEP_CTL_N_TXF_NUM_Msk) /*!< DIEP_CTL_N_TXF_NUM Set Value */
#define USB_DIEPCTL_N_DIEP_CTL_N_TXF_NUM_Get(x) (((uint32_t) (x) & USB_DIEPCTL_N_DIEP_CTL_N_TXF_NUM_Msk) >> USB_DIEPCTL_N_DIEP_CTL_N_TXF_NUM_Pos) /*!< DIEP_CTL_N_TXF_NUM Get Value */


#define USB_DIEPCTL_N_DIEP_CTL_N_STALL_Pos    (21U)                                                                       /*!< DIEP_CTL_N_STALL Postion   */ 
#define USB_DIEPCTL_N_DIEP_CTL_N_STALL_Msk    (0x1U << USB_DIEPCTL_N_DIEP_CTL_N_STALL_Pos)                                /*!< DIEP_CTL_N_STALL Mask      */
#define USB_DIEPCTL_N_DIEP_CTL_N_STALL_Set(x) (((uint32_t) (x) << USB_DIEPCTL_N_DIEP_CTL_N_STALL_Pos) & USB_DIEPCTL_N_DIEP_CTL_N_STALL_Msk) /*!< DIEP_CTL_N_STALL Set Value */
#define USB_DIEPCTL_N_DIEP_CTL_N_STALL_Get(x) (((uint32_t) (x) & USB_DIEPCTL_N_DIEP_CTL_N_STALL_Msk) >> USB_DIEPCTL_N_DIEP_CTL_N_STALL_Pos) /*!< DIEP_CTL_N_STALL Get Value */


#define USB_DIEPCTL_N_DIEP_CTL_N_EP_TYPE_Pos    (18U)                                                                       /*!< DIEP_CTL_N_EP_TYPE Postion   */ 
#define USB_DIEPCTL_N_DIEP_CTL_N_EP_TYPE_Msk    (0x3U << USB_DIEPCTL_N_DIEP_CTL_N_EP_TYPE_Pos)                              /*!< DIEP_CTL_N_EP_TYPE Mask      */
#define USB_DIEPCTL_N_DIEP_CTL_N_EP_TYPE_Set(x) (((uint32_t) (x) << USB_DIEPCTL_N_DIEP_CTL_N_EP_TYPE_Pos) & USB_DIEPCTL_N_DIEP_CTL_N_EP_TYPE_Msk) /*!< DIEP_CTL_N_EP_TYPE Set Value */
#define USB_DIEPCTL_N_DIEP_CTL_N_EP_TYPE_Get(x) (((uint32_t) (x) & USB_DIEPCTL_N_DIEP_CTL_N_EP_TYPE_Msk) >> USB_DIEPCTL_N_DIEP_CTL_N_EP_TYPE_Pos) /*!< DIEP_CTL_N_EP_TYPE Get Value */


#define USB_DIEPCTL_N_DIEP_CTL_N_NAKSTS_Pos    (17U)                                                                       /*!< DIEP_CTL_N_NAKSTS Postion   */ 
#define USB_DIEPCTL_N_DIEP_CTL_N_NAKSTS_Msk    (0x1U << USB_DIEPCTL_N_DIEP_CTL_N_NAKSTS_Pos)                               /*!< DIEP_CTL_N_NAKSTS Mask      */
#define USB_DIEPCTL_N_DIEP_CTL_N_NAKSTS_Set(x) (((uint32_t) (x) << USB_DIEPCTL_N_DIEP_CTL_N_NAKSTS_Pos) & USB_DIEPCTL_N_DIEP_CTL_N_NAKSTS_Msk) /*!< DIEP_CTL_N_NAKSTS Set Value */
#define USB_DIEPCTL_N_DIEP_CTL_N_NAKSTS_Get(x) (((uint32_t) (x) & USB_DIEPCTL_N_DIEP_CTL_N_NAKSTS_Msk) >> USB_DIEPCTL_N_DIEP_CTL_N_NAKSTS_Pos) /*!< DIEP_CTL_N_NAKSTS Get Value */


#define USB_DIEPCTL_N_DIEP_CTL_N_DPID_Pos    (16U)                                                                       /*!< DIEP_CTL_N_DPID Postion   */ 
#define USB_DIEPCTL_N_DIEP_CTL_N_DPID_Msk    (0x1U << USB_DIEPCTL_N_DIEP_CTL_N_DPID_Pos)                                 /*!< DIEP_CTL_N_DPID Mask      */
#define USB_DIEPCTL_N_DIEP_CTL_N_DPID_Set(x) (((uint32_t) (x) << USB_DIEPCTL_N_DIEP_CTL_N_DPID_Pos) & USB_DIEPCTL_N_DIEP_CTL_N_DPID_Msk) /*!< DIEP_CTL_N_DPID Set Value */
#define USB_DIEPCTL_N_DIEP_CTL_N_DPID_Get(x) (((uint32_t) (x) & USB_DIEPCTL_N_DIEP_CTL_N_DPID_Msk) >> USB_DIEPCTL_N_DIEP_CTL_N_DPID_Pos) /*!< DIEP_CTL_N_DPID Get Value */


#define USB_DIEPCTL_N_DIEP_CTL_N_USB_ACT_EP_Pos    (15U)                                                                       /*!< DIEP_CTL_N_USB_ACT_EP Postion   */ 
#define USB_DIEPCTL_N_DIEP_CTL_N_USB_ACT_EP_Msk    (0x1U << USB_DIEPCTL_N_DIEP_CTL_N_USB_ACT_EP_Pos)                           /*!< DIEP_CTL_N_USB_ACT_EP Mask      */
#define USB_DIEPCTL_N_DIEP_CTL_N_USB_ACT_EP_Set(x) (((uint32_t) (x) << USB_DIEPCTL_N_DIEP_CTL_N_USB_ACT_EP_Pos) & USB_DIEPCTL_N_DIEP_CTL_N_USB_ACT_EP_Msk) /*!< DIEP_CTL_N_USB_ACT_EP Set Value */
#define USB_DIEPCTL_N_DIEP_CTL_N_USB_ACT_EP_Get(x) (((uint32_t) (x) & USB_DIEPCTL_N_DIEP_CTL_N_USB_ACT_EP_Msk) >> USB_DIEPCTL_N_DIEP_CTL_N_USB_ACT_EP_Pos) /*!< DIEP_CTL_N_USB_ACT_EP Get Value */


#define USB_DIEPCTL_N_DIEP_CTL_N_MPS_Pos    (0U)                                                                        /*!< DIEP_CTL_N_MPS Postion   */ 
#define USB_DIEPCTL_N_DIEP_CTL_N_MPS_Msk    (0x7ffU << USB_DIEPCTL_N_DIEP_CTL_N_MPS_Pos)                                /*!< DIEP_CTL_N_MPS Mask      */
#define USB_DIEPCTL_N_DIEP_CTL_N_MPS_Set(x) (((uint32_t) (x) << USB_DIEPCTL_N_DIEP_CTL_N_MPS_Pos) & USB_DIEPCTL_N_DIEP_CTL_N_MPS_Msk) /*!< DIEP_CTL_N_MPS Set Value */
#define USB_DIEPCTL_N_DIEP_CTL_N_MPS_Get(x) (((uint32_t) (x) & USB_DIEPCTL_N_DIEP_CTL_N_MPS_Msk) >> USB_DIEPCTL_N_DIEP_CTL_N_MPS_Pos) /*!< DIEP_CTL_N_MPS Get Value */


/* DIEPINT_N bitfield */
#define USB_DIEPINT_N_DIEP_IN_T_N_NAKINTRPT_Pos    (13U)                                                                       /*!< DIEP_IN_T_N_NAKINTRPT Postion   */ 
#define USB_DIEPINT_N_DIEP_IN_T_N_NAKINTRPT_Msk    (0x1U << USB_DIEPINT_N_DIEP_IN_T_N_NAKINTRPT_Pos)                           /*!< DIEP_IN_T_N_NAKINTRPT Mask      */
#define USB_DIEPINT_N_DIEP_IN_T_N_NAKINTRPT_Set(x) (((uint32_t) (x) << USB_DIEPINT_N_DIEP_IN_T_N_NAKINTRPT_Pos) & USB_DIEPINT_N_DIEP_IN_T_N_NAKINTRPT_Msk) /*!< DIEP_IN_T_N_NAKINTRPT Set Value */
#define USB_DIEPINT_N_DIEP_IN_T_N_NAKINTRPT_Get(x) (((uint32_t) (x) & USB_DIEPINT_N_DIEP_IN_T_N_NAKINTRPT_Msk) >> USB_DIEPINT_N_DIEP_IN_T_N_NAKINTRPT_Pos) /*!< DIEP_IN_T_N_NAKINTRPT Get Value */


#define USB_DIEPINT_N_DIEP_IN_T_N_BBLE_ERR_Pos    (12U)                                                                       /*!< DIEP_IN_T_N_BBLE_ERR Postion   */ 
#define USB_DIEPINT_N_DIEP_IN_T_N_BBLE_ERR_Msk    (0x1U << USB_DIEPINT_N_DIEP_IN_T_N_BBLE_ERR_Pos)                            /*!< DIEP_IN_T_N_BBLE_ERR Mask      */
#define USB_DIEPINT_N_DIEP_IN_T_N_BBLE_ERR_Set(x) (((uint32_t) (x) << USB_DIEPINT_N_DIEP_IN_T_N_BBLE_ERR_Pos) & USB_DIEPINT_N_DIEP_IN_T_N_BBLE_ERR_Msk) /*!< DIEP_IN_T_N_BBLE_ERR Set Value */
#define USB_DIEPINT_N_DIEP_IN_T_N_BBLE_ERR_Get(x) (((uint32_t) (x) & USB_DIEPINT_N_DIEP_IN_T_N_BBLE_ERR_Msk) >> USB_DIEPINT_N_DIEP_IN_T_N_BBLE_ERR_Pos) /*!< DIEP_IN_T_N_BBLE_ERR Get Value */


#define USB_DIEPINT_N_DIEP_IN_T_N_PKT_DRP_STS_Pos    (11U)                                                                       /*!< DIEP_IN_T_N_PKT_DRP_STS Postion   */ 
#define USB_DIEPINT_N_DIEP_IN_T_N_PKT_DRP_STS_Msk    (0x1U << USB_DIEPINT_N_DIEP_IN_T_N_PKT_DRP_STS_Pos)                         /*!< DIEP_IN_T_N_PKT_DRP_STS Mask      */
#define USB_DIEPINT_N_DIEP_IN_T_N_PKT_DRP_STS_Set(x) (((uint32_t) (x) << USB_DIEPINT_N_DIEP_IN_T_N_PKT_DRP_STS_Pos) & USB_DIEPINT_N_DIEP_IN_T_N_PKT_DRP_STS_Msk) /*!< DIEP_IN_T_N_PKT_DRP_STS Set Value */
#define USB_DIEPINT_N_DIEP_IN_T_N_PKT_DRP_STS_Get(x) (((uint32_t) (x) & USB_DIEPINT_N_DIEP_IN_T_N_PKT_DRP_STS_Msk) >> USB_DIEPINT_N_DIEP_IN_T_N_PKT_DRP_STS_Pos) /*!< DIEP_IN_T_N_PKT_DRP_STS Get Value */


#define USB_DIEPINT_N_DIEP_IN_T_N_BNAINTR_Pos    (9U)                                                                        /*!< DIEP_IN_T_N_BNAINTR Postion   */ 
#define USB_DIEPINT_N_DIEP_IN_T_N_BNAINTR_Msk    (0x1U << USB_DIEPINT_N_DIEP_IN_T_N_BNAINTR_Pos)                             /*!< DIEP_IN_T_N_BNAINTR Mask      */
#define USB_DIEPINT_N_DIEP_IN_T_N_BNAINTR_Set(x) (((uint32_t) (x) << USB_DIEPINT_N_DIEP_IN_T_N_BNAINTR_Pos) & USB_DIEPINT_N_DIEP_IN_T_N_BNAINTR_Msk) /*!< DIEP_IN_T_N_BNAINTR Set Value */
#define USB_DIEPINT_N_DIEP_IN_T_N_BNAINTR_Get(x) (((uint32_t) (x) & USB_DIEPINT_N_DIEP_IN_T_N_BNAINTR_Msk) >> USB_DIEPINT_N_DIEP_IN_T_N_BNAINTR_Pos) /*!< DIEP_IN_T_N_BNAINTR Get Value */


#define USB_DIEPINT_N_DIEP_IN_T_N_TXFIFO_UNDRN_Pos    (8U)                                                                        /*!< DIEP_IN_T_N_TXFIFO_UNDRN Postion   */ 
#define USB_DIEPINT_N_DIEP_IN_T_N_TXFIFO_UNDRN_Msk    (0x1U << USB_DIEPINT_N_DIEP_IN_T_N_TXFIFO_UNDRN_Pos)                        /*!< DIEP_IN_T_N_TXFIFO_UNDRN Mask      */
#define USB_DIEPINT_N_DIEP_IN_T_N_TXFIFO_UNDRN_Set(x) (((uint32_t) (x) << USB_DIEPINT_N_DIEP_IN_T_N_TXFIFO_UNDRN_Pos) & USB_DIEPINT_N_DIEP_IN_T_N_TXFIFO_UNDRN_Msk) /*!< DIEP_IN_T_N_TXFIFO_UNDRN Set Value */
#define USB_DIEPINT_N_DIEP_IN_T_N_TXFIFO_UNDRN_Get(x) (((uint32_t) (x) & USB_DIEPINT_N_DIEP_IN_T_N_TXFIFO_UNDRN_Msk) >> USB_DIEPINT_N_DIEP_IN_T_N_TXFIFO_UNDRN_Pos) /*!< DIEP_IN_T_N_TXFIFO_UNDRN Get Value */


#define USB_DIEPINT_N_DIEP_IN_T_N_TXF_EMP_Pos    (7U)                                                                        /*!< DIEP_IN_T_N_TXF_EMP Postion   */ 
#define USB_DIEPINT_N_DIEP_IN_T_N_TXF_EMP_Msk    (0x1U << USB_DIEPINT_N_DIEP_IN_T_N_TXF_EMP_Pos)                             /*!< DIEP_IN_T_N_TXF_EMP Mask      */
#define USB_DIEPINT_N_DIEP_IN_T_N_TXF_EMP_Set(x) (((uint32_t) (x) << USB_DIEPINT_N_DIEP_IN_T_N_TXF_EMP_Pos) & USB_DIEPINT_N_DIEP_IN_T_N_TXF_EMP_Msk) /*!< DIEP_IN_T_N_TXF_EMP Set Value */
#define USB_DIEPINT_N_DIEP_IN_T_N_TXF_EMP_Get(x) (((uint32_t) (x) & USB_DIEPINT_N_DIEP_IN_T_N_TXF_EMP_Msk) >> USB_DIEPINT_N_DIEP_IN_T_N_TXF_EMP_Pos) /*!< DIEP_IN_T_N_TXF_EMP Get Value */


#define USB_DIEPINT_N_DIEP_IN_T_N_IN_EP_NAK_EFF_Pos    (6U)                                                                        /*!< DIEP_IN_T_N_IN_EP_NAK_EFF Postion   */ 
#define USB_DIEPINT_N_DIEP_IN_T_N_IN_EP_NAK_EFF_Msk    (0x1U << USB_DIEPINT_N_DIEP_IN_T_N_IN_EP_NAK_EFF_Pos)                       /*!< DIEP_IN_T_N_IN_EP_NAK_EFF Mask      */
#define USB_DIEPINT_N_DIEP_IN_T_N_IN_EP_NAK_EFF_Set(x) (((uint32_t) (x) << USB_DIEPINT_N_DIEP_IN_T_N_IN_EP_NAK_EFF_Pos) & USB_DIEPINT_N_DIEP_IN_T_N_IN_EP_NAK_EFF_Msk) /*!< DIEP_IN_T_N_IN_EP_NAK_EFF Set Value */
#define USB_DIEPINT_N_DIEP_IN_T_N_IN_EP_NAK_EFF_Get(x) (((uint32_t) (x) & USB_DIEPINT_N_DIEP_IN_T_N_IN_EP_NAK_EFF_Msk) >> USB_DIEPINT_N_DIEP_IN_T_N_IN_EP_NAK_EFF_Pos) /*!< DIEP_IN_T_N_IN_EP_NAK_EFF Get Value */


#define USB_DIEPINT_N_DIEP_IN_T_N_IN_TKN_EP_MIS_Pos    (5U)                                                                        /*!< DIEP_IN_T_N_IN_TKN_EP_MIS Postion   */ 
#define USB_DIEPINT_N_DIEP_IN_T_N_IN_TKN_EP_MIS_Msk    (0x1U << USB_DIEPINT_N_DIEP_IN_T_N_IN_TKN_EP_MIS_Pos)                       /*!< DIEP_IN_T_N_IN_TKN_EP_MIS Mask      */
#define USB_DIEPINT_N_DIEP_IN_T_N_IN_TKN_EP_MIS_Set(x) (((uint32_t) (x) << USB_DIEPINT_N_DIEP_IN_T_N_IN_TKN_EP_MIS_Pos) & USB_DIEPINT_N_DIEP_IN_T_N_IN_TKN_EP_MIS_Msk) /*!< DIEP_IN_T_N_IN_TKN_EP_MIS Set Value */
#define USB_DIEPINT_N_DIEP_IN_T_N_IN_TKN_EP_MIS_Get(x) (((uint32_t) (x) & USB_DIEPINT_N_DIEP_IN_T_N_IN_TKN_EP_MIS_Msk) >> USB_DIEPINT_N_DIEP_IN_T_N_IN_TKN_EP_MIS_Pos) /*!< DIEP_IN_T_N_IN_TKN_EP_MIS Get Value */


#define USB_DIEPINT_N_DIEP_IN_T_N_IN_TKN_TXFEMP_Pos    (4U)                                                                        /*!< DIEP_IN_T_N_IN_TKN_TXFEMP Postion   */ 
#define USB_DIEPINT_N_DIEP_IN_T_N_IN_TKN_TXFEMP_Msk    (0x1U << USB_DIEPINT_N_DIEP_IN_T_N_IN_TKN_TXFEMP_Pos)                       /*!< DIEP_IN_T_N_IN_TKN_TXFEMP Mask      */
#define USB_DIEPINT_N_DIEP_IN_T_N_IN_TKN_TXFEMP_Set(x) (((uint32_t) (x) << USB_DIEPINT_N_DIEP_IN_T_N_IN_TKN_TXFEMP_Pos) & USB_DIEPINT_N_DIEP_IN_T_N_IN_TKN_TXFEMP_Msk) /*!< DIEP_IN_T_N_IN_TKN_TXFEMP Set Value */
#define USB_DIEPINT_N_DIEP_IN_T_N_IN_TKN_TXFEMP_Get(x) (((uint32_t) (x) & USB_DIEPINT_N_DIEP_IN_T_N_IN_TKN_TXFEMP_Msk) >> USB_DIEPINT_N_DIEP_IN_T_N_IN_TKN_TXFEMP_Pos) /*!< DIEP_IN_T_N_IN_TKN_TXFEMP Get Value */


#define USB_DIEPINT_N_DIEP_IN_T_N_TIME_OUT_Pos    (3U)                                                                        /*!< DIEP_IN_T_N_TIME_OUT Postion   */ 
#define USB_DIEPINT_N_DIEP_IN_T_N_TIME_OUT_Msk    (0x1U << USB_DIEPINT_N_DIEP_IN_T_N_TIME_OUT_Pos)                            /*!< DIEP_IN_T_N_TIME_OUT Mask      */
#define USB_DIEPINT_N_DIEP_IN_T_N_TIME_OUT_Set(x) (((uint32_t) (x) << USB_DIEPINT_N_DIEP_IN_T_N_TIME_OUT_Pos) & USB_DIEPINT_N_DIEP_IN_T_N_TIME_OUT_Msk) /*!< DIEP_IN_T_N_TIME_OUT Set Value */
#define USB_DIEPINT_N_DIEP_IN_T_N_TIME_OUT_Get(x) (((uint32_t) (x) & USB_DIEPINT_N_DIEP_IN_T_N_TIME_OUT_Msk) >> USB_DIEPINT_N_DIEP_IN_T_N_TIME_OUT_Pos) /*!< DIEP_IN_T_N_TIME_OUT Get Value */


#define USB_DIEPINT_N_DIEP_IN_T_N_AHB_ERR_Pos    (2U)                                                                        /*!< DIEP_IN_T_N_AHB_ERR Postion   */ 
#define USB_DIEPINT_N_DIEP_IN_T_N_AHB_ERR_Msk    (0x1U << USB_DIEPINT_N_DIEP_IN_T_N_AHB_ERR_Pos)                             /*!< DIEP_IN_T_N_AHB_ERR Mask      */
#define USB_DIEPINT_N_DIEP_IN_T_N_AHB_ERR_Set(x) (((uint32_t) (x) << USB_DIEPINT_N_DIEP_IN_T_N_AHB_ERR_Pos) & USB_DIEPINT_N_DIEP_IN_T_N_AHB_ERR_Msk) /*!< DIEP_IN_T_N_AHB_ERR Set Value */
#define USB_DIEPINT_N_DIEP_IN_T_N_AHB_ERR_Get(x) (((uint32_t) (x) & USB_DIEPINT_N_DIEP_IN_T_N_AHB_ERR_Msk) >> USB_DIEPINT_N_DIEP_IN_T_N_AHB_ERR_Pos) /*!< DIEP_IN_T_N_AHB_ERR Get Value */


#define USB_DIEPINT_N_DIEP_IN_T_N_EP_DISBLD_Pos    (1U)                                                                        /*!< DIEP_IN_T_N_EP_DISBLD Postion   */ 
#define USB_DIEPINT_N_DIEP_IN_T_N_EP_DISBLD_Msk    (0x1U << USB_DIEPINT_N_DIEP_IN_T_N_EP_DISBLD_Pos)                           /*!< DIEP_IN_T_N_EP_DISBLD Mask      */
#define USB_DIEPINT_N_DIEP_IN_T_N_EP_DISBLD_Set(x) (((uint32_t) (x) << USB_DIEPINT_N_DIEP_IN_T_N_EP_DISBLD_Pos) & USB_DIEPINT_N_DIEP_IN_T_N_EP_DISBLD_Msk) /*!< DIEP_IN_T_N_EP_DISBLD Set Value */
#define USB_DIEPINT_N_DIEP_IN_T_N_EP_DISBLD_Get(x) (((uint32_t) (x) & USB_DIEPINT_N_DIEP_IN_T_N_EP_DISBLD_Msk) >> USB_DIEPINT_N_DIEP_IN_T_N_EP_DISBLD_Pos) /*!< DIEP_IN_T_N_EP_DISBLD Get Value */


#define USB_DIEPINT_N_DIEP_IN_T_N_XFER_COMPL_Pos    (0U)                                                                        /*!< DIEP_IN_T_N_XFER_COMPL Postion   */ 
#define USB_DIEPINT_N_DIEP_IN_T_N_XFER_COMPL_Msk    (0x1U << USB_DIEPINT_N_DIEP_IN_T_N_XFER_COMPL_Pos)                          /*!< DIEP_IN_T_N_XFER_COMPL Mask      */
#define USB_DIEPINT_N_DIEP_IN_T_N_XFER_COMPL_Set(x) (((uint32_t) (x) << USB_DIEPINT_N_DIEP_IN_T_N_XFER_COMPL_Pos) & USB_DIEPINT_N_DIEP_IN_T_N_XFER_COMPL_Msk) /*!< DIEP_IN_T_N_XFER_COMPL Set Value */
#define USB_DIEPINT_N_DIEP_IN_T_N_XFER_COMPL_Get(x) (((uint32_t) (x) & USB_DIEPINT_N_DIEP_IN_T_N_XFER_COMPL_Msk) >> USB_DIEPINT_N_DIEP_IN_T_N_XFER_COMPL_Pos) /*!< DIEP_IN_T_N_XFER_COMPL Get Value */


/* DIEPTSIZ_N bitfield */
#define USB_DIEPTSIZ_N_MC_Pos    (29U)                                                                       /*!< MC Postion   */ 
#define USB_DIEPTSIZ_N_MC_Msk    (0x3U << USB_DIEPTSIZ_N_MC_Pos)                                             /*!< MC Mask      */
#define USB_DIEPTSIZ_N_MC_Set(x) (((uint32_t) (x) << USB_DIEPTSIZ_N_MC_Pos) & USB_DIEPTSIZ_N_MC_Msk)         /*!< MC Set Value */
#define USB_DIEPTSIZ_N_MC_Get(x) (((uint32_t) (x) & USB_DIEPTSIZ_N_MC_Msk) >> USB_DIEPTSIZ_N_MC_Pos)         /*!< MC Get Value */


#define USB_DIEPTSIZ_N_DIEP_TSIZ_N_PKT_CNT_Pos    (19U)                                                                       /*!< DIEP_TSIZ_N_PKT_CNT Postion   */ 
#define USB_DIEPTSIZ_N_DIEP_TSIZ_N_PKT_CNT_Msk    (0x3ffU << USB_DIEPTSIZ_N_DIEP_TSIZ_N_PKT_CNT_Pos)                          /*!< DIEP_TSIZ_N_PKT_CNT Mask      */
#define USB_DIEPTSIZ_N_DIEP_TSIZ_N_PKT_CNT_Set(x) (((uint32_t) (x) << USB_DIEPTSIZ_N_DIEP_TSIZ_N_PKT_CNT_Pos) & USB_DIEPTSIZ_N_DIEP_TSIZ_N_PKT_CNT_Msk) /*!< DIEP_TSIZ_N_PKT_CNT Set Value */
#define USB_DIEPTSIZ_N_DIEP_TSIZ_N_PKT_CNT_Get(x) (((uint32_t) (x) & USB_DIEPTSIZ_N_DIEP_TSIZ_N_PKT_CNT_Msk) >> USB_DIEPTSIZ_N_DIEP_TSIZ_N_PKT_CNT_Pos) /*!< DIEP_TSIZ_N_PKT_CNT Get Value */


#define USB_DIEPTSIZ_N_DIEP_TSIZ_N_XFER_SIZE_Pos    (0U)                                                                        /*!< DIEP_TSIZ_N_XFER_SIZE Postion   */ 
//#define USB_DIEPTSIZ_N_DIEP_TSIZ_N_XFER_SIZE_Msk    (0x7FFFFUL << USB_DIEPTSIZ_N_DIEP_TSIZ_N_XFER_SIZE_Pos)                        /*!< DIEP_TSIZ_N_XFER_SIZE Mask      */
#define USB_DIEPTSIZ_N_DIEP_TSIZ_N_XFER_SIZE_Msk    (0x3ffU << USB_DIEPTSIZ_N_DIEP_TSIZ_N_XFER_SIZE_Pos)                        /*!< DIEP_TSIZ_N_XFER_SIZE Mask      */

#define USB_DIEPTSIZ_N_DIEP_TSIZ_N_XFER_SIZE_Set(x) (((uint32_t) (x) << USB_DIEPTSIZ_N_DIEP_TSIZ_N_XFER_SIZE_Pos) & USB_DIEPTSIZ_N_DIEP_TSIZ_N_XFER_SIZE_Msk) /*!< DIEP_TSIZ_N_XFER_SIZE Set Value */
#define USB_DIEPTSIZ_N_DIEP_TSIZ_N_XFER_SIZE_Get(x) (((uint32_t) (x) & USB_DIEPTSIZ_N_DIEP_TSIZ_N_XFER_SIZE_Msk) >> USB_DIEPTSIZ_N_DIEP_TSIZ_N_XFER_SIZE_Pos) /*!< DIEP_TSIZ_N_XFER_SIZE Get Value */


/* DIEPDMA_N bitfield */
#define USB_DIEPDMA_N_DIEP_DMA_N_DMA_ADDR_Pos    (0U)                                                                        /*!< DIEP_DMA_N_DMA_ADDR Postion   */ 
#define USB_DIEPDMA_N_DIEP_DMA_N_DMA_ADDR_Msk    (0xffffffffU << USB_DIEPDMA_N_DIEP_DMA_N_DMA_ADDR_Pos)                      /*!< DIEP_DMA_N_DMA_ADDR Mask      */
#define USB_DIEPDMA_N_DIEP_DMA_N_DMA_ADDR_Set(x) (((uint32_t) (x) << USB_DIEPDMA_N_DIEP_DMA_N_DMA_ADDR_Pos) & USB_DIEPDMA_N_DIEP_DMA_N_DMA_ADDR_Msk) /*!< DIEP_DMA_N_DMA_ADDR Set Value */
#define USB_DIEPDMA_N_DIEP_DMA_N_DMA_ADDR_Get(x) (((uint32_t) (x) & USB_DIEPDMA_N_DIEP_DMA_N_DMA_ADDR_Msk) >> USB_DIEPDMA_N_DIEP_DMA_N_DMA_ADDR_Pos) /*!< DIEP_DMA_N_DMA_ADDR Get Value */


/* DTXFSTS_N bitfield */
#define USB_DTXFSTS_N_IN_EP_TXF_SPC_AVAIL_Pos    (0U)                                                                        /*!< IN_EP_TXF_SPC_AVAIL Postion   */ 
#define USB_DTXFSTS_N_IN_EP_TXF_SPC_AVAIL_Msk    (0xffffU << USB_DTXFSTS_N_IN_EP_TXF_SPC_AVAIL_Pos)                          /*!< IN_EP_TXF_SPC_AVAIL Mask      */
#define USB_DTXFSTS_N_IN_EP_TXF_SPC_AVAIL_Set(x) (((uint32_t) (x) << USB_DTXFSTS_N_IN_EP_TXF_SPC_AVAIL_Pos) & USB_DTXFSTS_N_IN_EP_TXF_SPC_AVAIL_Msk) /*!< IN_EP_TXF_SPC_AVAIL Set Value */
#define USB_DTXFSTS_N_IN_EP_TXF_SPC_AVAIL_Get(x) (((uint32_t) (x) & USB_DTXFSTS_N_IN_EP_TXF_SPC_AVAIL_Msk) >> USB_DTXFSTS_N_IN_EP_TXF_SPC_AVAIL_Pos) /*!< IN_EP_TXF_SPC_AVAIL Get Value */


/* DIEPDMAB_N bitfield */
#define USB_DIEPDMAB_N_DIEP_DMA_B_N_DMA_BUFFER_ADDR_Pos    (0U)                                                                        /*!< DIEP_DMA_B_N_DMA_BUFFER_ADDR Postion   */ 
#define USB_DIEPDMAB_N_DIEP_DMA_B_N_DMA_BUFFER_ADDR_Msk    (0xffffffffU << USB_DIEPDMAB_N_DIEP_DMA_B_N_DMA_BUFFER_ADDR_Pos)            /*!< DIEP_DMA_B_N_DMA_BUFFER_ADDR Mask      */
#define USB_DIEPDMAB_N_DIEP_DMA_B_N_DMA_BUFFER_ADDR_Set(x) (((uint32_t) (x) << USB_DIEPDMAB_N_DIEP_DMA_B_N_DMA_BUFFER_ADDR_Pos) & USB_DIEPDMAB_N_DIEP_DMA_B_N_DMA_BUFFER_ADDR_Msk) /*!< DIEP_DMA_B_N_DMA_BUFFER_ADDR Set Value */
#define USB_DIEPDMAB_N_DIEP_DMA_B_N_DMA_BUFFER_ADDR_Get(x) (((uint32_t) (x) & USB_DIEPDMAB_N_DIEP_DMA_B_N_DMA_BUFFER_ADDR_Msk) >> USB_DIEPDMAB_N_DIEP_DMA_B_N_DMA_BUFFER_ADDR_Pos) /*!< DIEP_DMA_B_N_DMA_BUFFER_ADDR Get Value */


/* DOEPCTL_N bitfield */
#define USB_DOEPCTL_N_DOEP_CTL_N_EP_ENA_Pos    (31U)                                                                       /*!< DOEP_CTL_N_EP_ENA Postion   */ 
#define USB_DOEPCTL_N_DOEP_CTL_N_EP_ENA_Msk    (0x1U << USB_DOEPCTL_N_DOEP_CTL_N_EP_ENA_Pos)                               /*!< DOEP_CTL_N_EP_ENA Mask      */
#define USB_DOEPCTL_N_DOEP_CTL_N_EP_ENA_Set(x) (((uint32_t) (x) << USB_DOEPCTL_N_DOEP_CTL_N_EP_ENA_Pos) & USB_DOEPCTL_N_DOEP_CTL_N_EP_ENA_Msk) /*!< DOEP_CTL_N_EP_ENA Set Value */
#define USB_DOEPCTL_N_DOEP_CTL_N_EP_ENA_Get(x) (((uint32_t) (x) & USB_DOEPCTL_N_DOEP_CTL_N_EP_ENA_Msk) >> USB_DOEPCTL_N_DOEP_CTL_N_EP_ENA_Pos) /*!< DOEP_CTL_N_EP_ENA Get Value */


#define USB_DOEPCTL_N_DOEP_CTL_N_EP_DIS_Pos    (30U)                                                                       /*!< DOEP_CTL_N_EP_DIS Postion   */ 
#define USB_DOEPCTL_N_DOEP_CTL_N_EP_DIS_Msk    (0x1U << USB_DOEPCTL_N_DOEP_CTL_N_EP_DIS_Pos)                               /*!< DOEP_CTL_N_EP_DIS Mask      */
#define USB_DOEPCTL_N_DOEP_CTL_N_EP_DIS_Set(x) (((uint32_t) (x) << USB_DOEPCTL_N_DOEP_CTL_N_EP_DIS_Pos) & USB_DOEPCTL_N_DOEP_CTL_N_EP_DIS_Msk) /*!< DOEP_CTL_N_EP_DIS Set Value */
#define USB_DOEPCTL_N_DOEP_CTL_N_EP_DIS_Get(x) (((uint32_t) (x) & USB_DOEPCTL_N_DOEP_CTL_N_EP_DIS_Msk) >> USB_DOEPCTL_N_DOEP_CTL_N_EP_DIS_Pos) /*!< DOEP_CTL_N_EP_DIS Get Value */


#define USB_DOEPCTL_N_DOEP_CTL_N_SET_D1PID_Pos    (29U)                                                                       /*!< DOEP_CTL_N_SET_D1PID Postion   */ 
#define USB_DOEPCTL_N_DOEP_CTL_N_SET_D1PID_Msk    (0x1U << USB_DOEPCTL_N_DOEP_CTL_N_SET_D1PID_Pos)                            /*!< DOEP_CTL_N_SET_D1PID Mask      */
#define USB_DOEPCTL_N_DOEP_CTL_N_SET_D1PID_Set(x) (((uint32_t) (x) << USB_DOEPCTL_N_DOEP_CTL_N_SET_D1PID_Pos) & USB_DOEPCTL_N_DOEP_CTL_N_SET_D1PID_Msk) /*!< DOEP_CTL_N_SET_D1PID Set Value */
#define USB_DOEPCTL_N_DOEP_CTL_N_SET_D1PID_Get(x) (((uint32_t) (x) & USB_DOEPCTL_N_DOEP_CTL_N_SET_D1PID_Msk) >> USB_DOEPCTL_N_DOEP_CTL_N_SET_D1PID_Pos) /*!< DOEP_CTL_N_SET_D1PID Get Value */


#define USB_DOEPCTL_N_DOEP_CTL_N_SET_D0PID_Pos    (28U)                                                                       /*!< DOEP_CTL_N_SET_D0PID Postion   */ 
#define USB_DOEPCTL_N_DOEP_CTL_N_SET_D0PID_Msk    (0x1U << USB_DOEPCTL_N_DOEP_CTL_N_SET_D0PID_Pos)                            /*!< DOEP_CTL_N_SET_D0PID Mask      */
#define USB_DOEPCTL_N_DOEP_CTL_N_SET_D0PID_Set(x) (((uint32_t) (x) << USB_DOEPCTL_N_DOEP_CTL_N_SET_D0PID_Pos) & USB_DOEPCTL_N_DOEP_CTL_N_SET_D0PID_Msk) /*!< DOEP_CTL_N_SET_D0PID Set Value */
#define USB_DOEPCTL_N_DOEP_CTL_N_SET_D0PID_Get(x) (((uint32_t) (x) & USB_DOEPCTL_N_DOEP_CTL_N_SET_D0PID_Msk) >> USB_DOEPCTL_N_DOEP_CTL_N_SET_D0PID_Pos) /*!< DOEP_CTL_N_SET_D0PID Get Value */


#define USB_DOEPCTL_N_DOEP_CTL_N_SNAK_Pos    (27U)                                                                       /*!< DOEP_CTL_N_SNAK Postion   */ 
#define USB_DOEPCTL_N_DOEP_CTL_N_SNAK_Msk    (0x1U << USB_DOEPCTL_N_DOEP_CTL_N_SNAK_Pos)                                 /*!< DOEP_CTL_N_SNAK Mask      */
#define USB_DOEPCTL_N_DOEP_CTL_N_SNAK_Set(x) (((uint32_t) (x) << USB_DOEPCTL_N_DOEP_CTL_N_SNAK_Pos) & USB_DOEPCTL_N_DOEP_CTL_N_SNAK_Msk) /*!< DOEP_CTL_N_SNAK Set Value */
#define USB_DOEPCTL_N_DOEP_CTL_N_SNAK_Get(x) (((uint32_t) (x) & USB_DOEPCTL_N_DOEP_CTL_N_SNAK_Msk) >> USB_DOEPCTL_N_DOEP_CTL_N_SNAK_Pos) /*!< DOEP_CTL_N_SNAK Get Value */


#define USB_DOEPCTL_N_DOEP_CTL_N_CNAK_Pos    (26U)                                                                       /*!< DOEP_CTL_N_CNAK Postion   */ 
#define USB_DOEPCTL_N_DOEP_CTL_N_CNAK_Msk    (0x1U << USB_DOEPCTL_N_DOEP_CTL_N_CNAK_Pos)                                 /*!< DOEP_CTL_N_CNAK Mask      */
#define USB_DOEPCTL_N_DOEP_CTL_N_CNAK_Set(x) (((uint32_t) (x) << USB_DOEPCTL_N_DOEP_CTL_N_CNAK_Pos) & USB_DOEPCTL_N_DOEP_CTL_N_CNAK_Msk) /*!< DOEP_CTL_N_CNAK Set Value */
#define USB_DOEPCTL_N_DOEP_CTL_N_CNAK_Get(x) (((uint32_t) (x) & USB_DOEPCTL_N_DOEP_CTL_N_CNAK_Msk) >> USB_DOEPCTL_N_DOEP_CTL_N_CNAK_Pos) /*!< DOEP_CTL_N_CNAK Get Value */


#define USB_DOEPCTL_N_DOEP_CTL_N_STALL_Pos    (21U)                                                                       /*!< DOEP_CTL_N_STALL Postion   */ 
#define USB_DOEPCTL_N_DOEP_CTL_N_STALL_Msk    (0x1U << USB_DOEPCTL_N_DOEP_CTL_N_STALL_Pos)                                /*!< DOEP_CTL_N_STALL Mask      */
#define USB_DOEPCTL_N_DOEP_CTL_N_STALL_Set(x) (((uint32_t) (x) << USB_DOEPCTL_N_DOEP_CTL_N_STALL_Pos) & USB_DOEPCTL_N_DOEP_CTL_N_STALL_Msk) /*!< DOEP_CTL_N_STALL Set Value */
#define USB_DOEPCTL_N_DOEP_CTL_N_STALL_Get(x) (((uint32_t) (x) & USB_DOEPCTL_N_DOEP_CTL_N_STALL_Msk) >> USB_DOEPCTL_N_DOEP_CTL_N_STALL_Pos) /*!< DOEP_CTL_N_STALL Get Value */


#define USB_DOEPCTL_N_DOEP_CTL_N_SNP_Pos    (20U)                                                                       /*!< DOEP_CTL_N_SNP Postion   */ 
#define USB_DOEPCTL_N_DOEP_CTL_N_SNP_Msk    (0x1U << USB_DOEPCTL_N_DOEP_CTL_N_SNP_Pos)                                  /*!< DOEP_CTL_N_SNP Mask      */
#define USB_DOEPCTL_N_DOEP_CTL_N_SNP_Set(x) (((uint32_t) (x) << USB_DOEPCTL_N_DOEP_CTL_N_SNP_Pos) & USB_DOEPCTL_N_DOEP_CTL_N_SNP_Msk) /*!< DOEP_CTL_N_SNP Set Value */
#define USB_DOEPCTL_N_DOEP_CTL_N_SNP_Get(x) (((uint32_t) (x) & USB_DOEPCTL_N_DOEP_CTL_N_SNP_Msk) >> USB_DOEPCTL_N_DOEP_CTL_N_SNP_Pos) /*!< DOEP_CTL_N_SNP Get Value */


#define USB_DOEPCTL_N_DOEP_CTL_N_EP_TYPE_Pos    (18U)                                                                       /*!< DOEP_CTL_N_EP_TYPE Postion   */ 
#define USB_DOEPCTL_N_DOEP_CTL_N_EP_TYPE_Msk    (0x3U << USB_DOEPCTL_N_DOEP_CTL_N_EP_TYPE_Pos)                              /*!< DOEP_CTL_N_EP_TYPE Mask      */
#define USB_DOEPCTL_N_DOEP_CTL_N_EP_TYPE_Set(x) (((uint32_t) (x) << USB_DOEPCTL_N_DOEP_CTL_N_EP_TYPE_Pos) & USB_DOEPCTL_N_DOEP_CTL_N_EP_TYPE_Msk) /*!< DOEP_CTL_N_EP_TYPE Set Value */
#define USB_DOEPCTL_N_DOEP_CTL_N_EP_TYPE_Get(x) (((uint32_t) (x) & USB_DOEPCTL_N_DOEP_CTL_N_EP_TYPE_Msk) >> USB_DOEPCTL_N_DOEP_CTL_N_EP_TYPE_Pos) /*!< DOEP_CTL_N_EP_TYPE Get Value */


#define USB_DOEPCTL_N_DOEP_CTL_N_NAKSTS_Pos    (17U)                                                                       /*!< DOEP_CTL_N_NAKSTS Postion   */ 
#define USB_DOEPCTL_N_DOEP_CTL_N_NAKSTS_Msk    (0x1U << USB_DOEPCTL_N_DOEP_CTL_N_NAKSTS_Pos)                               /*!< DOEP_CTL_N_NAKSTS Mask      */
#define USB_DOEPCTL_N_DOEP_CTL_N_NAKSTS_Set(x) (((uint32_t) (x) << USB_DOEPCTL_N_DOEP_CTL_N_NAKSTS_Pos) & USB_DOEPCTL_N_DOEP_CTL_N_NAKSTS_Msk) /*!< DOEP_CTL_N_NAKSTS Set Value */
#define USB_DOEPCTL_N_DOEP_CTL_N_NAKSTS_Get(x) (((uint32_t) (x) & USB_DOEPCTL_N_DOEP_CTL_N_NAKSTS_Msk) >> USB_DOEPCTL_N_DOEP_CTL_N_NAKSTS_Pos) /*!< DOEP_CTL_N_NAKSTS Get Value */


#define USB_DOEPCTL_N_DOEP_CTL_N_DPID_Pos    (16U)                                                                       /*!< DOEP_CTL_N_DPID Postion   */ 
#define USB_DOEPCTL_N_DOEP_CTL_N_DPID_Msk    (0x1U << USB_DOEPCTL_N_DOEP_CTL_N_DPID_Pos)                                 /*!< DOEP_CTL_N_DPID Mask      */
#define USB_DOEPCTL_N_DOEP_CTL_N_DPID_Set(x) (((uint32_t) (x) << USB_DOEPCTL_N_DOEP_CTL_N_DPID_Pos) & USB_DOEPCTL_N_DOEP_CTL_N_DPID_Msk) /*!< DOEP_CTL_N_DPID Set Value */
#define USB_DOEPCTL_N_DOEP_CTL_N_DPID_Get(x) (((uint32_t) (x) & USB_DOEPCTL_N_DOEP_CTL_N_DPID_Msk) >> USB_DOEPCTL_N_DOEP_CTL_N_DPID_Pos) /*!< DOEP_CTL_N_DPID Get Value */


#define USB_DOEPCTL_N_DOEP_CTL_N_USB_ACT_EP_Pos    (15U)                                                                       /*!< DOEP_CTL_N_USB_ACT_EP Postion   */ 
#define USB_DOEPCTL_N_DOEP_CTL_N_USB_ACT_EP_Msk    (0x1U << USB_DOEPCTL_N_DOEP_CTL_N_USB_ACT_EP_Pos)                           /*!< DOEP_CTL_N_USB_ACT_EP Mask      */
#define USB_DOEPCTL_N_DOEP_CTL_N_USB_ACT_EP_Set(x) (((uint32_t) (x) << USB_DOEPCTL_N_DOEP_CTL_N_USB_ACT_EP_Pos) & USB_DOEPCTL_N_DOEP_CTL_N_USB_ACT_EP_Msk) /*!< DOEP_CTL_N_USB_ACT_EP Set Value */
#define USB_DOEPCTL_N_DOEP_CTL_N_USB_ACT_EP_Get(x) (((uint32_t) (x) & USB_DOEPCTL_N_DOEP_CTL_N_USB_ACT_EP_Msk) >> USB_DOEPCTL_N_DOEP_CTL_N_USB_ACT_EP_Pos) /*!< DOEP_CTL_N_USB_ACT_EP Get Value */


#define USB_DOEPCTL_N_DOEP_CTL_N_MPS_Pos    (0U)                                                                        /*!< DOEP_CTL_N_MPS Postion   */ 
#define USB_DOEPCTL_N_DOEP_CTL_N_MPS_Msk    (0x7ffU << USB_DOEPCTL_N_DOEP_CTL_N_MPS_Pos)                                /*!< DOEP_CTL_N_MPS Mask      */
#define USB_DOEPCTL_N_DOEP_CTL_N_MPS_Set(x) (((uint32_t) (x) << USB_DOEPCTL_N_DOEP_CTL_N_MPS_Pos) & USB_DOEPCTL_N_DOEP_CTL_N_MPS_Msk) /*!< DOEP_CTL_N_MPS Set Value */
#define USB_DOEPCTL_N_DOEP_CTL_N_MPS_Get(x) (((uint32_t) (x) & USB_DOEPCTL_N_DOEP_CTL_N_MPS_Msk) >> USB_DOEPCTL_N_DOEP_CTL_N_MPS_Pos) /*!< DOEP_CTL_N_MPS Get Value */


/* DOEPINT_N bitfield */
#define USB_DOEPINT_N_DOEP_IN_T_N_STUP_PKT_RCVD_Pos    (15U)                                                                       /*!< DOEP_IN_T_N_STUP_PKT_RCVD Postion   */ 
#define USB_DOEPINT_N_DOEP_IN_T_N_STUP_PKT_RCVD_Msk    (0x1U << USB_DOEPINT_N_DOEP_IN_T_N_STUP_PKT_RCVD_Pos)                       /*!< DOEP_IN_T_N_STUP_PKT_RCVD Mask      */
#define USB_DOEPINT_N_DOEP_IN_T_N_STUP_PKT_RCVD_Set(x) (((uint32_t) (x) << USB_DOEPINT_N_DOEP_IN_T_N_STUP_PKT_RCVD_Pos) & USB_DOEPINT_N_DOEP_IN_T_N_STUP_PKT_RCVD_Msk) /*!< DOEP_IN_T_N_STUP_PKT_RCVD Set Value */
#define USB_DOEPINT_N_DOEP_IN_T_N_STUP_PKT_RCVD_Get(x) (((uint32_t) (x) & USB_DOEPINT_N_DOEP_IN_T_N_STUP_PKT_RCVD_Msk) >> USB_DOEPINT_N_DOEP_IN_T_N_STUP_PKT_RCVD_Pos) /*!< DOEP_IN_T_N_STUP_PKT_RCVD Get Value */


#define USB_DOEPINT_N_DOEP_IN_T_N_NYETINTRPT_Pos    (14U)                                                                       /*!< DOEP_IN_T_N_NYETINTRPT Postion   */ 
#define USB_DOEPINT_N_DOEP_IN_T_N_NYETINTRPT_Msk    (0x1U << USB_DOEPINT_N_DOEP_IN_T_N_NYETINTRPT_Pos)                          /*!< DOEP_IN_T_N_NYETINTRPT Mask      */
#define USB_DOEPINT_N_DOEP_IN_T_N_NYETINTRPT_Set(x) (((uint32_t) (x) << USB_DOEPINT_N_DOEP_IN_T_N_NYETINTRPT_Pos) & USB_DOEPINT_N_DOEP_IN_T_N_NYETINTRPT_Msk) /*!< DOEP_IN_T_N_NYETINTRPT Set Value */
#define USB_DOEPINT_N_DOEP_IN_T_N_NYETINTRPT_Get(x) (((uint32_t) (x) & USB_DOEPINT_N_DOEP_IN_T_N_NYETINTRPT_Msk) >> USB_DOEPINT_N_DOEP_IN_T_N_NYETINTRPT_Pos) /*!< DOEP_IN_T_N_NYETINTRPT Get Value */


#define USB_DOEPINT_N_DOEP_IN_T_N_NAKINTRPT_Pos    (13U)                                                                       /*!< DOEP_IN_T_N_NAKINTRPT Postion   */ 
#define USB_DOEPINT_N_DOEP_IN_T_N_NAKINTRPT_Msk    (0x1U << USB_DOEPINT_N_DOEP_IN_T_N_NAKINTRPT_Pos)                           /*!< DOEP_IN_T_N_NAKINTRPT Mask      */
#define USB_DOEPINT_N_DOEP_IN_T_N_NAKINTRPT_Set(x) (((uint32_t) (x) << USB_DOEPINT_N_DOEP_IN_T_N_NAKINTRPT_Pos) & USB_DOEPINT_N_DOEP_IN_T_N_NAKINTRPT_Msk) /*!< DOEP_IN_T_N_NAKINTRPT Set Value */
#define USB_DOEPINT_N_DOEP_IN_T_N_NAKINTRPT_Get(x) (((uint32_t) (x) & USB_DOEPINT_N_DOEP_IN_T_N_NAKINTRPT_Msk) >> USB_DOEPINT_N_DOEP_IN_T_N_NAKINTRPT_Pos) /*!< DOEP_IN_T_N_NAKINTRPT Get Value */


#define USB_DOEPINT_N_DOEP_IN_T_N_BBLE_ERR_Pos    (12U)                                                                       /*!< DOEP_IN_T_N_BBLE_ERR Postion   */ 
#define USB_DOEPINT_N_DOEP_IN_T_N_BBLE_ERR_Msk    (0x1U << USB_DOEPINT_N_DOEP_IN_T_N_BBLE_ERR_Pos)                            /*!< DOEP_IN_T_N_BBLE_ERR Mask      */
#define USB_DOEPINT_N_DOEP_IN_T_N_BBLE_ERR_Set(x) (((uint32_t) (x) << USB_DOEPINT_N_DOEP_IN_T_N_BBLE_ERR_Pos) & USB_DOEPINT_N_DOEP_IN_T_N_BBLE_ERR_Msk) /*!< DOEP_IN_T_N_BBLE_ERR Set Value */
#define USB_DOEPINT_N_DOEP_IN_T_N_BBLE_ERR_Get(x) (((uint32_t) (x) & USB_DOEPINT_N_DOEP_IN_T_N_BBLE_ERR_Msk) >> USB_DOEPINT_N_DOEP_IN_T_N_BBLE_ERR_Pos) /*!< DOEP_IN_T_N_BBLE_ERR Get Value */


#define USB_DOEPINT_N_DOEP_IN_T_N_PKT_DRP_STS_Pos    (11U)                                                                       /*!< DOEP_IN_T_N_PKT_DRP_STS Postion   */ 
#define USB_DOEPINT_N_DOEP_IN_T_N_PKT_DRP_STS_Msk    (0x1U << USB_DOEPINT_N_DOEP_IN_T_N_PKT_DRP_STS_Pos)                         /*!< DOEP_IN_T_N_PKT_DRP_STS Mask      */
#define USB_DOEPINT_N_DOEP_IN_T_N_PKT_DRP_STS_Set(x) (((uint32_t) (x) << USB_DOEPINT_N_DOEP_IN_T_N_PKT_DRP_STS_Pos) & USB_DOEPINT_N_DOEP_IN_T_N_PKT_DRP_STS_Msk) /*!< DOEP_IN_T_N_PKT_DRP_STS Set Value */
#define USB_DOEPINT_N_DOEP_IN_T_N_PKT_DRP_STS_Get(x) (((uint32_t) (x) & USB_DOEPINT_N_DOEP_IN_T_N_PKT_DRP_STS_Msk) >> USB_DOEPINT_N_DOEP_IN_T_N_PKT_DRP_STS_Pos) /*!< DOEP_IN_T_N_PKT_DRP_STS Get Value */


#define USB_DOEPINT_N_DOEP_IN_T_N_BNAINTR_Pos    (9U)                                                                        /*!< DOEP_IN_T_N_BNAINTR Postion   */ 
#define USB_DOEPINT_N_DOEP_IN_T_N_BNAINTR_Msk    (0x1U << USB_DOEPINT_N_DOEP_IN_T_N_BNAINTR_Pos)                             /*!< DOEP_IN_T_N_BNAINTR Mask      */
#define USB_DOEPINT_N_DOEP_IN_T_N_BNAINTR_Set(x) (((uint32_t) (x) << USB_DOEPINT_N_DOEP_IN_T_N_BNAINTR_Pos) & USB_DOEPINT_N_DOEP_IN_T_N_BNAINTR_Msk) /*!< DOEP_IN_T_N_BNAINTR Set Value */
#define USB_DOEPINT_N_DOEP_IN_T_N_BNAINTR_Get(x) (((uint32_t) (x) & USB_DOEPINT_N_DOEP_IN_T_N_BNAINTR_Msk) >> USB_DOEPINT_N_DOEP_IN_T_N_BNAINTR_Pos) /*!< DOEP_IN_T_N_BNAINTR Get Value */


#define USB_DOEPINT_N_DOEP_IN_T_N_OUT_PKT_ERR_Pos    (8U)                                                                        /*!< DOEP_IN_T_N_OUT_PKT_ERR Postion   */ 
#define USB_DOEPINT_N_DOEP_IN_T_N_OUT_PKT_ERR_Msk    (0x1U << USB_DOEPINT_N_DOEP_IN_T_N_OUT_PKT_ERR_Pos)                         /*!< DOEP_IN_T_N_OUT_PKT_ERR Mask      */
#define USB_DOEPINT_N_DOEP_IN_T_N_OUT_PKT_ERR_Set(x) (((uint32_t) (x) << USB_DOEPINT_N_DOEP_IN_T_N_OUT_PKT_ERR_Pos) & USB_DOEPINT_N_DOEP_IN_T_N_OUT_PKT_ERR_Msk) /*!< DOEP_IN_T_N_OUT_PKT_ERR Set Value */
#define USB_DOEPINT_N_DOEP_IN_T_N_OUT_PKT_ERR_Get(x) (((uint32_t) (x) & USB_DOEPINT_N_DOEP_IN_T_N_OUT_PKT_ERR_Msk) >> USB_DOEPINT_N_DOEP_IN_T_N_OUT_PKT_ERR_Pos) /*!< DOEP_IN_T_N_OUT_PKT_ERR Get Value */


#define USB_DOEPINT_N_DOEP_IN_T_N_BACK2BACK_SETUP_Pos    (6U)                                                                        /*!< DOEP_IN_T_N_BACK2BACK_SETUP Postion   */ 
#define USB_DOEPINT_N_DOEP_IN_T_N_BACK2BACK_SETUP_Msk    (0x1U << USB_DOEPINT_N_DOEP_IN_T_N_BACK2BACK_SETUP_Pos)                     /*!< DOEP_IN_T_N_BACK2BACK_SETUP Mask      */
#define USB_DOEPINT_N_DOEP_IN_T_N_BACK2BACK_SETUP_Set(x) (((uint32_t) (x) << USB_DOEPINT_N_DOEP_IN_T_N_BACK2BACK_SETUP_Pos) & USB_DOEPINT_N_DOEP_IN_T_N_BACK2BACK_SETUP_Msk) /*!< DOEP_IN_T_N_BACK2BACK_SETUP Set Value */
#define USB_DOEPINT_N_DOEP_IN_T_N_BACK2BACK_SETUP_Get(x) (((uint32_t) (x) & USB_DOEPINT_N_DOEP_IN_T_N_BACK2BACK_SETUP_Msk) >> USB_DOEPINT_N_DOEP_IN_T_N_BACK2BACK_SETUP_Pos) /*!< DOEP_IN_T_N_BACK2BACK_SETUP Get Value */


#define USB_DOEPINT_N_DOEP_IN_T_N_STS_PHSE_RCVD_Pos    (5U)                                                                        /*!< DOEP_IN_T_N_STS_PHSE_RCVD Postion   */ 
#define USB_DOEPINT_N_DOEP_IN_T_N_STS_PHSE_RCVD_Msk    (0x1U << USB_DOEPINT_N_DOEP_IN_T_N_STS_PHSE_RCVD_Pos)                       /*!< DOEP_IN_T_N_STS_PHSE_RCVD Mask      */
#define USB_DOEPINT_N_DOEP_IN_T_N_STS_PHSE_RCVD_Set(x) (((uint32_t) (x) << USB_DOEPINT_N_DOEP_IN_T_N_STS_PHSE_RCVD_Pos) & USB_DOEPINT_N_DOEP_IN_T_N_STS_PHSE_RCVD_Msk) /*!< DOEP_IN_T_N_STS_PHSE_RCVD Set Value */
#define USB_DOEPINT_N_DOEP_IN_T_N_STS_PHSE_RCVD_Get(x) (((uint32_t) (x) & USB_DOEPINT_N_DOEP_IN_T_N_STS_PHSE_RCVD_Msk) >> USB_DOEPINT_N_DOEP_IN_T_N_STS_PHSE_RCVD_Pos) /*!< DOEP_IN_T_N_STS_PHSE_RCVD Get Value */


#define USB_DOEPINT_N_DOEP_IN_T_N_OUT_TKN_EP_DIS_Pos    (4U)                                                                        /*!< DOEP_IN_T_N_OUT_TKN_EP_DIS Postion   */ 
#define USB_DOEPINT_N_DOEP_IN_T_N_OUT_TKN_EP_DIS_Msk    (0x1U << USB_DOEPINT_N_DOEP_IN_T_N_OUT_TKN_EP_DIS_Pos)                      /*!< DOEP_IN_T_N_OUT_TKN_EP_DIS Mask      */
#define USB_DOEPINT_N_DOEP_IN_T_N_OUT_TKN_EP_DIS_Set(x) (((uint32_t) (x) << USB_DOEPINT_N_DOEP_IN_T_N_OUT_TKN_EP_DIS_Pos) & USB_DOEPINT_N_DOEP_IN_T_N_OUT_TKN_EP_DIS_Msk) /*!< DOEP_IN_T_N_OUT_TKN_EP_DIS Set Value */
#define USB_DOEPINT_N_DOEP_IN_T_N_OUT_TKN_EP_DIS_Get(x) (((uint32_t) (x) & USB_DOEPINT_N_DOEP_IN_T_N_OUT_TKN_EP_DIS_Msk) >> USB_DOEPINT_N_DOEP_IN_T_N_OUT_TKN_EP_DIS_Pos) /*!< DOEP_IN_T_N_OUT_TKN_EP_DIS Get Value */


#define USB_DOEPINT_N_DOEP_IN_T_N_SET_UP_Pos    (3U)                                                                        /*!< DOEP_IN_T_N_SET_UP Postion   */ 
#define USB_DOEPINT_N_DOEP_IN_T_N_SET_UP_Msk    (0x1U << USB_DOEPINT_N_DOEP_IN_T_N_SET_UP_Pos)                              /*!< DOEP_IN_T_N_SET_UP Mask      */
#define USB_DOEPINT_N_DOEP_IN_T_N_SET_UP_Set(x) (((uint32_t) (x) << USB_DOEPINT_N_DOEP_IN_T_N_SET_UP_Pos) & USB_DOEPINT_N_DOEP_IN_T_N_SET_UP_Msk) /*!< DOEP_IN_T_N_SET_UP Set Value */
#define USB_DOEPINT_N_DOEP_IN_T_N_SET_UP_Get(x) (((uint32_t) (x) & USB_DOEPINT_N_DOEP_IN_T_N_SET_UP_Msk) >> USB_DOEPINT_N_DOEP_IN_T_N_SET_UP_Pos) /*!< DOEP_IN_T_N_SET_UP Get Value */


#define USB_DOEPINT_N_DOEP_IN_T_N_AHB_ERR_Pos    (2U)                                                                        /*!< DOEP_IN_T_N_AHB_ERR Postion   */ 
#define USB_DOEPINT_N_DOEP_IN_T_N_AHB_ERR_Msk    (0x1U << USB_DOEPINT_N_DOEP_IN_T_N_AHB_ERR_Pos)                             /*!< DOEP_IN_T_N_AHB_ERR Mask      */
#define USB_DOEPINT_N_DOEP_IN_T_N_AHB_ERR_Set(x) (((uint32_t) (x) << USB_DOEPINT_N_DOEP_IN_T_N_AHB_ERR_Pos) & USB_DOEPINT_N_DOEP_IN_T_N_AHB_ERR_Msk) /*!< DOEP_IN_T_N_AHB_ERR Set Value */
#define USB_DOEPINT_N_DOEP_IN_T_N_AHB_ERR_Get(x) (((uint32_t) (x) & USB_DOEPINT_N_DOEP_IN_T_N_AHB_ERR_Msk) >> USB_DOEPINT_N_DOEP_IN_T_N_AHB_ERR_Pos) /*!< DOEP_IN_T_N_AHB_ERR Get Value */


#define USB_DOEPINT_N_DOEP_IN_T_N_EP_DISBLD_Pos    (1U)                                                                        /*!< DOEP_IN_T_N_EP_DISBLD Postion   */ 
#define USB_DOEPINT_N_DOEP_IN_T_N_EP_DISBLD_Msk    (0x1U << USB_DOEPINT_N_DOEP_IN_T_N_EP_DISBLD_Pos)                           /*!< DOEP_IN_T_N_EP_DISBLD Mask      */
#define USB_DOEPINT_N_DOEP_IN_T_N_EP_DISBLD_Set(x) (((uint32_t) (x) << USB_DOEPINT_N_DOEP_IN_T_N_EP_DISBLD_Pos) & USB_DOEPINT_N_DOEP_IN_T_N_EP_DISBLD_Msk) /*!< DOEP_IN_T_N_EP_DISBLD Set Value */
#define USB_DOEPINT_N_DOEP_IN_T_N_EP_DISBLD_Get(x) (((uint32_t) (x) & USB_DOEPINT_N_DOEP_IN_T_N_EP_DISBLD_Msk) >> USB_DOEPINT_N_DOEP_IN_T_N_EP_DISBLD_Pos) /*!< DOEP_IN_T_N_EP_DISBLD Get Value */


#define USB_DOEPINT_N_DOEP_IN_T_N_XFER_COMPL_Pos    (0U)                                                                        /*!< DOEP_IN_T_N_XFER_COMPL Postion   */ 
#define USB_DOEPINT_N_DOEP_IN_T_N_XFER_COMPL_Msk    (0x1U << USB_DOEPINT_N_DOEP_IN_T_N_XFER_COMPL_Pos)                          /*!< DOEP_IN_T_N_XFER_COMPL Mask      */
#define USB_DOEPINT_N_DOEP_IN_T_N_XFER_COMPL_Set(x) (((uint32_t) (x) << USB_DOEPINT_N_DOEP_IN_T_N_XFER_COMPL_Pos) & USB_DOEPINT_N_DOEP_IN_T_N_XFER_COMPL_Msk) /*!< DOEP_IN_T_N_XFER_COMPL Set Value */
#define USB_DOEPINT_N_DOEP_IN_T_N_XFER_COMPL_Get(x) (((uint32_t) (x) & USB_DOEPINT_N_DOEP_IN_T_N_XFER_COMPL_Msk) >> USB_DOEPINT_N_DOEP_IN_T_N_XFER_COMPL_Pos) /*!< DOEP_IN_T_N_XFER_COMPL Get Value */


/* DOEPTSIZ_N bitfield */
#define USB_DOEPTSIZ_N_RX_DPID_Pos    (29U)                                                                       /*!< RX_DPID Postion   */ 
#define USB_DOEPTSIZ_N_RX_DPID_Msk    (0x3U << USB_DOEPTSIZ_N_RX_DPID_Pos)                                        /*!< RX_DPID Mask      */
#define USB_DOEPTSIZ_N_RX_DPID_Set(x) (((uint32_t) (x) << USB_DOEPTSIZ_N_RX_DPID_Pos) & USB_DOEPTSIZ_N_RX_DPID_Msk) /*!< RX_DPID Set Value */
#define USB_DOEPTSIZ_N_RX_DPID_Get(x) (((uint32_t) (x) & USB_DOEPTSIZ_N_RX_DPID_Msk) >> USB_DOEPTSIZ_N_RX_DPID_Pos) /*!< RX_DPID Get Value */


#define USB_DOEPTSIZ_N_DOEP_TSIZ_N_PKT_CNT_Pos    (19U)                                                                       /*!< DOEP_TSIZ_N_PKT_CNT Postion   */ 
#define USB_DOEPTSIZ_N_DOEP_TSIZ_N_PKT_CNT_Msk    (0x3ffU << USB_DOEPTSIZ_N_DOEP_TSIZ_N_PKT_CNT_Pos)                          /*!< DOEP_TSIZ_N_PKT_CNT Mask      */
#define USB_DOEPTSIZ_N_DOEP_TSIZ_N_PKT_CNT_Set(x) (((uint32_t) (x) << USB_DOEPTSIZ_N_DOEP_TSIZ_N_PKT_CNT_Pos) & USB_DOEPTSIZ_N_DOEP_TSIZ_N_PKT_CNT_Msk) /*!< DOEP_TSIZ_N_PKT_CNT Set Value */
#define USB_DOEPTSIZ_N_DOEP_TSIZ_N_PKT_CNT_Get(x) (((uint32_t) (x) & USB_DOEPTSIZ_N_DOEP_TSIZ_N_PKT_CNT_Msk) >> USB_DOEPTSIZ_N_DOEP_TSIZ_N_PKT_CNT_Pos) /*!< DOEP_TSIZ_N_PKT_CNT Get Value */


#define USB_DOEPTSIZ_N_DOEP_TSIZ_N_XFER_SIZE_Pos    (0U)                                                                        /*!< DOEP_TSIZ_N_XFER_SIZE Postion   */ 
#define USB_DOEPTSIZ_N_DOEP_TSIZ_N_XFER_SIZE_Msk    (0x7ffffU << USB_DOEPTSIZ_N_DOEP_TSIZ_N_XFER_SIZE_Pos)                      /*!< DOEP_TSIZ_N_XFER_SIZE Mask      */
#define USB_DOEPTSIZ_N_DOEP_TSIZ_N_XFER_SIZE_Set(x) (((uint32_t) (x) << USB_DOEPTSIZ_N_DOEP_TSIZ_N_XFER_SIZE_Pos) & USB_DOEPTSIZ_N_DOEP_TSIZ_N_XFER_SIZE_Msk) /*!< DOEP_TSIZ_N_XFER_SIZE Set Value */
#define USB_DOEPTSIZ_N_DOEP_TSIZ_N_XFER_SIZE_Get(x) (((uint32_t) (x) & USB_DOEPTSIZ_N_DOEP_TSIZ_N_XFER_SIZE_Msk) >> USB_DOEPTSIZ_N_DOEP_TSIZ_N_XFER_SIZE_Pos) /*!< DOEP_TSIZ_N_XFER_SIZE Get Value */


/* DOEPDMA_N bitfield */
#define USB_DOEPDMA_N_DOEP_DMA_N_DMA_ADDR_Pos    (0U)                                                                        /*!< DOEP_DMA_N_DMA_ADDR Postion   */ 
#define USB_DOEPDMA_N_DOEP_DMA_N_DMA_ADDR_Msk    (0xffffffffU << USB_DOEPDMA_N_DOEP_DMA_N_DMA_ADDR_Pos)                      /*!< DOEP_DMA_N_DMA_ADDR Mask      */
#define USB_DOEPDMA_N_DOEP_DMA_N_DMA_ADDR_Set(x) (((uint32_t) (x) << USB_DOEPDMA_N_DOEP_DMA_N_DMA_ADDR_Pos) & USB_DOEPDMA_N_DOEP_DMA_N_DMA_ADDR_Msk) /*!< DOEP_DMA_N_DMA_ADDR Set Value */
#define USB_DOEPDMA_N_DOEP_DMA_N_DMA_ADDR_Get(x) (((uint32_t) (x) & USB_DOEPDMA_N_DOEP_DMA_N_DMA_ADDR_Msk) >> USB_DOEPDMA_N_DOEP_DMA_N_DMA_ADDR_Pos) /*!< DOEP_DMA_N_DMA_ADDR Get Value */


/* DOEPDMAB_N bitfield */
#define USB_DOEPDMAB_N_DOEP_DMA_B_N_DMA_BUFFER_ADDR_Pos    (0U)                                                                        /*!< DOEP_DMA_B_N_DMA_BUFFER_ADDR Postion   */ 
#define USB_DOEPDMAB_N_DOEP_DMA_B_N_DMA_BUFFER_ADDR_Msk    (0xffffffffU << USB_DOEPDMAB_N_DOEP_DMA_B_N_DMA_BUFFER_ADDR_Pos)            /*!< DOEP_DMA_B_N_DMA_BUFFER_ADDR Mask      */
#define USB_DOEPDMAB_N_DOEP_DMA_B_N_DMA_BUFFER_ADDR_Set(x) (((uint32_t) (x) << USB_DOEPDMAB_N_DOEP_DMA_B_N_DMA_BUFFER_ADDR_Pos) & USB_DOEPDMAB_N_DOEP_DMA_B_N_DMA_BUFFER_ADDR_Msk) /*!< DOEP_DMA_B_N_DMA_BUFFER_ADDR Set Value */
#define USB_DOEPDMAB_N_DOEP_DMA_B_N_DMA_BUFFER_ADDR_Get(x) (((uint32_t) (x) & USB_DOEPDMAB_N_DOEP_DMA_B_N_DMA_BUFFER_ADDR_Msk) >> USB_DOEPDMAB_N_DOEP_DMA_B_N_DMA_BUFFER_ADDR_Pos) /*!< DOEP_DMA_B_N_DMA_BUFFER_ADDR Get Value */


/* GOTGCTL bitfield */
#define USB_GOTGCTL_CUR_MOD_Pos    (21U)                                                                       /*!< CUR_MOD Postion   */ 
#define USB_GOTGCTL_CUR_MOD_Msk    (0x1U << USB_GOTGCTL_CUR_MOD_Pos)                                           /*!< CUR_MOD Mask      */
#define USB_GOTGCTL_CUR_MOD_Set(x) (((uint32_t) (x) << USB_GOTGCTL_CUR_MOD_Pos) & USB_GOTGCTL_CUR_MOD_Msk)     /*!< CUR_MOD Set Value */
#define USB_GOTGCTL_CUR_MOD_Get(x) (((uint32_t) (x) & USB_GOTGCTL_CUR_MOD_Msk) >> USB_GOTGCTL_CUR_MOD_Pos)     /*!< CUR_MOD Get Value */


#define USB_GOTGCTL_OTG_VER_Pos    (20U)                                                                       /*!< OTG_VER Postion   */ 
#define USB_GOTGCTL_OTG_VER_Msk    (0x1U << USB_GOTGCTL_OTG_VER_Pos)                                           /*!< OTG_VER Mask      */
#define USB_GOTGCTL_OTG_VER_Set(x) (((uint32_t) (x) << USB_GOTGCTL_OTG_VER_Pos) & USB_GOTGCTL_OTG_VER_Msk)     /*!< OTG_VER Set Value */
#define USB_GOTGCTL_OTG_VER_Get(x) (((uint32_t) (x) & USB_GOTGCTL_OTG_VER_Msk) >> USB_GOTGCTL_OTG_VER_Pos)     /*!< OTG_VER Get Value */


#define USB_GOTGCTL_BSES_VLD_Pos    (19U)                                                                       /*!< BSES_VLD Postion   */ 
#define USB_GOTGCTL_BSES_VLD_Msk    (0x1U << USB_GOTGCTL_BSES_VLD_Pos)                                          /*!< BSES_VLD Mask      */
#define USB_GOTGCTL_BSES_VLD_Set(x) (((uint32_t) (x) << USB_GOTGCTL_BSES_VLD_Pos) & USB_GOTGCTL_BSES_VLD_Msk)   /*!< BSES_VLD Set Value */
#define USB_GOTGCTL_BSES_VLD_Get(x) (((uint32_t) (x) & USB_GOTGCTL_BSES_VLD_Msk) >> USB_GOTGCTL_BSES_VLD_Pos)   /*!< BSES_VLD Get Value */


#define USB_GOTGCTL_ASES_VLD_Pos    (18U)                                                                       /*!< ASES_VLD Postion   */ 
#define USB_GOTGCTL_ASES_VLD_Msk    (0x1U << USB_GOTGCTL_ASES_VLD_Pos)                                          /*!< ASES_VLD Mask      */
#define USB_GOTGCTL_ASES_VLD_Set(x) (((uint32_t) (x) << USB_GOTGCTL_ASES_VLD_Pos) & USB_GOTGCTL_ASES_VLD_Msk)   /*!< ASES_VLD Set Value */
#define USB_GOTGCTL_ASES_VLD_Get(x) (((uint32_t) (x) & USB_GOTGCTL_ASES_VLD_Msk) >> USB_GOTGCTL_ASES_VLD_Pos)   /*!< ASES_VLD Get Value */


#define USB_GOTGCTL_DBNC_TIME_Pos    (17U)                                                                       /*!< DBNC_TIME Postion   */ 
#define USB_GOTGCTL_DBNC_TIME_Msk    (0x1U << USB_GOTGCTL_DBNC_TIME_Pos)                                         /*!< DBNC_TIME Mask      */
#define USB_GOTGCTL_DBNC_TIME_Set(x) (((uint32_t) (x) << USB_GOTGCTL_DBNC_TIME_Pos) & USB_GOTGCTL_DBNC_TIME_Msk) /*!< DBNC_TIME Set Value */
#define USB_GOTGCTL_DBNC_TIME_Get(x) (((uint32_t) (x) & USB_GOTGCTL_DBNC_TIME_Msk) >> USB_GOTGCTL_DBNC_TIME_Pos) /*!< DBNC_TIME Get Value */


#define USB_GOTGCTL_CON_ID_STS_Pos    (16U)                                                                       /*!< CON_ID_STS Postion   */ 
#define USB_GOTGCTL_CON_ID_STS_Msk    (0x1U << USB_GOTGCTL_CON_ID_STS_Pos)                                        /*!< CON_ID_STS Mask      */
#define USB_GOTGCTL_CON_ID_STS_Set(x) (((uint32_t) (x) << USB_GOTGCTL_CON_ID_STS_Pos) & USB_GOTGCTL_CON_ID_STS_Msk) /*!< CON_ID_STS Set Value */
#define USB_GOTGCTL_CON_ID_STS_Get(x) (((uint32_t) (x) & USB_GOTGCTL_CON_ID_STS_Msk) >> USB_GOTGCTL_CON_ID_STS_Pos) /*!< CON_ID_STS Get Value */


#define USB_GOTGCTL_BVALID_OV_VAL_Pos    (7U)                                                                        /*!< BVALID_OV_VAL Postion   */ 
#define USB_GOTGCTL_BVALID_OV_VAL_Msk    (0x1U << USB_GOTGCTL_BVALID_OV_VAL_Pos)                                     /*!< BVALID_OV_VAL Mask      */
#define USB_GOTGCTL_BVALID_OV_VAL_Set(x) (((uint32_t) (x) << USB_GOTGCTL_BVALID_OV_VAL_Pos) & USB_GOTGCTL_BVALID_OV_VAL_Msk) /*!< BVALID_OV_VAL Set Value */
#define USB_GOTGCTL_BVALID_OV_VAL_Get(x) (((uint32_t) (x) & USB_GOTGCTL_BVALID_OV_VAL_Msk) >> USB_GOTGCTL_BVALID_OV_VAL_Pos) /*!< BVALID_OV_VAL Get Value */


#define USB_GOTGCTL_BVALID_OV_EN_Pos    (6U)                                                                        /*!< BVALID_OV_EN Postion   */ 
#define USB_GOTGCTL_BVALID_OV_EN_Msk    (0x1U << USB_GOTGCTL_BVALID_OV_EN_Pos)                                      /*!< BVALID_OV_EN Mask      */
#define USB_GOTGCTL_BVALID_OV_EN_Set(x) (((uint32_t) (x) << USB_GOTGCTL_BVALID_OV_EN_Pos) & USB_GOTGCTL_BVALID_OV_EN_Msk) /*!< BVALID_OV_EN Set Value */
#define USB_GOTGCTL_BVALID_OV_EN_Get(x) (((uint32_t) (x) & USB_GOTGCTL_BVALID_OV_EN_Msk) >> USB_GOTGCTL_BVALID_OV_EN_Pos) /*!< BVALID_OV_EN Get Value */


#define USB_GOTGCTL_AVALID_OV_VAL_Pos    (5U)                                                                        /*!< AVALID_OV_VAL Postion   */ 
#define USB_GOTGCTL_AVALID_OV_VAL_Msk    (0x1U << USB_GOTGCTL_AVALID_OV_VAL_Pos)                                     /*!< AVALID_OV_VAL Mask      */
#define USB_GOTGCTL_AVALID_OV_VAL_Set(x) (((uint32_t) (x) << USB_GOTGCTL_AVALID_OV_VAL_Pos) & USB_GOTGCTL_AVALID_OV_VAL_Msk) /*!< AVALID_OV_VAL Set Value */
#define USB_GOTGCTL_AVALID_OV_VAL_Get(x) (((uint32_t) (x) & USB_GOTGCTL_AVALID_OV_VAL_Msk) >> USB_GOTGCTL_AVALID_OV_VAL_Pos) /*!< AVALID_OV_VAL Get Value */


#define USB_GOTGCTL_AVALID_OV_EN_Pos    (4U)                                                                        /*!< AVALID_OV_EN Postion   */ 
#define USB_GOTGCTL_AVALID_OV_EN_Msk    (0x1U << USB_GOTGCTL_AVALID_OV_EN_Pos)                                      /*!< AVALID_OV_EN Mask      */
#define USB_GOTGCTL_AVALID_OV_EN_Set(x) (((uint32_t) (x) << USB_GOTGCTL_AVALID_OV_EN_Pos) & USB_GOTGCTL_AVALID_OV_EN_Msk) /*!< AVALID_OV_EN Set Value */
#define USB_GOTGCTL_AVALID_OV_EN_Get(x) (((uint32_t) (x) & USB_GOTGCTL_AVALID_OV_EN_Msk) >> USB_GOTGCTL_AVALID_OV_EN_Pos) /*!< AVALID_OV_EN Get Value */


#define USB_GOTGCTL_VBVALID_OV_VAL_Pos    (3U)                                                                        /*!< VBVALID_OV_VAL Postion   */ 
#define USB_GOTGCTL_VBVALID_OV_VAL_Msk    (0x1U << USB_GOTGCTL_VBVALID_OV_VAL_Pos)                                    /*!< VBVALID_OV_VAL Mask      */
#define USB_GOTGCTL_VBVALID_OV_VAL_Set(x) (((uint32_t) (x) << USB_GOTGCTL_VBVALID_OV_VAL_Pos) & USB_GOTGCTL_VBVALID_OV_VAL_Msk) /*!< VBVALID_OV_VAL Set Value */
#define USB_GOTGCTL_VBVALID_OV_VAL_Get(x) (((uint32_t) (x) & USB_GOTGCTL_VBVALID_OV_VAL_Msk) >> USB_GOTGCTL_VBVALID_OV_VAL_Pos) /*!< VBVALID_OV_VAL Get Value */


#define USB_GOTGCTL_VBVALID_OV_EN_Pos    (2U)                                                                        /*!< VBVALID_OV_EN Postion   */ 
#define USB_GOTGCTL_VBVALID_OV_EN_Msk    (0x1U << USB_GOTGCTL_VBVALID_OV_EN_Pos)                                     /*!< VBVALID_OV_EN Mask      */
#define USB_GOTGCTL_VBVALID_OV_EN_Set(x) (((uint32_t) (x) << USB_GOTGCTL_VBVALID_OV_EN_Pos) & USB_GOTGCTL_VBVALID_OV_EN_Msk) /*!< VBVALID_OV_EN Set Value */
#define USB_GOTGCTL_VBVALID_OV_EN_Get(x) (((uint32_t) (x) & USB_GOTGCTL_VBVALID_OV_EN_Msk) >> USB_GOTGCTL_VBVALID_OV_EN_Pos) /*!< VBVALID_OV_EN Get Value */


/* GOTGINT bitfield */
#define USB_GOTGINT_DBNCE_DONE_Pos    (19U)                                                                       /*!< DBNCE_DONE Postion   */ 
#define USB_GOTGINT_DBNCE_DONE_Msk    (0x1U << USB_GOTGINT_DBNCE_DONE_Pos)                                        /*!< DBNCE_DONE Mask      */
#define USB_GOTGINT_DBNCE_DONE_Set(x) (((uint32_t) (x) << USB_GOTGINT_DBNCE_DONE_Pos) & USB_GOTGINT_DBNCE_DONE_Msk) /*!< DBNCE_DONE Set Value */
#define USB_GOTGINT_DBNCE_DONE_Get(x) (((uint32_t) (x) & USB_GOTGINT_DBNCE_DONE_Msk) >> USB_GOTGINT_DBNCE_DONE_Pos) /*!< DBNCE_DONE Get Value */


#define USB_GOTGINT_ADEV_TOUT_CHG_Pos    (18U)                                                                       /*!< ADEV_TOUT_CHG Postion   */ 
#define USB_GOTGINT_ADEV_TOUT_CHG_Msk    (0x1U << USB_GOTGINT_ADEV_TOUT_CHG_Pos)                                     /*!< ADEV_TOUT_CHG Mask      */
#define USB_GOTGINT_ADEV_TOUT_CHG_Set(x) (((uint32_t) (x) << USB_GOTGINT_ADEV_TOUT_CHG_Pos) & USB_GOTGINT_ADEV_TOUT_CHG_Msk) /*!< ADEV_TOUT_CHG Set Value */
#define USB_GOTGINT_ADEV_TOUT_CHG_Get(x) (((uint32_t) (x) & USB_GOTGINT_ADEV_TOUT_CHG_Msk) >> USB_GOTGINT_ADEV_TOUT_CHG_Pos) /*!< ADEV_TOUT_CHG Get Value */


#define USB_GOTGINT_HST_NEG_DET_Pos    (17U)                                                                       /*!< HST_NEG_DET Postion   */ 
#define USB_GOTGINT_HST_NEG_DET_Msk    (0x1U << USB_GOTGINT_HST_NEG_DET_Pos)                                       /*!< HST_NEG_DET Mask      */
#define USB_GOTGINT_HST_NEG_DET_Set(x) (((uint32_t) (x) << USB_GOTGINT_HST_NEG_DET_Pos) & USB_GOTGINT_HST_NEG_DET_Msk) /*!< HST_NEG_DET Set Value */
#define USB_GOTGINT_HST_NEG_DET_Get(x) (((uint32_t) (x) & USB_GOTGINT_HST_NEG_DET_Msk) >> USB_GOTGINT_HST_NEG_DET_Pos) /*!< HST_NEG_DET Get Value */


#define USB_GOTGINT_HST_NEG_SUC_STS_CHNG_Pos    (9U)                                                                        /*!< HST_NEG_SUC_STS_CHNG Postion   */ 
#define USB_GOTGINT_HST_NEG_SUC_STS_CHNG_Msk    (0x1U << USB_GOTGINT_HST_NEG_SUC_STS_CHNG_Pos)                              /*!< HST_NEG_SUC_STS_CHNG Mask      */
#define USB_GOTGINT_HST_NEG_SUC_STS_CHNG_Set(x) (((uint32_t) (x) << USB_GOTGINT_HST_NEG_SUC_STS_CHNG_Pos) & USB_GOTGINT_HST_NEG_SUC_STS_CHNG_Msk) /*!< HST_NEG_SUC_STS_CHNG Set Value */
#define USB_GOTGINT_HST_NEG_SUC_STS_CHNG_Get(x) (((uint32_t) (x) & USB_GOTGINT_HST_NEG_SUC_STS_CHNG_Msk) >> USB_GOTGINT_HST_NEG_SUC_STS_CHNG_Pos) /*!< HST_NEG_SUC_STS_CHNG Get Value */


#define USB_GOTGINT_SES_REQ_SUC_STS_CHNG_Pos    (8U)                                                                        /*!< SES_REQ_SUC_STS_CHNG Postion   */ 
#define USB_GOTGINT_SES_REQ_SUC_STS_CHNG_Msk    (0x1U << USB_GOTGINT_SES_REQ_SUC_STS_CHNG_Pos)                              /*!< SES_REQ_SUC_STS_CHNG Mask      */
#define USB_GOTGINT_SES_REQ_SUC_STS_CHNG_Set(x) (((uint32_t) (x) << USB_GOTGINT_SES_REQ_SUC_STS_CHNG_Pos) & USB_GOTGINT_SES_REQ_SUC_STS_CHNG_Msk) /*!< SES_REQ_SUC_STS_CHNG Set Value */
#define USB_GOTGINT_SES_REQ_SUC_STS_CHNG_Get(x) (((uint32_t) (x) & USB_GOTGINT_SES_REQ_SUC_STS_CHNG_Msk) >> USB_GOTGINT_SES_REQ_SUC_STS_CHNG_Pos) /*!< SES_REQ_SUC_STS_CHNG Get Value */


#define USB_GOTGINT_SES_END_DET_Pos    (2U)                                                                        /*!< SES_END_DET Postion   */ 
#define USB_GOTGINT_SES_END_DET_Msk    (0x1U << USB_GOTGINT_SES_END_DET_Pos)                                       /*!< SES_END_DET Mask      */
#define USB_GOTGINT_SES_END_DET_Set(x) (((uint32_t) (x) << USB_GOTGINT_SES_END_DET_Pos) & USB_GOTGINT_SES_END_DET_Msk) /*!< SES_END_DET Set Value */
#define USB_GOTGINT_SES_END_DET_Get(x) (((uint32_t) (x) & USB_GOTGINT_SES_END_DET_Msk) >> USB_GOTGINT_SES_END_DET_Pos) /*!< SES_END_DET Get Value */


/* GAHBCFG bitfield */
#define USB_GAHBCFG_AHB_SINGLE_Pos    (23U)                                                                       /*!< AHB_SINGLE Postion   */ 
#define USB_GAHBCFG_AHB_SINGLE_Msk    (0x1U << USB_GAHBCFG_AHB_SINGLE_Pos)                                        /*!< AHB_SINGLE Mask      */
#define USB_GAHBCFG_AHB_SINGLE_Set(x) (((uint32_t) (x) << USB_GAHBCFG_AHB_SINGLE_Pos) & USB_GAHBCFG_AHB_SINGLE_Msk) /*!< AHB_SINGLE Set Value */
#define USB_GAHBCFG_AHB_SINGLE_Get(x) (((uint32_t) (x) & USB_GAHBCFG_AHB_SINGLE_Msk) >> USB_GAHBCFG_AHB_SINGLE_Pos) /*!< AHB_SINGLE Get Value */


#define USB_GAHBCFG_NOTI_ALL_DMA_WRIT_Pos    (22U)                                                                       /*!< NOTI_ALL_DMA_WRIT Postion   */ 
#define USB_GAHBCFG_NOTI_ALL_DMA_WRIT_Msk    (0x1U << USB_GAHBCFG_NOTI_ALL_DMA_WRIT_Pos)                                 /*!< NOTI_ALL_DMA_WRIT Mask      */
#define USB_GAHBCFG_NOTI_ALL_DMA_WRIT_Set(x) (((uint32_t) (x) << USB_GAHBCFG_NOTI_ALL_DMA_WRIT_Pos) & USB_GAHBCFG_NOTI_ALL_DMA_WRIT_Msk) /*!< NOTI_ALL_DMA_WRIT Set Value */
#define USB_GAHBCFG_NOTI_ALL_DMA_WRIT_Get(x) (((uint32_t) (x) & USB_GAHBCFG_NOTI_ALL_DMA_WRIT_Msk) >> USB_GAHBCFG_NOTI_ALL_DMA_WRIT_Pos) /*!< NOTI_ALL_DMA_WRIT Get Value */


#define USB_GAHBCFG_REM_MEM_SUPP_Pos    (21U)                                                                       /*!< REM_MEM_SUPP Postion   */ 
#define USB_GAHBCFG_REM_MEM_SUPP_Msk    (0x1U << USB_GAHBCFG_REM_MEM_SUPP_Pos)                                      /*!< REM_MEM_SUPP Mask      */
#define USB_GAHBCFG_REM_MEM_SUPP_Set(x) (((uint32_t) (x) << USB_GAHBCFG_REM_MEM_SUPP_Pos) & USB_GAHBCFG_REM_MEM_SUPP_Msk) /*!< REM_MEM_SUPP Set Value */
#define USB_GAHBCFG_REM_MEM_SUPP_Get(x) (((uint32_t) (x) & USB_GAHBCFG_REM_MEM_SUPP_Msk) >> USB_GAHBCFG_REM_MEM_SUPP_Pos) /*!< REM_MEM_SUPP Get Value */


#define USB_GAHBCFG_PTXF_EMP_LVL_Pos    (8U)                                                                        /*!< PTXF_EMP_LVL Postion   */ 
#define USB_GAHBCFG_PTXF_EMP_LVL_Msk    (0x1U << USB_GAHBCFG_PTXF_EMP_LVL_Pos)                                      /*!< PTXF_EMP_LVL Mask      */
#define USB_GAHBCFG_PTXF_EMP_LVL_Set(x) (((uint32_t) (x) << USB_GAHBCFG_PTXF_EMP_LVL_Pos) & USB_GAHBCFG_PTXF_EMP_LVL_Msk) /*!< PTXF_EMP_LVL Set Value */
#define USB_GAHBCFG_PTXF_EMP_LVL_Get(x) (((uint32_t) (x) & USB_GAHBCFG_PTXF_EMP_LVL_Msk) >> USB_GAHBCFG_PTXF_EMP_LVL_Pos) /*!< PTXF_EMP_LVL Get Value */


#define USB_GAHBCFG_NP_TXF_EMP_LVL_Pos    (7U)                                                                        /*!< NP_TXF_EMP_LVL Postion   */ 
#define USB_GAHBCFG_NP_TXF_EMP_LVL_Msk    (0x1U << USB_GAHBCFG_NP_TXF_EMP_LVL_Pos)                                    /*!< NP_TXF_EMP_LVL Mask      */
#define USB_GAHBCFG_NP_TXF_EMP_LVL_Set(x) (((uint32_t) (x) << USB_GAHBCFG_NP_TXF_EMP_LVL_Pos) & USB_GAHBCFG_NP_TXF_EMP_LVL_Msk) /*!< NP_TXF_EMP_LVL Set Value */
#define USB_GAHBCFG_NP_TXF_EMP_LVL_Get(x) (((uint32_t) (x) & USB_GAHBCFG_NP_TXF_EMP_LVL_Msk) >> USB_GAHBCFG_NP_TXF_EMP_LVL_Pos) /*!< NP_TXF_EMP_LVL Get Value */


#define USB_GAHBCFG_DMA_EN_Pos    (5U)                                                                        /*!< DMA_EN Postion   */ 
#define USB_GAHBCFG_DMA_EN_Msk    (0x1U << USB_GAHBCFG_DMA_EN_Pos)                                            /*!< DMA_EN Mask      */
#define USB_GAHBCFG_DMA_EN_Set(x) (((uint32_t) (x) << USB_GAHBCFG_DMA_EN_Pos) & USB_GAHBCFG_DMA_EN_Msk)       /*!< DMA_EN Set Value */
#define USB_GAHBCFG_DMA_EN_Get(x) (((uint32_t) (x) & USB_GAHBCFG_DMA_EN_Msk) >> USB_GAHBCFG_DMA_EN_Pos)       /*!< DMA_EN Get Value */


#define USB_GAHBCFG_HBST_LEN_Pos    (1U)                                                                        /*!< HBST_LEN Postion   */ 
#define USB_GAHBCFG_HBST_LEN_Msk    (0xfU << USB_GAHBCFG_HBST_LEN_Pos)                                          /*!< HBST_LEN Mask      */
#define USB_GAHBCFG_HBST_LEN_Set(x) (((uint32_t) (x) << USB_GAHBCFG_HBST_LEN_Pos) & USB_GAHBCFG_HBST_LEN_Msk)   /*!< HBST_LEN Set Value */
#define USB_GAHBCFG_HBST_LEN_Get(x) (((uint32_t) (x) & USB_GAHBCFG_HBST_LEN_Msk) >> USB_GAHBCFG_HBST_LEN_Pos)   /*!< HBST_LEN Get Value */


#define USB_GAHBCFG_GLBL_INTR_MSK_Pos    (0U)                                                                        /*!< GLBL_INTR_MSK Postion   */ 
#define USB_GAHBCFG_GLBL_INTR_MSK_Msk    (0x1U << USB_GAHBCFG_GLBL_INTR_MSK_Pos)                                     /*!< GLBL_INTR_MSK Mask      */
#define USB_GAHBCFG_GLBL_INTR_MSK_Set(x) (((uint32_t) (x) << USB_GAHBCFG_GLBL_INTR_MSK_Pos) & USB_GAHBCFG_GLBL_INTR_MSK_Msk) /*!< GLBL_INTR_MSK Set Value */
#define USB_GAHBCFG_GLBL_INTR_MSK_Get(x) (((uint32_t) (x) & USB_GAHBCFG_GLBL_INTR_MSK_Msk) >> USB_GAHBCFG_GLBL_INTR_MSK_Pos) /*!< GLBL_INTR_MSK Get Value */


/* GUSBCFG bitfield */
#define USB_GUSBCFG_CORRUPT_TX_PKT_Pos    (31U)                                                                       /*!< CORRUPT_TX_PKT Postion   */ 
#define USB_GUSBCFG_CORRUPT_TX_PKT_Msk    (0x1U << USB_GUSBCFG_CORRUPT_TX_PKT_Pos)                                    /*!< CORRUPT_TX_PKT Mask      */
#define USB_GUSBCFG_CORRUPT_TX_PKT_Set(x) (((uint32_t) (x) << USB_GUSBCFG_CORRUPT_TX_PKT_Pos) & USB_GUSBCFG_CORRUPT_TX_PKT_Msk) /*!< CORRUPT_TX_PKT Set Value */
#define USB_GUSBCFG_CORRUPT_TX_PKT_Get(x) (((uint32_t) (x) & USB_GUSBCFG_CORRUPT_TX_PKT_Msk) >> USB_GUSBCFG_CORRUPT_TX_PKT_Pos) /*!< CORRUPT_TX_PKT Get Value */


#define USB_GUSBCFG_FORCE_DEV_MODE_Pos    (30U)                                                                       /*!< FORCE_DEV_MODE Postion   */ 
#define USB_GUSBCFG_FORCE_DEV_MODE_Msk    (0x1U << USB_GUSBCFG_FORCE_DEV_MODE_Pos)                                    /*!< FORCE_DEV_MODE Mask      */
#define USB_GUSBCFG_FORCE_DEV_MODE_Set(x) (((uint32_t) (x) << USB_GUSBCFG_FORCE_DEV_MODE_Pos) & USB_GUSBCFG_FORCE_DEV_MODE_Msk) /*!< FORCE_DEV_MODE Set Value */
#define USB_GUSBCFG_FORCE_DEV_MODE_Get(x) (((uint32_t) (x) & USB_GUSBCFG_FORCE_DEV_MODE_Msk) >> USB_GUSBCFG_FORCE_DEV_MODE_Pos) /*!< FORCE_DEV_MODE Get Value */


#define USB_GUSBCFG_FORCE_HST_MODE_Pos    (29U)                                                                       /*!< FORCE_HST_MODE Postion   */ 
#define USB_GUSBCFG_FORCE_HST_MODE_Msk    (0x1U << USB_GUSBCFG_FORCE_HST_MODE_Pos)                                    /*!< FORCE_HST_MODE Mask      */
#define USB_GUSBCFG_FORCE_HST_MODE_Set(x) (((uint32_t) (x) << USB_GUSBCFG_FORCE_HST_MODE_Pos) & USB_GUSBCFG_FORCE_HST_MODE_Msk) /*!< FORCE_HST_MODE Set Value */
#define USB_GUSBCFG_FORCE_HST_MODE_Get(x) (((uint32_t) (x) & USB_GUSBCFG_FORCE_HST_MODE_Msk) >> USB_GUSBCFG_FORCE_HST_MODE_Pos) /*!< FORCE_HST_MODE Get Value */


#define USB_GUSBCFG_TX_END_DELAY_Pos    (28U)                                                                       /*!< TX_END_DELAY Postion   */ 
#define USB_GUSBCFG_TX_END_DELAYk    (0x1U << USB_GUSBCFG_TX_END_DELAY_Pos)                                      /*!< TX_END_DELAY Mask      */
#define USB_GUSBCFG_TX_END_DELAY_Set(x) (((uint32_t) (x) << USB_GUSBCFG_TX_END_DELAY_Pos) & USB_GUSBCFG_TX_END_DELAYk) /*!< TX_END_DELAY Set Value */
#define USB_GUSBCFG_TX_END_DELAY_Get(x) (((uint32_t) (x) & USB_GUSBCFG_TX_END_DELAYk) >> USB_GUSBCFG_TX_END_DELAY_Pos) /*!< TX_END_DELAY Get Value */


#define USB_GUSBCFG_IC_USB_CAP_Pos    (26U)                                                                       /*!< IC_USB_CAP Postion   */ 
#define USB_GUSBCFG_IC_USB_CAP_Msk    (0x1U << USB_GUSBCFG_IC_USB_CAP_Pos)                                        /*!< IC_USB_CAP Mask      */
#define USB_GUSBCFG_IC_USB_CAP_Set(x) (((uint32_t) (x) << USB_GUSBCFG_IC_USB_CAP_Pos) & USB_GUSBCFG_IC_USB_CAP_Msk) /*!< IC_USB_CAP Set Value */
#define USB_GUSBCFG_IC_USB_CAP_Get(x) (((uint32_t) (x) & USB_GUSBCFG_IC_USB_CAP_Msk) >> USB_GUSBCFG_IC_USB_CAP_Pos) /*!< IC_USB_CAP Get Value */


#define USB_GUSBCFG_TERM_SEL_DLPULSE_Pos    (22U)                                                                       /*!< TERM_SEL_DLPULSE Postion   */ 
#define USB_GUSBCFG_TERM_SEL_DLPULSE_Msk    (0x1U << USB_GUSBCFG_TERM_SEL_DLPULSE_Pos)                                  /*!< TERM_SEL_DLPULSE Mask      */
#define USB_GUSBCFG_TERM_SEL_DLPULSE_Set(x) (((uint32_t) (x) << USB_GUSBCFG_TERM_SEL_DLPULSE_Pos) & USB_GUSBCFG_TERM_SEL_DLPULSE_Msk) /*!< TERM_SEL_DLPULSE Set Value */
#define USB_GUSBCFG_TERM_SEL_DLPULSE_Get(x) (((uint32_t) (x) & USB_GUSBCFG_TERM_SEL_DLPULSE_Msk) >> USB_GUSBCFG_TERM_SEL_DLPULSE_Pos) /*!< TERM_SEL_DLPULSE Get Value */


#define USB_GUSBCFG_USB_TRD_TIM_Pos    (10U)                                                                       /*!< USB_TRD_TIM Postion   */ 
#define USB_GUSBCFG_USB_TRD_TIM_Msk    (0xfU << USB_GUSBCFG_USB_TRD_TIM_Pos)                                       /*!< USB_TRD_TIM Mask      */
#define USB_GUSBCFG_USB_TRD_TIM_Set(x) (((uint32_t) (x) << USB_GUSBCFG_USB_TRD_TIM_Pos) & USB_GUSBCFG_USB_TRD_TIM_Msk) /*!< USB_TRD_TIM Set Value */
#define USB_GUSBCFG_USB_TRD_TIM_Get(x) (((uint32_t) (x) & USB_GUSBCFG_USB_TRD_TIM_Msk) >> USB_GUSBCFG_USB_TRD_TIM_Pos) /*!< USB_TRD_TIM Get Value */


#define USB_GUSBCFG_PHY_SEL_Pos    (6U)                                                                        /*!< PHY_SEL Postion   */ 
#define USB_GUSBCFG_PHY_SEL_Msk    (0x1U << USB_GUSBCFG_PHY_SEL_Pos)                                           /*!< PHY_SEL Mask      */
#define USB_GUSBCFG_PHY_SEL_Set(x) (((uint32_t) (x) << USB_GUSBCFG_PHY_SEL_Pos) & USB_GUSBCFG_PHY_SEL_Msk)     /*!< PHY_SEL Set Value */
#define USB_GUSBCFG_PHY_SEL_Get(x) (((uint32_t) (x) & USB_GUSBCFG_PHY_SEL_Msk) >> USB_GUSBCFG_PHY_SEL_Pos)     /*!< PHY_SEL Get Value */


#define USB_GUSBCFG_FS_INTF_Pos    (5U)                                                                        /*!< FS_INTF Postion   */ 
#define USB_GUSBCFG_FS_INTF_Msk    (0x1U << USB_GUSBCFG_FS_INTF_Pos)                                           /*!< FS_INTF Mask      */
#define USB_GUSBCFG_FS_INTF_Set(x) (((uint32_t) (x) << USB_GUSBCFG_FS_INTF_Pos) & USB_GUSBCFG_FS_INTF_Msk)     /*!< FS_INTF Set Value */
#define USB_GUSBCFG_FS_INTF_Get(x) (((uint32_t) (x) & USB_GUSBCFG_FS_INTF_Msk) >> USB_GUSBCFG_FS_INTF_Pos)     /*!< FS_INTF Get Value */


#define USB_GUSBCFG_PHY_IF_Pos    (3U)                                                                        /*!< PHY_IF Postion   */ 
#define USB_GUSBCFG_PHY_IF_Msk    (0x1U << USB_GUSBCFG_PHY_IF_Pos)                                            /*!< PHY_IF Mask      */
#define USB_GUSBCFG_PHY_IF_Set(x) (((uint32_t) (x) << USB_GUSBCFG_PHY_IF_Pos) & USB_GUSBCFG_PHY_IF_Msk)       /*!< PHY_IF Set Value */
#define USB_GUSBCFG_PHY_IF_Get(x) (((uint32_t) (x) & USB_GUSBCFG_PHY_IF_Msk) >> USB_GUSBCFG_PHY_IF_Pos)       /*!< PHY_IF Get Value */


#define USB_GUSBCFG_TOUT_CAL_Pos    (0U)                                                                        /*!< TOUT_CAL Postion   */ 
#define USB_GUSBCFG_TOUT_CAL_Msk    (0x7U << USB_GUSBCFG_TOUT_CAL_Pos)                                          /*!< TOUT_CAL Mask      */
#define USB_GUSBCFG_TOUT_CAL_Set(x) (((uint32_t) (x) << USB_GUSBCFG_TOUT_CAL_Pos) & USB_GUSBCFG_TOUT_CAL_Msk)   /*!< TOUT_CAL Set Value */
#define USB_GUSBCFG_TOUT_CAL_Get(x) (((uint32_t) (x) & USB_GUSBCFG_TOUT_CAL_Msk) >> USB_GUSBCFG_TOUT_CAL_Pos)   /*!< TOUT_CAL Get Value */


/* GRSTCTL bitfield */
#define USB_GRSTCTL_AHB_IDLE_Pos    (31U)                                                                       /*!< AHB_IDLE Postion   */ 
#define USB_GRSTCTL_AHB_IDLE_Msk    (0x1U << USB_GRSTCTL_AHB_IDLE_Pos)                                          /*!< AHB_IDLE Mask      */
#define USB_GRSTCTL_AHB_IDLE_Set(x) (((uint32_t) (x) << USB_GRSTCTL_AHB_IDLE_Pos) & USB_GRSTCTL_AHB_IDLE_Msk)   /*!< AHB_IDLE Set Value */
#define USB_GRSTCTL_AHB_IDLE_Get(x) (((uint32_t) (x) & USB_GRSTCTL_AHB_IDLE_Msk) >> USB_GRSTCTL_AHB_IDLE_Pos)   /*!< AHB_IDLE Get Value */


#define USB_GRSTCTL_DMA_REQ_Pos    (30U)                                                                       /*!< DMA_REQ Postion   */ 
#define USB_GRSTCTL_DMA_REQ_Msk    (0x1U << USB_GRSTCTL_DMA_REQ_Pos)                                           /*!< DMA_REQ Mask      */
#define USB_GRSTCTL_DMA_REQ_Set(x) (((uint32_t) (x) << USB_GRSTCTL_DMA_REQ_Pos) & USB_GRSTCTL_DMA_REQ_Msk)     /*!< DMA_REQ Set Value */
#define USB_GRSTCTL_DMA_REQ_Get(x) (((uint32_t) (x) & USB_GRSTCTL_DMA_REQ_Msk) >> USB_GRSTCTL_DMA_REQ_Pos)     /*!< DMA_REQ Get Value */


#define USB_GRSTCTL_TXF_NUM_Pos    (6U)                                                                        /*!< TXF_NUM Postion   */ 
#define USB_GRSTCTL_TXF_NUM_Msk    (0x1fU << USB_GRSTCTL_TXF_NUM_Pos)                                          /*!< TXF_NUM Mask      */
#define USB_GRSTCTL_TXF_NUM_Set(x) (((uint32_t) (x) << USB_GRSTCTL_TXF_NUM_Pos) & USB_GRSTCTL_TXF_NUM_Msk)     /*!< TXF_NUM Set Value */
#define USB_GRSTCTL_TXF_NUM_Get(x) (((uint32_t) (x) & USB_GRSTCTL_TXF_NUM_Msk) >> USB_GRSTCTL_TXF_NUM_Pos)     /*!< TXF_NUM Get Value */


#define USB_GRSTCTL_TXF_FLSH_Pos    (5U)                                                                        /*!< TXF_FLSH Postion   */ 
#define USB_GRSTCTL_TXF_FLSH_Msk    (0x1U << USB_GRSTCTL_TXF_FLSH_Pos)                                          /*!< TXF_FLSH Mask      */
#define USB_GRSTCTL_TXF_FLSH_Set(x) (((uint32_t) (x) << USB_GRSTCTL_TXF_FLSH_Pos) & USB_GRSTCTL_TXF_FLSH_Msk)   /*!< TXF_FLSH Set Value */
#define USB_GRSTCTL_TXF_FLSH_Get(x) (((uint32_t) (x) & USB_GRSTCTL_TXF_FLSH_Msk) >> USB_GRSTCTL_TXF_FLSH_Pos)   /*!< TXF_FLSH Get Value */


#define USB_GRSTCTL_RXF_FLSH_Pos    (4U)                                                                        /*!< RXF_FLSH Postion   */ 
#define USB_GRSTCTL_RXF_FLSH_Msk    (0x1U << USB_GRSTCTL_RXF_FLSH_Pos)                                          /*!< RXF_FLSH Mask      */
#define USB_GRSTCTL_RXF_FLSH_Set(x) (((uint32_t) (x) << USB_GRSTCTL_RXF_FLSH_Pos) & USB_GRSTCTL_RXF_FLSH_Msk)   /*!< RXF_FLSH Set Value */
#define USB_GRSTCTL_RXF_FLSH_Get(x) (((uint32_t) (x) & USB_GRSTCTL_RXF_FLSH_Msk) >> USB_GRSTCTL_RXF_FLSH_Pos)   /*!< RXF_FLSH Get Value */


#define USB_GRSTCTL_FRM_CNTR_RST_Pos    (2U)                                                                        /*!< FRM_CNTR_RST Postion   */ 
#define USB_GRSTCTL_FRM_CNTR_RST_Msk    (0x1U << USB_GRSTCTL_FRM_CNTR_RST_Pos)                                      /*!< FRM_CNTR_RST Mask      */
#define USB_GRSTCTL_FRM_CNTR_RST_Set(x) (((uint32_t) (x) << USB_GRSTCTL_FRM_CNTR_RST_Pos) & USB_GRSTCTL_FRM_CNTR_RST_Msk) /*!< FRM_CNTR_RST Set Value */
#define USB_GRSTCTL_FRM_CNTR_RST_Get(x) (((uint32_t) (x) & USB_GRSTCTL_FRM_CNTR_RST_Msk) >> USB_GRSTCTL_FRM_CNTR_RST_Pos) /*!< FRM_CNTR_RST Get Value */


#define USB_GRSTCTL_PIU_FS_SFT_RST_Pos    (1U)                                                                        /*!< PIU_FS_SFT_RST Postion   */ 
#define USB_GRSTCTL_PIU_FS_SFT_RST_Msk    (0x1U << USB_GRSTCTL_PIU_FS_SFT_RST_Pos)                                    /*!< PIU_FS_SFT_RST Mask      */
#define USB_GRSTCTL_PIU_FS_SFT_RST_Set(x) (((uint32_t) (x) << USB_GRSTCTL_PIU_FS_SFT_RST_Pos) & USB_GRSTCTL_PIU_FS_SFT_RST_Msk) /*!< PIU_FS_SFT_RST Set Value */
#define USB_GRSTCTL_PIU_FS_SFT_RST_Get(x) (((uint32_t) (x) & USB_GRSTCTL_PIU_FS_SFT_RST_Msk) >> USB_GRSTCTL_PIU_FS_SFT_RST_Pos) /*!< PIU_FS_SFT_RST Get Value */


#define USB_GRSTCTL_CSFT_RST_Pos    (0U)                                                                        /*!< CSFT_RST Postion   */ 
#define USB_GRSTCTL_CSFT_RST_Msk    (0x1U << USB_GRSTCTL_CSFT_RST_Pos)                                          /*!< CSFT_RST Mask      */
#define USB_GRSTCTL_CSFT_RST_Set(x) (((uint32_t) (x) << USB_GRSTCTL_CSFT_RST_Pos) & USB_GRSTCTL_CSFT_RST_Msk)   /*!< CSFT_RST Set Value */
#define USB_GRSTCTL_CSFT_RST_Get(x) (((uint32_t) (x) & USB_GRSTCTL_CSFT_RST_Msk) >> USB_GRSTCTL_CSFT_RST_Pos)   /*!< CSFT_RST Get Value */


/* GINTSTS bitfield */
#define USB_GINTSTS_WK_UP_INT_Pos    (31U)                                                                       /*!< WK_UP_INT Postion   */ 
#define USB_GINTSTS_WK_UP_INT_Msk    (0x1U << USB_GINTSTS_WK_UP_INT_Pos)                                         /*!< WK_UP_INT Mask      */
#define USB_GINTSTS_WK_UP_INT_Set(x) (((uint32_t) (x) << USB_GINTSTS_WK_UP_INT_Pos) & USB_GINTSTS_WK_UP_INT_Msk) /*!< WK_UP_INT Set Value */
#define USB_GINTSTS_WK_UP_INT_Get(x) (((uint32_t) (x) & USB_GINTSTS_WK_UP_INT_Msk) >> USB_GINTSTS_WK_UP_INT_Pos) /*!< WK_UP_INT Get Value */


#define USB_GINTSTS_SESS_REQ_INT_Pos    (30U)                                                                       /*!< SESS_REQ_INT Postion   */ 
#define USB_GINTSTS_SESS_REQ_INT_Msk    (0x1U << USB_GINTSTS_SESS_REQ_INT_Pos)                                      /*!< SESS_REQ_INT Mask      */
#define USB_GINTSTS_SESS_REQ_INT_Set(x) (((uint32_t) (x) << USB_GINTSTS_SESS_REQ_INT_Pos) & USB_GINTSTS_SESS_REQ_INT_Msk) /*!< SESS_REQ_INT Set Value */
#define USB_GINTSTS_SESS_REQ_INT_Get(x) (((uint32_t) (x) & USB_GINTSTS_SESS_REQ_INT_Msk) >> USB_GINTSTS_SESS_REQ_INT_Pos) /*!< SESS_REQ_INT Get Value */


#define USB_GINTSTS_DISCONN_INT_Pos    (29U)                                                                       /*!< DISCONN_INT Postion   */ 
#define USB_GINTSTS_DISCONN_INT_Msk    (0x1U << USB_GINTSTS_DISCONN_INT_Pos)                                       /*!< DISCONN_INT Mask      */
#define USB_GINTSTS_DISCONN_INT_Set(x) (((uint32_t) (x) << USB_GINTSTS_DISCONN_INT_Pos) & USB_GINTSTS_DISCONN_INT_Msk) /*!< DISCONN_INT Set Value */
#define USB_GINTSTS_DISCONN_INT_Get(x) (((uint32_t) (x) & USB_GINTSTS_DISCONN_INT_Msk) >> USB_GINTSTS_DISCONN_INT_Pos) /*!< DISCONN_INT Get Value */


#define USB_GINTSTS_CON_ID_STS_CHNG_Pos    (28U)                                                                       /*!< CON_ID_STS_CHNG Postion   */ 
#define USB_GINTSTS_CON_ID_STS_CHNG_Msk    (0x1U << USB_GINTSTS_CON_ID_STS_CHNG_Pos)                                   /*!< CON_ID_STS_CHNG Mask      */
#define USB_GINTSTS_CON_ID_STS_CHNG_Set(x) (((uint32_t) (x) << USB_GINTSTS_CON_ID_STS_CHNG_Pos) & USB_GINTSTS_CON_ID_STS_CHNG_Msk) /*!< CON_ID_STS_CHNG Set Value */
#define USB_GINTSTS_CON_ID_STS_CHNG_Get(x) (((uint32_t) (x) & USB_GINTSTS_CON_ID_STS_CHNG_Msk) >> USB_GINTSTS_CON_ID_STS_CHNG_Pos) /*!< CON_ID_STS_CHNG Get Value */


#define USB_GINTSTS_PTXF_EMP_Pos    (26U)                                                                       /*!< PTXF_EMP Postion   */ 
#define USB_GINTSTS_PTXF_EMP_Msk    (0x1U << USB_GINTSTS_PTXF_EMP_Pos)                                          /*!< PTXF_EMP Mask      */
#define USB_GINTSTS_PTXF_EMP_Set(x) (((uint32_t) (x) << USB_GINTSTS_PTXF_EMP_Pos) & USB_GINTSTS_PTXF_EMP_Msk)   /*!< PTXF_EMP Set Value */
#define USB_GINTSTS_PTXF_EMP_Get(x) (((uint32_t) (x) & USB_GINTSTS_PTXF_EMP_Msk) >> USB_GINTSTS_PTXF_EMP_Pos)   /*!< PTXF_EMP Get Value */


#define USB_GINTSTS_HCH_INT_Pos    (25U)                                                                       /*!< HCH_INT Postion   */ 
#define USB_GINTSTS_HCH_INT_Msk    (0x1U << USB_GINTSTS_HCH_INT_Pos)                                           /*!< HCH_INT Mask      */
#define USB_GINTSTS_HCH_INT_Set(x) (((uint32_t) (x) << USB_GINTSTS_HCH_INT_Pos) & USB_GINTSTS_HCH_INT_Msk)     /*!< HCH_INT Set Value */
#define USB_GINTSTS_HCH_INT_Get(x) (((uint32_t) (x) & USB_GINTSTS_HCH_INT_Msk) >> USB_GINTSTS_HCH_INT_Pos)     /*!< HCH_INT Get Value */


#define USB_GINTSTS_PRT_INT_Pos    (24U)                                                                       /*!< PRT_INT Postion   */ 
#define USB_GINTSTS_PRT_INT_Msk    (0x1U << USB_GINTSTS_PRT_INT_Pos)                                           /*!< PRT_INT Mask      */
#define USB_GINTSTS_PRT_INT_Set(x) (((uint32_t) (x) << USB_GINTSTS_PRT_INT_Pos) & USB_GINTSTS_PRT_INT_Msk)     /*!< PRT_INT Set Value */
#define USB_GINTSTS_PRT_INT_Get(x) (((uint32_t) (x) & USB_GINTSTS_PRT_INT_Msk) >> USB_GINTSTS_PRT_INT_Pos)     /*!< PRT_INT Get Value */


#define USB_GINTSTS_RESET_DET_Pos    (23U)                                                                       /*!< RESET_DET Postion   */ 
#define USB_GINTSTS_RESET_DET_Msk    (0x1U << USB_GINTSTS_RESET_DET_Pos)                                         /*!< RESET_DET Mask      */
#define USB_GINTSTS_RESET_DET_Set(x) (((uint32_t) (x) << USB_GINTSTS_RESET_DET_Pos) & USB_GINTSTS_RESET_DET_Msk) /*!< RESET_DET Set Value */
#define USB_GINTSTS_RESET_DET_Get(x) (((uint32_t) (x) & USB_GINTSTS_RESET_DET_Msk) >> USB_GINTSTS_RESET_DET_Pos) /*!< RESET_DET Get Value */


#define USB_GINTSTS_FET_SUSP_Pos    (22U)                                                                       /*!< FET_SUSP Postion   */ 
#define USB_GINTSTS_FET_SUSP_Msk    (0x1U << USB_GINTSTS_FET_SUSP_Pos)                                          /*!< FET_SUSP Mask      */
#define USB_GINTSTS_FET_SUSP_Set(x) (((uint32_t) (x) << USB_GINTSTS_FET_SUSP_Pos) & USB_GINTSTS_FET_SUSP_Msk)   /*!< FET_SUSP Set Value */
#define USB_GINTSTS_FET_SUSP_Get(x) (((uint32_t) (x) & USB_GINTSTS_FET_SUSP_Msk) >> USB_GINTSTS_FET_SUSP_Pos)   /*!< FET_SUSP Get Value */


#define USB_GINTSTS_INCOMPL_P_Pos    (21U)                                                                       /*!< INCOMPL_P Postion   */ 
#define USB_GINTSTS_INCOMPL_P_Msk    (0x1U << USB_GINTSTS_INCOMPL_P_Pos)                                         /*!< INCOMPL_P Mask      */
#define USB_GINTSTS_INCOMPL_P_Set(x) (((uint32_t) (x) << USB_GINTSTS_INCOMPL_P_Pos) & USB_GINTSTS_INCOMPL_P_Msk) /*!< INCOMPL_P Set Value */
#define USB_GINTSTS_INCOMPL_P_Get(x) (((uint32_t) (x) & USB_GINTSTS_INCOMPL_P_Msk) >> USB_GINTSTS_INCOMPL_P_Pos) /*!< INCOMPL_P Get Value */


#define USB_GINTSTS_INCOMP_ISO_IN_Pos    (20U)                                                                       /*!< INCOMP_ISO_IN Postion   */ 
#define USB_GINTSTS_INCOMP_ISO_IN_Msk    (0x1U << USB_GINTSTS_INCOMP_ISO_IN_Pos)                                     /*!< INCOMP_ISO_IN Mask      */
#define USB_GINTSTS_INCOMP_ISO_IN_Set(x) (((uint32_t) (x) << USB_GINTSTS_INCOMP_ISO_IN_Pos) & USB_GINTSTS_INCOMP_ISO_IN_Msk) /*!< INCOMP_ISO_IN Set Value */
#define USB_GINTSTS_INCOMP_ISO_IN_Get(x) (((uint32_t) (x) & USB_GINTSTS_INCOMP_ISO_IN_Msk) >> USB_GINTSTS_INCOMP_ISO_IN_Pos) /*!< INCOMP_ISO_IN Get Value */


#define USB_GINTSTS_OEP_INT_Pos    (19U)                                                                       /*!< OEP_INT Postion   */ 
#define USB_GINTSTS_OEP_INT_Msk    (0x1U << USB_GINTSTS_OEP_INT_Pos)                                           /*!< OEP_INT Mask      */
#define USB_GINTSTS_OEP_INT_Set(x) (((uint32_t) (x) << USB_GINTSTS_OEP_INT_Pos) & USB_GINTSTS_OEP_INT_Msk)     /*!< OEP_INT Set Value */
#define USB_GINTSTS_OEP_INT_Get(x) (((uint32_t) (x) & USB_GINTSTS_OEP_INT_Msk) >> USB_GINTSTS_OEP_INT_Pos)     /*!< OEP_INT Get Value */


#define USB_GINTSTS_IEP_INT_Pos    (18U)                                                                       /*!< IEP_INT Postion   */ 
#define USB_GINTSTS_IEP_INT_Msk    (0x1U << USB_GINTSTS_IEP_INT_Pos)                                           /*!< IEP_INT Mask      */
#define USB_GINTSTS_IEP_INT_Set(x) (((uint32_t) (x) << USB_GINTSTS_IEP_INT_Pos) & USB_GINTSTS_IEP_INT_Msk)     /*!< IEP_INT Set Value */
#define USB_GINTSTS_IEP_INT_Get(x) (((uint32_t) (x) & USB_GINTSTS_IEP_INT_Msk) >> USB_GINTSTS_IEP_INT_Pos)     /*!< IEP_INT Get Value */


#define USB_GINTSTS_EP_MIS_Pos    (17U)                                                                       /*!< EP_MIS Postion   */ 
#define USB_GINTSTS_EP_MIS_Msk    (0x1U << USB_GINTSTS_EP_MIS_Pos)                                            /*!< EP_MIS Mask      */
#define USB_GINTSTS_EP_MIS_Set(x) (((uint32_t) (x) << USB_GINTSTS_EP_MIS_Pos) & USB_GINTSTS_EP_MIS_Msk)       /*!< EP_MIS Set Value */
#define USB_GINTSTS_EP_MIS_Get(x) (((uint32_t) (x) & USB_GINTSTS_EP_MIS_Msk) >> USB_GINTSTS_EP_MIS_Pos)       /*!< EP_MIS Get Value */


#define USB_GINTSTS_EOPF_Pos    (15U)                                                                       /*!< EOPF Postion   */ 
#define USB_GINTSTS_EOPF_Msk    (0x1U << USB_GINTSTS_EOPF_Pos)                                              /*!< EOPF Mask      */
#define USB_GINTSTS_EOPF_Set(x) (((uint32_t) (x) << USB_GINTSTS_EOPF_Pos) & USB_GINTSTS_EOPF_Msk)           /*!< EOPF Set Value */
#define USB_GINTSTS_EOPF_Get(x) (((uint32_t) (x) & USB_GINTSTS_EOPF_Msk) >> USB_GINTSTS_EOPF_Pos)           /*!< EOPF Get Value */


#define USB_GINTSTS_ISO_OUT_DROP_Pos    (14U)                                                                       /*!< ISO_OUT_DROP Postion   */ 
#define USB_GINTSTS_ISO_OUT_DROP_Msk    (0x1U << USB_GINTSTS_ISO_OUT_DROP_Pos)                                      /*!< ISO_OUT_DROP Mask      */
#define USB_GINTSTS_ISO_OUT_DROP_Set(x) (((uint32_t) (x) << USB_GINTSTS_ISO_OUT_DROP_Pos) & USB_GINTSTS_ISO_OUT_DROP_Msk) /*!< ISO_OUT_DROP Set Value */
#define USB_GINTSTS_ISO_OUT_DROP_Get(x) (((uint32_t) (x) & USB_GINTSTS_ISO_OUT_DROP_Msk) >> USB_GINTSTS_ISO_OUT_DROP_Pos) /*!< ISO_OUT_DROP Get Value */


#define USB_GINTSTS_ENUM_DONE_Pos    (13U)                                                                       /*!< ENUM_DONE Postion   */ 
#define USB_GINTSTS_ENUM_DONE_Msk    (0x1U << USB_GINTSTS_ENUM_DONE_Pos)                                         /*!< ENUM_DONE Mask      */
#define USB_GINTSTS_ENUM_DONE_Set(x) (((uint32_t) (x) << USB_GINTSTS_ENUM_DONE_Pos) & USB_GINTSTS_ENUM_DONE_Msk) /*!< ENUM_DONE Set Value */
#define USB_GINTSTS_ENUM_DONE_Get(x) (((uint32_t) (x) & USB_GINTSTS_ENUM_DONE_Msk) >> USB_GINTSTS_ENUM_DONE_Pos) /*!< ENUM_DONE Get Value */


#define USB_GINTSTS_USB_RST_Pos    (12U)                                                                       /*!< USB_RST Postion   */ 
#define USB_GINTSTS_USB_RST_Msk    (0x1U << USB_GINTSTS_USB_RST_Pos)                                           /*!< USB_RST Mask      */
#define USB_GINTSTS_USB_RST_Set(x) (((uint32_t) (x) << USB_GINTSTS_USB_RST_Pos) & USB_GINTSTS_USB_RST_Msk)     /*!< USB_RST Set Value */
#define USB_GINTSTS_USB_RST_Get(x) (((uint32_t) (x) & USB_GINTSTS_USB_RST_Msk) >> USB_GINTSTS_USB_RST_Pos)     /*!< USB_RST Get Value */


#define USB_GINTSTS_USB_SUSP_Pos    (11U)                                                                       /*!< USB_SUSP Postion   */ 
#define USB_GINTSTS_USB_SUSP_Msk    (0x1U << USB_GINTSTS_USB_SUSP_Pos)                                          /*!< USB_SUSP Mask      */
#define USB_GINTSTS_USB_SUSP_Set(x) (((uint32_t) (x) << USB_GINTSTS_USB_SUSP_Pos) & USB_GINTSTS_USB_SUSP_Msk)   /*!< USB_SUSP Set Value */
#define USB_GINTSTS_USB_SUSP_Get(x) (((uint32_t) (x) & USB_GINTSTS_USB_SUSP_Msk) >> USB_GINTSTS_USB_SUSP_Pos)   /*!< USB_SUSP Get Value */


#define USB_GINTSTS_ERLY_SUSP_Pos    (10U)                                                                       /*!< ERLY_SUSP Postion   */ 
#define USB_GINTSTS_ERLY_SUSP_Msk    (0x1U << USB_GINTSTS_ERLY_SUSP_Pos)                                         /*!< ERLY_SUSP Mask      */
#define USB_GINTSTS_ERLY_SUSP_Set(x) (((uint32_t) (x) << USB_GINTSTS_ERLY_SUSP_Pos) & USB_GINTSTS_ERLY_SUSP_Msk) /*!< ERLY_SUSP Set Value */
#define USB_GINTSTS_ERLY_SUSP_Get(x) (((uint32_t) (x) & USB_GINTSTS_ERLY_SUSP_Msk) >> USB_GINTSTS_ERLY_SUSP_Pos) /*!< ERLY_SUSP Get Value */


#define USB_GINTSTS_GOUT_NAK_EFF_Pos    (7U)                                                                        /*!< GOUT_NAK_EFF Postion   */ 
#define USB_GINTSTS_GOUT_NAK_EFF_Msk    (0x1U << USB_GINTSTS_GOUT_NAK_EFF_Pos)                                      /*!< GOUT_NAK_EFF Mask      */
#define USB_GINTSTS_GOUT_NAK_EFF_Set(x) (((uint32_t) (x) << USB_GINTSTS_GOUT_NAK_EFF_Pos) & USB_GINTSTS_GOUT_NAK_EFF_Msk) /*!< GOUT_NAK_EFF Set Value */
#define USB_GINTSTS_GOUT_NAK_EFF_Get(x) (((uint32_t) (x) & USB_GINTSTS_GOUT_NAK_EFF_Msk) >> USB_GINTSTS_GOUT_NAK_EFF_Pos) /*!< GOUT_NAK_EFF Get Value */


#define USB_GINTSTS_GIN_NAK_EFF_Pos    (6U)                                                                        /*!< GIN_NAK_EFF Postion   */ 
#define USB_GINTSTS_GIN_NAK_EFF_Msk    (0x1U << USB_GINTSTS_GIN_NAK_EFF_Pos)                                       /*!< GIN_NAK_EFF Mask      */
#define USB_GINTSTS_GIN_NAK_EFF_Set(x) (((uint32_t) (x) << USB_GINTSTS_GIN_NAK_EFF_Pos) & USB_GINTSTS_GIN_NAK_EFF_Msk) /*!< GIN_NAK_EFF Set Value */
#define USB_GINTSTS_GIN_NAK_EFF_Get(x) (((uint32_t) (x) & USB_GINTSTS_GIN_NAK_EFF_Msk) >> USB_GINTSTS_GIN_NAK_EFF_Pos) /*!< GIN_NAK_EFF Get Value */


#define USB_GINTSTS_NP_TXF_EMP_Pos    (5U)                                                                        /*!< NP_TXF_EMP Postion   */ 
#define USB_GINTSTS_NP_TXF_EMP_Msk    (0x1U << USB_GINTSTS_NP_TXF_EMP_Pos)                                        /*!< NP_TXF_EMP Mask      */
#define USB_GINTSTS_NP_TXF_EMP_Set(x) (((uint32_t) (x) << USB_GINTSTS_NP_TXF_EMP_Pos) & USB_GINTSTS_NP_TXF_EMP_Msk) /*!< NP_TXF_EMP Set Value */
#define USB_GINTSTS_NP_TXF_EMP_Get(x) (((uint32_t) (x) & USB_GINTSTS_NP_TXF_EMP_Msk) >> USB_GINTSTS_NP_TXF_EMP_Pos) /*!< NP_TXF_EMP Get Value */


#define USB_GINTSTS_RXF_LVL_Pos    (4U)                                                                        /*!< RXF_LVL Postion   */ 
#define USB_GINTSTS_RXF_LVL_Msk    (0x1U << USB_GINTSTS_RXF_LVL_Pos)                                           /*!< RXF_LVL Mask      */
#define USB_GINTSTS_RXF_LVL_Set(x) (((uint32_t) (x) << USB_GINTSTS_RXF_LVL_Pos) & USB_GINTSTS_RXF_LVL_Msk)     /*!< RXF_LVL Set Value */
#define USB_GINTSTS_RXF_LVL_Get(x) (((uint32_t) (x) & USB_GINTSTS_RXF_LVL_Msk) >> USB_GINTSTS_RXF_LVL_Pos)     /*!< RXF_LVL Get Value */


#define USB_GINTSTS_SOF_Pos    (3U)                                                                        /*!< SOF Postion   */ 
#define USB_GINTSTS_SOF_Msk    (0x1U << USB_GINTSTS_SOF_Pos)                                               /*!< SOF Mask      */
#define USB_GINTSTS_SOF_Set(x) (((uint32_t) (x) << USB_GINTSTS_SOF_Pos) & USB_GINTSTS_SOF_Msk)             /*!< SOF Set Value */
#define USB_GINTSTS_SOF_Get(x) (((uint32_t) (x) & USB_GINTSTS_SOF_Msk) >> USB_GINTSTS_SOF_Pos)             /*!< SOF Get Value */


#define USB_GINTSTS_OTG_INT_Pos    (2U)                                                                        /*!< OTG_INT Postion   */ 
#define USB_GINTSTS_OTG_INT_Msk    (0x1U << USB_GINTSTS_OTG_INT_Pos)                                           /*!< OTG_INT Mask      */
#define USB_GINTSTS_OTG_INT_Set(x) (((uint32_t) (x) << USB_GINTSTS_OTG_INT_Pos) & USB_GINTSTS_OTG_INT_Msk)     /*!< OTG_INT Set Value */
#define USB_GINTSTS_OTG_INT_Get(x) (((uint32_t) (x) & USB_GINTSTS_OTG_INT_Msk) >> USB_GINTSTS_OTG_INT_Pos)     /*!< OTG_INT Get Value */


#define USB_GINTSTS_MODE_MIS_Pos    (1U)                                                                        /*!< MODE_MIS Postion   */ 
#define USB_GINTSTS_MODE_MIS_Msk    (0x1U << USB_GINTSTS_MODE_MIS_Pos)                                          /*!< MODE_MIS Mask      */
#define USB_GINTSTS_MODE_MIS_Set(x) (((uint32_t) (x) << USB_GINTSTS_MODE_MIS_Pos) & USB_GINTSTS_MODE_MIS_Msk)   /*!< MODE_MIS Set Value */
#define USB_GINTSTS_MODE_MIS_Get(x) (((uint32_t) (x) & USB_GINTSTS_MODE_MIS_Msk) >> USB_GINTSTS_MODE_MIS_Pos)   /*!< MODE_MIS Get Value */


#define USB_GINTSTS_GIN_TSTS_CUR_MOD_Pos    (0U)                                                                        /*!< GIN_TSTS_CUR_MOD Postion   */ 
#define USB_GINTSTS_GIN_TSTS_CUR_MOD_Msk    (0x1U << USB_GINTSTS_GIN_TSTS_CUR_MOD_Pos)                                  /*!< GIN_TSTS_CUR_MOD Mask      */
#define USB_GINTSTS_GIN_TSTS_CUR_MOD_Set(x) (((uint32_t) (x) << USB_GINTSTS_GIN_TSTS_CUR_MOD_Pos) & USB_GINTSTS_GIN_TSTS_CUR_MOD_Msk) /*!< GIN_TSTS_CUR_MOD Set Value */
#define USB_GINTSTS_GIN_TSTS_CUR_MOD_Get(x) (((uint32_t) (x) & USB_GINTSTS_GIN_TSTS_CUR_MOD_Msk) >> USB_GINTSTS_GIN_TSTS_CUR_MOD_Pos) /*!< GIN_TSTS_CUR_MOD Get Value */


/* GINTMSK bitfield */
#define USB_GINTMSK_WK_UP_INT_MSK_Pos    (31U)                                                                       /*!< WK_UP_INT_MSK Postion   */ 
#define USB_GINTMSK_WK_UP_INT_MSK_Msk    (0x1U << USB_GINTMSK_WK_UP_INT_MSK_Pos)                                     /*!< WK_UP_INT_MSK Mask      */
#define USB_GINTMSK_WK_UP_INT_MSK_Set(x) (((uint32_t) (x) << USB_GINTMSK_WK_UP_INT_MSK_Pos) & USB_GINTMSK_WK_UP_INT_MSK_Msk) /*!< WK_UP_INT_MSK Set Value */
#define USB_GINTMSK_WK_UP_INT_MSK_Get(x) (((uint32_t) (x) & USB_GINTMSK_WK_UP_INT_MSK_Msk) >> USB_GINTMSK_WK_UP_INT_MSK_Pos) /*!< WK_UP_INT_MSK Get Value */


#define USB_GINTMSK_SESS_REQ_INT_MSK_Pos    (30U)                                                                       /*!< SESS_REQ_INT_MSK Postion   */ 
#define USB_GINTMSK_SESS_REQ_INT_MSK_Msk    (0x1U << USB_GINTMSK_SESS_REQ_INT_MSK_Pos)                                  /*!< SESS_REQ_INT_MSK Mask      */
#define USB_GINTMSK_SESS_REQ_INT_MSK_Set(x) (((uint32_t) (x) << USB_GINTMSK_SESS_REQ_INT_MSK_Pos) & USB_GINTMSK_SESS_REQ_INT_MSK_Msk) /*!< SESS_REQ_INT_MSK Set Value */
#define USB_GINTMSK_SESS_REQ_INT_MSK_Get(x) (((uint32_t) (x) & USB_GINTMSK_SESS_REQ_INT_MSK_Msk) >> USB_GINTMSK_SESS_REQ_INT_MSK_Pos) /*!< SESS_REQ_INT_MSK Get Value */


#define USB_GINTMSK_DISCONN_INT_MSK_Pos    (29U)                                                                       /*!< DISCONN_INT_MSK Postion   */ 
#define USB_GINTMSK_DISCONN_INT_MSK_Msk    (0x1U << USB_GINTMSK_DISCONN_INT_MSK_Pos)                                   /*!< DISCONN_INT_MSK Mask      */
#define USB_GINTMSK_DISCONN_INT_MSK_Set(x) (((uint32_t) (x) << USB_GINTMSK_DISCONN_INT_MSK_Pos) & USB_GINTMSK_DISCONN_INT_MSK_Msk) /*!< DISCONN_INT_MSK Set Value */
#define USB_GINTMSK_DISCONN_INT_MSK_Get(x) (((uint32_t) (x) & USB_GINTMSK_DISCONN_INT_MSK_Msk) >> USB_GINTMSK_DISCONN_INT_MSK_Pos) /*!< DISCONN_INT_MSK Get Value */


#define USB_GINTMSK_CON_ID_STS_CHNG_MSK_Pos    (28U)                                                                       /*!< CON_ID_STS_CHNG_MSK Postion   */ 
#define USB_GINTMSK_CON_ID_STS_CHNG_MSK_Msk    (0x1U << USB_GINTMSK_CON_ID_STS_CHNG_MSK_Pos)                               /*!< CON_ID_STS_CHNG_MSK Mask      */
#define USB_GINTMSK_CON_ID_STS_CHNG_MSK_Set(x) (((uint32_t) (x) << USB_GINTMSK_CON_ID_STS_CHNG_MSK_Pos) & USB_GINTMSK_CON_ID_STS_CHNG_MSK_Msk) /*!< CON_ID_STS_CHNG_MSK Set Value */
#define USB_GINTMSK_CON_ID_STS_CHNG_MSK_Get(x) (((uint32_t) (x) & USB_GINTMSK_CON_ID_STS_CHNG_MSK_Msk) >> USB_GINTMSK_CON_ID_STS_CHNG_MSK_Pos) /*!< CON_ID_STS_CHNG_MSK Get Value */


#define USB_GINTMSK_PTXF_EMP_MSK_Pos    (26U)                                                                       /*!< PTXF_EMP_MSK Postion   */ 
#define USB_GINTMSK_PTXF_EMP_MSK_Msk    (0x1U << USB_GINTMSK_PTXF_EMP_MSK_Pos)                                      /*!< PTXF_EMP_MSK Mask      */
#define USB_GINTMSK_PTXF_EMP_MSK_Set(x) (((uint32_t) (x) << USB_GINTMSK_PTXF_EMP_MSK_Pos) & USB_GINTMSK_PTXF_EMP_MSK_Msk) /*!< PTXF_EMP_MSK Set Value */
#define USB_GINTMSK_PTXF_EMP_MSK_Get(x) (((uint32_t) (x) & USB_GINTMSK_PTXF_EMP_MSK_Msk) >> USB_GINTMSK_PTXF_EMP_MSK_Pos) /*!< PTXF_EMP_MSK Get Value */


#define USB_GINTMSK_HCH_INT_MSK_Pos    (25U)                                                                       /*!< HCH_INT_MSK Postion   */ 
#define USB_GINTMSK_HCH_INT_MSK_Msk    (0x1U << USB_GINTMSK_HCH_INT_MSK_Pos)                                       /*!< HCH_INT_MSK Mask      */
#define USB_GINTMSK_HCH_INT_MSK_Set(x) (((uint32_t) (x) << USB_GINTMSK_HCH_INT_MSK_Pos) & USB_GINTMSK_HCH_INT_MSK_Msk) /*!< HCH_INT_MSK Set Value */
#define USB_GINTMSK_HCH_INT_MSK_Get(x) (((uint32_t) (x) & USB_GINTMSK_HCH_INT_MSK_Msk) >> USB_GINTMSK_HCH_INT_MSK_Pos) /*!< HCH_INT_MSK Get Value */


#define USB_GINTMSK_PRT_INT_MSK_Pos    (24U)                                                                       /*!< PRT_INT_MSK Postion   */ 
#define USB_GINTMSK_PRT_INT_MSK_Msk    (0x1U << USB_GINTMSK_PRT_INT_MSK_Pos)                                       /*!< PRT_INT_MSK Mask      */
#define USB_GINTMSK_PRT_INT_MSK_Set(x) (((uint32_t) (x) << USB_GINTMSK_PRT_INT_MSK_Pos) & USB_GINTMSK_PRT_INT_MSK_Msk) /*!< PRT_INT_MSK Set Value */
#define USB_GINTMSK_PRT_INT_MSK_Get(x) (((uint32_t) (x) & USB_GINTMSK_PRT_INT_MSK_Msk) >> USB_GINTMSK_PRT_INT_MSK_Pos) /*!< PRT_INT_MSK Get Value */


#define USB_GINTMSK_RESET_DET_MSK_Pos    (23U)                                                                       /*!< RESET_DET_MSK Postion   */ 
#define USB_GINTMSK_RESET_DET_MSK_Msk    (0x1U << USB_GINTMSK_RESET_DET_MSK_Pos)                                     /*!< RESET_DET_MSK Mask      */
#define USB_GINTMSK_RESET_DET_MSK_Set(x) (((uint32_t) (x) << USB_GINTMSK_RESET_DET_MSK_Pos) & USB_GINTMSK_RESET_DET_MSK_Msk) /*!< RESET_DET_MSK Set Value */
#define USB_GINTMSK_RESET_DET_MSK_Get(x) (((uint32_t) (x) & USB_GINTMSK_RESET_DET_MSK_Msk) >> USB_GINTMSK_RESET_DET_MSK_Pos) /*!< RESET_DET_MSK Get Value */


#define USB_GINTMSK_FET_SUSP_MSK_Pos    (22U)                                                                       /*!< FET_SUSP_MSK Postion   */ 
#define USB_GINTMSK_FET_SUSP_MSK_Msk    (0x1U << USB_GINTMSK_FET_SUSP_MSK_Pos)                                      /*!< FET_SUSP_MSK Mask      */
#define USB_GINTMSK_FET_SUSP_MSK_Set(x) (((uint32_t) (x) << USB_GINTMSK_FET_SUSP_MSK_Pos) & USB_GINTMSK_FET_SUSP_MSK_Msk) /*!< FET_SUSP_MSK Set Value */
#define USB_GINTMSK_FET_SUSP_MSK_Get(x) (((uint32_t) (x) & USB_GINTMSK_FET_SUSP_MSK_Msk) >> USB_GINTMSK_FET_SUSP_MSK_Pos) /*!< FET_SUSP_MSK Get Value */


#define USB_GINTMSK_INCOMPL_PMS_K_Pos    (21U)                                                                       /*!< INCOMPL_PMS_K Postion   */ 
#define USB_GINTMSK_INCOMPL_PMS_K_Msk    (0x1U << USB_GINTMSK_INCOMPL_PMS_K_Pos)                                     /*!< INCOMPL_PMS_K Mask      */
#define USB_GINTMSK_INCOMPL_PMS_K_Set(x) (((uint32_t) (x) << USB_GINTMSK_INCOMPL_PMS_K_Pos) & USB_GINTMSK_INCOMPL_PMS_K_Msk) /*!< INCOMPL_PMS_K Set Value */
#define USB_GINTMSK_INCOMPL_PMS_K_Get(x) (((uint32_t) (x) & USB_GINTMSK_INCOMPL_PMS_K_Msk) >> USB_GINTMSK_INCOMPL_PMS_K_Pos) /*!< INCOMPL_PMS_K Get Value */


#define USB_GINTMSK_OEP_INT_MSK_Pos    (19U)                                                                       /*!< OEP_INT_MSK Postion   */ 
#define USB_GINTMSK_OEP_INT_MSK_Msk    (0x1U << USB_GINTMSK_OEP_INT_MSK_Pos)                                       /*!< OEP_INT_MSK Mask      */
#define USB_GINTMSK_OEP_INT_MSK_Set(x) (((uint32_t) (x) << USB_GINTMSK_OEP_INT_MSK_Pos) & USB_GINTMSK_OEP_INT_MSK_Msk) /*!< OEP_INT_MSK Set Value */
#define USB_GINTMSK_OEP_INT_MSK_Get(x) (((uint32_t) (x) & USB_GINTMSK_OEP_INT_MSK_Msk) >> USB_GINTMSK_OEP_INT_MSK_Pos) /*!< OEP_INT_MSK Get Value */


#define USB_GINTMSK_IEP_INT_MSK_Pos    (18U)                                                                       /*!< IEP_INT_MSK Postion   */ 
#define USB_GINTMSK_IEP_INT_MSK_Msk    (0x1U << USB_GINTMSK_IEP_INT_MSK_Pos)                                       /*!< IEP_INT_MSK Mask      */
#define USB_GINTMSK_IEP_INT_MSK_Set(x) (((uint32_t) (x) << USB_GINTMSK_IEP_INT_MSK_Pos) & USB_GINTMSK_IEP_INT_MSK_Msk) /*!< IEP_INT_MSK Set Value */
#define USB_GINTMSK_IEP_INT_MSK_Get(x) (((uint32_t) (x) & USB_GINTMSK_IEP_INT_MSK_Msk) >> USB_GINTMSK_IEP_INT_MSK_Pos) /*!< IEP_INT_MSK Get Value */


#define USB_GINTMSK_EP_MIS_MSK_Pos    (17U)                                                                       /*!< EP_MIS_MSK Postion   */ 
#define USB_GINTMSK_EP_MIS_MSK_Msk    (0x1U << USB_GINTMSK_EP_MIS_MSK_Pos)                                        /*!< EP_MIS_MSK Mask      */
#define USB_GINTMSK_EP_MIS_MSK_Set(x) (((uint32_t) (x) << USB_GINTMSK_EP_MIS_MSK_Pos) & USB_GINTMSK_EP_MIS_MSK_Msk) /*!< EP_MIS_MSK Set Value */
#define USB_GINTMSK_EP_MIS_MSK_Get(x) (((uint32_t) (x) & USB_GINTMSK_EP_MIS_MSK_Msk) >> USB_GINTMSK_EP_MIS_MSK_Pos) /*!< EP_MIS_MSK Get Value */


#define USB_GINTMSK_EOPFMSK_Pos    (15U)                                                                       /*!< EOPFMSK Postion   */ 
#define USB_GINTMSK_EOPFMSK_Msk    (0x1U << USB_GINTMSK_EOPFMSK_Pos)                                           /*!< EOPFMSK Mask      */
#define USB_GINTMSK_EOPFMSK_Set(x) (((uint32_t) (x) << USB_GINTMSK_EOPFMSK_Pos) & USB_GINTMSK_EOPFMSK_Msk)     /*!< EOPFMSK Set Value */
#define USB_GINTMSK_EOPFMSK_Get(x) (((uint32_t) (x) & USB_GINTMSK_EOPFMSK_Msk) >> USB_GINTMSK_EOPFMSK_Pos)     /*!< EOPFMSK Get Value */


#define USB_GINTMSK_ISO_OUT_DROP_MSK_Pos    (14U)                                                                       /*!< ISO_OUT_DROP_MSK Postion   */ 
#define USB_GINTMSK_ISO_OUT_DROP_MSK_Msk    (0x1U << USB_GINTMSK_ISO_OUT_DROP_MSK_Pos)                                  /*!< ISO_OUT_DROP_MSK Mask      */
#define USB_GINTMSK_ISO_OUT_DROP_MSK_Set(x) (((uint32_t) (x) << USB_GINTMSK_ISO_OUT_DROP_MSK_Pos) & USB_GINTMSK_ISO_OUT_DROP_MSK_Msk) /*!< ISO_OUT_DROP_MSK Set Value */
#define USB_GINTMSK_ISO_OUT_DROP_MSK_Get(x) (((uint32_t) (x) & USB_GINTMSK_ISO_OUT_DROP_MSK_Msk) >> USB_GINTMSK_ISO_OUT_DROP_MSK_Pos) /*!< ISO_OUT_DROP_MSK Get Value */


#define USB_GINTMSK_ENUM_DONE_MSK_Pos    (13U)                                                                       /*!< ENUM_DONE_MSK Postion   */ 
#define USB_GINTMSK_ENUM_DONE_MSK_Msk    (0x1U << USB_GINTMSK_ENUM_DONE_MSK_Pos)                                     /*!< ENUM_DONE_MSK Mask      */
#define USB_GINTMSK_ENUM_DONE_MSK_Set(x) (((uint32_t) (x) << USB_GINTMSK_ENUM_DONE_MSK_Pos) & USB_GINTMSK_ENUM_DONE_MSK_Msk) /*!< ENUM_DONE_MSK Set Value */
#define USB_GINTMSK_ENUM_DONE_MSK_Get(x) (((uint32_t) (x) & USB_GINTMSK_ENUM_DONE_MSK_Msk) >> USB_GINTMSK_ENUM_DONE_MSK_Pos) /*!< ENUM_DONE_MSK Get Value */


#define USB_GINTMSK_USB_RST_MSK_Pos    (12U)                                                                       /*!< USB_RST_MSK Postion   */ 
#define USB_GINTMSK_USB_RST_MSK_Msk    (0x1U << USB_GINTMSK_USB_RST_MSK_Pos)                                       /*!< USB_RST_MSK Mask      */
#define USB_GINTMSK_USB_RST_MSK_Set(x) (((uint32_t) (x) << USB_GINTMSK_USB_RST_MSK_Pos) & USB_GINTMSK_USB_RST_MSK_Msk) /*!< USB_RST_MSK Set Value */
#define USB_GINTMSK_USB_RST_MSK_Get(x) (((uint32_t) (x) & USB_GINTMSK_USB_RST_MSK_Msk) >> USB_GINTMSK_USB_RST_MSK_Pos) /*!< USB_RST_MSK Get Value */


#define USB_GINTMSK_USB_SUSP_MSK_Pos    (11U)                                                                       /*!< USB_SUSP_MSK Postion   */ 
#define USB_GINTMSK_USB_SUSP_MSK_Msk    (0x1U << USB_GINTMSK_USB_SUSP_MSK_Pos)                                      /*!< USB_SUSP_MSK Mask      */
#define USB_GINTMSK_USB_SUSP_MSK_Set(x) (((uint32_t) (x) << USB_GINTMSK_USB_SUSP_MSK_Pos) & USB_GINTMSK_USB_SUSP_MSK_Msk) /*!< USB_SUSP_MSK Set Value */
#define USB_GINTMSK_USB_SUSP_MSK_Get(x) (((uint32_t) (x) & USB_GINTMSK_USB_SUSP_MSK_Msk) >> USB_GINTMSK_USB_SUSP_MSK_Pos) /*!< USB_SUSP_MSK Get Value */


#define USB_GINTMSK_ERLY_SUSP_MSK_Pos    (10U)                                                                       /*!< ERLY_SUSP_MSK Postion   */ 
#define USB_GINTMSK_ERLY_SUSP_MSK_Msk    (0x1U << USB_GINTMSK_ERLY_SUSP_MSK_Pos)                                     /*!< ERLY_SUSP_MSK Mask      */
#define USB_GINTMSK_ERLY_SUSP_MSK_Set(x) (((uint32_t) (x) << USB_GINTMSK_ERLY_SUSP_MSK_Pos) & USB_GINTMSK_ERLY_SUSP_MSK_Msk) /*!< ERLY_SUSP_MSK Set Value */
#define USB_GINTMSK_ERLY_SUSP_MSK_Get(x) (((uint32_t) (x) & USB_GINTMSK_ERLY_SUSP_MSK_Msk) >> USB_GINTMSK_ERLY_SUSP_MSK_Pos) /*!< ERLY_SUSP_MSK Get Value */


#define USB_GINTMSK_GOUT_NAK_EFF_MSK_Pos    (7U)                                                                        /*!< GOUT_NAK_EFF_MSK Postion   */ 
#define USB_GINTMSK_GOUT_NAK_EFF_MSK_Msk    (0x1U << USB_GINTMSK_GOUT_NAK_EFF_MSK_Pos)                                  /*!< GOUT_NAK_EFF_MSK Mask      */
#define USB_GINTMSK_GOUT_NAK_EFF_MSK_Set(x) (((uint32_t) (x) << USB_GINTMSK_GOUT_NAK_EFF_MSK_Pos) & USB_GINTMSK_GOUT_NAK_EFF_MSK_Msk) /*!< GOUT_NAK_EFF_MSK Set Value */
#define USB_GINTMSK_GOUT_NAK_EFF_MSK_Get(x) (((uint32_t) (x) & USB_GINTMSK_GOUT_NAK_EFF_MSK_Msk) >> USB_GINTMSK_GOUT_NAK_EFF_MSK_Pos) /*!< GOUT_NAK_EFF_MSK Get Value */


#define USB_GINTMSK_GIN_NAK_EFF_MSK_Pos    (6U)                                                                        /*!< GIN_NAK_EFF_MSK Postion   */ 
#define USB_GINTMSK_GIN_NAK_EFF_MSK_Msk    (0x1U << USB_GINTMSK_GIN_NAK_EFF_MSK_Pos)                                   /*!< GIN_NAK_EFF_MSK Mask      */
#define USB_GINTMSK_GIN_NAK_EFF_MSK_Set(x) (((uint32_t) (x) << USB_GINTMSK_GIN_NAK_EFF_MSK_Pos) & USB_GINTMSK_GIN_NAK_EFF_MSK_Msk) /*!< GIN_NAK_EFF_MSK Set Value */
#define USB_GINTMSK_GIN_NAK_EFF_MSK_Get(x) (((uint32_t) (x) & USB_GINTMSK_GIN_NAK_EFF_MSK_Msk) >> USB_GINTMSK_GIN_NAK_EFF_MSK_Pos) /*!< GIN_NAK_EFF_MSK Get Value */


#define USB_GINTMSK_NP_TXF_EMP_MSK_Pos    (5U)                                                                        /*!< NP_TXF_EMP_MSK Postion   */ 
#define USB_GINTMSK_NP_TXF_EMP_MSK_Msk    (0x1U << USB_GINTMSK_NP_TXF_EMP_MSK_Pos)                                    /*!< NP_TXF_EMP_MSK Mask      */
#define USB_GINTMSK_NP_TXF_EMP_MSK_Set(x) (((uint32_t) (x) << USB_GINTMSK_NP_TXF_EMP_MSK_Pos) & USB_GINTMSK_NP_TXF_EMP_MSK_Msk) /*!< NP_TXF_EMP_MSK Set Value */
#define USB_GINTMSK_NP_TXF_EMP_MSK_Get(x) (((uint32_t) (x) & USB_GINTMSK_NP_TXF_EMP_MSK_Msk) >> USB_GINTMSK_NP_TXF_EMP_MSK_Pos) /*!< NP_TXF_EMP_MSK Get Value */


#define USB_GINTMSK_RXF_LVL_MSK_Pos    (4U)                                                                        /*!< RXF_LVL_MSK Postion   */ 
#define USB_GINTMSK_RXF_LVL_MSK_Msk    (0x1U << USB_GINTMSK_RXF_LVL_MSK_Pos)                                       /*!< RXF_LVL_MSK Mask      */
#define USB_GINTMSK_RXF_LVL_MSK_Set(x) (((uint32_t) (x) << USB_GINTMSK_RXF_LVL_MSK_Pos) & USB_GINTMSK_RXF_LVL_MSK_Msk) /*!< RXF_LVL_MSK Set Value */
#define USB_GINTMSK_RXF_LVL_MSK_Get(x) (((uint32_t) (x) & USB_GINTMSK_RXF_LVL_MSK_Msk) >> USB_GINTMSK_RXF_LVL_MSK_Pos) /*!< RXF_LVL_MSK Get Value */


#define USB_GINTMSK_SOF_MSK_Pos    (3U)                                                                        /*!< SOF_MSK Postion   */ 
#define USB_GINTMSK_SOF_MSK_Msk    (0x1U << USB_GINTMSK_SOF_MSK_Pos)                                           /*!< SOF_MSK Mask      */
#define USB_GINTMSK_SOF_MSK_Set(x) (((uint32_t) (x) << USB_GINTMSK_SOF_MSK_Pos) & USB_GINTMSK_SOF_MSK_Msk)     /*!< SOF_MSK Set Value */
#define USB_GINTMSK_SOF_MSK_Get(x) (((uint32_t) (x) & USB_GINTMSK_SOF_MSK_Msk) >> USB_GINTMSK_SOF_MSK_Pos)     /*!< SOF_MSK Get Value */


#define USB_GINTMSK_OTG_INT_MSK_Pos    (2U)                                                                        /*!< OTG_INT_MSK Postion   */ 
#define USB_GINTMSK_OTG_INT_MSK_Msk    (0x1U << USB_GINTMSK_OTG_INT_MSK_Pos)                                       /*!< OTG_INT_MSK Mask      */
#define USB_GINTMSK_OTG_INT_MSK_Set(x) (((uint32_t) (x) << USB_GINTMSK_OTG_INT_MSK_Pos) & USB_GINTMSK_OTG_INT_MSK_Msk) /*!< OTG_INT_MSK Set Value */
#define USB_GINTMSK_OTG_INT_MSK_Get(x) (((uint32_t) (x) & USB_GINTMSK_OTG_INT_MSK_Msk) >> USB_GINTMSK_OTG_INT_MSK_Pos) /*!< OTG_INT_MSK Get Value */


#define USB_GINTMSK_MODE_MIS_MSK_Pos    (1U)                                                                        /*!< MODE_MIS_MSK Postion   */ 
#define USB_GINTMSK_MODE_MIS_MSK_Msk    (0x1U << USB_GINTMSK_MODE_MIS_MSK_Pos)                                      /*!< MODE_MIS_MSK Mask      */
#define USB_GINTMSK_MODE_MIS_MSK_Set(x) (((uint32_t) (x) << USB_GINTMSK_MODE_MIS_MSK_Pos) & USB_GINTMSK_MODE_MIS_MSK_Msk) /*!< MODE_MIS_MSK Set Value */
#define USB_GINTMSK_MODE_MIS_MSK_Get(x) (((uint32_t) (x) & USB_GINTMSK_MODE_MIS_MSK_Msk) >> USB_GINTMSK_MODE_MIS_MSK_Pos) /*!< MODE_MIS_MSK Get Value */


/* GRXSTSR bitfield */
#define USB_GRXSTSR_GRXSTSR_FN_Pos    (21U)                                                                       /*!< GRXSTSR_FN Postion   */ 
#define USB_GRXSTSR_GRXSTSR_FN_Msk    (0xfU << USB_GRXSTSR_GRXSTSR_FN_Pos)                                        /*!< GRXSTSR_FN Mask      */
#define USB_GRXSTSR_GRXSTSR_FN_Set(x) (((uint32_t) (x) << USB_GRXSTSR_GRXSTSR_FN_Pos) & USB_GRXSTSR_GRXSTSR_FN_Msk) /*!< GRXSTSR_FN Set Value */
#define USB_GRXSTSR_GRXSTSR_FN_Get(x) (((uint32_t) (x) & USB_GRXSTSR_GRXSTSR_FN_Msk) >> USB_GRXSTSR_GRXSTSR_FN_Pos) /*!< GRXSTSR_FN Get Value */


#define USB_GRXSTSR_GRXSTSR_PKT_STS_Pos    (17U)                                                                       /*!< GRXSTSR_PKT_STS Postion   */ 
#define USB_GRXSTSR_GRXSTSR_PKT_STS_Msk    (0xfU << USB_GRXSTSR_GRXSTSR_PKT_STS_Pos)                                   /*!< GRXSTSR_PKT_STS Mask      */
#define USB_GRXSTSR_GRXSTSR_PKT_STS_Set(x) (((uint32_t) (x) << USB_GRXSTSR_GRXSTSR_PKT_STS_Pos) & USB_GRXSTSR_GRXSTSR_PKT_STS_Msk) /*!< GRXSTSR_PKT_STS Set Value */
#define USB_GRXSTSR_GRXSTSR_PKT_STS_Get(x) (((uint32_t) (x) & USB_GRXSTSR_GRXSTSR_PKT_STS_Msk) >> USB_GRXSTSR_GRXSTSR_PKT_STS_Pos) /*!< GRXSTSR_PKT_STS Get Value */


#define USB_GRXSTSR_GRXSTSR_DPID_Pos    (15U)                                                                       /*!< GRXSTSR_DPID Postion   */ 
#define USB_GRXSTSR_GRXSTSR_DPID_Msk    (0x3U << USB_GRXSTSR_GRXSTSR_DPID_Pos)                                      /*!< GRXSTSR_DPID Mask      */
#define USB_GRXSTSR_GRXSTSR_DPID_Set(x) (((uint32_t) (x) << USB_GRXSTSR_GRXSTSR_DPID_Pos) & USB_GRXSTSR_GRXSTSR_DPID_Msk) /*!< GRXSTSR_DPID Set Value */
#define USB_GRXSTSR_GRXSTSR_DPID_Get(x) (((uint32_t) (x) & USB_GRXSTSR_GRXSTSR_DPID_Msk) >> USB_GRXSTSR_GRXSTSR_DPID_Pos) /*!< GRXSTSR_DPID Get Value */


#define USB_GRXSTSR_GRXSTSR_BCNT_Pos    (4U)                                                                        /*!< GRXSTSR_BCNT Postion   */ 
#define USB_GRXSTSR_GRXSTSR_BCNT_Msk    (0x7ffU << USB_GRXSTSR_GRXSTSR_BCNT_Pos)                                    /*!< GRXSTSR_BCNT Mask      */
#define USB_GRXSTSR_GRXSTSR_BCNT_Set(x) (((uint32_t) (x) << USB_GRXSTSR_GRXSTSR_BCNT_Pos) & USB_GRXSTSR_GRXSTSR_BCNT_Msk) /*!< GRXSTSR_BCNT Set Value */
#define USB_GRXSTSR_GRXSTSR_BCNT_Get(x) (((uint32_t) (x) & USB_GRXSTSR_GRXSTSR_BCNT_Msk) >> USB_GRXSTSR_GRXSTSR_BCNT_Pos) /*!< GRXSTSR_BCNT Get Value */


#define USB_GRXSTSR_GRXSTSR_CH_NUM_Pos    (0U)                                                                        /*!< GRXSTSR_CH_NUM Postion   */ 
#define USB_GRXSTSR_GRXSTSR_CH_NUM_Msk    (0xfU << USB_GRXSTSR_GRXSTSR_CH_NUM_Pos)                                    /*!< GRXSTSR_CH_NUM Mask      */
#define USB_GRXSTSR_GRXSTSR_CH_NUM_Set(x) (((uint32_t) (x) << USB_GRXSTSR_GRXSTSR_CH_NUM_Pos) & USB_GRXSTSR_GRXSTSR_CH_NUM_Msk) /*!< GRXSTSR_CH_NUM Set Value */
#define USB_GRXSTSR_GRXSTSR_CH_NUM_Get(x) (((uint32_t) (x) & USB_GRXSTSR_GRXSTSR_CH_NUM_Msk) >> USB_GRXSTSR_GRXSTSR_CH_NUM_Pos) /*!< GRXSTSR_CH_NUM Get Value */


/* GRXSTSP bitfield */
#define USB_GRXSTSP_GRXSTSP_FN_Pos    (21U)                                                                       /*!< GRXSTSP_FN Postion   */ 
#define USB_GRXSTSP_GRXSTSP_FN_Msk    (0xfU << USB_GRXSTSP_GRXSTSP_FN_Pos)                                        /*!< GRXSTSP_FN Mask      */
#define USB_GRXSTSP_GRXSTSP_FN_Set(x) (((uint32_t) (x) << USB_GRXSTSP_GRXSTSP_FN_Pos) & USB_GRXSTSP_GRXSTSP_FN_Msk) /*!< GRXSTSP_FN Set Value */
#define USB_GRXSTSP_GRXSTSP_FN_Get(x) (((uint32_t) (x) & USB_GRXSTSP_GRXSTSP_FN_Msk) >> USB_GRXSTSP_GRXSTSP_FN_Pos) /*!< GRXSTSP_FN Get Value */


#define USB_GRXSTSP_GRXSTSP_PKT_STS_Pos    (17U)                                                                       /*!< GRXSTSP_PKT_STS Postion   */ 
#define USB_GRXSTSP_GRXSTSP_PKT_STS_Msk    (0xfU << USB_GRXSTSP_GRXSTSP_PKT_STS_Pos)                                   /*!< GRXSTSP_PKT_STS Mask      */
#define USB_GRXSTSP_GRXSTSP_PKT_STS_Set(x) (((uint32_t) (x) << USB_GRXSTSP_GRXSTSP_PKT_STS_Pos) & USB_GRXSTSP_GRXSTSP_PKT_STS_Msk) /*!< GRXSTSP_PKT_STS Set Value */
#define USB_GRXSTSP_GRXSTSP_PKT_STS_Get(x) (((uint32_t) (x) & USB_GRXSTSP_GRXSTSP_PKT_STS_Msk) >> USB_GRXSTSP_GRXSTSP_PKT_STS_Pos) /*!< GRXSTSP_PKT_STS Get Value */


#define USB_GRXSTSP_GRXSTSP_DPID_Pos    (15U)                                                                       /*!< GRXSTSP_DPID Postion   */ 
#define USB_GRXSTSP_GRXSTSP_DPID_Msk    (0x3U << USB_GRXSTSP_GRXSTSP_DPID_Pos)                                      /*!< GRXSTSP_DPID Mask      */
#define USB_GRXSTSP_GRXSTSP_DPID_Set(x) (((uint32_t) (x) << USB_GRXSTSP_GRXSTSP_DPID_Pos) & USB_GRXSTSP_GRXSTSP_DPID_Msk) /*!< GRXSTSP_DPID Set Value */
#define USB_GRXSTSP_GRXSTSP_DPID_Get(x) (((uint32_t) (x) & USB_GRXSTSP_GRXSTSP_DPID_Msk) >> USB_GRXSTSP_GRXSTSP_DPID_Pos) /*!< GRXSTSP_DPID Get Value */


#define USB_GRXSTSP_GRXSTSP_BCNT_Pos    (4U)                                                                        /*!< GRXSTSP_BCNT Postion   */ 
#define USB_GRXSTSP_GRXSTSP_BCNT_Msk    (0x7ffU << USB_GRXSTSP_GRXSTSP_BCNT_Pos)                                    /*!< GRXSTSP_BCNT Mask      */
#define USB_GRXSTSP_GRXSTSP_BCNT_Set(x) (((uint32_t) (x) << USB_GRXSTSP_GRXSTSP_BCNT_Pos) & USB_GRXSTSP_GRXSTSP_BCNT_Msk) /*!< GRXSTSP_BCNT Set Value */
#define USB_GRXSTSP_GRXSTSP_BCNT_Get(x) (((uint32_t) (x) & USB_GRXSTSP_GRXSTSP_BCNT_Msk) >> USB_GRXSTSP_GRXSTSP_BCNT_Pos) /*!< GRXSTSP_BCNT Get Value */


#define USB_GRXSTSP_GRXSTSP_CH_NUM_Pos    (0U)                                                                        /*!< GRXSTSP_CH_NUM Postion   */ 
#define USB_GRXSTSP_GRXSTSP_CH_NUM_Msk    (0xfU << USB_GRXSTSP_GRXSTSP_CH_NUM_Pos)                                    /*!< GRXSTSP_CH_NUM Mask      */
#define USB_GRXSTSP_GRXSTSP_CH_NUM_Set(x) (((uint32_t) (x) << USB_GRXSTSP_GRXSTSP_CH_NUM_Pos) & USB_GRXSTSP_GRXSTSP_CH_NUM_Msk) /*!< GRXSTSP_CH_NUM Set Value */
#define USB_GRXSTSP_GRXSTSP_CH_NUM_Get(x) (((uint32_t) (x) & USB_GRXSTSP_GRXSTSP_CH_NUM_Msk) >> USB_GRXSTSP_GRXSTSP_CH_NUM_Pos) /*!< GRXSTSP_CH_NUM Get Value */


/* GRXFSIZ bitfield */
#define USB_GRXFSIZ_RXF_DEP_Pos    (0U)                                                                        /*!< RXF_DEP Postion   */ 
#define USB_GRXFSIZ_RXF_DEP_Msk    (0x7ffU << USB_GRXFSIZ_RXF_DEP_Pos)                                         /*!< RXF_DEP Mask      */
#define USB_GRXFSIZ_RXF_DEP_Set(x) (((uint32_t) (x) << USB_GRXFSIZ_RXF_DEP_Pos) & USB_GRXFSIZ_RXF_DEP_Msk)     /*!< RXF_DEP Set Value */
#define USB_GRXFSIZ_RXF_DEP_Get(x) (((uint32_t) (x) & USB_GRXFSIZ_RXF_DEP_Msk) >> USB_GRXFSIZ_RXF_DEP_Pos)     /*!< RXF_DEP Get Value */


/* GNPTXFSIZ bitfield */
#define USB_GNPTXFSIZ_NP_TXF_DEP_Pos    (16U)                                                                       /*!< NP_TXF_DEP Postion   */ 
#define USB_GNPTXFSIZ_NP_TXF_DEP_Msk    (0x7ffU << USB_GNPTXFSIZ_NP_TXF_DEP_Pos)                                    /*!< NP_TXF_DEP Mask      */
#define USB_GNPTXFSIZ_NP_TXF_DEP_Set(x) (((uint32_t) (x) << USB_GNPTXFSIZ_NP_TXF_DEP_Pos) & USB_GNPTXFSIZ_NP_TXF_DEP_Msk) /*!< NP_TXF_DEP Set Value */
#define USB_GNPTXFSIZ_NP_TXF_DEP_Get(x) (((uint32_t) (x) & USB_GNPTXFSIZ_NP_TXF_DEP_Msk) >> USB_GNPTXFSIZ_NP_TXF_DEP_Pos) /*!< NP_TXF_DEP Get Value */


#define USB_GNPTXFSIZ_NP_TXF_ST_ADDR_Pos    (0U)                                                                        /*!< NP_TXF_ST_ADDR Postion   */ 
#define USB_GNPTXFSIZ_NP_TXF_ST_ADDR_Msk    (0x7ffU << USB_GNPTXFSIZ_NP_TXF_ST_ADDR_Pos)                                /*!< NP_TXF_ST_ADDR Mask      */
#define USB_GNPTXFSIZ_NP_TXF_ST_ADDR_Set(x) (((uint32_t) (x) << USB_GNPTXFSIZ_NP_TXF_ST_ADDR_Pos) & USB_GNPTXFSIZ_NP_TXF_ST_ADDR_Msk) /*!< NP_TXF_ST_ADDR Set Value */
#define USB_GNPTXFSIZ_NP_TXF_ST_ADDR_Get(x) (((uint32_t) (x) & USB_GNPTXFSIZ_NP_TXF_ST_ADDR_Msk) >> USB_GNPTXFSIZ_NP_TXF_ST_ADDR_Pos) /*!< NP_TXF_ST_ADDR Get Value */


/* GNPTXSTS bitfield */
#define USB_GNPTXSTS_NP_TX_QTOP_Pos    (24U)                                                                       /*!< NP_TX_QTOP Postion   */ 
#define USB_GNPTXSTS_NP_TX_QTOP_Msk    (0x7fU << USB_GNPTXSTS_NP_TX_QTOP_Pos)                                      /*!< NP_TX_QTOP Mask      */
#define USB_GNPTXSTS_NP_TX_QTOP_Set(x) (((uint32_t) (x) << USB_GNPTXSTS_NP_TX_QTOP_Pos) & USB_GNPTXSTS_NP_TX_QTOP_Msk) /*!< NP_TX_QTOP Set Value */
#define USB_GNPTXSTS_NP_TX_QTOP_Get(x) (((uint32_t) (x) & USB_GNPTXSTS_NP_TX_QTOP_Msk) >> USB_GNPTXSTS_NP_TX_QTOP_Pos) /*!< NP_TX_QTOP Get Value */


#define USB_GNPTXSTS_NP_TX_QSPC_AVAIL_Pos    (16U)                                                                       /*!< NP_TX_QSPC_AVAIL Postion   */ 
#define USB_GNPTXSTS_NP_TX_QSPC_AVAIL_Msk    (0xffU << USB_GNPTXSTS_NP_TX_QSPC_AVAIL_Pos)                                /*!< NP_TX_QSPC_AVAIL Mask      */
#define USB_GNPTXSTS_NP_TX_QSPC_AVAIL_Set(x) (((uint32_t) (x) << USB_GNPTXSTS_NP_TX_QSPC_AVAIL_Pos) & USB_GNPTXSTS_NP_TX_QSPC_AVAIL_Msk) /*!< NP_TX_QSPC_AVAIL Set Value */
#define USB_GNPTXSTS_NP_TX_QSPC_AVAIL_Get(x) (((uint32_t) (x) & USB_GNPTXSTS_NP_TX_QSPC_AVAIL_Msk) >> USB_GNPTXSTS_NP_TX_QSPC_AVAIL_Pos) /*!< NP_TX_QSPC_AVAIL Get Value */


#define USB_GNPTXSTS_NP_TXF_SPC_AVAIL_Pos    (0U)                                                                        /*!< NP_TXF_SPC_AVAIL Postion   */ 
#define USB_GNPTXSTS_NP_TXF_SPC_AVAIL_Msk    (0xffffU << USB_GNPTXSTS_NP_TXF_SPC_AVAIL_Pos)                              /*!< NP_TXF_SPC_AVAIL Mask      */
#define USB_GNPTXSTS_NP_TXF_SPC_AVAIL_Set(x) (((uint32_t) (x) << USB_GNPTXSTS_NP_TXF_SPC_AVAIL_Pos) & USB_GNPTXSTS_NP_TXF_SPC_AVAIL_Msk) /*!< NP_TXF_SPC_AVAIL Set Value */
#define USB_GNPTXSTS_NP_TXF_SPC_AVAIL_Get(x) (((uint32_t) (x) & USB_GNPTXSTS_NP_TXF_SPC_AVAIL_Msk) >> USB_GNPTXSTS_NP_TXF_SPC_AVAIL_Pos) /*!< NP_TXF_SPC_AVAIL Get Value */


/* GSNPSID bitfield */
#define USB_GSNPSID_SYNOPSYS_ID_Pos    (0U)                                                                        /*!< SYNOPSYS_ID Postion   */ 
#define USB_GSNPSID_SYNOPSYS_ID_Msk    (0xffffffffU << USB_GSNPSID_SYNOPSYS_ID_Pos)                                /*!< SYNOPSYS_ID Mask      */
#define USB_GSNPSID_SYNOPSYS_ID_Set(x) (((uint32_t) (x) << USB_GSNPSID_SYNOPSYS_ID_Pos) & USB_GSNPSID_SYNOPSYS_ID_Msk) /*!< SYNOPSYS_ID Set Value */
#define USB_GSNPSID_SYNOPSYS_ID_Get(x) (((uint32_t) (x) & USB_GSNPSID_SYNOPSYS_ID_Msk) >> USB_GSNPSID_SYNOPSYS_ID_Pos) /*!< SYNOPSYS_ID Get Value */


/* GHWCFG1 bitfield */
#define USB_GHWCFG1_EP_DIR_Pos    (0U)                                                                        /*!< EP_DIR Postion   */ 
#define USB_GHWCFG1_EP_DIR_Msk    (0xffffffffU << USB_GHWCFG1_EP_DIR_Pos)                                     /*!< EP_DIR Mask      */
#define USB_GHWCFG1_EP_DIR_Set(x) (((uint32_t) (x) << USB_GHWCFG1_EP_DIR_Pos) & USB_GHWCFG1_EP_DIR_Msk)       /*!< EP_DIR Set Value */
#define USB_GHWCFG1_EP_DIR_Get(x) (((uint32_t) (x) & USB_GHWCFG1_EP_DIR_Msk) >> USB_GHWCFG1_EP_DIR_Pos)       /*!< EP_DIR Get Value */


/* GHWCFG2 bitfield */
#define USB_GHWCFG2_TKN_QDEPTH_Pos    (26U)                                                                       /*!< TKN_QDEPTH Postion   */ 
#define USB_GHWCFG2_TKN_QDEPTH_Msk    (0x1fU << USB_GHWCFG2_TKN_QDEPTH_Pos)                                       /*!< TKN_QDEPTH Mask      */
#define USB_GHWCFG2_TKN_QDEPTH_Set(x) (((uint32_t) (x) << USB_GHWCFG2_TKN_QDEPTH_Pos) & USB_GHWCFG2_TKN_QDEPTH_Msk) /*!< TKN_QDEPTH Set Value */
#define USB_GHWCFG2_TKN_QDEPTH_Get(x) (((uint32_t) (x) & USB_GHWCFG2_TKN_QDEPTH_Msk) >> USB_GHWCFG2_TKN_QDEPTH_Pos) /*!< TKN_QDEPTH Get Value */


#define USB_GHWCFG2_PTX_QDEPTH_Pos    (24U)                                                                       /*!< PTX_QDEPTH Postion   */ 
#define USB_GHWCFG2_PTX_QDEPTH_Msk    (0x3U << USB_GHWCFG2_PTX_QDEPTH_Pos)                                        /*!< PTX_QDEPTH Mask      */
#define USB_GHWCFG2_PTX_QDEPTH_Set(x) (((uint32_t) (x) << USB_GHWCFG2_PTX_QDEPTH_Pos) & USB_GHWCFG2_PTX_QDEPTH_Msk) /*!< PTX_QDEPTH Set Value */
#define USB_GHWCFG2_PTX_QDEPTH_Get(x) (((uint32_t) (x) & USB_GHWCFG2_PTX_QDEPTH_Msk) >> USB_GHWCFG2_PTX_QDEPTH_Pos) /*!< PTX_QDEPTH Get Value */


#define USB_GHWCFG2_NP_TX_QDEPTH_Pos    (22U)                                                                       /*!< NP_TX_QDEPTH Postion   */ 
#define USB_GHWCFG2_NP_TX_QDEPTH_Msk    (0x3U << USB_GHWCFG2_NP_TX_QDEPTH_Pos)                                      /*!< NP_TX_QDEPTH Mask      */
#define USB_GHWCFG2_NP_TX_QDEPTH_Set(x) (((uint32_t) (x) << USB_GHWCFG2_NP_TX_QDEPTH_Pos) & USB_GHWCFG2_NP_TX_QDEPTH_Msk) /*!< NP_TX_QDEPTH Set Value */
#define USB_GHWCFG2_NP_TX_QDEPTH_Get(x) (((uint32_t) (x) & USB_GHWCFG2_NP_TX_QDEPTH_Msk) >> USB_GHWCFG2_NP_TX_QDEPTH_Pos) /*!< NP_TX_QDEPTH Get Value */


#define USB_GHWCFG2_MULTI_PROC_INTRPT_Pos    (20U)                                                                       /*!< MULTI_PROC_INTRPT Postion   */ 
#define USB_GHWCFG2_MULTI_PROC_INTRPT_Msk    (0x1U << USB_GHWCFG2_MULTI_PROC_INTRPT_Pos)                                 /*!< MULTI_PROC_INTRPT Mask      */
#define USB_GHWCFG2_MULTI_PROC_INTRPT_Set(x) (((uint32_t) (x) << USB_GHWCFG2_MULTI_PROC_INTRPT_Pos) & USB_GHWCFG2_MULTI_PROC_INTRPT_Msk) /*!< MULTI_PROC_INTRPT Set Value */
#define USB_GHWCFG2_MULTI_PROC_INTRPT_Get(x) (((uint32_t) (x) & USB_GHWCFG2_MULTI_PROC_INTRPT_Msk) >> USB_GHWCFG2_MULTI_PROC_INTRPT_Pos) /*!< MULTI_PROC_INTRPT Get Value */


#define USB_GHWCFG2_DYN_FIFO_SIZING_Pos    (19U)                                                                       /*!< DYN_FIFO_SIZING Postion   */ 
#define USB_GHWCFG2_DYN_FIFO_SIZING_Msk    (0x1U << USB_GHWCFG2_DYN_FIFO_SIZING_Pos)                                   /*!< DYN_FIFO_SIZING Mask      */
#define USB_GHWCFG2_DYN_FIFO_SIZING_Set(x) (((uint32_t) (x) << USB_GHWCFG2_DYN_FIFO_SIZING_Pos) & USB_GHWCFG2_DYN_FIFO_SIZING_Msk) /*!< DYN_FIFO_SIZING Set Value */
#define USB_GHWCFG2_DYN_FIFO_SIZING_Get(x) (((uint32_t) (x) & USB_GHWCFG2_DYN_FIFO_SIZING_Msk) >> USB_GHWCFG2_DYN_FIFO_SIZING_Pos) /*!< DYN_FIFO_SIZING Get Value */


#define USB_GHWCFG2_PERIO_SUPPORT_Pos    (18U)                                                                       /*!< PERIO_SUPPORT Postion   */ 
#define USB_GHWCFG2_PERIO_SUPPORT_Msk    (0x1U << USB_GHWCFG2_PERIO_SUPPORT_Pos)                                     /*!< PERIO_SUPPORT Mask      */
#define USB_GHWCFG2_PERIO_SUPPORT_Set(x) (((uint32_t) (x) << USB_GHWCFG2_PERIO_SUPPORT_Pos) & USB_GHWCFG2_PERIO_SUPPORT_Msk) /*!< PERIO_SUPPORT Set Value */
#define USB_GHWCFG2_PERIO_SUPPORT_Get(x) (((uint32_t) (x) & USB_GHWCFG2_PERIO_SUPPORT_Msk) >> USB_GHWCFG2_PERIO_SUPPORT_Pos) /*!< PERIO_SUPPORT Get Value */


#define USB_GHWCFG2_NUM_HST_CHNL_Pos    (14U)                                                                       /*!< NUM_HST_CHNL Postion   */ 
#define USB_GHWCFG2_NUM_HST_CHNL_Msk    (0xfU << USB_GHWCFG2_NUM_HST_CHNL_Pos)                                      /*!< NUM_HST_CHNL Mask      */
#define USB_GHWCFG2_NUM_HST_CHNL_Set(x) (((uint32_t) (x) << USB_GHWCFG2_NUM_HST_CHNL_Pos) & USB_GHWCFG2_NUM_HST_CHNL_Msk) /*!< NUM_HST_CHNL Set Value */
#define USB_GHWCFG2_NUM_HST_CHNL_Get(x) (((uint32_t) (x) & USB_GHWCFG2_NUM_HST_CHNL_Msk) >> USB_GHWCFG2_NUM_HST_CHNL_Pos) /*!< NUM_HST_CHNL Get Value */


#define USB_GHWCFG2_NUM_DEV_EPS_Pos    (10U)                                                                       /*!< NUM_DEV_EPS Postion   */ 
#define USB_GHWCFG2_NUM_DEV_EPS_Msk    (0xfU << USB_GHWCFG2_NUM_DEV_EPS_Pos)                                       /*!< NUM_DEV_EPS Mask      */
#define USB_GHWCFG2_NUM_DEV_EPS_Set(x) (((uint32_t) (x) << USB_GHWCFG2_NUM_DEV_EPS_Pos) & USB_GHWCFG2_NUM_DEV_EPS_Msk) /*!< NUM_DEV_EPS Set Value */
#define USB_GHWCFG2_NUM_DEV_EPS_Get(x) (((uint32_t) (x) & USB_GHWCFG2_NUM_DEV_EPS_Msk) >> USB_GHWCFG2_NUM_DEV_EPS_Pos) /*!< NUM_DEV_EPS Get Value */


#define USB_GHWCFG2_FS_PHY_TYPE_Pos    (8U)                                                                        /*!< FS_PHY_TYPE Postion   */ 
#define USB_GHWCFG2_FS_PHY_TYPE_Msk    (0x3U << USB_GHWCFG2_FS_PHY_TYPE_Pos)                                       /*!< FS_PHY_TYPE Mask      */
#define USB_GHWCFG2_FS_PHY_TYPE_Set(x) (((uint32_t) (x) << USB_GHWCFG2_FS_PHY_TYPE_Pos) & USB_GHWCFG2_FS_PHY_TYPE_Msk) /*!< FS_PHY_TYPE Set Value */
#define USB_GHWCFG2_FS_PHY_TYPE_Get(x) (((uint32_t) (x) & USB_GHWCFG2_FS_PHY_TYPE_Msk) >> USB_GHWCFG2_FS_PHY_TYPE_Pos) /*!< FS_PHY_TYPE Get Value */


#define USB_GHWCFG2_HSPHY_TYPE_Pos    (6U)                                                                        /*!< HSPHY_TYPE Postion   */ 
#define USB_GHWCFG2_HSPHY_TYPE_Msk    (0x3U << USB_GHWCFG2_HSPHY_TYPE_Pos)                                        /*!< HSPHY_TYPE Mask      */
#define USB_GHWCFG2_HSPHY_TYPE_Set(x) (((uint32_t) (x) << USB_GHWCFG2_HSPHY_TYPE_Pos) & USB_GHWCFG2_HSPHY_TYPE_Msk) /*!< HSPHY_TYPE Set Value */
#define USB_GHWCFG2_HSPHY_TYPE_Get(x) (((uint32_t) (x) & USB_GHWCFG2_HSPHY_TYPE_Msk) >> USB_GHWCFG2_HSPHY_TYPE_Pos) /*!< HSPHY_TYPE Get Value */


#define USB_GHWCFG2_SING_PNT_Pos    (5U)                                                                        /*!< SING_PNT Postion   */ 
#define USB_GHWCFG2_SING_PNT_Msk    (0x1U << USB_GHWCFG2_SING_PNT_Pos)                                          /*!< SING_PNT Mask      */
#define USB_GHWCFG2_SING_PNT_Set(x) (((uint32_t) (x) << USB_GHWCFG2_SING_PNT_Pos) & USB_GHWCFG2_SING_PNT_Msk)   /*!< SING_PNT Set Value */
#define USB_GHWCFG2_SING_PNT_Get(x) (((uint32_t) (x) & USB_GHWCFG2_SING_PNT_Msk) >> USB_GHWCFG2_SING_PNT_Pos)   /*!< SING_PNT Get Value */


#define USB_GHWCFG2_OTG_ARCH_Pos    (3U)                                                                        /*!< OTG_ARCH Postion   */ 
#define USB_GHWCFG2_OTG_ARCH_Msk    (0x3U << USB_GHWCFG2_OTG_ARCH_Pos)                                          /*!< OTG_ARCH Mask      */
#define USB_GHWCFG2_OTG_ARCH_Set(x) (((uint32_t) (x) << USB_GHWCFG2_OTG_ARCH_Pos) & USB_GHWCFG2_OTG_ARCH_Msk)   /*!< OTG_ARCH Set Value */
#define USB_GHWCFG2_OTG_ARCH_Get(x) (((uint32_t) (x) & USB_GHWCFG2_OTG_ARCH_Msk) >> USB_GHWCFG2_OTG_ARCH_Pos)   /*!< OTG_ARCH Get Value */


#define USB_GHWCFG2_OTG_MODE_Pos    (0U)                                                                        /*!< OTG_MODE Postion   */ 
#define USB_GHWCFG2_OTG_MODE_Msk    (0x7U << USB_GHWCFG2_OTG_MODE_Pos)                                          /*!< OTG_MODE Mask      */
#define USB_GHWCFG2_OTG_MODE_Set(x) (((uint32_t) (x) << USB_GHWCFG2_OTG_MODE_Pos) & USB_GHWCFG2_OTG_MODE_Msk)   /*!< OTG_MODE Set Value */
#define USB_GHWCFG2_OTG_MODE_Get(x) (((uint32_t) (x) & USB_GHWCFG2_OTG_MODE_Msk) >> USB_GHWCFG2_OTG_MODE_Pos)   /*!< OTG_MODE Get Value */


/* GHWCFG3 bitfield */
#define USB_GHWCFG3_DFIFO_DEPTH_Pos    (16U)                                                                       /*!< DFIFO_DEPTH Postion   */ 
#define USB_GHWCFG3_DFIFO_DEPTH_Msk    (0xffffU << USB_GHWCFG3_DFIFO_DEPTH_Pos)                                    /*!< DFIFO_DEPTH Mask      */
#define USB_GHWCFG3_DFIFO_DEPTH_Set(x) (((uint32_t) (x) << USB_GHWCFG3_DFIFO_DEPTH_Pos) & USB_GHWCFG3_DFIFO_DEPTH_Msk) /*!< DFIFO_DEPTH Set Value */
#define USB_GHWCFG3_DFIFO_DEPTH_Get(x) (((uint32_t) (x) & USB_GHWCFG3_DFIFO_DEPTH_Msk) >> USB_GHWCFG3_DFIFO_DEPTH_Pos) /*!< DFIFO_DEPTH Get Value */


#define USB_GHWCFG3_LPMMODE_Pos    (15U)                                                                       /*!< LPMMODE Postion   */ 
#define USB_GHWCFG3_LPMMODE_Msk    (0x1U << USB_GHWCFG3_LPMMODE_Pos)                                           /*!< LPMMODE Mask      */
#define USB_GHWCFG3_LPMMODE_Set(x) (((uint32_t) (x) << USB_GHWCFG3_LPMMODE_Pos) & USB_GHWCFG3_LPMMODE_Msk)     /*!< LPMMODE Set Value */
#define USB_GHWCFG3_LPMMODE_Get(x) (((uint32_t) (x) & USB_GHWCFG3_LPMMODE_Msk) >> USB_GHWCFG3_LPMMODE_Pos)     /*!< LPMMODE Get Value */


#define USB_GHWCFG3_BCSUPPORT_Pos    (14U)                                                                       /*!< BCSUPPORT Postion   */ 
#define USB_GHWCFG3_BCSUPPORT_Msk    (0x1U << USB_GHWCFG3_BCSUPPORT_Pos)                                         /*!< BCSUPPORT Mask      */
#define USB_GHWCFG3_BCSUPPORT_Set(x) (((uint32_t) (x) << USB_GHWCFG3_BCSUPPORT_Pos) & USB_GHWCFG3_BCSUPPORT_Msk) /*!< BCSUPPORT Set Value */
#define USB_GHWCFG3_BCSUPPORT_Get(x) (((uint32_t) (x) & USB_GHWCFG3_BCSUPPORT_Msk) >> USB_GHWCFG3_BCSUPPORT_Pos) /*!< BCSUPPORT Get Value */


#define USB_GHWCFG3_HSICMODE_Pos    (13U)                                                                       /*!< HSICMODE Postion   */ 
#define USB_GHWCFG3_HSICMODE_Msk    (0x1U << USB_GHWCFG3_HSICMODE_Pos)                                          /*!< HSICMODE Mask      */
#define USB_GHWCFG3_HSICMODE_Set(x) (((uint32_t) (x) << USB_GHWCFG3_HSICMODE_Pos) & USB_GHWCFG3_HSICMODE_Msk)   /*!< HSICMODE Set Value */
#define USB_GHWCFG3_HSICMODE_Get(x) (((uint32_t) (x) & USB_GHWCFG3_HSICMODE_Msk) >> USB_GHWCFG3_HSICMODE_Pos)   /*!< HSICMODE Get Value */


#define USB_GHWCFG3_ADPSUPPORT_Pos    (12U)                                                                       /*!< ADPSUPPORT Postion   */ 
#define USB_GHWCFG3_ADPSUPPORT_Msk    (0x1U << USB_GHWCFG3_ADPSUPPORT_Pos)                                        /*!< ADPSUPPORT Mask      */
#define USB_GHWCFG3_ADPSUPPORT_Set(x) (((uint32_t) (x) << USB_GHWCFG3_ADPSUPPORT_Pos) & USB_GHWCFG3_ADPSUPPORT_Msk) /*!< ADPSUPPORT Set Value */
#define USB_GHWCFG3_ADPSUPPORT_Get(x) (((uint32_t) (x) & USB_GHWCFG3_ADPSUPPORT_Msk) >> USB_GHWCFG3_ADPSUPPORT_Pos) /*!< ADPSUPPORT Get Value */


#define USB_GHWCFG3_RST_TYPE_Pos    (11U)                                                                       /*!< RST_TYPE Postion   */ 
#define USB_GHWCFG3_RST_TYPE_Msk    (0x1U << USB_GHWCFG3_RST_TYPE_Pos)                                          /*!< RST_TYPE Mask      */
#define USB_GHWCFG3_RST_TYPE_Set(x) (((uint32_t) (x) << USB_GHWCFG3_RST_TYPE_Pos) & USB_GHWCFG3_RST_TYPE_Msk)   /*!< RST_TYPE Set Value */
#define USB_GHWCFG3_RST_TYPE_Get(x) (((uint32_t) (x) & USB_GHWCFG3_RST_TYPE_Msk) >> USB_GHWCFG3_RST_TYPE_Pos)   /*!< RST_TYPE Get Value */


#define USB_GHWCFG3_OPT_FEATURE_Pos    (10U)                                                                       /*!< OPT_FEATURE Postion   */ 
#define USB_GHWCFG3_OPT_FEATURE_Msk    (0x1U << USB_GHWCFG3_OPT_FEATURE_Pos)                                       /*!< OPT_FEATURE Mask      */
#define USB_GHWCFG3_OPT_FEATURE_Set(x) (((uint32_t) (x) << USB_GHWCFG3_OPT_FEATURE_Pos) & USB_GHWCFG3_OPT_FEATURE_Msk) /*!< OPT_FEATURE Set Value */
#define USB_GHWCFG3_OPT_FEATURE_Get(x) (((uint32_t) (x) & USB_GHWCFG3_OPT_FEATURE_Msk) >> USB_GHWCFG3_OPT_FEATURE_Pos) /*!< OPT_FEATURE Get Value */


#define USB_GHWCFG3_VNDCTL_SUPT_Pos    (9U)                                                                        /*!< VNDCTL_SUPT Postion   */ 
#define USB_GHWCFG3_VNDCTL_SUPT_Msk    (0x1U << USB_GHWCFG3_VNDCTL_SUPT_Pos)                                       /*!< VNDCTL_SUPT Mask      */
#define USB_GHWCFG3_VNDCTL_SUPT_Set(x) (((uint32_t) (x) << USB_GHWCFG3_VNDCTL_SUPT_Pos) & USB_GHWCFG3_VNDCTL_SUPT_Msk) /*!< VNDCTL_SUPT Set Value */
#define USB_GHWCFG3_VNDCTL_SUPT_Get(x) (((uint32_t) (x) & USB_GHWCFG3_VNDCTL_SUPT_Msk) >> USB_GHWCFG3_VNDCTL_SUPT_Pos) /*!< VNDCTL_SUPT Get Value */


#define USB_GHWCFG3_I2CINT_SEL_Pos    (8U)                                                                        /*!< I2CINT_SEL Postion   */ 
#define USB_GHWCFG3_I2CINT_SEL_Msk    (0x1U << USB_GHWCFG3_I2CINT_SEL_Pos)                                        /*!< I2CINT_SEL Mask      */
#define USB_GHWCFG3_I2CINT_SEL_Set(x) (((uint32_t) (x) << USB_GHWCFG3_I2CINT_SEL_Pos) & USB_GHWCFG3_I2CINT_SEL_Msk) /*!< I2CINT_SEL Set Value */
#define USB_GHWCFG3_I2CINT_SEL_Get(x) (((uint32_t) (x) & USB_GHWCFG3_I2CINT_SEL_Msk) >> USB_GHWCFG3_I2CINT_SEL_Pos) /*!< I2CINT_SEL Get Value */


#define USB_GHWCFG3_OTG_EN_Pos    (7U)                                                                        /*!< OTG_EN Postion   */ 
#define USB_GHWCFG3_OTG_EN_Msk    (0x1U << USB_GHWCFG3_OTG_EN_Pos)                                            /*!< OTG_EN Mask      */
#define USB_GHWCFG3_OTG_EN_Set(x) (((uint32_t) (x) << USB_GHWCFG3_OTG_EN_Pos) & USB_GHWCFG3_OTG_EN_Msk)       /*!< OTG_EN Set Value */
#define USB_GHWCFG3_OTG_EN_Get(x) (((uint32_t) (x) & USB_GHWCFG3_OTG_EN_Msk) >> USB_GHWCFG3_OTG_EN_Pos)       /*!< OTG_EN Get Value */


#define USB_GHWCFG3_PKT_SIZE_WIDTH_Pos    (4U)                                                                        /*!< PKT_SIZE_WIDTH Postion   */ 
#define USB_GHWCFG3_PKT_SIZE_WIDTH_Msk    (0x7U << USB_GHWCFG3_PKT_SIZE_WIDTH_Pos)                                    /*!< PKT_SIZE_WIDTH Mask      */
#define USB_GHWCFG3_PKT_SIZE_WIDTH_Set(x) (((uint32_t) (x) << USB_GHWCFG3_PKT_SIZE_WIDTH_Pos) & USB_GHWCFG3_PKT_SIZE_WIDTH_Msk) /*!< PKT_SIZE_WIDTH Set Value */
#define USB_GHWCFG3_PKT_SIZE_WIDTH_Get(x) (((uint32_t) (x) & USB_GHWCFG3_PKT_SIZE_WIDTH_Msk) >> USB_GHWCFG3_PKT_SIZE_WIDTH_Pos) /*!< PKT_SIZE_WIDTH Get Value */


#define USB_GHWCFG3_XFER_SIZE_WIDTH_Pos    (0U)                                                                        /*!< XFER_SIZE_WIDTH Postion   */ 
#define USB_GHWCFG3_XFER_SIZE_WIDTH_Msk    (0xfU << USB_GHWCFG3_XFER_SIZE_WIDTH_Pos)                                   /*!< XFER_SIZE_WIDTH Mask      */
#define USB_GHWCFG3_XFER_SIZE_WIDTH_Set(x) (((uint32_t) (x) << USB_GHWCFG3_XFER_SIZE_WIDTH_Pos) & USB_GHWCFG3_XFER_SIZE_WIDTH_Msk) /*!< XFER_SIZE_WIDTH Set Value */
#define USB_GHWCFG3_XFER_SIZE_WIDTH_Get(x) (((uint32_t) (x) & USB_GHWCFG3_XFER_SIZE_WIDTH_Msk) >> USB_GHWCFG3_XFER_SIZE_WIDTH_Pos) /*!< XFER_SIZE_WIDTH Get Value */


/* GHWCFG4 bitfield */
#define USB_GHWCFG4_GHWCFG4_DESC_DMA_Pos    (31U)                                                                       /*!< GHWCFG4_DESC_DMA Postion   */ 
#define USB_GHWCFG4_GHWCFG4_DESC_DMA_Msk    (0x1U << USB_GHWCFG4_GHWCFG4_DESC_DMA_Pos)                                  /*!< GHWCFG4_DESC_DMA Mask      */
#define USB_GHWCFG4_GHWCFG4_DESC_DMA_Set(x) (((uint32_t) (x) << USB_GHWCFG4_GHWCFG4_DESC_DMA_Pos) & USB_GHWCFG4_GHWCFG4_DESC_DMA_Msk) /*!< GHWCFG4_DESC_DMA Set Value */
#define USB_GHWCFG4_GHWCFG4_DESC_DMA_Get(x) (((uint32_t) (x) & USB_GHWCFG4_GHWCFG4_DESC_DMA_Msk) >> USB_GHWCFG4_GHWCFG4_DESC_DMA_Pos) /*!< GHWCFG4_DESC_DMA Get Value */


#define USB_GHWCFG4_DESC_DMA_ENABLED_Pos    (30U)                                                                       /*!< DESC_DMA_ENABLED Postion   */ 
#define USB_GHWCFG4_DESC_DMA_ENABLED_Msk    (0x1U << USB_GHWCFG4_DESC_DMA_ENABLED_Pos)                                  /*!< DESC_DMA_ENABLED Mask      */
#define USB_GHWCFG4_DESC_DMA_ENABLED_Set(x) (((uint32_t) (x) << USB_GHWCFG4_DESC_DMA_ENABLED_Pos) & USB_GHWCFG4_DESC_DMA_ENABLED_Msk) /*!< DESC_DMA_ENABLED Set Value */
#define USB_GHWCFG4_DESC_DMA_ENABLED_Get(x) (((uint32_t) (x) & USB_GHWCFG4_DESC_DMA_ENABLED_Msk) >> USB_GHWCFG4_DESC_DMA_ENABLED_Pos) /*!< DESC_DMA_ENABLED Get Value */


#define USB_GHWCFG4_IN_EPS_Pos    (26U)                                                                       /*!< IN_EPS Postion   */ 
#define USB_GHWCFG4_IN_EPS_Msk    (0xfU << USB_GHWCFG4_IN_EPS_Pos)                                            /*!< IN_EPS Mask      */
#define USB_GHWCFG4_IN_EPS_Set(x) (((uint32_t) (x) << USB_GHWCFG4_IN_EPS_Pos) & USB_GHWCFG4_IN_EPS_Msk)       /*!< IN_EPS Set Value */
#define USB_GHWCFG4_IN_EPS_Get(x) (((uint32_t) (x) & USB_GHWCFG4_IN_EPS_Msk) >> USB_GHWCFG4_IN_EPS_Pos)       /*!< IN_EPS Get Value */


#define USB_GHWCFG4_DED_FIFO_MODE_Pos    (25U)                                                                       /*!< DED_FIFO_MODE Postion   */ 
#define USB_GHWCFG4_DED_FIFO_MODE_Msk    (0x1U << USB_GHWCFG4_DED_FIFO_MODE_Pos)                                     /*!< DED_FIFO_MODE Mask      */
#define USB_GHWCFG4_DED_FIFO_MODE_Set(x) (((uint32_t) (x) << USB_GHWCFG4_DED_FIFO_MODE_Pos) & USB_GHWCFG4_DED_FIFO_MODE_Msk) /*!< DED_FIFO_MODE Set Value */
#define USB_GHWCFG4_DED_FIFO_MODE_Get(x) (((uint32_t) (x) & USB_GHWCFG4_DED_FIFO_MODE_Msk) >> USB_GHWCFG4_DED_FIFO_MODE_Pos) /*!< DED_FIFO_MODE Get Value */


#define USB_GHWCFG4_SESS_END_FLTR_Pos    (24U)                                                                       /*!< SESS_END_FLTR Postion   */ 
#define USB_GHWCFG4_SESS_END_FLTR_Msk    (0x1U << USB_GHWCFG4_SESS_END_FLTR_Pos)                                     /*!< SESS_END_FLTR Mask      */
#define USB_GHWCFG4_SESS_END_FLTR_Set(x) (((uint32_t) (x) << USB_GHWCFG4_SESS_END_FLTR_Pos) & USB_GHWCFG4_SESS_END_FLTR_Msk) /*!< SESS_END_FLTR Set Value */
#define USB_GHWCFG4_SESS_END_FLTR_Get(x) (((uint32_t) (x) & USB_GHWCFG4_SESS_END_FLTR_Msk) >> USB_GHWCFG4_SESS_END_FLTR_Pos) /*!< SESS_END_FLTR Get Value */


#define USB_GHWCFG4_BVALID_FLTR_Pos    (23U)                                                                       /*!< BVALID_FLTR Postion   */ 
#define USB_GHWCFG4_BVALID_FLTR_Msk    (0x1U << USB_GHWCFG4_BVALID_FLTR_Pos)                                       /*!< BVALID_FLTR Mask      */
#define USB_GHWCFG4_BVALID_FLTR_Set(x) (((uint32_t) (x) << USB_GHWCFG4_BVALID_FLTR_Pos) & USB_GHWCFG4_BVALID_FLTR_Msk) /*!< BVALID_FLTR Set Value */
#define USB_GHWCFG4_BVALID_FLTR_Get(x) (((uint32_t) (x) & USB_GHWCFG4_BVALID_FLTR_Msk) >> USB_GHWCFG4_BVALID_FLTR_Pos) /*!< BVALID_FLTR Get Value */


#define USB_GHWCFG4_AVALID_FLTR_Pos    (22U)                                                                       /*!< AVALID_FLTR Postion   */ 
#define USB_GHWCFG4_AVALID_FLTR_Msk    (0x1U << USB_GHWCFG4_AVALID_FLTR_Pos)                                       /*!< AVALID_FLTR Mask      */
#define USB_GHWCFG4_AVALID_FLTR_Set(x) (((uint32_t) (x) << USB_GHWCFG4_AVALID_FLTR_Pos) & USB_GHWCFG4_AVALID_FLTR_Msk) /*!< AVALID_FLTR Set Value */
#define USB_GHWCFG4_AVALID_FLTR_Get(x) (((uint32_t) (x) & USB_GHWCFG4_AVALID_FLTR_Msk) >> USB_GHWCFG4_AVALID_FLTR_Pos) /*!< AVALID_FLTR Get Value */


#define USB_GHWCFG4_VBUS_VALID_FLTR_Pos    (21U)                                                                       /*!< VBUS_VALID_FLTR Postion   */ 
#define USB_GHWCFG4_VBUS_VALID_FLTR_Msk    (0x1U << USB_GHWCFG4_VBUS_VALID_FLTR_Pos)                                   /*!< VBUS_VALID_FLTR Mask      */
#define USB_GHWCFG4_VBUS_VALID_FLTR_Set(x) (((uint32_t) (x) << USB_GHWCFG4_VBUS_VALID_FLTR_Pos) & USB_GHWCFG4_VBUS_VALID_FLTR_Msk) /*!< VBUS_VALID_FLTR Set Value */
#define USB_GHWCFG4_VBUS_VALID_FLTR_Get(x) (((uint32_t) (x) & USB_GHWCFG4_VBUS_VALID_FLTR_Msk) >> USB_GHWCFG4_VBUS_VALID_FLTR_Pos) /*!< VBUS_VALID_FLTR Get Value */


#define USB_GHWCFG4_IDDG_FLTR_Pos    (20U)                                                                       /*!< IDDG_FLTR Postion   */ 
#define USB_GHWCFG4_IDDG_FLTR_Msk    (0x1U << USB_GHWCFG4_IDDG_FLTR_Pos)                                         /*!< IDDG_FLTR Mask      */
#define USB_GHWCFG4_IDDG_FLTR_Set(x) (((uint32_t) (x) << USB_GHWCFG4_IDDG_FLTR_Pos) & USB_GHWCFG4_IDDG_FLTR_Msk) /*!< IDDG_FLTR Set Value */
#define USB_GHWCFG4_IDDG_FLTR_Get(x) (((uint32_t) (x) & USB_GHWCFG4_IDDG_FLTR_Msk) >> USB_GHWCFG4_IDDG_FLTR_Pos) /*!< IDDG_FLTR Get Value */


#define USB_GHWCFG4_NUM_CTL_EPS_Pos    (16U)                                                                       /*!< NUM_CTL_EPS Postion   */ 
#define USB_GHWCFG4_NUM_CTL_EPS_Msk    (0xfU << USB_GHWCFG4_NUM_CTL_EPS_Pos)                                       /*!< NUM_CTL_EPS Mask      */
#define USB_GHWCFG4_NUM_CTL_EPS_Set(x) (((uint32_t) (x) << USB_GHWCFG4_NUM_CTL_EPS_Pos) & USB_GHWCFG4_NUM_CTL_EPS_Msk) /*!< NUM_CTL_EPS Set Value */
#define USB_GHWCFG4_NUM_CTL_EPS_Get(x) (((uint32_t) (x) & USB_GHWCFG4_NUM_CTL_EPS_Msk) >> USB_GHWCFG4_NUM_CTL_EPS_Pos) /*!< NUM_CTL_EPS Get Value */


#define USB_GHWCFG4_PHY_DATA_WIDTH_Pos    (14U)                                                                       /*!< PHY_DATA_WIDTH Postion   */ 
#define USB_GHWCFG4_PHY_DATA_WIDTH_Msk    (0x3U << USB_GHWCFG4_PHY_DATA_WIDTH_Pos)                                    /*!< PHY_DATA_WIDTH Mask      */
#define USB_GHWCFG4_PHY_DATA_WIDTH_Set(x) (((uint32_t) (x) << USB_GHWCFG4_PHY_DATA_WIDTH_Pos) & USB_GHWCFG4_PHY_DATA_WIDTH_Msk) /*!< PHY_DATA_WIDTH Set Value */
#define USB_GHWCFG4_PHY_DATA_WIDTH_Get(x) (((uint32_t) (x) & USB_GHWCFG4_PHY_DATA_WIDTH_Msk) >> USB_GHWCFG4_PHY_DATA_WIDTH_Pos) /*!< PHY_DATA_WIDTH Get Value */


#define USB_GHWCFG4_ENHANCED_LPMSUPT_Pos    (13U)                                                                       /*!< ENHANCED_LPMSUPT Postion   */ 
#define USB_GHWCFG4_ENHANCED_LPMSUPT_Msk    (0x1U << USB_GHWCFG4_ENHANCED_LPMSUPT_Pos)                                  /*!< ENHANCED_LPMSUPT Mask      */
#define USB_GHWCFG4_ENHANCED_LPMSUPT_Set(x) (((uint32_t) (x) << USB_GHWCFG4_ENHANCED_LPMSUPT_Pos) & USB_GHWCFG4_ENHANCED_LPMSUPT_Msk) /*!< ENHANCED_LPMSUPT Set Value */
#define USB_GHWCFG4_ENHANCED_LPMSUPT_Get(x) (((uint32_t) (x) & USB_GHWCFG4_ENHANCED_LPMSUPT_Msk) >> USB_GHWCFG4_ENHANCED_LPMSUPT_Pos) /*!< ENHANCED_LPMSUPT Get Value */


#define USB_GHWCFG4_ACGSUPT_Pos    (12U)                                                                       /*!< ACGSUPT Postion   */ 
#define USB_GHWCFG4_ACGSUPT_Msk    (0x1U << USB_GHWCFG4_ACGSUPT_Pos)                                           /*!< ACGSUPT Mask      */
#define USB_GHWCFG4_ACGSUPT_Set(x) (((uint32_t) (x) << USB_GHWCFG4_ACGSUPT_Pos) & USB_GHWCFG4_ACGSUPT_Msk)     /*!< ACGSUPT Set Value */
#define USB_GHWCFG4_ACGSUPT_Get(x) (((uint32_t) (x) & USB_GHWCFG4_ACGSUPT_Msk) >> USB_GHWCFG4_ACGSUPT_Pos)     /*!< ACGSUPT Get Value */


#define USB_GHWCFG4_IPGISOC_SUPT_Pos    (11U)                                                                       /*!< IPGISOC_SUPT Postion   */ 
#define USB_GHWCFG4_IPGISOC_SUPT_Msk    (0x1U << USB_GHWCFG4_IPGISOC_SUPT_Pos)                                      /*!< IPGISOC_SUPT Mask      */
#define USB_GHWCFG4_IPGISOC_SUPT_Set(x) (((uint32_t) (x) << USB_GHWCFG4_IPGISOC_SUPT_Pos) & USB_GHWCFG4_IPGISOC_SUPT_Msk) /*!< IPGISOC_SUPT Set Value */
#define USB_GHWCFG4_IPGISOC_SUPT_Get(x) (((uint32_t) (x) & USB_GHWCFG4_IPGISOC_SUPT_Msk) >> USB_GHWCFG4_IPGISOC_SUPT_Pos) /*!< IPGISOC_SUPT Get Value */


#define USB_GHWCFG4_SERV_INT_FLOW_Pos    (10U)                                                                       /*!< SERV_INT_FLOW Postion   */ 
#define USB_GHWCFG4_SERV_INT_FLOW_Msk    (0x1U << USB_GHWCFG4_SERV_INT_FLOW_Pos)                                     /*!< SERV_INT_FLOW Mask      */
#define USB_GHWCFG4_SERV_INT_FLOW_Set(x) (((uint32_t) (x) << USB_GHWCFG4_SERV_INT_FLOW_Pos) & USB_GHWCFG4_SERV_INT_FLOW_Msk) /*!< SERV_INT_FLOW Set Value */
#define USB_GHWCFG4_SERV_INT_FLOW_Get(x) (((uint32_t) (x) & USB_GHWCFG4_SERV_INT_FLOW_Msk) >> USB_GHWCFG4_SERV_INT_FLOW_Pos) /*!< SERV_INT_FLOW Get Value */


#define USB_GHWCFG4_ENHANCED_LPMSUPT1_Pos    (9U)                                                                        /*!< ENHANCED_LPMSUPT1 Postion   */ 
#define USB_GHWCFG4_ENHANCED_LPMSUPT1_Msk    (0x1U << USB_GHWCFG4_ENHANCED_LPMSUPT1_Pos)                                 /*!< ENHANCED_LPMSUPT1 Mask      */
#define USB_GHWCFG4_ENHANCED_LPMSUPT1_Set(x) (((uint32_t) (x) << USB_GHWCFG4_ENHANCED_LPMSUPT1_Pos) & USB_GHWCFG4_ENHANCED_LPMSUPT1_Msk) /*!< ENHANCED_LPMSUPT1 Set Value */
#define USB_GHWCFG4_ENHANCED_LPMSUPT1_Get(x) (((uint32_t) (x) & USB_GHWCFG4_ENHANCED_LPMSUPT1_Msk) >> USB_GHWCFG4_ENHANCED_LPMSUPT1_Pos) /*!< ENHANCED_LPMSUPT1 Get Value */


#define USB_GHWCFG4_EXTENDED_HIBERNATION_Pos    (7U)                                                                        /*!< EXTENDED_HIBERNATION Postion   */ 
#define USB_GHWCFG4_EXTENDED_HIBERNATION_Msk    (0x1U << USB_GHWCFG4_EXTENDED_HIBERNATION_Pos)                              /*!< EXTENDED_HIBERNATION Mask      */
#define USB_GHWCFG4_EXTENDED_HIBERNATION_Set(x) (((uint32_t) (x) << USB_GHWCFG4_EXTENDED_HIBERNATION_Pos) & USB_GHWCFG4_EXTENDED_HIBERNATION_Msk) /*!< EXTENDED_HIBERNATION Set Value */
#define USB_GHWCFG4_EXTENDED_HIBERNATION_Get(x) (((uint32_t) (x) & USB_GHWCFG4_EXTENDED_HIBERNATION_Msk) >> USB_GHWCFG4_EXTENDED_HIBERNATION_Pos) /*!< EXTENDED_HIBERNATION Get Value */


#define USB_GHWCFG4_HIBERNATION_Pos    (6U)                                                                        /*!< HIBERNATION Postion   */ 
#define USB_GHWCFG4_HIBERNATION_Msk    (0x1U << USB_GHWCFG4_HIBERNATION_Pos)                                       /*!< HIBERNATION Mask      */
#define USB_GHWCFG4_HIBERNATION_Set(x) (((uint32_t) (x) << USB_GHWCFG4_HIBERNATION_Pos) & USB_GHWCFG4_HIBERNATION_Msk) /*!< HIBERNATION Set Value */
#define USB_GHWCFG4_HIBERNATION_Get(x) (((uint32_t) (x) & USB_GHWCFG4_HIBERNATION_Msk) >> USB_GHWCFG4_HIBERNATION_Pos) /*!< HIBERNATION Get Value */


#define USB_GHWCFG4_AHB_FREQ_Pos    (5U)                                                                        /*!< AHB_FREQ Postion   */ 
#define USB_GHWCFG4_AHB_FREQ_Msk    (0x1U << USB_GHWCFG4_AHB_FREQ_Pos)                                          /*!< AHB_FREQ Mask      */
#define USB_GHWCFG4_AHB_FREQ_Set(x) (((uint32_t) (x) << USB_GHWCFG4_AHB_FREQ_Pos) & USB_GHWCFG4_AHB_FREQ_Msk)   /*!< AHB_FREQ Set Value */
#define USB_GHWCFG4_AHB_FREQ_Get(x) (((uint32_t) (x) & USB_GHWCFG4_AHB_FREQ_Msk) >> USB_GHWCFG4_AHB_FREQ_Pos)   /*!< AHB_FREQ Get Value */


#define USB_GHWCFG4_PARTIAL_PWR_DN_Pos    (4U)                                                                        /*!< PARTIAL_PWR_DN Postion   */ 
#define USB_GHWCFG4_PARTIAL_PWR_DN_Msk    (0x1U << USB_GHWCFG4_PARTIAL_PWR_DN_Pos)                                    /*!< PARTIAL_PWR_DN Mask      */
#define USB_GHWCFG4_PARTIAL_PWR_DN_Set(x) (((uint32_t) (x) << USB_GHWCFG4_PARTIAL_PWR_DN_Pos) & USB_GHWCFG4_PARTIAL_PWR_DN_Msk) /*!< PARTIAL_PWR_DN Set Value */
#define USB_GHWCFG4_PARTIAL_PWR_DN_Get(x) (((uint32_t) (x) & USB_GHWCFG4_PARTIAL_PWR_DN_Msk) >> USB_GHWCFG4_PARTIAL_PWR_DN_Pos) /*!< PARTIAL_PWR_DN Get Value */


#define USB_GHWCFG4_NUM_DEV_PERIO_EPS_Pos    (0U)                                                                        /*!< NUM_DEV_PERIO_EPS Postion   */ 
#define USB_GHWCFG4_NUM_DEV_PERIO_EPS_Msk    (0xfU << USB_GHWCFG4_NUM_DEV_PERIO_EPS_Pos)                                 /*!< NUM_DEV_PERIO_EPS Mask      */
#define USB_GHWCFG4_NUM_DEV_PERIO_EPS_Set(x) (((uint32_t) (x) << USB_GHWCFG4_NUM_DEV_PERIO_EPS_Pos) & USB_GHWCFG4_NUM_DEV_PERIO_EPS_Msk) /*!< NUM_DEV_PERIO_EPS Set Value */
#define USB_GHWCFG4_NUM_DEV_PERIO_EPS_Get(x) (((uint32_t) (x) & USB_GHWCFG4_NUM_DEV_PERIO_EPS_Msk) >> USB_GHWCFG4_NUM_DEV_PERIO_EPS_Pos) /*!< NUM_DEV_PERIO_EPS Get Value */


/* GDFIFOCFG bitfield */
#define USB_GDFIFOCFG_EP_INFO_BASE_ADDR_Pos    (16U)                                                                       /*!< EP_INFO_BASE_ADDR Postion   */ 
#define USB_GDFIFOCFG_EP_INFO_BASE_ADDR_Msk    (0xffffU << USB_GDFIFOCFG_EP_INFO_BASE_ADDR_Pos)                            /*!< EP_INFO_BASE_ADDR Mask      */
#define USB_GDFIFOCFG_EP_INFO_BASE_ADDR_Set(x) (((uint32_t) (x) << USB_GDFIFOCFG_EP_INFO_BASE_ADDR_Pos) & USB_GDFIFOCFG_EP_INFO_BASE_ADDR_Msk) /*!< EP_INFO_BASE_ADDR Set Value */
#define USB_GDFIFOCFG_EP_INFO_BASE_ADDR_Get(x) (((uint32_t) (x) & USB_GDFIFOCFG_EP_INFO_BASE_ADDR_Msk) >> USB_GDFIFOCFG_EP_INFO_BASE_ADDR_Pos) /*!< EP_INFO_BASE_ADDR Get Value */


#define USB_GDFIFOCFG_GDFIFOCFG_Pos    (0U)                                                                        /*!< GDFIFOCFG Postion   */ 
#define USB_GDFIFOCFG_GDFIFOCFG_Msk    (0xffffU << USB_GDFIFOCFG_GDFIFOCFG_Pos)                                    /*!< GDFIFOCFG Mask      */
#define USB_GDFIFOCFG_GDFIFOCFG_Set(x) (((uint32_t) (x) << USB_GDFIFOCFG_GDFIFOCFG_Pos) & USB_GDFIFOCFG_GDFIFOCFG_Msk) /*!< GDFIFOCFG Set Value */
#define USB_GDFIFOCFG_GDFIFOCFG_Get(x) (((uint32_t) (x) & USB_GDFIFOCFG_GDFIFOCFG_Msk) >> USB_GDFIFOCFG_GDFIFOCFG_Pos) /*!< GDFIFOCFG Get Value */


/* GINTMSK2 bitfield */
/* GINTSTS2 bitfield */
/* HPTXFSIZ bitfield */
#define USB_HPTXFSIZ_PTXF_SIZE_Pos    (16U)                                                                       /*!< PTXF_SIZE Postion   */ 
#define USB_HPTXFSIZ_PTXF_SIZE_Msk    (0xffffU << USB_HPTXFSIZ_PTXF_SIZE_Pos)                                     /*!< PTXF_SIZE Mask      */
#define USB_HPTXFSIZ_PTXF_SIZE_Set(x) (((uint32_t) (x) << USB_HPTXFSIZ_PTXF_SIZE_Pos) & USB_HPTXFSIZ_PTXF_SIZE_Msk) /*!< PTXF_SIZE Set Value */
#define USB_HPTXFSIZ_PTXF_SIZE_Get(x) (((uint32_t) (x) & USB_HPTXFSIZ_PTXF_SIZE_Msk) >> USB_HPTXFSIZ_PTXF_SIZE_Pos) /*!< PTXF_SIZE Get Value */


#define USB_HPTXFSIZ_PTXF_ST_ADDR_Pos    (0U)                                                                        /*!< PTXF_ST_ADDR Postion   */ 
#define USB_HPTXFSIZ_PTXF_ST_ADDR_Msk    (0xffffU << USB_HPTXFSIZ_PTXF_ST_ADDR_Pos)                                  /*!< PTXF_ST_ADDR Mask      */
#define USB_HPTXFSIZ_PTXF_ST_ADDR_Set(x) (((uint32_t) (x) << USB_HPTXFSIZ_PTXF_ST_ADDR_Pos) & USB_HPTXFSIZ_PTXF_ST_ADDR_Msk) /*!< PTXF_ST_ADDR Set Value */
#define USB_HPTXFSIZ_PTXF_ST_ADDR_Get(x) (((uint32_t) (x) & USB_HPTXFSIZ_PTXF_ST_ADDR_Msk) >> USB_HPTXFSIZ_PTXF_ST_ADDR_Pos) /*!< PTXF_ST_ADDR Get Value */


/* HCFG bitfield */
#define USB_HCFG_MODE_CH_TIM_EN_Pos    (31U)                                                                       /*!< MODE_CH_TIM_EN Postion   */ 
#define USB_HCFG_MODE_CH_TIM_EN_Msk    (0x1U << USB_HCFG_MODE_CH_TIM_EN_Pos)                                       /*!< MODE_CH_TIM_EN Mask      */
#define USB_HCFG_MODE_CH_TIM_EN_Set(x) (((uint32_t) (x) << USB_HCFG_MODE_CH_TIM_EN_Pos) & USB_HCFG_MODE_CH_TIM_EN_Msk) /*!< MODE_CH_TIM_EN Set Value */
#define USB_HCFG_MODE_CH_TIM_EN_Get(x) (((uint32_t) (x) & USB_HCFG_MODE_CH_TIM_EN_Msk) >> USB_HCFG_MODE_CH_TIM_EN_Pos) /*!< MODE_CH_TIM_EN Get Value */


#define USB_HCFG_PER_SCHED_ENA_Pos    (26U)                                                                       /*!< PER_SCHED_ENA Postion   */ 
#define USB_HCFG_PER_SCHED_ENA_Msk    (0x1U << USB_HCFG_PER_SCHED_ENA_Pos)                                        /*!< PER_SCHED_ENA Mask      */
#define USB_HCFG_PER_SCHED_ENA_Set(x) (((uint32_t) (x) << USB_HCFG_PER_SCHED_ENA_Pos) & USB_HCFG_PER_SCHED_ENA_Msk) /*!< PER_SCHED_ENA Set Value */
#define USB_HCFG_PER_SCHED_ENA_Get(x) (((uint32_t) (x) & USB_HCFG_PER_SCHED_ENA_Msk) >> USB_HCFG_PER_SCHED_ENA_Pos) /*!< PER_SCHED_ENA Get Value */


#define USB_HCFG_FR_LIST_EN_Pos    (24U)                                                                       /*!< FR_LIST_EN Postion   */ 
#define USB_HCFG_FR_LIST_EN_Msk    (0x3U << USB_HCFG_FR_LIST_EN_Pos)                                           /*!< FR_LIST_EN Mask      */
#define USB_HCFG_FR_LIST_EN_Set(x) (((uint32_t) (x) << USB_HCFG_FR_LIST_EN_Pos) & USB_HCFG_FR_LIST_EN_Msk)     /*!< FR_LIST_EN Set Value */
#define USB_HCFG_FR_LIST_EN_Get(x) (((uint32_t) (x) & USB_HCFG_FR_LIST_EN_Msk) >> USB_HCFG_FR_LIST_EN_Pos)     /*!< FR_LIST_EN Get Value */


#define USB_HCFG_HCFG_DESC_DMA_Pos    (23U)                                                                       /*!< HCFG_DESC_DMA Postion   */ 
#define USB_HCFG_HCFG_DESC_DMA_Msk    (0x1U << USB_HCFG_HCFG_DESC_DMA_Pos)                                        /*!< HCFG_DESC_DMA Mask      */
#define USB_HCFG_HCFG_DESC_DMA_Set(x) (((uint32_t) (x) << USB_HCFG_HCFG_DESC_DMA_Pos) & USB_HCFG_HCFG_DESC_DMA_Msk) /*!< HCFG_DESC_DMA Set Value */
#define USB_HCFG_HCFG_DESC_DMA_Get(x) (((uint32_t) (x) & USB_HCFG_HCFG_DESC_DMA_Msk) >> USB_HCFG_HCFG_DESC_DMA_Pos) /*!< HCFG_DESC_DMA Get Value */


#define USB_HCFG_HCFG_RES_VALID_Pos    (8U)                                                                        /*!< HCFG_RES_VALID Postion   */ 
#define USB_HCFG_HCFG_RES_VALID_Msk    (0xffU << USB_HCFG_HCFG_RES_VALID_Pos)                                      /*!< HCFG_RES_VALID Mask      */
#define USB_HCFG_HCFG_RES_VALID_Set(x) (((uint32_t) (x) << USB_HCFG_HCFG_RES_VALID_Pos) & USB_HCFG_HCFG_RES_VALID_Msk) /*!< HCFG_RES_VALID Set Value */
#define USB_HCFG_HCFG_RES_VALID_Get(x) (((uint32_t) (x) & USB_HCFG_HCFG_RES_VALID_Msk) >> USB_HCFG_HCFG_RES_VALID_Pos) /*!< HCFG_RES_VALID Get Value */


#define USB_HCFG_ENA32KHZ_S_Pos    (7U)                                                                        /*!< ENA32KHZ_S Postion   */ 
#define USB_HCFG_ENA32KHZ_S_Msk    (0x1U << USB_HCFG_ENA32KHZ_S_Pos)                                           /*!< ENA32KHZ_S Mask      */
#define USB_HCFG_ENA32KHZ_S_Set(x) (((uint32_t) (x) << USB_HCFG_ENA32KHZ_S_Pos) & USB_HCFG_ENA32KHZ_S_Msk)     /*!< ENA32KHZ_S Set Value */
#define USB_HCFG_ENA32KHZ_S_Get(x) (((uint32_t) (x) & USB_HCFG_ENA32KHZ_S_Msk) >> USB_HCFG_ENA32KHZ_S_Pos)     /*!< ENA32KHZ_S Get Value */


#define USB_HCFG_FS_LSSUPP_Pos    (2U)                                                                        /*!< FS_LSSUPP Postion   */ 
#define USB_HCFG_FS_LSSUPP_Msk    (0x1U << USB_HCFG_FS_LSSUPP_Pos)                                            /*!< FS_LSSUPP Mask      */
#define USB_HCFG_FS_LSSUPP_Set(x) (((uint32_t) (x) << USB_HCFG_FS_LSSUPP_Pos) & USB_HCFG_FS_LSSUPP_Msk)       /*!< FS_LSSUPP Set Value */
#define USB_HCFG_FS_LSSUPP_Get(x) (((uint32_t) (x) & USB_HCFG_FS_LSSUPP_Msk) >> USB_HCFG_FS_LSSUPP_Pos)       /*!< FS_LSSUPP Get Value */


#define USB_HCFG_FS_LSPCLK_SEL_Pos    (0U)                                                                        /*!< FS_LSPCLK_SEL Postion   */ 
#define USB_HCFG_FS_LSPCLK_SEL_Msk    (0x3U << USB_HCFG_FS_LSPCLK_SEL_Pos)                                        /*!< FS_LSPCLK_SEL Mask      */
#define USB_HCFG_FS_LSPCLK_SEL_Set(x) (((uint32_t) (x) << USB_HCFG_FS_LSPCLK_SEL_Pos) & USB_HCFG_FS_LSPCLK_SEL_Msk) /*!< FS_LSPCLK_SEL Set Value */
#define USB_HCFG_FS_LSPCLK_SEL_Get(x) (((uint32_t) (x) & USB_HCFG_FS_LSPCLK_SEL_Msk) >> USB_HCFG_FS_LSPCLK_SEL_Pos) /*!< FS_LSPCLK_SEL Get Value */


/* HFIR bitfield */
#define USB_HFIR_HFIRRLD_CTRL_Pos    (16U)                                                                       /*!< HFIRRLD_CTRL Postion   */ 
#define USB_HFIR_HFIRRLD_CTRL_Msk    (0x1U << USB_HFIR_HFIRRLD_CTRL_Pos)                                         /*!< HFIRRLD_CTRL Mask      */
#define USB_HFIR_HFIRRLD_CTRL_Set(x) (((uint32_t) (x) << USB_HFIR_HFIRRLD_CTRL_Pos) & USB_HFIR_HFIRRLD_CTRL_Msk) /*!< HFIRRLD_CTRL Set Value */
#define USB_HFIR_HFIRRLD_CTRL_Get(x) (((uint32_t) (x) & USB_HFIR_HFIRRLD_CTRL_Msk) >> USB_HFIR_HFIRRLD_CTRL_Pos) /*!< HFIRRLD_CTRL Get Value */


#define USB_HFIR_FR_INT_Pos    (0U)                                                                        /*!< FR_INT Postion   */ 
#define USB_HFIR_FR_INT_Msk    (0xffffU << USB_HFIR_FR_INT_Pos)                                            /*!< FR_INT Mask      */
#define USB_HFIR_FR_INT_Set(x) (((uint32_t) (x) << USB_HFIR_FR_INT_Pos) & USB_HFIR_FR_INT_Msk)             /*!< FR_INT Set Value */
#define USB_HFIR_FR_INT_Get(x) (((uint32_t) (x) & USB_HFIR_FR_INT_Msk) >> USB_HFIR_FR_INT_Pos)             /*!< FR_INT Get Value */


/* HFNUM bitfield */
#define USB_HFNUM_FR_REM_Pos    (16U)                                                                       /*!< FR_REM Postion   */ 
#define USB_HFNUM_FR_REM_Msk    (0xffffU << USB_HFNUM_FR_REM_Pos)                                           /*!< FR_REM Mask      */
#define USB_HFNUM_FR_REM_Set(x) (((uint32_t) (x) << USB_HFNUM_FR_REM_Pos) & USB_HFNUM_FR_REM_Msk)           /*!< FR_REM Set Value */
#define USB_HFNUM_FR_REM_Get(x) (((uint32_t) (x) & USB_HFNUM_FR_REM_Msk) >> USB_HFNUM_FR_REM_Pos)           /*!< FR_REM Get Value */


#define USB_HFNUM_FR_NUM_Pos    (0U)                                                                        /*!< FR_NUM Postion   */ 
#define USB_HFNUM_FR_NUM_Msk    (0xffffU << USB_HFNUM_FR_NUM_Pos)                                           /*!< FR_NUM Mask      */
#define USB_HFNUM_FR_NUM_Set(x) (((uint32_t) (x) << USB_HFNUM_FR_NUM_Pos) & USB_HFNUM_FR_NUM_Msk)           /*!< FR_NUM Set Value */
#define USB_HFNUM_FR_NUM_Get(x) (((uint32_t) (x) & USB_HFNUM_FR_NUM_Msk) >> USB_HFNUM_FR_NUM_Pos)           /*!< FR_NUM Get Value */


/* HPTXSTS bitfield */
#define USB_HPTXSTS_PTX_QTOP_Pos    (24U)                                                                       /*!< PTX_QTOP Postion   */ 
#define USB_HPTXSTS_PTX_QTOP_Msk    (0xffU << USB_HPTXSTS_PTX_QTOP_Pos)                                         /*!< PTX_QTOP Mask      */
#define USB_HPTXSTS_PTX_QTOP_Set(x) (((uint32_t) (x) << USB_HPTXSTS_PTX_QTOP_Pos) & USB_HPTXSTS_PTX_QTOP_Msk)   /*!< PTX_QTOP Set Value */
#define USB_HPTXSTS_PTX_QTOP_Get(x) (((uint32_t) (x) & USB_HPTXSTS_PTX_QTOP_Msk) >> USB_HPTXSTS_PTX_QTOP_Pos)   /*!< PTX_QTOP Get Value */


#define USB_HPTXSTS_PTX_QSPC_AVAIL_Pos    (16U)                                                                       /*!< PTX_QSPC_AVAIL Postion   */ 
#define USB_HPTXSTS_PTX_QSPC_AVAIL_Msk    (0xffU << USB_HPTXSTS_PTX_QSPC_AVAIL_Pos)                                   /*!< PTX_QSPC_AVAIL Mask      */
#define USB_HPTXSTS_PTX_QSPC_AVAIL_Set(x) (((uint32_t) (x) << USB_HPTXSTS_PTX_QSPC_AVAIL_Pos) & USB_HPTXSTS_PTX_QSPC_AVAIL_Msk) /*!< PTX_QSPC_AVAIL Set Value */
#define USB_HPTXSTS_PTX_QSPC_AVAIL_Get(x) (((uint32_t) (x) & USB_HPTXSTS_PTX_QSPC_AVAIL_Msk) >> USB_HPTXSTS_PTX_QSPC_AVAIL_Pos) /*!< PTX_QSPC_AVAIL Get Value */


#define USB_HPTXSTS_PTXF_SPC_AVAIL_Pos    (0U)                                                                        /*!< PTXF_SPC_AVAIL Postion   */ 
#define USB_HPTXSTS_PTXF_SPC_AVAIL_Msk    (0xffffU << USB_HPTXSTS_PTXF_SPC_AVAIL_Pos)                                 /*!< PTXF_SPC_AVAIL Mask      */
#define USB_HPTXSTS_PTXF_SPC_AVAIL_Set(x) (((uint32_t) (x) << USB_HPTXSTS_PTXF_SPC_AVAIL_Pos) & USB_HPTXSTS_PTXF_SPC_AVAIL_Msk) /*!< PTXF_SPC_AVAIL Set Value */
#define USB_HPTXSTS_PTXF_SPC_AVAIL_Get(x) (((uint32_t) (x) & USB_HPTXSTS_PTXF_SPC_AVAIL_Msk) >> USB_HPTXSTS_PTXF_SPC_AVAIL_Pos) /*!< PTXF_SPC_AVAIL Get Value */


/* HAINT bitfield */
#define USB_HAINT_HAIN_T_Pos    (0U)                                                                        /*!< HAIN_T Postion   */ 
#define USB_HAINT_HAIN_T_Msk    (0xffffU << USB_HAINT_HAIN_T_Pos)                                           /*!< HAIN_T Mask      */
#define USB_HAINT_HAIN_T_Set(x) (((uint32_t) (x) << USB_HAINT_HAIN_T_Pos) & USB_HAINT_HAIN_T_Msk)           /*!< HAIN_T Set Value */
#define USB_HAINT_HAIN_T_Get(x) (((uint32_t) (x) & USB_HAINT_HAIN_T_Msk) >> USB_HAINT_HAIN_T_Pos)           /*!< HAIN_T Get Value */


/* HAINTMSK bitfield */
#define USB_HAINTMSK_HAIN_TMSK_Pos    (0U)                                                                        /*!< HAIN_TMSK Postion   */ 
#define USB_HAINTMSK_HAIN_TMSK_Msk    (0xffffU << USB_HAINTMSK_HAIN_TMSK_Pos)                                     /*!< HAIN_TMSK Mask      */
#define USB_HAINTMSK_HAIN_TMSK_Set(x) (((uint32_t) (x) << USB_HAINTMSK_HAIN_TMSK_Pos) & USB_HAINTMSK_HAIN_TMSK_Msk) /*!< HAIN_TMSK Set Value */
#define USB_HAINTMSK_HAIN_TMSK_Get(x) (((uint32_t) (x) & USB_HAINTMSK_HAIN_TMSK_Msk) >> USB_HAINTMSK_HAIN_TMSK_Pos) /*!< HAIN_TMSK Get Value */


/* HFLBADDR bitfield */
#define USB_HFLBADDR_HFLBADDR_Pos    (0U)                                                                        /*!< HFLBADDR Postion   */ 
#define USB_HFLBADDR_HFLBADDR_Msk    (0xffffffffU << USB_HFLBADDR_HFLBADDR_Pos)                                  /*!< HFLBADDR Mask      */
#define USB_HFLBADDR_HFLBADDR_Set(x) (((uint32_t) (x) << USB_HFLBADDR_HFLBADDR_Pos) & USB_HFLBADDR_HFLBADDR_Msk) /*!< HFLBADDR Set Value */
#define USB_HFLBADDR_HFLBADDR_Get(x) (((uint32_t) (x) & USB_HFLBADDR_HFLBADDR_Msk) >> USB_HFLBADDR_HFLBADDR_Pos) /*!< HFLBADDR Get Value */


/* HPRT bitfield */
#define USB_HPRT_PRT_SPD_Pos    (17U)                                                                       /*!< PRT_SPD Postion   */ 
#define USB_HPRT_PRT_SPD_Msk    (0x3U << USB_HPRT_PRT_SPD_Pos)                                              /*!< PRT_SPD Mask      */
#define USB_HPRT_PRT_SPD_Set(x) (((uint32_t) (x) << USB_HPRT_PRT_SPD_Pos) & USB_HPRT_PRT_SPD_Msk)           /*!< PRT_SPD Set Value */
#define USB_HPRT_PRT_SPD_Get(x) (((uint32_t) (x) & USB_HPRT_PRT_SPD_Msk) >> USB_HPRT_PRT_SPD_Pos)           /*!< PRT_SPD Get Value */


#define USB_HPRT_PRT_TST_CTL_Pos    (13U)                                                                       /*!< PRT_TST_CTL Postion   */ 
#define USB_HPRT_PRT_TST_CTL_Msk    (0xfU << USB_HPRT_PRT_TST_CTL_Pos)                                          /*!< PRT_TST_CTL Mask      */
#define USB_HPRT_PRT_TST_CTL_Set(x) (((uint32_t) (x) << USB_HPRT_PRT_TST_CTL_Pos) & USB_HPRT_PRT_TST_CTL_Msk)   /*!< PRT_TST_CTL Set Value */
#define USB_HPRT_PRT_TST_CTL_Get(x) (((uint32_t) (x) & USB_HPRT_PRT_TST_CTL_Msk) >> USB_HPRT_PRT_TST_CTL_Pos)   /*!< PRT_TST_CTL Get Value */


#define USB_HPRT_PRT_PWR_Pos    (12U)                                                                       /*!< PRT_PWR Postion   */ 
#define USB_HPRT_PRT_PWR_Msk    (0x1U << USB_HPRT_PRT_PWR_Pos)                                              /*!< PRT_PWR Mask      */
#define USB_HPRT_PRT_PWR_Set(x) (((uint32_t) (x) << USB_HPRT_PRT_PWR_Pos) & USB_HPRT_PRT_PWR_Msk)           /*!< PRT_PWR Set Value */
#define USB_HPRT_PRT_PWR_Get(x) (((uint32_t) (x) & USB_HPRT_PRT_PWR_Msk) >> USB_HPRT_PRT_PWR_Pos)           /*!< PRT_PWR Get Value */


#define USB_HPRT_PRT_LN_STS_Pos    (10U)                                                                       /*!< PRT_LN_STS Postion   */ 
#define USB_HPRT_PRT_LN_STS_Msk    (0x3U << USB_HPRT_PRT_LN_STS_Pos)                                           /*!< PRT_LN_STS Mask      */
#define USB_HPRT_PRT_LN_STS_Set(x) (((uint32_t) (x) << USB_HPRT_PRT_LN_STS_Pos) & USB_HPRT_PRT_LN_STS_Msk)     /*!< PRT_LN_STS Set Value */
#define USB_HPRT_PRT_LN_STS_Get(x) (((uint32_t) (x) & USB_HPRT_PRT_LN_STS_Msk) >> USB_HPRT_PRT_LN_STS_Pos)     /*!< PRT_LN_STS Get Value */


#define USB_HPRT_PRT_RST_Pos    (8U)                                                                        /*!< PRT_RST Postion   */ 
#define USB_HPRT_PRT_RST_Msk    (0x1U << USB_HPRT_PRT_RST_Pos)                                              /*!< PRT_RST Mask      */
#define USB_HPRT_PRT_RST_Set(x) (((uint32_t) (x) << USB_HPRT_PRT_RST_Pos) & USB_HPRT_PRT_RST_Msk)           /*!< PRT_RST Set Value */
#define USB_HPRT_PRT_RST_Get(x) (((uint32_t) (x) & USB_HPRT_PRT_RST_Msk) >> USB_HPRT_PRT_RST_Pos)           /*!< PRT_RST Get Value */


#define USB_HPRT_PRT_SUSP_Pos    (7U)                                                                        /*!< PRT_SUSP Postion   */ 
#define USB_HPRT_PRT_SUSP_Msk    (0x1U << USB_HPRT_PRT_SUSP_Pos)                                             /*!< PRT_SUSP Mask      */
#define USB_HPRT_PRT_SUSP_Set(x) (((uint32_t) (x) << USB_HPRT_PRT_SUSP_Pos) & USB_HPRT_PRT_SUSP_Msk)         /*!< PRT_SUSP Set Value */
#define USB_HPRT_PRT_SUSP_Get(x) (((uint32_t) (x) & USB_HPRT_PRT_SUSP_Msk) >> USB_HPRT_PRT_SUSP_Pos)         /*!< PRT_SUSP Get Value */


#define USB_HPRT_PRT_RES_Pos    (6U)                                                                        /*!< PRT_RES Postion   */ 
#define USB_HPRT_PRT_RES_Msk    (0x1U << USB_HPRT_PRT_RES_Pos)                                              /*!< PRT_RES Mask      */
#define USB_HPRT_PRT_RES_Set(x) (((uint32_t) (x) << USB_HPRT_PRT_RES_Pos) & USB_HPRT_PRT_RES_Msk)           /*!< PRT_RES Set Value */
#define USB_HPRT_PRT_RES_Get(x) (((uint32_t) (x) & USB_HPRT_PRT_RES_Msk) >> USB_HPRT_PRT_RES_Pos)           /*!< PRT_RES Get Value */


#define USB_HPRT_PRT_OVR_CURR_CHNG_Pos    (5U)                                                                        /*!< PRT_OVR_CURR_CHNG Postion   */ 
#define USB_HPRT_PRT_OVR_CURR_CHNG_Msk    (0x1U << USB_HPRT_PRT_OVR_CURR_CHNG_Pos)                                    /*!< PRT_OVR_CURR_CHNG Mask      */
#define USB_HPRT_PRT_OVR_CURR_CHNG_Set(x) (((uint32_t) (x) << USB_HPRT_PRT_OVR_CURR_CHNG_Pos) & USB_HPRT_PRT_OVR_CURR_CHNG_Msk) /*!< PRT_OVR_CURR_CHNG Set Value */
#define USB_HPRT_PRT_OVR_CURR_CHNG_Get(x) (((uint32_t) (x) & USB_HPRT_PRT_OVR_CURR_CHNG_Msk) >> USB_HPRT_PRT_OVR_CURR_CHNG_Pos) /*!< PRT_OVR_CURR_CHNG Get Value */


#define USB_HPRT_PRT_OVR_CURR_ACT_Pos    (4U)                                                                        /*!< PRT_OVR_CURR_ACT Postion   */ 
#define USB_HPRT_PRT_OVR_CURR_ACT_Msk    (0x1U << USB_HPRT_PRT_OVR_CURR_ACT_Pos)                                     /*!< PRT_OVR_CURR_ACT Mask      */
#define USB_HPRT_PRT_OVR_CURR_ACT_Set(x) (((uint32_t) (x) << USB_HPRT_PRT_OVR_CURR_ACT_Pos) & USB_HPRT_PRT_OVR_CURR_ACT_Msk) /*!< PRT_OVR_CURR_ACT Set Value */
#define USB_HPRT_PRT_OVR_CURR_ACT_Get(x) (((uint32_t) (x) & USB_HPRT_PRT_OVR_CURR_ACT_Msk) >> USB_HPRT_PRT_OVR_CURR_ACT_Pos) /*!< PRT_OVR_CURR_ACT Get Value */


#define USB_HPRT_PRT_EN_CHNG_Pos    (3U)                                                                        /*!< PRT_EN_CHNG Postion   */ 
#define USB_HPRT_PRT_EN_CHNG_Msk    (0x1U << USB_HPRT_PRT_EN_CHNG_Pos)                                          /*!< PRT_EN_CHNG Mask      */
#define USB_HPRT_PRT_EN_CHNG_Set(x) (((uint32_t) (x) << USB_HPRT_PRT_EN_CHNG_Pos) & USB_HPRT_PRT_EN_CHNG_Msk)   /*!< PRT_EN_CHNG Set Value */
#define USB_HPRT_PRT_EN_CHNG_Get(x) (((uint32_t) (x) & USB_HPRT_PRT_EN_CHNG_Msk) >> USB_HPRT_PRT_EN_CHNG_Pos)   /*!< PRT_EN_CHNG Get Value */


#define USB_HPRT_PRT_ENA_Pos    (2U)                                                                        /*!< PRT_ENA Postion   */ 
#define USB_HPRT_PRT_ENA_Msk    (0x1U << USB_HPRT_PRT_ENA_Pos)                                              /*!< PRT_ENA Mask      */
#define USB_HPRT_PRT_ENA_Set(x) (((uint32_t) (x) << USB_HPRT_PRT_ENA_Pos) & USB_HPRT_PRT_ENA_Msk)           /*!< PRT_ENA Set Value */
#define USB_HPRT_PRT_ENA_Get(x) (((uint32_t) (x) & USB_HPRT_PRT_ENA_Msk) >> USB_HPRT_PRT_ENA_Pos)           /*!< PRT_ENA Get Value */


#define USB_HPRT_PRT_CONN_DET_Pos    (1U)                                                                        /*!< PRT_CONN_DET Postion   */ 
#define USB_HPRT_PRT_CONN_DET_Msk    (0x1U << USB_HPRT_PRT_CONN_DET_Pos)                                         /*!< PRT_CONN_DET Mask      */
#define USB_HPRT_PRT_CONN_DET_Set(x) (((uint32_t) (x) << USB_HPRT_PRT_CONN_DET_Pos) & USB_HPRT_PRT_CONN_DET_Msk) /*!< PRT_CONN_DET Set Value */
#define USB_HPRT_PRT_CONN_DET_Get(x) (((uint32_t) (x) & USB_HPRT_PRT_CONN_DET_Msk) >> USB_HPRT_PRT_CONN_DET_Pos) /*!< PRT_CONN_DET Get Value */


#define USB_HPRT_PRT_CONN_STS_Pos    (0U)                                                                        /*!< PRT_CONN_STS Postion   */ 
#define USB_HPRT_PRT_CONN_STS_Msk    (0x1U << USB_HPRT_PRT_CONN_STS_Pos)                                         /*!< PRT_CONN_STS Mask      */
#define USB_HPRT_PRT_CONN_STS_Set(x) (((uint32_t) (x) << USB_HPRT_PRT_CONN_STS_Pos) & USB_HPRT_PRT_CONN_STS_Msk) /*!< PRT_CONN_STS Set Value */
#define USB_HPRT_PRT_CONN_STS_Get(x) (((uint32_t) (x) & USB_HPRT_PRT_CONN_STS_Msk) >> USB_HPRT_PRT_CONN_STS_Pos) /*!< PRT_CONN_STS Get Value */


/* DCFG bitfield */
#define USB_DCFG_DCFG_RES_VALID_Pos    (26U)                                                                       /*!< DCFG_RES_VALID Postion   */ 
#define USB_DCFG_DCFG_RES_VALID_Msk    (0x3fU << USB_DCFG_DCFG_RES_VALID_Pos)                                      /*!< DCFG_RES_VALID Mask      */
#define USB_DCFG_DCFG_RES_VALID_Set(x) (((uint32_t) (x) << USB_DCFG_DCFG_RES_VALID_Pos) & USB_DCFG_DCFG_RES_VALID_Msk) /*!< DCFG_RES_VALID Set Value */
#define USB_DCFG_DCFG_RES_VALID_Get(x) (((uint32_t) (x) & USB_DCFG_DCFG_RES_VALID_Msk) >> USB_DCFG_DCFG_RES_VALID_Pos) /*!< DCFG_RES_VALID Get Value */


#define USB_DCFG_PER_SCH_INTVL_Pos    (24U)                                                                       /*!< PER_SCH_INTVL Postion   */ 
#define USB_DCFG_PER_SCH_INTVL_Msk    (0x3U << USB_DCFG_PER_SCH_INTVL_Pos)                                        /*!< PER_SCH_INTVL Mask      */
#define USB_DCFG_PER_SCH_INTVL_Set(x) (((uint32_t) (x) << USB_DCFG_PER_SCH_INTVL_Pos) & USB_DCFG_PER_SCH_INTVL_Msk) /*!< PER_SCH_INTVL Set Value */
#define USB_DCFG_PER_SCH_INTVL_Get(x) (((uint32_t) (x) & USB_DCFG_PER_SCH_INTVL_Msk) >> USB_DCFG_PER_SCH_INTVL_Pos) /*!< PER_SCH_INTVL Get Value */


#define USB_DCFG_DCFG_DESC_DMA_Pos    (23U)                                                                       /*!< DCFG_DESC_DMA Postion   */ 
#define USB_DCFG_DCFG_DESC_DMA_Msk    (0x1U << USB_DCFG_DCFG_DESC_DMA_Pos)                                        /*!< DCFG_DESC_DMA Mask      */
#define USB_DCFG_DCFG_DESC_DMA_Set(x) (((uint32_t) (x) << USB_DCFG_DCFG_DESC_DMA_Pos) & USB_DCFG_DCFG_DESC_DMA_Msk) /*!< DCFG_DESC_DMA Set Value */
#define USB_DCFG_DCFG_DESC_DMA_Get(x) (((uint32_t) (x) & USB_DCFG_DCFG_DESC_DMA_Msk) >> USB_DCFG_DCFG_DESC_DMA_Pos) /*!< DCFG_DESC_DMA Get Value */


#define USB_DCFG_ERRATIC_INT_MSK_Pos    (15U)                                                                       /*!< ERRATIC_INT_MSK Postion   */ 
#define USB_DCFG_ERRATIC_INT_MSK_Msk    (0x1U << USB_DCFG_ERRATIC_INT_MSK_Pos)                                      /*!< ERRATIC_INT_MSK Mask      */
#define USB_DCFG_ERRATIC_INT_MSK_Set(x) (((uint32_t) (x) << USB_DCFG_ERRATIC_INT_MSK_Pos) & USB_DCFG_ERRATIC_INT_MSK_Msk) /*!< ERRATIC_INT_MSK Set Value */
#define USB_DCFG_ERRATIC_INT_MSK_Get(x) (((uint32_t) (x) & USB_DCFG_ERRATIC_INT_MSK_Msk) >> USB_DCFG_ERRATIC_INT_MSK_Pos) /*!< ERRATIC_INT_MSK Get Value */


#define USB_DCFG_XCVRDLY_Pos    (14U)                                                                       /*!< XCVRDLY Postion   */ 
#define USB_DCFG_XCVRDLY_Msk    (0x1U << USB_DCFG_XCVRDLY_Pos)                                              /*!< XCVRDLY Mask      */
#define USB_DCFG_XCVRDLY_Set(x) (((uint32_t) (x) << USB_DCFG_XCVRDLY_Pos) & USB_DCFG_XCVRDLY_Msk)           /*!< XCVRDLY Set Value */
#define USB_DCFG_XCVRDLY_Get(x) (((uint32_t) (x) & USB_DCFG_XCVRDLY_Msk) >> USB_DCFG_XCVRDLY_Pos)           /*!< XCVRDLY Get Value */


#define USB_DCFG_EN_DEV_OUT_NAK_Pos    (13U)                                                                       /*!< EN_DEV_OUT_NAK Postion   */ 
#define USB_DCFG_EN_DEV_OUT_NAK_Msk    (0x1U << USB_DCFG_EN_DEV_OUT_NAK_Pos)                                       /*!< EN_DEV_OUT_NAK Mask      */
#define USB_DCFG_EN_DEV_OUT_NAK_Set(x) (((uint32_t) (x) << USB_DCFG_EN_DEV_OUT_NAK_Pos) & USB_DCFG_EN_DEV_OUT_NAK_Msk) /*!< EN_DEV_OUT_NAK Set Value */
#define USB_DCFG_EN_DEV_OUT_NAK_Get(x) (((uint32_t) (x) & USB_DCFG_EN_DEV_OUT_NAK_Msk) >> USB_DCFG_EN_DEV_OUT_NAK_Pos) /*!< EN_DEV_OUT_NAK Get Value */


#define USB_DCFG_PER_FR_INT_Pos    (11U)                                                                       /*!< PER_FR_INT Postion   */ 
#define USB_DCFG_PER_FR_INT_Msk    (0x3U << USB_DCFG_PER_FR_INT_Pos)                                           /*!< PER_FR_INT Mask      */
#define USB_DCFG_PER_FR_INT_Set(x) (((uint32_t) (x) << USB_DCFG_PER_FR_INT_Pos) & USB_DCFG_PER_FR_INT_Msk)     /*!< PER_FR_INT Set Value */
#define USB_DCFG_PER_FR_INT_Get(x) (((uint32_t) (x) & USB_DCFG_PER_FR_INT_Msk) >> USB_DCFG_PER_FR_INT_Pos)     /*!< PER_FR_INT Get Value */


#define USB_DCFG_DCFG_DEV_ADDR_Pos    (4U)                                                                        /*!< DCFG_DEV_ADDR Postion   */ 
#define USB_DCFG_DCFG_DEV_ADDR_Msk    (0x7fU << USB_DCFG_DCFG_DEV_ADDR_Pos)                                       /*!< DCFG_DEV_ADDR Mask      */
#define USB_DCFG_DCFG_DEV_ADDR_Set(x) (((uint32_t) (x) << USB_DCFG_DCFG_DEV_ADDR_Pos) & USB_DCFG_DCFG_DEV_ADDR_Msk) /*!< DCFG_DEV_ADDR Set Value */
#define USB_DCFG_DCFG_DEV_ADDR_Get(x) (((uint32_t) (x) & USB_DCFG_DCFG_DEV_ADDR_Msk) >> USB_DCFG_DCFG_DEV_ADDR_Pos) /*!< DCFG_DEV_ADDR Get Value */


#define USB_DCFG_ENA32KHZ_SUSP_Pos    (3U)                                                                        /*!< ENA32KHZ_SUSP Postion   */ 
#define USB_DCFG_ENA32KHZ_SUSP_Msk    (0x1U << USB_DCFG_ENA32KHZ_SUSP_Pos)                                        /*!< ENA32KHZ_SUSP Mask      */
#define USB_DCFG_ENA32KHZ_SUSP_Set(x) (((uint32_t) (x) << USB_DCFG_ENA32KHZ_SUSP_Pos) & USB_DCFG_ENA32KHZ_SUSP_Msk) /*!< ENA32KHZ_SUSP Set Value */
#define USB_DCFG_ENA32KHZ_SUSP_Get(x) (((uint32_t) (x) & USB_DCFG_ENA32KHZ_SUSP_Msk) >> USB_DCFG_ENA32KHZ_SUSP_Pos) /*!< ENA32KHZ_SUSP Get Value */


#define USB_DCFG_NZSTS_OUT_HSHK_Pos    (2U)                                                                        /*!< NZSTS_OUT_HSHK Postion   */ 
#define USB_DCFG_NZSTS_OUT_HSHK_Msk    (0x1U << USB_DCFG_NZSTS_OUT_HSHK_Pos)                                       /*!< NZSTS_OUT_HSHK Mask      */
#define USB_DCFG_NZSTS_OUT_HSHK_Set(x) (((uint32_t) (x) << USB_DCFG_NZSTS_OUT_HSHK_Pos) & USB_DCFG_NZSTS_OUT_HSHK_Msk) /*!< NZSTS_OUT_HSHK Set Value */
#define USB_DCFG_NZSTS_OUT_HSHK_Get(x) (((uint32_t) (x) & USB_DCFG_NZSTS_OUT_HSHK_Msk) >> USB_DCFG_NZSTS_OUT_HSHK_Pos) /*!< NZSTS_OUT_HSHK Get Value */


#define USB_DCFG_DEV_SPD_Pos    (0U)                                                                        /*!< DEV_SPD Postion   */ 
#define USB_DCFG_DEV_SPD_Msk    (0x3U << USB_DCFG_DEV_SPD_Pos)                                              /*!< DEV_SPD Mask      */
#define USB_DCFG_DEV_SPD_Set(x) (((uint32_t) (x) << USB_DCFG_DEV_SPD_Pos) & USB_DCFG_DEV_SPD_Msk)           /*!< DEV_SPD Set Value */
#define USB_DCFG_DEV_SPD_Get(x) (((uint32_t) (x) & USB_DCFG_DEV_SPD_Msk) >> USB_DCFG_DEV_SPD_Pos)           /*!< DEV_SPD Get Value */


/* DCTL bitfield */
#define USB_DCTL_SERV_INT_Pos    (19U)                                                                       /*!< SERV_INT Postion   */ 
#define USB_DCTL_SERV_INT_Msk    (0x1U << USB_DCTL_SERV_INT_Pos)                                             /*!< SERV_INT Mask      */
#define USB_DCTL_SERV_INT_Set(x) (((uint32_t) (x) << USB_DCTL_SERV_INT_Pos) & USB_DCTL_SERV_INT_Msk)         /*!< SERV_INT Set Value */
#define USB_DCTL_SERV_INT_Get(x) (((uint32_t) (x) & USB_DCTL_SERV_INT_Msk) >> USB_DCTL_SERV_INT_Pos)         /*!< SERV_INT Get Value */


#define USB_DCTL_EN_CONT_ON_BNA_Pos    (17U)                                                                       /*!< EN_CONT_ON_BNA Postion   */ 
#define USB_DCTL_EN_CONT_ON_BNA_Msk    (0x1U << USB_DCTL_EN_CONT_ON_BNA_Pos)                                       /*!< EN_CONT_ON_BNA Mask      */
#define USB_DCTL_EN_CONT_ON_BNA_Set(x) (((uint32_t) (x) << USB_DCTL_EN_CONT_ON_BNA_Pos) & USB_DCTL_EN_CONT_ON_BNA_Msk) /*!< EN_CONT_ON_BNA Set Value */
#define USB_DCTL_EN_CONT_ON_BNA_Get(x) (((uint32_t) (x) & USB_DCTL_EN_CONT_ON_BNA_Msk) >> USB_DCTL_EN_CONT_ON_BNA_Pos) /*!< EN_CONT_ON_BNA Get Value */


#define USB_DCTL_NAK_ON_BBLE_Pos    (16U)                                                                       /*!< NAK_ON_BBLE Postion   */ 
#define USB_DCTL_NAK_ON_BBLE_Msk    (0x1U << USB_DCTL_NAK_ON_BBLE_Pos)                                          /*!< NAK_ON_BBLE Mask      */
#define USB_DCTL_NAK_ON_BBLE_Set(x) (((uint32_t) (x) << USB_DCTL_NAK_ON_BBLE_Pos) & USB_DCTL_NAK_ON_BBLE_Msk)   /*!< NAK_ON_BBLE Set Value */
#define USB_DCTL_NAK_ON_BBLE_Get(x) (((uint32_t) (x) & USB_DCTL_NAK_ON_BBLE_Msk) >> USB_DCTL_NAK_ON_BBLE_Pos)   /*!< NAK_ON_BBLE Get Value */


#define USB_DCTL_IGNR_FRM_NUM_Pos    (15U)                                                                       /*!< IGNR_FRM_NUM Postion   */ 
#define USB_DCTL_IGNR_FRM_NUM_Msk    (0x1U << USB_DCTL_IGNR_FRM_NUM_Pos)                                         /*!< IGNR_FRM_NUM Mask      */
#define USB_DCTL_IGNR_FRM_NUM_Set(x) (((uint32_t) (x) << USB_DCTL_IGNR_FRM_NUM_Pos) & USB_DCTL_IGNR_FRM_NUM_Msk) /*!< IGNR_FRM_NUM Set Value */
#define USB_DCTL_IGNR_FRM_NUM_Get(x) (((uint32_t) (x) & USB_DCTL_IGNR_FRM_NUM_Msk) >> USB_DCTL_IGNR_FRM_NUM_Pos) /*!< IGNR_FRM_NUM Get Value */


#define USB_DCTL_GMC_Pos    (13U)                                                                       /*!< GMC Postion   */ 
#define USB_DCTL_GMC_Msk    (0x3U << USB_DCTL_GMC_Pos)                                                  /*!< GMC Mask      */
#define USB_DCTL_GMC_Set(x) (((uint32_t) (x) << USB_DCTL_GMC_Pos) & USB_DCTL_GMC_Msk)                   /*!< GMC Set Value */
#define USB_DCTL_GMC_Get(x) (((uint32_t) (x) & USB_DCTL_GMC_Msk) >> USB_DCTL_GMC_Pos)                   /*!< GMC Get Value */


#define USB_DCTL_PWRON_PRG_DONE_Pos    (11U)                                                                       /*!< PWRON_PRG_DONE Postion   */ 
#define USB_DCTL_PWRON_PRG_DONE_Msk    (0x1U << USB_DCTL_PWRON_PRG_DONE_Pos)                                       /*!< PWRON_PRG_DONE Mask      */
#define USB_DCTL_PWRON_PRG_DONE_Set(x) (((uint32_t) (x) << USB_DCTL_PWRON_PRG_DONE_Pos) & USB_DCTL_PWRON_PRG_DONE_Msk) /*!< PWRON_PRG_DONE Set Value */
#define USB_DCTL_PWRON_PRG_DONE_Get(x) (((uint32_t) (x) & USB_DCTL_PWRON_PRG_DONE_Msk) >> USB_DCTL_PWRON_PRG_DONE_Pos) /*!< PWRON_PRG_DONE Get Value */


#define USB_DCTL_CGOUT_NAK_Pos    (10U)                                                                       /*!< CGOUT_NAK Postion   */ 
#define USB_DCTL_CGOUT_NAK_Msk    (0x1U << USB_DCTL_CGOUT_NAK_Pos)                                            /*!< CGOUT_NAK Mask      */
#define USB_DCTL_CGOUT_NAK_Set(x) (((uint32_t) (x) << USB_DCTL_CGOUT_NAK_Pos) & USB_DCTL_CGOUT_NAK_Msk)       /*!< CGOUT_NAK Set Value */
#define USB_DCTL_CGOUT_NAK_Get(x) (((uint32_t) (x) & USB_DCTL_CGOUT_NAK_Msk) >> USB_DCTL_CGOUT_NAK_Pos)       /*!< CGOUT_NAK Get Value */


#define USB_DCTL_SGOUT_NAK_Pos    (9U)                                                                        /*!< SGOUT_NAK Postion   */ 
#define USB_DCTL_SGOUT_NAK_Msk    (0x1U << USB_DCTL_SGOUT_NAK_Pos)                                            /*!< SGOUT_NAK Mask      */
#define USB_DCTL_SGOUT_NAK_Set(x) (((uint32_t) (x) << USB_DCTL_SGOUT_NAK_Pos) & USB_DCTL_SGOUT_NAK_Msk)       /*!< SGOUT_NAK Set Value */
#define USB_DCTL_SGOUT_NAK_Get(x) (((uint32_t) (x) & USB_DCTL_SGOUT_NAK_Msk) >> USB_DCTL_SGOUT_NAK_Pos)       /*!< SGOUT_NAK Get Value */


#define USB_DCTL_CGNP_IN_NAK_Pos    (8U)                                                                        /*!< CGNP_IN_NAK Postion   */ 
#define USB_DCTL_CGNP_IN_NAK_Msk    (0x1U << USB_DCTL_CGNP_IN_NAK_Pos)                                          /*!< CGNP_IN_NAK Mask      */
#define USB_DCTL_CGNP_IN_NAK_Set(x) (((uint32_t) (x) << USB_DCTL_CGNP_IN_NAK_Pos) & USB_DCTL_CGNP_IN_NAK_Msk)   /*!< CGNP_IN_NAK Set Value */
#define USB_DCTL_CGNP_IN_NAK_Get(x) (((uint32_t) (x) & USB_DCTL_CGNP_IN_NAK_Msk) >> USB_DCTL_CGNP_IN_NAK_Pos)   /*!< CGNP_IN_NAK Get Value */


#define USB_DCTL_SGNP_IN_NAK_Pos    (7U)                                                                        /*!< SGNP_IN_NAK Postion   */ 
#define USB_DCTL_SGNP_IN_NAK_Msk    (0x1U << USB_DCTL_SGNP_IN_NAK_Pos)                                          /*!< SGNP_IN_NAK Mask      */
#define USB_DCTL_SGNP_IN_NAK_Set(x) (((uint32_t) (x) << USB_DCTL_SGNP_IN_NAK_Pos) & USB_DCTL_SGNP_IN_NAK_Msk)   /*!< SGNP_IN_NAK Set Value */
#define USB_DCTL_SGNP_IN_NAK_Get(x) (((uint32_t) (x) & USB_DCTL_SGNP_IN_NAK_Msk) >> USB_DCTL_SGNP_IN_NAK_Pos)   /*!< SGNP_IN_NAK Get Value */


#define USB_DCTL_TST_CTL_Pos    (4U)                                                                        /*!< TST_CTL Postion   */ 
#define USB_DCTL_TST_CTL_Msk    (0x7U << USB_DCTL_TST_CTL_Pos)                                              /*!< TST_CTL Mask      */
#define USB_DCTL_TST_CTL_Set(x) (((uint32_t) (x) << USB_DCTL_TST_CTL_Pos) & USB_DCTL_TST_CTL_Msk)           /*!< TST_CTL Set Value */
#define USB_DCTL_TST_CTL_Get(x) (((uint32_t) (x) & USB_DCTL_TST_CTL_Msk) >> USB_DCTL_TST_CTL_Pos)           /*!< TST_CTL Get Value */


#define USB_DCTL_GOUT_NAK_STS_Pos    (3U)                                                                        /*!< GOUT_NAK_STS Postion   */ 
#define USB_DCTL_GOUT_NAK_STS_Msk    (0x1U << USB_DCTL_GOUT_NAK_STS_Pos)                                         /*!< GOUT_NAK_STS Mask      */
#define USB_DCTL_GOUT_NAK_STS_Set(x) (((uint32_t) (x) << USB_DCTL_GOUT_NAK_STS_Pos) & USB_DCTL_GOUT_NAK_STS_Msk) /*!< GOUT_NAK_STS Set Value */
#define USB_DCTL_GOUT_NAK_STS_Get(x) (((uint32_t) (x) & USB_DCTL_GOUT_NAK_STS_Msk) >> USB_DCTL_GOUT_NAK_STS_Pos) /*!< GOUT_NAK_STS Get Value */


#define USB_DCTL_GNP_IN_NAK_STS_Pos    (2U)                                                                        /*!< GNP_IN_NAK_STS Postion   */ 
#define USB_DCTL_GNP_IN_NAK_STS_Msk    (0x1U << USB_DCTL_GNP_IN_NAK_STS_Pos)                                       /*!< GNP_IN_NAK_STS Mask      */
#define USB_DCTL_GNP_IN_NAK_STS_Set(x) (((uint32_t) (x) << USB_DCTL_GNP_IN_NAK_STS_Pos) & USB_DCTL_GNP_IN_NAK_STS_Msk) /*!< GNP_IN_NAK_STS Set Value */
#define USB_DCTL_GNP_IN_NAK_STS_Get(x) (((uint32_t) (x) & USB_DCTL_GNP_IN_NAK_STS_Msk) >> USB_DCTL_GNP_IN_NAK_STS_Pos) /*!< GNP_IN_NAK_STS Get Value */


#define USB_DCTL_SFT_DISCON_Pos    (1U)                                                                        /*!< SFT_DISCON Postion   */ 
#define USB_DCTL_SFT_DISCON_Msk    (0x1U << USB_DCTL_SFT_DISCON_Pos)                                           /*!< SFT_DISCON Mask      */
#define USB_DCTL_SFT_DISCON_Set(x) (((uint32_t) (x) << USB_DCTL_SFT_DISCON_Pos) & USB_DCTL_SFT_DISCON_Msk)     /*!< SFT_DISCON Set Value */
#define USB_DCTL_SFT_DISCON_Get(x) (((uint32_t) (x) & USB_DCTL_SFT_DISCON_Msk) >> USB_DCTL_SFT_DISCON_Pos)     /*!< SFT_DISCON Get Value */


#define USB_DCTL_RMT_WK_UP_SIG_Pos    (0U)                                                                        /*!< RMT_WK_UP_SIG Postion   */ 
#define USB_DCTL_RMT_WK_UP_SIG_Msk    (0x1U << USB_DCTL_RMT_WK_UP_SIG_Pos)                                        /*!< RMT_WK_UP_SIG Mask      */
#define USB_DCTL_RMT_WK_UP_SIG_Set(x) (((uint32_t) (x) << USB_DCTL_RMT_WK_UP_SIG_Pos) & USB_DCTL_RMT_WK_UP_SIG_Msk) /*!< RMT_WK_UP_SIG Set Value */
#define USB_DCTL_RMT_WK_UP_SIG_Get(x) (((uint32_t) (x) & USB_DCTL_RMT_WK_UP_SIG_Msk) >> USB_DCTL_RMT_WK_UP_SIG_Pos) /*!< RMT_WK_UP_SIG Get Value */


/* DSTS bitfield */
#define USB_DSTS_DEV_LN_STS_Pos    (22U)                                                                       /*!< DEV_LN_STS Postion   */ 
#define USB_DSTS_DEV_LN_STS_Msk    (0x3U << USB_DSTS_DEV_LN_STS_Pos)                                           /*!< DEV_LN_STS Mask      */
#define USB_DSTS_DEV_LN_STS_Set(x) (((uint32_t) (x) << USB_DSTS_DEV_LN_STS_Pos) & USB_DSTS_DEV_LN_STS_Msk)     /*!< DEV_LN_STS Set Value */
#define USB_DSTS_DEV_LN_STS_Get(x) (((uint32_t) (x) & USB_DSTS_DEV_LN_STS_Msk) >> USB_DSTS_DEV_LN_STS_Pos)     /*!< DEV_LN_STS Get Value */


#define USB_DSTS_SOFFN_Pos    (8U)                                                                        /*!< SOFFN Postion   */ 
#define USB_DSTS_SOFFN_Msk    (0x3fffU << USB_DSTS_SOFFN_Pos)                                             /*!< SOFFN Mask      */
#define USB_DSTS_SOFFN_Set(x) (((uint32_t) (x) << USB_DSTS_SOFFN_Pos) & USB_DSTS_SOFFN_Msk)               /*!< SOFFN Set Value */
#define USB_DSTS_SOFFN_Get(x) (((uint32_t) (x) & USB_DSTS_SOFFN_Msk) >> USB_DSTS_SOFFN_Pos)               /*!< SOFFN Get Value */


#define USB_DSTS_ERRTIC_ERR_Pos    (3U)                                                                        /*!< ERRTIC_ERR Postion   */ 
#define USB_DSTS_ERRTIC_ERR_Msk    (0x1U << USB_DSTS_ERRTIC_ERR_Pos)                                           /*!< ERRTIC_ERR Mask      */
#define USB_DSTS_ERRTIC_ERR_Set(x) (((uint32_t) (x) << USB_DSTS_ERRTIC_ERR_Pos) & USB_DSTS_ERRTIC_ERR_Msk)     /*!< ERRTIC_ERR Set Value */
#define USB_DSTS_ERRTIC_ERR_Get(x) (((uint32_t) (x) & USB_DSTS_ERRTIC_ERR_Msk) >> USB_DSTS_ERRTIC_ERR_Pos)     /*!< ERRTIC_ERR Get Value */


#define USB_DSTS_ENUM_SPD_Pos    (1U)                                                                        /*!< ENUM_SPD Postion   */ 
#define USB_DSTS_ENUM_SPD_Msk    (0x3U << USB_DSTS_ENUM_SPD_Pos)                                             /*!< ENUM_SPD Mask      */
#define USB_DSTS_ENUM_SPD_Set(x) (((uint32_t) (x) << USB_DSTS_ENUM_SPD_Pos) & USB_DSTS_ENUM_SPD_Msk)         /*!< ENUM_SPD Set Value */
#define USB_DSTS_ENUM_SPD_Get(x) (((uint32_t) (x) & USB_DSTS_ENUM_SPD_Msk) >> USB_DSTS_ENUM_SPD_Pos)         /*!< ENUM_SPD Get Value */


#define USB_DSTS_SUSP_STS_Pos    (0U)                                                                        /*!< SUSP_STS Postion   */ 
#define USB_DSTS_SUSP_STS_Msk    (0x1U << USB_DSTS_SUSP_STS_Pos)                                             /*!< SUSP_STS Mask      */
#define USB_DSTS_SUSP_STS_Set(x) (((uint32_t) (x) << USB_DSTS_SUSP_STS_Pos) & USB_DSTS_SUSP_STS_Msk)         /*!< SUSP_STS Set Value */
#define USB_DSTS_SUSP_STS_Get(x) (((uint32_t) (x) & USB_DSTS_SUSP_STS_Msk) >> USB_DSTS_SUSP_STS_Pos)         /*!< SUSP_STS Get Value */


/* DIEPMSK bitfield */
#define USB_DIEPMSK_DIEP_MSK_NAKMSK_Pos    (13U)                                                                       /*!< DIEP_MSK_NAKMSK Postion   */ 
#define USB_DIEPMSK_DIEP_MSK_NAKMSK_Msk    (0x1U << USB_DIEPMSK_DIEP_MSK_NAKMSK_Pos)                                   /*!< DIEP_MSK_NAKMSK Mask      */
#define USB_DIEPMSK_DIEP_MSK_NAKMSK_Set(x) (((uint32_t) (x) << USB_DIEPMSK_DIEP_MSK_NAKMSK_Pos) & USB_DIEPMSK_DIEP_MSK_NAKMSK_Msk) /*!< DIEP_MSK_NAKMSK Set Value */
#define USB_DIEPMSK_DIEP_MSK_NAKMSK_Get(x) (((uint32_t) (x) & USB_DIEPMSK_DIEP_MSK_NAKMSK_Msk) >> USB_DIEPMSK_DIEP_MSK_NAKMSK_Pos) /*!< DIEP_MSK_NAKMSK Get Value */


#define USB_DIEPMSK_DIEP_MSK_BNAIN_INTR_MSK_Pos    (9U)                                                                        /*!< DIEP_MSK_BNAIN_INTR_MSK Postion   */ 
#define USB_DIEPMSK_DIEP_MSK_BNAIN_INTR_MSK_Msk    (0x1U << USB_DIEPMSK_DIEP_MSK_BNAIN_INTR_MSK_Pos)                           /*!< DIEP_MSK_BNAIN_INTR_MSK Mask      */
#define USB_DIEPMSK_DIEP_MSK_BNAIN_INTR_MSK_Set(x) (((uint32_t) (x) << USB_DIEPMSK_DIEP_MSK_BNAIN_INTR_MSK_Pos) & USB_DIEPMSK_DIEP_MSK_BNAIN_INTR_MSK_Msk) /*!< DIEP_MSK_BNAIN_INTR_MSK Set Value */
#define USB_DIEPMSK_DIEP_MSK_BNAIN_INTR_MSK_Get(x) (((uint32_t) (x) & USB_DIEPMSK_DIEP_MSK_BNAIN_INTR_MSK_Msk) >> USB_DIEPMSK_DIEP_MSK_BNAIN_INTR_MSK_Pos) /*!< DIEP_MSK_BNAIN_INTR_MSK Get Value */


#define USB_DIEPMSK_DIEP_MSK_TXFIFO_UNDRN_MSK_Pos    (8U)                                                                        /*!< DIEP_MSK_TXFIFO_UNDRN_MSK Postion   */ 
#define USB_DIEPMSK_DIEP_MSK_TXFIFO_UNDRN_MSK_Msk    (0x1U << USB_DIEPMSK_DIEP_MSK_TXFIFO_UNDRN_MSK_Pos)                         /*!< DIEP_MSK_TXFIFO_UNDRN_MSK Mask      */
#define USB_DIEPMSK_DIEP_MSK_TXFIFO_UNDRN_MSK_Set(x) (((uint32_t) (x) << USB_DIEPMSK_DIEP_MSK_TXFIFO_UNDRN_MSK_Pos) & USB_DIEPMSK_DIEP_MSK_TXFIFO_UNDRN_MSK_Msk) /*!< DIEP_MSK_TXFIFO_UNDRN_MSK Set Value */
#define USB_DIEPMSK_DIEP_MSK_TXFIFO_UNDRN_MSK_Get(x) (((uint32_t) (x) & USB_DIEPMSK_DIEP_MSK_TXFIFO_UNDRN_MSK_Msk) >> USB_DIEPMSK_DIEP_MSK_TXFIFO_UNDRN_MSK_Pos) /*!< DIEP_MSK_TXFIFO_UNDRN_MSK Get Value */


#define USB_DIEPMSK_DIEP_MSK_IN_EP_NAK_EFF_MSK_Pos    (6U)                                                                        /*!< DIEP_MSK_IN_EP_NAK_EFF_MSK Postion   */ 
#define USB_DIEPMSK_DIEP_MSK_IN_EP_NAK_EFF_MSK_Msk    (0x1U << USB_DIEPMSK_DIEP_MSK_IN_EP_NAK_EFF_MSK_Pos)                        /*!< DIEP_MSK_IN_EP_NAK_EFF_MSK Mask      */
#define USB_DIEPMSK_DIEP_MSK_IN_EP_NAK_EFF_MSK_Set(x) (((uint32_t) (x) << USB_DIEPMSK_DIEP_MSK_IN_EP_NAK_EFF_MSK_Pos) & USB_DIEPMSK_DIEP_MSK_IN_EP_NAK_EFF_MSK_Msk) /*!< DIEP_MSK_IN_EP_NAK_EFF_MSK Set Value */
#define USB_DIEPMSK_DIEP_MSK_IN_EP_NAK_EFF_MSK_Get(x) (((uint32_t) (x) & USB_DIEPMSK_DIEP_MSK_IN_EP_NAK_EFF_MSK_Msk) >> USB_DIEPMSK_DIEP_MSK_IN_EP_NAK_EFF_MSK_Pos) /*!< DIEP_MSK_IN_EP_NAK_EFF_MSK Get Value */


#define USB_DIEPMSK_DIEP_MSK_IN_TKN_EP_MIS_MSK_Pos    (5U)                                                                        /*!< DIEP_MSK_IN_TKN_EP_MIS_MSK Postion   */ 
#define USB_DIEPMSK_DIEP_MSK_IN_TKN_EP_MIS_MSK_Msk    (0x1U << USB_DIEPMSK_DIEP_MSK_IN_TKN_EP_MIS_MSK_Pos)                        /*!< DIEP_MSK_IN_TKN_EP_MIS_MSK Mask      */
#define USB_DIEPMSK_DIEP_MSK_IN_TKN_EP_MIS_MSK_Set(x) (((uint32_t) (x) << USB_DIEPMSK_DIEP_MSK_IN_TKN_EP_MIS_MSK_Pos) & USB_DIEPMSK_DIEP_MSK_IN_TKN_EP_MIS_MSK_Msk) /*!< DIEP_MSK_IN_TKN_EP_MIS_MSK Set Value */
#define USB_DIEPMSK_DIEP_MSK_IN_TKN_EP_MIS_MSK_Get(x) (((uint32_t) (x) & USB_DIEPMSK_DIEP_MSK_IN_TKN_EP_MIS_MSK_Msk) >> USB_DIEPMSK_DIEP_MSK_IN_TKN_EP_MIS_MSK_Pos) /*!< DIEP_MSK_IN_TKN_EP_MIS_MSK Get Value */


#define USB_DIEPMSK_DIEP_MSK_IN_TKN_TXFEMP_MSK_Pos    (4U)                                                                        /*!< DIEP_MSK_IN_TKN_TXFEMP_MSK Postion   */ 
#define USB_DIEPMSK_DIEP_MSK_IN_TKN_TXFEMP_MSK_Msk    (0x1U << USB_DIEPMSK_DIEP_MSK_IN_TKN_TXFEMP_MSK_Pos)                        /*!< DIEP_MSK_IN_TKN_TXFEMP_MSK Mask      */
#define USB_DIEPMSK_DIEP_MSK_IN_TKN_TXFEMP_MSK_Set(x) (((uint32_t) (x) << USB_DIEPMSK_DIEP_MSK_IN_TKN_TXFEMP_MSK_Pos) & USB_DIEPMSK_DIEP_MSK_IN_TKN_TXFEMP_MSK_Msk) /*!< DIEP_MSK_IN_TKN_TXFEMP_MSK Set Value */
#define USB_DIEPMSK_DIEP_MSK_IN_TKN_TXFEMP_MSK_Get(x) (((uint32_t) (x) & USB_DIEPMSK_DIEP_MSK_IN_TKN_TXFEMP_MSK_Msk) >> USB_DIEPMSK_DIEP_MSK_IN_TKN_TXFEMP_MSK_Pos) /*!< DIEP_MSK_IN_TKN_TXFEMP_MSK Get Value */


#define USB_DIEPMSK_DIEP_MSK_TIME_OUT_MSK_Pos    (3U)                                                                        /*!< DIEP_MSK_TIME_OUT_MSK Postion   */ 
#define USB_DIEPMSK_DIEP_MSK_TIME_OUT_MSK_Msk    (0x1U << USB_DIEPMSK_DIEP_MSK_TIME_OUT_MSK_Pos)                             /*!< DIEP_MSK_TIME_OUT_MSK Mask      */
#define USB_DIEPMSK_DIEP_MSK_TIME_OUT_MSK_Set(x) (((uint32_t) (x) << USB_DIEPMSK_DIEP_MSK_TIME_OUT_MSK_Pos) & USB_DIEPMSK_DIEP_MSK_TIME_OUT_MSK_Msk) /*!< DIEP_MSK_TIME_OUT_MSK Set Value */
#define USB_DIEPMSK_DIEP_MSK_TIME_OUT_MSK_Get(x) (((uint32_t) (x) & USB_DIEPMSK_DIEP_MSK_TIME_OUT_MSK_Msk) >> USB_DIEPMSK_DIEP_MSK_TIME_OUT_MSK_Pos) /*!< DIEP_MSK_TIME_OUT_MSK Get Value */


#define USB_DIEPMSK_DIEP_MSK_AHB_ERR_MSK_Pos    (2U)                                                                        /*!< DIEP_MSK_AHB_ERR_MSK Postion   */ 
#define USB_DIEPMSK_DIEP_MSK_AHB_ERR_MSK_Msk    (0x1U << USB_DIEPMSK_DIEP_MSK_AHB_ERR_MSK_Pos)                              /*!< DIEP_MSK_AHB_ERR_MSK Mask      */
#define USB_DIEPMSK_DIEP_MSK_AHB_ERR_MSK_Set(x) (((uint32_t) (x) << USB_DIEPMSK_DIEP_MSK_AHB_ERR_MSK_Pos) & USB_DIEPMSK_DIEP_MSK_AHB_ERR_MSK_Msk) /*!< DIEP_MSK_AHB_ERR_MSK Set Value */
#define USB_DIEPMSK_DIEP_MSK_AHB_ERR_MSK_Get(x) (((uint32_t) (x) & USB_DIEPMSK_DIEP_MSK_AHB_ERR_MSK_Msk) >> USB_DIEPMSK_DIEP_MSK_AHB_ERR_MSK_Pos) /*!< DIEP_MSK_AHB_ERR_MSK Get Value */


#define USB_DIEPMSK_DIEP_MSK_EP_DISBLD_MSK_Pos    (1U)                                                                        /*!< DIEP_MSK_EP_DISBLD_MSK Postion   */ 
#define USB_DIEPMSK_DIEP_MSK_EP_DISBLD_MSK_Msk    (0x1U << USB_DIEPMSK_DIEP_MSK_EP_DISBLD_MSK_Pos)                            /*!< DIEP_MSK_EP_DISBLD_MSK Mask      */
#define USB_DIEPMSK_DIEP_MSK_EP_DISBLD_MSK_Set(x) (((uint32_t) (x) << USB_DIEPMSK_DIEP_MSK_EP_DISBLD_MSK_Pos) & USB_DIEPMSK_DIEP_MSK_EP_DISBLD_MSK_Msk) /*!< DIEP_MSK_EP_DISBLD_MSK Set Value */
#define USB_DIEPMSK_DIEP_MSK_EP_DISBLD_MSK_Get(x) (((uint32_t) (x) & USB_DIEPMSK_DIEP_MSK_EP_DISBLD_MSK_Msk) >> USB_DIEPMSK_DIEP_MSK_EP_DISBLD_MSK_Pos) /*!< DIEP_MSK_EP_DISBLD_MSK Get Value */


#define USB_DIEPMSK_DIEP_MSK_XFER_COMPL_MSK_Pos    (0U)                                                                        /*!< DIEP_MSK_XFER_COMPL_MSK Postion   */ 
#define USB_DIEPMSK_DIEP_MSK_XFER_COMPL_MSK_Msk    (0x1U << USB_DIEPMSK_DIEP_MSK_XFER_COMPL_MSK_Pos)                           /*!< DIEP_MSK_XFER_COMPL_MSK Mask      */
#define USB_DIEPMSK_DIEP_MSK_XFER_COMPL_MSK_Set(x) (((uint32_t) (x) << USB_DIEPMSK_DIEP_MSK_XFER_COMPL_MSK_Pos) & USB_DIEPMSK_DIEP_MSK_XFER_COMPL_MSK_Msk) /*!< DIEP_MSK_XFER_COMPL_MSK Set Value */
#define USB_DIEPMSK_DIEP_MSK_XFER_COMPL_MSK_Get(x) (((uint32_t) (x) & USB_DIEPMSK_DIEP_MSK_XFER_COMPL_MSK_Msk) >> USB_DIEPMSK_DIEP_MSK_XFER_COMPL_MSK_Pos) /*!< DIEP_MSK_XFER_COMPL_MSK Get Value */


/* DOEPMSK bitfield */
#define USB_DOEPMSK_DOEP_MSK_NYETMSK_Pos    (14U)                                                                       /*!< DOEP_MSK_NYETMSK Postion   */ 
#define USB_DOEPMSK_DOEP_MSK_NYETMSK_Msk    (0x1U << USB_DOEPMSK_DOEP_MSK_NYETMSK_Pos)                                  /*!< DOEP_MSK_NYETMSK Mask      */
#define USB_DOEPMSK_DOEP_MSK_NYETMSK_Set(x) (((uint32_t) (x) << USB_DOEPMSK_DOEP_MSK_NYETMSK_Pos) & USB_DOEPMSK_DOEP_MSK_NYETMSK_Msk) /*!< DOEP_MSK_NYETMSK Set Value */
#define USB_DOEPMSK_DOEP_MSK_NYETMSK_Get(x) (((uint32_t) (x) & USB_DOEPMSK_DOEP_MSK_NYETMSK_Msk) >> USB_DOEPMSK_DOEP_MSK_NYETMSK_Pos) /*!< DOEP_MSK_NYETMSK Get Value */


#define USB_DOEPMSK_DOEP_MSK_NAKMSK_Pos    (13U)                                                                       /*!< DOEP_MSK_NAKMSK Postion   */ 
#define USB_DOEPMSK_DOEP_MSK_NAKMSK_Msk    (0x1U << USB_DOEPMSK_DOEP_MSK_NAKMSK_Pos)                                   /*!< DOEP_MSK_NAKMSK Mask      */
#define USB_DOEPMSK_DOEP_MSK_NAKMSK_Set(x) (((uint32_t) (x) << USB_DOEPMSK_DOEP_MSK_NAKMSK_Pos) & USB_DOEPMSK_DOEP_MSK_NAKMSK_Msk) /*!< DOEP_MSK_NAKMSK Set Value */
#define USB_DOEPMSK_DOEP_MSK_NAKMSK_Get(x) (((uint32_t) (x) & USB_DOEPMSK_DOEP_MSK_NAKMSK_Msk) >> USB_DOEPMSK_DOEP_MSK_NAKMSK_Pos) /*!< DOEP_MSK_NAKMSK Get Value */


#define USB_DOEPMSK_DOEP_MSK_BBLE_ERR_MSK_Pos    (12U)                                                                       /*!< DOEP_MSK_BBLE_ERR_MSK Postion   */ 
#define USB_DOEPMSK_DOEP_MSK_BBLE_ERR_MSK_Msk    (0x1U << USB_DOEPMSK_DOEP_MSK_BBLE_ERR_MSK_Pos)                             /*!< DOEP_MSK_BBLE_ERR_MSK Mask      */
#define USB_DOEPMSK_DOEP_MSK_BBLE_ERR_MSK_Set(x) (((uint32_t) (x) << USB_DOEPMSK_DOEP_MSK_BBLE_ERR_MSK_Pos) & USB_DOEPMSK_DOEP_MSK_BBLE_ERR_MSK_Msk) /*!< DOEP_MSK_BBLE_ERR_MSK Set Value */
#define USB_DOEPMSK_DOEP_MSK_BBLE_ERR_MSK_Get(x) (((uint32_t) (x) & USB_DOEPMSK_DOEP_MSK_BBLE_ERR_MSK_Msk) >> USB_DOEPMSK_DOEP_MSK_BBLE_ERR_MSK_Pos) /*!< DOEP_MSK_BBLE_ERR_MSK Get Value */


#define USB_DOEPMSK_DOEP_MSK_BNA_OUT_INTR_MSK_Pos    (9U)                                                                        /*!< DOEP_MSK_BNA_OUT_INTR_MSK Postion   */ 
#define USB_DOEPMSK_DOEP_MSK_BNA_OUT_INTR_MSK_Msk    (0x1U << USB_DOEPMSK_DOEP_MSK_BNA_OUT_INTR_MSK_Pos)                         /*!< DOEP_MSK_BNA_OUT_INTR_MSK Mask      */
#define USB_DOEPMSK_DOEP_MSK_BNA_OUT_INTR_MSK_Set(x) (((uint32_t) (x) << USB_DOEPMSK_DOEP_MSK_BNA_OUT_INTR_MSK_Pos) & USB_DOEPMSK_DOEP_MSK_BNA_OUT_INTR_MSK_Msk) /*!< DOEP_MSK_BNA_OUT_INTR_MSK Set Value */
#define USB_DOEPMSK_DOEP_MSK_BNA_OUT_INTR_MSK_Get(x) (((uint32_t) (x) & USB_DOEPMSK_DOEP_MSK_BNA_OUT_INTR_MSK_Msk) >> USB_DOEPMSK_DOEP_MSK_BNA_OUT_INTR_MSK_Pos) /*!< DOEP_MSK_BNA_OUT_INTR_MSK Get Value */


#define USB_DOEPMSK_DOEP_MSK_OUT_PKT_ERR_MSK_Pos    (8U)                                                                        /*!< DOEP_MSK_OUT_PKT_ERR_MSK Postion   */ 
#define USB_DOEPMSK_DOEP_MSK_OUT_PKT_ERR_MSK_Msk    (0x1U << USB_DOEPMSK_DOEP_MSK_OUT_PKT_ERR_MSK_Pos)                          /*!< DOEP_MSK_OUT_PKT_ERR_MSK Mask      */
#define USB_DOEPMSK_DOEP_MSK_OUT_PKT_ERR_MSK_Set(x) (((uint32_t) (x) << USB_DOEPMSK_DOEP_MSK_OUT_PKT_ERR_MSK_Pos) & USB_DOEPMSK_DOEP_MSK_OUT_PKT_ERR_MSK_Msk) /*!< DOEP_MSK_OUT_PKT_ERR_MSK Set Value */
#define USB_DOEPMSK_DOEP_MSK_OUT_PKT_ERR_MSK_Get(x) (((uint32_t) (x) & USB_DOEPMSK_DOEP_MSK_OUT_PKT_ERR_MSK_Msk) >> USB_DOEPMSK_DOEP_MSK_OUT_PKT_ERR_MSK_Pos) /*!< DOEP_MSK_OUT_PKT_ERR_MSK Get Value */


#define USB_DOEPMSK_DOEP_MSK_BACK2BACK_SETUP_Pos    (6U)                                                                        /*!< DOEP_MSK_BACK2BACK_SETUP Postion   */ 
#define USB_DOEPMSK_DOEP_MSK_BACK2BACK_SETUP_Msk    (0x1U << USB_DOEPMSK_DOEP_MSK_BACK2BACK_SETUP_Pos)                          /*!< DOEP_MSK_BACK2BACK_SETUP Mask      */
#define USB_DOEPMSK_DOEP_MSK_BACK2BACK_SETUP_Set(x) (((uint32_t) (x) << USB_DOEPMSK_DOEP_MSK_BACK2BACK_SETUP_Pos) & USB_DOEPMSK_DOEP_MSK_BACK2BACK_SETUP_Msk) /*!< DOEP_MSK_BACK2BACK_SETUP Set Value */
#define USB_DOEPMSK_DOEP_MSK_BACK2BACK_SETUP_Get(x) (((uint32_t) (x) & USB_DOEPMSK_DOEP_MSK_BACK2BACK_SETUP_Msk) >> USB_DOEPMSK_DOEP_MSK_BACK2BACK_SETUP_Pos) /*!< DOEP_MSK_BACK2BACK_SETUP Get Value */


#define USB_DOEPMSK_DOEP_MSK_STS_PHSE_RCVD_MSK_Pos    (5U)                                                                        /*!< DOEP_MSK_STS_PHSE_RCVD_MSK Postion   */ 
#define USB_DOEPMSK_DOEP_MSK_STS_PHSE_RCVD_MSK_Msk    (0x1U << USB_DOEPMSK_DOEP_MSK_STS_PHSE_RCVD_MSK_Pos)                        /*!< DOEP_MSK_STS_PHSE_RCVD_MSK Mask      */
#define USB_DOEPMSK_DOEP_MSK_STS_PHSE_RCVD_MSK_Set(x) (((uint32_t) (x) << USB_DOEPMSK_DOEP_MSK_STS_PHSE_RCVD_MSK_Pos) & USB_DOEPMSK_DOEP_MSK_STS_PHSE_RCVD_MSK_Msk) /*!< DOEP_MSK_STS_PHSE_RCVD_MSK Set Value */
#define USB_DOEPMSK_DOEP_MSK_STS_PHSE_RCVD_MSK_Get(x) (((uint32_t) (x) & USB_DOEPMSK_DOEP_MSK_STS_PHSE_RCVD_MSK_Msk) >> USB_DOEPMSK_DOEP_MSK_STS_PHSE_RCVD_MSK_Pos) /*!< DOEP_MSK_STS_PHSE_RCVD_MSK Get Value */


#define USB_DOEPMSK_DOEP_MSK_OUT_TKN_EP_DIS_MSK_Pos    (4U)                                                                        /*!< DOEP_MSK_OUT_TKN_EP_DIS_MSK Postion   */ 
#define USB_DOEPMSK_DOEP_MSK_OUT_TKN_EP_DIS_MSK_Msk    (0x1U << USB_DOEPMSK_DOEP_MSK_OUT_TKN_EP_DIS_MSK_Pos)                       /*!< DOEP_MSK_OUT_TKN_EP_DIS_MSK Mask      */
#define USB_DOEPMSK_DOEP_MSK_OUT_TKN_EP_DIS_MSK_Set(x) (((uint32_t) (x) << USB_DOEPMSK_DOEP_MSK_OUT_TKN_EP_DIS_MSK_Pos) & USB_DOEPMSK_DOEP_MSK_OUT_TKN_EP_DIS_MSK_Msk) /*!< DOEP_MSK_OUT_TKN_EP_DIS_MSK Set Value */
#define USB_DOEPMSK_DOEP_MSK_OUT_TKN_EP_DIS_MSK_Get(x) (((uint32_t) (x) & USB_DOEPMSK_DOEP_MSK_OUT_TKN_EP_DIS_MSK_Msk) >> USB_DOEPMSK_DOEP_MSK_OUT_TKN_EP_DIS_MSK_Pos) /*!< DOEP_MSK_OUT_TKN_EP_DIS_MSK Get Value */


#define USB_DOEPMSK_DOEP_MSK_SET_UPMSK_Pos    (3U)                                                                        /*!< DOEP_MSK_SET_UPMSK Postion   */ 
#define USB_DOEPMSK_DOEP_MSK_SET_UPMSK_Msk    (0x1U << USB_DOEPMSK_DOEP_MSK_SET_UPMSK_Pos)                                /*!< DOEP_MSK_SET_UPMSK Mask      */
#define USB_DOEPMSK_DOEP_MSK_SET_UPMSK_Set(x) (((uint32_t) (x) << USB_DOEPMSK_DOEP_MSK_SET_UPMSK_Pos) & USB_DOEPMSK_DOEP_MSK_SET_UPMSK_Msk) /*!< DOEP_MSK_SET_UPMSK Set Value */
#define USB_DOEPMSK_DOEP_MSK_SET_UPMSK_Get(x) (((uint32_t) (x) & USB_DOEPMSK_DOEP_MSK_SET_UPMSK_Msk) >> USB_DOEPMSK_DOEP_MSK_SET_UPMSK_Pos) /*!< DOEP_MSK_SET_UPMSK Get Value */


#define USB_DOEPMSK_DOEP_MSK_AHB_ERR_MSK_Pos    (2U)                                                                        /*!< DOEP_MSK_AHB_ERR_MSK Postion   */ 
#define USB_DOEPMSK_DOEP_MSK_AHB_ERR_MSK_Msk    (0x1U << USB_DOEPMSK_DOEP_MSK_AHB_ERR_MSK_Pos)                              /*!< DOEP_MSK_AHB_ERR_MSK Mask      */
#define USB_DOEPMSK_DOEP_MSK_AHB_ERR_MSK_Set(x) (((uint32_t) (x) << USB_DOEPMSK_DOEP_MSK_AHB_ERR_MSK_Pos) & USB_DOEPMSK_DOEP_MSK_AHB_ERR_MSK_Msk) /*!< DOEP_MSK_AHB_ERR_MSK Set Value */
#define USB_DOEPMSK_DOEP_MSK_AHB_ERR_MSK_Get(x) (((uint32_t) (x) & USB_DOEPMSK_DOEP_MSK_AHB_ERR_MSK_Msk) >> USB_DOEPMSK_DOEP_MSK_AHB_ERR_MSK_Pos) /*!< DOEP_MSK_AHB_ERR_MSK Get Value */


#define USB_DOEPMSK_DOEP_MSK_EP_DISBLD_MSK_Pos    (1U)                                                                        /*!< DOEP_MSK_EP_DISBLD_MSK Postion   */ 
#define USB_DOEPMSK_DOEP_MSK_EP_DISBLD_MSK_Msk    (0x1U << USB_DOEPMSK_DOEP_MSK_EP_DISBLD_MSK_Pos)                            /*!< DOEP_MSK_EP_DISBLD_MSK Mask      */
#define USB_DOEPMSK_DOEP_MSK_EP_DISBLD_MSK_Set(x) (((uint32_t) (x) << USB_DOEPMSK_DOEP_MSK_EP_DISBLD_MSK_Pos) & USB_DOEPMSK_DOEP_MSK_EP_DISBLD_MSK_Msk) /*!< DOEP_MSK_EP_DISBLD_MSK Set Value */
#define USB_DOEPMSK_DOEP_MSK_EP_DISBLD_MSK_Get(x) (((uint32_t) (x) & USB_DOEPMSK_DOEP_MSK_EP_DISBLD_MSK_Msk) >> USB_DOEPMSK_DOEP_MSK_EP_DISBLD_MSK_Pos) /*!< DOEP_MSK_EP_DISBLD_MSK Get Value */


#define USB_DOEPMSK_DOEP_MSK_XFER_COMPL_MSK_Pos    (0U)                                                                        /*!< DOEP_MSK_XFER_COMPL_MSK Postion   */ 
#define USB_DOEPMSK_DOEP_MSK_XFER_COMPL_MSK_Msk    (0x1U << USB_DOEPMSK_DOEP_MSK_XFER_COMPL_MSK_Pos)                           /*!< DOEP_MSK_XFER_COMPL_MSK Mask      */
#define USB_DOEPMSK_DOEP_MSK_XFER_COMPL_MSK_Set(x) (((uint32_t) (x) << USB_DOEPMSK_DOEP_MSK_XFER_COMPL_MSK_Pos) & USB_DOEPMSK_DOEP_MSK_XFER_COMPL_MSK_Msk) /*!< DOEP_MSK_XFER_COMPL_MSK Set Value */
#define USB_DOEPMSK_DOEP_MSK_XFER_COMPL_MSK_Get(x) (((uint32_t) (x) & USB_DOEPMSK_DOEP_MSK_XFER_COMPL_MSK_Msk) >> USB_DOEPMSK_DOEP_MSK_XFER_COMPL_MSK_Pos) /*!< DOEP_MSK_XFER_COMPL_MSK Get Value */


/* DAINT bitfield */
#define USB_DAINT_OUT_EP_INT15_Pos    (31U)                                                                       /*!< OUT_EP_INT15 Postion   */ 
#define USB_DAINT_OUT_EP_INT15_Msk    (0x1U << USB_DAINT_OUT_EP_INT15_Pos)                                        /*!< OUT_EP_INT15 Mask      */
#define USB_DAINT_OUT_EP_INT15_Set(x) (((uint32_t) (x) << USB_DAINT_OUT_EP_INT15_Pos) & USB_DAINT_OUT_EP_INT15_Msk) /*!< OUT_EP_INT15 Set Value */
#define USB_DAINT_OUT_EP_INT15_Get(x) (((uint32_t) (x) & USB_DAINT_OUT_EP_INT15_Msk) >> USB_DAINT_OUT_EP_INT15_Pos) /*!< OUT_EP_INT15 Get Value */


#define USB_DAINT_OUT_EP_INT14_Pos    (30U)                                                                       /*!< OUT_EP_INT14 Postion   */ 
#define USB_DAINT_OUT_EP_INT14_Msk    (0x1U << USB_DAINT_OUT_EP_INT14_Pos)                                        /*!< OUT_EP_INT14 Mask      */
#define USB_DAINT_OUT_EP_INT14_Set(x) (((uint32_t) (x) << USB_DAINT_OUT_EP_INT14_Pos) & USB_DAINT_OUT_EP_INT14_Msk) /*!< OUT_EP_INT14 Set Value */
#define USB_DAINT_OUT_EP_INT14_Get(x) (((uint32_t) (x) & USB_DAINT_OUT_EP_INT14_Msk) >> USB_DAINT_OUT_EP_INT14_Pos) /*!< OUT_EP_INT14 Get Value */


#define USB_DAINT_OUT_EP_INT13_Pos    (29U)                                                                       /*!< OUT_EP_INT13 Postion   */ 
#define USB_DAINT_OUT_EP_INT13_Msk    (0x1U << USB_DAINT_OUT_EP_INT13_Pos)                                        /*!< OUT_EP_INT13 Mask      */
#define USB_DAINT_OUT_EP_INT13_Set(x) (((uint32_t) (x) << USB_DAINT_OUT_EP_INT13_Pos) & USB_DAINT_OUT_EP_INT13_Msk) /*!< OUT_EP_INT13 Set Value */
#define USB_DAINT_OUT_EP_INT13_Get(x) (((uint32_t) (x) & USB_DAINT_OUT_EP_INT13_Msk) >> USB_DAINT_OUT_EP_INT13_Pos) /*!< OUT_EP_INT13 Get Value */


#define USB_DAINT_OUT_EP_INT12_Pos    (28U)                                                                       /*!< OUT_EP_INT12 Postion   */ 
#define USB_DAINT_OUT_EP_INT12_Msk    (0x1U << USB_DAINT_OUT_EP_INT12_Pos)                                        /*!< OUT_EP_INT12 Mask      */
#define USB_DAINT_OUT_EP_INT12_Set(x) (((uint32_t) (x) << USB_DAINT_OUT_EP_INT12_Pos) & USB_DAINT_OUT_EP_INT12_Msk) /*!< OUT_EP_INT12 Set Value */
#define USB_DAINT_OUT_EP_INT12_Get(x) (((uint32_t) (x) & USB_DAINT_OUT_EP_INT12_Msk) >> USB_DAINT_OUT_EP_INT12_Pos) /*!< OUT_EP_INT12 Get Value */


#define USB_DAINT_OUT_EP_INT11_Pos    (27U)                                                                       /*!< OUT_EP_INT11 Postion   */ 
#define USB_DAINT_OUT_EP_INT11_Msk    (0x1U << USB_DAINT_OUT_EP_INT11_Pos)                                        /*!< OUT_EP_INT11 Mask      */
#define USB_DAINT_OUT_EP_INT11_Set(x) (((uint32_t) (x) << USB_DAINT_OUT_EP_INT11_Pos) & USB_DAINT_OUT_EP_INT11_Msk) /*!< OUT_EP_INT11 Set Value */
#define USB_DAINT_OUT_EP_INT11_Get(x) (((uint32_t) (x) & USB_DAINT_OUT_EP_INT11_Msk) >> USB_DAINT_OUT_EP_INT11_Pos) /*!< OUT_EP_INT11 Get Value */


#define USB_DAINT_OUT_EP_INT10_Pos    (26U)                                                                       /*!< OUT_EP_INT10 Postion   */ 
#define USB_DAINT_OUT_EP_INT10_Msk    (0x1U << USB_DAINT_OUT_EP_INT10_Pos)                                        /*!< OUT_EP_INT10 Mask      */
#define USB_DAINT_OUT_EP_INT10_Set(x) (((uint32_t) (x) << USB_DAINT_OUT_EP_INT10_Pos) & USB_DAINT_OUT_EP_INT10_Msk) /*!< OUT_EP_INT10 Set Value */
#define USB_DAINT_OUT_EP_INT10_Get(x) (((uint32_t) (x) & USB_DAINT_OUT_EP_INT10_Msk) >> USB_DAINT_OUT_EP_INT10_Pos) /*!< OUT_EP_INT10 Get Value */


#define USB_DAINT_OUT_EP_INT9_Pos    (25U)                                                                       /*!< OUT_EP_INT9 Postion   */ 
#define USB_DAINT_OUT_EP_INT9_Msk    (0x1U << USB_DAINT_OUT_EP_INT9_Pos)                                         /*!< OUT_EP_INT9 Mask      */
#define USB_DAINT_OUT_EP_INT9_Set(x) (((uint32_t) (x) << USB_DAINT_OUT_EP_INT9_Pos) & USB_DAINT_OUT_EP_INT9_Msk) /*!< OUT_EP_INT9 Set Value */
#define USB_DAINT_OUT_EP_INT9_Get(x) (((uint32_t) (x) & USB_DAINT_OUT_EP_INT9_Msk) >> USB_DAINT_OUT_EP_INT9_Pos) /*!< OUT_EP_INT9 Get Value */


#define USB_DAINT_OUT_EP_INT8_Pos    (24U)                                                                       /*!< OUT_EP_INT8 Postion   */ 
#define USB_DAINT_OUT_EP_INT8_Msk    (0x1U << USB_DAINT_OUT_EP_INT8_Pos)                                         /*!< OUT_EP_INT8 Mask      */
#define USB_DAINT_OUT_EP_INT8_Set(x) (((uint32_t) (x) << USB_DAINT_OUT_EP_INT8_Pos) & USB_DAINT_OUT_EP_INT8_Msk) /*!< OUT_EP_INT8 Set Value */
#define USB_DAINT_OUT_EP_INT8_Get(x) (((uint32_t) (x) & USB_DAINT_OUT_EP_INT8_Msk) >> USB_DAINT_OUT_EP_INT8_Pos) /*!< OUT_EP_INT8 Get Value */


#define USB_DAINT_OUT_EP_INT7_Pos    (23U)                                                                       /*!< OUT_EP_INT7 Postion   */ 
#define USB_DAINT_OUT_EP_INT7_Msk    (0x1U << USB_DAINT_OUT_EP_INT7_Pos)                                         /*!< OUT_EP_INT7 Mask      */
#define USB_DAINT_OUT_EP_INT7_Set(x) (((uint32_t) (x) << USB_DAINT_OUT_EP_INT7_Pos) & USB_DAINT_OUT_EP_INT7_Msk) /*!< OUT_EP_INT7 Set Value */
#define USB_DAINT_OUT_EP_INT7_Get(x) (((uint32_t) (x) & USB_DAINT_OUT_EP_INT7_Msk) >> USB_DAINT_OUT_EP_INT7_Pos) /*!< OUT_EP_INT7 Get Value */


#define USB_DAINT_OUT_EP_INT6_Pos    (22U)                                                                       /*!< OUT_EP_INT6 Postion   */ 
#define USB_DAINT_OUT_EP_INT6_Msk    (0x1U << USB_DAINT_OUT_EP_INT6_Pos)                                         /*!< OUT_EP_INT6 Mask      */
#define USB_DAINT_OUT_EP_INT6_Set(x) (((uint32_t) (x) << USB_DAINT_OUT_EP_INT6_Pos) & USB_DAINT_OUT_EP_INT6_Msk) /*!< OUT_EP_INT6 Set Value */
#define USB_DAINT_OUT_EP_INT6_Get(x) (((uint32_t) (x) & USB_DAINT_OUT_EP_INT6_Msk) >> USB_DAINT_OUT_EP_INT6_Pos) /*!< OUT_EP_INT6 Get Value */


#define USB_DAINT_OUT_EP_INT5_Pos    (21U)                                                                       /*!< OUT_EP_INT5 Postion   */ 
#define USB_DAINT_OUT_EP_INT5_Msk    (0x1U << USB_DAINT_OUT_EP_INT5_Pos)                                         /*!< OUT_EP_INT5 Mask      */
#define USB_DAINT_OUT_EP_INT5_Set(x) (((uint32_t) (x) << USB_DAINT_OUT_EP_INT5_Pos) & USB_DAINT_OUT_EP_INT5_Msk) /*!< OUT_EP_INT5 Set Value */
#define USB_DAINT_OUT_EP_INT5_Get(x) (((uint32_t) (x) & USB_DAINT_OUT_EP_INT5_Msk) >> USB_DAINT_OUT_EP_INT5_Pos) /*!< OUT_EP_INT5 Get Value */


#define USB_DAINT_OUT_EP_INT4_Pos    (20U)                                                                       /*!< OUT_EP_INT4 Postion   */ 
#define USB_DAINT_OUT_EP_INT4_Msk    (0x1U << USB_DAINT_OUT_EP_INT4_Pos)                                         /*!< OUT_EP_INT4 Mask      */
#define USB_DAINT_OUT_EP_INT4_Set(x) (((uint32_t) (x) << USB_DAINT_OUT_EP_INT4_Pos) & USB_DAINT_OUT_EP_INT4_Msk) /*!< OUT_EP_INT4 Set Value */
#define USB_DAINT_OUT_EP_INT4_Get(x) (((uint32_t) (x) & USB_DAINT_OUT_EP_INT4_Msk) >> USB_DAINT_OUT_EP_INT4_Pos) /*!< OUT_EP_INT4 Get Value */


#define USB_DAINT_OUT_EP_INT3_Pos    (19U)                                                                       /*!< OUT_EP_INT3 Postion   */ 
#define USB_DAINT_OUT_EP_INT3_Msk    (0x1U << USB_DAINT_OUT_EP_INT3_Pos)                                         /*!< OUT_EP_INT3 Mask      */
#define USB_DAINT_OUT_EP_INT3_Set(x) (((uint32_t) (x) << USB_DAINT_OUT_EP_INT3_Pos) & USB_DAINT_OUT_EP_INT3_Msk) /*!< OUT_EP_INT3 Set Value */
#define USB_DAINT_OUT_EP_INT3_Get(x) (((uint32_t) (x) & USB_DAINT_OUT_EP_INT3_Msk) >> USB_DAINT_OUT_EP_INT3_Pos) /*!< OUT_EP_INT3 Get Value */


#define USB_DAINT_OUT_EP_INT2_Pos    (18U)                                                                       /*!< OUT_EP_INT2 Postion   */ 
#define USB_DAINT_OUT_EP_INT2_Msk    (0x1U << USB_DAINT_OUT_EP_INT2_Pos)                                         /*!< OUT_EP_INT2 Mask      */
#define USB_DAINT_OUT_EP_INT2_Set(x) (((uint32_t) (x) << USB_DAINT_OUT_EP_INT2_Pos) & USB_DAINT_OUT_EP_INT2_Msk) /*!< OUT_EP_INT2 Set Value */
#define USB_DAINT_OUT_EP_INT2_Get(x) (((uint32_t) (x) & USB_DAINT_OUT_EP_INT2_Msk) >> USB_DAINT_OUT_EP_INT2_Pos) /*!< OUT_EP_INT2 Get Value */


#define USB_DAINT_OUT_EP_INT1_Pos    (17U)                                                                       /*!< OUT_EP_INT1 Postion   */ 
#define USB_DAINT_OUT_EP_INT1_Msk    (0x1U << USB_DAINT_OUT_EP_INT1_Pos)                                         /*!< OUT_EP_INT1 Mask      */
#define USB_DAINT_OUT_EP_INT1_Set(x) (((uint32_t) (x) << USB_DAINT_OUT_EP_INT1_Pos) & USB_DAINT_OUT_EP_INT1_Msk) /*!< OUT_EP_INT1 Set Value */
#define USB_DAINT_OUT_EP_INT1_Get(x) (((uint32_t) (x) & USB_DAINT_OUT_EP_INT1_Msk) >> USB_DAINT_OUT_EP_INT1_Pos) /*!< OUT_EP_INT1 Get Value */


#define USB_DAINT_OUT_EP_INT0_Pos    (16U)                                                                       /*!< OUT_EP_INT0 Postion   */ 
#define USB_DAINT_OUT_EP_INT0_Msk    (0x1U << USB_DAINT_OUT_EP_INT0_Pos)                                         /*!< OUT_EP_INT0 Mask      */
#define USB_DAINT_OUT_EP_INT0_Set(x) (((uint32_t) (x) << USB_DAINT_OUT_EP_INT0_Pos) & USB_DAINT_OUT_EP_INT0_Msk) /*!< OUT_EP_INT0 Set Value */
#define USB_DAINT_OUT_EP_INT0_Get(x) (((uint32_t) (x) & USB_DAINT_OUT_EP_INT0_Msk) >> USB_DAINT_OUT_EP_INT0_Pos) /*!< OUT_EP_INT0 Get Value */


#define USB_DAINT_IN_EP_INT15_Pos    (15U)                                                                       /*!< IN_EP_INT15 Postion   */ 
#define USB_DAINT_IN_EP_INT15_Msk    (0x1U << USB_DAINT_IN_EP_INT15_Pos)                                         /*!< IN_EP_INT15 Mask      */
#define USB_DAINT_IN_EP_INT15_Set(x) (((uint32_t) (x) << USB_DAINT_IN_EP_INT15_Pos) & USB_DAINT_IN_EP_INT15_Msk) /*!< IN_EP_INT15 Set Value */
#define USB_DAINT_IN_EP_INT15_Get(x) (((uint32_t) (x) & USB_DAINT_IN_EP_INT15_Msk) >> USB_DAINT_IN_EP_INT15_Pos) /*!< IN_EP_INT15 Get Value */


#define USB_DAINT_IN_EP_INT14_Pos    (14U)                                                                       /*!< IN_EP_INT14 Postion   */ 
#define USB_DAINT_IN_EP_INT14_Msk    (0x1U << USB_DAINT_IN_EP_INT14_Pos)                                         /*!< IN_EP_INT14 Mask      */
#define USB_DAINT_IN_EP_INT14_Set(x) (((uint32_t) (x) << USB_DAINT_IN_EP_INT14_Pos) & USB_DAINT_IN_EP_INT14_Msk) /*!< IN_EP_INT14 Set Value */
#define USB_DAINT_IN_EP_INT14_Get(x) (((uint32_t) (x) & USB_DAINT_IN_EP_INT14_Msk) >> USB_DAINT_IN_EP_INT14_Pos) /*!< IN_EP_INT14 Get Value */


#define USB_DAINT_IN_EP_INT13_Pos    (13U)                                                                       /*!< IN_EP_INT13 Postion   */ 
#define USB_DAINT_IN_EP_INT13_Msk    (0x1U << USB_DAINT_IN_EP_INT13_Pos)                                         /*!< IN_EP_INT13 Mask      */
#define USB_DAINT_IN_EP_INT13_Set(x) (((uint32_t) (x) << USB_DAINT_IN_EP_INT13_Pos) & USB_DAINT_IN_EP_INT13_Msk) /*!< IN_EP_INT13 Set Value */
#define USB_DAINT_IN_EP_INT13_Get(x) (((uint32_t) (x) & USB_DAINT_IN_EP_INT13_Msk) >> USB_DAINT_IN_EP_INT13_Pos) /*!< IN_EP_INT13 Get Value */


#define USB_DAINT_IN_EP_INT12_Pos    (12U)                                                                       /*!< IN_EP_INT12 Postion   */ 
#define USB_DAINT_IN_EP_INT12_Msk    (0x1U << USB_DAINT_IN_EP_INT12_Pos)                                         /*!< IN_EP_INT12 Mask      */
#define USB_DAINT_IN_EP_INT12_Set(x) (((uint32_t) (x) << USB_DAINT_IN_EP_INT12_Pos) & USB_DAINT_IN_EP_INT12_Msk) /*!< IN_EP_INT12 Set Value */
#define USB_DAINT_IN_EP_INT12_Get(x) (((uint32_t) (x) & USB_DAINT_IN_EP_INT12_Msk) >> USB_DAINT_IN_EP_INT12_Pos) /*!< IN_EP_INT12 Get Value */


#define USB_DAINT_IN_EP_INT11_Pos    (11U)                                                                       /*!< IN_EP_INT11 Postion   */ 
#define USB_DAINT_IN_EP_INT11_Msk    (0x1U << USB_DAINT_IN_EP_INT11_Pos)                                         /*!< IN_EP_INT11 Mask      */
#define USB_DAINT_IN_EP_INT11_Set(x) (((uint32_t) (x) << USB_DAINT_IN_EP_INT11_Pos) & USB_DAINT_IN_EP_INT11_Msk) /*!< IN_EP_INT11 Set Value */
#define USB_DAINT_IN_EP_INT11_Get(x) (((uint32_t) (x) & USB_DAINT_IN_EP_INT11_Msk) >> USB_DAINT_IN_EP_INT11_Pos) /*!< IN_EP_INT11 Get Value */


#define USB_DAINT_IN_EP_INT10_Pos    (10U)                                                                       /*!< IN_EP_INT10 Postion   */ 
#define USB_DAINT_IN_EP_INT10_Msk    (0x1U << USB_DAINT_IN_EP_INT10_Pos)                                         /*!< IN_EP_INT10 Mask      */
#define USB_DAINT_IN_EP_INT10_Set(x) (((uint32_t) (x) << USB_DAINT_IN_EP_INT10_Pos) & USB_DAINT_IN_EP_INT10_Msk) /*!< IN_EP_INT10 Set Value */
#define USB_DAINT_IN_EP_INT10_Get(x) (((uint32_t) (x) & USB_DAINT_IN_EP_INT10_Msk) >> USB_DAINT_IN_EP_INT10_Pos) /*!< IN_EP_INT10 Get Value */


#define USB_DAINT_IN_EP_INT9_Pos    (9U)                                                                        /*!< IN_EP_INT9 Postion   */ 
#define USB_DAINT_IN_EP_INT9_Msk    (0x1U << USB_DAINT_IN_EP_INT9_Pos)                                          /*!< IN_EP_INT9 Mask      */
#define USB_DAINT_IN_EP_INT9_Set(x) (((uint32_t) (x) << USB_DAINT_IN_EP_INT9_Pos) & USB_DAINT_IN_EP_INT9_Msk)   /*!< IN_EP_INT9 Set Value */
#define USB_DAINT_IN_EP_INT9_Get(x) (((uint32_t) (x) & USB_DAINT_IN_EP_INT9_Msk) >> USB_DAINT_IN_EP_INT9_Pos)   /*!< IN_EP_INT9 Get Value */


#define USB_DAINT_IN_EP_INT8_Pos    (8U)                                                                        /*!< IN_EP_INT8 Postion   */ 
#define USB_DAINT_IN_EP_INT8_Msk    (0x1U << USB_DAINT_IN_EP_INT8_Pos)                                          /*!< IN_EP_INT8 Mask      */
#define USB_DAINT_IN_EP_INT8_Set(x) (((uint32_t) (x) << USB_DAINT_IN_EP_INT8_Pos) & USB_DAINT_IN_EP_INT8_Msk)   /*!< IN_EP_INT8 Set Value */
#define USB_DAINT_IN_EP_INT8_Get(x) (((uint32_t) (x) & USB_DAINT_IN_EP_INT8_Msk) >> USB_DAINT_IN_EP_INT8_Pos)   /*!< IN_EP_INT8 Get Value */


#define USB_DAINT_IN_EP_INT7_Pos    (7U)                                                                        /*!< IN_EP_INT7 Postion   */ 
#define USB_DAINT_IN_EP_INT7_Msk    (0x1U << USB_DAINT_IN_EP_INT7_Pos)                                          /*!< IN_EP_INT7 Mask      */
#define USB_DAINT_IN_EP_INT7_Set(x) (((uint32_t) (x) << USB_DAINT_IN_EP_INT7_Pos) & USB_DAINT_IN_EP_INT7_Msk)   /*!< IN_EP_INT7 Set Value */
#define USB_DAINT_IN_EP_INT7_Get(x) (((uint32_t) (x) & USB_DAINT_IN_EP_INT7_Msk) >> USB_DAINT_IN_EP_INT7_Pos)   /*!< IN_EP_INT7 Get Value */


#define USB_DAINT_IN_EP_INT6_Pos    (6U)                                                                        /*!< IN_EP_INT6 Postion   */ 
#define USB_DAINT_IN_EP_INT6_Msk    (0x1U << USB_DAINT_IN_EP_INT6_Pos)                                          /*!< IN_EP_INT6 Mask      */
#define USB_DAINT_IN_EP_INT6_Set(x) (((uint32_t) (x) << USB_DAINT_IN_EP_INT6_Pos) & USB_DAINT_IN_EP_INT6_Msk)   /*!< IN_EP_INT6 Set Value */
#define USB_DAINT_IN_EP_INT6_Get(x) (((uint32_t) (x) & USB_DAINT_IN_EP_INT6_Msk) >> USB_DAINT_IN_EP_INT6_Pos)   /*!< IN_EP_INT6 Get Value */


#define USB_DAINT_IN_EP_INT5_Pos    (5U)                                                                        /*!< IN_EP_INT5 Postion   */ 
#define USB_DAINT_IN_EP_INT5_Msk    (0x1U << USB_DAINT_IN_EP_INT5_Pos)                                          /*!< IN_EP_INT5 Mask      */
#define USB_DAINT_IN_EP_INT5_Set(x) (((uint32_t) (x) << USB_DAINT_IN_EP_INT5_Pos) & USB_DAINT_IN_EP_INT5_Msk)   /*!< IN_EP_INT5 Set Value */
#define USB_DAINT_IN_EP_INT5_Get(x) (((uint32_t) (x) & USB_DAINT_IN_EP_INT5_Msk) >> USB_DAINT_IN_EP_INT5_Pos)   /*!< IN_EP_INT5 Get Value */


#define USB_DAINT_IN_EP_INT4_Pos    (4U)                                                                        /*!< IN_EP_INT4 Postion   */ 
#define USB_DAINT_IN_EP_INT4_Msk    (0x1U << USB_DAINT_IN_EP_INT4_Pos)                                          /*!< IN_EP_INT4 Mask      */
#define USB_DAINT_IN_EP_INT4_Set(x) (((uint32_t) (x) << USB_DAINT_IN_EP_INT4_Pos) & USB_DAINT_IN_EP_INT4_Msk)   /*!< IN_EP_INT4 Set Value */
#define USB_DAINT_IN_EP_INT4_Get(x) (((uint32_t) (x) & USB_DAINT_IN_EP_INT4_Msk) >> USB_DAINT_IN_EP_INT4_Pos)   /*!< IN_EP_INT4 Get Value */


#define USB_DAINT_IN_EP_INT3_Pos    (3U)                                                                        /*!< IN_EP_INT3 Postion   */ 
#define USB_DAINT_IN_EP_INT3_Msk    (0x1U << USB_DAINT_IN_EP_INT3_Pos)                                          /*!< IN_EP_INT3 Mask      */
#define USB_DAINT_IN_EP_INT3_Set(x) (((uint32_t) (x) << USB_DAINT_IN_EP_INT3_Pos) & USB_DAINT_IN_EP_INT3_Msk)   /*!< IN_EP_INT3 Set Value */
#define USB_DAINT_IN_EP_INT3_Get(x) (((uint32_t) (x) & USB_DAINT_IN_EP_INT3_Msk) >> USB_DAINT_IN_EP_INT3_Pos)   /*!< IN_EP_INT3 Get Value */


#define USB_DAINT_IN_EP_INT2_Pos    (2U)                                                                        /*!< IN_EP_INT2 Postion   */ 
#define USB_DAINT_IN_EP_INT2_Msk    (0x1U << USB_DAINT_IN_EP_INT2_Pos)                                          /*!< IN_EP_INT2 Mask      */
#define USB_DAINT_IN_EP_INT2_Set(x) (((uint32_t) (x) << USB_DAINT_IN_EP_INT2_Pos) & USB_DAINT_IN_EP_INT2_Msk)   /*!< IN_EP_INT2 Set Value */
#define USB_DAINT_IN_EP_INT2_Get(x) (((uint32_t) (x) & USB_DAINT_IN_EP_INT2_Msk) >> USB_DAINT_IN_EP_INT2_Pos)   /*!< IN_EP_INT2 Get Value */


#define USB_DAINT_IN_EP_INT1_Pos    (1U)                                                                        /*!< IN_EP_INT1 Postion   */ 
#define USB_DAINT_IN_EP_INT1_Msk    (0x1U << USB_DAINT_IN_EP_INT1_Pos)                                          /*!< IN_EP_INT1 Mask      */
#define USB_DAINT_IN_EP_INT1_Set(x) (((uint32_t) (x) << USB_DAINT_IN_EP_INT1_Pos) & USB_DAINT_IN_EP_INT1_Msk)   /*!< IN_EP_INT1 Set Value */
#define USB_DAINT_IN_EP_INT1_Get(x) (((uint32_t) (x) & USB_DAINT_IN_EP_INT1_Msk) >> USB_DAINT_IN_EP_INT1_Pos)   /*!< IN_EP_INT1 Get Value */


#define USB_DAINT_IN_EP_INT0_Pos    (0U)                                                                        /*!< IN_EP_INT0 Postion   */ 
#define USB_DAINT_IN_EP_INT0_Msk    (0x1U << USB_DAINT_IN_EP_INT0_Pos)                                          /*!< IN_EP_INT0 Mask      */
#define USB_DAINT_IN_EP_INT0_Set(x) (((uint32_t) (x) << USB_DAINT_IN_EP_INT0_Pos) & USB_DAINT_IN_EP_INT0_Msk)   /*!< IN_EP_INT0 Set Value */
#define USB_DAINT_IN_EP_INT0_Get(x) (((uint32_t) (x) & USB_DAINT_IN_EP_INT0_Msk) >> USB_DAINT_IN_EP_INT0_Pos)   /*!< IN_EP_INT0 Get Value */


/* DAINTMSK bitfield */
#define USB_DAINTMSK_IEPM_Pos       (0U)
#define USB_DAINTMSK_IEPM_Msk       (0xFFFFUL << USB_DAINTMSK_IEPM_Pos) /*!< 0x0000FFFF */
#define USB_DAINTMSK_IEPM           USB_DAINTMSK_IEPM_Msk     /*!< IN EP interrupt mask bits */
#define USB_DAINTMSK_IEPM_Set(x)    (((uint32_t) (x) << USB_DAINTMSK_IEPM_Pos) & USB_DAINTMSK_IEPM_Msk) /*!< IN EP interrupt Set Value */
#define USB_DAINTMSK_IEPM_Get(x)    (((uint32_t) (x) & USB_DAINTMSK_IEPM_Msk) >> USB_DAINTMSK_IEPM_Pos) /*!< IN EP interrupt Get Value */

#define USB_DAINTMSK_OEPM_Pos        (16U)
#define USB_DAINTMSK_OEPM_Msk        (0xFFFFUL << USB_DAINTMSK_OEPM_Pos) /*!< 0xFFFF0000 */
#define USB_DAINTMSK_OEPM            USB_DAINTMSK_OEPM_Msk     /*!< OUT EP interrupt mask bits */
#define USB_DAINTMSK_OEPM_Set(x)    (((uint32_t) (x) << USB_DAINTMSK_OEPM_Pos) & USB_DAINTMSK_OEPM_Msk) /*!< OUTN EP interrupt Set Value */
#define USB_DAINTMSK_OEPM_Get(x)    (((uint32_t) (x) & USB_DAINTMSK_OEPM_Msk) >> USB_DAINTMSK_OEPM_Pos) /*!< OUTN EP interrupt Get Value */


/* DVBUSDIS bitfield */
#define USB_DVBUSDIS_DVBUSDIS_Pos    (0U)                                                                        /*!< DVBUSDIS Postion   */ 
#define USB_DVBUSDIS_DVBUSDIS_Msk    (0xffffU << USB_DVBUSDIS_DVBUSDIS_Pos)                                      /*!< DVBUSDIS Mask      */
#define USB_DVBUSDIS_DVBUSDIS_Set(x) (((uint32_t) (x) << USB_DVBUSDIS_DVBUSDIS_Pos) & USB_DVBUSDIS_DVBUSDIS_Msk) /*!< DVBUSDIS Set Value */
#define USB_DVBUSDIS_DVBUSDIS_Get(x) (((uint32_t) (x) & USB_DVBUSDIS_DVBUSDIS_Msk) >> USB_DVBUSDIS_DVBUSDIS_Pos) /*!< DVBUSDIS Get Value */


/* DVBUSPULSE bitfield */
#define USB_DVBUSPULSE_DVBUSPULSE_Pos    (0U)                                                                        /*!< DVBUSPULSE Postion   */ 
#define USB_DVBUSPULSE_DVBUSPULSE_Msk    (0xfffU << USB_DVBUSPULSE_DVBUSPULSE_Pos)                                   /*!< DVBUSPULSE Mask      */
#define USB_DVBUSPULSE_DVBUSPULSE_Set(x) (((uint32_t) (x) << USB_DVBUSPULSE_DVBUSPULSE_Pos) & USB_DVBUSPULSE_DVBUSPULSE_Msk) /*!< DVBUSPULSE Set Value */
#define USB_DVBUSPULSE_DVBUSPULSE_Get(x) (((uint32_t) (x) & USB_DVBUSPULSE_DVBUSPULSE_Msk) >> USB_DVBUSPULSE_DVBUSPULSE_Pos) /*!< DVBUSPULSE Get Value */


/* DTHRCTL bitfield */
#define USB_DTHRCTL_RX_THR_LEN_Pos    (17U)                                                                       /*!< RX_THR_LEN Postion   */ 
#define USB_DTHRCTL_RX_THR_LEN_Msk    (0x1ffU << USB_DTHRCTL_RX_THR_LEN_Pos)                                      /*!< RX_THR_LEN Mask      */
#define USB_DTHRCTL_RX_THR_LEN_Set(x) (((uint32_t) (x) << USB_DTHRCTL_RX_THR_LEN_Pos) & USB_DTHRCTL_RX_THR_LEN_Msk) /*!< RX_THR_LEN Set Value */
#define USB_DTHRCTL_RX_THR_LEN_Get(x) (((uint32_t) (x) & USB_DTHRCTL_RX_THR_LEN_Msk) >> USB_DTHRCTL_RX_THR_LEN_Pos) /*!< RX_THR_LEN Get Value */


#define USB_DTHRCTL_RX_THR_EN_Pos    (16U)                                                                       /*!< RX_THR_EN Postion   */ 
#define USB_DTHRCTL_RX_THR_EN_Msk    (0x1U << USB_DTHRCTL_RX_THR_EN_Pos)                                         /*!< RX_THR_EN Mask      */
#define USB_DTHRCTL_RX_THR_EN_Set(x) (((uint32_t) (x) << USB_DTHRCTL_RX_THR_EN_Pos) & USB_DTHRCTL_RX_THR_EN_Msk) /*!< RX_THR_EN Set Value */
#define USB_DTHRCTL_RX_THR_EN_Get(x) (((uint32_t) (x) & USB_DTHRCTL_RX_THR_EN_Msk) >> USB_DTHRCTL_RX_THR_EN_Pos) /*!< RX_THR_EN Get Value */


#define USB_DTHRCTL_AHB_THR_RATIO_Pos    (11U)                                                                       /*!< AHB_THR_RATIO Postion   */ 
#define USB_DTHRCTL_AHB_THR_RATIO_Msk    (0x3U << USB_DTHRCTL_AHB_THR_RATIO_Pos)                                     /*!< AHB_THR_RATIO Mask      */
#define USB_DTHRCTL_AHB_THR_RATIO_Set(x) (((uint32_t) (x) << USB_DTHRCTL_AHB_THR_RATIO_Pos) & USB_DTHRCTL_AHB_THR_RATIO_Msk) /*!< AHB_THR_RATIO Set Value */
#define USB_DTHRCTL_AHB_THR_RATIO_Get(x) (((uint32_t) (x) & USB_DTHRCTL_AHB_THR_RATIO_Msk) >> USB_DTHRCTL_AHB_THR_RATIO_Pos) /*!< AHB_THR_RATIO Get Value */


#define USB_DTHRCTL_TX_THR_LEN_Pos    (2U)                                                                        /*!< TX_THR_LEN Postion   */ 
#define USB_DTHRCTL_TX_THR_LEN_Msk    (0x1ffU << USB_DTHRCTL_TX_THR_LEN_Pos)                                      /*!< TX_THR_LEN Mask      */
#define USB_DTHRCTL_TX_THR_LEN_Set(x) (((uint32_t) (x) << USB_DTHRCTL_TX_THR_LEN_Pos) & USB_DTHRCTL_TX_THR_LEN_Msk) /*!< TX_THR_LEN Set Value */
#define USB_DTHRCTL_TX_THR_LEN_Get(x) (((uint32_t) (x) & USB_DTHRCTL_TX_THR_LEN_Msk) >> USB_DTHRCTL_TX_THR_LEN_Pos) /*!< TX_THR_LEN Get Value */


#define USB_DTHRCTL_ISO_THR_EN_Pos    (1U)                                                                        /*!< ISO_THR_EN Postion   */ 
#define USB_DTHRCTL_ISO_THR_EN_Msk    (0x1U << USB_DTHRCTL_ISO_THR_EN_Pos)                                        /*!< ISO_THR_EN Mask      */
#define USB_DTHRCTL_ISO_THR_EN_Set(x) (((uint32_t) (x) << USB_DTHRCTL_ISO_THR_EN_Pos) & USB_DTHRCTL_ISO_THR_EN_Msk) /*!< ISO_THR_EN Set Value */
#define USB_DTHRCTL_ISO_THR_EN_Get(x) (((uint32_t) (x) & USB_DTHRCTL_ISO_THR_EN_Msk) >> USB_DTHRCTL_ISO_THR_EN_Pos) /*!< ISO_THR_EN Get Value */


#define USB_DTHRCTL_NON_ISO_THR_EN_Pos    (0U)                                                                        /*!< NON_ISO_THR_EN Postion   */ 
#define USB_DTHRCTL_NON_ISO_THR_EN_Msk    (0x1U << USB_DTHRCTL_NON_ISO_THR_EN_Pos)                                    /*!< NON_ISO_THR_EN Mask      */
#define USB_DTHRCTL_NON_ISO_THR_EN_Set(x) (((uint32_t) (x) << USB_DTHRCTL_NON_ISO_THR_EN_Pos) & USB_DTHRCTL_NON_ISO_THR_EN_Msk) /*!< NON_ISO_THR_EN Set Value */
#define USB_DTHRCTL_NON_ISO_THR_EN_Get(x) (((uint32_t) (x) & USB_DTHRCTL_NON_ISO_THR_EN_Msk) >> USB_DTHRCTL_NON_ISO_THR_EN_Pos) /*!< NON_ISO_THR_EN Get Value */


/* DIEPEMPMSK bitfield */
#define USB_DIEPEMPMSK_IN_EP_TXF_EMP_MSK_Pos    (0U)                                                                        /*!< IN_EP_TXF_EMP_MSK Postion   */ 
#define USB_DIEPEMPMSK_IN_EP_TXF_EMP_MSK_Msk    (0xffffU << USB_DIEPEMPMSK_IN_EP_TXF_EMP_MSK_Pos)                           /*!< IN_EP_TXF_EMP_MSK Mask      */
#define USB_DIEPEMPMSK_IN_EP_TXF_EMP_MSK_Set(x) (((uint32_t) (x) << USB_DIEPEMPMSK_IN_EP_TXF_EMP_MSK_Pos) & USB_DIEPEMPMSK_IN_EP_TXF_EMP_MSK_Msk) /*!< IN_EP_TXF_EMP_MSK Set Value */
#define USB_DIEPEMPMSK_IN_EP_TXF_EMP_MSK_Get(x) (((uint32_t) (x) & USB_DIEPEMPMSK_IN_EP_TXF_EMP_MSK_Msk) >> USB_DIEPEMPMSK_IN_EP_TXF_EMP_MSK_Pos) /*!< IN_EP_TXF_EMP_MSK Get Value */


/* DEACHINT bitfield */
#define USB_DEACHINT_ECH_OUT_EP_INT_Pos    (16U)                                                                       /*!< ECH_OUT_EP_INT Postion   */ 
#define USB_DEACHINT_ECH_OUT_EP_INT_Msk    (0xffffU << USB_DEACHINT_ECH_OUT_EP_INT_Pos)                                /*!< ECH_OUT_EP_INT Mask      */
#define USB_DEACHINT_ECH_OUT_EP_INT_Set(x) (((uint32_t) (x) << USB_DEACHINT_ECH_OUT_EP_INT_Pos) & USB_DEACHINT_ECH_OUT_EP_INT_Msk) /*!< ECH_OUT_EP_INT Set Value */
#define USB_DEACHINT_ECH_OUT_EP_INT_Get(x) (((uint32_t) (x) & USB_DEACHINT_ECH_OUT_EP_INT_Msk) >> USB_DEACHINT_ECH_OUT_EP_INT_Pos) /*!< ECH_OUT_EP_INT Get Value */


#define USB_DEACHINT_ECH_IN_EP_INT_Pos    (0U)                                                                        /*!< ECH_IN_EP_INT Postion   */ 
#define USB_DEACHINT_ECH_IN_EP_INT_Msk    (0xffffU << USB_DEACHINT_ECH_IN_EP_INT_Pos)                                 /*!< ECH_IN_EP_INT Mask      */
#define USB_DEACHINT_ECH_IN_EP_INT_Set(x) (((uint32_t) (x) << USB_DEACHINT_ECH_IN_EP_INT_Pos) & USB_DEACHINT_ECH_IN_EP_INT_Msk) /*!< ECH_IN_EP_INT Set Value */
#define USB_DEACHINT_ECH_IN_EP_INT_Get(x) (((uint32_t) (x) & USB_DEACHINT_ECH_IN_EP_INT_Msk) >> USB_DEACHINT_ECH_IN_EP_INT_Pos) /*!< ECH_IN_EP_INT Get Value */


/* DEACHINTMSK bitfield */
#define USB_DEACHINTMSK_ECH_OUT_EP_MSK15_Pos    (31U)                                                                       /*!< ECH_OUT_EP_MSK15 Postion   */ 
#define USB_DEACHINTMSK_ECH_OUT_EP_MSK15_Msk    (0x1U << USB_DEACHINTMSK_ECH_OUT_EP_MSK15_Pos)                              /*!< ECH_OUT_EP_MSK15 Mask      */
#define USB_DEACHINTMSK_ECH_OUT_EP_MSK15_Set(x) (((uint32_t) (x) << USB_DEACHINTMSK_ECH_OUT_EP_MSK15_Pos) & USB_DEACHINTMSK_ECH_OUT_EP_MSK15_Msk) /*!< ECH_OUT_EP_MSK15 Set Value */
#define USB_DEACHINTMSK_ECH_OUT_EP_MSK15_Get(x) (((uint32_t) (x) & USB_DEACHINTMSK_ECH_OUT_EP_MSK15_Msk) >> USB_DEACHINTMSK_ECH_OUT_EP_MSK15_Pos) /*!< ECH_OUT_EP_MSK15 Get Value */


#define USB_DEACHINTMSK_ECH_OUT_EP_MSK14_Pos    (30U)                                                                       /*!< ECH_OUT_EP_MSK14 Postion   */ 
#define USB_DEACHINTMSK_ECH_OUT_EP_MSK14_Msk    (0x1U << USB_DEACHINTMSK_ECH_OUT_EP_MSK14_Pos)                              /*!< ECH_OUT_EP_MSK14 Mask      */
#define USB_DEACHINTMSK_ECH_OUT_EP_MSK14_Set(x) (((uint32_t) (x) << USB_DEACHINTMSK_ECH_OUT_EP_MSK14_Pos) & USB_DEACHINTMSK_ECH_OUT_EP_MSK14_Msk) /*!< ECH_OUT_EP_MSK14 Set Value */
#define USB_DEACHINTMSK_ECH_OUT_EP_MSK14_Get(x) (((uint32_t) (x) & USB_DEACHINTMSK_ECH_OUT_EP_MSK14_Msk) >> USB_DEACHINTMSK_ECH_OUT_EP_MSK14_Pos) /*!< ECH_OUT_EP_MSK14 Get Value */


#define USB_DEACHINTMSK_ECH_OUT_EP_MSK13_Pos    (29U)                                                                       /*!< ECH_OUT_EP_MSK13 Postion   */ 
#define USB_DEACHINTMSK_ECH_OUT_EP_MSK13_Msk    (0x1U << USB_DEACHINTMSK_ECH_OUT_EP_MSK13_Pos)                              /*!< ECH_OUT_EP_MSK13 Mask      */
#define USB_DEACHINTMSK_ECH_OUT_EP_MSK13_Set(x) (((uint32_t) (x) << USB_DEACHINTMSK_ECH_OUT_EP_MSK13_Pos) & USB_DEACHINTMSK_ECH_OUT_EP_MSK13_Msk) /*!< ECH_OUT_EP_MSK13 Set Value */
#define USB_DEACHINTMSK_ECH_OUT_EP_MSK13_Get(x) (((uint32_t) (x) & USB_DEACHINTMSK_ECH_OUT_EP_MSK13_Msk) >> USB_DEACHINTMSK_ECH_OUT_EP_MSK13_Pos) /*!< ECH_OUT_EP_MSK13 Get Value */


#define USB_DEACHINTMSK_ECH_OUT_EP_MSK12_Pos    (28U)                                                                       /*!< ECH_OUT_EP_MSK12 Postion   */ 
#define USB_DEACHINTMSK_ECH_OUT_EP_MSK12_Msk    (0x1U << USB_DEACHINTMSK_ECH_OUT_EP_MSK12_Pos)                              /*!< ECH_OUT_EP_MSK12 Mask      */
#define USB_DEACHINTMSK_ECH_OUT_EP_MSK12_Set(x) (((uint32_t) (x) << USB_DEACHINTMSK_ECH_OUT_EP_MSK12_Pos) & USB_DEACHINTMSK_ECH_OUT_EP_MSK12_Msk) /*!< ECH_OUT_EP_MSK12 Set Value */
#define USB_DEACHINTMSK_ECH_OUT_EP_MSK12_Get(x) (((uint32_t) (x) & USB_DEACHINTMSK_ECH_OUT_EP_MSK12_Msk) >> USB_DEACHINTMSK_ECH_OUT_EP_MSK12_Pos) /*!< ECH_OUT_EP_MSK12 Get Value */


#define USB_DEACHINTMSK_ECH_OUT_EP_MSK11_Pos    (27U)                                                                       /*!< ECH_OUT_EP_MSK11 Postion   */ 
#define USB_DEACHINTMSK_ECH_OUT_EP_MSK11_Msk    (0x1U << USB_DEACHINTMSK_ECH_OUT_EP_MSK11_Pos)                              /*!< ECH_OUT_EP_MSK11 Mask      */
#define USB_DEACHINTMSK_ECH_OUT_EP_MSK11_Set(x) (((uint32_t) (x) << USB_DEACHINTMSK_ECH_OUT_EP_MSK11_Pos) & USB_DEACHINTMSK_ECH_OUT_EP_MSK11_Msk) /*!< ECH_OUT_EP_MSK11 Set Value */
#define USB_DEACHINTMSK_ECH_OUT_EP_MSK11_Get(x) (((uint32_t) (x) & USB_DEACHINTMSK_ECH_OUT_EP_MSK11_Msk) >> USB_DEACHINTMSK_ECH_OUT_EP_MSK11_Pos) /*!< ECH_OUT_EP_MSK11 Get Value */


#define USB_DEACHINTMSK_ECH_OUT_EP_MSK10_Pos    (26U)                                                                       /*!< ECH_OUT_EP_MSK10 Postion   */ 
#define USB_DEACHINTMSK_ECH_OUT_EP_MSK10_Msk    (0x1U << USB_DEACHINTMSK_ECH_OUT_EP_MSK10_Pos)                              /*!< ECH_OUT_EP_MSK10 Mask      */
#define USB_DEACHINTMSK_ECH_OUT_EP_MSK10_Set(x) (((uint32_t) (x) << USB_DEACHINTMSK_ECH_OUT_EP_MSK10_Pos) & USB_DEACHINTMSK_ECH_OUT_EP_MSK10_Msk) /*!< ECH_OUT_EP_MSK10 Set Value */
#define USB_DEACHINTMSK_ECH_OUT_EP_MSK10_Get(x) (((uint32_t) (x) & USB_DEACHINTMSK_ECH_OUT_EP_MSK10_Msk) >> USB_DEACHINTMSK_ECH_OUT_EP_MSK10_Pos) /*!< ECH_OUT_EP_MSK10 Get Value */


#define USB_DEACHINTMSK_ECH_OUT_EP_MSK9_Pos    (25U)                                                                       /*!< ECH_OUT_EP_MSK9 Postion   */ 
#define USB_DEACHINTMSK_ECH_OUT_EP_MSK9_Msk    (0x1U << USB_DEACHINTMSK_ECH_OUT_EP_MSK9_Pos)                               /*!< ECH_OUT_EP_MSK9 Mask      */
#define USB_DEACHINTMSK_ECH_OUT_EP_MSK9_Set(x) (((uint32_t) (x) << USB_DEACHINTMSK_ECH_OUT_EP_MSK9_Pos) & USB_DEACHINTMSK_ECH_OUT_EP_MSK9_Msk) /*!< ECH_OUT_EP_MSK9 Set Value */
#define USB_DEACHINTMSK_ECH_OUT_EP_MSK9_Get(x) (((uint32_t) (x) & USB_DEACHINTMSK_ECH_OUT_EP_MSK9_Msk) >> USB_DEACHINTMSK_ECH_OUT_EP_MSK9_Pos) /*!< ECH_OUT_EP_MSK9 Get Value */


#define USB_DEACHINTMSK_ECH_OUT_EP_MSK8_Pos    (24U)                                                                       /*!< ECH_OUT_EP_MSK8 Postion   */ 
#define USB_DEACHINTMSK_ECH_OUT_EP_MSK8_Msk    (0x1U << USB_DEACHINTMSK_ECH_OUT_EP_MSK8_Pos)                               /*!< ECH_OUT_EP_MSK8 Mask      */
#define USB_DEACHINTMSK_ECH_OUT_EP_MSK8_Set(x) (((uint32_t) (x) << USB_DEACHINTMSK_ECH_OUT_EP_MSK8_Pos) & USB_DEACHINTMSK_ECH_OUT_EP_MSK8_Msk) /*!< ECH_OUT_EP_MSK8 Set Value */
#define USB_DEACHINTMSK_ECH_OUT_EP_MSK8_Get(x) (((uint32_t) (x) & USB_DEACHINTMSK_ECH_OUT_EP_MSK8_Msk) >> USB_DEACHINTMSK_ECH_OUT_EP_MSK8_Pos) /*!< ECH_OUT_EP_MSK8 Get Value */


#define USB_DEACHINTMSK_ECH_OUT_EP_MSK7_Pos    (23U)                                                                       /*!< ECH_OUT_EP_MSK7 Postion   */ 
#define USB_DEACHINTMSK_ECH_OUT_EP_MSK7_Msk    (0x1U << USB_DEACHINTMSK_ECH_OUT_EP_MSK7_Pos)                               /*!< ECH_OUT_EP_MSK7 Mask      */
#define USB_DEACHINTMSK_ECH_OUT_EP_MSK7_Set(x) (((uint32_t) (x) << USB_DEACHINTMSK_ECH_OUT_EP_MSK7_Pos) & USB_DEACHINTMSK_ECH_OUT_EP_MSK7_Msk) /*!< ECH_OUT_EP_MSK7 Set Value */
#define USB_DEACHINTMSK_ECH_OUT_EP_MSK7_Get(x) (((uint32_t) (x) & USB_DEACHINTMSK_ECH_OUT_EP_MSK7_Msk) >> USB_DEACHINTMSK_ECH_OUT_EP_MSK7_Pos) /*!< ECH_OUT_EP_MSK7 Get Value */


#define USB_DEACHINTMSK_ECH_OUT_EP_MSK6_Pos    (22U)                                                                       /*!< ECH_OUT_EP_MSK6 Postion   */ 
#define USB_DEACHINTMSK_ECH_OUT_EP_MSK6_Msk    (0x1U << USB_DEACHINTMSK_ECH_OUT_EP_MSK6_Pos)                               /*!< ECH_OUT_EP_MSK6 Mask      */
#define USB_DEACHINTMSK_ECH_OUT_EP_MSK6_Set(x) (((uint32_t) (x) << USB_DEACHINTMSK_ECH_OUT_EP_MSK6_Pos) & USB_DEACHINTMSK_ECH_OUT_EP_MSK6_Msk) /*!< ECH_OUT_EP_MSK6 Set Value */
#define USB_DEACHINTMSK_ECH_OUT_EP_MSK6_Get(x) (((uint32_t) (x) & USB_DEACHINTMSK_ECH_OUT_EP_MSK6_Msk) >> USB_DEACHINTMSK_ECH_OUT_EP_MSK6_Pos) /*!< ECH_OUT_EP_MSK6 Get Value */


#define USB_DEACHINTMSK_ECH_OUT_EP_MSK5_Pos    (21U)                                                                       /*!< ECH_OUT_EP_MSK5 Postion   */ 
#define USB_DEACHINTMSK_ECH_OUT_EP_MSK5_Msk    (0x1U << USB_DEACHINTMSK_ECH_OUT_EP_MSK5_Pos)                               /*!< ECH_OUT_EP_MSK5 Mask      */
#define USB_DEACHINTMSK_ECH_OUT_EP_MSK5_Set(x) (((uint32_t) (x) << USB_DEACHINTMSK_ECH_OUT_EP_MSK5_Pos) & USB_DEACHINTMSK_ECH_OUT_EP_MSK5_Msk) /*!< ECH_OUT_EP_MSK5 Set Value */
#define USB_DEACHINTMSK_ECH_OUT_EP_MSK5_Get(x) (((uint32_t) (x) & USB_DEACHINTMSK_ECH_OUT_EP_MSK5_Msk) >> USB_DEACHINTMSK_ECH_OUT_EP_MSK5_Pos) /*!< ECH_OUT_EP_MSK5 Get Value */


#define USB_DEACHINTMSK_ECH_OUT_EP_MSK4_Pos    (20U)                                                                       /*!< ECH_OUT_EP_MSK4 Postion   */ 
#define USB_DEACHINTMSK_ECH_OUT_EP_MSK4_Msk    (0x1U << USB_DEACHINTMSK_ECH_OUT_EP_MSK4_Pos)                               /*!< ECH_OUT_EP_MSK4 Mask      */
#define USB_DEACHINTMSK_ECH_OUT_EP_MSK4_Set(x) (((uint32_t) (x) << USB_DEACHINTMSK_ECH_OUT_EP_MSK4_Pos) & USB_DEACHINTMSK_ECH_OUT_EP_MSK4_Msk) /*!< ECH_OUT_EP_MSK4 Set Value */
#define USB_DEACHINTMSK_ECH_OUT_EP_MSK4_Get(x) (((uint32_t) (x) & USB_DEACHINTMSK_ECH_OUT_EP_MSK4_Msk) >> USB_DEACHINTMSK_ECH_OUT_EP_MSK4_Pos) /*!< ECH_OUT_EP_MSK4 Get Value */


#define USB_DEACHINTMSK_ECH_OUT_EP_MSK3_Pos    (19U)                                                                       /*!< ECH_OUT_EP_MSK3 Postion   */ 
#define USB_DEACHINTMSK_ECH_OUT_EP_MSK3_Msk    (0x1U << USB_DEACHINTMSK_ECH_OUT_EP_MSK3_Pos)                               /*!< ECH_OUT_EP_MSK3 Mask      */
#define USB_DEACHINTMSK_ECH_OUT_EP_MSK3_Set(x) (((uint32_t) (x) << USB_DEACHINTMSK_ECH_OUT_EP_MSK3_Pos) & USB_DEACHINTMSK_ECH_OUT_EP_MSK3_Msk) /*!< ECH_OUT_EP_MSK3 Set Value */
#define USB_DEACHINTMSK_ECH_OUT_EP_MSK3_Get(x) (((uint32_t) (x) & USB_DEACHINTMSK_ECH_OUT_EP_MSK3_Msk) >> USB_DEACHINTMSK_ECH_OUT_EP_MSK3_Pos) /*!< ECH_OUT_EP_MSK3 Get Value */


#define USB_DEACHINTMSK_ECH_OUT_EP_MSK2_Pos    (18U)                                                                       /*!< ECH_OUT_EP_MSK2 Postion   */ 
#define USB_DEACHINTMSK_ECH_OUT_EP_MSK2_Msk    (0x1U << USB_DEACHINTMSK_ECH_OUT_EP_MSK2_Pos)                               /*!< ECH_OUT_EP_MSK2 Mask      */
#define USB_DEACHINTMSK_ECH_OUT_EP_MSK2_Set(x) (((uint32_t) (x) << USB_DEACHINTMSK_ECH_OUT_EP_MSK2_Pos) & USB_DEACHINTMSK_ECH_OUT_EP_MSK2_Msk) /*!< ECH_OUT_EP_MSK2 Set Value */
#define USB_DEACHINTMSK_ECH_OUT_EP_MSK2_Get(x) (((uint32_t) (x) & USB_DEACHINTMSK_ECH_OUT_EP_MSK2_Msk) >> USB_DEACHINTMSK_ECH_OUT_EP_MSK2_Pos) /*!< ECH_OUT_EP_MSK2 Get Value */


#define USB_DEACHINTMSK_ECH_OUT_EP_MSK1_Pos    (17U)                                                                       /*!< ECH_OUT_EP_MSK1 Postion   */ 
#define USB_DEACHINTMSK_ECH_OUT_EP_MSK1_Msk    (0x1U << USB_DEACHINTMSK_ECH_OUT_EP_MSK1_Pos)                               /*!< ECH_OUT_EP_MSK1 Mask      */
#define USB_DEACHINTMSK_ECH_OUT_EP_MSK1_Set(x) (((uint32_t) (x) << USB_DEACHINTMSK_ECH_OUT_EP_MSK1_Pos) & USB_DEACHINTMSK_ECH_OUT_EP_MSK1_Msk) /*!< ECH_OUT_EP_MSK1 Set Value */
#define USB_DEACHINTMSK_ECH_OUT_EP_MSK1_Get(x) (((uint32_t) (x) & USB_DEACHINTMSK_ECH_OUT_EP_MSK1_Msk) >> USB_DEACHINTMSK_ECH_OUT_EP_MSK1_Pos) /*!< ECH_OUT_EP_MSK1 Get Value */


#define USB_DEACHINTMSK_ECH_OUT_EP_MSK0_Pos    (16U)                                                                       /*!< ECH_OUT_EP_MSK0 Postion   */ 
#define USB_DEACHINTMSK_ECH_OUT_EP_MSK0_Msk    (0x1U << USB_DEACHINTMSK_ECH_OUT_EP_MSK0_Pos)                               /*!< ECH_OUT_EP_MSK0 Mask      */
#define USB_DEACHINTMSK_ECH_OUT_EP_MSK0_Set(x) (((uint32_t) (x) << USB_DEACHINTMSK_ECH_OUT_EP_MSK0_Pos) & USB_DEACHINTMSK_ECH_OUT_EP_MSK0_Msk) /*!< ECH_OUT_EP_MSK0 Set Value */
#define USB_DEACHINTMSK_ECH_OUT_EP_MSK0_Get(x) (((uint32_t) (x) & USB_DEACHINTMSK_ECH_OUT_EP_MSK0_Msk) >> USB_DEACHINTMSK_ECH_OUT_EP_MSK0_Pos) /*!< ECH_OUT_EP_MSK0 Get Value */


#define USB_DEACHINTMSK_ECH_IN_EP_MSK15_Pos    (15U)                                                                       /*!< ECH_IN_EP_MSK15 Postion   */ 
#define USB_DEACHINTMSK_ECH_IN_EP_MSK15_Msk    (0x1U << USB_DEACHINTMSK_ECH_IN_EP_MSK15_Pos)                               /*!< ECH_IN_EP_MSK15 Mask      */
#define USB_DEACHINTMSK_ECH_IN_EP_MSK15_Set(x) (((uint32_t) (x) << USB_DEACHINTMSK_ECH_IN_EP_MSK15_Pos) & USB_DEACHINTMSK_ECH_IN_EP_MSK15_Msk) /*!< ECH_IN_EP_MSK15 Set Value */
#define USB_DEACHINTMSK_ECH_IN_EP_MSK15_Get(x) (((uint32_t) (x) & USB_DEACHINTMSK_ECH_IN_EP_MSK15_Msk) >> USB_DEACHINTMSK_ECH_IN_EP_MSK15_Pos) /*!< ECH_IN_EP_MSK15 Get Value */


#define USB_DEACHINTMSK_ECH_IN_EP_MSK14_Pos    (14U)                                                                       /*!< ECH_IN_EP_MSK14 Postion   */ 
#define USB_DEACHINTMSK_ECH_IN_EP_MSK14_Msk    (0x1U << USB_DEACHINTMSK_ECH_IN_EP_MSK14_Pos)                               /*!< ECH_IN_EP_MSK14 Mask      */
#define USB_DEACHINTMSK_ECH_IN_EP_MSK14_Set(x) (((uint32_t) (x) << USB_DEACHINTMSK_ECH_IN_EP_MSK14_Pos) & USB_DEACHINTMSK_ECH_IN_EP_MSK14_Msk) /*!< ECH_IN_EP_MSK14 Set Value */
#define USB_DEACHINTMSK_ECH_IN_EP_MSK14_Get(x) (((uint32_t) (x) & USB_DEACHINTMSK_ECH_IN_EP_MSK14_Msk) >> USB_DEACHINTMSK_ECH_IN_EP_MSK14_Pos) /*!< ECH_IN_EP_MSK14 Get Value */


#define USB_DEACHINTMSK_ECH_IN_EP_MSK13_Pos    (13U)                                                                       /*!< ECH_IN_EP_MSK13 Postion   */ 
#define USB_DEACHINTMSK_ECH_IN_EP_MSK13_Msk    (0x1U << USB_DEACHINTMSK_ECH_IN_EP_MSK13_Pos)                               /*!< ECH_IN_EP_MSK13 Mask      */
#define USB_DEACHINTMSK_ECH_IN_EP_MSK13_Set(x) (((uint32_t) (x) << USB_DEACHINTMSK_ECH_IN_EP_MSK13_Pos) & USB_DEACHINTMSK_ECH_IN_EP_MSK13_Msk) /*!< ECH_IN_EP_MSK13 Set Value */
#define USB_DEACHINTMSK_ECH_IN_EP_MSK13_Get(x) (((uint32_t) (x) & USB_DEACHINTMSK_ECH_IN_EP_MSK13_Msk) >> USB_DEACHINTMSK_ECH_IN_EP_MSK13_Pos) /*!< ECH_IN_EP_MSK13 Get Value */


#define USB_DEACHINTMSK_ECH_IN_EP_MSK12_Pos    (12U)                                                                       /*!< ECH_IN_EP_MSK12 Postion   */ 
#define USB_DEACHINTMSK_ECH_IN_EP_MSK12_Msk    (0x1U << USB_DEACHINTMSK_ECH_IN_EP_MSK12_Pos)                               /*!< ECH_IN_EP_MSK12 Mask      */
#define USB_DEACHINTMSK_ECH_IN_EP_MSK12_Set(x) (((uint32_t) (x) << USB_DEACHINTMSK_ECH_IN_EP_MSK12_Pos) & USB_DEACHINTMSK_ECH_IN_EP_MSK12_Msk) /*!< ECH_IN_EP_MSK12 Set Value */
#define USB_DEACHINTMSK_ECH_IN_EP_MSK12_Get(x) (((uint32_t) (x) & USB_DEACHINTMSK_ECH_IN_EP_MSK12_Msk) >> USB_DEACHINTMSK_ECH_IN_EP_MSK12_Pos) /*!< ECH_IN_EP_MSK12 Get Value */


#define USB_DEACHINTMSK_ECH_IN_EP_MSK11_Pos    (11U)                                                                       /*!< ECH_IN_EP_MSK11 Postion   */ 
#define USB_DEACHINTMSK_ECH_IN_EP_MSK11_Msk    (0x1U << USB_DEACHINTMSK_ECH_IN_EP_MSK11_Pos)                               /*!< ECH_IN_EP_MSK11 Mask      */
#define USB_DEACHINTMSK_ECH_IN_EP_MSK11_Set(x) (((uint32_t) (x) << USB_DEACHINTMSK_ECH_IN_EP_MSK11_Pos) & USB_DEACHINTMSK_ECH_IN_EP_MSK11_Msk) /*!< ECH_IN_EP_MSK11 Set Value */
#define USB_DEACHINTMSK_ECH_IN_EP_MSK11_Get(x) (((uint32_t) (x) & USB_DEACHINTMSK_ECH_IN_EP_MSK11_Msk) >> USB_DEACHINTMSK_ECH_IN_EP_MSK11_Pos) /*!< ECH_IN_EP_MSK11 Get Value */


#define USB_DEACHINTMSK_ECH_IN_EP_MSK10_Pos    (10U)                                                                       /*!< ECH_IN_EP_MSK10 Postion   */ 
#define USB_DEACHINTMSK_ECH_IN_EP_MSK10_Msk    (0x1U << USB_DEACHINTMSK_ECH_IN_EP_MSK10_Pos)                               /*!< ECH_IN_EP_MSK10 Mask      */
#define USB_DEACHINTMSK_ECH_IN_EP_MSK10_Set(x) (((uint32_t) (x) << USB_DEACHINTMSK_ECH_IN_EP_MSK10_Pos) & USB_DEACHINTMSK_ECH_IN_EP_MSK10_Msk) /*!< ECH_IN_EP_MSK10 Set Value */
#define USB_DEACHINTMSK_ECH_IN_EP_MSK10_Get(x) (((uint32_t) (x) & USB_DEACHINTMSK_ECH_IN_EP_MSK10_Msk) >> USB_DEACHINTMSK_ECH_IN_EP_MSK10_Pos) /*!< ECH_IN_EP_MSK10 Get Value */


#define USB_DEACHINTMSK_ECH_IN_EP_MSK9_Pos    (9U)                                                                        /*!< ECH_IN_EP_MSK9 Postion   */ 
#define USB_DEACHINTMSK_ECH_IN_EP_MSK9_Msk    (0x1U << USB_DEACHINTMSK_ECH_IN_EP_MSK9_Pos)                                /*!< ECH_IN_EP_MSK9 Mask      */
#define USB_DEACHINTMSK_ECH_IN_EP_MSK9_Set(x) (((uint32_t) (x) << USB_DEACHINTMSK_ECH_IN_EP_MSK9_Pos) & USB_DEACHINTMSK_ECH_IN_EP_MSK9_Msk) /*!< ECH_IN_EP_MSK9 Set Value */
#define USB_DEACHINTMSK_ECH_IN_EP_MSK9_Get(x) (((uint32_t) (x) & USB_DEACHINTMSK_ECH_IN_EP_MSK9_Msk) >> USB_DEACHINTMSK_ECH_IN_EP_MSK9_Pos) /*!< ECH_IN_EP_MSK9 Get Value */


#define USB_DEACHINTMSK_ECH_IN_EP_MSK8_Pos    (8U)                                                                        /*!< ECH_IN_EP_MSK8 Postion   */ 
#define USB_DEACHINTMSK_ECH_IN_EP_MSK8_Msk    (0x1U << USB_DEACHINTMSK_ECH_IN_EP_MSK8_Pos)                                /*!< ECH_IN_EP_MSK8 Mask      */
#define USB_DEACHINTMSK_ECH_IN_EP_MSK8_Set(x) (((uint32_t) (x) << USB_DEACHINTMSK_ECH_IN_EP_MSK8_Pos) & USB_DEACHINTMSK_ECH_IN_EP_MSK8_Msk) /*!< ECH_IN_EP_MSK8 Set Value */
#define USB_DEACHINTMSK_ECH_IN_EP_MSK8_Get(x) (((uint32_t) (x) & USB_DEACHINTMSK_ECH_IN_EP_MSK8_Msk) >> USB_DEACHINTMSK_ECH_IN_EP_MSK8_Pos) /*!< ECH_IN_EP_MSK8 Get Value */


#define USB_DEACHINTMSK_ECH_IN_EP_MSK7_Pos    (7U)                                                                        /*!< ECH_IN_EP_MSK7 Postion   */ 
#define USB_DEACHINTMSK_ECH_IN_EP_MSK7_Msk    (0x1U << USB_DEACHINTMSK_ECH_IN_EP_MSK7_Pos)                                /*!< ECH_IN_EP_MSK7 Mask      */
#define USB_DEACHINTMSK_ECH_IN_EP_MSK7_Set(x) (((uint32_t) (x) << USB_DEACHINTMSK_ECH_IN_EP_MSK7_Pos) & USB_DEACHINTMSK_ECH_IN_EP_MSK7_Msk) /*!< ECH_IN_EP_MSK7 Set Value */
#define USB_DEACHINTMSK_ECH_IN_EP_MSK7_Get(x) (((uint32_t) (x) & USB_DEACHINTMSK_ECH_IN_EP_MSK7_Msk) >> USB_DEACHINTMSK_ECH_IN_EP_MSK7_Pos) /*!< ECH_IN_EP_MSK7 Get Value */


#define USB_DEACHINTMSK_ECH_IN_EP_MSK6_Pos    (6U)                                                                        /*!< ECH_IN_EP_MSK6 Postion   */ 
#define USB_DEACHINTMSK_ECH_IN_EP_MSK6_Msk    (0x1U << USB_DEACHINTMSK_ECH_IN_EP_MSK6_Pos)                                /*!< ECH_IN_EP_MSK6 Mask      */
#define USB_DEACHINTMSK_ECH_IN_EP_MSK6_Set(x) (((uint32_t) (x) << USB_DEACHINTMSK_ECH_IN_EP_MSK6_Pos) & USB_DEACHINTMSK_ECH_IN_EP_MSK6_Msk) /*!< ECH_IN_EP_MSK6 Set Value */
#define USB_DEACHINTMSK_ECH_IN_EP_MSK6_Get(x) (((uint32_t) (x) & USB_DEACHINTMSK_ECH_IN_EP_MSK6_Msk) >> USB_DEACHINTMSK_ECH_IN_EP_MSK6_Pos) /*!< ECH_IN_EP_MSK6 Get Value */


#define USB_DEACHINTMSK_ECH_IN_EP_MSK5_Pos    (5U)                                                                        /*!< ECH_IN_EP_MSK5 Postion   */ 
#define USB_DEACHINTMSK_ECH_IN_EP_MSK5_Msk    (0x1U << USB_DEACHINTMSK_ECH_IN_EP_MSK5_Pos)                                /*!< ECH_IN_EP_MSK5 Mask      */
#define USB_DEACHINTMSK_ECH_IN_EP_MSK5_Set(x) (((uint32_t) (x) << USB_DEACHINTMSK_ECH_IN_EP_MSK5_Pos) & USB_DEACHINTMSK_ECH_IN_EP_MSK5_Msk) /*!< ECH_IN_EP_MSK5 Set Value */
#define USB_DEACHINTMSK_ECH_IN_EP_MSK5_Get(x) (((uint32_t) (x) & USB_DEACHINTMSK_ECH_IN_EP_MSK5_Msk) >> USB_DEACHINTMSK_ECH_IN_EP_MSK5_Pos) /*!< ECH_IN_EP_MSK5 Get Value */


#define USB_DEACHINTMSK_ECH_IN_EP_MSK4_Pos    (4U)                                                                        /*!< ECH_IN_EP_MSK4 Postion   */ 
#define USB_DEACHINTMSK_ECH_IN_EP_MSK4_Msk    (0x1U << USB_DEACHINTMSK_ECH_IN_EP_MSK4_Pos)                                /*!< ECH_IN_EP_MSK4 Mask      */
#define USB_DEACHINTMSK_ECH_IN_EP_MSK4_Set(x) (((uint32_t) (x) << USB_DEACHINTMSK_ECH_IN_EP_MSK4_Pos) & USB_DEACHINTMSK_ECH_IN_EP_MSK4_Msk) /*!< ECH_IN_EP_MSK4 Set Value */
#define USB_DEACHINTMSK_ECH_IN_EP_MSK4_Get(x) (((uint32_t) (x) & USB_DEACHINTMSK_ECH_IN_EP_MSK4_Msk) >> USB_DEACHINTMSK_ECH_IN_EP_MSK4_Pos) /*!< ECH_IN_EP_MSK4 Get Value */


#define USB_DEACHINTMSK_ECH_IN_EP_MSK3_Pos    (3U)                                                                        /*!< ECH_IN_EP_MSK3 Postion   */ 
#define USB_DEACHINTMSK_ECH_IN_EP_MSK3_Msk    (0x1U << USB_DEACHINTMSK_ECH_IN_EP_MSK3_Pos)                                /*!< ECH_IN_EP_MSK3 Mask      */
#define USB_DEACHINTMSK_ECH_IN_EP_MSK3_Set(x) (((uint32_t) (x) << USB_DEACHINTMSK_ECH_IN_EP_MSK3_Pos) & USB_DEACHINTMSK_ECH_IN_EP_MSK3_Msk) /*!< ECH_IN_EP_MSK3 Set Value */
#define USB_DEACHINTMSK_ECH_IN_EP_MSK3_Get(x) (((uint32_t) (x) & USB_DEACHINTMSK_ECH_IN_EP_MSK3_Msk) >> USB_DEACHINTMSK_ECH_IN_EP_MSK3_Pos) /*!< ECH_IN_EP_MSK3 Get Value */


#define USB_DEACHINTMSK_ECH_IN_EP_MSK2_Pos    (2U)                                                                        /*!< ECH_IN_EP_MSK2 Postion   */ 
#define USB_DEACHINTMSK_ECH_IN_EP_MSK2_Msk    (0x1U << USB_DEACHINTMSK_ECH_IN_EP_MSK2_Pos)                                /*!< ECH_IN_EP_MSK2 Mask      */
#define USB_DEACHINTMSK_ECH_IN_EP_MSK2_Set(x) (((uint32_t) (x) << USB_DEACHINTMSK_ECH_IN_EP_MSK2_Pos) & USB_DEACHINTMSK_ECH_IN_EP_MSK2_Msk) /*!< ECH_IN_EP_MSK2 Set Value */
#define USB_DEACHINTMSK_ECH_IN_EP_MSK2_Get(x) (((uint32_t) (x) & USB_DEACHINTMSK_ECH_IN_EP_MSK2_Msk) >> USB_DEACHINTMSK_ECH_IN_EP_MSK2_Pos) /*!< ECH_IN_EP_MSK2 Get Value */


#define USB_DEACHINTMSK_ECH_IN_EP_MSK1_Pos    (1U)                                                                        /*!< ECH_IN_EP_MSK1 Postion   */ 
#define USB_DEACHINTMSK_ECH_IN_EP_MSK1_Msk    (0x1U << USB_DEACHINTMSK_ECH_IN_EP_MSK1_Pos)                                /*!< ECH_IN_EP_MSK1 Mask      */
#define USB_DEACHINTMSK_ECH_IN_EP_MSK1_Set(x) (((uint32_t) (x) << USB_DEACHINTMSK_ECH_IN_EP_MSK1_Pos) & USB_DEACHINTMSK_ECH_IN_EP_MSK1_Msk) /*!< ECH_IN_EP_MSK1 Set Value */
#define USB_DEACHINTMSK_ECH_IN_EP_MSK1_Get(x) (((uint32_t) (x) & USB_DEACHINTMSK_ECH_IN_EP_MSK1_Msk) >> USB_DEACHINTMSK_ECH_IN_EP_MSK1_Pos) /*!< ECH_IN_EP_MSK1 Get Value */


#define USB_DEACHINTMSK_ECH_IN_EP_MSK0_Pos    (0U)                                                                        /*!< ECH_IN_EP_MSK0 Postion   */ 
#define USB_DEACHINTMSK_ECH_IN_EP_MSK0_Msk    (0x1U << USB_DEACHINTMSK_ECH_IN_EP_MSK0_Pos)                                /*!< ECH_IN_EP_MSK0 Mask      */
#define USB_DEACHINTMSK_ECH_IN_EP_MSK0_Set(x) (((uint32_t) (x) << USB_DEACHINTMSK_ECH_IN_EP_MSK0_Pos) & USB_DEACHINTMSK_ECH_IN_EP_MSK0_Msk) /*!< ECH_IN_EP_MSK0 Set Value */
#define USB_DEACHINTMSK_ECH_IN_EP_MSK0_Get(x) (((uint32_t) (x) & USB_DEACHINTMSK_ECH_IN_EP_MSK0_Msk) >> USB_DEACHINTMSK_ECH_IN_EP_MSK0_Pos) /*!< ECH_IN_EP_MSK0 Get Value */


/* DIEPEACHMSK0 bitfield */
#define USB_DIEPEACHMSK0_DIEP_EACHMSK0_NAKMSK_Pos    (13U)                                                                       /*!< DIEP_EACHMSK0_NAKMSK Postion   */ 
#define USB_DIEPEACHMSK0_DIEP_EACHMSK0_NAKMSK_Msk    (0x1U << USB_DIEPEACHMSK0_DIEP_EACHMSK0_NAKMSK_Pos)                         /*!< DIEP_EACHMSK0_NAKMSK Mask      */
#define USB_DIEPEACHMSK0_DIEP_EACHMSK0_NAKMSK_Set(x) (((uint32_t) (x) << USB_DIEPEACHMSK0_DIEP_EACHMSK0_NAKMSK_Pos) & USB_DIEPEACHMSK0_DIEP_EACHMSK0_NAKMSK_Msk) /*!< DIEP_EACHMSK0_NAKMSK Set Value */
#define USB_DIEPEACHMSK0_DIEP_EACHMSK0_NAKMSK_Get(x) (((uint32_t) (x) & USB_DIEPEACHMSK0_DIEP_EACHMSK0_NAKMSK_Msk) >> USB_DIEPEACHMSK0_DIEP_EACHMSK0_NAKMSK_Pos) /*!< DIEP_EACHMSK0_NAKMSK Get Value */


#define USB_DIEPEACHMSK0_DIEP_EACHMSK0_BNAIN_INTR_MSK_Pos    (9U)                                                                        /*!< DIEP_EACHMSK0_BNAIN_INTR_MSK Postion   */ 
#define USB_DIEPEACHMSK0_DIEP_EACHMSK0_BNAIN_INTR_MSK_Msk    (0x1U << USB_DIEPEACHMSK0_DIEP_EACHMSK0_BNAIN_INTR_MSK_Pos)                 /*!< DIEP_EACHMSK0_BNAIN_INTR_MSK Mask      */
#define USB_DIEPEACHMSK0_DIEP_EACHMSK0_BNAIN_INTR_MSK_Set(x) (((uint32_t) (x) << USB_DIEPEACHMSK0_DIEP_EACHMSK0_BNAIN_INTR_MSK_Pos) & USB_DIEPEACHMSK0_DIEP_EACHMSK0_BNAIN_INTR_MSK_Msk) /*!< DIEP_EACHMSK0_BNAIN_INTR_MSK Set Value */
#define USB_DIEPEACHMSK0_DIEP_EACHMSK0_BNAIN_INTR_MSK_Get(x) (((uint32_t) (x) & USB_DIEPEACHMSK0_DIEP_EACHMSK0_BNAIN_INTR_MSK_Msk) >> USB_DIEPEACHMSK0_DIEP_EACHMSK0_BNAIN_INTR_MSK_Pos) /*!< DIEP_EACHMSK0_BNAIN_INTR_MSK Get Value */


#define USB_DIEPEACHMSK0_DIEP_EACHMSK0_TXFIFO_UNDRN_MSK_Pos    (8U)                                                                        /*!< DIEP_EACHMSK0_TXFIFO_UNDRN_MSK Postion   */ 
#define USB_DIEPEACHMSK0_DIEP_EACHMSK0_TXFIFO_UNDRN_MSK_Msk    (0x1U << USB_DIEPEACHMSK0_DIEP_EACHMSK0_TXFIFO_UNDRN_MSK_Pos)               /*!< DIEP_EACHMSK0_TXFIFO_UNDRN_MSK Mask      */
#define USB_DIEPEACHMSK0_DIEP_EACHMSK0_TXFIFO_UNDRN_MSK_Set(x) (((uint32_t) (x) << USB_DIEPEACHMSK0_DIEP_EACHMSK0_TXFIFO_UNDRN_MSK_Pos) & USB_DIEPEACHMSK0_DIEP_EACHMSK0_TXFIFO_UNDRN_MSK_Msk) /*!< DIEP_EACHMSK0_TXFIFO_UNDRN_MSK Set Value */
#define USB_DIEPEACHMSK0_DIEP_EACHMSK0_TXFIFO_UNDRN_MSK_Get(x) (((uint32_t) (x) & USB_DIEPEACHMSK0_DIEP_EACHMSK0_TXFIFO_UNDRN_MSK_Msk) >> USB_DIEPEACHMSK0_DIEP_EACHMSK0_TXFIFO_UNDRN_MSK_Pos) /*!< DIEP_EACHMSK0_TXFIFO_UNDRN_MSK Get Value */


#define USB_DIEPEACHMSK0_DIEP_EACHMSK0_IN_EP_NAK_EFF_MSK_Pos    (6U)                                                                        /*!< DIEP_EACHMSK0_IN_EP_NAK_EFF_MSK Postion   */ 
#define USB_DIEPEACHMSK0_DIEP_EACHMSK0_IN_EP_NAK_EFF_MSK_Msk    (0x1U << USB_DIEPEACHMSK0_DIEP_EACHMSK0_IN_EP_NAK_EFF_MSK_Pos)              /*!< DIEP_EACHMSK0_IN_EP_NAK_EFF_MSK Mask      */
#define USB_DIEPEACHMSK0_DIEP_EACHMSK0_IN_EP_NAK_EFF_MSK_Set(x) (((uint32_t) (x) << USB_DIEPEACHMSK0_DIEP_EACHMSK0_IN_EP_NAK_EFF_MSK_Pos) & USB_DIEPEACHMSK0_DIEP_EACHMSK0_IN_EP_NAK_EFF_MSK_Msk) /*!< DIEP_EACHMSK0_IN_EP_NAK_EFF_MSK Set Value */
#define USB_DIEPEACHMSK0_DIEP_EACHMSK0_IN_EP_NAK_EFF_MSK_Get(x) (((uint32_t) (x) & USB_DIEPEACHMSK0_DIEP_EACHMSK0_IN_EP_NAK_EFF_MSK_Msk) >> USB_DIEPEACHMSK0_DIEP_EACHMSK0_IN_EP_NAK_EFF_MSK_Pos) /*!< DIEP_EACHMSK0_IN_EP_NAK_EFF_MSK Get Value */


#define USB_DIEPEACHMSK0_DIEP_EACHMSK0_IN_TKN_EP_MIS_MSK_Pos    (5U)                                                                        /*!< DIEP_EACHMSK0_IN_TKN_EP_MIS_MSK Postion   */ 
#define USB_DIEPEACHMSK0_DIEP_EACHMSK0_IN_TKN_EP_MIS_MSK_Msk    (0x1U << USB_DIEPEACHMSK0_DIEP_EACHMSK0_IN_TKN_EP_MIS_MSK_Pos)              /*!< DIEP_EACHMSK0_IN_TKN_EP_MIS_MSK Mask      */
#define USB_DIEPEACHMSK0_DIEP_EACHMSK0_IN_TKN_EP_MIS_MSK_Set(x) (((uint32_t) (x) << USB_DIEPEACHMSK0_DIEP_EACHMSK0_IN_TKN_EP_MIS_MSK_Pos) & USB_DIEPEACHMSK0_DIEP_EACHMSK0_IN_TKN_EP_MIS_MSK_Msk) /*!< DIEP_EACHMSK0_IN_TKN_EP_MIS_MSK Set Value */
#define USB_DIEPEACHMSK0_DIEP_EACHMSK0_IN_TKN_EP_MIS_MSK_Get(x) (((uint32_t) (x) & USB_DIEPEACHMSK0_DIEP_EACHMSK0_IN_TKN_EP_MIS_MSK_Msk) >> USB_DIEPEACHMSK0_DIEP_EACHMSK0_IN_TKN_EP_MIS_MSK_Pos) /*!< DIEP_EACHMSK0_IN_TKN_EP_MIS_MSK Get Value */


#define USB_DIEPEACHMSK0_DIEP_EACHMSK0_IN_TKN_TXFEMP_MSK_Pos    (4U)                                                                        /*!< DIEP_EACHMSK0_IN_TKN_TXFEMP_MSK Postion   */ 
#define USB_DIEPEACHMSK0_DIEP_EACHMSK0_IN_TKN_TXFEMP_MSK_Msk    (0x1U << USB_DIEPEACHMSK0_DIEP_EACHMSK0_IN_TKN_TXFEMP_MSK_Pos)              /*!< DIEP_EACHMSK0_IN_TKN_TXFEMP_MSK Mask      */
#define USB_DIEPEACHMSK0_DIEP_EACHMSK0_IN_TKN_TXFEMP_MSK_Set(x) (((uint32_t) (x) << USB_DIEPEACHMSK0_DIEP_EACHMSK0_IN_TKN_TXFEMP_MSK_Pos) & USB_DIEPEACHMSK0_DIEP_EACHMSK0_IN_TKN_TXFEMP_MSK_Msk) /*!< DIEP_EACHMSK0_IN_TKN_TXFEMP_MSK Set Value */
#define USB_DIEPEACHMSK0_DIEP_EACHMSK0_IN_TKN_TXFEMP_MSK_Get(x) (((uint32_t) (x) & USB_DIEPEACHMSK0_DIEP_EACHMSK0_IN_TKN_TXFEMP_MSK_Msk) >> USB_DIEPEACHMSK0_DIEP_EACHMSK0_IN_TKN_TXFEMP_MSK_Pos) /*!< DIEP_EACHMSK0_IN_TKN_TXFEMP_MSK Get Value */


#define USB_DIEPEACHMSK0_DIEP_EACHMSK0_TIME_OUT_MSK_Pos    (3U)                                                                        /*!< DIEP_EACHMSK0_TIME_OUT_MSK Postion   */ 
#define USB_DIEPEACHMSK0_DIEP_EACHMSK0_TIME_OUT_MSK_Msk    (0x1U << USB_DIEPEACHMSK0_DIEP_EACHMSK0_TIME_OUT_MSK_Pos)                   /*!< DIEP_EACHMSK0_TIME_OUT_MSK Mask      */
#define USB_DIEPEACHMSK0_DIEP_EACHMSK0_TIME_OUT_MSK_Set(x) (((uint32_t) (x) << USB_DIEPEACHMSK0_DIEP_EACHMSK0_TIME_OUT_MSK_Pos) & USB_DIEPEACHMSK0_DIEP_EACHMSK0_TIME_OUT_MSK_Msk) /*!< DIEP_EACHMSK0_TIME_OUT_MSK Set Value */
#define USB_DIEPEACHMSK0_DIEP_EACHMSK0_TIME_OUT_MSK_Get(x) (((uint32_t) (x) & USB_DIEPEACHMSK0_DIEP_EACHMSK0_TIME_OUT_MSK_Msk) >> USB_DIEPEACHMSK0_DIEP_EACHMSK0_TIME_OUT_MSK_Pos) /*!< DIEP_EACHMSK0_TIME_OUT_MSK Get Value */


#define USB_DIEPEACHMSK0_DIEP_EACHMSK0_AHB_ERR_MSK_Pos    (2U)                                                                        /*!< DIEP_EACHMSK0_AHB_ERR_MSK Postion   */ 
#define USB_DIEPEACHMSK0_DIEP_EACHMSK0_AHB_ERR_MSK_Msk    (0x1U << USB_DIEPEACHMSK0_DIEP_EACHMSK0_AHB_ERR_MSK_Pos)                    /*!< DIEP_EACHMSK0_AHB_ERR_MSK Mask      */
#define USB_DIEPEACHMSK0_DIEP_EACHMSK0_AHB_ERR_MSK_Set(x) (((uint32_t) (x) << USB_DIEPEACHMSK0_DIEP_EACHMSK0_AHB_ERR_MSK_Pos) & USB_DIEPEACHMSK0_DIEP_EACHMSK0_AHB_ERR_MSK_Msk) /*!< DIEP_EACHMSK0_AHB_ERR_MSK Set Value */
#define USB_DIEPEACHMSK0_DIEP_EACHMSK0_AHB_ERR_MSK_Get(x) (((uint32_t) (x) & USB_DIEPEACHMSK0_DIEP_EACHMSK0_AHB_ERR_MSK_Msk) >> USB_DIEPEACHMSK0_DIEP_EACHMSK0_AHB_ERR_MSK_Pos) /*!< DIEP_EACHMSK0_AHB_ERR_MSK Get Value */


#define USB_DIEPEACHMSK0_DIEP_EACHMSK0_EP_DISBLD_MSK_Pos    (1U)                                                                        /*!< DIEP_EACHMSK0_EP_DISBLD_MSK Postion   */ 
#define USB_DIEPEACHMSK0_DIEP_EACHMSK0_EP_DISBLD_MSK_Msk    (0x1U << USB_DIEPEACHMSK0_DIEP_EACHMSK0_EP_DISBLD_MSK_Pos)                  /*!< DIEP_EACHMSK0_EP_DISBLD_MSK Mask      */
#define USB_DIEPEACHMSK0_DIEP_EACHMSK0_EP_DISBLD_MSK_Set(x) (((uint32_t) (x) << USB_DIEPEACHMSK0_DIEP_EACHMSK0_EP_DISBLD_MSK_Pos) & USB_DIEPEACHMSK0_DIEP_EACHMSK0_EP_DISBLD_MSK_Msk) /*!< DIEP_EACHMSK0_EP_DISBLD_MSK Set Value */
#define USB_DIEPEACHMSK0_DIEP_EACHMSK0_EP_DISBLD_MSK_Get(x) (((uint32_t) (x) & USB_DIEPEACHMSK0_DIEP_EACHMSK0_EP_DISBLD_MSK_Msk) >> USB_DIEPEACHMSK0_DIEP_EACHMSK0_EP_DISBLD_MSK_Pos) /*!< DIEP_EACHMSK0_EP_DISBLD_MSK Get Value */


#define USB_DIEPEACHMSK0_DIEP_EACHMSK0_XFER_COMPL_MSK_Pos    (0U)                                                                        /*!< DIEP_EACHMSK0_XFER_COMPL_MSK Postion   */ 
#define USB_DIEPEACHMSK0_DIEP_EACHMSK0_XFER_COMPL_MSK_Msk    (0x1U << USB_DIEPEACHMSK0_DIEP_EACHMSK0_XFER_COMPL_MSK_Pos)                 /*!< DIEP_EACHMSK0_XFER_COMPL_MSK Mask      */
#define USB_DIEPEACHMSK0_DIEP_EACHMSK0_XFER_COMPL_MSK_Set(x) (((uint32_t) (x) << USB_DIEPEACHMSK0_DIEP_EACHMSK0_XFER_COMPL_MSK_Pos) & USB_DIEPEACHMSK0_DIEP_EACHMSK0_XFER_COMPL_MSK_Msk) /*!< DIEP_EACHMSK0_XFER_COMPL_MSK Set Value */
#define USB_DIEPEACHMSK0_DIEP_EACHMSK0_XFER_COMPL_MSK_Get(x) (((uint32_t) (x) & USB_DIEPEACHMSK0_DIEP_EACHMSK0_XFER_COMPL_MSK_Msk) >> USB_DIEPEACHMSK0_DIEP_EACHMSK0_XFER_COMPL_MSK_Pos) /*!< DIEP_EACHMSK0_XFER_COMPL_MSK Get Value */


/* DOEPEACHMSK0 bitfield */
#define USB_DOEPEACHMSK0_DOEP_EACHMSK0_NYETMSK_Pos    (14U)                                                                       /*!< DOEP_EACHMSK0_NYETMSK Postion   */ 
#define USB_DOEPEACHMSK0_DOEP_EACHMSK0_NYETMSK_Msk    (0x1U << USB_DOEPEACHMSK0_DOEP_EACHMSK0_NYETMSK_Pos)                        /*!< DOEP_EACHMSK0_NYETMSK Mask      */
#define USB_DOEPEACHMSK0_DOEP_EACHMSK0_NYETMSK_Set(x) (((uint32_t) (x) << USB_DOEPEACHMSK0_DOEP_EACHMSK0_NYETMSK_Pos) & USB_DOEPEACHMSK0_DOEP_EACHMSK0_NYETMSK_Msk) /*!< DOEP_EACHMSK0_NYETMSK Set Value */
#define USB_DOEPEACHMSK0_DOEP_EACHMSK0_NYETMSK_Get(x) (((uint32_t) (x) & USB_DOEPEACHMSK0_DOEP_EACHMSK0_NYETMSK_Msk) >> USB_DOEPEACHMSK0_DOEP_EACHMSK0_NYETMSK_Pos) /*!< DOEP_EACHMSK0_NYETMSK Get Value */


#define USB_DOEPEACHMSK0_DOEP_EACHMSK0_NAKMSK_Pos    (13U)                                                                       /*!< DOEP_EACHMSK0_NAKMSK Postion   */ 
#define USB_DOEPEACHMSK0_DOEP_EACHMSK0_NAKMSK_Msk    (0x1U << USB_DOEPEACHMSK0_DOEP_EACHMSK0_NAKMSK_Pos)                         /*!< DOEP_EACHMSK0_NAKMSK Mask      */
#define USB_DOEPEACHMSK0_DOEP_EACHMSK0_NAKMSK_Set(x) (((uint32_t) (x) << USB_DOEPEACHMSK0_DOEP_EACHMSK0_NAKMSK_Pos) & USB_DOEPEACHMSK0_DOEP_EACHMSK0_NAKMSK_Msk) /*!< DOEP_EACHMSK0_NAKMSK Set Value */
#define USB_DOEPEACHMSK0_DOEP_EACHMSK0_NAKMSK_Get(x) (((uint32_t) (x) & USB_DOEPEACHMSK0_DOEP_EACHMSK0_NAKMSK_Msk) >> USB_DOEPEACHMSK0_DOEP_EACHMSK0_NAKMSK_Pos) /*!< DOEP_EACHMSK0_NAKMSK Get Value */


#define USB_DOEPEACHMSK0_DOEP_EACHMSK0_BBLE_ERR_MSK_Pos    (12U)                                                                       /*!< DOEP_EACHMSK0_BBLE_ERR_MSK Postion   */ 
#define USB_DOEPEACHMSK0_DOEP_EACHMSK0_BBLE_ERR_MSK_Msk    (0x1U << USB_DOEPEACHMSK0_DOEP_EACHMSK0_BBLE_ERR_MSK_Pos)                   /*!< DOEP_EACHMSK0_BBLE_ERR_MSK Mask      */
#define USB_DOEPEACHMSK0_DOEP_EACHMSK0_BBLE_ERR_MSK_Set(x) (((uint32_t) (x) << USB_DOEPEACHMSK0_DOEP_EACHMSK0_BBLE_ERR_MSK_Pos) & USB_DOEPEACHMSK0_DOEP_EACHMSK0_BBLE_ERR_MSK_Msk) /*!< DOEP_EACHMSK0_BBLE_ERR_MSK Set Value */
#define USB_DOEPEACHMSK0_DOEP_EACHMSK0_BBLE_ERR_MSK_Get(x) (((uint32_t) (x) & USB_DOEPEACHMSK0_DOEP_EACHMSK0_BBLE_ERR_MSK_Msk) >> USB_DOEPEACHMSK0_DOEP_EACHMSK0_BBLE_ERR_MSK_Pos) /*!< DOEP_EACHMSK0_BBLE_ERR_MSK Get Value */


#define USB_DOEPEACHMSK0_DOEP_EACHMSK0_BNA_OUT_INTR_MSK_Pos    (9U)                                                                        /*!< DOEP_EACHMSK0_BNA_OUT_INTR_MSK Postion   */ 
#define USB_DOEPEACHMSK0_DOEP_EACHMSK0_BNA_OUT_INTR_MSK_Msk    (0x1U << USB_DOEPEACHMSK0_DOEP_EACHMSK0_BNA_OUT_INTR_MSK_Pos)               /*!< DOEP_EACHMSK0_BNA_OUT_INTR_MSK Mask      */
#define USB_DOEPEACHMSK0_DOEP_EACHMSK0_BNA_OUT_INTR_MSK_Set(x) (((uint32_t) (x) << USB_DOEPEACHMSK0_DOEP_EACHMSK0_BNA_OUT_INTR_MSK_Pos) & USB_DOEPEACHMSK0_DOEP_EACHMSK0_BNA_OUT_INTR_MSK_Msk) /*!< DOEP_EACHMSK0_BNA_OUT_INTR_MSK Set Value */
#define USB_DOEPEACHMSK0_DOEP_EACHMSK0_BNA_OUT_INTR_MSK_Get(x) (((uint32_t) (x) & USB_DOEPEACHMSK0_DOEP_EACHMSK0_BNA_OUT_INTR_MSK_Msk) >> USB_DOEPEACHMSK0_DOEP_EACHMSK0_BNA_OUT_INTR_MSK_Pos) /*!< DOEP_EACHMSK0_BNA_OUT_INTR_MSK Get Value */


#define USB_DOEPEACHMSK0_DOEP_EACHMSK0_OUT_PKT_ERR_MSK_Pos    (8U)                                                                        /*!< DOEP_EACHMSK0_OUT_PKT_ERR_MSK Postion   */ 
#define USB_DOEPEACHMSK0_DOEP_EACHMSK0_OUT_PKT_ERR_MSK_Msk    (0x1U << USB_DOEPEACHMSK0_DOEP_EACHMSK0_OUT_PKT_ERR_MSK_Pos)                /*!< DOEP_EACHMSK0_OUT_PKT_ERR_MSK Mask      */
#define USB_DOEPEACHMSK0_DOEP_EACHMSK0_OUT_PKT_ERR_MSK_Set(x) (((uint32_t) (x) << USB_DOEPEACHMSK0_DOEP_EACHMSK0_OUT_PKT_ERR_MSK_Pos) & USB_DOEPEACHMSK0_DOEP_EACHMSK0_OUT_PKT_ERR_MSK_Msk) /*!< DOEP_EACHMSK0_OUT_PKT_ERR_MSK Set Value */
#define USB_DOEPEACHMSK0_DOEP_EACHMSK0_OUT_PKT_ERR_MSK_Get(x) (((uint32_t) (x) & USB_DOEPEACHMSK0_DOEP_EACHMSK0_OUT_PKT_ERR_MSK_Msk) >> USB_DOEPEACHMSK0_DOEP_EACHMSK0_OUT_PKT_ERR_MSK_Pos) /*!< DOEP_EACHMSK0_OUT_PKT_ERR_MSK Get Value */


#define USB_DOEPEACHMSK0_DOEP_EACHMSK0_BACK2BACK_SETUP_Pos    (6U)                                                                        /*!< DOEP_EACHMSK0_BACK2BACK_SETUP Postion   */ 
#define USB_DOEPEACHMSK0_DOEP_EACHMSK0_BACK2BACK_SETUP_Msk    (0x1U << USB_DOEPEACHMSK0_DOEP_EACHMSK0_BACK2BACK_SETUP_Pos)                /*!< DOEP_EACHMSK0_BACK2BACK_SETUP Mask      */
#define USB_DOEPEACHMSK0_DOEP_EACHMSK0_BACK2BACK_SETUP_Set(x) (((uint32_t) (x) << USB_DOEPEACHMSK0_DOEP_EACHMSK0_BACK2BACK_SETUP_Pos) & USB_DOEPEACHMSK0_DOEP_EACHMSK0_BACK2BACK_SETUP_Msk) /*!< DOEP_EACHMSK0_BACK2BACK_SETUP Set Value */
#define USB_DOEPEACHMSK0_DOEP_EACHMSK0_BACK2BACK_SETUP_Get(x) (((uint32_t) (x) & USB_DOEPEACHMSK0_DOEP_EACHMSK0_BACK2BACK_SETUP_Msk) >> USB_DOEPEACHMSK0_DOEP_EACHMSK0_BACK2BACK_SETUP_Pos) /*!< DOEP_EACHMSK0_BACK2BACK_SETUP Get Value */


#define USB_DOEPEACHMSK0_DOEP_EACHMSK0_STS_PHS_RCVD_MSK_Pos    (5U)                                                                        /*!< DOEP_EACHMSK0_STS_PHS_RCVD_MSK Postion   */ 
#define USB_DOEPEACHMSK0_DOEP_EACHMSK0_STS_PHS_RCVD_MSK_Msk    (0x1U << USB_DOEPEACHMSK0_DOEP_EACHMSK0_STS_PHS_RCVD_MSK_Pos)               /*!< DOEP_EACHMSK0_STS_PHS_RCVD_MSK Mask      */
#define USB_DOEPEACHMSK0_DOEP_EACHMSK0_STS_PHS_RCVD_MSK_Set(x) (((uint32_t) (x) << USB_DOEPEACHMSK0_DOEP_EACHMSK0_STS_PHS_RCVD_MSK_Pos) & USB_DOEPEACHMSK0_DOEP_EACHMSK0_STS_PHS_RCVD_MSK_Msk) /*!< DOEP_EACHMSK0_STS_PHS_RCVD_MSK Set Value */
#define USB_DOEPEACHMSK0_DOEP_EACHMSK0_STS_PHS_RCVD_MSK_Get(x) (((uint32_t) (x) & USB_DOEPEACHMSK0_DOEP_EACHMSK0_STS_PHS_RCVD_MSK_Msk) >> USB_DOEPEACHMSK0_DOEP_EACHMSK0_STS_PHS_RCVD_MSK_Pos) /*!< DOEP_EACHMSK0_STS_PHS_RCVD_MSK Get Value */


#define USB_DOEPEACHMSK0_DOEP_EACHMSK0_OUT_TKN_EP_DIS_MSK_Pos    (4U)                                                                        /*!< DOEP_EACHMSK0_OUT_TKN_EP_DIS_MSK Postion   */ 
#define USB_DOEPEACHMSK0_DOEP_EACHMSK0_OUT_TKN_EP_DIS_MSK_Msk    (0x1U << USB_DOEPEACHMSK0_DOEP_EACHMSK0_OUT_TKN_EP_DIS_MSK_Pos)             /*!< DOEP_EACHMSK0_OUT_TKN_EP_DIS_MSK Mask      */
#define USB_DOEPEACHMSK0_DOEP_EACHMSK0_OUT_TKN_EP_DIS_MSK_Set(x) (((uint32_t) (x) << USB_DOEPEACHMSK0_DOEP_EACHMSK0_OUT_TKN_EP_DIS_MSK_Pos) & USB_DOEPEACHMSK0_DOEP_EACHMSK0_OUT_TKN_EP_DIS_MSK_Msk) /*!< DOEP_EACHMSK0_OUT_TKN_EP_DIS_MSK Set Value */
#define USB_DOEPEACHMSK0_DOEP_EACHMSK0_OUT_TKN_EP_DIS_MSK_Get(x) (((uint32_t) (x) & USB_DOEPEACHMSK0_DOEP_EACHMSK0_OUT_TKN_EP_DIS_MSK_Msk) >> USB_DOEPEACHMSK0_DOEP_EACHMSK0_OUT_TKN_EP_DIS_MSK_Pos) /*!< DOEP_EACHMSK0_OUT_TKN_EP_DIS_MSK Get Value */


#define USB_DOEPEACHMSK0_DOEP_EACHMSK0_SET_UPMSK_Pos    (3U)                                                                        /*!< DOEP_EACHMSK0_SET_UPMSK Postion   */ 
#define USB_DOEPEACHMSK0_DOEP_EACHMSK0_SET_UPMSK_Msk    (0x1U << USB_DOEPEACHMSK0_DOEP_EACHMSK0_SET_UPMSK_Pos)                      /*!< DOEP_EACHMSK0_SET_UPMSK Mask      */
#define USB_DOEPEACHMSK0_DOEP_EACHMSK0_SET_UPMSK_Set(x) (((uint32_t) (x) << USB_DOEPEACHMSK0_DOEP_EACHMSK0_SET_UPMSK_Pos) & USB_DOEPEACHMSK0_DOEP_EACHMSK0_SET_UPMSK_Msk) /*!< DOEP_EACHMSK0_SET_UPMSK Set Value */
#define USB_DOEPEACHMSK0_DOEP_EACHMSK0_SET_UPMSK_Get(x) (((uint32_t) (x) & USB_DOEPEACHMSK0_DOEP_EACHMSK0_SET_UPMSK_Msk) >> USB_DOEPEACHMSK0_DOEP_EACHMSK0_SET_UPMSK_Pos) /*!< DOEP_EACHMSK0_SET_UPMSK Get Value */


#define USB_DOEPEACHMSK0_DOEP_EACHMSK0_AHB_ERR_MSK_Pos    (2U)                                                                        /*!< DOEP_EACHMSK0_AHB_ERR_MSK Postion   */ 
#define USB_DOEPEACHMSK0_DOEP_EACHMSK0_AHB_ERR_MSK_Msk    (0x1U << USB_DOEPEACHMSK0_DOEP_EACHMSK0_AHB_ERR_MSK_Pos)                    /*!< DOEP_EACHMSK0_AHB_ERR_MSK Mask      */
#define USB_DOEPEACHMSK0_DOEP_EACHMSK0_AHB_ERR_MSK_Set(x) (((uint32_t) (x) << USB_DOEPEACHMSK0_DOEP_EACHMSK0_AHB_ERR_MSK_Pos) & USB_DOEPEACHMSK0_DOEP_EACHMSK0_AHB_ERR_MSK_Msk) /*!< DOEP_EACHMSK0_AHB_ERR_MSK Set Value */
#define USB_DOEPEACHMSK0_DOEP_EACHMSK0_AHB_ERR_MSK_Get(x) (((uint32_t) (x) & USB_DOEPEACHMSK0_DOEP_EACHMSK0_AHB_ERR_MSK_Msk) >> USB_DOEPEACHMSK0_DOEP_EACHMSK0_AHB_ERR_MSK_Pos) /*!< DOEP_EACHMSK0_AHB_ERR_MSK Get Value */


#define USB_DOEPEACHMSK0_DOEP_EACHMSK0_EP_DISBLD_MSK_Pos    (1U)                                                                        /*!< DOEP_EACHMSK0_EP_DISBLD_MSK Postion   */ 
#define USB_DOEPEACHMSK0_DOEP_EACHMSK0_EP_DISBLD_MSK_Msk    (0x1U << USB_DOEPEACHMSK0_DOEP_EACHMSK0_EP_DISBLD_MSK_Pos)                  /*!< DOEP_EACHMSK0_EP_DISBLD_MSK Mask      */
#define USB_DOEPEACHMSK0_DOEP_EACHMSK0_EP_DISBLD_MSK_Set(x) (((uint32_t) (x) << USB_DOEPEACHMSK0_DOEP_EACHMSK0_EP_DISBLD_MSK_Pos) & USB_DOEPEACHMSK0_DOEP_EACHMSK0_EP_DISBLD_MSK_Msk) /*!< DOEP_EACHMSK0_EP_DISBLD_MSK Set Value */
#define USB_DOEPEACHMSK0_DOEP_EACHMSK0_EP_DISBLD_MSK_Get(x) (((uint32_t) (x) & USB_DOEPEACHMSK0_DOEP_EACHMSK0_EP_DISBLD_MSK_Msk) >> USB_DOEPEACHMSK0_DOEP_EACHMSK0_EP_DISBLD_MSK_Pos) /*!< DOEP_EACHMSK0_EP_DISBLD_MSK Get Value */


#define USB_DOEPEACHMSK0_DOEP_EACHMSK0_XFER_COMPL_MSK_Pos    (0U)                                                                        /*!< DOEP_EACHMSK0_XFER_COMPL_MSK Postion   */ 
#define USB_DOEPEACHMSK0_DOEP_EACHMSK0_XFER_COMPL_MSK_Msk    (0x1U << USB_DOEPEACHMSK0_DOEP_EACHMSK0_XFER_COMPL_MSK_Pos)                 /*!< DOEP_EACHMSK0_XFER_COMPL_MSK Mask      */
#define USB_DOEPEACHMSK0_DOEP_EACHMSK0_XFER_COMPL_MSK_Set(x) (((uint32_t) (x) << USB_DOEPEACHMSK0_DOEP_EACHMSK0_XFER_COMPL_MSK_Pos) & USB_DOEPEACHMSK0_DOEP_EACHMSK0_XFER_COMPL_MSK_Msk) /*!< DOEP_EACHMSK0_XFER_COMPL_MSK Set Value */
#define USB_DOEPEACHMSK0_DOEP_EACHMSK0_XFER_COMPL_MSK_Get(x) (((uint32_t) (x) & USB_DOEPEACHMSK0_DOEP_EACHMSK0_XFER_COMPL_MSK_Msk) >> USB_DOEPEACHMSK0_DOEP_EACHMSK0_XFER_COMPL_MSK_Pos) /*!< DOEP_EACHMSK0_XFER_COMPL_MSK Get Value */


/* DIEPCTL0 bitfield */
#define USB_DIEPCTL0_DIEP_CTL0_EP_ENA_Pos    (31U)                                                                       /*!< DIEP_CTL0_EP_ENA Postion   */ 
#define USB_DIEPCTL0_DIEP_CTL0_EP_ENA_Msk    (0x1U << USB_DIEPCTL0_DIEP_CTL0_EP_ENA_Pos)                                 /*!< DIEP_CTL0_EP_ENA Mask      */
#define USB_DIEPCTL0_DIEP_CTL0_EP_ENA_Set(x) (((uint32_t) (x) << USB_DIEPCTL0_DIEP_CTL0_EP_ENA_Pos) & USB_DIEPCTL0_DIEP_CTL0_EP_ENA_Msk) /*!< DIEP_CTL0_EP_ENA Set Value */
#define USB_DIEPCTL0_DIEP_CTL0_EP_ENA_Get(x) (((uint32_t) (x) & USB_DIEPCTL0_DIEP_CTL0_EP_ENA_Msk) >> USB_DIEPCTL0_DIEP_CTL0_EP_ENA_Pos) /*!< DIEP_CTL0_EP_ENA Get Value */


#define USB_DIEPCTL0_DIEP_CTL0_EP_DIS_Pos    (30U)                                                                       /*!< DIEP_CTL0_EP_DIS Postion   */ 
#define USB_DIEPCTL0_DIEP_CTL0_EP_DIS_Msk    (0x1U << USB_DIEPCTL0_DIEP_CTL0_EP_DIS_Pos)                                 /*!< DIEP_CTL0_EP_DIS Mask      */
#define USB_DIEPCTL0_DIEP_CTL0_EP_DIS_Set(x) (((uint32_t) (x) << USB_DIEPCTL0_DIEP_CTL0_EP_DIS_Pos) & USB_DIEPCTL0_DIEP_CTL0_EP_DIS_Msk) /*!< DIEP_CTL0_EP_DIS Set Value */
#define USB_DIEPCTL0_DIEP_CTL0_EP_DIS_Get(x) (((uint32_t) (x) & USB_DIEPCTL0_DIEP_CTL0_EP_DIS_Msk) >> USB_DIEPCTL0_DIEP_CTL0_EP_DIS_Pos) /*!< DIEP_CTL0_EP_DIS Get Value */


#define USB_DIEPCTL0_DIEP_CTL0_SNAK_Pos    (27U)                                                                       /*!< DIEP_CTL0_SNAK Postion   */ 
#define USB_DIEPCTL0_DIEP_CTL0_SNAK_Msk    (0x1U << USB_DIEPCTL0_DIEP_CTL0_SNAK_Pos)                                   /*!< DIEP_CTL0_SNAK Mask      */
#define USB_DIEPCTL0_DIEP_CTL0_SNAK_Set(x) (((uint32_t) (x) << USB_DIEPCTL0_DIEP_CTL0_SNAK_Pos) & USB_DIEPCTL0_DIEP_CTL0_SNAK_Msk) /*!< DIEP_CTL0_SNAK Set Value */
#define USB_DIEPCTL0_DIEP_CTL0_SNAK_Get(x) (((uint32_t) (x) & USB_DIEPCTL0_DIEP_CTL0_SNAK_Msk) >> USB_DIEPCTL0_DIEP_CTL0_SNAK_Pos) /*!< DIEP_CTL0_SNAK Get Value */


#define USB_DIEPCTL0_DIEP_CTL0_CNAK_Pos    (26U)                                                                       /*!< DIEP_CTL0_CNAK Postion   */ 
#define USB_DIEPCTL0_DIEP_CTL0_CNAK_Msk    (0x1U << USB_DIEPCTL0_DIEP_CTL0_CNAK_Pos)                                   /*!< DIEP_CTL0_CNAK Mask      */
#define USB_DIEPCTL0_DIEP_CTL0_CNAK_Set(x) (((uint32_t) (x) << USB_DIEPCTL0_DIEP_CTL0_CNAK_Pos) & USB_DIEPCTL0_DIEP_CTL0_CNAK_Msk) /*!< DIEP_CTL0_CNAK Set Value */
#define USB_DIEPCTL0_DIEP_CTL0_CNAK_Get(x) (((uint32_t) (x) & USB_DIEPCTL0_DIEP_CTL0_CNAK_Msk) >> USB_DIEPCTL0_DIEP_CTL0_CNAK_Pos) /*!< DIEP_CTL0_CNAK Get Value */


#define USB_DIEPCTL0_DIEP_CTL0_TXF_NUM_Pos    (22U)                                                                       /*!< DIEP_CTL0_TXF_NUM Postion   */ 
#define USB_DIEPCTL0_DIEP_CTL0_TXF_NUM_Msk    (0xfU << USB_DIEPCTL0_DIEP_CTL0_TXF_NUM_Pos)                                /*!< DIEP_CTL0_TXF_NUM Mask      */
#define USB_DIEPCTL0_DIEP_CTL0_TXF_NUM_Set(x) (((uint32_t) (x) << USB_DIEPCTL0_DIEP_CTL0_TXF_NUM_Pos) & USB_DIEPCTL0_DIEP_CTL0_TXF_NUM_Msk) /*!< DIEP_CTL0_TXF_NUM Set Value */
#define USB_DIEPCTL0_DIEP_CTL0_TXF_NUM_Get(x) (((uint32_t) (x) & USB_DIEPCTL0_DIEP_CTL0_TXF_NUM_Msk) >> USB_DIEPCTL0_DIEP_CTL0_TXF_NUM_Pos) /*!< DIEP_CTL0_TXF_NUM Get Value */


#define USB_DIEPCTL0_DIEP_CTL0_STALL_Pos    (21U)                                                                       /*!< DIEP_CTL0_STALL Postion   */ 
#define USB_DIEPCTL0_DIEP_CTL0_STALL_Msk    (0x1U << USB_DIEPCTL0_DIEP_CTL0_STALL_Pos)                                  /*!< DIEP_CTL0_STALL Mask      */
#define USB_DIEPCTL0_DIEP_CTL0_STALL_Set(x) (((uint32_t) (x) << USB_DIEPCTL0_DIEP_CTL0_STALL_Pos) & USB_DIEPCTL0_DIEP_CTL0_STALL_Msk) /*!< DIEP_CTL0_STALL Set Value */
#define USB_DIEPCTL0_DIEP_CTL0_STALL_Get(x) (((uint32_t) (x) & USB_DIEPCTL0_DIEP_CTL0_STALL_Msk) >> USB_DIEPCTL0_DIEP_CTL0_STALL_Pos) /*!< DIEP_CTL0_STALL Get Value */


#define USB_DIEPCTL0_DIEP_CTL0_EP_TYPE_Pos    (18U)                                                                       /*!< DIEP_CTL0_EP_TYPE Postion   */ 
#define USB_DIEPCTL0_DIEP_CTL0_EP_TYPE_Msk    (0x3U << USB_DIEPCTL0_DIEP_CTL0_EP_TYPE_Pos)                                /*!< DIEP_CTL0_EP_TYPE Mask      */
#define USB_DIEPCTL0_DIEP_CTL0_EP_TYPE_Set(x) (((uint32_t) (x) << USB_DIEPCTL0_DIEP_CTL0_EP_TYPE_Pos) & USB_DIEPCTL0_DIEP_CTL0_EP_TYPE_Msk) /*!< DIEP_CTL0_EP_TYPE Set Value */
#define USB_DIEPCTL0_DIEP_CTL0_EP_TYPE_Get(x) (((uint32_t) (x) & USB_DIEPCTL0_DIEP_CTL0_EP_TYPE_Msk) >> USB_DIEPCTL0_DIEP_CTL0_EP_TYPE_Pos) /*!< DIEP_CTL0_EP_TYPE Get Value */


#define USB_DIEPCTL0_DIEP_CTL0_NAKSTS_Pos    (17U)                                                                       /*!< DIEP_CTL0_NAKSTS Postion   */ 
#define USB_DIEPCTL0_DIEP_CTL0_NAKSTS_Msk    (0x1U << USB_DIEPCTL0_DIEP_CTL0_NAKSTS_Pos)                                 /*!< DIEP_CTL0_NAKSTS Mask      */
#define USB_DIEPCTL0_DIEP_CTL0_NAKSTS_Set(x) (((uint32_t) (x) << USB_DIEPCTL0_DIEP_CTL0_NAKSTS_Pos) & USB_DIEPCTL0_DIEP_CTL0_NAKSTS_Msk) /*!< DIEP_CTL0_NAKSTS Set Value */
#define USB_DIEPCTL0_DIEP_CTL0_NAKSTS_Get(x) (((uint32_t) (x) & USB_DIEPCTL0_DIEP_CTL0_NAKSTS_Msk) >> USB_DIEPCTL0_DIEP_CTL0_NAKSTS_Pos) /*!< DIEP_CTL0_NAKSTS Get Value */


#define USB_DIEPCTL0_DIEP_CTL0_USB_ACT_EP_Pos    (15U)                                                                       /*!< DIEP_CTL0_USB_ACT_EP Postion   */ 
#define USB_DIEPCTL0_DIEP_CTL0_USB_ACT_EP_Msk    (0x1U << USB_DIEPCTL0_DIEP_CTL0_USB_ACT_EP_Pos)                             /*!< DIEP_CTL0_USB_ACT_EP Mask      */
#define USB_DIEPCTL0_DIEP_CTL0_USB_ACT_EP_Set(x) (((uint32_t) (x) << USB_DIEPCTL0_DIEP_CTL0_USB_ACT_EP_Pos) & USB_DIEPCTL0_DIEP_CTL0_USB_ACT_EP_Msk) /*!< DIEP_CTL0_USB_ACT_EP Set Value */
#define USB_DIEPCTL0_DIEP_CTL0_USB_ACT_EP_Get(x) (((uint32_t) (x) & USB_DIEPCTL0_DIEP_CTL0_USB_ACT_EP_Msk) >> USB_DIEPCTL0_DIEP_CTL0_USB_ACT_EP_Pos) /*!< DIEP_CTL0_USB_ACT_EP Get Value */


#define USB_DIEPCTL0_DIEP_CTL0_MPS_Pos    (0U)                                                                        /*!< DIEP_CTL0_MPS Postion   */ 
#define USB_DIEPCTL0_DIEP_CTL0_MPS_Msk    (0x3U << USB_DIEPCTL0_DIEP_CTL0_MPS_Pos)                                    /*!< DIEP_CTL0_MPS Mask      */
#define USB_DIEPCTL0_DIEP_CTL0_MPS_Set(x) (((uint32_t) (x) << USB_DIEPCTL0_DIEP_CTL0_MPS_Pos) & USB_DIEPCTL0_DIEP_CTL0_MPS_Msk) /*!< DIEP_CTL0_MPS Set Value */
#define USB_DIEPCTL0_DIEP_CTL0_MPS_Get(x) (((uint32_t) (x) & USB_DIEPCTL0_DIEP_CTL0_MPS_Msk) >> USB_DIEPCTL0_DIEP_CTL0_MPS_Pos) /*!< DIEP_CTL0_MPS Get Value */


/* DIEPINT0 bitfield */
#define USB_DIEPINT0_DIEP_IN_T0_NYETINTRPT_Pos    (14U)                                                                       /*!< DIEP_IN_T0_NYETINTRPT Postion   */ 
#define USB_DIEPINT0_DIEP_IN_T0_NYETINTRPT_Msk    (0x1U << USB_DIEPINT0_DIEP_IN_T0_NYETINTRPT_Pos)                            /*!< DIEP_IN_T0_NYETINTRPT Mask      */
#define USB_DIEPINT0_DIEP_IN_T0_NYETINTRPT_Set(x) (((uint32_t) (x) << USB_DIEPINT0_DIEP_IN_T0_NYETINTRPT_Pos) & USB_DIEPINT0_DIEP_IN_T0_NYETINTRPT_Msk) /*!< DIEP_IN_T0_NYETINTRPT Set Value */
#define USB_DIEPINT0_DIEP_IN_T0_NYETINTRPT_Get(x) (((uint32_t) (x) & USB_DIEPINT0_DIEP_IN_T0_NYETINTRPT_Msk) >> USB_DIEPINT0_DIEP_IN_T0_NYETINTRPT_Pos) /*!< DIEP_IN_T0_NYETINTRPT Get Value */


#define USB_DIEPINT0_DIEP_IN_T0_NAKINTRPT_Pos    (13U)                                                                       /*!< DIEP_IN_T0_NAKINTRPT Postion   */ 
#define USB_DIEPINT0_DIEP_IN_T0_NAKINTRPT_Msk    (0x1U << USB_DIEPINT0_DIEP_IN_T0_NAKINTRPT_Pos)                             /*!< DIEP_IN_T0_NAKINTRPT Mask      */
#define USB_DIEPINT0_DIEP_IN_T0_NAKINTRPT_Set(x) (((uint32_t) (x) << USB_DIEPINT0_DIEP_IN_T0_NAKINTRPT_Pos) & USB_DIEPINT0_DIEP_IN_T0_NAKINTRPT_Msk) /*!< DIEP_IN_T0_NAKINTRPT Set Value */
#define USB_DIEPINT0_DIEP_IN_T0_NAKINTRPT_Get(x) (((uint32_t) (x) & USB_DIEPINT0_DIEP_IN_T0_NAKINTRPT_Msk) >> USB_DIEPINT0_DIEP_IN_T0_NAKINTRPT_Pos) /*!< DIEP_IN_T0_NAKINTRPT Get Value */


#define USB_DIEPINT0_DIEP_IN_T0_BBLE_ERR_Pos    (12U)                                                                       /*!< DIEP_IN_T0_BBLE_ERR Postion   */ 
#define USB_DIEPINT0_DIEP_IN_T0_BBLE_ERR_Msk    (0x1U << USB_DIEPINT0_DIEP_IN_T0_BBLE_ERR_Pos)                              /*!< DIEP_IN_T0_BBLE_ERR Mask      */
#define USB_DIEPINT0_DIEP_IN_T0_BBLE_ERR_Set(x) (((uint32_t) (x) << USB_DIEPINT0_DIEP_IN_T0_BBLE_ERR_Pos) & USB_DIEPINT0_DIEP_IN_T0_BBLE_ERR_Msk) /*!< DIEP_IN_T0_BBLE_ERR Set Value */
#define USB_DIEPINT0_DIEP_IN_T0_BBLE_ERR_Get(x) (((uint32_t) (x) & USB_DIEPINT0_DIEP_IN_T0_BBLE_ERR_Msk) >> USB_DIEPINT0_DIEP_IN_T0_BBLE_ERR_Pos) /*!< DIEP_IN_T0_BBLE_ERR Get Value */


#define USB_DIEPINT0_DIEP_IN_T0_PKT_DRP_STS_Pos    (11U)                                                                       /*!< DIEP_IN_T0_PKT_DRP_STS Postion   */ 
#define USB_DIEPINT0_DIEP_IN_T0_PKT_DRP_STS_Msk    (0x1U << USB_DIEPINT0_DIEP_IN_T0_PKT_DRP_STS_Pos)                           /*!< DIEP_IN_T0_PKT_DRP_STS Mask      */
#define USB_DIEPINT0_DIEP_IN_T0_PKT_DRP_STS_Set(x) (((uint32_t) (x) << USB_DIEPINT0_DIEP_IN_T0_PKT_DRP_STS_Pos) & USB_DIEPINT0_DIEP_IN_T0_PKT_DRP_STS_Msk) /*!< DIEP_IN_T0_PKT_DRP_STS Set Value */
#define USB_DIEPINT0_DIEP_IN_T0_PKT_DRP_STS_Get(x) (((uint32_t) (x) & USB_DIEPINT0_DIEP_IN_T0_PKT_DRP_STS_Msk) >> USB_DIEPINT0_DIEP_IN_T0_PKT_DRP_STS_Pos) /*!< DIEP_IN_T0_PKT_DRP_STS Get Value */


#define USB_DIEPINT0_DIEP_IN_T0_BNAINTR_Pos    (9U)                                                                        /*!< DIEP_IN_T0_BNAINTR Postion   */ 
#define USB_DIEPINT0_DIEP_IN_T0_BNAINTR_Msk    (0x1U << USB_DIEPINT0_DIEP_IN_T0_BNAINTR_Pos)                               /*!< DIEP_IN_T0_BNAINTR Mask      */
#define USB_DIEPINT0_DIEP_IN_T0_BNAINTR_Set(x) (((uint32_t) (x) << USB_DIEPINT0_DIEP_IN_T0_BNAINTR_Pos) & USB_DIEPINT0_DIEP_IN_T0_BNAINTR_Msk) /*!< DIEP_IN_T0_BNAINTR Set Value */
#define USB_DIEPINT0_DIEP_IN_T0_BNAINTR_Get(x) (((uint32_t) (x) & USB_DIEPINT0_DIEP_IN_T0_BNAINTR_Msk) >> USB_DIEPINT0_DIEP_IN_T0_BNAINTR_Pos) /*!< DIEP_IN_T0_BNAINTR Get Value */


#define USB_DIEPINT0_DIEP_IN_T0_TXFIFO_UNDRN_Pos    (8U)                                                                        /*!< DIEP_IN_T0_TXFIFO_UNDRN Postion   */ 
#define USB_DIEPINT0_DIEP_IN_T0_TXFIFO_UNDRN_Msk    (0x1U << USB_DIEPINT0_DIEP_IN_T0_TXFIFO_UNDRN_Pos)                          /*!< DIEP_IN_T0_TXFIFO_UNDRN Mask      */
#define USB_DIEPINT0_DIEP_IN_T0_TXFIFO_UNDRN_Set(x) (((uint32_t) (x) << USB_DIEPINT0_DIEP_IN_T0_TXFIFO_UNDRN_Pos) & USB_DIEPINT0_DIEP_IN_T0_TXFIFO_UNDRN_Msk) /*!< DIEP_IN_T0_TXFIFO_UNDRN Set Value */
#define USB_DIEPINT0_DIEP_IN_T0_TXFIFO_UNDRN_Get(x) (((uint32_t) (x) & USB_DIEPINT0_DIEP_IN_T0_TXFIFO_UNDRN_Msk) >> USB_DIEPINT0_DIEP_IN_T0_TXFIFO_UNDRN_Pos) /*!< DIEP_IN_T0_TXFIFO_UNDRN Get Value */


#define USB_DIEPINT0_DIEP_IN_T0_TXF_EMP_Pos    (7U)                                                                        /*!< DIEP_IN_T0_TXF_EMP Postion   */ 
#define USB_DIEPINT0_DIEP_IN_T0_TXF_EMP_Msk    (0x1U << USB_DIEPINT0_DIEP_IN_T0_TXF_EMP_Pos)                               /*!< DIEP_IN_T0_TXF_EMP Mask      */
#define USB_DIEPINT0_DIEP_IN_T0_TXF_EMP_Set(x) (((uint32_t) (x) << USB_DIEPINT0_DIEP_IN_T0_TXF_EMP_Pos) & USB_DIEPINT0_DIEP_IN_T0_TXF_EMP_Msk) /*!< DIEP_IN_T0_TXF_EMP Set Value */
#define USB_DIEPINT0_DIEP_IN_T0_TXF_EMP_Get(x) (((uint32_t) (x) & USB_DIEPINT0_DIEP_IN_T0_TXF_EMP_Msk) >> USB_DIEPINT0_DIEP_IN_T0_TXF_EMP_Pos) /*!< DIEP_IN_T0_TXF_EMP Get Value */


#define USB_DIEPINT0_DIEP_IN_T0_IN_EP_NAK_EFF_Pos    (6U)                                                                        /*!< DIEP_IN_T0_IN_EP_NAK_EFF Postion   */ 
#define USB_DIEPINT0_DIEP_IN_T0_IN_EP_NAK_EFF_Msk    (0x1U << USB_DIEPINT0_DIEP_IN_T0_IN_EP_NAK_EFF_Pos)                         /*!< DIEP_IN_T0_IN_EP_NAK_EFF Mask      */
#define USB_DIEPINT0_DIEP_IN_T0_IN_EP_NAK_EFF_Set(x) (((uint32_t) (x) << USB_DIEPINT0_DIEP_IN_T0_IN_EP_NAK_EFF_Pos) & USB_DIEPINT0_DIEP_IN_T0_IN_EP_NAK_EFF_Msk) /*!< DIEP_IN_T0_IN_EP_NAK_EFF Set Value */
#define USB_DIEPINT0_DIEP_IN_T0_IN_EP_NAK_EFF_Get(x) (((uint32_t) (x) & USB_DIEPINT0_DIEP_IN_T0_IN_EP_NAK_EFF_Msk) >> USB_DIEPINT0_DIEP_IN_T0_IN_EP_NAK_EFF_Pos) /*!< DIEP_IN_T0_IN_EP_NAK_EFF Get Value */


#define USB_DIEPINT0_DIEP_IN_T0_IN_TKN_EP_MIS_Pos    (5U)                                                                        /*!< DIEP_IN_T0_IN_TKN_EP_MIS Postion   */ 
#define USB_DIEPINT0_DIEP_IN_T0_IN_TKN_EP_MIS_Msk    (0x1U << USB_DIEPINT0_DIEP_IN_T0_IN_TKN_EP_MIS_Pos)                         /*!< DIEP_IN_T0_IN_TKN_EP_MIS Mask      */
#define USB_DIEPINT0_DIEP_IN_T0_IN_TKN_EP_MIS_Set(x) (((uint32_t) (x) << USB_DIEPINT0_DIEP_IN_T0_IN_TKN_EP_MIS_Pos) & USB_DIEPINT0_DIEP_IN_T0_IN_TKN_EP_MIS_Msk) /*!< DIEP_IN_T0_IN_TKN_EP_MIS Set Value */
#define USB_DIEPINT0_DIEP_IN_T0_IN_TKN_EP_MIS_Get(x) (((uint32_t) (x) & USB_DIEPINT0_DIEP_IN_T0_IN_TKN_EP_MIS_Msk) >> USB_DIEPINT0_DIEP_IN_T0_IN_TKN_EP_MIS_Pos) /*!< DIEP_IN_T0_IN_TKN_EP_MIS Get Value */


#define USB_DIEPINT0_DIEP_IN_T0_IN_TKN_TXFEMP_Pos    (4U)                                                                        /*!< DIEP_IN_T0_IN_TKN_TXFEMP Postion   */ 
#define USB_DIEPINT0_DIEP_IN_T0_IN_TKN_TXFEMP_Msk    (0x1U << USB_DIEPINT0_DIEP_IN_T0_IN_TKN_TXFEMP_Pos)                         /*!< DIEP_IN_T0_IN_TKN_TXFEMP Mask      */
#define USB_DIEPINT0_DIEP_IN_T0_IN_TKN_TXFEMP_Set(x) (((uint32_t) (x) << USB_DIEPINT0_DIEP_IN_T0_IN_TKN_TXFEMP_Pos) & USB_DIEPINT0_DIEP_IN_T0_IN_TKN_TXFEMP_Msk) /*!< DIEP_IN_T0_IN_TKN_TXFEMP Set Value */
#define USB_DIEPINT0_DIEP_IN_T0_IN_TKN_TXFEMP_Get(x) (((uint32_t) (x) & USB_DIEPINT0_DIEP_IN_T0_IN_TKN_TXFEMP_Msk) >> USB_DIEPINT0_DIEP_IN_T0_IN_TKN_TXFEMP_Pos) /*!< DIEP_IN_T0_IN_TKN_TXFEMP Get Value */


#define USB_DIEPINT0_DIEP_IN_T0_TIME_OUT_Pos    (3U)                                                                        /*!< DIEP_IN_T0_TIME_OUT Postion   */ 
#define USB_DIEPINT0_DIEP_IN_T0_TIME_OUT_Msk    (0x1U << USB_DIEPINT0_DIEP_IN_T0_TIME_OUT_Pos)                              /*!< DIEP_IN_T0_TIME_OUT Mask      */
#define USB_DIEPINT0_DIEP_IN_T0_TIME_OUT_Set(x) (((uint32_t) (x) << USB_DIEPINT0_DIEP_IN_T0_TIME_OUT_Pos) & USB_DIEPINT0_DIEP_IN_T0_TIME_OUT_Msk) /*!< DIEP_IN_T0_TIME_OUT Set Value */
#define USB_DIEPINT0_DIEP_IN_T0_TIME_OUT_Get(x) (((uint32_t) (x) & USB_DIEPINT0_DIEP_IN_T0_TIME_OUT_Msk) >> USB_DIEPINT0_DIEP_IN_T0_TIME_OUT_Pos) /*!< DIEP_IN_T0_TIME_OUT Get Value */


#define USB_DIEPINT0_DIEP_IN_T0_AHB_ERR_Pos    (2U)                                                                        /*!< DIEP_IN_T0_AHB_ERR Postion   */ 
#define USB_DIEPINT0_DIEP_IN_T0_AHB_ERR_Msk    (0x1U << USB_DIEPINT0_DIEP_IN_T0_AHB_ERR_Pos)                               /*!< DIEP_IN_T0_AHB_ERR Mask      */
#define USB_DIEPINT0_DIEP_IN_T0_AHB_ERR_Set(x) (((uint32_t) (x) << USB_DIEPINT0_DIEP_IN_T0_AHB_ERR_Pos) & USB_DIEPINT0_DIEP_IN_T0_AHB_ERR_Msk) /*!< DIEP_IN_T0_AHB_ERR Set Value */
#define USB_DIEPINT0_DIEP_IN_T0_AHB_ERR_Get(x) (((uint32_t) (x) & USB_DIEPINT0_DIEP_IN_T0_AHB_ERR_Msk) >> USB_DIEPINT0_DIEP_IN_T0_AHB_ERR_Pos) /*!< DIEP_IN_T0_AHB_ERR Get Value */


#define USB_DIEPINT0_DIEP_IN_T0_EP_DISBLD_Pos    (1U)                                                                        /*!< DIEP_IN_T0_EP_DISBLD Postion   */ 
#define USB_DIEPINT0_DIEP_IN_T0_EP_DISBLD_Msk    (0x1U << USB_DIEPINT0_DIEP_IN_T0_EP_DISBLD_Pos)                             /*!< DIEP_IN_T0_EP_DISBLD Mask      */
#define USB_DIEPINT0_DIEP_IN_T0_EP_DISBLD_Set(x) (((uint32_t) (x) << USB_DIEPINT0_DIEP_IN_T0_EP_DISBLD_Pos) & USB_DIEPINT0_DIEP_IN_T0_EP_DISBLD_Msk) /*!< DIEP_IN_T0_EP_DISBLD Set Value */
#define USB_DIEPINT0_DIEP_IN_T0_EP_DISBLD_Get(x) (((uint32_t) (x) & USB_DIEPINT0_DIEP_IN_T0_EP_DISBLD_Msk) >> USB_DIEPINT0_DIEP_IN_T0_EP_DISBLD_Pos) /*!< DIEP_IN_T0_EP_DISBLD Get Value */


#define USB_DIEPINT0_DIEP_IN_T0_XFER_COMPL_Pos    (0U)                                                                        /*!< DIEP_IN_T0_XFER_COMPL Postion   */ 
#define USB_DIEPINT0_DIEP_IN_T0_XFER_COMPL_Msk    (0x1U << USB_DIEPINT0_DIEP_IN_T0_XFER_COMPL_Pos)                            /*!< DIEP_IN_T0_XFER_COMPL Mask      */
#define USB_DIEPINT0_DIEP_IN_T0_XFER_COMPL_Set(x) (((uint32_t) (x) << USB_DIEPINT0_DIEP_IN_T0_XFER_COMPL_Pos) & USB_DIEPINT0_DIEP_IN_T0_XFER_COMPL_Msk) /*!< DIEP_IN_T0_XFER_COMPL Set Value */
#define USB_DIEPINT0_DIEP_IN_T0_XFER_COMPL_Get(x) (((uint32_t) (x) & USB_DIEPINT0_DIEP_IN_T0_XFER_COMPL_Msk) >> USB_DIEPINT0_DIEP_IN_T0_XFER_COMPL_Pos) /*!< DIEP_IN_T0_XFER_COMPL Get Value */


/* DIEPTSIZ0 bitfield */
#define USB_DIEPTSIZ0_DIEP_TSIZ0_PKT_CNT_Pos    (19U)                                                                       /*!< DIEP_TSIZ0_PKT_CNT Postion   */ 
#define USB_DIEPTSIZ0_DIEP_TSIZ0_PKT_CNT_Msk    (0x3U << USB_DIEPTSIZ0_DIEP_TSIZ0_PKT_CNT_Pos)                              /*!< DIEP_TSIZ0_PKT_CNT Mask      */
#define USB_DIEPTSIZ0_DIEP_TSIZ0_PKT_CNT_Set(x) (((uint32_t) (x) << USB_DIEPTSIZ0_DIEP_TSIZ0_PKT_CNT_Pos) & USB_DIEPTSIZ0_DIEP_TSIZ0_PKT_CNT_Msk) /*!< DIEP_TSIZ0_PKT_CNT Set Value */
#define USB_DIEPTSIZ0_DIEP_TSIZ0_PKT_CNT_Get(x) (((uint32_t) (x) & USB_DIEPTSIZ0_DIEP_TSIZ0_PKT_CNT_Msk) >> USB_DIEPTSIZ0_DIEP_TSIZ0_PKT_CNT_Pos) /*!< DIEP_TSIZ0_PKT_CNT Get Value */


#define USB_DIEPTSIZ0_DIEP_TSIZ0_XFER_SIZE_Pos    (0U)                                                                        /*!< DIEP_TSIZ0_XFER_SIZE Postion   */ 
#define USB_DIEPTSIZ0_DIEP_TSIZ0_XFER_SIZE_Msk    (0x7fU << USB_DIEPTSIZ0_DIEP_TSIZ0_XFER_SIZE_Pos)                           /*!< DIEP_TSIZ0_XFER_SIZE Mask      */
#define USB_DIEPTSIZ0_DIEP_TSIZ0_XFER_SIZE_Set(x) (((uint32_t) (x) << USB_DIEPTSIZ0_DIEP_TSIZ0_XFER_SIZE_Pos) & USB_DIEPTSIZ0_DIEP_TSIZ0_XFER_SIZE_Msk) /*!< DIEP_TSIZ0_XFER_SIZE Set Value */
#define USB_DIEPTSIZ0_DIEP_TSIZ0_XFER_SIZE_Get(x) (((uint32_t) (x) & USB_DIEPTSIZ0_DIEP_TSIZ0_XFER_SIZE_Msk) >> USB_DIEPTSIZ0_DIEP_TSIZ0_XFER_SIZE_Pos) /*!< DIEP_TSIZ0_XFER_SIZE Get Value */


/* DIEPDMA0 bitfield */
#define USB_DIEPDMA0_DIEP_DMA0_DMA_ADDR_Pos    (0U)                                                                        /*!< DIEP_DMA0_DMA_ADDR Postion   */ 
#define USB_DIEPDMA0_DIEP_DMA0_DMA_ADDR_Msk    (0xffffffffU << USB_DIEPDMA0_DIEP_DMA0_DMA_ADDR_Pos)                        /*!< DIEP_DMA0_DMA_ADDR Mask      */
#define USB_DIEPDMA0_DIEP_DMA0_DMA_ADDR_Set(x) (((uint32_t) (x) << USB_DIEPDMA0_DIEP_DMA0_DMA_ADDR_Pos) & USB_DIEPDMA0_DIEP_DMA0_DMA_ADDR_Msk) /*!< DIEP_DMA0_DMA_ADDR Set Value */
#define USB_DIEPDMA0_DIEP_DMA0_DMA_ADDR_Get(x) (((uint32_t) (x) & USB_DIEPDMA0_DIEP_DMA0_DMA_ADDR_Msk) >> USB_DIEPDMA0_DIEP_DMA0_DMA_ADDR_Pos) /*!< DIEP_DMA0_DMA_ADDR Get Value */


/* DTXFSTS0 bitfield */
#define USB_DTXFSTS0_DTXFS_TS0_IN_EP_TXF_SPC_AVAIL_Pos    (0U)                                                                        /*!< DTXFS_TS0_IN_EP_TXF_SPC_AVAIL Postion   */ 
#define USB_DTXFSTS0_DTXFS_TS0_IN_EP_TXF_SPC_AVAIL_Msk    (0xffffU << USB_DTXFSTS0_DTXFS_TS0_IN_EP_TXF_SPC_AVAIL_Pos)                 /*!< DTXFS_TS0_IN_EP_TXF_SPC_AVAIL Mask      */
#define USB_DTXFSTS0_DTXFS_TS0_IN_EP_TXF_SPC_AVAIL_Set(x) (((uint32_t) (x) << USB_DTXFSTS0_DTXFS_TS0_IN_EP_TXF_SPC_AVAIL_Pos) & USB_DTXFSTS0_DTXFS_TS0_IN_EP_TXF_SPC_AVAIL_Msk) /*!< DTXFS_TS0_IN_EP_TXF_SPC_AVAIL Set Value */
#define USB_DTXFSTS0_DTXFS_TS0_IN_EP_TXF_SPC_AVAIL_Get(x) (((uint32_t) (x) & USB_DTXFSTS0_DTXFS_TS0_IN_EP_TXF_SPC_AVAIL_Msk) >> USB_DTXFSTS0_DTXFS_TS0_IN_EP_TXF_SPC_AVAIL_Pos) /*!< DTXFS_TS0_IN_EP_TXF_SPC_AVAIL Get Value */


/* DIEPDMAB0 bitfield */
#define USB_DIEPDMAB0_DTXFS_TS0_DMA_BUFFER_ADDR_Pos    (0U)                                                                        /*!< DTXFS_TS0_DMA_BUFFER_ADDR Postion   */ 
#define USB_DIEPDMAB0_DTXFS_TS0_DMA_BUFFER_ADDR_Msk    (0xffffffffU << USB_DIEPDMAB0_DTXFS_TS0_DMA_BUFFER_ADDR_Pos)                /*!< DTXFS_TS0_DMA_BUFFER_ADDR Mask      */
#define USB_DIEPDMAB0_DTXFS_TS0_DMA_BUFFER_ADDR_Set(x) (((uint32_t) (x) << USB_DIEPDMAB0_DTXFS_TS0_DMA_BUFFER_ADDR_Pos) & USB_DIEPDMAB0_DTXFS_TS0_DMA_BUFFER_ADDR_Msk) /*!< DTXFS_TS0_DMA_BUFFER_ADDR Set Value */
#define USB_DIEPDMAB0_DTXFS_TS0_DMA_BUFFER_ADDR_Get(x) (((uint32_t) (x) & USB_DIEPDMAB0_DTXFS_TS0_DMA_BUFFER_ADDR_Msk) >> USB_DIEPDMAB0_DTXFS_TS0_DMA_BUFFER_ADDR_Pos) /*!< DTXFS_TS0_DMA_BUFFER_ADDR Get Value */


/* DOEPCTL0 bitfield */
#define USB_DOEPCTL0_DOEP_CTL0_EP_ENA_Pos    (31U)                                                                       /*!< DOEP_CTL0_EP_ENA Postion   */ 
#define USB_DOEPCTL0_DOEP_CTL0_EP_ENA_Msk    (0x1U << USB_DOEPCTL0_DOEP_CTL0_EP_ENA_Pos)                                 /*!< DOEP_CTL0_EP_ENA Mask      */
#define USB_DOEPCTL0_DOEP_CTL0_EP_ENA_Set(x) (((uint32_t) (x) << USB_DOEPCTL0_DOEP_CTL0_EP_ENA_Pos) & USB_DOEPCTL0_DOEP_CTL0_EP_ENA_Msk) /*!< DOEP_CTL0_EP_ENA Set Value */
#define USB_DOEPCTL0_DOEP_CTL0_EP_ENA_Get(x) (((uint32_t) (x) & USB_DOEPCTL0_DOEP_CTL0_EP_ENA_Msk) >> USB_DOEPCTL0_DOEP_CTL0_EP_ENA_Pos) /*!< DOEP_CTL0_EP_ENA Get Value */


#define USB_DOEPCTL0_DOEP_CTL0_EP_DIS_Pos    (30U)                                                                       /*!< DOEP_CTL0_EP_DIS Postion   */ 
#define USB_DOEPCTL0_DOEP_CTL0_EP_DIS_Msk    (0x1U << USB_DOEPCTL0_DOEP_CTL0_EP_DIS_Pos)                                 /*!< DOEP_CTL0_EP_DIS Mask      */
#define USB_DOEPCTL0_DOEP_CTL0_EP_DIS_Set(x) (((uint32_t) (x) << USB_DOEPCTL0_DOEP_CTL0_EP_DIS_Pos) & USB_DOEPCTL0_DOEP_CTL0_EP_DIS_Msk) /*!< DOEP_CTL0_EP_DIS Set Value */
#define USB_DOEPCTL0_DOEP_CTL0_EP_DIS_Get(x) (((uint32_t) (x) & USB_DOEPCTL0_DOEP_CTL0_EP_DIS_Msk) >> USB_DOEPCTL0_DOEP_CTL0_EP_DIS_Pos) /*!< DOEP_CTL0_EP_DIS Get Value */


#define USB_DOEPCTL0_DOEP_CTL0_SNAK_Pos    (27U)                                                                       /*!< DOEP_CTL0_SNAK Postion   */ 
#define USB_DOEPCTL0_DOEP_CTL0_SNAK_Msk    (0x1U << USB_DOEPCTL0_DOEP_CTL0_SNAK_Pos)                                   /*!< DOEP_CTL0_SNAK Mask      */
#define USB_DOEPCTL0_DOEP_CTL0_SNAK_Set(x) (((uint32_t) (x) << USB_DOEPCTL0_DOEP_CTL0_SNAK_Pos) & USB_DOEPCTL0_DOEP_CTL0_SNAK_Msk) /*!< DOEP_CTL0_SNAK Set Value */
#define USB_DOEPCTL0_DOEP_CTL0_SNAK_Get(x) (((uint32_t) (x) & USB_DOEPCTL0_DOEP_CTL0_SNAK_Msk) >> USB_DOEPCTL0_DOEP_CTL0_SNAK_Pos) /*!< DOEP_CTL0_SNAK Get Value */


#define USB_DOEPCTL0_DOEP_CTL0_CNAK_Pos    (26U)                                                                       /*!< DOEP_CTL0_CNAK Postion   */ 
#define USB_DOEPCTL0_DOEP_CTL0_CNAK_Msk    (0x1U << USB_DOEPCTL0_DOEP_CTL0_CNAK_Pos)                                   /*!< DOEP_CTL0_CNAK Mask      */
#define USB_DOEPCTL0_DOEP_CTL0_CNAK_Set(x) (((uint32_t) (x) << USB_DOEPCTL0_DOEP_CTL0_CNAK_Pos) & USB_DOEPCTL0_DOEP_CTL0_CNAK_Msk) /*!< DOEP_CTL0_CNAK Set Value */
#define USB_DOEPCTL0_DOEP_CTL0_CNAK_Get(x) (((uint32_t) (x) & USB_DOEPCTL0_DOEP_CTL0_CNAK_Msk) >> USB_DOEPCTL0_DOEP_CTL0_CNAK_Pos) /*!< DOEP_CTL0_CNAK Get Value */


#define USB_DOEPCTL0_DOEP_CTL0_STALL_Pos    (21U)                                                                       /*!< DOEP_CTL0_STALL Postion   */ 
#define USB_DOEPCTL0_DOEP_CTL0_STALL_Msk    (0x1U << USB_DOEPCTL0_DOEP_CTL0_STALL_Pos)                                  /*!< DOEP_CTL0_STALL Mask      */
#define USB_DOEPCTL0_DOEP_CTL0_STALL_Set(x) (((uint32_t) (x) << USB_DOEPCTL0_DOEP_CTL0_STALL_Pos) & USB_DOEPCTL0_DOEP_CTL0_STALL_Msk) /*!< DOEP_CTL0_STALL Set Value */
#define USB_DOEPCTL0_DOEP_CTL0_STALL_Get(x) (((uint32_t) (x) & USB_DOEPCTL0_DOEP_CTL0_STALL_Msk) >> USB_DOEPCTL0_DOEP_CTL0_STALL_Pos) /*!< DOEP_CTL0_STALL Get Value */


#define USB_DOEPCTL0_DOEP_CTL0_SNP_Pos    (20U)                                                                       /*!< DOEP_CTL0_SNP Postion   */ 
#define USB_DOEPCTL0_DOEP_CTL0_SNP_Msk    (0x1U << USB_DOEPCTL0_DOEP_CTL0_SNP_Pos)                                    /*!< DOEP_CTL0_SNP Mask      */
#define USB_DOEPCTL0_DOEP_CTL0_SNP_Set(x) (((uint32_t) (x) << USB_DOEPCTL0_DOEP_CTL0_SNP_Pos) & USB_DOEPCTL0_DOEP_CTL0_SNP_Msk) /*!< DOEP_CTL0_SNP Set Value */
#define USB_DOEPCTL0_DOEP_CTL0_SNP_Get(x) (((uint32_t) (x) & USB_DOEPCTL0_DOEP_CTL0_SNP_Msk) >> USB_DOEPCTL0_DOEP_CTL0_SNP_Pos) /*!< DOEP_CTL0_SNP Get Value */


#define USB_DOEPCTL0_DOEP_CTL0_EP_TYPE_Pos    (18U)                                                                       /*!< DOEP_CTL0_EP_TYPE Postion   */ 
#define USB_DOEPCTL0_DOEP_CTL0_EP_TYPE_Msk    (0x3U << USB_DOEPCTL0_DOEP_CTL0_EP_TYPE_Pos)                                /*!< DOEP_CTL0_EP_TYPE Mask      */
#define USB_DOEPCTL0_DOEP_CTL0_EP_TYPE_Set(x) (((uint32_t) (x) << USB_DOEPCTL0_DOEP_CTL0_EP_TYPE_Pos) & USB_DOEPCTL0_DOEP_CTL0_EP_TYPE_Msk) /*!< DOEP_CTL0_EP_TYPE Set Value */
#define USB_DOEPCTL0_DOEP_CTL0_EP_TYPE_Get(x) (((uint32_t) (x) & USB_DOEPCTL0_DOEP_CTL0_EP_TYPE_Msk) >> USB_DOEPCTL0_DOEP_CTL0_EP_TYPE_Pos) /*!< DOEP_CTL0_EP_TYPE Get Value */


#define USB_DOEPCTL0_DOEP_CTL0_NAKSTS_Pos    (17U)                                                                       /*!< DOEP_CTL0_NAKSTS Postion   */ 
#define USB_DOEPCTL0_DOEP_CTL0_NAKSTS_Msk    (0x1U << USB_DOEPCTL0_DOEP_CTL0_NAKSTS_Pos)                                 /*!< DOEP_CTL0_NAKSTS Mask      */
#define USB_DOEPCTL0_DOEP_CTL0_NAKSTS_Set(x) (((uint32_t) (x) << USB_DOEPCTL0_DOEP_CTL0_NAKSTS_Pos) & USB_DOEPCTL0_DOEP_CTL0_NAKSTS_Msk) /*!< DOEP_CTL0_NAKSTS Set Value */
#define USB_DOEPCTL0_DOEP_CTL0_NAKSTS_Get(x) (((uint32_t) (x) & USB_DOEPCTL0_DOEP_CTL0_NAKSTS_Msk) >> USB_DOEPCTL0_DOEP_CTL0_NAKSTS_Pos) /*!< DOEP_CTL0_NAKSTS Get Value */


#define USB_DOEPCTL0_DOEP_CTL0_USB_ACT_EP_Pos    (15U)                                                                       /*!< DOEP_CTL0_USB_ACT_EP Postion   */ 
#define USB_DOEPCTL0_DOEP_CTL0_USB_ACT_EP_Msk    (0x1U << USB_DOEPCTL0_DOEP_CTL0_USB_ACT_EP_Pos)                             /*!< DOEP_CTL0_USB_ACT_EP Mask      */
#define USB_DOEPCTL0_DOEP_CTL0_USB_ACT_EP_Set(x) (((uint32_t) (x) << USB_DOEPCTL0_DOEP_CTL0_USB_ACT_EP_Pos) & USB_DOEPCTL0_DOEP_CTL0_USB_ACT_EP_Msk) /*!< DOEP_CTL0_USB_ACT_EP Set Value */
#define USB_DOEPCTL0_DOEP_CTL0_USB_ACT_EP_Get(x) (((uint32_t) (x) & USB_DOEPCTL0_DOEP_CTL0_USB_ACT_EP_Msk) >> USB_DOEPCTL0_DOEP_CTL0_USB_ACT_EP_Pos) /*!< DOEP_CTL0_USB_ACT_EP Get Value */


#define USB_DOEPCTL0_DOEP_CTL0_MPS_Pos    (0U)                                                                        /*!< DOEP_CTL0_MPS Postion   */ 
#define USB_DOEPCTL0_DOEP_CTL0_MPS_Msk    (0x3U << USB_DOEPCTL0_DOEP_CTL0_MPS_Pos)                                    /*!< DOEP_CTL0_MPS Mask      */
#define USB_DOEPCTL0_DOEP_CTL0_MPS_Set(x) (((uint32_t) (x) << USB_DOEPCTL0_DOEP_CTL0_MPS_Pos) & USB_DOEPCTL0_DOEP_CTL0_MPS_Msk) /*!< DOEP_CTL0_MPS Set Value */
#define USB_DOEPCTL0_DOEP_CTL0_MPS_Get(x) (((uint32_t) (x) & USB_DOEPCTL0_DOEP_CTL0_MPS_Msk) >> USB_DOEPCTL0_DOEP_CTL0_MPS_Pos) /*!< DOEP_CTL0_MPS Get Value */


/* DOEPINT0 bitfield */
#define USB_DOEPINT0_DOEP_IN_T0_STUP_PKT_RCVD_Pos    (15U)                                                                       /*!< DOEP_IN_T0_STUP_PKT_RCVD Postion   */ 
#define USB_DOEPINT0_DOEP_IN_T0_STUP_PKT_RCVD_Msk    (0x1U << USB_DOEPINT0_DOEP_IN_T0_STUP_PKT_RCVD_Pos)                         /*!< DOEP_IN_T0_STUP_PKT_RCVD Mask      */
#define USB_DOEPINT0_DOEP_IN_T0_STUP_PKT_RCVD_Set(x) (((uint32_t) (x) << USB_DOEPINT0_DOEP_IN_T0_STUP_PKT_RCVD_Pos) & USB_DOEPINT0_DOEP_IN_T0_STUP_PKT_RCVD_Msk) /*!< DOEP_IN_T0_STUP_PKT_RCVD Set Value */
#define USB_DOEPINT0_DOEP_IN_T0_STUP_PKT_RCVD_Get(x) (((uint32_t) (x) & USB_DOEPINT0_DOEP_IN_T0_STUP_PKT_RCVD_Msk) >> USB_DOEPINT0_DOEP_IN_T0_STUP_PKT_RCVD_Pos) /*!< DOEP_IN_T0_STUP_PKT_RCVD Get Value */


#define USB_DOEPINT0_DOEP_IN_T0_NYETINTRPT_Pos    (14U)                                                                       /*!< DOEP_IN_T0_NYETINTRPT Postion   */ 
#define USB_DOEPINT0_DOEP_IN_T0_NYETINTRPT_Msk    (0x1U << USB_DOEPINT0_DOEP_IN_T0_NYETINTRPT_Pos)                            /*!< DOEP_IN_T0_NYETINTRPT Mask      */
#define USB_DOEPINT0_DOEP_IN_T0_NYETINTRPT_Set(x) (((uint32_t) (x) << USB_DOEPINT0_DOEP_IN_T0_NYETINTRPT_Pos) & USB_DOEPINT0_DOEP_IN_T0_NYETINTRPT_Msk) /*!< DOEP_IN_T0_NYETINTRPT Set Value */
#define USB_DOEPINT0_DOEP_IN_T0_NYETINTRPT_Get(x) (((uint32_t) (x) & USB_DOEPINT0_DOEP_IN_T0_NYETINTRPT_Msk) >> USB_DOEPINT0_DOEP_IN_T0_NYETINTRPT_Pos) /*!< DOEP_IN_T0_NYETINTRPT Get Value */


#define USB_DOEPINT0_DOEP_IN_T0_NAKINTRPT_Pos    (13U)                                                                       /*!< DOEP_IN_T0_NAKINTRPT Postion   */ 
#define USB_DOEPINT0_DOEP_IN_T0_NAKINTRPT_Msk    (0x1U << USB_DOEPINT0_DOEP_IN_T0_NAKINTRPT_Pos)                             /*!< DOEP_IN_T0_NAKINTRPT Mask      */
#define USB_DOEPINT0_DOEP_IN_T0_NAKINTRPT_Set(x) (((uint32_t) (x) << USB_DOEPINT0_DOEP_IN_T0_NAKINTRPT_Pos) & USB_DOEPINT0_DOEP_IN_T0_NAKINTRPT_Msk) /*!< DOEP_IN_T0_NAKINTRPT Set Value */
#define USB_DOEPINT0_DOEP_IN_T0_NAKINTRPT_Get(x) (((uint32_t) (x) & USB_DOEPINT0_DOEP_IN_T0_NAKINTRPT_Msk) >> USB_DOEPINT0_DOEP_IN_T0_NAKINTRPT_Pos) /*!< DOEP_IN_T0_NAKINTRPT Get Value */


#define USB_DOEPINT0_DOEP_IN_T0_BBLE_ERR_Pos    (12U)                                                                       /*!< DOEP_IN_T0_BBLE_ERR Postion   */ 
#define USB_DOEPINT0_DOEP_IN_T0_BBLE_ERR_Msk    (0x1U << USB_DOEPINT0_DOEP_IN_T0_BBLE_ERR_Pos)                              /*!< DOEP_IN_T0_BBLE_ERR Mask      */
#define USB_DOEPINT0_DOEP_IN_T0_BBLE_ERR_Set(x) (((uint32_t) (x) << USB_DOEPINT0_DOEP_IN_T0_BBLE_ERR_Pos) & USB_DOEPINT0_DOEP_IN_T0_BBLE_ERR_Msk) /*!< DOEP_IN_T0_BBLE_ERR Set Value */
#define USB_DOEPINT0_DOEP_IN_T0_BBLE_ERR_Get(x) (((uint32_t) (x) & USB_DOEPINT0_DOEP_IN_T0_BBLE_ERR_Msk) >> USB_DOEPINT0_DOEP_IN_T0_BBLE_ERR_Pos) /*!< DOEP_IN_T0_BBLE_ERR Get Value */


#define USB_DOEPINT0_DOEP_IN_T0_PKT_DRP_STS_Pos    (11U)                                                                       /*!< DOEP_IN_T0_PKT_DRP_STS Postion   */ 
#define USB_DOEPINT0_DOEP_IN_T0_PKT_DRP_STS_Msk    (0x1U << USB_DOEPINT0_DOEP_IN_T0_PKT_DRP_STS_Pos)                           /*!< DOEP_IN_T0_PKT_DRP_STS Mask      */
#define USB_DOEPINT0_DOEP_IN_T0_PKT_DRP_STS_Set(x) (((uint32_t) (x) << USB_DOEPINT0_DOEP_IN_T0_PKT_DRP_STS_Pos) & USB_DOEPINT0_DOEP_IN_T0_PKT_DRP_STS_Msk) /*!< DOEP_IN_T0_PKT_DRP_STS Set Value */
#define USB_DOEPINT0_DOEP_IN_T0_PKT_DRP_STS_Get(x) (((uint32_t) (x) & USB_DOEPINT0_DOEP_IN_T0_PKT_DRP_STS_Msk) >> USB_DOEPINT0_DOEP_IN_T0_PKT_DRP_STS_Pos) /*!< DOEP_IN_T0_PKT_DRP_STS Get Value */


#define USB_DOEPINT0_DOEP_IN_T0_BNAINTR_Pos    (9U)                                                                        /*!< DOEP_IN_T0_BNAINTR Postion   */ 
#define USB_DOEPINT0_DOEP_IN_T0_BNAINTR_Msk    (0x1U << USB_DOEPINT0_DOEP_IN_T0_BNAINTR_Pos)                               /*!< DOEP_IN_T0_BNAINTR Mask      */
#define USB_DOEPINT0_DOEP_IN_T0_BNAINTR_Set(x) (((uint32_t) (x) << USB_DOEPINT0_DOEP_IN_T0_BNAINTR_Pos) & USB_DOEPINT0_DOEP_IN_T0_BNAINTR_Msk) /*!< DOEP_IN_T0_BNAINTR Set Value */
#define USB_DOEPINT0_DOEP_IN_T0_BNAINTR_Get(x) (((uint32_t) (x) & USB_DOEPINT0_DOEP_IN_T0_BNAINTR_Msk) >> USB_DOEPINT0_DOEP_IN_T0_BNAINTR_Pos) /*!< DOEP_IN_T0_BNAINTR Get Value */


#define USB_DOEPINT0_DOEP_IN_T0_OUT_PKT_ERR_Pos    (8U)                                                                        /*!< DOEP_IN_T0_OUT_PKT_ERR Postion   */ 
#define USB_DOEPINT0_DOEP_IN_T0_OUT_PKT_ERR_Msk    (0x1U << USB_DOEPINT0_DOEP_IN_T0_OUT_PKT_ERR_Pos)                           /*!< DOEP_IN_T0_OUT_PKT_ERR Mask      */
#define USB_DOEPINT0_DOEP_IN_T0_OUT_PKT_ERR_Set(x) (((uint32_t) (x) << USB_DOEPINT0_DOEP_IN_T0_OUT_PKT_ERR_Pos) & USB_DOEPINT0_DOEP_IN_T0_OUT_PKT_ERR_Msk) /*!< DOEP_IN_T0_OUT_PKT_ERR Set Value */
#define USB_DOEPINT0_DOEP_IN_T0_OUT_PKT_ERR_Get(x) (((uint32_t) (x) & USB_DOEPINT0_DOEP_IN_T0_OUT_PKT_ERR_Msk) >> USB_DOEPINT0_DOEP_IN_T0_OUT_PKT_ERR_Pos) /*!< DOEP_IN_T0_OUT_PKT_ERR Get Value */


#define USB_DOEPINT0_DOEP_IN_T0_BACK2BACK_SETUP_Pos    (6U)                                                                        /*!< DOEP_IN_T0_BACK2BACK_SETUP Postion   */ 
#define USB_DOEPINT0_DOEP_IN_T0_BACK2BACK_SETUP_Msk    (0x1U << USB_DOEPINT0_DOEP_IN_T0_BACK2BACK_SETUP_Pos)                       /*!< DOEP_IN_T0_BACK2BACK_SETUP Mask      */
#define USB_DOEPINT0_DOEP_IN_T0_BACK2BACK_SETUP_Set(x) (((uint32_t) (x) << USB_DOEPINT0_DOEP_IN_T0_BACK2BACK_SETUP_Pos) & USB_DOEPINT0_DOEP_IN_T0_BACK2BACK_SETUP_Msk) /*!< DOEP_IN_T0_BACK2BACK_SETUP Set Value */
#define USB_DOEPINT0_DOEP_IN_T0_BACK2BACK_SETUP_Get(x) (((uint32_t) (x) & USB_DOEPINT0_DOEP_IN_T0_BACK2BACK_SETUP_Msk) >> USB_DOEPINT0_DOEP_IN_T0_BACK2BACK_SETUP_Pos) /*!< DOEP_IN_T0_BACK2BACK_SETUP Get Value */


#define USB_DOEPINT0_DOEP_IN_T0_STS_PHSE_RCVD_Pos    (5U)                                                                        /*!< DOEP_IN_T0_STS_PHSE_RCVD Postion   */ 
#define USB_DOEPINT0_DOEP_IN_T0_STS_PHSE_RCVD_Msk    (0x1U << USB_DOEPINT0_DOEP_IN_T0_STS_PHSE_RCVD_Pos)                         /*!< DOEP_IN_T0_STS_PHSE_RCVD Mask      */
#define USB_DOEPINT0_DOEP_IN_T0_STS_PHSE_RCVD_Set(x) (((uint32_t) (x) << USB_DOEPINT0_DOEP_IN_T0_STS_PHSE_RCVD_Pos) & USB_DOEPINT0_DOEP_IN_T0_STS_PHSE_RCVD_Msk) /*!< DOEP_IN_T0_STS_PHSE_RCVD Set Value */
#define USB_DOEPINT0_DOEP_IN_T0_STS_PHSE_RCVD_Get(x) (((uint32_t) (x) & USB_DOEPINT0_DOEP_IN_T0_STS_PHSE_RCVD_Msk) >> USB_DOEPINT0_DOEP_IN_T0_STS_PHSE_RCVD_Pos) /*!< DOEP_IN_T0_STS_PHSE_RCVD Get Value */


#define USB_DOEPINT0_DOEP_IN_T0_OUT_TKN_EP_DIS_Pos    (4U)                                                                        /*!< DOEP_IN_T0_OUT_TKN_EP_DIS Postion   */ 
#define USB_DOEPINT0_DOEP_IN_T0_OUT_TKN_EP_DIS_Msk    (0x1U << USB_DOEPINT0_DOEP_IN_T0_OUT_TKN_EP_DIS_Pos)                        /*!< DOEP_IN_T0_OUT_TKN_EP_DIS Mask      */
#define USB_DOEPINT0_DOEP_IN_T0_OUT_TKN_EP_DIS_Set(x) (((uint32_t) (x) << USB_DOEPINT0_DOEP_IN_T0_OUT_TKN_EP_DIS_Pos) & USB_DOEPINT0_DOEP_IN_T0_OUT_TKN_EP_DIS_Msk) /*!< DOEP_IN_T0_OUT_TKN_EP_DIS Set Value */
#define USB_DOEPINT0_DOEP_IN_T0_OUT_TKN_EP_DIS_Get(x) (((uint32_t) (x) & USB_DOEPINT0_DOEP_IN_T0_OUT_TKN_EP_DIS_Msk) >> USB_DOEPINT0_DOEP_IN_T0_OUT_TKN_EP_DIS_Pos) /*!< DOEP_IN_T0_OUT_TKN_EP_DIS Get Value */


#define USB_DOEPINT0_DOEP_IN_T0_SET_UP_Pos    (3U)                                                                        /*!< DOEP_IN_T0_SET_UP Postion   */ 
#define USB_DOEPINT0_DOEP_IN_T0_SET_UP_Msk    (0x1U << USB_DOEPINT0_DOEP_IN_T0_SET_UP_Pos)                                /*!< DOEP_IN_T0_SET_UP Mask      */
#define USB_DOEPINT0_DOEP_IN_T0_SET_UP_Set(x) (((uint32_t) (x) << USB_DOEPINT0_DOEP_IN_T0_SET_UP_Pos) & USB_DOEPINT0_DOEP_IN_T0_SET_UP_Msk) /*!< DOEP_IN_T0_SET_UP Set Value */
#define USB_DOEPINT0_DOEP_IN_T0_SET_UP_Get(x) (((uint32_t) (x) & USB_DOEPINT0_DOEP_IN_T0_SET_UP_Msk) >> USB_DOEPINT0_DOEP_IN_T0_SET_UP_Pos) /*!< DOEP_IN_T0_SET_UP Get Value */


#define USB_DOEPINT0_DOEP_IN_T0_AHB_ERR_Pos    (2U)                                                                        /*!< DOEP_IN_T0_AHB_ERR Postion   */ 
#define USB_DOEPINT0_DOEP_IN_T0_AHB_ERR_Msk    (0x1U << USB_DOEPINT0_DOEP_IN_T0_AHB_ERR_Pos)                               /*!< DOEP_IN_T0_AHB_ERR Mask      */
#define USB_DOEPINT0_DOEP_IN_T0_AHB_ERR_Set(x) (((uint32_t) (x) << USB_DOEPINT0_DOEP_IN_T0_AHB_ERR_Pos) & USB_DOEPINT0_DOEP_IN_T0_AHB_ERR_Msk) /*!< DOEP_IN_T0_AHB_ERR Set Value */
#define USB_DOEPINT0_DOEP_IN_T0_AHB_ERR_Get(x) (((uint32_t) (x) & USB_DOEPINT0_DOEP_IN_T0_AHB_ERR_Msk) >> USB_DOEPINT0_DOEP_IN_T0_AHB_ERR_Pos) /*!< DOEP_IN_T0_AHB_ERR Get Value */


#define USB_DOEPINT0_DOEP_IN_T0_EP_DISBLD_Pos    (1U)                                                                        /*!< DOEP_IN_T0_EP_DISBLD Postion   */ 
#define USB_DOEPINT0_DOEP_IN_T0_EP_DISBLD_Msk    (0x1U << USB_DOEPINT0_DOEP_IN_T0_EP_DISBLD_Pos)                             /*!< DOEP_IN_T0_EP_DISBLD Mask      */
#define USB_DOEPINT0_DOEP_IN_T0_EP_DISBLD_Set(x) (((uint32_t) (x) << USB_DOEPINT0_DOEP_IN_T0_EP_DISBLD_Pos) & USB_DOEPINT0_DOEP_IN_T0_EP_DISBLD_Msk) /*!< DOEP_IN_T0_EP_DISBLD Set Value */
#define USB_DOEPINT0_DOEP_IN_T0_EP_DISBLD_Get(x) (((uint32_t) (x) & USB_DOEPINT0_DOEP_IN_T0_EP_DISBLD_Msk) >> USB_DOEPINT0_DOEP_IN_T0_EP_DISBLD_Pos) /*!< DOEP_IN_T0_EP_DISBLD Get Value */


#define USB_DOEPINT0_DOEP_IN_T0_XFER_COMPL_Pos    (0U)                                                                        /*!< DOEP_IN_T0_XFER_COMPL Postion   */ 
#define USB_DOEPINT0_DOEP_IN_T0_XFER_COMPL_Msk    (0x1U << USB_DOEPINT0_DOEP_IN_T0_XFER_COMPL_Pos)                            /*!< DOEP_IN_T0_XFER_COMPL Mask      */
#define USB_DOEPINT0_DOEP_IN_T0_XFER_COMPL_Set(x) (((uint32_t) (x) << USB_DOEPINT0_DOEP_IN_T0_XFER_COMPL_Pos) & USB_DOEPINT0_DOEP_IN_T0_XFER_COMPL_Msk) /*!< DOEP_IN_T0_XFER_COMPL Set Value */
#define USB_DOEPINT0_DOEP_IN_T0_XFER_COMPL_Get(x) (((uint32_t) (x) & USB_DOEPINT0_DOEP_IN_T0_XFER_COMPL_Msk) >> USB_DOEPINT0_DOEP_IN_T0_XFER_COMPL_Pos) /*!< DOEP_IN_T0_XFER_COMPL Get Value */


/* DOEPTSIZ0 bitfield */
#define USB_DOEPTSIZ0_SUPCNT_Pos    (29U)                                                                       /*!< SUPCNT Postion   */ 
#define USB_DOEPTSIZ0_SUPCNT_Msk    (0x3U << USB_DOEPTSIZ0_SUPCNT_Pos)                                          /*!< SUPCNT Mask      */
#define USB_DOEPTSIZ0_SUPCNT_Set(x) (((uint32_t) (x) << USB_DOEPTSIZ0_SUPCNT_Pos) & USB_DOEPTSIZ0_SUPCNT_Msk)   /*!< SUPCNT Set Value */
#define USB_DOEPTSIZ0_SUPCNT_Get(x) (((uint32_t) (x) & USB_DOEPTSIZ0_SUPCNT_Msk) >> USB_DOEPTSIZ0_SUPCNT_Pos)   /*!< SUPCNT Get Value */


#define USB_DOEPTSIZ0_DOEP_TSIZ0_PKT_CNT_Pos    (19U)                                                                       /*!< DOEP_TSIZ0_PKT_CNT Postion   */ 
#define USB_DOEPTSIZ0_DOEP_TSIZ0_PKT_CNT_Msk    (0x1U << USB_DOEPTSIZ0_DOEP_TSIZ0_PKT_CNT_Pos)                              /*!< DOEP_TSIZ0_PKT_CNT Mask      */
#define USB_DOEPTSIZ0_DOEP_TSIZ0_PKT_CNT_Set(x) (((uint32_t) (x) << USB_DOEPTSIZ0_DOEP_TSIZ0_PKT_CNT_Pos) & USB_DOEPTSIZ0_DOEP_TSIZ0_PKT_CNT_Msk) /*!< DOEP_TSIZ0_PKT_CNT Set Value */
#define USB_DOEPTSIZ0_DOEP_TSIZ0_PKT_CNT_Get(x) (((uint32_t) (x) & USB_DOEPTSIZ0_DOEP_TSIZ0_PKT_CNT_Msk) >> USB_DOEPTSIZ0_DOEP_TSIZ0_PKT_CNT_Pos) /*!< DOEP_TSIZ0_PKT_CNT Get Value */


#define USB_DOEPTSIZ0_DOEP_TSIZ0_XFER_SIZE_Pos    (0U)                                                                        /*!< DOEP_TSIZ0_XFER_SIZE Postion   */ 
#define USB_DOEPTSIZ0_DOEP_TSIZ0_XFER_SIZE_Msk    (0x7fU << USB_DOEPTSIZ0_DOEP_TSIZ0_XFER_SIZE_Pos)                           /*!< DOEP_TSIZ0_XFER_SIZE Mask      */
#define USB_DOEPTSIZ0_DOEP_TSIZ0_XFER_SIZE_Set(x) (((uint32_t) (x) << USB_DOEPTSIZ0_DOEP_TSIZ0_XFER_SIZE_Pos) & USB_DOEPTSIZ0_DOEP_TSIZ0_XFER_SIZE_Msk) /*!< DOEP_TSIZ0_XFER_SIZE Set Value */
#define USB_DOEPTSIZ0_DOEP_TSIZ0_XFER_SIZE_Get(x) (((uint32_t) (x) & USB_DOEPTSIZ0_DOEP_TSIZ0_XFER_SIZE_Msk) >> USB_DOEPTSIZ0_DOEP_TSIZ0_XFER_SIZE_Pos) /*!< DOEP_TSIZ0_XFER_SIZE Get Value */


/* DOEPDMA0 bitfield */
#define USB_DOEPDMA0_DOEP_DMA0_DMA_ADDR_Pos    (0U)                                                                        /*!< DOEP_DMA0_DMA_ADDR Postion   */ 
#define USB_DOEPDMA0_DOEP_DMA0_DMA_ADDR_Msk    (0xffffffffU << USB_DOEPDMA0_DOEP_DMA0_DMA_ADDR_Pos)                        /*!< DOEP_DMA0_DMA_ADDR Mask      */
#define USB_DOEPDMA0_DOEP_DMA0_DMA_ADDR_Set(x) (((uint32_t) (x) << USB_DOEPDMA0_DOEP_DMA0_DMA_ADDR_Pos) & USB_DOEPDMA0_DOEP_DMA0_DMA_ADDR_Msk) /*!< DOEP_DMA0_DMA_ADDR Set Value */
#define USB_DOEPDMA0_DOEP_DMA0_DMA_ADDR_Get(x) (((uint32_t) (x) & USB_DOEPDMA0_DOEP_DMA0_DMA_ADDR_Msk) >> USB_DOEPDMA0_DOEP_DMA0_DMA_ADDR_Pos) /*!< DOEP_DMA0_DMA_ADDR Get Value */


/* DOEPDMAB0 bitfield */
#define USB_DOEPDMAB0_DOEP_DMA_B0_DMA_BUFFER_ADDR_Pos    (0U)                                                                        /*!< DOEP_DMA_B0_DMA_BUFFER_ADDR Postion   */ 
#define USB_DOEPDMAB0_DOEP_DMA_B0_DMA_BUFFER_ADDR_Msk    (0xffffffffU << USB_DOEPDMAB0_DOEP_DMA_B0_DMA_BUFFER_ADDR_Pos)              /*!< DOEP_DMA_B0_DMA_BUFFER_ADDR Mask      */
#define USB_DOEPDMAB0_DOEP_DMA_B0_DMA_BUFFER_ADDR_Set(x) (((uint32_t) (x) << USB_DOEPDMAB0_DOEP_DMA_B0_DMA_BUFFER_ADDR_Pos) & USB_DOEPDMAB0_DOEP_DMA_B0_DMA_BUFFER_ADDR_Msk) /*!< DOEP_DMA_B0_DMA_BUFFER_ADDR Set Value */
#define USB_DOEPDMAB0_DOEP_DMA_B0_DMA_BUFFER_ADDR_Get(x) (((uint32_t) (x) & USB_DOEPDMAB0_DOEP_DMA_B0_DMA_BUFFER_ADDR_Msk) >> USB_DOEPDMAB0_DOEP_DMA_B0_DMA_BUFFER_ADDR_Pos) /*!< DOEP_DMA_B0_DMA_BUFFER_ADDR Get Value */


/* PCGCCTL bitfield */
#define USB_PCGCCTL_RESET_AFTER_SUSP_Pos    (8U)                                                                        /*!< RESET_AFTER_SUSP Postion   */ 
#define USB_PCGCCTL_RESET_AFTER_SUSP_Msk    (0x1U << USB_PCGCCTL_RESET_AFTER_SUSP_Pos)                                  /*!< RESET_AFTER_SUSP Mask      */
#define USB_PCGCCTL_RESET_AFTER_SUSP_Set(x) (((uint32_t) (x) << USB_PCGCCTL_RESET_AFTER_SUSP_Pos) & USB_PCGCCTL_RESET_AFTER_SUSP_Msk) /*!< RESET_AFTER_SUSP Set Value */
#define USB_PCGCCTL_RESET_AFTER_SUSP_Get(x) (((uint32_t) (x) & USB_PCGCCTL_RESET_AFTER_SUSP_Msk) >> USB_PCGCCTL_RESET_AFTER_SUSP_Pos) /*!< RESET_AFTER_SUSP Get Value */


#define USB_PCGCCTL_L1SUSPENDED_Pos    (7U)                                                                        /*!< L1SUSPENDED Postion   */ 
#define USB_PCGCCTL_L1SUSPENDED_Msk    (0x1U << USB_PCGCCTL_L1SUSPENDED_Pos)                                       /*!< L1SUSPENDED Mask      */
#define USB_PCGCCTL_L1SUSPENDED_Set(x) (((uint32_t) (x) << USB_PCGCCTL_L1SUSPENDED_Pos) & USB_PCGCCTL_L1SUSPENDED_Msk) /*!< L1SUSPENDED Set Value */
#define USB_PCGCCTL_L1SUSPENDED_Get(x) (((uint32_t) (x) & USB_PCGCCTL_L1SUSPENDED_Msk) >> USB_PCGCCTL_L1SUSPENDED_Pos) /*!< L1SUSPENDED Get Value */


#define USB_PCGCCTL_PHY_SLEEP_Pos    (6U)                                                                        /*!< PHY_SLEEP Postion   */ 
#define USB_PCGCCTL_PHY_SLEEP_Msk    (0x1U << USB_PCGCCTL_PHY_SLEEP_Pos)                                         /*!< PHY_SLEEP Mask      */
#define USB_PCGCCTL_PHY_SLEEP_Set(x) (((uint32_t) (x) << USB_PCGCCTL_PHY_SLEEP_Pos) & USB_PCGCCTL_PHY_SLEEP_Msk) /*!< PHY_SLEEP Set Value */
#define USB_PCGCCTL_PHY_SLEEP_Get(x) (((uint32_t) (x) & USB_PCGCCTL_PHY_SLEEP_Msk) >> USB_PCGCCTL_PHY_SLEEP_Pos) /*!< PHY_SLEEP Get Value */


#define USB_PCGCCTL_ENBL_L1GATING_Pos    (5U)                                                                        /*!< ENBL_L1GATING Postion   */ 
#define USB_PCGCCTL_ENBL_L1GATING_Msk    (0x1U << USB_PCGCCTL_ENBL_L1GATING_Pos)                                     /*!< ENBL_L1GATING Mask      */
#define USB_PCGCCTL_ENBL_L1GATING_Set(x) (((uint32_t) (x) << USB_PCGCCTL_ENBL_L1GATING_Pos) & USB_PCGCCTL_ENBL_L1GATING_Msk) /*!< ENBL_L1GATING Set Value */
#define USB_PCGCCTL_ENBL_L1GATING_Get(x) (((uint32_t) (x) & USB_PCGCCTL_ENBL_L1GATING_Msk) >> USB_PCGCCTL_ENBL_L1GATING_Pos) /*!< ENBL_L1GATING Get Value */


#define USB_PCGCCTL_RST_PDWN_MODULE_Pos    (3U)                                                                        /*!< RST_PDWN_MODULE Postion   */ 
#define USB_PCGCCTL_RST_PDWN_MODULE_Msk    (0x1U << USB_PCGCCTL_RST_PDWN_MODULE_Pos)                                   /*!< RST_PDWN_MODULE Mask      */
#define USB_PCGCCTL_RST_PDWN_MODULE_Set(x) (((uint32_t) (x) << USB_PCGCCTL_RST_PDWN_MODULE_Pos) & USB_PCGCCTL_RST_PDWN_MODULE_Msk) /*!< RST_PDWN_MODULE Set Value */
#define USB_PCGCCTL_RST_PDWN_MODULE_Get(x) (((uint32_t) (x) & USB_PCGCCTL_RST_PDWN_MODULE_Msk) >> USB_PCGCCTL_RST_PDWN_MODULE_Pos) /*!< RST_PDWN_MODULE Get Value */


#define USB_PCGCCTL_PWR_CLMP_Pos    (2U)                                                                        /*!< PWR_CLMP Postion   */ 
#define USB_PCGCCTL_PWR_CLMP_Msk    (0x1U << USB_PCGCCTL_PWR_CLMP_Pos)                                          /*!< PWR_CLMP Mask      */
#define USB_PCGCCTL_PWR_CLMP_Set(x) (((uint32_t) (x) << USB_PCGCCTL_PWR_CLMP_Pos) & USB_PCGCCTL_PWR_CLMP_Msk)   /*!< PWR_CLMP Set Value */
#define USB_PCGCCTL_PWR_CLMP_Get(x) (((uint32_t) (x) & USB_PCGCCTL_PWR_CLMP_Msk) >> USB_PCGCCTL_PWR_CLMP_Pos)   /*!< PWR_CLMP Get Value */


#define USB_PCGCCTL_GATE_HCLK_Pos    (1U)                                                                        /*!< GATE_HCLK Postion   */ 
#define USB_PCGCCTL_GATE_HCLK_Msk    (0x1U << USB_PCGCCTL_GATE_HCLK_Pos)                                         /*!< GATE_HCLK Mask      */
#define USB_PCGCCTL_GATE_HCLK_Set(x) (((uint32_t) (x) << USB_PCGCCTL_GATE_HCLK_Pos) & USB_PCGCCTL_GATE_HCLK_Msk) /*!< GATE_HCLK Set Value */
#define USB_PCGCCTL_GATE_HCLK_Get(x) (((uint32_t) (x) & USB_PCGCCTL_GATE_HCLK_Msk) >> USB_PCGCCTL_GATE_HCLK_Pos) /*!< GATE_HCLK Get Value */


#define USB_PCGCCTL_STOP_PCLK_Pos    (0U)                                                                        /*!< STOP_PCLK Postion   */ 
#define USB_PCGCCTL_STOP_PCLK_Msk    (0x1U << USB_PCGCCTL_STOP_PCLK_Pos)                                         /*!< STOP_PCLK Mask      */
#define USB_PCGCCTL_STOP_PCLK_Set(x) (((uint32_t) (x) << USB_PCGCCTL_STOP_PCLK_Pos) & USB_PCGCCTL_STOP_PCLK_Msk) /*!< STOP_PCLK Set Value */
#define USB_PCGCCTL_STOP_PCLK_Get(x) (((uint32_t) (x) & USB_PCGCCTL_STOP_PCLK_Msk) >> USB_PCGCCTL_STOP_PCLK_Pos) /*!< STOP_PCLK Get Value */


/*!
 * @}
 */

/* clang-format on */

/*!
 * @}
 */ /* end of HS32F7D377_USB_REGISTER */

#endif /* HS32F7D377_USB_H */
