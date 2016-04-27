#pragma once
#include <vector>
using namespace std;

class CTool
{
public:
	CTool(void);
	~CTool(void);
	char * Four2Three(char* str);
	char * Three2Two(char* str);
	char * Three2Four(char* str);
	char * Two2Three(char* str);

	char * Four2Two(char* str);
	char * Two2Four(char* str);

	char * Zero2Zero(char* str);
	char * Three2Three(char* str);
	char * Two2Two(char* str);

	vector<CString> SplitCString(CString strSource, char ch);
};

