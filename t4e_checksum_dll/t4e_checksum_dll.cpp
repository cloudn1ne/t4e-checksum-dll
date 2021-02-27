/*
** t4e_checksum_dll - (c) cn@warp.at - 2016
**
*/

// t4e_checksum_dll.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "t4e_checksum_dll.h"
#include "t4e_cal_checksum.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>


/*
** implements the DECRAM/CALRAM algo used in T4e's
** 
** *data = ptr to Byte() array of calram data
** size  = length of Byte() array
*/
T4E_CHECKSUM_DLL_API __int32 t4e_cal_chksum(BYTE *data, UINT16 offset, UINT16 size)
{
	UINT16 crc = 0;
	UINT16 lv;
	UINT16 i=size;
	UINT32 addr=offset;
	UINT16 v;
	
	while (i != 0)
	{						    
		v = ((crc ^ data[addr]) & 0xFF) << 1;		
		lv = (chksum_tbl_bin[v]<<8) | (chksum_tbl_bin[v+1]);		
		lv = lv & 0xFFFF;
		crc = ((crc >> 8) ^ lv) & 0xFFFF;			
		addr++;
		i--;		
	}
	return(crc);
}



