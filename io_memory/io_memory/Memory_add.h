#pragma once
#include "MyEdit.h"
#include "GlobalData.h"


// CMemory_add 对话框

class CMemory_add : public CDialogEx
{
	DECLARE_DYNAMIC(CMemory_add)

public:
	CMemory_add(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CMemory_add();

// 对话框数据
	enum { IDD = IDD_MEMORY_ADDRESS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnBnClickedOk();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	CMyEdit m_s10;
};
