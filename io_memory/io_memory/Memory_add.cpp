// Memory_add.cpp : 实现文件
//

#include "stdafx.h"
#include "io_memory.h"
#include "Memory_add.h"
#include "afxdialogex.h"


// CMemory_add 对话框

IMPLEMENT_DYNAMIC(CMemory_add, CDialogEx)

CMemory_add::CMemory_add(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMemory_add::IDD, pParent)
{

}

CMemory_add::~CMemory_add()
{
}

void CMemory_add::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_s10);
}


BEGIN_MESSAGE_MAP(CMemory_add, CDialogEx)
	ON_BN_CLICKED(IDOK, &CMemory_add::OnBnClickedOk)
END_MESSAGE_MAP()


// CMemory_add 消息处理程序


BOOL CMemory_add::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	SetDlgItemText(IDC_EDIT1, _T("0"));
	m_s10.SetLimitText(8);
	return TRUE;
}

void CMemory_add::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	GetDlgItemText(IDC_EDIT1, CGlobalData::io_mem_address);
	CDialogEx::OnOK();
}

BOOL CMemory_add::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类

	if ( pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_RETURN )
	{  
		switch( GetFocus()->GetDlgCtrlID())
		{  
		case IDC_EDIT1: 
			PostMessage(WM_COMMAND, MAKEWPARAM(IDOK, BN_CLICKED), NULL);
			break;

		default:
			break;
		}

		return TRUE;

	}
	return CDialogEx::PreTranslateMessage(pMsg);
}