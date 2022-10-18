/*
Author: Sudip Ghosh (sudipghosh9333@gmail.com)
q653.cpp (c) 2022
Desc: Two Sum IV - Input is a BST
Created:  Sun Oct 09 2022 22:50:14 GMT+0530 (India Standard Time)
Modified: 2022-10-09T17:24:40.984Z
*/

// Question :Given the root of a Binary Search Tree and a target number k, return true if there exist two elements in the BST such that their sum is equal to the given target.
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
    bool findTarget(TreeNode *root, int k)
    {
        unordered_set<int> s;
        return find(root, k, s);
    }
    bool find(TreeNode *root, int k, unordered_set<int> &s)
    {
        if (root == NULL)
        {
            return false;
        }
        if (s.find(k - root->val) != s.end())
        {
            return true;
        }
        s.insert(root->val);
        return find(root->left, k, s) || find(root->right, k, s);
    }
};

int main()
{
    Solution s;
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);
    cout << s.findTarget(root, 9) << endl;
    return 0;
}