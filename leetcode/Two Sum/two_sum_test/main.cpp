#include "two_sum.h"

int main()
{
	const int arr[] = {2, 7, 11, 15};
	vector<int> number(&arr[0], &arr[4]);
	Solution solution;
	vector<int> dest = solution.twoSum(number, 9);
	return 0;
}