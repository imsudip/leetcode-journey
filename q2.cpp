/*
Author: Sudip Ghosh (sudipghosh9333@gmail.com)
q2.cpp (c) 2022
Desc: add two numbers
Created:  2022-08-29T15:59:38.976Z
Modified: 2022-08-29T16:06:52.847Z
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
#include <bits/stdc++.h>
using namespace std;

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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *head = new ListNode();
        ListNode *temp = head;
        int carry = 0;
        while (l1 != NULL || l2 != NULL || carry)
        {
            int sum = 0;
            if (l1 != NULL)
            {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL)
            {
                sum += l2->val;
                l2 = l2->next;
            }
            sum += carry;
            carry = sum / 10;
            ListNode *node = new ListNode(sum % 10);
            temp->next = node;
            temp = temp->next;
        }
        return head->next;
    }
};

int main()
{
    ListNode *l1 = new ListNode(2);
    ListNode *l2 = new ListNode(4);
    ListNode *l3 = new ListNode(3);
    l1->next = l2;
    l2->next = l3;
    ListNode *l4 = new ListNode(5);
    ListNode *l5 = new ListNode(6);
    ListNode *l6 = new ListNode(4);
    l4->next = l5;
    l5->next = l6;
    Solution s;
    ListNode *ans = s.addTwoNumbers(l1, l4);
    while (ans != NULL)
    {
        cout << ans->val << " ";
        ans = ans->next;
    }
    return 0;
}