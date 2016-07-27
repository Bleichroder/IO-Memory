#pragma once
#include "MyEdit.h"
#include "GlobalData.h"
#include "afxcmn.h"


// CSetMem_word 对话框

class CSetMem_word : public CDialogEx
{
	DECLARE_DYNAMIC(CSetMem_word)

public:
	CSetMem_word(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CSetMem_word();

// 对话框数据
	enum { IDD = IDD_SET_ADDRESS_WORD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()

public:
	CListCtrl io_memory_word_h;
	CListCtrl io_memory_word_l;
	afx_msg void OnNMCustomdrawListWordH(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawListWordL(NMHDR *pNMHDR, LRESULT *pResult);
	CMyEdit m_s3, m_s4;
	unsigned long word, word_h, word_l;
	unsigned int bit;
	CString mem_word_h, mem_word_l;
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
