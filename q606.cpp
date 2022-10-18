/*
Author: Sudip Ghosh (sudipghosh9333@gmail.com)
q606.cpp (c) 2022
Desc: Construct String from Binary Tree
Created:  2022-09-07T01:08:36.865Z
Modified: 2022-09-07T02:26:07.169Z
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
    string tree2str(TreeNode *root)
    {
        if (root == NULL)
        {
            return "";
        }
        string ans = to_string(root->val);
        if (root->left == NULL && root->right == NULL)
        {
            return ans;
        }
        if (root->left == NULL) // that means root->right != NULL
        {
            return ans + "()" + "(" + tree2str(root->right) + ")";
        }
        if (root->right == NULL)
        {
            return ans + "(" + tree2str(root->left) + ")";
        }
        return ans + "(" + tree2str(root->left) + ")" + "(" + tree2str(root->right) + ")";
    }
};
int main()
{
    TreeNode *root = new TreeNode(1);
    // root->left = new TreeNode(2);
    // root->right = new TreeNode(3);
    // root->left->left = new TreeNode(4);
    Solution s;
    cout << s.tree2str(root) << endl;
    return 0;
}

// question: https://leetcode.com/problems/construct-string-from-binary-tree/

// Approach: Recursion
// After observing the question we can see that we have traverse the tree in preorder fashion for that we can use recursion.
// we will create a string and we will update the string according to the condition while traversing the tree.
// There are 4 cases:
// 1. if the left and right subtree of the current node is NULL then we will return the string with the value of the current node.
// 2. if the left subtree is NULL and right subtree is not NULL then we will return the string with the value of the current node then we have to add () to the string and then we will call the function recursively for the right subtree.
// 3. if the left subtree is not NULL and right subtree is NULL then we will return the string with the value of the current node then we will call the function recursively for the left subtree.
// 4. if the left subtree is not NULL and right subtree is not NULL then we will return the string with the value of the current node then we will call the function recursively for the left subtree and then we will call the function recursively for the right subtree.

// And that's pretty much it. Let's look at the code now

// Pseudo code:
// function tree2str(root):
//     if root is NULL:
//         return ""
//     ans = value of root
//     if left subtree is NULL and right subtree is NULL:
//         return ans
//     if left subtree is NULL:
//         return ans + "()" + "(" + tree2str(root->right) + ")"
//     if right subtree is NULL:
//         return ans + "(" + tree2str(root->left) + ")"
//     return ans + "(" + tree2str(root->left) + ")" + "(" + tree2str(root->right) + ")"
// end function

// Complexity: O(n)
// Space Complexity: O(n)