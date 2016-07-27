
// io_memory.h : PROJECT_NAME 应用程序的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"		// 主符号


// Cio_memoryApp:
// 有关此类的实现，请参阅 io_memory.cpp
//

class Cio_memoryApp : public CWinApp
{
public:
	Cio_memoryApp();

// 重写
public:
	virtual BOOL InitInstance();

// 实现

	DECLARE_MESSAGE_MAP()
};

extern Cio_memoryApp theApp;