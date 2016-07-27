// SetMem_dword.cpp : 实现文件
//

#include "stdafx.h"
#include "io_memory.h"
#include "SetMem_dword.h"
#include "afxdialogex.h"


// CSetMem_dword 对话框

IMPLEMENT_DYNAMIC(CSetMem_dword, CDialogEx)

CSetMem_dword::CSetMem_dword(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSetMem_dword::IDD, pParent)
{

}

CSetMem_dword::~CSetMem_dword()
{
}

void CSetMem_dword::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_DWORD_1, io_memory_dword_1);
	DDX_Control(pDX, IDC_LIST_DWORD_2, io_memory_dword_2);
	DDX_Control(pDX, IDC_LIST_DWORD_3, io_memory_dword_3);
	DDX_Control(pDX, IDC_LIST_DWORD_4, io_memory_dword_4);
	DDX_Control(pDX, IDC_EDIT5, m_s5);
	DDX_Control(pDX, IDC_EDIT6, m_s6);
	DDX_Control(pDX, IDC_EDIT7, m_s7);
	DDX_Control(pDX, IDC_EDIT8, m_s8);
}


BEGIN_MESSAGE_MAP(CSetMem_dword, CDialogEx)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_LIST_DWORD_1, &CSetMem_dword::OnNMCustomdrawListDword1)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_LIST_DWORD_2, &CSetMem_dword::OnNMCustomdrawListDword2)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_LIST_DWORD_3, &CSetMem_dword::OnNMCustomdrawListDword3)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_LIST_DWORD_4, &CSetMem_dword::OnNMCustomdrawListDword4)
END_MESSAGE_MAP()


// CSetMem_dword 消息处理程序


BOOL CSetMem_dword::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	CRect rect;
	io_memory_dword_1.GetClientRect(&rect);

	io_memory_dword_1.SetExtendedStyle(io_memory_dword_1.GetExtendedStyle() | LVS_EX_GRIDLINES);
	io_memory_dword_1.InsertColumn(0, _T(""), LVCFMT_CENTER, 0, 0);
	io_memory_dword_1.InsertColumn(1, _T("7"), LVCFMT_CENTER, rect.Width()/8, 1);
	io_memory_dword_1.InsertColumn(2, _T("6"), LVCFMT_CENTER, rect.Width()/8, 2);
	io_memory_dword_1.InsertColumn(3, _T("5"), LVCFMT_CENTER, rect.Width()/8, 3);
	io_memory_dword_1.InsertColumn(4, _T("4"), LVCFMT_CENTER, rect.Width()/8, 4);
	io_memory_dword_1.InsertColumn(5, _T("3"), LVCFMT_CENTER, rect.Width()/8, 5);
	io_memory_dword_1.InsertColumn(6, _T("2"), LVCFMT_CENTER, rect.Width()/8, 6);
	io_memory_dword_1.InsertColumn(7, _T("1"), LVCFMT_CENTER, rect.Width()/8, 7);
	io_memory_dword_1.InsertColumn(8, _T("0"), LVCFMT_CENTER, rect.Width()/8, 8);

	io_memory_dword_1.InsertItem(0, _T(""));
	io_memory_dword_1.InsertItem(1, _T(""));

	io_memory_dword_1.SetItemText(0, 1, _T("31"));
	io_memory_dword_1.SetItemText(0, 2, _T("30"));
	io_memory_dword_1.SetItemText(0, 3, _T("29"));
	io_memory_dword_1.SetItemText(0, 4, _T("28"));
	io_memory_dword_1.SetItemText(0, 5, _T("27"));
	io_memory_dword_1.SetItemText(0, 6, _T("26"));
	io_memory_dword_1.SetItemText(0, 7, _T("25"));
	io_memory_dword_1.SetItemText(0, 8, _T("24"));

	io_memory_dword_2.GetClientRect(&rect);

	io_memory_dword_2.SetExtendedStyle(io_memory_dword_2.GetExtendedStyle() | LVS_EX_GRIDLINES);
	io_memory_dword_2.InsertColumn(0, _T(""), LVCFMT_CENTER, 0, 0);
	io_memory_dword_2.InsertColumn(1, _T("7"), LVCFMT_CENTER, rect.Width()/8, 1);
	io_memory_dword_2.InsertColumn(2, _T("6"), LVCFMT_CENTER, rect.Width()/8, 2);
	io_memory_dword_2.InsertColumn(3, _T("5"), LVCFMT_CENTER, rect.Width()/8, 3);
	io_memory_dword_2.InsertColumn(4, _T("4"), LVCFMT_CENTER, rect.Width()/8, 4);
	io_memory_dword_2.InsertColumn(5, _T("3"), LVCFMT_CENTER, rect.Width()/8, 5);
	io_memory_dword_2.InsertColumn(6, _T("2"), LVCFMT_CENTER, rect.Width()/8, 6);
	io_memory_dword_2.InsertColumn(7, _T("1"), LVCFMT_CENTER, rect.Width()/8, 7);
	io_memory_dword_2.InsertColumn(8, _T("0"), LVCFMT_CENTER, rect.Width()/8, 8);

	io_memory_dword_2.InsertItem(0, _T(""));
	io_memory_dword_2.InsertItem(1, _T(""));

	io_memory_dword_2.SetItemText(0, 1, _T("23"));
	io_memory_dword_2.SetItemText(0, 2, _T("22"));
	io_memory_dword_2.SetItemText(0, 3, _T("21"));
	io_memory_dword_2.SetItemText(0, 4, _T("20"));
	io_memory_dword_2.SetItemText(0, 5, _T("19"));
	io_memory_dword_2.SetItemText(0, 6, _T("18"));
	io_memory_dword_2.SetItemText(0, 7, _T("17"));
	io_memory_dword_2.SetItemText(0, 8, _T("16"));

	io_memory_dword_3.GetClientRect(&rect);

	io_memory_dword_3.SetExtendedStyle(io_memory_dword_3.GetExtendedStyle() | LVS_EX_GRIDLINES);
	io_memory_dword_3.InsertColumn(0, _T(""), LVCFMT_CENTER, 0, 0);
	io_memory_dword_3.InsertColumn(1, _T("7"), LVCFMT_CENTER, rect.Width()/8, 1);
	io_memory_dword_3.InsertColumn(2, _T("6"), LVCFMT_CENTER, rect.Width()/8, 2);
	io_memory_dword_3.InsertColumn(3, _T("5"), LVCFMT_CENTER, rect.Width()/8, 3);
	io_memory_dword_3.InsertColumn(4, _T("4"), LVCFMT_CENTER, rect.Width()/8, 4);
	io_memory_dword_3.InsertColumn(5, _T("3"), LVCFMT_CENTER, rect.Width()/8, 5);
	io_memory_dword_3.InsertColumn(6, _T("2"), LVCFMT_CENTER, rect.Width()/8, 6);
	io_memory_dword_3.InsertColumn(7, _T("1"), LVCFMT_CENTER, rect.Width()/8, 7);
	io_memory_dword_3.InsertColumn(8, _T("0"), LVCFMT_CENTER, rect.Width()/8, 8);

	io_memory_dword_3.InsertItem(0, _T(""));
	io_memory_dword_3.InsertItem(1, _T(""));

	io_memory_dword_3.SetItemText(0, 1, _T("15"));
	io_memory_dword_3.SetItemText(0, 2, _T("14"));
	io_memory_dword_3.SetItemText(0, 3, _T("13"));
	io_memory_dword_3.SetItemText(0, 4, _T("12"));
	io_memory_dword_3.SetItemText(0, 5, _T("11"));
	io_memory_dword_3.SetItemText(0, 6, _T("10"));
	io_memory_dword_3.SetItemText(0, 7, _T("9"));
	io_memory_dword_3.SetItemText(0, 8, _T("8"));

	io_memory_dword_4.GetClientRect(&rect);

	io_memory_dword_4.SetExtendedStyle(io_memory_dword_4.GetExtendedStyle() | LVS_EX_GRIDLINES);
	io_memory_dword_4.InsertColumn(0, _T(""), LVCFMT_CENTER, 0, 0);
	io_memory_dword_4.InsertColumn(1, _T("7"), LVCFMT_CENTER, rect.Width()/8, 1);
	io_memory_dword_4.InsertColumn(2, _T("6"), LVCFMT_CENTER, rect.Width()/8, 2);
	io_memory_dword_4.InsertColumn(3, _T("5"), LVCFMT_CENTER, rect.Width()/8, 3);
	io_memory_dword_4.InsertColumn(4, _T("4"), LVCFMT_CENTER, rect.Width()/8, 4);
	io_memory_dword_4.InsertColumn(5, _T("3"), LVCFMT_CENTER, rect.Width()/8, 5);
	io_memory_dword_4.InsertColumn(6, _T("2"), LVCFMT_CENTER, rect.Width()/8, 6);
	io_memory_dword_4.InsertColumn(7, _T("1"), LVCFMT_CENTER, rect.Width()/8, 7);
	io_memory_dword_4.InsertColumn(8, _T("0"), LVCFMT_CENTER, rect.Width()/8, 8);

	io_memory_dword_4.InsertItem(0, _T(""));
	io_memory_dword_4.InsertItem(1, _T(""));

	io_memory_dword_4.SetItemText(0, 1, _T("7"));
	io_memory_dword_4.SetItemText(0, 2, _T("6"));
	io_memory_dword_4.SetItemText(0, 3, _T("5"));
	io_memory_dword_4.SetItemText(0, 4, _T("4"));
	io_memory_dword_4.SetItemText(0, 5, _T("3"));
	io_memory_dword_4.SetItemText(0, 6, _T("2"));
	io_memory_dword_4.SetItemText(0, 7, _T("1"));
	io_memory_dword_4.SetItemText(0, 8, _T("0"));

	dword = _tcstoul(CGlobalData::mem_byte, 0, 16);
	int i;
	for(i = 0; i < 8; i++)
	{
		bit = (dword>>i)&0x1;
		mem_dword.Format(_T("%01x"),bit);
		io_memory_dword_4.SetItemText(1, 8-i, mem_dword);
	}

	for(i = 8; i < 16; i++)
	{
		bit = (dword>>i)&0x1;
		mem_dword.Format(_T("%01x"),bit);
		io_memory_dword_3.SetItemText(1, 16-i, mem_dword);
	}

	for(i = 16; i < 24; i++)
	{
		bit = (dword>>i)&0x1;
		mem_dword.Format(_T("%01x"),bit);
		io_memory_dword_2.SetItemText(1, 24-i, mem_dword);
	}

	for(i = 24; i < 32; i++)
	{
		bit = (dword>>i)&0x1;
		mem_dword.Format(_T("%01x"),bit);
		io_memory_dword_1.SetItemText(1, 32-i, mem_dword);
	}

	m_s5.SetLimitText(2);
	m_s6.SetLimitText(2);
	m_s7.SetLimitText(2);
	m_s8.SetLimitText(2);

	dword_1 = (dword>>24) & 0xff;
	dword_2 = (dword>>16) & 0xff;
	dword_3 = (dword>>8) & 0xff;
	dword_4 = dword & 0xff;
	mem_dword.Format(_T("%02X"), dword_1);
	SetDlgItemText(IDC_EDIT5, mem_dword);
	mem_dword.Format(_T("%02X"), dword_2);
	SetDlgItemText(IDC_EDIT6, mem_dword);
	mem_dword.Format(_T("%02X"), dword_3);
	SetDlgItemText(IDC_EDIT7, mem_dword);
	mem_dword.Format(_T("%02X"), dword_4);
	SetDlgItemText(IDC_EDIT8, mem_dword);

	return TRUE; 
}

void CSetMem_dword::OnNMCustomdrawListDword1(NMHDR *pNMHDR, LRESULT *pResult)
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


void CSetMem_dword::OnNMCustomdrawListDword2(NMHDR *pNMHDR, LRESULT *pResult)
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
			pLVCD->clrTextBk = RGB(140,140,140);	//背景粉
		}
		else
		{
			pLVCD->clrText = RGB(125,125,125);	//灰
			pLVCD->clrTextBk = RGB(240,240,240);	//背景灰
		}
		*pResult = CDRF_DODEFAULT;
	}
}


void CSetMem_dword::OnNMCustomdrawListDword3(NMHDR *pNMHDR, LRESULT *pResult)
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


void CSetMem_dword::OnNMCustomdrawListDword4(NMHDR *pNMHDR, LRESULT *pResult)
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
			pLVCD->clrTextBk = RGB(140,140,140);	//背景粉
		}
		else
		{
			pLVCD->clrText = RGB(125,125,125);	//灰
			pLVCD->clrTextBk = RGB(240,240,240);	//背景灰
		}
		*pResult = CDRF_DODEFAULT;
	}
}

BOOL CSetMem_dword::PreTranslateMessage(MSG* pMsg)
{
	if ( pMsg->message == WM_KEYDOWN )
	{  		
		if(pMsg->wParam == VK_RETURN)
		{
			switch( GetFocus()->GetDlgCtrlID())
			{  
			case IDC_EDIT5:
			case IDC_EDIT6:
			case IDC_EDIT7:
			case IDC_EDIT8:
				PostMessage(WM_COMMAND, MAKEWPARAM(IDOK, BN_CLICKED), NULL);
				break;

			default:
				break;
			}
			return TRUE;
		}
		else if(pMsg->wParam == 0x1)
		{
			int i;
			switch( GetFocus()->GetDlgCtrlID())
			{  
			case IDC_EDIT5: 
				GetDlgItemText(IDC_EDIT5, mem_dword);
				dword = _tcstoul(mem_dword, 0, 16);
				for(i = 0; i < 8; i++)
				{
					bit = (dword>>i)&0x1;
					mem_dword.Format(_T("%01x"),bit);
					io_memory_dword_1.SetItemText(1, 8-i, mem_dword);
				}
				GetDlgItemText(IDC_EDIT5, mem_dword);
				CGlobalData::mem_byte = mem_dword;
				GetDlgItemText(IDC_EDIT6, mem_dword);
				CGlobalData::mem_byte += mem_dword;
				GetDlgItemText(IDC_EDIT7, mem_dword);
				CGlobalData::mem_byte += mem_dword;
				GetDlgItemText(IDC_EDIT8, mem_dword);
				CGlobalData::mem_byte += mem_dword;
				return CDialogEx::PreTranslateMessage(pMsg);
				break;

			case IDC_EDIT6: 
				GetDlgItemText(IDC_EDIT6, mem_dword);
				dword = _tcstoul(mem_dword, 0, 16);
				for(i = 0; i < 8; i++)
				{
					bit = (dword>>i)&0x1;
					mem_dword.Format(_T("%01x"),bit);
					io_memory_dword_2.SetItemText(1, 8-i, mem_dword);
				}
				GetDlgItemText(IDC_EDIT5, mem_dword);
				CGlobalData::mem_byte = mem_dword;
				GetDlgItemText(IDC_EDIT6, mem_dword);
				CGlobalData::mem_byte += mem_dword;
				GetDlgItemText(IDC_EDIT7, mem_dword);
				CGlobalData::mem_byte += mem_dword;
				GetDlgItemText(IDC_EDIT8, mem_dword);
				CGlobalData::mem_byte += mem_dword;
				return CDialogEx::PreTranslateMessage(pMsg);
				break;

			case IDC_EDIT7: 
				GetDlgItemText(IDC_EDIT7, mem_dword);
				dword = _tcstoul(mem_dword, 0, 16);
				for(i = 0; i < 8; i++)
				{
					bit = (dword>>i)&0x1;
					mem_dword.Format(_T("%01x"),bit);
					io_memory_dword_3.SetItemText(1, 8-i, mem_dword);
				}
				GetDlgItemText(IDC_EDIT5, mem_dword);
				CGlobalData::mem_byte = mem_dword;
				GetDlgItemText(IDC_EDIT6, mem_dword);
				CGlobalData::mem_byte += mem_dword;
				GetDlgItemText(IDC_EDIT7, mem_dword);
				CGlobalData::mem_byte += mem_dword;
				GetDlgItemText(IDC_EDIT8, mem_dword);
				CGlobalData::mem_byte += mem_dword;
				return CDialogEx::PreTranslateMessage(pMsg);
				break;

			case IDC_EDIT8: 
				GetDlgItemText(IDC_EDIT8, mem_dword);
				dword = _tcstoul(mem_dword, 0, 16);
				for(i = 0; i < 8; i++)
				{
					bit = (dword>>i)&0x1;
					mem_dword.Format(_T("%01x"),bit);
					io_memory_dword_4.SetItemText(1, 8-i, mem_dword);
				}
				GetDlgItemText(IDC_EDIT5, mem_dword);
				CGlobalData::mem_byte = mem_dword;
				GetDlgItemText(IDC_EDIT6, mem_dword);
				CGlobalData::mem_byte += mem_dword;
				GetDlgItemText(IDC_EDIT7, mem_dword);
				CGlobalData::mem_byte += mem_dword;
				GetDlgItemText(IDC_EDIT8, mem_dword);
				CGlobalData::mem_byte += mem_dword;
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