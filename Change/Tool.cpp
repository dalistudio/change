#include "StdAfx.h"
#include "Tool.h"


CTool::CTool(void)
{
}


CTool::~CTool(void)
{
}

/**
** 四字定转三字定
*/
char * CTool::Four2Three(char* str){
	char dec[2] = ",";

	char a[5] = ""; // 四字定号码
	char b[5] = ""; // 临时号码

	memcpy(&a,str,4);
	
	char *re = (char*)malloc(128); // 分配内存空间
	memset(re,0,128); // 内存空间清零


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
* 三字定转二字定
*/
char * CTool::Three2Two(char* str){
	char dec[2] = ",";

	char a[5] = ""; // 三字定号码
	char b[5] = ""; // 临时号码

	memcpy(&a,str,4);
	
	char *re = (char*)malloc(128); // 分配内存空间
	memset(re,0,128); // 内存空间清零

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

	// 获得字符串长度
	int len = strlen(re);

	// 判断字符串最后一个字节是否为 ","
	// 如果是将 "," 逗号赋零值。
	char *temp = re+len-1;
	if(strcmp((char*)temp,(char*)&dec)==0)
	{
		memset((char*)temp,0,1);
	}

	return re;
}

/**
** 三字定转四字定
*/
char * CTool::Three2Four(char* str){
	char dec[2] = ",";

	char a[5] = ""; // 三字定号码
	char b[5] = ""; // 临时号码

	memcpy(&a,str,4);
	
	char *re = (char*)malloc(128); // 分配内存空间
	memset(re,0,128); // 内存空间清零

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
* 二字定转三字定
*/
char * CTool::Two2Three(char* str){
	char dec[2] = ",";

	char a[5] = ""; // 二字定号码
	char b[5] = ""; // 临时号码

	memcpy(&a,str,4);
	
	char *re = (char*)malloc(128); // 分配内存空间
	memset(re,0,128); // 内存空间清零

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
* 四字定转二字定
*/
char * CTool::Four2Two(char* str){
	char dec[2] = ",";

	char *re = (char*)malloc(128); // 分配内存空间
	memset(re,0,128); // 内存空间清零

	char * strTemp = Four2Three(str);

	// 4字转3字，为 1 => 4
	// 3字转2字，为 1 => 3
	// 4字转2字，为 1 => 12

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

	// 获得字符串长度
	int len = strlen(re);

	// 判断字符串最后一个字节是否为 ","
	// 如果是将 "," 逗号赋零值。
	char *temp = re+len-1;
	if(strcmp((char*)temp,(char*)&dec)==0)
	{
		memset((char*)temp,0,1);
	}

	return re;
}

/**
* 二字定转四字定
*/
char * CTool::Two2Four(char* str){
	char dec[2] = ",";

	char *re = (char*)malloc(1024); // 分配内存空间
	memset(re,0,1024); // 内存空间清零

	char * strTemp = Two2Three(str);

	// 2字转3字，为 1 => 20
	// 3字转4字，为 1 => 10
	// 2字转4字，为 1 => 200

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

	// 获得字符串长度
	int len = strlen(re);

	// 判断字符串最后一个字节是否为 ","
	// 如果是将 "," 逗号赋零值。
	char *temp = re+len-1;
	if(strcmp((char*)temp,(char*)&dec)==0)
	{
		memset((char*)temp,0,1);
	}

	return re;
}

/**
* 平移不转换
*/
char * CTool::Zero2Zero(char* str){
	// 直接返回，不做转换
	return str;
}

/**
* 三字现转三字定
*/
char * CTool::Three2Three(char* str){
	char dec[2] = ",";

	char a[5] = ""; // 三字现号码
	char b[5] = ""; // 临时号码

	memcpy(&a,str,3); // 将号码复制到数组

	// 需要判断是否为双重和三重
	int CF = 0; // 表示没有重复的

	if(a[0]==a[1]) CF=1; // 表示前面两数重复 12组
	if(a[1]==a[2]) CF=1; // 表示后面两数重复 12组
	if(a[0]==a[2]) CF=1; // 表示第1和第3个数重复 12组
	if(a[0]==a[1]&&a[1]==a[2]) CF=2; // 表示三个数重复 4组

	// 由于后面的判断有bug，必须要212这样的重复才正确，
	// 所以这里可以先把重复的换成这个格式，再继续。
	if(CF==1){
		// 221 => 212
		if(a[0]==a[1]){ // 表示前面两数重复
			a[1]=a[2];
			a[2]=a[0];
		}

		// 122 => 212
		if(a[1]==a[2]){ // 表示后面两数重复
			a[1]=a[0];
			a[0]=a[2];
		}
	}

	char *re = (char*)malloc(1024); // 分配内存空间
	memset(re,0,1024); // 内存空间清零

	// 三字现转三字定，一共24组
	// OOOX OOXO OXOO XOOO
	// 每个号码顺序转4个类型


	//////////////////////////
	/////////////////////////
	// 第一组
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

	if(CF!=1&&CF!=2){ // 如果不是双重和三重，则继续
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
	// 第二组
	if(CF!=2){ // 如果不是三重，则继续
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

	if(CF!=1&&CF!=2){ // 如果不是双重和三重，则继续
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
	// 第三组
	if(CF!=2){ // 如果不是三重，则继续
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

	if(CF!=1&&CF!=2){ // 如果不是双重和三重，则继续
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
* 二字现转二字定
*/
char * CTool::Two2Two(char* str){
	char dec[2] = ",";

	char a[5] = ""; // 二字现号码
	char b[5] = ""; // 临时号码

	memcpy(&a,str,2); // 将号码复制到数组

	// 需要判断是否为重复号

	char *re = (char*)malloc(1024); // 分配内存空间
	memset(re,0,1024); // 内存空间清零

	// 二字现转二字定，一共12组
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