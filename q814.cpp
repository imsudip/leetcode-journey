/*
Author: Sudip Ghosh (sudipghosh9333@gmail.com)
q814.cpp (c) 2022
Desc: Binary Tree Pruning
Created:  2022-09-06T05:27:26.252Z
Modified: 2022-09-06T05:37:12.552Z
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode *pruneTree(TreeNode *root)
    {
        if (root == NULL)
        {
            return NULL;
        }
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        if (root->val == 0 && root->left == NULL && root->right == NULL)
        {
            return NULL;
        }
        return root;
    }
};

// complexity: O(n)
// Question: https://leetcode.com/problems/binary-tree-pruning/

// Approach: Recursion
// one observation is that if the root is 0 and both its left and right child are NULL then we can return NULL
// else we can return the root
// here we are using recursion to solve this problem. we are calling the function recursively for left and right subtree. if the left and right subtree both are null and the value of the current node is 0 then we are returning null. otherwise we are returning the current node.
//
