#include <cassert>
#include "gray_code.h"

int main ()
{
	vector<int> ret;
	ret = Solution().grayCode(2);
	ret = Solution().grayCode(3);
	ret = Solution().grayCode(4);
	ret = Solution().grayCode(5);
	return 0;
}