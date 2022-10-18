/*
Author: Sudip Ghosh (sudipghosh9333@gmail.com)
q429.cpp (c) 2022
Desc: N-ary Tree Level Order Traversal
Created:  2022-09-05T00:18:33.771Z
Modified: 2022-09-05T02:08:08.821Z
*/

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

class Solution
{
public:
    vector<vector<int>> levelOrder(Node *root)
    {
        vector<vector<int>> ans;
        if (root == NULL)
        {
            return ans;
        }
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            vector<int> temp;
            for (int i = 0; i < size; i++)
            {
                Node *curr = q.front();
                q.pop();
                temp.push_back(curr->val);
                for (int j = 0; j < curr->children.size(); j++)
                {
                    q.push(curr->children[j]);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};

// question: Given an n-ary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

// Approach:
// We can use a queue to solve this problem.
// We can push the root node in the queue and then we can pop the node and push all its children in the queue.
// Since queue is a FIFO data structure, we can pop the nodes in the order of their level.
// We can repeat this process until the queue is empty.
// We can use a vector to store the values of the nodes in each level. We can push this vector in the answer vector and then we can clear the vector and repeat the process until the queue is empty.

// Time Complexity: O(n)
// Space Complexity: O(n)

// psedo code:
// function levelOrder(root):
//     ans = []
//     if root is equal to NULL:
//         return ans
//     make a queue q
//     push root in q
//     while q is not empty:
//         size = size of q
//         make a vector temp
//         for i = 0 to size:
//             curr = front of q
//             pop q
//             push curr->val in temp
//             for j = 0 to size of curr->children:
//                 push curr->children[j] in q
//         push temp in ans
//     return ans

// Language: cpp
