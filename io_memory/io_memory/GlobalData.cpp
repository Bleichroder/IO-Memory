#include "GlobalData.h"


CGlobalData::CGlobalData(void)
{
}


CGlobalData::~CGlobalData(void)
{
}

CString CGlobalData::mem_byte = _T("");
CString CGlobalData::io_mem_address = _T("0");
int CGlobalData::bit_mode = 1;	//1--8 bit		2--16 bit		3--32 bit
int CGlobalData::io_mem_read = 1;	//1--mem_read		2--io_read