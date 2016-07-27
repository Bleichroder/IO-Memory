#include "stdafx.h"

#pragma once
class CGlobalData
{
public:
	CGlobalData(void);
	~CGlobalData(void);

	static CString mem_byte, io_mem_address;
	static int bit_mode, io_mem_read;
};
