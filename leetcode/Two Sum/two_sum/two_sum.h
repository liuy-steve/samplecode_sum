#include <vector>

using std::vector;
class Solution {
public:
	vector<int> twoSum(vector<int> &numbers, int target) {
		vector<int> vRet;
		for (vector<int>::iterator it = numbers.begin(); it != numbers.end() - 1; it++)
		{
			for(vector<int>::iterator cursor = it + 1; cursor != numbers.end(); cursor++)
			{
				if (*it + *cursor == target)
				{
					vRet.push_back(it - numbers.begin() + 1);
					vRet.push_back(cursor - numbers.begin() + 1);
					return vRet;
				}
			}
		}
		return vRet;
	}
};