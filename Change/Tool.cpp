#include "StdAfx.h"
#include "Tool.h"


CTool::CTool(void)
{
}


CTool::~CTool(void)
{
}

/**
** ���ֶ�ת���ֶ�
*/
char * CTool::Four2Three(char* str){
	char dec[2] = ",";

	char a[5] = ""; // ���ֶ�����
	char b[5] = ""; // ��ʱ����

	memcpy(&a,str,4);
	
	char *re = (char*)malloc(128); // �����ڴ�ռ�
	memset(re,0,128); // �ڴ�ռ�����


	// x234
	memcpy(&b,&a,4);
	b[0] = 'X';
	strcat(re,(char*)&b);
	strcat(re,(char*)&dec);

	// 1x34
	memcpy(&b,&a,4);
	b[1] = 'X';
	strcat(re,(char*)&b);
	strcat(re,(char*)&dec);

	// 12x4
	memcpy(&b,&a,4);
	b[2] = 'X';
	strcat(re,(char*)&b);
	strcat(re,(char*)&dec);

	// 123x
	memcpy(&b,&a,4);
	b[3] = 'X';
	strcat(re,(char*)&b);

	return re;
}

/**
* ���ֶ�ת���ֶ�
*/
char * CTool::Three2Two(char* str){
	char dec[2] = ",";

	char a[5] = ""; // ���ֶ�����
	char b[5] = ""; // ��ʱ����

	memcpy(&a,str,4);
	
	char *re = (char*)malloc(128); // �����ڴ�ռ�
	memset(re,0,128); // �ڴ�ռ�����

	// x234
	memcpy(&b,&a,4);
	if(b[0]!='X'){
	  b[0] = 'X';
	  strcat(re,(char*)&b);
	  strcat(re,(char*)&dec);
	}

	// 1x34
	memcpy(&b,&a,4);
	if(b[1]!='X'){
	  b[1] = 'X';
	  strcat(re,(char*)&b);
	  strcat(re,(char*)&dec);
	}

	// 12x4
	memcpy(&b,&a,4);
	if(b[2]!='X'){
	  b[2] = 'X';
	  strcat(re,(char*)&b);
	  strcat(re,(char*)&dec);
	}

	// 123x
	memcpy(&b,&a,4);
	if(b[3]!='X'){
	  b[3] = 'X';
	  strcat(re,(char*)&b);
	}

	// ����ַ�������
	int len = strlen(re);

	// �ж��ַ������һ���ֽ��Ƿ�Ϊ ","
	// ����ǽ� "," ���Ÿ���ֵ��
	char *temp = re+len-1;
	if(strcmp((char*)temp,(char*)&dec)==0)
	{
		memset((char*)temp,0,1);
	}

	return re;
}

/**
** ���ֶ�ת���ֶ�
*/
char * CTool::Three2Four(char* str){
	char dec[2] = ",";

	char a[5] = ""; // ���ֶ�����
	char b[5] = ""; // ��ʱ����

	memcpy(&a,str,4);
	
	char *re = (char*)malloc(128); // �����ڴ�ռ�
	memset(re,0,128); // �ڴ�ռ�����

	// x234
	memcpy(&b,&a,4);
	if(b[0]=='X'){
		for(int i=0;i<10;i++)
		{
			b[0] = (char)i+48;
			strcat(re,(char*)&b);
			if(i<9)strcat(re,(char*)&dec);
		}
	}

	// 1x34
	memcpy(&b,&a,4);
	if(b[1]=='X'){
		for(int i=0;i<10;i++)
		{
			b[1] = (char)i+48;
			strcat(re,(char*)&b);
			if(i<9)strcat(re,(char*)&dec);
		}
	}

	// 12x4
	memcpy(&b,&a,4);
	if(b[2]=='X'){
		for(int i=0;i<10;i++)
		{
			b[2] = (char)i+48;
			strcat(re,(char*)&b);
			if(i<9)strcat(re,(char*)&dec);
		}
	}

	// 123x
	memcpy(&b,&a,4);
	if(b[3]=='X'){
		for(int i=0;i<10;i++)
		{
			b[3] = (char)i+48;
			strcat(re,(char*)&b);
			if(i<9)strcat(re,(char*)&dec);
		}
	}

	return re;
}

/**
* ���ֶ�ת���ֶ�
*/
char * CTool::Two2Three(char* str){
	char dec[2] = ",";

	char a[5] = ""; // ���ֶ�����
	char b[5] = ""; // ��ʱ����

	memcpy(&a,str,4);
	
	char *re = (char*)malloc(128); // �����ڴ�ռ�
	memset(re,0,128); // �ڴ�ռ�����

	int temp = 1;

	// x234
	memcpy(&b,&a,4);
	if(b[0]=='X'){
		for(int i=0;i<10;i++)
		{
			b[0] = (char)i+48;
			strcat(re,(char*)&b);
			if(i<9)strcat(re,(char*)&dec);
		}

		if(temp<=1){
			strcat(re,(char*)&dec);
			temp=2;
		}
	}



	// 1x34
	memcpy(&b,&a,4);
	if(b[1]=='X'){
		for(int i=0;i<10;i++)
		{
			b[1] = (char)i+48;
			strcat(re,(char*)&b);
			if(i<9)strcat(re,(char*)&dec);
		}

		if(temp<=1){
			strcat(re,(char*)&dec);
			temp=2;
		}
	}

	

	// 12x4
	memcpy(&b,&a,4);
	if(b[2]=='X'){
		for(int i=0;i<10;i++)
		{
			b[2] = (char)i+48;
			strcat(re,(char*)&b);
			if(i<9)strcat(re,(char*)&dec);
		}

		if(temp<=1){
			strcat(re,(char*)&dec);
			temp=2;
		}
	}



	// 123x
	memcpy(&b,&a,4);
	if(b[3]=='X'){
		for(int i=0;i<10;i++)
		{
			b[3] = (char)i+48;
			strcat(re,(char*)&b);
			if(i<9)strcat(re,(char*)&dec);
		}

		if(temp<=1){
			strcat(re,(char*)&dec);
			temp=2;
		}
	}

	return re;
}

/**
* ���ֶ�ת���ֶ�
*/
char * CTool::Four2Two(char* str){
	char dec[2] = ",";

	char *re = (char*)malloc(128); // �����ڴ�ռ�
	memset(re,0,128); // �ڴ�ռ�����

	char * strTemp = Four2Three(str);

	// 4��ת3�֣�Ϊ 1 => 4
	// 3��ת2�֣�Ϊ 1 => 3
	// 4��ת2�֣�Ϊ 1 => 12

	vector<CString> arr;
	arr = SplitCString(strTemp,',');
	int arrLen = arr.size();

	for(int i=0;i<arrLen;i++)
	{
		CString strA = arr[i];
		int strALen = strA.GetLength()+1;
		char *temp = new char[strALen];
		memset(temp,0,strALen);
		strncpy(temp,strA,strALen);

		char *strRe = (char*)malloc(128);
		memset(strRe,0,128);

		strRe = Three2Two(temp);
		strcat(re,(char*)strRe);
		strcat(re,(char*)&dec);
	}

	// ����ַ�������
	int len = strlen(re);

	// �ж��ַ������һ���ֽ��Ƿ�Ϊ ","
	// ����ǽ� "," ���Ÿ���ֵ��
	char *temp = re+len-1;
	if(strcmp((char*)temp,(char*)&dec)==0)
	{
		memset((char*)temp,0,1);
	}

	return re;
}

/**
* ���ֶ�ת���ֶ�
*/
char * CTool::Two2Four(char* str){
	char dec[2] = ",";

	char *re = (char*)malloc(1024); // �����ڴ�ռ�
	memset(re,0,1024); // �ڴ�ռ�����

	char * strTemp = Two2Three(str);

	// 2��ת3�֣�Ϊ 1 => 20
	// 3��ת4�֣�Ϊ 1 => 10
	// 2��ת4�֣�Ϊ 1 => 200

	vector<CString> arr;
	arr = SplitCString(strTemp,',');
	int arrLen = arr.size();

	for(int i=0;i<arrLen;i++)
	{
		CString strA = arr[i];
		int strALen = strA.GetLength()+1;
		char *temp = new char[strALen];
		memset(temp,0,strALen);
		strncpy(temp,strA,strALen);

		char *strRe = (char*)malloc(256);
		memset(strRe,0,256);

		strRe = Three2Four(temp);
		strcat(re,(char*)strRe);
		strcat(re,(char*)&dec);
	}

	// ����ַ�������
	int len = strlen(re);

	// �ж��ַ������һ���ֽ��Ƿ�Ϊ ","
	// ����ǽ� "," ���Ÿ���ֵ��
	char *temp = re+len-1;
	if(strcmp((char*)temp,(char*)&dec)==0)
	{
		memset((char*)temp,0,1);
	}

	return re;
}

/**
* ƽ�Ʋ�ת��
*/
char * CTool::Zero2Zero(char* str){
	// ֱ�ӷ��أ�����ת��
	return str;
}

/**
* ������ת���ֶ�
*/
char * CTool::Three2Three(char* str){
	char dec[2] = ",";

	char a[5] = ""; // �����ֺ���
	char b[5] = ""; // ��ʱ����

	memcpy(&a,str,3); // �����븴�Ƶ�����

	// ��Ҫ�ж��Ƿ�Ϊ˫�غ�����
	int CF = 0; // ��ʾû���ظ���

	if(a[0]==a[1]) CF=1; // ��ʾǰ�������ظ� 12��
	if(a[1]==a[2]) CF=1; // ��ʾ���������ظ� 12��
	if(a[0]==a[2]) CF=1; // ��ʾ��1�͵�3�����ظ� 12��
	if(a[0]==a[1]&&a[1]==a[2]) CF=2; // ��ʾ�������ظ� 4��

	// ���ں�����ж���bug������Ҫ212�������ظ�����ȷ��
	// ������������Ȱ��ظ��Ļ��������ʽ���ټ�����
	if(CF==1){
		// 221 => 212
		if(a[0]==a[1]){ // ��ʾǰ�������ظ�
			a[1]=a[2];
			a[2]=a[0];
		}

		// 122 => 212
		if(a[1]==a[2]){ // ��ʾ���������ظ�
			a[1]=a[0];
			a[0]=a[2];
		}
	}

	char *re = (char*)malloc(1024); // �����ڴ�ռ�
	memset(re,0,1024); // �ڴ�ռ�����

	// ������ת���ֶ���һ��24��
	// OOOX OOXO OXOO XOOO
	// ÿ������˳��ת4������


	//////////////////////////
	/////////////////////////
	// ��һ��
	b[0] = a[0];
	b[1] = a[1];
	b[2] = a[2];
	b[3] = 'X';
	strcat(re,(char*)&b);
	strcat(re,(char*)&dec);

	b[0] = a[0];
	b[1] = a[1];
	b[2] = 'X';
	b[3] = a[2];
	strcat(re,(char*)&b);
	strcat(re,(char*)&dec);

	b[0] = a[0];
	b[1] = 'X';
	b[2] = a[1];
	b[3] = a[2];
	strcat(re,(char*)&b);
	strcat(re,(char*)&dec);

	b[0] = 'X';
	b[1] = a[0];
	b[2] = a[1];
	b[3] = a[2];
	strcat(re,(char*)&b);
	if(CF!=2) strcat(re,(char*)&dec);
	/////////////////////////////

	if(CF!=1&&CF!=2){ // �������˫�غ����أ������
	b[0] = a[0];
	b[1] = a[2];
	b[2] = a[1];
	b[3] = 'X';
	strcat(re,(char*)&b);
	strcat(re,(char*)&dec);

	b[0] = a[0];
	b[1] = a[2];
	b[2] = 'X';
	b[3] = a[1];
	strcat(re,(char*)&b);
	strcat(re,(char*)&dec);

	b[0] = a[0];
	b[1] = 'X';
	b[2] = a[2];
	b[3] = a[1];
	strcat(re,(char*)&b);
	strcat(re,(char*)&dec);

	b[0] = 'X';
	b[1] = a[0];
	b[2] = a[2];
	b[3] = a[1];
	strcat(re,(char*)&b);
	strcat(re,(char*)&dec);
	}

	/////////////////////////////
	/////////////////////////////
	// �ڶ���
	if(CF!=2){ // ����������أ������
	b[0] = a[1];
	b[1] = a[0];
	b[2] = a[2];
	b[3] = 'X';
	strcat(re,(char*)&b);
	strcat(re,(char*)&dec);

	b[0] = a[1];
	b[1] = a[0];
	b[2] = 'X';
	b[3] = a[2];
	strcat(re,(char*)&b);
	strcat(re,(char*)&dec);

	b[0] = a[1];
	b[1] = 'X';
	b[2] = a[0];
	b[3] = a[2];
	strcat(re,(char*)&b);
	strcat(re,(char*)&dec);

	b[0] = 'X';
	b[1] = a[1];
	b[2] = a[0];
	b[3] = a[2];
	strcat(re,(char*)&b);
	strcat(re,(char*)&dec);
	}
	/////////////////////////////

	if(CF!=1&&CF!=2){ // �������˫�غ����أ������
	b[0] = a[1];
	b[1] = a[2];
	b[2] = a[0];
	b[3] = 'X';
	strcat(re,(char*)&b);
	strcat(re,(char*)&dec);

	b[0] = a[1];
	b[1] = a[2];
	b[2] = 'X';
	b[3] = a[0];
	strcat(re,(char*)&b);
	strcat(re,(char*)&dec);

	b[0] = a[1];
	b[1] = 'X';
	b[2] = a[2];
	b[3] = a[0];
	strcat(re,(char*)&b);
	strcat(re,(char*)&dec);

	b[0] = 'X';
	b[1] = a[1];
	b[2] = a[2];
	b[3] = a[0];
	strcat(re,(char*)&b);
	strcat(re,(char*)&dec);
	}

	///////////////////////////////
	////////////////////////////
	// ������
	if(CF!=2){ // ����������أ������
	b[0] = a[2];
	b[1] = a[0];
	b[2] = a[1];
	b[3] = 'X';
	strcat(re,(char*)&b);
	strcat(re,(char*)&dec);

	b[0] = a[2];
	b[1] = a[0];
	b[2] = 'X';
	b[3] = a[1];
	strcat(re,(char*)&b);
	strcat(re,(char*)&dec);

	b[0] = a[2];
	b[1] = 'X';
	b[2] = a[0];
	b[3] = a[1];
	strcat(re,(char*)&b);
	strcat(re,(char*)&dec);

	b[0] = 'X';
	b[1] = a[2];
	b[2] = a[0];
	b[3] = a[1];
	strcat(re,(char*)&b);
	if(CF!=1&&CF!=2) strcat(re,(char*)&dec);
	}
	///////////////////////////////

	if(CF!=1&&CF!=2){ // �������˫�غ����أ������
	b[0] = a[2];
	b[1] = a[1];
	b[2] = a[0];
	b[3] = 'X';
	strcat(re,(char*)&b);
	strcat(re,(char*)&dec);

	b[0] = a[2];
	b[1] = a[1];
	b[2] = 'X';
	b[3] = a[0];
	strcat(re,(char*)&b);
	strcat(re,(char*)&dec);

	b[0] = a[2];
	b[1] = 'X';
	b[2] = a[1];
	b[3] = a[0];
	strcat(re,(char*)&b);
	strcat(re,(char*)&dec);

	b[0] = 'X';
	b[1] = a[2];
	b[2] = a[1];
	b[3] = a[0];
	strcat(re,(char*)&b);
	}

	return re;
}

/**
* ������ת���ֶ�
*/
char * CTool::Two2Two(char* str){
	char dec[2] = ",";

	char a[5] = ""; // �����ֺ���
	char b[5] = ""; // ��ʱ����

	memcpy(&a,str,2); // �����븴�Ƶ�����

	// ��Ҫ�ж��Ƿ�Ϊ�ظ���

	char *re = (char*)malloc(1024); // �����ڴ�ռ�
	memset(re,0,1024); // �ڴ�ռ�����

	// ������ת���ֶ���һ��12��
	// OOXX XXOO OXOX XOXO XOOX OXXO
	b[0] = a[0];
	b[1] = a[1];
	b[2] = 'X';
	b[3] = 'X';
	strcat(re,(char*)&b);
	strcat(re,(char*)&dec);

	b[0] = 'X';
	b[1] = 'X';
	b[2] = a[0];
	b[3] = a[1];
	strcat(re,(char*)&b);
	strcat(re,(char*)&dec);

	b[0] = a[0];
	b[1] = 'X';
	b[2] = a[1];
	b[3] = 'X';
	strcat(re,(char*)&b);
	strcat(re,(char*)&dec);
	
	b[0] = 'X';
	b[1] = a[0];
	b[2] = 'X';
	b[3] = a[1];
	strcat(re,(char*)&b);
	strcat(re,(char*)&dec);

	b[0] = 'X';
	b[1] = a[0];
	b[2] = a[1];
	b[3] = 'X';
	strcat(re,(char*)&b);
	strcat(re,(char*)&dec);

	b[0] = a[0];
	b[1] = 'X';
	b[2] = 'X';
	b[3] = a[1];
	strcat(re,(char*)&b);
	if(a[0]!=a[1]) strcat(re,(char*)&dec);

	////////////////////////////////
	if(a[0]!=a[1]){
	b[0] = a[1];
	b[1] = a[0];
	b[2] = 'X';
	b[3] = 'X';
	strcat(re,(char*)&b);
	strcat(re,(char*)&dec);

	b[0] = 'X';
	b[1] = 'X';
	b[2] = a[1];
	b[3] = a[0];
	strcat(re,(char*)&b);
	strcat(re,(char*)&dec);

	b[0] = a[1];
	b[1] = 'X';
	b[2] = a[0];
	b[3] = 'X';
	strcat(re,(char*)&b);
	strcat(re,(char*)&dec);
	
	b[0] = 'X';
	b[1] = a[1];
	b[2] = 'X';
	b[3] = a[0];
	strcat(re,(char*)&b);
	strcat(re,(char*)&dec);

	b[0] = 'X';
	b[1] = a[1];
	b[2] = a[0];
	b[3] = 'X';
	strcat(re,(char*)&b);
	strcat(re,(char*)&dec);

	b[0] = a[1];
	b[1] = 'X';
	b[2] = 'X';
	b[3] = a[0];
	strcat(re,(char*)&b);
	}

	return re;
}

vector<CString> CTool::SplitCString(CString strSource, char ch)
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