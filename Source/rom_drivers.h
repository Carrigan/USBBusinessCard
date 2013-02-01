/****************************************************************************
 *   $Id:: rom_drivers.h 3632 2010-06-01 22:54:42Z usb00423                 $
 *   Project: NXP LPC13xx USB MSC ROM version example
 *
 *   Description:
 *     This file contains USB MSC ROM driver header definition.
 *
 ****************************************************************************
 * Software that is described herein is for illustrative purposes only
 * which provides customers with programming information regarding the
 * products. This software is supplied "AS IS" without any warranties.
 * NXP Semiconductors assumes no responsibility or liability for the
 * use of the software, conveys no license or title under any patent,
 * copyright, or mask work right to the product. NXP Semiconductors
 * reserves the right to make changes in the software without
 * notification. NXP Semiconductors also make no representation or
 * warranty that such application will be suitable for the specified
 * use without further testing or modification.
****************************************************************************/
#ifndef ROM_DRIVERS_H_
#define ROM_DRIVERS_H_

#include "type.h"
 
typedef struct _USB_DEVICE_INFO {
  uint16_t DevType;
  uint32_t  DevDetailPtr;
} USB_DEV_INFO; 

typedef	struct _USBD {
  void (*init_clk_pins)(void);
  void (*isr)(void);
  void (*init)( USB_DEV_INFO * DevInfoPtr ); 
  void (*connect)(uint32_t  con);
}  USBD;

#define init_msdstate() *((uint32_t *)(0x10000054)) = 0x0

typedef	struct _ROM {
   const USBD * pUSBD;
}  ROM;

typedef	struct _MSC_DEVICE_INFO {
  uint16_t   idVendor;
  uint16_t   idProduct;
  uint16_t   bcdDevice;
  uint32_t  StrDescPtr;
  uint32_t  MSCInquiryStr;
  uint32_t  BlockCount;
  uint32_t  BlockSize;
  uint32_t  MemorySize;
  void (*MSC_Write)( uint32_t offset, uint8_t src[], uint32_t length); 
  void (*MSC_Read)( uint32_t offset, uint8_t dst[], uint32_t length);
}  MSC_DEVICE_INFO;

typedef	struct _HID_DEVICE_INFO {
  uint16_t   idVendor;
  uint16_t   idProduct;
  uint16_t   bcdDevice;
  uint32_t  StrDescPtr;
  uint8_t   InReportCount;
  uint8_t   OutReportCount;
  uint8_t   SampleInterval;
  void (*InReport)( uint8_t src[], uint32_t length); 
  void (*OutReport)(uint8_t dst[], uint32_t length);
}  HID_DEVICE_INFO;

#endif /*ROM_DRIVERS_H_*/
