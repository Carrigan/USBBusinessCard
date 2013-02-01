/**
  	@author Brian Carrigan
  	@date 7/12/2012
	@file spi.c
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
#include "LPC13xx.h"

/**
 *	@brief Configure the LPC1343 SPI module
 *
 */
void SPI_Config()
{
	// Turn off reset assertion
	LPC_SYSCON->PRESETCTRL |= 1;
	// Power On
	LPC_SYSCON->SYSAHBCLKCTRL |= 1ul << 11;
	LPC_SYSCON->SYSAHBCLKCTRL |= (1<<6);
	// Clock Control
	LPC_SYSCON->SSP0CLKDIV |= 2;
		
	// Configure pins 0.8 0.9 2.11	
	LPC_IOCON->PIO0_8 &= ~0x07;
	LPC_IOCON->PIO0_8 |= 0x1;
	LPC_IOCON->PIO0_9 &= ~0x07;
	LPC_IOCON->PIO0_9 |= 0x1;
	LPC_IOCON->SCK_LOC |= 0x1;
	LPC_IOCON->PIO2_11 &= ~0x07;
	LPC_IOCON->PIO2_11 |= 0x1;

	LPC_IOCON->PIO2_2 &= ~0x1F;

	// Direction of 2.2
	SPI_CS_SETUP();
	
	// Set clock
	LPC_SSP0->CPSR |= 8;

	LPC_SSP0->CR0 |= 0x0007;
	LPC_SSP0->CR1 |= 0x2;

	while((LPC_SSP0->SR & SPI_RNE) == SPI_RNE)
	{
		unsigned char charIn;
		charIn = LPC_SSP0->DR; 
	} 	
}

/**
 *	@brief Perform an SPI duplex read/write.
 *
 *	@param dataToSend The data to be sent.
 *  @return The data being returned from the read.
 */
unsigned char SPI_ReadWrite(unsigned char dataToSend)
{
	unsigned char charIn;
	// Block until the buffer is empty
	while((LPC_SSP0->SR & (SPI_TFE|SPI_BSY)) != SPI_TFE);	
	LPC_SSP0->DR = dataToSend;
	
	// Wait until the transfer is complete to empty the FIFO
	while((LPC_SSP0->SR & (SPI_RNE|SPI_BSY)) != SPI_RNE);
	charIn = LPC_SSP0->DR;
	return charIn;
}
