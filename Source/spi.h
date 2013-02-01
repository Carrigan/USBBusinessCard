/**
  	@author Brian Carrigan
  	@date 7/12/2012
	@file spi.h
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

#ifndef SPI_H
#define SPI_H

#include "LPC13xx.h"

#define SPI_TFE		1ul
#define SPI_RNE		0x00000004
#define SPI_BSY		0x00000010

// Use this in code where the byte out doesnt matter
#define SPI_DUMMY	0xFF

#define SPI_CS_DISABLE()	(LPC_GPIO2->DATA |= 0x0004)	
#define SPI_CS_ENABLE()	    (LPC_GPIO2->DATA &= 0xFFFB)
#define	SPI_CS_SETUP()		(LPC_GPIO2->DIR |= 0x0004)	

void SPI_Config(void);
unsigned char SPI_ReadWrite(unsigned char dataToSend);

#endif
