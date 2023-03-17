#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *pLeft;
    Node *pRight;
    Node()
    {
        pLeft = pRight = nullptr;
    }
    Node(int data)
    {
        pLeft = pRight = nullptr;
        this->data = data;
    }
};

class BinTree
{
public:
    Node *root;
    void insert(int *arr, int size);
    void InOrder(Node *node);
    void mirror(Node *node);
    // void process(Node *node, int level, int &sum);
    void sumLevel(int L);
    // void process2(Node *node, stack<Node *> &st);
    void printR2L();
};

void BinTree::insert(int *arr, int size)
{
    if (size == 0)
    {
        return;
    }
    queue<Node *> q;
    root = new Node(arr[0]);
    q.push(root);
    int i = 1;
    while (i < size)
    {
        Node *cur = q.front();
        q.pop();
        if (i < size)
        {
            cur->pLeft = new Node(arr[i]);
            q.push(cur->pLeft);
        }
        i++;
        if (i < size)
        {
            cur->pRight = new Node(arr[i]);
            q.push(cur->pRight);
        }
        i++;
    }
}

void BinTree::InOrder(Node *node)
{
    if (node == nullptr)
    {
        return;
    }
    else
    {
        InOrder(node->pLeft);
        cout << node->data << " ";
        InOrder(node->pRight);
    }
}

void recurCntSum(Node *root, int l, int &sum)
{
    if (l == 0 && root != nullptr)
    {
        sum += root->data; // base case
    }
    if (root == nullptr)
    {
        return;
    }
    recurCntSum(root->pLeft, l - 1, sum);
    recurCntSum(root->pRight, l - 1, sum);
}

void BinTree::sumLevel(int L)
{
    int sum = 0;
    recurCntSum(this->root, L, sum);
    cout << "Level " << L << " Sum:" << sum;
}

void swapNode(Node *left, Node *right)
{
    Node *tmp = left;
    left = right;
    right = tmp;  
}
void printQ(queue<Node *> q)
{
}
void BinTree::printR2L()
{
    Node *node = this->root;
    if (node == nullptr)
    {
        return;
    }
    queue<Node *> q;
    q.push(node);
    // if (node->pLeft == nullptr && node->pRight == nullptr)
    // {
    //     printQ(q);
    // }
    // else
    // {
    //     QPath(node->pLeft, q);
    //     QPath(node->pRight, q);
    // }
    while (!q.empty())
    {
        Node *tmp = q.front();
        q.pop();
        cout << tmp->data << " ";
        if (tmp->pLeft != nullptr)
        {
            q.push(tmp->pLeft);
        }
        if (tmp->pRight != nullptr)
        {
            q.push(tmp->pRight);
        }
    }
}

void BinTree::mirror(Node *node)
{
    if (node == nullptr)
    {
        return;
    }
    if (node->pLeft != nullptr && node->pRight != nullptr)
    {
        swapNode(node->pLeft, node->pRight);
    }
    mirror(node->pLeft);
    mirror(node->pRight);
}

int main()
{
    // int *a = new int[5];
    int a[] = {5, 7, 4, 3, 2, 1};
    // for (int i = 1; i <= 6; i++)
    // {
    //     cin >> a[i];
    // }
    // int size = sizeof(arr) / sizeof(arr[0]);
    BinTree *binTree = new BinTree();
    binTree->insert(a, 6);
    binTree->InOrder(binTree->root);
    cout << endl;
    binTree->printR2L();
}