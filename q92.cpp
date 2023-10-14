

/*
Author: Subhamay Nath(subhamaynath2002@gmail.com)
q92.cpp (c) 2023
Desc: Reverse Linked List II
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    ListNode* reverse(ListNode* h, ListNode *t){
        ListNode *p=NULL, *c=h,*n=NULL;
        while(c!=t){
            n=c->next;
            c->next=p;
            p=c;
            c=n;
        }
        return p;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == nullptr) return head;
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* prev = dummy;
        for (int i = 0; i < left-1; i++) {
            prev = prev->next;
        }
        ListNode* curr = prev->next;
        
        for (int i = 0; i < right-left; i++) {
            ListNode* next = curr->next;
            curr->next = next->next;
            next->next = prev->next;
            prev->next = next;
        }
        
        return dummy->next;


    }
};

/*
 Link : https://leetcode.com/problems/reverse-linked-list-ii/
 Question :Given the head of a singly linked list and two integers left and right where left <= right, 
 reverse the nodes of the list from position left to position right, and return the reversed list.

 
Constraints:

The number of nodes in the list is n.
1 <= n <= 500
-500 <= Node.val <= 500
1 <= left <= right <= n
 
*/