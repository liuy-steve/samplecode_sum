#include <vector>
#include <string>
#include <algorithm>
using std::vector;
using std::string;
using std::sort;

class Solution {
public:
	string longestCommonPrefix(vector<string> &strs) {

		if(strs.empty())
		{
			return "";
		}
		if (strs.size() == 1)
		{
			return *strs.begin();
		}

		string sprefix = *strs.begin();
		for (unsigned int i = 1; i < strs.size(); i++)
		{
			subCommonString(sprefix, strs[i]);
			if (sprefix.length() == 0)
			{
				break;
			}
		}
		return sprefix;
	}

private:
	void subCommonString(string & l, string & r)
	{
		size_t npos = 0;
		while(1)
		{
			if (npos >= l.length() || npos >= r.length())
			{
				break;
			}
			if (l.substr(npos, 1) == r.substr(npos, 1))
			{
				npos ++;
				continue;
			}
			else
			{
				break;
			}
		}
		l = l.substr(0, npos);
	}
};