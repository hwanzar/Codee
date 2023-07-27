#include <bits/stdc++.h>
using namespace std;
#define outtext freopen("output.txt", "w", stdout)
#define _io                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

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
    // static BTNode *createTree(int arr[], int size)
    // {
    //     if (size == 0)
    //         return NULL;
    //     BTNode *root = new BTNode(arr[0]);
    //     queue<BTNode *> q;
    //     q.push(root);
    //     int i = 1;
    //     while (!q.empty() && i < size)
    //     {
    //         BTNode *curr = q.front();
    //         q.pop();
    //         if (arr[i] != -1)
    //         {
    //             curr->left = new BTNode(arr[i]);
    //             q.push(curr->left);
    //         }
    //         i++;
    //         if (i < size && arr[i] != -1)
    //         {
    //             curr->right = new BTNode(arr[i]);
    //             q.push(curr->right);
    //         }
    //         i++;
    //     }
    //     return root;
    // }
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

bool checkGreatAncestor(BTNode *node, int val)
{
    if (node == NULL)
        return true;
    if (node->val > val)
        return false;
    return checkGreatAncestor(node->left, val) && checkGreatAncestor(node->right, val);
}

int count_greatAncestor(BTNode *node)
{
    if (node == NULL)
        return 0;
    int count = 0;
    if (checkGreatAncestor(node, node->val))
        count++;
    count += count_greatAncestor(node->left);
    count += count_greatAncestor(node->right);
    return count;
}
int greatAncestor(BTNode *root)
{
    return count_greatAncestor(root);
}

int largestValue(BTNode *root)
{
    if (root == NULL)
        return 0;
    int max = root->val;
    BTNode *curr = root->left;
    while (curr != NULL)
    {
        if (curr->val > max)
            max = curr->val;
        curr = curr->right;
    }
    return max;
}
// largestDiff
void findDiff(BTNode *node, int base, vector<int> &diff){
    if(node == nullptr) return;
    diff.push_back(abs(node->val - base));
    if(node->left == nullptr && node->right == nullptr){
        return;
    }
    else{
        findDiff(node->left, base, diff);
        findDiff(node->right, base, diff);
    }
}
int largestDiff(BTNode *root){
    if(root == nullptr) return 0;
    vector<int> diff;
    queue<BTNode *> q;
    q.push(root);

    while(!q.empty()){
        BTNode *node = q.front();
        int base = node->val;
        q.pop();

        findDiff(node, base, diff);

        if(node->left != nullptr){
            q.push(node->left);
        }
        if(node->right != nullptr){
            q.push(node->right);
        }
    }
    int max = diff[0];
    for(auto x : diff){
        if(max < x) max = x;
    }
    return max;
}

// sumDigitPath
const int MOD = 27022001;
int sumDigitPathUtils(BTNode *node, int val)
{
    if (node == NULL)
        return 0;
    val = ((val * 10) + node->val) % MOD;
    return (sumDigitPathUtils(node->left, val) + sumDigitPathUtils(node->right, val)) % MOD;
}
int sumDigitPath(BTNode *root)
{
    return sumDigitPathUtils(root, 0);
}

// findDeepest
void findDeepest(BTNode *node, int depth, int &maxDepth, int &secondMaxDepth)
{
    if (node == NULL)
        return;
    if (node->left == NULL && node->right == NULL)
    {
        if (depth > maxDepth)
        {
            secondMaxDepth = maxDepth;
            maxDepth = depth;
        }
        else if (depth > secondMaxDepth && depth < maxDepth)
        {
            secondMaxDepth = depth;
        }
    }
    findDeepest(node->left, depth + 1, maxDepth, secondMaxDepth);
    findDeepest(node->right, depth + 1, maxDepth, secondMaxDepth);
}

int secondDeepest(BTNode *root)
{
    int maxDepth = -1;
    int secondMaxDepth = -1;
    findDeepest(root, 0, maxDepth, secondMaxDepth);
    return secondMaxDepth;
}

// lowestAncestor
int lowestAncestor(BTNode *root, int a, int b)
{
    if (root == NULL)
        return -1;
    if (root->val == a || root->val == b)
        return root->val;
    int left = lowestAncestor(root->left, a, b);
    int right = lowestAncestor(root->right, a, b);
    if (left != -1 && right != -1)
        return root->val;
    if (left != -1)
        return left;
    return right;
}

// ===== longestPathSum =====
int sumPath(vector<int> path){
    int sum = 0;
    for(auto x : path){
        sum += x;
    }
    return sum;
}

vector<int> longestPath(BTNode *root){
    if(root == nullptr){
        vector<int> nothing = {};
        return nothing;
    }
    
}

int longestPathSum(BTNode *root){
    vector<int> resPath = longestPath(root);
    return sumPath(resPath);
}

int main()
{
    _io;
    outtext;
    // int arr[] = {-1, 0, 0};
    // int value[] = {1, 2, 3};
    // BTNode *root = BTNode::createTree(arr, sizeof(arr) / sizeof(int), value);
    // cout << sumDigitPath(root);
    // int arr[] = {-1, 0, 0, 2, 2, 3, 4};
    // int value[] = {1, 2, 3, 4, 5, 6, 7};
    // BTNode *root = BTNode::createTree(arr, sizeof(arr) / sizeof(int), value);
    // cout << secondDeepest(root);
    // cout << distinctParities(root);
    // int arr[] = {-1, 0};
    // int value[] = {1, 0};
    // BTNode *root = BTNode::createTree(arr, sizeof(arr) / sizeof(int), value);
    // cout << largestDiff(root) << "\n";

    // int arr[] = {-1, 0, 0, 2, 2, 3, 3, 5};
    // int value[] = {1, 5, 4, 7, 12, 4, 8, 2};
    // BTNode *root = BTNode::createTree(arr, sizeof(arr) / sizeof(int), value);
    // cout << longestPathSum(root);

    int arr[] = {-1, 0, 0, 2, 2, 3, 3, 5};
    int value[] = {1, 5, 4, 7, 12, 4, 8, 2};
    BTNode *root = BTNode::createTree(arr, sizeof(arr) / sizeof(int), value);
    cout << longestPathSum(root);

    // int arr[] = {-1, 0, 0, 1, 1, 4, 2, 2, 7};
    // int value[] = {3, 4, 5, 6, 7, 8, 9, 10, 0};
    // BTNode *root = BTNode::createTree(arr, sizeof(arr) / sizeof(int), value);
    // cout << longestPathSum(root);
}