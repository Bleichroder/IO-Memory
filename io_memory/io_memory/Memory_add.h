#pragma once
#include "MyEdit.h"
#include "GlobalData.h"


// CMemory_add �Ի���

class CMemory_add : public CDialogEx
{
	DECLARE_DYNAMIC(CMemory_add)

public:
	CMemory_add(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CMemory_add();

// �Ի�������
	enum { IDD = IDD_MEMORY_ADDRESS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnBnClickedOk();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	CMyEdit m_s10;
};
