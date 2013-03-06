/**
  	@author Brian Carrigan
  	@date 7/12/2012
		@file bc.c
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
 
#include "lpc13xx.h"
#include "bc.h"

/**
 *	@brief Initialize the LEDs on the board.
 *
 */
void initializeBoard(void)
{
  LPC_IOCON->R_PIO1_0 &= 0xFFFFFB40;
  LPC_IOCON->R_PIO1_1 &= 0xFFFFFB40;

  LPC_IOCON->R_PIO1_0 |= 0x481;
  LPC_IOCON->R_PIO1_1 |= 0x481;

  LPC_GPIO1->DIR = 0x03;
  LPC_GPIO1->DATA = 0x03;
}

/**
 *	@brief Turn the indicated LED on.
 *
 *	@param pLED LED to be turned on.
 *
 */
void lightLED(LedIdentifier_t pLED)
{
	LPC_GPIO1->DATA &= ~(1<<((unsigned char)pLED)); 
}

/**
 *	@brief Turn the indicated LED off.
 *
 *	@param pLED LED to be turned off.
 *
 */
void clearLED(LedIdentifier_t pLED)
{
	LPC_GPIO1->DATA |= (1<<((unsigned char)pLED));
}
