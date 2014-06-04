#include <iostream>
#include "cpp_log_descriptor.h"

const int TEST_ARG = 0;
using std::cout;
using std::endl;
int main()
{
	cout << "here it is!" << endl;

 //	cout << CppLog<>(__FILE__, __LINE__) << "test"<< endl;
//  cout << LOGDES << "test output" << endl;
	CppLog<> & ref = CppLog<>(__FILE__, __LINE__);
	ref << "test" << endl;
	cout << ref.str();
 	LOGDES << "test output1" /*<< endl*/;
	LOGDES << "test output2" << endl;
	LOGDES << "test output3" << endl;
	LOGDES << "test output4" << endl;
	LOGDES << "test output5" << endl;
	LOGDES << "test output6" << endl;

	std::stringstream ss ;
	ss << "test output 6";
	cout << ss.str();
	return 0;
}