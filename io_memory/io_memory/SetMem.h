#pragma once
#include "afxcmn.h"
#include "MyEdit.h"
#include "GlobalData.h"


// CSetMem 对话框

class CSetMem : public CDialogEx
{
	DECLARE_DYNAMIC(CSetMem)

public:
	CSetMem(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CSetMem();

// 对话框数据
	enum { IDD = IDD_SET_ADDRESS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl io_memory_byte;
	afx_msg void OnNMCustomdrawListByte(NMHDR *pNMHDR, LRESULT *pResult);
	CString mem_bit;
	unsigned int byte, bit;
	CMyEdit m_s2;
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
