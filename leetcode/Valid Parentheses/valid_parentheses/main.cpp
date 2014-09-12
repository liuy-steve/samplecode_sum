#include <cassert>
#include "valid_parentheses.h"

int main()
{
	assert(Solution().isValid("({[]})"));
	assert(!Solution().isValid("({[]})}"));
	return 0;
}