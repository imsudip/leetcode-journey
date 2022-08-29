/*
Author: Sudip Ghosh (sudipghosh9333@gmail.com)
q23.cpp (c) 2022
Desc: merging two sorted arrays
Created:  2022-08-29T10:51:55.465Z
Modified: 2022-08-29T10:55:00.226Z
*/

#include <iostream>
using namespace std;

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

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *head = new ListNode(0);
        ListNode *curr = head;
        while (list1 && list2)
        {
            if (list1->val < list2->val)
            {
                curr->next = list1;
                list1 = list1->next;
            }
            else
            {
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;
        }
        if (list1)
        {
            curr->next = list1;
        }
        if (list2)
        {
            curr->next = list2;
        }
        return head->next;
    }
};

int main()
{
    Solution s;
    ListNode *list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);
    ListNode *list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);
    ListNode *list = s.mergeTwoLists(list1, list2);
    while (list)
    {
        cout << list->val << " ";
        list = list->next;
    }
    cout << endl;
}