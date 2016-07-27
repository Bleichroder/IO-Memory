// ---------------------------------------------------- //
//                      WinIo v3.0                      //
//				 Direct Hardware Access Under Windows	//
//           Copyright 1998-2010 Yariv Kaplan           //
//               http://www.internals.com               //
// ---------------------------------------------------- //

#include <windows.h>
#include <winioctl.h>
#include <conio.h>
#include "phys32.h"
#include "..\drv\winio_nt.h"
#include "winio.h"


PBYTE _stdcall MapPhysToLin(tagPhysStruct &PhysStruct)
{
	PBYTE pbLinAddr = NULL;
	DWORD dwBytesReturned;

	if (!IsWinIoInitialized)
		return false;

	if (!DeviceIoControl(hDriver, IOCTL_WINIO_MAPPHYSTOLIN, &PhysStruct,
		sizeof(tagPhysStruct), &PhysStruct, sizeof(tagPhysStruct),
		&dwBytesReturned, NULL))
	{
		int a = GetLastError();
		return NULL;
	}

	return (PBYTE)PhysStruct.pvPhysMemLin;
}


bool _stdcall UnmapPhysicalMemory(tagPhysStruct &PhysStruct)
{
	DWORD dwBytesReturned;

	if (!IsWinIoInitialized)
	{
		return false;
	}

	if (!DeviceIoControl(hDriver, IOCTL_WINIO_UNMAPPHYSADDR, &PhysStruct,
		sizeof(tagPhysStruct), NULL, 0, &dwBytesReturned, NULL))
	{
		return false;
	}

	return true;
}

// Support functions

bool _stdcall GetPhysLong(PBYTE pbPhysAddr, PDWORD pdwPhysVal)
{
	PDWORD pdwLinAddr;
	tagPhysStruct PhysStruct;

	if (!IsWinIoInitialized)
		return false;

	if (g_Is64BitOS)
	{
		PhysStruct.pvPhysAddress = (DWORD64)(DWORD32)pbPhysAddr;
	}
	else
	{
		// Avoid sign extension issues
		PhysStruct.pvPhysAddress = (DWORD64)(DWORD32)pbPhysAddr & 0xffffffff;
	}

	PhysStruct.dwPhysMemSizeInBytes = 4;

	pdwLinAddr = (PDWORD)MapPhysToLin(PhysStruct);

	if (pdwLinAddr == NULL)
		return false;

	*pdwPhysVal = *pdwLinAddr;

	UnmapPhysicalMemory(PhysStruct);

	return true;
}


bool _stdcall SetPhysLong(PBYTE pbPhysAddr, DWORD dwPhysVal)
{
	PDWORD pdwLinAddr;
	tagPhysStruct PhysStruct;

	if (!IsWinIoInitialized)
		return false;

	if (g_Is64BitOS)
	{
		PhysStruct.pvPhysAddress = (DWORD64)pbPhysAddr;
	}
	else
	{
		// Avoid sign extension issues
		PhysStruct.pvPhysAddress = (DWORD64)(DWORD32)pbPhysAddr;
	}

	PhysStruct.dwPhysMemSizeInBytes = 4;

	pdwLinAddr = (PDWORD)MapPhysToLin(PhysStruct);

	if (pdwLinAddr == NULL)
		return false;

	*pdwLinAddr = dwPhysVal;

	UnmapPhysicalMemory(PhysStruct);

	return true;
}

bool _stdcall ReadMSR(PVOID* MSR)
{
	DWORD dwBytesReturned;
	if (!IsWinIoInitialized)
		return false;
	if (g_Is64BitOS)
	{
		bool ret = DeviceIoControl(hDriver, IOCTL_WINIO_READMSR, MSR, 16, MSR, 16, &dwBytesReturned, NULL);
		int err;
		err = GetLastError();
		return ret;
	}
	else
		return false;
}

bool _stdcall WriteMSR(PVOID* MSR)
{
	DWORD dwBytesReturned;
	if (!IsWinIoInitialized)
		return false;
	if (g_Is64BitOS)
	{
		return DeviceIoControl(hDriver, IOCTL_WINIO_WRITEMSR, MSR, sizeof(stREG),
			MSR,sizeof(stREG), &dwBytesReturned, NULL);
	}
	else
		return false;
}