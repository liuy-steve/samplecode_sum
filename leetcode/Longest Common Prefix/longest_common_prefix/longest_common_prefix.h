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
		sort(strs.begin(), strs.end());

		string sprefix = subCommonString(strs[0], strs[1]);
		for (unsigned int i = 2; i < strs.size(); i++)
		{
			if (strs[i].find(sprefix) != 0)
			{
				return "";
			}
		}
		return sprefix;
	}

private:
	string subCommonString(string & l, string & r)
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
		return l.substr(0, npos);
	}
};