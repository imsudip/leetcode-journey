/*
Author: Arghya Baran Naskar (arghya.official@yahoo.com)
q2095.cpp (c) 2023
Desc: Delete Node in a Linked List
Created: Sat Oct 28 2023 10:03:12 GMT+0530 (India Standard Time)
*/

class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode *temp = node->next;
        node->val = temp->val;
        node->next = temp->next;
        delete temp;
    }
};

/* Question: There is a singly-linked list head and we want to delete a node node in it.

You are given the node to be deleted node. You will not be given access to the first node of head.

All the values of the linked list are unique, and it is guaranteed that the given node node is not the last node in the linked list.

Delete the given node. Note that by deleting the node, we do not mean removing it from memory. We mean:

    The value of the given node should not exist in the linked list.
    The number of nodes in the linked list should decrease by one.
    All the values before node should be in the same order.
    All the values after node should be in the same order.


Approach: I am not given the headnode of the linked list so at first it seemed difficult but then you can think that I will just have to remove the value...so what I did is that, copied the value of the next node into the given node and then deleted the next node. That's it.

  1. Store the address of the next node in a pointer to ListNode type variable.
  2. Copy next node's value into current node.
  3. Connect: node->next = node->next->next;
  4. Now delete the node whose address is stored in temp;
  5. Done.
    */
