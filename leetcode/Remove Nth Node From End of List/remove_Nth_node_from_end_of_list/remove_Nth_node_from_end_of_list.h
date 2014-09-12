#include <cstddef>

/**
 * Definition for singly-linked list.*/
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        unsigned int count = GetLen(head) - n;
		if (count == 0 )
		{
			if (n == 1)
			{
				return NULL;
			}
			else
			{
				return head->next;
			}
		}

		ListNode * pPre = head;
		for (unsigned int n = 0; n < count - 1; n++)
		{
			pPre = pPre->next;
		}
		pPre->next = pPre->next->next;
		return head;
    }
private:
	unsigned int GetLen(ListNode *head)
	{
		int len = 0;
		while(head)
		{
			head = head->next;
			len++;
		}
		return len;
	}
};