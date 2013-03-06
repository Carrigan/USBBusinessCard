/****************************************************************************
 *   $Id:: memory.c 6997 2011-03-28 18:32:43Z usb00423                      $
 *   Project: NXP LPC13xx USB MSC ROM version example
 *
 *   Description:
 *     This file contains USB MSC test modules, main entry, to test ROM
 *     based USB MSC APIs.
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

#include "lpc13xx.h"
#include "usb.h"
#include "usbdesc.h"
#include "type.h"
#include "mscuser.h"
#include "memory.h"
#include "rom_drivers.h"
#include "spi.h"
#include "bc.h"

#define USB_VENDOR_ID       0x1FC9
#define USB_PROD_ID         0x8055
#define USB_DEVICE	        0x0100

USB_DEV_INFO DeviceInfo;
MSC_DEVICE_INFO MscDevInfo;
ROM ** rom = (ROM **)0x1fff1ff8;

#define EN_TIMER32_1        (0x1<<10)
#define EN_IOCON            (0x1<<16)
#define EN_USBREG       	(1<<14)

/* Main Program */

int main (void) {
  uint32_t n;	

  MscDevInfo.idVendor = USB_VENDOR_ID;
  MscDevInfo.idProduct = USB_PROD_ID;
  MscDevInfo.bcdDevice = USB_DEVICE; 
  MscDevInfo.StrDescPtr = (uint32_t)&USB_StringDescriptor[0];
  MscDevInfo.MSCInquiryStr = (uint32_t)&InquiryStr[0];
  MscDevInfo.BlockSize = MSC_BlockSize;
  MscDevInfo.BlockCount = MSC_BlockCount;
  MscDevInfo.MemorySize = MSC_MemorySize;
  MscDevInfo.MSC_Read = MSC_MemoryRead;
  MscDevInfo.MSC_Write = MSC_MemoryWrite;

  DeviceInfo.DevType = USB_DEVICE_CLASS_STORAGE;
  DeviceInfo.DevDetailPtr = (uint32_t)&MscDevInfo;

  /* Enable Timer32_1 and IOCON blocks */
 
  LPC_SYSCON->SYSAHBCLKCTRL |= (EN_TIMER32_1 | EN_IOCON | EN_USBREG);


  initializeBoard();
  SPI_Config();

  (*rom)->pUSBD->init_clk_pins();   /* Use pll and pin init function in rom */

  /* insert a delay between clk init and usb init */
  for (n = 0; n < 75; n++) {
  }

  (*rom)->pUSBD->init(&DeviceInfo);  /* USB Initialization */
  init_msdstate();					 /* Initialize Storage state machine */
  (*rom)->pUSBD->connect(TRUE);      /* USB Connect */

  while (1);                                /* Loop forever */
}

USB_IRQHandler(void)
{
  (*rom)->pUSBD->isr();
}
