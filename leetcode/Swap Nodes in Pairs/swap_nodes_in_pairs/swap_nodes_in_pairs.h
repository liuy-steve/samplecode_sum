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
    ListNode *swapPairs(ListNode *head) {
		if (head == NULL) return head;
		ListNode *pret = head->next;
		if (pret == NULL)
		{
			return head;
		}
		swapImp(head, NULL);
		return pret;
	}
       

private:
	void swapImp(ListNode *head, ListNode *pretail)
	{
		if (head == NULL || head->next == NULL)
		{
			return;
		}
		ListNode* third = head->next->next;
		ListNode* secode = head->next;

		secode->next = head;
		head->next = third;
		if (pretail != NULL)
		{
			pretail->next = secode;
		}
		
		swapImp(third, head);
    }
};