#include <vector>
using std::vector;

class Solution {
public:
	int climbStairs(int n) {
		if (n <= 1)
		{
			return 1;
		}

		vector<int> steps;
		steps.push_back(1);
		steps.push_back(1);

		for (int i = 2; i <= n; i++)
		{
			steps.push_back(steps[i - 1] + steps[i - 2]);
		}
		return steps[n];
	}
};