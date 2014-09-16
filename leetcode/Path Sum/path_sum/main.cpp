#include <cassert>
#include "path_sum.h"

int main ()
{
	TreeNode node1(1);
	TreeNode node2(2);

	node1.left = &node2;
	assert(Solution().hasPathSum(&node1, 1) == false);
	return 0;
}