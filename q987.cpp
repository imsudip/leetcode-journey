/*
Author: Sudip Ghosh (sudipghosh9333@gmail.com)
q987.cpp (c) 2022
Desc: Vertical Order Traversal of a Binary Tree
Created:  2022-09-04T08:33:47.499Z
Modified: 2022-09-04T09:18:50.141Z
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
    void solve(TreeNode *root, int vLevel, int hLevel, map<int, map<int, vector<int>>> &m)
    {
        if (root == NULL)
        {
            return;
        }
        map<int, vector<int>> tempMap = m.count(vLevel) ? m[vLevel] : map<int, vector<int>>();
        vector<int> value = tempMap.count(hLevel) ? tempMap[hLevel] : vector<int>();

        value.push_back(root->val);
        tempMap[hLevel] = value;
        m[vLevel] = tempMap;

        solve(root->left, vLevel - 1, hLevel + 1, m);
        solve(root->right, vLevel + 1, hLevel + 1, m);
    }
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (root == NULL)
        {
            return ans;
        }
        map<int, map<int, vector<int>>> m;
        solve(root, 0, 0, m);
        for (auto it = m.begin(); it != m.end(); it++)
        {
            vector<int> temp;
            for (auto it2 = it->second.begin(); it2 != it->second.end(); it2++)
            {
                sort(it2->second.begin(), it2->second.end());
                for (int i = 0; i < it2->second.size(); i++)
                {
                    temp.push_back(it2->second[i]);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
