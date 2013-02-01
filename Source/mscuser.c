/****************************************************************************
 *   $Id:: mscuser.c 6997 2011-03-28 18:32:43Z usb00423                     $
 *   Project: NXP LPC13xx USB MSC ROM version example
 *
 *   Description:
 *     This file contains basic USB MSC(Mass Storage Class) APIs.
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
#include "type.h"
#include "usb.h"
#include "mscuser.h"
#include "at45db.h"
#include "bc.h"

const uint8_t InquiryStr[] = {'C', 'a', 'r', 'r', 'i', 'g', 'a', 'n',};

/**
 *	@brief Callback function for the Mass Storage Device read function.
 *
 *	@param offset 	The offset of the data to be read.
 *	@param dst[]	The data array to be filled by the data.
 *	@param length	The length of data to be read.
 */
void MSC_MemoryRead (uint32_t offset, uint8_t dst[], uint32_t length) {
	lightLED(LED_READ);
  	AT45DB_ReadIntoArray(dst, length, offset);
	clearLED(LED_READ);
}

/**
 *	@brief Callback function for the Mass Storage Device write function.
 *
 *	@param offset 	The offset of the data to be written.
 *	@param dst[]	The data to be written.
 *	@param length	The length of data to be written.
 */
void MSC_MemoryWrite (uint32_t offset, uint8_t src[], uint32_t length) {
	lightLED(LED_WRITE);
	AT45DB_WriteFromArray(src, length, offset);
	clearLED(LED_WRITE);
}
