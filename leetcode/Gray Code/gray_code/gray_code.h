#include <vector>
using std::vector;

class Solution {
public:
	vector<int> grayCode(int n) {
		const int len = 1 << n ;
		vector<int> ret(len, 0);
		if (n <= 0)
		{
			return ret;
		}

		ret[0] = 0;
		ret[1] = 1;

		for (int i = 2; i <= n; i++)
		{
			for (int j = 1 << (i - 1); j < (1 << i); j++)
			{
				ret[j] = ret[(1 << i) - 1 - j] + (1 << (i - 1));
			}
		}

		return ret;
	}
};