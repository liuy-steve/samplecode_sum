#include "rotate_image.h"

int main()
{
	vector<vector<int> > test;
	for (int i = 0; i < 3; i++)
	{
		test.push_back(vector<int>());
		for (int j = 0; j < 3; j++)
		{
			test[i].push_back(i * 3 + j + 1);
		}
	}

	Solution().rotate(test);
	return 0;
}