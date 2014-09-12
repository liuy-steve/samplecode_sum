#include "remove_Nth_node_from_end_of_list.h"

int main()
{
	ListNode node(1);
	ListNode* pnode = Solution().removeNthFromEnd(&node, 1);
	ListNode node2(2);
	node.next = &node2;
	pnode = Solution().removeNthFromEnd(&node, 1);
	return 0;
}