#include <tchar.h>
#include <iostream>
#include <boost/smart_ptr.hpp>

using std::cout;
using boost::shared_ptr;

int main()
{
	const int MAX_LEN = 100;
	_TCHAR *pBuf = new _TCHAR[MAX_LEN];
	shared_ptr<_TCHAR> pMsg(pBuf);
	_tcscpy(pMsg.get(), _T("ChinaÖÐ¹ú"));
	std::wcout << pBuf << std::endl;
}