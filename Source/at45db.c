/**
  	@author Brian Carrigan
  	@date 7/12/2012
	@file at45db.c
  	Email brian.c.carrigan@gmail.com
 
	This file is part of the AT45DB LPC-Library.

    The AT45DB LPC-Library is free software: you 
    can redistribute it and/or modify it under the terms of the GNU 
    General Public License as published by the Free Software Foundation, 
    either version 3 of the License, or (at your option) any later 
    version.

    The AT45DB LPC-Library is distributed in 
    the hope that it will be useful, but WITHOUT ANY WARRANTY; without 
    even the implied warranty of MERCHANTABILITY or FITNESS FOR A 
    PARTICULAR PURPOSE.  See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with the AT45DB LPC-Library.  If not, 
    see <http://www.gnu.org/licenses/>.
 */

#include "spi.h"
#include "at45db.h"


/**
 *	@brief Blocking function that waits for the AT45DB to finish it's current 
 *
 */
static void AT45DB_WaitForBusy()
{
	unsigned char isBusy = 0;
	SPI_CS_ENABLE();
	SPI_ReadWrite(READ_STATE_REGISTER);
	do
	{
		isBusy = SPI_ReadWrite(SPI_DUMMY);
	} while(!(isBusy & 0x80));
	SPI_CS_DISABLE();	
}

/**
 *	@brief Writes an array of data to the AT45DB081, starting at a specific offset.
 *
 *	@param *array A pointer to the array of data to be sent.
 *	@param length Length of data to be written.
 *	@param offset Position (byte number) to be written to on the AT45DB.
 */
void AT45DB_ReadIntoArray(unsigned char *array, unsigned int length, unsigned int offset)
{
	unsigned char 	page_offset;
	unsigned short 	byte_offset;
	
	// If the offset is not valid:
	if(offset > 0x108000)
		return;

	// Wait for the AT45 to finish it's current duties.
	AT45DB_WaitForBusy();

	// Assert the CS line and tell the AT45DB
	SPI_CS_ENABLE();
	SPI_ReadWrite(MAIN_PAGE_READ);
	
	// Compute the offset.
	page_offset = offset/264;
	byte_offset = offset%264;

	// Write the offset
	SPI_ReadWrite(page_offset >> 7);
	SPI_ReadWrite(((page_offset & 0x7F)<<1) + (byte_offset >> 8));
	SPI_ReadWrite(byte_offset & 0xFF);

	// Continue reading until done
	while(length > 0)
	{
		*array = SPI_ReadWrite(SPI_DUMMY);
		array++;
		length--;
	}

	// Deassert SPI
	SPI_CS_DISABLE();
}

/**
 *	@brief Reads an array of data from the AT45DB081, starting at a specific offset.
 *
 *	@param *array A pointer to the array where incoming data will be written to.
 *	@param length Length of data to be read.
 *	@param offset Position (byte number) of data to be read from the AT45DB.
 */
void AT45DB_WriteFromArray(unsigned char *array, unsigned int length, unsigned int offset)
{
	unsigned short 	page_offset;
	unsigned short 	byte_offset;
	unsigned char mathbyte;
	
	// If the offset is not valid:
	if(offset > 0x108000)
		return;

	// Compute the offset
	page_offset = offset/264;
	byte_offset = offset%264;

	// For each page, do this operation
	do
	{
		// Wait for the flash to be ready.
		AT45DB_WaitForBusy();
		
		// Load the page into SRAM
		SPI_CS_ENABLE();
		SPI_ReadWrite(MAIN_PAGE_TO_BUF1);
		SPI_ReadWrite(page_offset >> 7);
		mathbyte = (page_offset & 0x7F)<<1;
		SPI_ReadWrite(mathbyte);
		SPI_ReadWrite(SPI_DUMMY);
		SPI_CS_DISABLE();
		
		// Wait for the page to be in RAM
		AT45DB_WaitForBusy();
	
		// Write the data
		SPI_CS_ENABLE();
		SPI_ReadWrite(MAIN_PAGE_BUF1WRITE);
		SPI_ReadWrite(page_offset >> 7);
		mathbyte = ((page_offset & 0x7F)<<1) + (byte_offset >> 8);
		SPI_ReadWrite(mathbyte);
		SPI_ReadWrite(byte_offset);
		do
		{
			SPI_ReadWrite(*array);
			array++;
			length--;
			byte_offset++;
		} while (byte_offset < 264 && length > 0); 		 
		SPI_CS_DISABLE();

	   	// Delay the processor 
		array = array + 2;
		array = array - 2;

		// Wait for the page to be in RAM
		AT45DB_WaitForBusy();

		// Load the page into Flash
		SPI_CS_ENABLE();
		SPI_ReadWrite(0x58);
		SPI_ReadWrite(page_offset >> 7);
		mathbyte = (page_offset & 0x7F)<<1;
		SPI_ReadWrite(mathbyte);
		SPI_ReadWrite(SPI_DUMMY);
		SPI_CS_DISABLE();
		
		// Is the operation complete?
		if(length > 0)
		{
			byte_offset = 0;
			page_offset++;	
		} else {
			break;
		}	
	} while (1);
}
