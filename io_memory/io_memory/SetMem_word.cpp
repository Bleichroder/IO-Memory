// SetMem_word.cpp : 实现文件
//

#include "stdafx.h"
#include "io_memory.h"
#include "SetMem_word.h"
#include "afxdialogex.h"


// CSetMem_word 对话框

IMPLEMENT_DYNAMIC(CSetMem_word, CDialogEx)

CSetMem_word::CSetMem_word(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSetMem_word::IDD, pParent)
{

}

CSetMem_word::~CSetMem_word()
{
}

void CSetMem_word::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_WORD_H, io_memory_word_h);
	DDX_Control(pDX, IDC_LIST_WORD_L, io_memory_word_l);
	DDX_Control(pDX, IDC_EDIT3, m_s3);
	DDX_Control(pDX, IDC_EDIT4, m_s4);
}


BEGIN_MESSAGE_MAP(CSetMem_word, CDialogEx)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_LIST_WORD_H, &CSetMem_word::OnNMCustomdrawListWordH)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_LIST_WORD_L, &CSetMem_word::OnNMCustomdrawListWordL)
END_MESSAGE_MAP()


// CSetMem_word 消息处理程序


BOOL CSetMem_word::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	CRect rect;
	io_memory_word_h.GetClientRect(&rect);

	io_memory_word_h.SetExtendedStyle(io_memory_word_h.GetExtendedStyle() | LVS_EX_GRIDLINES);

	io_memory_word_h.InsertColumn(0, _T(""), LVCFMT_CENTER, 0, 0);
	io_memory_word_h.InsertColumn(1, _T("7"), LVCFMT_CENTER, rect.Width()/8, 1);
	io_memory_word_h.InsertColumn(2, _T("6"), LVCFMT_CENTER, rect.Width()/8, 2);
	io_memory_word_h.InsertColumn(3, _T("5"), LVCFMT_CENTER, rect.Width()/8, 3);
	io_memory_word_h.InsertColumn(4, _T("4"), LVCFMT_CENTER, rect.Width()/8, 4);
	io_memory_word_h.InsertColumn(5, _T("3"), LVCFMT_CENTER, rect.Width()/8, 5);
	io_memory_word_h.InsertColumn(6, _T("2"), LVCFMT_CENTER, rect.Width()/8, 6);
	io_memory_word_h.InsertColumn(7, _T("1"), LVCFMT_CENTER, rect.Width()/8, 7);
	io_memory_word_h.InsertColumn(8, _T("0"), LVCFMT_CENTER, rect.Width()/8, 8);

	io_memory_word_h.InsertItem(0, _T(""));
	io_memory_word_h.InsertItem(1, _T(""));

	io_memory_word_h.SetItemText(0, 1, _T("15"));
	io_memory_word_h.SetItemText(0, 2, _T("14"));
	io_memory_word_h.SetItemText(0, 3, _T("13"));
	io_memory_word_h.SetItemText(0, 4, _T("12"));
	io_memory_word_h.SetItemText(0, 5, _T("11"));
	io_memory_word_h.SetItemText(0, 6, _T("10"));
	io_memory_word_h.SetItemText(0, 7, _T("9"));
	io_memory_word_h.SetItemText(0, 8, _T("8"));

	io_memory_word_l.GetClientRect(&rect);

	io_memory_word_l.SetExtendedStyle(io_memory_word_l.GetExtendedStyle() | LVS_EX_GRIDLINES);

	io_memory_word_l.InsertColumn(0, _T(""), LVCFMT_CENTER, 0, 0);
	io_memory_word_l.InsertColumn(1, _T("7"), LVCFMT_CENTER, rect.Width()/8, 1);
	io_memory_word_l.InsertColumn(2, _T("6"), LVCFMT_CENTER, rect.Width()/8, 2);
	io_memory_word_l.InsertColumn(3, _T("5"), LVCFMT_CENTER, rect.Width()/8, 3);
	io_memory_word_l.InsertColumn(4, _T("4"), LVCFMT_CENTER, rect.Width()/8, 4);
	io_memory_word_l.InsertColumn(5, _T("3"), LVCFMT_CENTER, rect.Width()/8, 5);
	io_memory_word_l.InsertColumn(6, _T("2"), LVCFMT_CENTER, rect.Width()/8, 6);
	io_memory_word_l.InsertColumn(7, _T("1"), LVCFMT_CENTER, rect.Width()/8, 7);
	io_memory_word_l.InsertColumn(8, _T("0"), LVCFMT_CENTER, rect.Width()/8, 8);

	io_memory_word_l.InsertItem(0, _T(""));
	io_memory_word_l.InsertItem(1, _T(""));

	io_memory_word_l.SetItemText(0, 1, _T("7"));
	io_memory_word_l.SetItemText(0, 2, _T("6"));
	io_memory_word_l.SetItemText(0, 3, _T("5"));
	io_memory_word_l.SetItemText(0, 4, _T("4"));
	io_memory_word_l.SetItemText(0, 5, _T("3"));
	io_memory_word_l.SetItemText(0, 6, _T("2"));
	io_memory_word_l.SetItemText(0, 7, _T("1"));
	io_memory_word_l.SetItemText(0, 8, _T("0"));

	word = _tcstoul(CGlobalData::mem_byte, 0, 16);
	int i;
	for(i = 0; i < 8; i++)
	{
		bit = (word>>i)&0x1;
		mem_word_l.Format(_T("%01x"),bit);
		io_memory_word_l.SetItemText(1, 8-i, mem_word_l);
	}

	for(i = 8; i < 16; i++)
	{
		bit = (word>>i)&0x1;
		mem_word_h.Format(_T("%01x"),bit);
		io_memory_word_h.SetItemText(1, 16-i, mem_word_h);
	}

	m_s3.SetLimitText(2);
	m_s4.SetLimitText(2);

	word_h = (word>>8) & 0xff;
	word_l = word & 0xff;
	mem_word_l.Format(_T("%02X"), word_l);
	mem_word_h.Format(_T("%02X"), word_h);
	SetDlgItemText(IDC_EDIT3, mem_word_h);
	SetDlgItemText(IDC_EDIT4, mem_word_l);

	return TRUE; 
}

void CSetMem_word::OnNMCustomdrawListWordH(NMHDR *pNMHDR, LRESULT *pResult)
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


void CSetMem_word::OnNMCustomdrawListWordL(NMHDR *pNMHDR, LRESULT *pResult)
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

BOOL CSetMem_word::PreTranslateMessage(MSG* pMsg)
{
	if ( pMsg->message == WM_KEYDOWN )
	{  		
		if(pMsg->wParam == VK_RETURN)
		{
			switch( GetFocus()->GetDlgCtrlID())
			{  
			case IDC_EDIT3:
			case IDC_EDIT4:
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
			case IDC_EDIT3: 
				GetDlgItemText(IDC_EDIT3, mem_word_h);
				word_h = _tcstoul(mem_word_h, 0, 16);
				for(i = 0; i < 8; i++)
				{
					bit = (word_h>>i)&0x1;
					mem_word_h.Format(_T("%01x"),bit);
					io_memory_word_h.SetItemText(1, 8-i, mem_word_h);
				}
				GetDlgItemText(IDC_EDIT3, mem_word_h);
				GetDlgItemText(IDC_EDIT4, mem_word_l);
				CGlobalData::mem_byte = mem_word_h + mem_word_l;
				return CDialogEx::PreTranslateMessage(pMsg);
				break;

			case IDC_EDIT4: 
				GetDlgItemText(IDC_EDIT4, mem_word_l);
				word_l = _tcstoul(mem_word_l, 0, 16);
				for(i = 0; i < 8; i++)
				{
					bit = (word_l>>i)&0x1;
					mem_word_l.Format(_T("%01x"),bit);
					io_memory_word_l.SetItemText(1, 8-i, mem_word_l);
				}
				GetDlgItemText(IDC_EDIT3, mem_word_h);
				GetDlgItemText(IDC_EDIT4, mem_word_l);
				CGlobalData::mem_byte = mem_word_h + mem_word_l;
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