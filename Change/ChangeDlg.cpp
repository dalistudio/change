
// ChangeDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Change.h"
#include "ChangeDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CChangeDlg 对话框




CChangeDlg::CChangeDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CChangeDlg::IDD, pParent)
{
	m_QTY = 0; // 设置生产的号码数量
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CChangeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SOURCE_PATH, m_source_path);
	DDX_Control(pDX, IDC_SOURCE_BUT, m_source_but);
	DDX_Control(pDX, IDC_SOURCE_EDIT, m_source_edit);
	DDX_Control(pDX, IDC_TARGET_EDIT, m_target_edit);
	DDX_Control(pDX, IDC_CHANGE_BUT, m_change_but);
	DDX_Control(pDX, IDC_SAVE_BUT, m_save_but);
	DDX_Control(pDX, IDC_C43, m_c43);
	DDX_Control(pDX, IDC_C32, m_c32);
	DDX_Control(pDX, IDC_C34, m_c34);
	DDX_Control(pDX, IDC_C23, m_c23);
	DDX_Control(pDX, IDC_C42, m_c42);
	DDX_Control(pDX, IDC_C24, m_c24);
	DDX_Control(pDX, IDC_C00, m_c00);
	DDX_Control(pDX, IDC_C33, m_c33);
	DDX_Control(pDX, IDC_C22, m_c22);
	DDX_Control(pDX, IDC_D33, m_d33);
	DDX_Control(pDX, IDC_D32, m_d32);
	DDX_Control(pDX, IDC_D22, m_d22);
	DDX_Control(pDX, IDC_MONEY, m_money);
	DDX_Control(pDX, IDC_QTY, m_qty);
	DDX_Control(pDX, IDC_TOTAL, m_total);
	DDX_Control(pDX, IDC_NUMBER, m_number);
	DDX_Control(pDX, IDC_ADD_BUT, m_add_but);
	DDX_Control(pDX, IDC_DEL_BUT, m_del_but);
	DDX_Control(pDX, IDC_SOURCE_QTY, m_source_qty);
}

BEGIN_MESSAGE_MAP(CChangeDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_SOURCE_BUT, &CChangeDlg::OnBnClickedSourceBut)
	ON_BN_CLICKED(IDC_CHANGE_BUT, &CChangeDlg::OnBnClickedChangeBut)
	ON_BN_CLICKED(IDC_SAVE_BUT, &CChangeDlg::OnBnClickedSaveBut)
END_MESSAGE_MAP()


// CChangeDlg 消息处理程序

BOOL CChangeDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CChangeDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CChangeDlg::OnPaint()
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
HCURSOR CChangeDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

vector<CString> CChangeDlg::SplitCString(CString strSource, char ch)
{   
	CString strTmp;   
	vector<CString> vecString;     
	int n=-1;
	n=strSource.Find(ch); // 找到第一个分隔符的位置
        
    while(n!=-1)
    {
		strTmp=strSource.Left(n); // 从左边开始取字符串到分隔符为止       
		vecString.push_back(strTmp); // 将截取的字符串压入 数组 最后 
		int len = strSource.GetLength(); // 获得原字符串的长度
		strSource=strSource.Right(len -(n+1)); // 从右开始取字符串到第一个字符串为止
		n=strSource.Find(ch); // 查找分隔符位置
    }
	vecString.push_back(strSource); // 压入最后的字符串

    return vecString; // 返回数组
}



// 来源文件浏览按钮
void CChangeDlg::OnBnClickedSourceBut()
{
	// TODO: 在此添加控件通知处理程序代码
	CString FilePathName;
	CFileDialog dlg(
		TRUE, // TRUE为OPEN对话框，FALSE为SAVE AS对话框
		NULL, // 为缺省的扩展名
		NULL, // 为显示在文件名组合框的编辑框的文件名，一般可选NULL 
		OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, // 即隐藏只读选项和覆盖已有文件前提示
		(LPCTSTR)_TEXT("TXT Files (*.txt)|*.txt|All Files (*.*)|*.*||"), // 为下拉列表枢中显示文件类型
		NULL); // 为父窗口指针, 一般可选NULL

	if(dlg.DoModal()==IDOK)
	{
		FilePathName=dlg.GetPathName(); //文件名保存在了FilePathName里
		m_source_path.SetWindowTextA(FilePathName); // 将文件名显示到来源路径框中

		// 打开并加载文件到来源内容框
		CStdioFile myFile;
		CFileException fileException;
		if(myFile.Open(FilePathName,CFile::typeText|CFile::modeRead),&fileException)
		{
			// 读取 TXT 的所有内容
			int len = (int)myFile.GetLength(); // 获得打开文件的长度
			char *context = (char*)malloc(len+2); // 分配内存空间
			memset(context,0,len+2); // 初始化内存空间
			myFile.Read(context,len); // 读取文件内容到内存空间

			CString str = context; // 将内存数据转为字符串
			m_source_edit.SetWindowTextA(str); // 显示文件内容

			free(context); // 释放分配的内存空间
		}
		else
		{
			// 打开文件失败，输出错误信息
			TRACE("Can't open file %s,error=%u\n",FilePathName,fileException.m_cause);
		}


	}
	else
	{
		m_source_path.SetWindowTextA(""); // 如果取消打开文件对话框，则清空路径
		return;
	}
}

// 号码转换按钮
void CChangeDlg::OnBnClickedChangeBut()
{
	// TODO: 在此添加控件通知处理程序代码
	m_QTY = 0;

	if(m_c43.GetCheck()|| m_c32.GetCheck()||m_c34.GetCheck()||m_c23.GetCheck()||m_c24.GetCheck()||m_c42.GetCheck()||m_c00.GetCheck()||m_c33.GetCheck()||m_c22.GetCheck()||m_d33.GetCheck()||m_d32.GetCheck()||m_d22.GetCheck())
	{
		// 必须选择一个转换类型
		//
		// 读取来源内容文本框，并处理
		// 1、按","逗号分隔文本内容，生成数组
		CString str = "";
		m_source_edit.GetWindowTextA(str); // 获取来源文件内容
		str.Replace("\r", ""); // 过滤掉字符串中的换行符号
		str.Replace("\n", ""); // 过滤掉字符串中的换行符号

		vector<CString> arr;
		arr = SplitCString(str,',');

		// 2、按"="等号分隔数组元素，获得投注号码
		int arrLen = arr.size(); // 获得 arr 数组的元素量
		CString strLen;
		strLen.Format("%d",arrLen); 
		m_source_qty.SetWindowTextA(strLen); // 设置来源号码的数量

		CString tempStr = "";
		int flag = 1;
		for(int i=0;i<arrLen;i++)
		{
			vector<CString> num;
			num = SplitCString(arr[i],'='); // 分割号码和金额

		// 3、根据转换类型，将投注号码进行转换

			// 将 CString 转 char*
			CString cstr1 = num[0];
			int strLength = cstr1.GetLength() + 1;
			char *pValue = new char[strLength];
			strncpy(pValue, cstr1, strLength);

			// 号码转换
			CTool *tool = new CTool();
			char *a;

			// 4字转3字
			if(m_c43.GetCheck())
			{
				a = tool->Four2Three(pValue);
			}

			// 3字转2字
			if(m_c32.GetCheck())
			{
				a = tool->Three2Two(pValue);
			}

			// 3字转4字
			if(m_c34.GetCheck())
			{
				a = tool->Three2Four(pValue);
			}

			// 2字转3字
			if(m_c23.GetCheck())
			{
				a = tool->Two2Three(pValue);
			}

			// 2字转4字
			if(m_c24.GetCheck())
			{
				// 2字先转3字
				// 3字再转4字
				a = tool->Two2Four(pValue);
			}

			// 4字转2字
			if(m_c42.GetCheck())
			{
				// 4字先转3字
				// 3字再转2字
				a = tool->Four2Two(pValue);
			}

			// 平移，不做转换
			if(m_c00.GetCheck())
			{
				a = tool->Zero2Zero(pValue);
			}

			// 3字现转3字定
			if(m_c33.GetCheck())
			{
				a = tool->Three2Three(pValue);
			}

			// 2字现转2字定
			if(m_c22.GetCheck())
			{
				a = tool->Two2Two(pValue);
			}

			// 3定转3现
			if(m_d33.GetCheck())
			{
				a = tool->Three2Three_D(pValue);
			}

			// 3定转2现
			if(m_d32.GetCheck())
			{
				a = tool->Three2Two_D(pValue);
			}

			// 2定转2现
			if(m_d22.GetCheck())
			{
				a = tool->Two2Two_D(pValue);
			}

			// 将号码转换成数组
			CString strNumArr = a;
			vector<CString> NumArr;
			NumArr = SplitCString(strNumArr,',');
			int NumArrLen = NumArr.size();
			m_QTY += NumArrLen;
			CString strQty;
			strQty.Format("%d",m_QTY); 
			m_qty.SetWindowTextA(strQty); // 输出号码数量


		// 4、将转换后的号码写入临时内存空间
			for(int i=0;i<NumArrLen;i++)
			{
				// 格式： 号码=金额,号码=金额
				tempStr.Append(NumArr[i]);
				tempStr.Append("=");
				CString moneyStr = "";
				m_money.GetWindowTextA(moneyStr);
				tempStr.Append(moneyStr);
				tempStr.Append(",");
			
				// 每 7 个号码，进行换行
				if(flag == 7)
				{
					tempStr.Append("\n");
					flag=0;
				}
				flag++;
			}
		}
		
		// 5、将临时内存中的数据写入目标内容文本框
		int strlen = tempStr.GetLength();
		tempStr = tempStr.Left(strlen-1);
		m_target_edit.SetWindowTextA(tempStr);

		// 6、获取金额值，并计算合计值
		
		int money = 0; // 单价
		int qty = 0; // 数量
		int total = 0; // 合计

		CString strMoney = "";
		m_money.GetWindowTextA(strMoney);
		
		if(strMoney=="")
		{
			money = 0;
		}

		money = _ttoi(strMoney);
		qty = m_QTY;

		total = money * qty;
		CString strTotal;
		strTotal.Format("%d",total); 
		m_total.SetWindowTextA(strTotal);
		
	}
	else
	{
		// 没有选择转换类型
		AfxMessageBox("请选择一个号码转换的类型\n例如：4字转3字", MB_OK|MB_ICONEXCLAMATION);
	}
}

// 保存文件
void CChangeDlg::OnBnClickedSaveBut()
{
	// TODO: 在此添加控件通知处理程序代码
	char exeFullPath[MAX_PATH]; // MAX_PATH
	GetModuleFileName(NULL,exeFullPath,MAX_PATH);//得到程序模块名称，全路径
	(_tcsrchr(exeFullPath,_T('\\')))[1] = 0; // 删除执行程序的文件名

	// 获得当前时间
	SYSTEMTIME st;
	CString strDateTime;
	GetLocalTime(&st);
	strDateTime.Format("%4d%02d%02d_%02d%02d%02d",st.wYear,st.wMonth,st.wDay,st.wHour,st.wMinute,st.wSecond);

	CString pszFileName = exeFullPath;
	pszFileName += "Change_";
	pszFileName += strDateTime;
	pszFileName += ".txt";

//	char* pszFileName="E:\\myfile.txt";
	CStdioFile myFile;
	CFileException fileException;
	if(myFile.Open(pszFileName,CFile::typeText|CFile::modeCreate|CFile::modeReadWrite),&fileException)
	{
		CString str;
		m_target_edit.GetWindowTextA(str);
		myFile.WriteString(str);
	}
	else
	{
		TRACE("Can't open file %s,error=%u\n",pszFileName,fileException.m_cause);
	}

}
