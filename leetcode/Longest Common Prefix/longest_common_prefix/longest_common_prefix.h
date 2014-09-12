#include <vector>
#include <string>
#include <algorithm>
using std::vector;
using std::string;
using std::sort;

class Solution {
public:
	string longestCommonPrefix(vector<string> &strs) {
		string sret = "";
		if(strs.empty())
		{
			return sret;
		}
		if (strs.size() == 1)
		{
			return *strs.begin();
		}
		sort(strs.begin(), strs.end());
		sret = "";
		for (unsigned int i = 0; i < strs.size() - 1; i++)
		{
			string sprefix = subCommonString(strs[i], strs[i + 1]);
			if (sprefix.length() > sret.length())
			{
				sret = sprefix;
			}
		}
		return sret;
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