// SetMem.cpp : 实现文件
//

#include "stdafx.h"
#include "io_memory.h"
#include "SetMem.h"
#include "afxdialogex.h"


// CSetMem 对话框

IMPLEMENT_DYNAMIC(CSetMem, CDialogEx)

CSetMem::CSetMem(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSetMem::IDD, pParent)
{
}

CSetMem::~CSetMem()
{
}

void CSetMem::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_BYTE, io_memory_byte);
	DDX_Control(pDX, IDC_EDIT2, m_s2);
}

BOOL CSetMem::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	CRect rect;
	io_memory_byte.GetClientRect(&rect);

	io_memory_byte.SetExtendedStyle(io_memory_byte.GetExtendedStyle() | LVS_EX_GRIDLINES);

	io_memory_byte.InsertColumn(0, _T(""), LVCFMT_CENTER, 0, 0);
	io_memory_byte.InsertColumn(1, _T("7"), LVCFMT_CENTER, rect.Width()/8, 1);
	io_memory_byte.InsertColumn(2, _T("6"), LVCFMT_CENTER, rect.Width()/8, 2);
	io_memory_byte.InsertColumn(3, _T("5"), LVCFMT_CENTER, rect.Width()/8, 3);
	io_memory_byte.InsertColumn(4, _T("4"), LVCFMT_CENTER, rect.Width()/8, 4);
	io_memory_byte.InsertColumn(5, _T("3"), LVCFMT_CENTER, rect.Width()/8, 5);
	io_memory_byte.InsertColumn(6, _T("2"), LVCFMT_CENTER, rect.Width()/8, 6);
	io_memory_byte.InsertColumn(7, _T("1"), LVCFMT_CENTER, rect.Width()/8, 7);
	io_memory_byte.InsertColumn(8, _T("0"), LVCFMT_CENTER, rect.Width()/8, 8);

	io_memory_byte.InsertItem(0, _T(""));
	io_memory_byte.InsertItem(1, _T(""));

	io_memory_byte.SetItemText(0, 1, _T("7"));
	io_memory_byte.SetItemText(0, 2, _T("6"));
	io_memory_byte.SetItemText(0, 3, _T("5"));
	io_memory_byte.SetItemText(0, 4, _T("4"));
	io_memory_byte.SetItemText(0, 5, _T("3"));
	io_memory_byte.SetItemText(0, 6, _T("2"));
	io_memory_byte.SetItemText(0, 7, _T("1"));
	io_memory_byte.SetItemText(0, 8, _T("0"));

	byte = _tcstoul(CGlobalData::mem_byte, 0, 16);
	int i;
	for(i = 0; i < 8; i++)
	{
		bit = (byte>>i)&0x1;
		mem_bit.Format(_T("%01x"),bit);
		io_memory_byte.SetItemText(1, 8-i, mem_bit);
	}

	m_s2.SetLimitText(2);

	SetDlgItemText(IDC_EDIT2, CGlobalData::mem_byte);

	return TRUE;  
}


BEGIN_MESSAGE_MAP(CSetMem, CDialogEx)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_LIST_BYTE, &CSetMem::OnNMCustomdrawListByte)
END_MESSAGE_MAP()


// CSetMem 消息处理程序


void CSetMem::OnNMCustomdrawListByte(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	LPNMLVCUSTOMDRAW pLVCD = reinterpret_cast<LPNMLVCUSTOMDRAW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;

	int iRow = static_cast<int>(pLVCD->nmcd.dwItemSpec);	//行
	int iCol = pLVCD->iSubItem;								//列

	if ( CDDS_PREPAINT == pLVCD->nmcd.dwDrawStage )
	{
		*pResult = CDRF_NOTIFYITEMDRAW;
	}
	else if ( CDDS_ITEMPREPAINT == pLVCD->nmcd.dwDrawStage )
	{
		*pResult = CDRF_NOTIFYSUBITEMDRAW;
	}
	else if	(  pLVCD->nmcd.dwDrawStage == (CDDS_ITEMPREPAINT | CDDS_SUBITEM) )
	{
		if(0 == iRow)
		{
			pLVCD->clrText = RGB(0,0,0);		//黑
			pLVCD->clrTextBk = RGB(255,240,245);	//背景粉
		}
		else
		{
			pLVCD->clrText = RGB(125,125,125);	//灰
			pLVCD->clrTextBk = RGB(240,240,240);	//背景灰
		}
		*pResult = CDRF_DODEFAULT;
	}
}

BOOL CSetMem::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类

	if ( pMsg->message == WM_KEYDOWN )
	{  		
		if(pMsg->wParam == VK_RETURN)
		{
			switch( GetFocus()->GetDlgCtrlID())
			{  
			case IDC_EDIT2: 
				PostMessage(WM_COMMAND, MAKEWPARAM(IDOK, BN_CLICKED), NULL);
				break;

			default:
				break;
			}
			return TRUE;
		}
		else if(pMsg->wParam == 0x1)
		{
			switch( GetFocus()->GetDlgCtrlID())
			{  
			case IDC_EDIT2: 
				GetDlgItemText(IDC_EDIT2, CGlobalData::mem_byte);
				byte = _tcstoul(CGlobalData::mem_byte, 0, 16);
				int i;
				for(i = 0; i < 8; i++)
				{
					bit = (byte>>i)&0x1;
					mem_bit.Format(_T("%01x"),bit);
					io_memory_byte.SetItemText(1, 8-i, mem_bit);
				}
				return CDialogEx::PreTranslateMessage(pMsg);
				break;

			default:
				break;
			}
			return TRUE;
		}
	}

	return CDialogEx::PreTranslateMessage(pMsg);
}