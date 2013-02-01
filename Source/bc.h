/**
  	@author Brian Carrigan
  	@date 7/12/2012
	@file bc.h
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

#ifndef BC_H
#define BC_H

typedef enum
{
	LED_READ = 0,
	LED_WRITE = 1
} LedIdentifier_t;

void initializeBoard(void);
void lightLED(LedIdentifier_t pLED);
void clearLED(LedIdentifier_t pLED);

#endif
