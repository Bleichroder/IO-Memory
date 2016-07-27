#pragma once
#include "MyEdit.h"
#include "GlobalData.h"


// CIo_add 对话框

class CIo_add : public CDialogEx
{
	DECLARE_DYNAMIC(CIo_add)

public:
	CIo_add(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CIo_add();

// 对话框数据
	enum { IDD = IDD_IO_ADDRESS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()

public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	CMyEdit m_s11;
	afx_msg void OnBnClickedOk();
};
