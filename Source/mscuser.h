/****************************************************************************
 *   $Id:: mscuser.h 6997 2011-03-28 18:32:43Z usb00423                     $
 *   Project: NXP LPC13xx USB MSC ROM version example
 *
 *   Description:
 *     This file contains USB MSC user code header definition.
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
#ifndef __MSCUSER_H__
#define __MSCUSER_H__

#include "at45db.h"

/* Mass Storage Memory Layout */
// For the AT45DB081, there are 264x4096 sectors, or 1081344 bytes of memory.
#define MSC_MemorySize  (AT45DB_TOTALMEM)
#define MSC_BlockSize   512
#define MSC_BlockCount  (MSC_MemorySize / MSC_BlockSize)

extern const uint8_t InquiryStr[];

extern void MSC_MemoryRead (uint32_t offset, uint8_t dst[], uint32_t length);
extern void MSC_MemoryWrite (uint32_t offset, uint8_t src[], uint32_t length);


#endif  /* __MSCUSER_H__ */
