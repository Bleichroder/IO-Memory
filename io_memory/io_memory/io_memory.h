
// io_memory.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// Cio_memoryApp:
// �йش����ʵ�֣������ io_memory.cpp
//

class Cio_memoryApp : public CWinApp
{
public:
	Cio_memoryApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern Cio_memoryApp theApp;