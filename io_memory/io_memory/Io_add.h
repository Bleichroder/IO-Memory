#pragma once
#include "MyEdit.h"
#include "GlobalData.h"


// CIo_add �Ի���

class CIo_add : public CDialogEx
{
	DECLARE_DYNAMIC(CIo_add)

public:
	CIo_add(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CIo_add();

// �Ի�������
	enum { IDD = IDD_IO_ADDRESS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()

public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	CMyEdit m_s11;
	afx_msg void OnBnClickedOk();
};
