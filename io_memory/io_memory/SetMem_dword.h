#pragma once
#include "MyEdit.h"
#include "GlobalData.h"
#include "afxcmn.h"


// CSetMem_dword 对话框

class CSetMem_dword : public CDialogEx
{
	DECLARE_DYNAMIC(CSetMem_dword)

public:
	CSetMem_dword(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CSetMem_dword();

// 对话框数据
	enum { IDD = IDD_SET_ADDRESS_DWORD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()

	CMyEdit m_s5, m_s6, m_s7, m_s8;
public:
	CListCtrl io_memory_dword_1;
	CListCtrl io_memory_dword_2;
	CListCtrl io_memory_dword_3;
	CListCtrl io_memory_dword_4;
	afx_msg void OnNMCustomdrawListDword1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawListDword2(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawListDword3(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawListDword4(NMHDR *pNMHDR, LRESULT *pResult);
	unsigned long dword, dword_1, dword_2, dword_3, dword_4;
	unsigned int bit;
	CString mem_dword;
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
