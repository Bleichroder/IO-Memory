
// io_memoryDlg.cpp : 实现文件
//
#include "stdafx.h"
#include "winio.h"
#include "io_memory.h"
#include "io_memoryDlg.h"
#include "afxdialogex.h"
#pragma comment(lib, "WinIo.lib")

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// Cio_memoryDlg 对话框


Cio_memoryDlg::Cio_memoryDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Cio_memoryDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Cio_memoryDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_DATA, io_memory_data);
}

BEGIN_MESSAGE_MAP(Cio_memoryDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &Cio_memoryDlg::OnBnClickedButton1)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_LIST_DATA, &Cio_memoryDlg::OnNMCustomdrawListData)
	ON_NOTIFY(NM_CLICK, IDC_LIST_DATA, &Cio_memoryDlg::OnNMClickListData)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST_DATA, &Cio_memoryDlg::OnNMDblclkListData)
	ON_BN_CLICKED(IDC_BUTTON2, &Cio_memoryDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &Cio_memoryDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &Cio_memoryDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &Cio_memoryDlg::OnBnClickedButton5)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON6, &Cio_memoryDlg::OnBnClickedButton6)
//	ON_BN_CLICKED(IDC_BUTTON7, &Cio_memoryDlg::OnBnClickedButton7)
END_MESSAGE_MAP()


// Cio_memoryDlg 消息处理程序

BOOL Cio_memoryDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	CRect rect;
	io_memory_data.GetClientRect(&rect);

	io_memory_data.SetExtendedStyle(io_memory_data.GetExtendedStyle() | LVS_EX_GRIDLINES);

	//io_memory_data.InsertColumn(0, _T("00"), LVCFMT_CENTER, 0, 0);
	//io_memory_data.DeleteColumn(0);
	io_memory_data.InsertColumn(0, _T(""), LVCFMT_CENTER, 0, 0);
	io_memory_data.InsertColumn(1, _T(""), LVCFMT_CENTER, rect.Width()/17+3, 1);
	io_memory_data.InsertColumn(2, _T("00"), LVCFMT_CENTER, rect.Width()/17, 2);
	io_memory_data.InsertColumn(3, _T("01"), LVCFMT_CENTER, rect.Width()/17, 3);
	io_memory_data.InsertColumn(4, _T("02"), LVCFMT_CENTER, rect.Width()/17, 4);
	io_memory_data.InsertColumn(5, _T("03"), LVCFMT_CENTER, rect.Width()/17, 5);
	io_memory_data.InsertColumn(6, _T("04"), LVCFMT_CENTER, rect.Width()/17, 6);
	io_memory_data.InsertColumn(7, _T("05"), LVCFMT_CENTER, rect.Width()/17, 7);
	io_memory_data.InsertColumn(8, _T("06"), LVCFMT_CENTER, rect.Width()/17, 8);
	io_memory_data.InsertColumn(9, _T("07"), LVCFMT_CENTER, rect.Width()/17, 9);
	io_memory_data.InsertColumn(10, _T("08"), LVCFMT_CENTER, rect.Width()/17, 10);
	io_memory_data.InsertColumn(11, _T("09"), LVCFMT_CENTER, rect.Width()/17, 11);
	io_memory_data.InsertColumn(12, _T("0A"), LVCFMT_CENTER, rect.Width()/17, 12);
	io_memory_data.InsertColumn(13, _T("0B"), LVCFMT_CENTER, rect.Width()/17, 13);
	io_memory_data.InsertColumn(14, _T("0C"), LVCFMT_CENTER, rect.Width()/17, 14);
	io_memory_data.InsertColumn(15, _T("0D"), LVCFMT_CENTER, rect.Width()/17, 15);
	io_memory_data.InsertColumn(16, _T("0E"), LVCFMT_CENTER, rect.Width()/17, 16);
	io_memory_data.InsertColumn(17, _T("0F"), LVCFMT_CENTER, rect.Width()/17, 17);

	io_memory_data.InsertItem(0, _T(""));
	io_memory_data.InsertItem(1, _T("00"));
	io_memory_data.InsertItem(2, _T("01"));
	io_memory_data.InsertItem(3, _T("02"));
	io_memory_data.InsertItem(4, _T("03"));
	io_memory_data.InsertItem(5, _T("04"));
	io_memory_data.InsertItem(6, _T("05"));
	io_memory_data.InsertItem(7, _T("06"));
	io_memory_data.InsertItem(8, _T("07"));
	io_memory_data.InsertItem(9, _T("08"));
	io_memory_data.InsertItem(10, _T("09"));
	io_memory_data.InsertItem(11, _T("0A"));
	io_memory_data.InsertItem(12, _T("0B"));
	io_memory_data.InsertItem(13, _T("0C"));
	io_memory_data.InsertItem(14, _T("0D"));
	io_memory_data.InsertItem(15, _T("0E"));
	io_memory_data.InsertItem(16, _T("0F"));

	io_memory_data.SetItemText(0, 1, _T(""));
	io_memory_data.SetItemText(0, 2, _T("00"));
	io_memory_data.SetItemText(0, 3, _T("01"));
	io_memory_data.SetItemText(0, 4, _T("02"));
	io_memory_data.SetItemText(0, 5, _T("03"));
	io_memory_data.SetItemText(0, 6, _T("04"));
	io_memory_data.SetItemText(0, 7, _T("05"));
	io_memory_data.SetItemText(0, 8, _T("06"));
	io_memory_data.SetItemText(0, 9, _T("07"));
	io_memory_data.SetItemText(0, 10, _T("08"));
	io_memory_data.SetItemText(0, 11, _T("09"));
	io_memory_data.SetItemText(0, 12, _T("0A"));
	io_memory_data.SetItemText(0, 13, _T("0B"));
	io_memory_data.SetItemText(0, 14, _T("0C"));
	io_memory_data.SetItemText(0, 15, _T("0D"));
	io_memory_data.SetItemText(0, 16, _T("0E"));
	io_memory_data.SetItemText(0, 17, _T("0F"));

	io_memory_data.SetItemText(1, 1, _T("00"));
	io_memory_data.SetItemText(2, 1, _T("10"));
	io_memory_data.SetItemText(3, 1, _T("20"));
	io_memory_data.SetItemText(4, 1, _T("30"));
	io_memory_data.SetItemText(5, 1, _T("40"));
	io_memory_data.SetItemText(6, 1, _T("50"));
	io_memory_data.SetItemText(7, 1, _T("60"));
	io_memory_data.SetItemText(8, 1, _T("70"));
	io_memory_data.SetItemText(9, 1, _T("80"));
	io_memory_data.SetItemText(10, 1, _T("90"));
	io_memory_data.SetItemText(11, 1, _T("A0"));
	io_memory_data.SetItemText(12, 1, _T("B0"));
	io_memory_data.SetItemText(13, 1, _T("C0"));
	io_memory_data.SetItemText(14, 1, _T("D0"));
	io_memory_data.SetItemText(15, 1, _T("E0"));
	io_memory_data.SetItemText(16, 1, _T("F0"));

	m_bFocus = 0;
	m_breset = 0;
	m_bRefresh = 0;

	read_mem();
	SetDlgItemText(IDC_ADDRESS, _T("0x0"));
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void Cio_memoryDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR Cio_memoryDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Cio_memoryDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	//InstallWinIoDriver((PWSTR)"WinIo64.sys",0);
	//LoadLibrary(_T("WinIo32.dll"));

	/*wchar_t szWinIoDriverPath[32768], bb[32768];
	PWSTR pszSlash;
	int aa;
	GetModuleFileName(GetModuleHandle(NULL), szWinIoDriverPath, sizeof(szWinIoDriverPath));
	//pszSlash = wcsrchr(szWinIoDriverPath, '\\');
	SetDlgItemText(IDC_EDIT1,szWinIoDriverPath);*/

	CGlobalData::io_mem_read = 1;
	KillTimer(20);

	CMemory_add Memory_add;
	INT_PTR nRes;             // 用于保存DoModal函数的返回值

	nRes = Memory_add.DoModal();  // 弹出对话框

	if (IDCANCEL == nRes)     // 判断对话框退出后返回值是否为IDCANCEL，如果是则return，否则继续向下执行   
		return;
	else if (IDOK == nRes)
	{
		read_mem();
		CString add_disp;
		add_disp = _T("0x") + CGlobalData::io_mem_address;
		SetDlgItemText(IDC_ADDRESS, add_disp);
		m_breset = 0;
		m_bFocus = 0;
		/*WORD io_add = 0x75;
		DWORD io_data, mem_data, mem_add;
		mem_add = 0x40000000;
		if(GetPhysLong((PBYTE)mem_add, &mem_data))
		{
		SetDlgItemText(IDC_EDIT1,_T("ok"));
		}
		if(GetPortVal(io_add, &io_data, 4))
		{
		SetDlgItemText(IDC_EDIT1,_T("ok"));
		}*/
	}
	CString BN_disp;
	GetDlgItemText(IDC_BUTTON6, BN_disp);
	if(BN_disp == _T("Refresh"));
	else if(BN_disp == _T("Stop Refresh"))
	{
		//m_bRefresh = 1;
		SetTimer(20, 2000, NULL);
	}
}

void Cio_memoryDlg::read_mem(void)
{
	if(InitializeWinIo())
	{
		CString add, data;
		add = CGlobalData::io_mem_address;
		if(add == _T(""))
		{
			MessageBox(L"No Address Input", _T("error"), MB_OK);
		}
		else
		{
			address = _tcstoul(add, 0, 16);
			if(address >0xffffff00)
			{
				MessageBox(L"Cant't reach above 4G!", L"error", MB_OK);
				return;
			}
			DWORD mem_data;
			int i ;
			if(CGlobalData::bit_mode == 1)
			{
				for(i = 0; i <256; i++)
				{
					if(GetPhysLong((PBYTE)(address+i), &mem_data))
					{
						mem_data = mem_data & 0xff;
						data.Format(_T("%02X"), mem_data);
						//color_sel[0][0] = 10;
						//io_memory_data.SetItemText(1, 1, _T("be"));
						if(mem_data == 0xff)
							color_sel[i/16][i%16] = 10;
						else if(mem_data == 0)
							color_sel[i/16][i%16] = 11;
						else
							color_sel[i/16][i%16] = 0;
						io_memory_data.SetItemText((i/16+1), (i%16+2), data);
					}
				}
			}
			else if(CGlobalData::bit_mode == 2)
			{
				for(i = 0; i <128; i++)
				{
					if(GetPhysLong((PBYTE)(address+i*2), &mem_data))
					{
						mem_data = mem_data & 0xffff;
						data.Format(_T("%04X"), mem_data);
						//color_sel[0][0] = 10;
						//io_memory_data.SetItemText(1, 1, _T("be"));
						if(mem_data == 0xffff)
							color_sel[i/8][i%8] = 10;
						else if(mem_data == 0)
							color_sel[i/8][i%8] = 11;
						else
							color_sel[i/8][i%8] = 0;
						io_memory_data.SetItemText((i/8+1), (i%8+2), data);
					}
				}
			}
			else if(CGlobalData::bit_mode == 3)
			{
				for(i = 0; i <64; i++)
				{
					if(GetPhysLong((PBYTE)(address+i*4), &mem_data))
					{
						mem_data = mem_data & 0xffffffff;
						data.Format(_T("%08X"), mem_data);
						//color_sel[0][0] = 10;
						//io_memory_data.SetItemText(1, 1, _T("be"));
						if(mem_data == 0xffffffff)
							color_sel[i/4][i%4] = 10;
						else if(mem_data == 0)
							color_sel[i/4][i%4] = 11;
						else
							color_sel[i/4][i%4] = 0;
						io_memory_data.SetItemText((i/4+1), (i%4+2), data);
					}
				}
			}
		}
	}
	else
		MessageBox(L"InitializeWinIo Failed", _T("error"), MB_OK);
}

void Cio_memoryDlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码

	CGlobalData::io_mem_read = 2;
	KillTimer(20);

	CIo_add Io_add;
	INT_PTR nRes;             // 用于保存DoModal函数的返回值

	nRes = Io_add.DoModal();  // 弹出对话框

	if (IDCANCEL == nRes)     // 判断对话框退出后返回值是否为IDCANCEL，如果是则return，否则继续向下执行   
		return;
	else if (IDOK == nRes)
	{
		read_io();
		CString add_disp;
		add_disp = _T("0x") + CGlobalData::io_mem_address;
		SetDlgItemText(IDC_ADDRESS, add_disp);
		m_breset = 0;
		m_bFocus = 0;
	}
	CString BN_disp;
	GetDlgItemText(IDC_BUTTON6, BN_disp);
	if(BN_disp == _T("Refresh"));
	else if(BN_disp == _T("Stop Refresh"))
	{
		//m_bRefresh = 1;
		SetTimer(20, 2000, NULL);
	}
}

void Cio_memoryDlg::read_io(void)
{
	if(InitializeWinIo())
	{
		CString add, data;
		add = CGlobalData::io_mem_address;
		if(add == _T(""))
		{
			MessageBox(L"No Address Input", _T("error"), MB_OK);
		}
		else
		{
			address = _tcstoul(add, 0, 16);
			if(address >0xff00)
			{
				MessageBox(L"Cant't reach above 64K!", L"error", MB_OK);
				return;
			}
			DWORD io_data;
			int i ;
			if(CGlobalData::bit_mode == 1)
			{
				for(i = 0; i <256; i++)
				{
					if(GetPortVal((WORD)(address+i), &io_data, 1))
					{
						io_data = io_data & 0xff;
						data.Format(_T("%02X"), io_data);
						if(io_data == 0xff)
							color_sel[i/16][i%16] = 10;
						else if(io_data == 0)
							color_sel[i/16][i%16] = 11;
						else
							color_sel[i/16][i%16] = 0;
						io_memory_data.SetItemText((i/16+1), (i%16+2), data);
					}
				}
			}
			else if(CGlobalData::bit_mode == 2)
			{
				for(i = 0; i <128; i++)
				{
					io_data = 0;
					DWORD byte_data;
					if(GetPortVal((WORD)(address+i*2), &io_data, 1))
					{
						io_data = io_data & 0xff;
					}
					byte_data = io_data;
					if(GetPortVal((WORD)(address+i*2+1), &io_data, 1))
					{
						io_data = io_data & 0xff;
					}
					byte_data += io_data<<8;
					data.Format(_T("%04X"), byte_data);
					if(byte_data == 0xffff)
						color_sel[i/8][i%8] = 10;
					else if(byte_data == 0)
						color_sel[i/8][i%8] = 11;
					else
						color_sel[i/8][i%8] = 0;
					io_memory_data.SetItemText((i/8+1), (i%8+2), data);

				}
			}
			else if(CGlobalData::bit_mode == 3)
			{
				for(i = 0; i <64; i++)
				{
					io_data = 0;
					DWORD byte_data;
					if(GetPortVal((WORD)(address+i*4), &io_data, 1))
					{
						io_data = io_data & 0xff;
					}
					byte_data = io_data;
					if(GetPortVal((WORD)(address+i*4+1), &io_data, 1))
					{
						io_data = io_data & 0xff;
					}
					byte_data += io_data<<8;
					if(GetPortVal((WORD)(address+i*4+2), &io_data, 1))
					{
						io_data = io_data & 0xff;
					}
					byte_data += io_data<<16;
					if(GetPortVal((WORD)(address+i*4+3), &io_data, 1))
					{
						io_data = io_data & 0xff;
					}
					byte_data += io_data<<24;

					data.Format(_T("%08X"), byte_data);
					if(byte_data == 0xffffffff)
						color_sel[i/4][i%4] = 10;
					else if(byte_data == 0)
						color_sel[i/4][i%4] = 11;
					else
						color_sel[i/4][i%4] = 0;
					io_memory_data.SetItemText((i/4+1), (i%4+2), data);
				}
			}
		}
	}
	else
		MessageBox(L"InitializeWinIo Failed", _T("error"), MB_OK);
}

void Cio_memoryDlg::OnNMCustomdrawListData(NMHDR *pNMHDR, LRESULT *pResult)
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
		if(0 == iCol || 1 == iCol)
		{
			pLVCD->clrTextBk = RGB(255,240,245);		//背景粉
			if(iRow == 0)
				pLVCD->clrText = RGB(240,0,0);
		}
		else
		{
			if(0 == iRow)
				pLVCD->clrTextBk = RGB(255,240,245);	//背景粉
			else if(iCol == m_iSubItem && iRow == m_iItem && iRow > 0 && iCol > 1 && (m_bFocus == 1 || m_breset == 1))
			{
				pLVCD->clrTextBk = RGB(155,155,155);	//选中背景深灰
				m_bFocus = 0;
				m_breset = 1;
				lastdata = currdata;
				lastItem = m_iItem;
				lastSubItem = m_iSubItem;
			}
			else
				pLVCD->clrTextBk = RGB(240,240,240);	//背景灰

			if(color_sel[iRow-1][iCol-2] == 10)
				pLVCD->clrText = RGB(34,110,34);	//绿
			else if(color_sel[iRow-1][iCol-2] == 11)
			{
				pLVCD->clrText = RGB(125,125,125);	//灰
			}
			else if(iRow == 0 || iCol == 1)
				pLVCD->clrText = RGB(0,0,0);		//黑
			else
				pLVCD->clrText = RGB(0,0,150);		//蓝
		}
		*pResult = CDRF_DODEFAULT;
	}
}

void Cio_memoryDlg::OnNMClickListData(NMHDR *pNMHDR, LRESULT *pResult)

{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	LPNMLVCUSTOMDRAW pLVCD = reinterpret_cast<LPNMLVCUSTOMDRAW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;

	DWORD dwPos = GetMessagePos();
	CPoint point( LOWORD(dwPos), HIWORD(dwPos) );
	io_memory_data.ScreenToClient(&point);
	LVHITTESTINFO lvinfo;
	lvinfo.pt = point;
	lvinfo.flags = LVHT_ABOVE;
	int nItem = io_memory_data.SubItemHitTest(&lvinfo); 

	if(nItem != -1)
	{
		m_iItem = lvinfo.iItem;				//行
		m_iSubItem = lvinfo.iSubItem;		//列
	}

	if(m_iItem > 0 && m_iSubItem > 1)
	{
		if(CGlobalData::bit_mode == 1)
		{
			if(CGlobalData::io_mem_read == 1)
			{
				currdata = io_memory_data.GetItemText(m_iItem, m_iSubItem);
				m_bFocus = 1;
				CGlobalData::mem_byte = currdata;
			}
			else if(CGlobalData::io_mem_read == 2)
			{
				currdata = io_memory_data.GetItemText(m_iItem, m_iSubItem);
				m_bFocus = 1;
				CGlobalData::mem_byte = currdata;
			}
			if(m_breset)
			{
				io_memory_data.SetItemText(lastItem, lastSubItem, lastdata);
			}
			io_memory_data.SetItemText(m_iItem, m_iSubItem, currdata);
		}
		else if(CGlobalData::bit_mode == 2)
		{
			if(CGlobalData::io_mem_read == 1)
			{
				currdata = io_memory_data.GetItemText(m_iItem, m_iSubItem);
				m_bFocus = 1;
				CGlobalData::mem_byte = currdata;
			}
			else if(CGlobalData::io_mem_read == 2)
			{
				currdata = io_memory_data.GetItemText(m_iItem, m_iSubItem);
				m_bFocus = 1;
				CGlobalData::mem_byte = currdata;
			}
			if(m_breset)
			{
				io_memory_data.SetItemText(lastItem, lastSubItem, lastdata);
			}
			io_memory_data.SetItemText(m_iItem, m_iSubItem, currdata);
		}
		else if(CGlobalData::bit_mode == 3)
		{
			if(CGlobalData::io_mem_read == 1)
			{
				currdata = io_memory_data.GetItemText(m_iItem, m_iSubItem);
				m_bFocus = 1;
				CGlobalData::mem_byte = currdata;
			}
			else if(CGlobalData::io_mem_read == 2)
			{
				currdata = io_memory_data.GetItemText(m_iItem, m_iSubItem);
				m_bFocus = 1;
				CGlobalData::mem_byte = currdata;
			}
			if(m_breset)
			{
				io_memory_data.SetItemText(lastItem, lastSubItem, lastdata);
			}
			io_memory_data.SetItemText(m_iItem, m_iSubItem, currdata);
		}
		*pResult = CDRF_NOTIFYSUBITEMDRAW;
	}
}


void Cio_memoryDlg::OnNMDblclkListData(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
	
	KillTimer(20);
	if(CGlobalData::bit_mode == 1)
	{
		CSetMem SetMem;

		INT_PTR nRes;             // 用于保存DoModal函数的返回值

		nRes = SetMem.DoModal();  // 弹出对话框

		if (IDCANCEL == nRes)     // 判断对话框退出后返回值是否为IDCANCEL，如果是则return，否则继续向下执行   
		{
			CString BN_disp;
			GetDlgItemText(IDC_BUTTON6, BN_disp);
			if(BN_disp == _T("Refresh"));
			else if(BN_disp == _T("Stop Refresh"))
			{
				//m_bRefresh = 1;
				SetTimer(20, 2000, NULL);
			}
			return;
		}
		else if (IDOK == nRes)
		{
			DWORD io_mem_data;
			unsigned int byte_data;
			if(CGlobalData::io_mem_read == 1)
			{
				GetPhysLong((PBYTE)(address+(m_iItem-1)*16+(m_iSubItem-2)), &io_mem_data);
				byte_data = _tcstoul(CGlobalData::mem_byte, 0, 16);
				byte_data &= 0xff;
				io_mem_data &=0xffffff00;
				io_mem_data |= byte_data;
				SetPhysLong((PBYTE)(address+(m_iItem-1)*16+(m_iSubItem-2)), io_mem_data);
			}
			else if(CGlobalData::io_mem_read == 2)
			{
				byte_data = _tcstoul(CGlobalData::mem_byte, 0, 16);
				byte_data &= 0xff;
				io_mem_data = byte_data;
				SetPortVal((WORD)(address+(m_iItem-1)*16+(m_iSubItem-2)), io_mem_data, 1);
			}

			CString new_byte;
			new_byte.Format(_T("%02X"), byte_data);
			if(byte_data == 0xff)
				color_sel[m_iItem-1][m_iSubItem-2] = 10;
			else if(byte_data == 0)
				color_sel[m_iItem-1][m_iSubItem-2] = 11;
			else
				color_sel[m_iItem-1][m_iSubItem-2] = 0;
			io_memory_data.SetItemText(m_iItem, m_iSubItem, new_byte);
			currdata = new_byte;

			CString BN_disp;
			GetDlgItemText(IDC_BUTTON6, BN_disp);
			if(BN_disp == _T("Refresh"));
			else if(BN_disp == _T("Stop Refresh"))
			{
				//m_bRefresh = 1;
				SetTimer(20, 2000, NULL);
			}
		}
	}

	else if(CGlobalData::bit_mode == 2)
	{
		CSetMem_word SetMem_word;

		INT_PTR nRes;             // 用于保存DoModal函数的返回值

		nRes = SetMem_word.DoModal();  // 弹出对话框

		if (IDCANCEL == nRes)     // 判断对话框退出后返回值是否为IDCANCEL，如果是则return，否则继续向下执行   
		{
			CString BN_disp;
			GetDlgItemText(IDC_BUTTON6, BN_disp);
			if(BN_disp == _T("Refresh"));
			else if(BN_disp == _T("Stop Refresh"))
			{
				//m_bRefresh = 1;
				SetTimer(20, 2000, NULL);
			}
			return;
		}
		else if (IDOK == nRes)
		{
			DWORD io_mem_data;
			unsigned int word_data;
			if(CGlobalData::io_mem_read == 1)
			{
				GetPhysLong((PBYTE)(address+(m_iItem-1)*16+(m_iSubItem-2)*2), &io_mem_data);
				word_data = _tcstoul(CGlobalData::mem_byte, 0, 16);
				word_data &= 0xffff;
				io_mem_data &=0xffff0000;
				io_mem_data |= word_data;
				SetPhysLong((PBYTE)(address+(m_iItem-1)*16+(m_iSubItem-2)*2), io_mem_data);
			}
			else if(CGlobalData::io_mem_read == 2)
			{
				word_data = _tcstoul(CGlobalData::mem_byte, 0, 16);
				word_data &= 0xffff;
				io_mem_data = word_data & 0xff;
				SetPortVal((WORD)(address+(m_iItem-1)*16+(m_iSubItem-2)*2), io_mem_data, 1);
				io_mem_data = (word_data>>8) & 0xff;
				SetPortVal((WORD)(address+(m_iItem-1)*16+(m_iSubItem-2)*2+1), io_mem_data, 1);
			}

			CString new_word;
			new_word.Format(_T("%04X"), word_data);
			if(word_data == 0xffff)
				color_sel[m_iItem-1][m_iSubItem-2] = 10;
			else if(word_data == 0)
				color_sel[m_iItem-1][m_iSubItem-2] = 11;
			else
				color_sel[m_iItem-1][m_iSubItem-2] = 0;
			io_memory_data.SetItemText(m_iItem, m_iSubItem, new_word);
			currdata = new_word;

			CString BN_disp;
			GetDlgItemText(IDC_BUTTON6, BN_disp);
			if(BN_disp == _T("Refresh"));
			else if(BN_disp == _T("Stop Refresh"))
			{
				//m_bRefresh = 1;
				SetTimer(20, 2000, NULL);
			}
		}
	}
	else if(CGlobalData::bit_mode == 3)
	{
		CSetMem_dword SetMem_dword;

		INT_PTR nRes;             // 用于保存DoModal函数的返回值

		nRes = SetMem_dword.DoModal();  // 弹出对话框

		if (IDCANCEL == nRes)     // 判断对话框退出后返回值是否为IDCANCEL，如果是则return，否则继续向下执行   
		{
			CString BN_disp;
			GetDlgItemText(IDC_BUTTON6, BN_disp);
			if(BN_disp == _T("Refresh"));
			else if(BN_disp == _T("Stop Refresh"))
			{
				//m_bRefresh = 1;
				SetTimer(20, 2000, NULL);
			}
			return;
		}
		else if (IDOK == nRes)
		{
			DWORD io_mem_data;
			unsigned long dword_data;
			if(CGlobalData::io_mem_read == 1)
			{
				GetPhysLong((PBYTE)(address+(m_iItem-1)*16+(m_iSubItem-2)*4), &io_mem_data);
				dword_data = _tcstoul(CGlobalData::mem_byte, 0, 16);
				dword_data &= 0xffffffff;
				io_mem_data = dword_data;
				SetPhysLong((PBYTE)(address+(m_iItem-1)*16+(m_iSubItem-2)*4), io_mem_data);
			}
			else if(CGlobalData::io_mem_read == 2)
			{
				dword_data = _tcstoul(CGlobalData::mem_byte, 0, 16);
				dword_data &= 0xffffffff;
				io_mem_data = dword_data & 0xff;
				SetPortVal((WORD)(address+(m_iItem-1)*16+(m_iSubItem-2)*4), io_mem_data, 1);
				io_mem_data = (dword_data>>8) & 0xff;
				SetPortVal((WORD)(address+(m_iItem-1)*16+(m_iSubItem-2)*4+1), io_mem_data, 1);
				io_mem_data = (dword_data>>16) & 0xff;
				SetPortVal((WORD)(address+(m_iItem-1)*16+(m_iSubItem-2)*4+2), io_mem_data, 1);
				io_mem_data = (dword_data>>24) & 0xff;
				SetPortVal((WORD)(address+(m_iItem-1)*16+(m_iSubItem-2)*4+3), io_mem_data, 1);
			}

			CString new_dword;
			new_dword.Format(_T("%08X"), dword_data);
			if(dword_data == 0xffffffff)
				color_sel[m_iItem-1][m_iSubItem-2] = 10;
			else if(dword_data == 0)
				color_sel[m_iItem-1][m_iSubItem-2] = 11;
			else
				color_sel[m_iItem-1][m_iSubItem-2] = 0;
			io_memory_data.SetItemText(m_iItem, m_iSubItem, new_dword);
			currdata = new_dword;

			CString BN_disp;
			GetDlgItemText(IDC_BUTTON6, BN_disp);
			if(BN_disp == _T("Refresh"));
			else if(BN_disp == _T("Stop Refresh"))
			{
				//m_bRefresh = 1;
				SetTimer(20, 2000, NULL);
			}
		}
	}
}


void Cio_memoryDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	if(CGlobalData::bit_mode == 1)
		return;
	else
	{
		CGlobalData::bit_mode = 1;

		CRect rect;
		io_memory_data.GetClientRect(&rect);

		io_memory_data.InsertColumn(0, _T(""), LVCFMT_CENTER, 0, 0);
		io_memory_data.InsertColumn(1, _T(""), LVCFMT_CENTER, rect.Width()/17+3, 1);
		io_memory_data.InsertColumn(2, _T("00"), LVCFMT_CENTER, rect.Width()/17, 2);
		io_memory_data.InsertColumn(3, _T("01"), LVCFMT_CENTER, rect.Width()/17, 3);
		io_memory_data.InsertColumn(4, _T("02"), LVCFMT_CENTER, rect.Width()/17, 4);
		io_memory_data.InsertColumn(5, _T("03"), LVCFMT_CENTER, rect.Width()/17, 5);
		io_memory_data.InsertColumn(6, _T("04"), LVCFMT_CENTER, rect.Width()/17, 6);
		io_memory_data.InsertColumn(7, _T("05"), LVCFMT_CENTER, rect.Width()/17, 7);
		io_memory_data.InsertColumn(8, _T("06"), LVCFMT_CENTER, rect.Width()/17, 8);
		io_memory_data.InsertColumn(9, _T("07"), LVCFMT_CENTER, rect.Width()/17, 9);
		io_memory_data.InsertColumn(10, _T("08"), LVCFMT_CENTER, rect.Width()/17, 10);
		io_memory_data.InsertColumn(10, _T("08"), LVCFMT_CENTER, rect.Width()/17, 10);
		io_memory_data.InsertColumn(11, _T("09"), LVCFMT_CENTER, rect.Width()/17, 11);
		io_memory_data.InsertColumn(12, _T("0A"), LVCFMT_CENTER, rect.Width()/17, 12);
		io_memory_data.InsertColumn(13, _T("0B"), LVCFMT_CENTER, rect.Width()/17, 13);
		io_memory_data.InsertColumn(14, _T("0C"), LVCFMT_CENTER, rect.Width()/17, 14);
		io_memory_data.InsertColumn(15, _T("0D"), LVCFMT_CENTER, rect.Width()/17, 15);
		io_memory_data.InsertColumn(16, _T("0E"), LVCFMT_CENTER, rect.Width()/17, 16);
		io_memory_data.InsertColumn(17, _T("0F"), LVCFMT_CENTER, rect.Width()/17, 17);

		io_memory_data.InsertItem(0, _T(""));
		io_memory_data.InsertItem(1, _T("00"));
		io_memory_data.InsertItem(2, _T("01"));
		io_memory_data.InsertItem(3, _T("02"));
		io_memory_data.InsertItem(4, _T("03"));
		io_memory_data.InsertItem(5, _T("04"));
		io_memory_data.InsertItem(6, _T("05"));
		io_memory_data.InsertItem(7, _T("06"));
		io_memory_data.InsertItem(8, _T("07"));
		io_memory_data.InsertItem(9, _T("08"));
		io_memory_data.InsertItem(10, _T("09"));
		io_memory_data.InsertItem(11, _T("0A"));
		io_memory_data.InsertItem(12, _T("0B"));
		io_memory_data.InsertItem(13, _T("0C"));
		io_memory_data.InsertItem(14, _T("0D"));
		io_memory_data.InsertItem(15, _T("0E"));
		io_memory_data.InsertItem(16, _T("0F"));

		io_memory_data.SetItemText(0, 1, _T(""));
		io_memory_data.SetItemText(0, 2, _T("00"));
		io_memory_data.SetItemText(0, 3, _T("01"));
		io_memory_data.SetItemText(0, 4, _T("02"));
		io_memory_data.SetItemText(0, 5, _T("03"));
		io_memory_data.SetItemText(0, 6, _T("04"));
		io_memory_data.SetItemText(0, 7, _T("05"));
		io_memory_data.SetItemText(0, 8, _T("06"));
		io_memory_data.SetItemText(0, 9, _T("07"));
		io_memory_data.SetItemText(0, 10, _T("08"));
		io_memory_data.SetItemText(0, 11, _T("09"));
		io_memory_data.SetItemText(0, 12, _T("0A"));
		io_memory_data.SetItemText(0, 13, _T("0B"));
		io_memory_data.SetItemText(0, 14, _T("0C"));
		io_memory_data.SetItemText(0, 15, _T("0D"));
		io_memory_data.SetItemText(0, 16, _T("0E"));
		io_memory_data.SetItemText(0, 17, _T("0F"));

		io_memory_data.SetItemText(1, 1, _T("00"));
		io_memory_data.SetItemText(2, 1, _T("10"));
		io_memory_data.SetItemText(3, 1, _T("20"));
		io_memory_data.SetItemText(4, 1, _T("30"));
		io_memory_data.SetItemText(5, 1, _T("40"));
		io_memory_data.SetItemText(6, 1, _T("50"));
		io_memory_data.SetItemText(7, 1, _T("60"));
		io_memory_data.SetItemText(8, 1, _T("70"));
		io_memory_data.SetItemText(9, 1, _T("80"));
		io_memory_data.SetItemText(10, 1, _T("90"));
		io_memory_data.SetItemText(11, 1, _T("A0"));
		io_memory_data.SetItemText(12, 1, _T("B0"));
		io_memory_data.SetItemText(13, 1, _T("C0"));
		io_memory_data.SetItemText(14, 1, _T("D0"));
		io_memory_data.SetItemText(15, 1, _T("E0"));
		io_memory_data.SetItemText(16, 1, _T("F0"));

		m_breset = 0;

		if(CGlobalData::io_mem_read == 1)
			read_mem();
		else if(CGlobalData::io_mem_read ==2)
			read_io();
	}
}


void Cio_memoryDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	if(CGlobalData::bit_mode == 2)
		return;
	else
	{
		CGlobalData::bit_mode = 2;

		CRect rect;
		io_memory_data.GetClientRect(&rect);

		io_memory_data.InsertColumn(0, _T(""), LVCFMT_CENTER, 0, 0);
		io_memory_data.InsertColumn(1, _T(""), LVCFMT_CENTER, rect.Width()/9, 1);
		io_memory_data.InsertColumn(2, _T("0100"), LVCFMT_CENTER, rect.Width()/9, 2);
		io_memory_data.InsertColumn(3, _T("0302"), LVCFMT_CENTER, rect.Width()/9, 3);
		io_memory_data.InsertColumn(4, _T("0504"), LVCFMT_CENTER, rect.Width()/9, 4);
		io_memory_data.InsertColumn(5, _T("0706"), LVCFMT_CENTER, rect.Width()/9, 5);
		io_memory_data.InsertColumn(6, _T("0908"), LVCFMT_CENTER, rect.Width()/9, 6);
		io_memory_data.InsertColumn(7, _T("0B0A"), LVCFMT_CENTER, rect.Width()/9, 7);
		io_memory_data.InsertColumn(8, _T("0D0C"), LVCFMT_CENTER, rect.Width()/9, 8);
		io_memory_data.InsertColumn(9, _T("0F0E"), LVCFMT_CENTER, rect.Width()/9, 9);

		io_memory_data.InsertItem(0, _T(""));
		io_memory_data.InsertItem(1, _T("00"));
		io_memory_data.InsertItem(2, _T("01"));
		io_memory_data.InsertItem(3, _T("02"));
		io_memory_data.InsertItem(4, _T("03"));
		io_memory_data.InsertItem(5, _T("04"));
		io_memory_data.InsertItem(6, _T("05"));
		io_memory_data.InsertItem(7, _T("06"));
		io_memory_data.InsertItem(8, _T("07"));
		io_memory_data.InsertItem(9, _T("08"));
		io_memory_data.InsertItem(10, _T("09"));
		io_memory_data.InsertItem(11, _T("0A"));
		io_memory_data.InsertItem(12, _T("0B"));
		io_memory_data.InsertItem(13, _T("0C"));
		io_memory_data.InsertItem(14, _T("0D"));
		io_memory_data.InsertItem(15, _T("0E"));
		io_memory_data.InsertItem(16, _T("0F"));

		io_memory_data.SetItemText(0, 1, _T(""));
		io_memory_data.SetItemText(0, 2, _T("0100"));
		io_memory_data.SetItemText(0, 3, _T("0302"));
		io_memory_data.SetItemText(0, 4, _T("0504"));
		io_memory_data.SetItemText(0, 5, _T("0706"));
		io_memory_data.SetItemText(0, 6, _T("0908"));
		io_memory_data.SetItemText(0, 7, _T("0B0A"));
		io_memory_data.SetItemText(0, 8, _T("0D0C"));
		io_memory_data.SetItemText(0, 9, _T("0F0E"));

		io_memory_data.SetItemText(1, 1, _T("00"));
		io_memory_data.SetItemText(2, 1, _T("10"));
		io_memory_data.SetItemText(3, 1, _T("20"));
		io_memory_data.SetItemText(4, 1, _T("30"));
		io_memory_data.SetItemText(5, 1, _T("40"));
		io_memory_data.SetItemText(6, 1, _T("50"));
		io_memory_data.SetItemText(7, 1, _T("60"));
		io_memory_data.SetItemText(8, 1, _T("70"));
		io_memory_data.SetItemText(9, 1, _T("80"));
		io_memory_data.SetItemText(10, 1, _T("90"));
		io_memory_data.SetItemText(11, 1, _T("A0"));
		io_memory_data.SetItemText(12, 1, _T("B0"));
		io_memory_data.SetItemText(13, 1, _T("C0"));
		io_memory_data.SetItemText(14, 1, _T("D0"));
		io_memory_data.SetItemText(15, 1, _T("E0"));
		io_memory_data.SetItemText(16, 1, _T("F0"));

		m_breset = 0;

		if(CGlobalData::io_mem_read == 1)
			read_mem();
		else if(CGlobalData::io_mem_read ==2)
			read_io();
	}
}


void Cio_memoryDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	if(CGlobalData::bit_mode == 3)
		return;
	else
	{
		CGlobalData::bit_mode = 3;

		CRect rect;
		io_memory_data.GetClientRect(&rect);

		io_memory_data.InsertColumn(0, _T(""), LVCFMT_CENTER, 0, 0);
		io_memory_data.InsertColumn(1, _T(""), LVCFMT_CENTER, rect.Width()/5, 1);
		io_memory_data.InsertColumn(2, _T("03020100"), LVCFMT_CENTER, rect.Width()/5, 2);
		io_memory_data.InsertColumn(3, _T("07060504"), LVCFMT_CENTER, rect.Width()/5, 3);
		io_memory_data.InsertColumn(4, _T("0B0A0908"), LVCFMT_CENTER, rect.Width()/5, 4);
		io_memory_data.InsertColumn(5, _T("0F0E0D0C"), LVCFMT_CENTER, rect.Width()/5, 5);

		io_memory_data.InsertItem(0, _T(""));
		io_memory_data.InsertItem(1, _T("00"));
		io_memory_data.InsertItem(2, _T("01"));
		io_memory_data.InsertItem(3, _T("02"));
		io_memory_data.InsertItem(4, _T("03"));
		io_memory_data.InsertItem(5, _T("04"));
		io_memory_data.InsertItem(6, _T("05"));
		io_memory_data.InsertItem(7, _T("06"));
		io_memory_data.InsertItem(8, _T("07"));
		io_memory_data.InsertItem(9, _T("08"));
		io_memory_data.InsertItem(10, _T("09"));
		io_memory_data.InsertItem(11, _T("0A"));
		io_memory_data.InsertItem(12, _T("0B"));
		io_memory_data.InsertItem(13, _T("0C"));
		io_memory_data.InsertItem(14, _T("0D"));
		io_memory_data.InsertItem(15, _T("0E"));
		io_memory_data.InsertItem(16, _T("0F"));

		io_memory_data.SetItemText(0, 1, _T(""));
		io_memory_data.SetItemText(0, 2, _T("03020100"));
		io_memory_data.SetItemText(0, 3, _T("07060504"));
		io_memory_data.SetItemText(0, 4, _T("0B0A0908"));
		io_memory_data.SetItemText(0, 5, _T("0F0E0D0C"));

		io_memory_data.SetItemText(1, 1, _T("00"));
		io_memory_data.SetItemText(2, 1, _T("10"));
		io_memory_data.SetItemText(3, 1, _T("20"));
		io_memory_data.SetItemText(4, 1, _T("30"));
		io_memory_data.SetItemText(5, 1, _T("40"));
		io_memory_data.SetItemText(6, 1, _T("50"));
		io_memory_data.SetItemText(7, 1, _T("60"));
		io_memory_data.SetItemText(8, 1, _T("70"));
		io_memory_data.SetItemText(9, 1, _T("80"));
		io_memory_data.SetItemText(10, 1, _T("90"));
		io_memory_data.SetItemText(11, 1, _T("A0"));
		io_memory_data.SetItemText(12, 1, _T("B0"));
		io_memory_data.SetItemText(13, 1, _T("C0"));
		io_memory_data.SetItemText(14, 1, _T("D0"));
		io_memory_data.SetItemText(15, 1, _T("E0"));
		io_memory_data.SetItemText(16, 1, _T("F0"));

		m_breset = 0;

		if(CGlobalData::io_mem_read == 1)
			read_mem();
		else if(CGlobalData::io_mem_read ==2)
			read_io();
	}
}

void Cio_memoryDlg::OnTimer(UINT_PTR nIDEvent)
{
	if(nIDEvent == 20)
	{
		if(CGlobalData::io_mem_read == 1)
		{
			read_mem();
		}
		else if(CGlobalData::io_mem_read == 2)
		{
			read_io();
		}
	}
}

void Cio_memoryDlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	if(CGlobalData::io_mem_read == 1)
	{
		read_mem();
	}
	else if(CGlobalData::io_mem_read == 2)
	{
		read_io();
	}
	CString BN_disp;
	GetDlgItemText(IDC_BUTTON6, BN_disp);
	if(BN_disp == _T("Refresh"))
	{
		//if(m_breset == 1)
			//m_bRefresh = 1;
		//else
			//m_bRefresh = 0;
		SetTimer(20, 2000, NULL);
		SetDlgItemText(IDC_BUTTON6, _T("Stop Refresh"));
	}
	else if(BN_disp == _T("Stop Refresh"))
	{
		m_bRefresh = 0;
		KillTimer(20);
		SetDlgItemText(IDC_BUTTON6, _T("Refresh"));
	}
}

/*void Cio_memoryDlg::Executecpuid(DWORD veax)
{
	// 因为嵌入式的汇编代码不能识别 类成员变量
	// 所以定义四个临时变量作为过渡
	DWORD deax;
	DWORD debx;
	DWORD decx;
	DWORD dedx;

	/*__asm
	{
		mov eax, veax ;//将输入参数移入eax
		cpuid  ;//执行cpuid
		mov deax, eax ;//以下四行代码把寄存器中的变量存入临时变量
		mov debx, ebx ;
		mov decx, ecx ;
		mov dedx, edx ;
	}

	m_eax = deax; // 把临时变量中的内容放入类成员变量
	m_ebx = debx;
	m_ecx = decx;
	m_edx = dedx;*/
	/*if(InitializeWinIo())
	{
		stREG msr;
		memset(&msr,0,sizeof(stREG));
		msr.ECX=0x10;	//读取保留地址将引发通用保护异常，引起蓝屏
		//请严格按照CPU手册进行操作
		if(ReadMSR((PVOID *)&msr))
		{
			int a = 0;
			int b =a;
			char c = 'a';
		}
	}
}*/

//void Cio_memoryDlg::OnBnClickedButton7()
//{
//	// TODO: 在此添加控件通知处理程序代码
//	char cVID[13];   // 字符串，用来存储制造商信息
//	memset(cVID, 0, 13);  // 把数组清0
//	Executecpuid(0x10);  // 执行cpuid指令，使用输入参数 eax = 0
//	memcpy(cVID, &m_ebx, 4); // 复制前四个字符到数组
//	memcpy(cVID+4, &m_edx, 4); // 复制中间四个字符到数组
//	memcpy(cVID+8, &m_ecx, 4); // 复制最后四个字符到数组
//	CString cid ;
//	cid.Format(_T("%s"),cVID);
//	SetDlgItemText(IDC_EDIT_CPUID, cid);
//}
