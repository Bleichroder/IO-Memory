// MyEdit.cpp : 实现文件
//

#include "stdafx.h"
#include "io_memory.h"
#include "MyEdit.h"
#include "io_memoryDlg.h"


// CMyEdit

IMPLEMENT_DYNAMIC(CMyEdit, CEdit)

CMyEdit::CMyEdit()
{

}

CMyEdit::~CMyEdit()
{
}


BEGIN_MESSAGE_MAP(CMyEdit, CEdit)
	ON_WM_CHAR()
END_MESSAGE_MAP()



// CMyEdit 消息处理程序




void CMyEdit::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	if(nChar == 0x8 || (nChar > 0x2f && nChar < 0x3a) || (nChar > 0x60 && nChar < 0x67))
	{
		CEdit::OnChar(nChar, nRepCnt, nFlags);
		if(GetFocus()->GetDlgCtrlID() == IDC_EDIT2 || GetFocus()->GetDlgCtrlID() == IDC_EDIT3 || GetFocus()->GetDlgCtrlID() == IDC_EDIT4 || GetFocus()->GetDlgCtrlID() == IDC_EDIT5 ||GetFocus()->GetDlgCtrlID() == IDC_EDIT6 || GetFocus()->GetDlgCtrlID() == IDC_EDIT7 || GetFocus()->GetDlgCtrlID() == IDC_EDIT8)
			PostMessage(WM_KEYDOWN, 0x1, 0); 
	}
	else
		return;
}