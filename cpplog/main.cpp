#include <iostream>
#include "cpp_log_descriptor.h"

const int TEST_ARG = 0;
using std::cout;
using std::endl;
int main()
{
	cout << "here it is!" << endl;

	LOGDES << "test output1" << endl;
	LOGDES << "test output2" << endl;
	LOGDES << "test output3" << endl;
	LOGDES << "test output4" << endl;
	LOGDES << "test output5" << endl;
	LOGDES << "test output6" << endl;

	return 0;
}