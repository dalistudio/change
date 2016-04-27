
// ChangeDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include "Tool.h"
#include <vector>
using namespace std;

// CChangeDlg �Ի���
class CChangeDlg : public CDialogEx
{
// ����
public:
	CChangeDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_CHANGE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	// �����ĺ�������
	int m_QTY;

	// ��Դ���ļ�·��
	CEdit m_source_path;
	// ��Դ�������ť
	CButton m_source_but;
	// ��Դ���ļ�����
	CEdit m_source_edit;
	// Ŀ����ļ�����
	CEdit m_target_edit;
	// ����ת����ť
	CButton m_change_but;
	// �ļ����水ť
	CButton m_save_but;
	// 4ת3
	CButton m_c43;
	// 3ת2
	CButton m_c32;
	// 3ת4
	CButton m_c34;
	// 2ת3
	CButton m_c23;
	// 4��ת2��
	CButton m_c42;
	// 2��ת4��
	CButton m_c24;
	// ƽ��
	CButton m_c00;
	// 3��ת3��
	CButton m_c33;
	// 2��ת2��
	CButton m_c22;

	vector<CString> CChangeDlg::SplitCString(CString strSource, char ch);

	afx_msg void OnBnClickedSourceBut();
	afx_msg void OnBnClickedChangeBut();
	// Ͷע���
	CEdit m_money;
	afx_msg void OnBnClickedSaveBut();

	// Ͷע���������
	CEdit m_qty;
	// ���ϼ�
	CEdit m_total;
	// ���������
	CEdit m_number;
	// ��Ӻ��밴ť
	CButton m_add_but;
	// ɾ�����밴ť
	CButton m_del_but;
	// ��Դ�еĺ�������
	CEdit m_source_qty;
};
