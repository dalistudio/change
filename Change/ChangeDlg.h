
// ChangeDlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include "Tool.h"
#include <vector>
using namespace std;

// CChangeDlg 对话框
class CChangeDlg : public CDialogEx
{
// 构造
public:
	CChangeDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_CHANGE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	// 生产的号码总数
	int m_QTY;

	// 来源的文件路径
	CEdit m_source_path;
	// 来源的浏览按钮
	CButton m_source_but;
	// 来源的文件内容
	CEdit m_source_edit;
	// 目标的文件内容
	CEdit m_target_edit;
	// 号码转换按钮
	CButton m_change_but;
	// 文件保存按钮
	CButton m_save_but;
	// 4转3
	CButton m_c43;
	// 3转2
	CButton m_c32;
	// 3转4
	CButton m_c34;
	// 2转3
	CButton m_c23;
	// 4字转2字
	CButton m_c42;
	// 2字转4字
	CButton m_c24;
	// 平移
	CButton m_c00;
	// 3现转3定
	CButton m_c33;
	// 2现转2定
	CButton m_c22;

	vector<CString> CChangeDlg::SplitCString(CString strSource, char ch);

	afx_msg void OnBnClickedSourceBut();
	afx_msg void OnBnClickedChangeBut();
	// 投注金额
	CEdit m_money;
	afx_msg void OnBnClickedSaveBut();

	// 投注号码的数量
	CEdit m_qty;
	// 金额合计
	CEdit m_total;
	// 号码输入框
	CEdit m_number;
	// 添加号码按钮
	CButton m_add_but;
	// 删除号码按钮
	CButton m_del_but;
	// 来源中的号码数量
	CEdit m_source_qty;
};
