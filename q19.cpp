/*
Author: Arghya Baran Naskar (arghya.official@yahoo.com)
q19.cpp (c) 2023
Desc: Remove Nth Node From End of List
Created: Sun Oct 22 2023 10:57:47 GMT+0530 (India Standard Time)
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *curr, *temp, *start;
        int pos = 0;
        curr = start = head;
        if(!head)
            return head;
        while(curr && pos<n){
            curr = curr->next;
            pos++;
        }
        if(!curr){
            if(pos == n){
                temp = head;
                head = head->next;
                delete temp;
            }
            return head;
        }
        while(curr->next){
            curr = curr->next;
            start = start->next;
        }
        temp = start->next;
        start->next = temp->next;
        delete temp;
        return head;
    }
};


// question: Given the head of a linked list, remove the nth node from the end of the list and return its head.

// Approach:
// I used 2 pointer and created a gap of 'n' between them, used a int pos variable to achieve this.
// Then I used the second pointer(n nodes ahead) to traverse to the last node of the linked list and also shifter the first pointer along with it.
// After the loop is over the first pointer will be pointing to the node ahead of the node ot be deleted...from now we just delete the targeted node.

// Corner cases: if after the traversal is over the end pointer is nullptr and pos == n then we remove the first node of the linked list
// and if pos<n then we simply return head.

// 1. Decleared 4 variable ListNode *curr, *temp, *start and int pos = 0;

// 2. curr <- start <- head 
// 3. passing condition (curr && pos<n) to while loop we create a gap of n between start node and curr.

// 4. After the traversal is over start will be positioned just before the node to be deleted.

// 5. Now we store the node to be deleted in temp. temp = start->next.

// 6. now we connect start to start->next->next;

// 7. Then we delete temp and return the head pointer.
