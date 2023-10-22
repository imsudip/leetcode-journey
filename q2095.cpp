/*
Author: Arghya Baran Naskar (arghya.official@yahoo.com)
q2095.cpp (c) 2023
Desc: Delete the Middle Node of a Linked List
Created: Sun Oct 22 2023 11:58:02 GMT+0530 (India Standard Time)
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode *prev=NULL, *slow, *fast;
        slow = fast = head;
        if(!head) return head;
        if(!head->next){
            delete head;
            return NULL;
        }
        while(fast && fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = slow->next; //if only one node in linked list then prev remains NULL so handle it beforehand
        delete slow;
        return head;
    }
};


// Approach: Used 2 pointers ListNode *slow, *fast to traverse the linked list while(fast && fast->next). fast traverses in steps of 2 while slow traverses in steps of 1. By the end of the loop slow will be pointing to the very node that we intend to delete. I also used a ListNode *prev pointer to keep track of the node 1 step before the node pointed to by "slow". Now I just have to do prev->next = slow->next; delete slow and return head. That's it.

// Corner Cases: 1. if head == NULL, we return NULL. 
//               2. if there is only 1 Node in the entire linked list then we delete that only node and return NULL.

// 1. Traverse the node using 2 pointers. one slow pointer that traverses in steps of 1 and a fast pointer that traverses in steps of 2.
// 2. We traverse while fast != NULL && fast->next != NULL.
// 3. In every step we are storing the location of the node previously pointed to by "slow" in "prev".
// 4. After the end of the loop situation is head->....->prev->slow->|_val_|_next_|->....fast->NULL
// 5. slow points to the very node that we want to delete. After deletion head->....->prev->|_val_|_next_|->....fast->NULL
// 6. Now we just return the head pointer.
