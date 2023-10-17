class Solution {
public:
   bool isBinaryTreeValid(int root, vector<int> &leftChild, vector<int> &rightChild)
{
    vector<bool> visited(leftChild.size(), false);
    queue<int> nodeQueue;                         
    nodeQueue.push(root);
    visited[root] = true;

    while (!nodeQueue.empty())
    {
        int current = nodeQueue.front();
        nodeQueue.pop();

        if (leftChild[current] != -1)
        {
            if (visited[leftChild[current]]) 
                return false;

            nodeQueue.push(leftChild[current]);
            visited[leftChild[current]] = true;
        }

        // Check right child
        if (rightChild[current] != -1)
        {
            if (visited[rightChild[current]]) 
                return false;

            nodeQueue.push(rightChild[current]);
            visited[rightChild[current]] = true; 
        }
    }

    for (int i = 0; i < visited.size(); i++)
        if (!visited[i])
            return false;
    return true;
}

bool validateBinaryTreeNodes(int n, vector<int> &leftChild, vector<int> &rightChild)
{
    vector<int> indegree(n, 0);

    for (int i = 0; i < n; i++)
    {
        int left = leftChild[i];
        int right = rightChild[i];

        if (left != -1)
            indegree[left]++;

        if (right != -1)
            indegree[right]++;
    }

    vector<int> root_candiates;

    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
            root_candiates.push_back(i);
    }

    if (root_candiates.size() != 1)
        return false;

    int root = root_candiates[0];

    return isBinaryTreeValid(root, leftChild, rightChild);
}
};

// Approach
// Binary Tree property
// a) Every child has only one parent.
// b) Only one root -> It has no parent.
// c) Only one connected component.


// Time Complexity: O(n*n)
// Space Complexity: O(n*n)
