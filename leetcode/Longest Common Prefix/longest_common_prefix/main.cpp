#include <cassert>
#include "longest_common_prefix.h"

int main()
{
	string stest[] = {"abc", "abcd", "abcde"};
	vector<string> test(&stest[0], &stest[0] + 3);
	Solution solution;
	assert(solution.longestCommonPrefix(test) == "abcd");
	return 0;
}