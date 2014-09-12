#include <cassert>
#include "reverse_integer.h"

int main()
{
	Solution solution;
	assert(solution.reverse(123) == 321);
	assert(solution.reverse(-123) == -321);
	int a = -19 % 10;
	return 0;
}