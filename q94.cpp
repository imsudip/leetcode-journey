/*
Author: Sudip Ghosh (sudipghosh9333@gmail.com)
q94.cpp (c) 2022
Desc: Binary tree inorder traversal
Created:  2022-09-08T04:12:12.974Z
Modified: 2022-09-08T04:14:30.239Z
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
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        if (root == NULL)
        {
            return ans;
        }
        recurse(root, ans);
        return ans;
    }

    void recurse(TreeNode *root, vector<int> &ans)
    {
        if (root == NULL)
        {
            return;
        }
        recurse(root->left, ans);
        ans.push_back(root->val);
        recurse(root->right, ans);
    }
};
