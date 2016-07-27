// ---------------------------------------------------- //
//                      WinIo v3.0                      //
//				 Direct Hardware Access Under Windows	//
//           Copyright 1998-2010 Yariv Kaplan           //
//               http://www.internals.com               //
// ---------------------------------------------------- //

#include <windows.h>
#include "winio.h"

bool _stdcall InstallWinIoDriver(PWSTR pszWinIoDriverPath, bool IsDemandLoaded)
{
	SC_HANDLE hSCManager;
	SC_HANDLE hService;

	// Remove any previous instance of the driver

	RemoveWinIoDriver();

	hSCManager = OpenSCManager(NULL, NULL, SC_MANAGER_ALL_ACCESS);

	if (hSCManager)
	{
		// Install the driver

		hService = CreateService(hSCManager,
			L"WINIO",
			L"WINIO",
			SERVICE_ALL_ACCESS,
			SERVICE_KERNEL_DRIVER,
			(IsDemandLoaded == true) ? SERVICE_DEMAND_START : SERVICE_SYSTEM_START,
			SERVICE_ERROR_NORMAL,
			pszWinIoDriverPath,
			NULL,
			NULL,
			NULL,
			NULL,
			NULL);

		unsigned int err = GetLastError();
		CloseServiceHandle(hSCManager);

		if (hService == NULL)
		{
			if (err != 1072)
			{
				MessageBox(NULL, L"hService fail", L"error", MB_OK);
				return false;
			}
		}
	}
	else
	{
		MessageBox(NULL, L"hSCManager fail", L"error", MB_OK);
		return false;
	}

	CloseServiceHandle(hService);

	return true;
}


bool _stdcall RemoveWinIoDriver()
{
	SC_HANDLE hSCManager;
	SC_HANDLE hService;
	LPQUERY_SERVICE_CONFIG pServiceConfig;
	DWORD dwBytesNeeded;
	DWORD cbBufSize;
	bool bResult;

	StopWinIoDriver();

	hSCManager = OpenSCManager(NULL, NULL, SC_MANAGER_ALL_ACCESS);

	if (!hSCManager)
	{
		return false;
	}

	hService = OpenService(hSCManager, L"WINIO", SERVICE_ALL_ACCESS);
	CloseServiceHandle(hSCManager);

	if (!hService)
	{
		return false;
	}

	bResult = QueryServiceConfig(hService, NULL, 0, &dwBytesNeeded);

	if (GetLastError() == ERROR_INSUFFICIENT_BUFFER)
	{
		cbBufSize = dwBytesNeeded;
		pServiceConfig = (LPQUERY_SERVICE_CONFIG)malloc(cbBufSize);
		bResult = QueryServiceConfig(hService, pServiceConfig, cbBufSize, &dwBytesNeeded);

		if (!bResult)
		{
			free(pServiceConfig);
			CloseServiceHandle(hService);
			return bResult;
		}

		// If service is set to load automatically, don't delete it!
		if (pServiceConfig->dwStartType == SERVICE_DEMAND_START)
		{
			bResult = DeleteService(hService);
		}
	}

	CloseServiceHandle(hService);

	return bResult;
}


bool _stdcall StartWinIoDriver()
{
	SC_HANDLE hSCManager;
	SC_HANDLE hService;
	bool bResult;

	hSCManager = OpenSCManager(NULL, NULL, SC_MANAGER_ALL_ACCESS);

	if (hSCManager)
	{
		hService = OpenService(hSCManager, L"WINIO", SERVICE_ALL_ACCESS);

		CloseServiceHandle(hSCManager);

		if (hService)
		{
			bResult = StartService(hService, 0, NULL) || GetLastError() == ERROR_SERVICE_ALREADY_RUNNING;
			int err;
			err = GetLastError();

			CloseServiceHandle(hService);
		}
		else
			return false;
	}
	else
		return false;

	return bResult;
}


bool _stdcall StopWinIoDriver()
{
	SC_HANDLE hSCManager;
	SC_HANDLE hService;
	SERVICE_STATUS ServiceStatus;
	bool bResult;

	hSCManager = OpenSCManager(NULL, NULL, SC_MANAGER_ALL_ACCESS);

	if (hSCManager)
	{
		hService = OpenService(hSCManager, L"WINIO", SERVICE_STOP | DELETE | SERVICE_ALL_ACCESS);//SERVICE_ALL_ACCESS);

		CloseServiceHandle(hSCManager);

		if (hService)
		{
			bResult = ControlService(hService, SERVICE_CONTROL_STOP, NULL);//&ServiceStatus);
			int err;
			err = GetLastError();

			DeleteService(hService);

			CloseServiceHandle(hService);
		}
		else
			return false;
	}
	else
		return false;

	return bResult;
}