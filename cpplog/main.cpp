#include <iostream>
#include "cpp_log_descriptor.h"

const int TEST_ARG = 0;
using std::cout;
using std::endl;
int main()
{
	cout << "here it is!" << endl;

// 	cout << CppLog<>(__FILE__, __LINE__);
//  cout << LOGDES << "�������" << endl;
	CppLog<> & ref = CppLog<>(__FILE__, __LINE__);
	ref << "test" << endl;
	cout << ref;
 	LOGDES << "�������1" << endl;
	LOGDES << "�������2" << endl;
	LOGDES << "�������3" << endl;
	LOGDES << "�������4" << endl;
	LOGDES << "�������5" << endl;
	LOGDES << "�������6" << endl;
	return 0;
}