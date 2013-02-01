/****************************************************************************
 *   $Id:: usbdesc.c 3632 2010-06-01 22:54:42Z usb00423                     $
 *   Project: NXP LPC13xx USB USB ROM version example
 *
 *   Description:
 *     This file contains customized USB MSC descriptor example.
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

/* USB String Descriptor (optional) */
const uint8_t USB_StringDescriptor[] = {
/* Index 0x00: LANGID Codes */
  0x04,                              /* bLength */
  USB_STRING_DESCRIPTOR_TYPE,        /* bDescriptorType */
  WBVAL(0x0409), /* US English */    /* wLANGID */
/* Index 0x04: Manufacturer */
  0x1C,                              /* bLength */
  USB_STRING_DESCRIPTOR_TYPE,        /* bDescriptorType */
  'B',0,
  '.',0,
  ' ',0,
  'C',0,
  'a',0,
  'r',0,
  'r',0,
  'i',0,
  'g',0,
  'a',0,
  'n',0,
  ' ',0,
  ' ',0,
/* Index 0x20: Product */
  0x28,                              /* bLength */
  USB_STRING_DESCRIPTOR_TYPE,        /* bDescriptorType */
  'U',0,
  'S',0,
  'B',0,
  ' ',0,
  'B',0,
  'u',0,
  's',0,
  'i',0,
  'n',0,
  'e',0,
  's',0,
  's',0,
  ' ',0,
  'C',0,
  'a',0,
  'r',0,
  'd',0,
  ' ',0,
  ' ',0,
/* Index 0x48: Serial Number */
  0x1A,                              /* bLength */
  USB_STRING_DESCRIPTOR_TYPE,        /* bDescriptorType */
  '4',0,
  '2',0,
  '0',0,
  '0',0,
  '0',0,
  '0',0,
  '0',0,
  '0',0,
  '0',0,
  '0',0,
  '0',0,
  '0',0,
/* Index 0x62: Interface 0, Alternate Setting 0 */
  0x0E,                              /* bLength */
  USB_STRING_DESCRIPTOR_TYPE,        /* bDescriptorType */
  'M',0,
  'e',0,
  'm',0,
  'o',0,
  'r',0,
  'y',0,
};
