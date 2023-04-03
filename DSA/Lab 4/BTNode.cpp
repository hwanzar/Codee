#include <bits/stdc++.h>
using namespace std;
class BTNode
{
public:
    int val;
    BTNode *left;
    BTNode *right;
    BTNode()
    {
        this->left = this->right = NULL;
    }
    BTNode(int val)
    {
        this->val = val;
        this->left = this->right = NULL;
    }
    BTNode(int val, BTNode *&left, BTNode *&right)
    {
        this->val = val;
        this->left = left;
        this->right = right;
    }
    static BTNode *createTree(int *parentIndices, int n, int *values)
    {
        unordered_map<int, BTNode *> nodes;
        BTNode *root = nullptr;

        // create nodes
        for (int i = 0; i < n; i++)
        {
            nodes[i] = new BTNode(values[i]);
            if (parentIndices[i] == -1)
            {
                root = nodes[i];
            }
        }

        // connect nodes
        for (int i = 0; i < n; i++)
        {
            if (parentIndices[i] != -1)
            {
                BTNode *parent = nodes[parentIndices[i]];
                if (parent->left == nullptr)
                {
                    parent->left = nodes[i];
                }
                else
                {
                    parent->right = nodes[i];
                }
            }
        }

        return root;
    }
};
int sumSubtree(BTNode *root)
{
    if (root == NULL)
        return 0;
    return root->val + sumSubtree(root->left) + sumSubtree(root->right);
}
int distinctParities(BTNode *root)
{
    if (root == NULL)
        return 0;
    if (root->left != NULL && root->right != NULL)
    {
        if (sumSubtree(root->left) + sumSubtree(root->right) % 2 != 0)
            return 1 + distinctParities(root->left) + distinctParities(root->right);
    }
    return distinctParities(root->left) + distinctParities(root->right);
}
int greatAncestor(BTNode *root)
{
    if (!root)
    {
        return 0;
    }
    int count = 0;
    if (!root->left && !root->right)
    {
        // leaf node is a great ancestor node
        return 1;
    }
    else
    {
        // check if root is a great ancestor node
        bool isGreatAncestor = true;
        if (root->left)
        {
            isGreatAncestor &= root->val >= root->left->val && greatAncestor(root->left) > 0;
        }
        if (root->right)
        {
            isGreatAncestor &= root->val >= root->right->val && greatAncestor(root->right) > 0;
        }
        if (isGreatAncestor)
        {
            count++;
        }
    }
    return count;
}

int main()
{
    int arr[] = {-1, 0, 0, 2, 2};
    int value[] = {1, 5, 3, 4, 7};
    int n = sizeof(arr) / sizeof(int);
    BTNode *root = BTNode::createTree(arr, n, value);
    cout << distinctParities(root);
}