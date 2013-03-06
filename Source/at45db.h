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

// Option 1: 256 byte blocks, 1048576 bytes. The 512 byte formatted blocks expected
// by Windows fit in much nicer, yielding a 44% better perfomance while sacrificing
// only 3% of the total memory.
#define	AT45DB_BLOCKSIZE	256			///<	Block size of the AT45DB being used
#define	AT45DB_TOTALMEM		1048576		///<	Total memory of the AT45DB, using this block size

// Option 2: 264 byte blocks, 1081344 bytes. More memory, but because the blocks don't
// align nicely, 31 out of 32 block (512b) writes will take 3 blocks, causing a slowdown in 
// write speed. Switch to this ONLY if space is a problem, as you get 32768k more memory.
// #define AT45DB_BLOCKSIZE	264		///<	Block size of the AT45DB being used
// #define AT45DB_TOTALMEM	1081344	///<	Total memory of the AT45DB, using this block size


void AT45DB_WriteFromArray(unsigned char *array, unsigned int length, unsigned int offset);
void AT45DB_ReadIntoArray(unsigned char *array, unsigned int length, unsigned int offset);

#endif
