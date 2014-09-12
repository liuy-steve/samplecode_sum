#include <sstream>

using std::stringstream;
class Solution {
public:
	int atoi(const char *str) 
	{
		stringstream ss;
		ss << str;
		int nret = 0;
		ss >> nret;
		return nret;
	}
};