#include <cassert>
#include <climits>
#include "string_to_integer.h"

int main()
{
	Solution solution;
	//normal
	assert(solution.atoi("123") == 123);
	assert(solution.atoi("2147483647") == INT_MAX);

	//abnormal
	assert(solution.atoi("2147483648") != INT_MAX);
	return 0;
}