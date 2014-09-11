#include <vector>
#include <algorithm>

using std::vector;
using std::find;
class Solution {
public:
	vector<int> twoSum(vector<int> &numbers, int target) {
		vector<int> vRet;
		for (vector<int>::iterator it = numbers.begin(); it != numbers.end() - 1; it++)
		{
			vector<int>::iterator dest = find(it + 1, numbers.end(), target - *it);
			if (dest != numbers.end())
			{
				vRet.push_back(it - numbers.begin() + 1);
				vRet.push_back(dest - numbers.begin() + 1);
				return vRet;
			}
		}
		return vRet;
	}
};