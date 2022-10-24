
//234. Palindrome Linked List
#include<bits/stdc++.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode * findMiddle(ListNode* head){
		ListNode * slow = head;
		ListNode * fast = head->next;

		while(fast && fast->next){
			slow = slow->next;
			fast = fast->next->next;
		}
		return slow;
	}

	ListNode * reverse(ListNode * head){
		ListNode * p = NULL,*c = head,* n = NULL;
		while(c){
			n = c->next;
			c-> next = p;
			p = c;
			c = n;
		}
		return p;
	}
};