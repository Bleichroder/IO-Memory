// Io_add.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "io_memory.h"
#include "Io_add.h"
#include "afxdialogex.h"


// CIo_add �Ի���

IMPLEMENT_DYNAMIC(CIo_add, CDialogEx)

CIo_add::CIo_add(CWnd* pParent /*=NULL*/)
	: CDialogEx(CIo_add::IDD, pParent)
{

}

CIo_add::~CIo_add()
{
}

void CIo_add::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT11, m_s11);
}


BEGIN_MESSAGE_MAP(CIo_add, CDialogEx)
	ON_BN_CLICKED(IDOK, &CIo_add::OnBnClickedOk)
END_MESSAGE_MAP()


// CIo_add ��Ϣ�������


void CIo_add::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	GetDlgItemText(IDC_EDIT11, CGlobalData::io_mem_address);
	CDialogEx::OnOK();
}

BOOL CIo_add::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	SetDlgItemText(IDC_EDIT11, _T("0"));
	m_s11.SetLimitText(4);
	return TRUE;
}

BOOL CIo_add::PreTranslateMessage(MSG* pMsg)
{
	// TODO: �ڴ����ר�ô����/����û���

	if ( pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_RETURN )
	{  
		switch( GetFocus()->GetDlgCtrlID())
		{  
		case IDC_EDIT11: 
			PostMessage(WM_COMMAND, MAKEWPARAM(IDOK, BN_CLICKED), NULL);
			break;

		default:
			break;
		}

		return TRUE;

	}
	return CDialogEx::PreTranslateMessage(pMsg);
}