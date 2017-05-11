
// ChangeDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Change.h"
#include "ChangeDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CChangeDlg �Ի���




CChangeDlg::CChangeDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CChangeDlg::IDD, pParent)
{
	m_QTY = 0; // ���������ĺ�������
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


// CChangeDlg ��Ϣ�������

BOOL CChangeDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CChangeDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CChangeDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

vector<CString> CChangeDlg::SplitCString(CString strSource, char ch)
{   
	CString strTmp;   
	vector<CString> vecString;     
	int n=-1;
	n=strSource.Find(ch); // �ҵ���һ���ָ�����λ��
        
    while(n!=-1)
    {
		strTmp=strSource.Left(n); // ����߿�ʼȡ�ַ������ָ���Ϊֹ       
		vecString.push_back(strTmp); // ����ȡ���ַ���ѹ�� ���� ��� 
		int len = strSource.GetLength(); // ���ԭ�ַ����ĳ���
		strSource=strSource.Right(len -(n+1)); // ���ҿ�ʼȡ�ַ�������һ���ַ���Ϊֹ
		n=strSource.Find(ch); // ���ҷָ���λ��
    }
	vecString.push_back(strSource); // ѹ�������ַ���

    return vecString; // ��������
}



// ��Դ�ļ������ť
void CChangeDlg::OnBnClickedSourceBut()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString FilePathName;
	CFileDialog dlg(
		TRUE, // TRUEΪOPEN�Ի���FALSEΪSAVE AS�Ի���
		NULL, // Ϊȱʡ����չ��
		NULL, // Ϊ��ʾ���ļ�����Ͽ�ı༭����ļ�����һ���ѡNULL 
		OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, // ������ֻ��ѡ��͸��������ļ�ǰ��ʾ
		(LPCTSTR)_TEXT("TXT Files (*.txt)|*.txt|All Files (*.*)|*.*||"), // Ϊ�����б�������ʾ�ļ�����
		NULL); // Ϊ������ָ��, һ���ѡNULL

	if(dlg.DoModal()==IDOK)
	{
		FilePathName=dlg.GetPathName(); //�ļ�����������FilePathName��
		m_source_path.SetWindowTextA(FilePathName); // ���ļ�����ʾ����Դ·������

		// �򿪲������ļ�����Դ���ݿ�
		CStdioFile myFile;
		CFileException fileException;
		if(myFile.Open(FilePathName,CFile::typeText|CFile::modeRead),&fileException)
		{
			// ��ȡ TXT ����������
			int len = (int)myFile.GetLength(); // ��ô��ļ��ĳ���
			char *context = (char*)malloc(len+2); // �����ڴ�ռ�
			memset(context,0,len+2); // ��ʼ���ڴ�ռ�
			myFile.Read(context,len); // ��ȡ�ļ����ݵ��ڴ�ռ�

			CString str = context; // ���ڴ�����תΪ�ַ���
			m_source_edit.SetWindowTextA(str); // ��ʾ�ļ�����

			free(context); // �ͷŷ�����ڴ�ռ�
		}
		else
		{
			// ���ļ�ʧ�ܣ����������Ϣ
			TRACE("Can't open file %s,error=%u\n",FilePathName,fileException.m_cause);
		}


	}
	else
	{
		m_source_path.SetWindowTextA(""); // ���ȡ�����ļ��Ի��������·��
		return;
	}
}

// ����ת����ť
void CChangeDlg::OnBnClickedChangeBut()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_QTY = 0;

	if(m_c43.GetCheck()|| m_c32.GetCheck()||m_c34.GetCheck()||m_c23.GetCheck()||m_c24.GetCheck()||m_c42.GetCheck()||m_c00.GetCheck()||m_c33.GetCheck()||m_c22.GetCheck()||m_d33.GetCheck()||m_d32.GetCheck()||m_d22.GetCheck())
	{
		// ����ѡ��һ��ת������
		//
		// ��ȡ��Դ�����ı��򣬲�����
		// 1����","���ŷָ��ı����ݣ���������
		CString str = "";
		m_source_edit.GetWindowTextA(str); // ��ȡ��Դ�ļ�����
		str.Replace("\r", ""); // ���˵��ַ����еĻ��з���
		str.Replace("\n", ""); // ���˵��ַ����еĻ��з���

		vector<CString> arr;
		arr = SplitCString(str,',');

		// 2����"="�Ⱥŷָ�����Ԫ�أ����Ͷע����
		int arrLen = arr.size(); // ��� arr �����Ԫ����
		CString strLen;
		strLen.Format("%d",arrLen); 
		m_source_qty.SetWindowTextA(strLen); // ������Դ���������

		CString tempStr = "";
		int flag = 1;
		for(int i=0;i<arrLen;i++)
		{
			vector<CString> num;
			num = SplitCString(arr[i],'='); // �ָ����ͽ��

		// 3������ת�����ͣ���Ͷע�������ת��

			// �� CString ת char*
			CString cstr1 = num[0];
			int strLength = cstr1.GetLength() + 1;
			char *pValue = new char[strLength];
			strncpy(pValue, cstr1, strLength);

			// ����ת��
			CTool *tool = new CTool();
			char *a;

			// 4��ת3��
			if(m_c43.GetCheck())
			{
				a = tool->Four2Three(pValue);
			}

			// 3��ת2��
			if(m_c32.GetCheck())
			{
				a = tool->Three2Two(pValue);
			}

			// 3��ת4��
			if(m_c34.GetCheck())
			{
				a = tool->Three2Four(pValue);
			}

			// 2��ת3��
			if(m_c23.GetCheck())
			{
				a = tool->Two2Three(pValue);
			}

			// 2��ת4��
			if(m_c24.GetCheck())
			{
				// 2����ת3��
				// 3����ת4��
				a = tool->Two2Four(pValue);
			}

			// 4��ת2��
			if(m_c42.GetCheck())
			{
				// 4����ת3��
				// 3����ת2��
				a = tool->Four2Two(pValue);
			}

			// ƽ�ƣ�����ת��
			if(m_c00.GetCheck())
			{
				a = tool->Zero2Zero(pValue);
			}

			// 3����ת3�ֶ�
			if(m_c33.GetCheck())
			{
				a = tool->Three2Three(pValue);
			}

			// 2����ת2�ֶ�
			if(m_c22.GetCheck())
			{
				a = tool->Two2Two(pValue);
			}

			// 3��ת3��
			if(m_d33.GetCheck())
			{
				a = tool->Three2Three_D(pValue);
			}

			// 3��ת2��
			if(m_d32.GetCheck())
			{
				a = tool->Three2Two_D(pValue);
			}

			// 2��ת2��
			if(m_d22.GetCheck())
			{
				a = tool->Two2Two_D(pValue);
			}

			// ������ת��������
			CString strNumArr = a;
			vector<CString> NumArr;
			NumArr = SplitCString(strNumArr,',');
			int NumArrLen = NumArr.size();
			m_QTY += NumArrLen;
			CString strQty;
			strQty.Format("%d",m_QTY); 
			m_qty.SetWindowTextA(strQty); // �����������


		// 4����ת����ĺ���д����ʱ�ڴ�ռ�
			for(int i=0;i<NumArrLen;i++)
			{
				// ��ʽ�� ����=���,����=���
				tempStr.Append(NumArr[i]);
				tempStr.Append("=");
				CString moneyStr = "";
				m_money.GetWindowTextA(moneyStr);
				tempStr.Append(moneyStr);
				tempStr.Append(",");
			
				// ÿ 7 �����룬���л���
				if(flag == 7)
				{
					tempStr.Append("\n");
					flag=0;
				}
				flag++;
			}
		}
		
		// 5������ʱ�ڴ��е�����д��Ŀ�������ı���
		int strlen = tempStr.GetLength();
		tempStr = tempStr.Left(strlen-1);
		m_target_edit.SetWindowTextA(tempStr);

		// 6����ȡ���ֵ��������ϼ�ֵ
		
		int money = 0; // ����
		int qty = 0; // ����
		int total = 0; // �ϼ�

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
		// û��ѡ��ת������
		AfxMessageBox("��ѡ��һ������ת��������\n���磺4��ת3��", MB_OK|MB_ICONEXCLAMATION);
	}
}

// �����ļ�
void CChangeDlg::OnBnClickedSaveBut()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	char exeFullPath[MAX_PATH]; // MAX_PATH
	GetModuleFileName(NULL,exeFullPath,MAX_PATH);//�õ�����ģ�����ƣ�ȫ·��
	(_tcsrchr(exeFullPath,_T('\\')))[1] = 0; // ɾ��ִ�г�����ļ���

	// ��õ�ǰʱ��
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
