// Memory_add.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "io_memory.h"
#include "Memory_add.h"
#include "afxdialogex.h"


// CMemory_add �Ի���

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


// CMemory_add ��Ϣ�������


BOOL CMemory_add::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	SetDlgItemText(IDC_EDIT1, _T("0"));
	m_s10.SetLimitText(8);
	return TRUE;
}

void CMemory_add::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	GetDlgItemText(IDC_EDIT1, CGlobalData::io_mem_address);
	CDialogEx::OnOK();
}

BOOL CMemory_add::PreTranslateMessage(MSG* pMsg)
{
	// TODO: �ڴ����ר�ô����/����û���

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