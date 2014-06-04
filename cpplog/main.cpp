#include <iostream>
#include "cpp_log_descriptor.h"

const int TEST_ARG = 0;
using std::cout;
using std::endl;
int main()
{
	cout << "here it is!" << endl;

// 	cout << CppLog<>(__FILE__, __LINE__);
//  cout << LOGDES << "²âÊÔÊä³ö" << endl;
	CppLog<> & ref = CppLog<>(__FILE__, __LINE__);
	ref << "test" << endl;
	cout << ref;
 	LOGDES << "²âÊÔÊä³ö1" << endl;
	LOGDES << "²âÊÔÊä³ö2" << endl;
	LOGDES << "²âÊÔÊä³ö3" << endl;
	LOGDES << "²âÊÔÊä³ö4" << endl;
	LOGDES << "²âÊÔÊä³ö5" << endl;
	LOGDES << "²âÊÔÊä³ö6" << endl;
	return 0;
}