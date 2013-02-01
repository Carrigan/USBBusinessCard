/**
  	@author Brian Carrigan
  	@date 7/12/2012
	@file at45db.h
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

#ifndef AT45DB_H
#define AT45DB_H 

#define MAIN_PAGE_READ		0x03
#define MAIN_PAGE_BUF1WRITE	0x82
#define MAIN_PAGE_TO_BUF1	0x53
#define MAIN_PAGE_BUF1_COMP	0x60
#define READ_STATE_REGISTER 0xD7


void AT45DB_WriteFromArray(unsigned char *array, unsigned int length, unsigned int offset);
void AT45DB_ReadIntoArray(unsigned char *array, unsigned int length, unsigned int offset);

#endif
