#include "swap_nodes_in_pairs.h"

int main()
{
	{
		ListNode n1(1);
		ListNode n2(2);
		n1.next = &n2;
		ListNode* pnode = Solution().swapPairs(&n1);
	}
	{
		ListNode n1(1);
		ListNode n2(2);
		ListNode n3(3);
		ListNode n4(4);
		n1.next = &n2;
		n2.next = &n3;
		n3.next = &n4;
		ListNode* pnode = Solution().swapPairs(&n1);
	}
	
	return 0;
}