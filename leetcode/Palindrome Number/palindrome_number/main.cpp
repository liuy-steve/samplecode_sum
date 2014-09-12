
#include <cassert>
#include "palindrome_number.h"

int main()
{
	Solution solution;
	assert(solution.isPalindrome(123321));
	assert(!solution.isPalindrome(-2147447412));
	assert(!solution.isPalindrome(1233211));
	return 0;
}