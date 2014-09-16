#include <cassert>
#include "climbing_stairs.h"


int main()
{
	assert(Solution().climbStairs(0) == 1);
	assert(Solution().climbStairs(1) == 1);
	assert(Solution().climbStairs(2) == 2);
	assert(Solution().climbStairs(3) == 3);
	assert(Solution().climbStairs(4) == 5);

	return 0;
}