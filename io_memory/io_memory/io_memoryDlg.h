
// io_memoryDlg.h : 头文件
//

#pragma once
#include "afxcmn.h"
#include "MyEdit.h"
#include "SetMem.h"
#include "SetMem_word.h"
#include "SetMem_dword.h"
#include "Memory_add.h"
#include "Io_add.h"

#include "GlobalData.h"


// Cio_memoryDlg 对话框
class Cio_memoryDlg : public CDialogEx
{
// 构造
public:
	Cio_memoryDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_IO_MEMORY_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CListCtrl io_memory_data;
	CMyEdit m_s;
	afx_msg void OnNMCustomdrawListData(NMHDR *pNMHDR, LRESULT *pResult);
	int color_sel[16][16];
	int m_iItem, lastItem; //主项标识符
	int m_iSubItem, lastSubItem; //子项标识符
	BOOL m_bFocus, m_bRefresh, m_breset;
	CString lastdata, currdata;
	unsigned long address;
	afx_msg void OnNMClickListData(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMDblclkListData(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnClickedButton6();
	afx_msg void read_mem(void);
	afx_msg void read_io(void);

	afx_msg void Executecpuid(DWORD eax); // 用来实现cpuid
	DWORD m_eax;   // 存储返回的eax
	DWORD m_ebx;   // 存储返回的ebx
	DWORD m_ecx;   // 存储返回的ecx
	DWORD m_edx;   // 存储返回的edx
//	afx_msg void OnBnClickedButton7();
	//struct stREG
	//{
		//DWORD EAX;
//		DWORD EBX;
	//	DWORD ECX;
		//DWORD EDX;
	//};
};