/*
Author: Arghya Baran Naskar (arghya.official@yahoo.com)
q203.cpp (c) 2023
Desc: Remove Linked List Elements
Created: Sun Oct 22 2023 12:39:35 GMT+0530 (India Standard Time)
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *curr, *temp;

        while(head && val == head->val){ //While traversing head might become NULL so checking for it is better.
            temp = head;
            head = head->next;
            delete temp;
        }
        if(!head) return head;
        curr = head;
        while(curr->next){
            if(curr->next->val == val){
                temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
            }
            else{
                curr = curr->next;
            }
        }
        return head;
    }
};

/* question: Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.
Example 1:

Input: head = [1,2,6,3,4,5,6], val = 6
Output: [1,2,3,4,5]

Approach: After understanding the problem I figured out that if val == head->val the steps of deleting these starting nodes will be different than the steps of deleting other nodes.
So I used 1 loop to delete nodes under the condition head->val == val and another loop to delete non-starting nodes.

1. if val == head->val we do temp = head and head = head->next. 
2. then we delete temp and again while condition is checked if val == head->val.
3. if yes step 1 to 3 is executed again.
4. if no we get out of the loop.
5. now we check if head == NULL or not.
6. if yes we return NULL else we assign curr = head;
7. Now we check non-starting nodes by checking if(curr->next->val == val) under while loop while(curr->next).
8. if values match we delete that node but don't move "curr" to next node...THIS STEP IS VERY IMPORTANT.
9. WE ONLY MOVE "curr" TO NEXT NODE IF THE CONDITION if(curr->next->val == val) fails.
10. After the while loop is over, our work is done. So, we return the head pointer.


    Time complexity: O(N) - There are 2 while loops that are not nested so TC: O(2N) = O(N)

    Space complexity: O(1) - Increasing the number of nodes doesn't increase the space required in the program.

*/
