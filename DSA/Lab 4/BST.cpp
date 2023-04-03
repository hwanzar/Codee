#include <bits/stdc++.h>
using namespace std;

template <class T>
class BST
{
public:
    class Node;
    Node *root;

public:
    void Insert(T *arr, int size)
    {
        for (int i = 0; i < size; i++)
        {
            if (root == NULL)
            {
                root = new Node(arr[i]);
            }
            else
            {
                _insert(root, arr[i]);
            }
        }
    }
    Node *_insert(Node *node, T data)
    {
        if (node == NULL)
        {
            node = new Node();
            node->data = data;
            node->left = NULL;
            node->right = NULL;
        }
        else if (data < node->data)
        {
            node->left = _insert(node->left, data);
        }
        else if (data > node->data)
        {
            node->right = _insert(node->right, data);
        }
        return node;
    }
    void InsertNonRecur(T *arr, int size)
    {
        for (int i = 0; i < size; i++)
        {
            if (root == nullptr)
            {
                root = arr[i];
            }
            else
            {
                Node *cur = root;
                while (cur != nullptr)
                {
                    if (cur > arr[i])
                    {
                        cur = cur->left;
                    }
                    if (cur < arr[i])
                    {
                        cur = cur->right;
                    }
                }
                Node *newNode = new Node(arr[i]);
                cur = newNode;
            }
        }
    }
    Node *_deleteMinRight(Node *node)
    {
        if (node == NULL)
        {
            return NULL;
        }
        else if (node->left == NULL)
        {
            Node *temp = node->right;
            delete node;
            return temp;
        }
        else
        {
            node->left = _deleteMinRight(node->left);
            return node;
        }
    }
    void Delete(T value, int opt)
    {
        if (opt == 1)
        {
        }
    } // option 1 max Left, option 2 min Right
    bool Find(T value)
    {
        Node *cur = root;
        while (cur != NULL)
        {
            if (cur->data == value)
                return true;
            else
            {
                if (cur->data > value)
                    cur = cur->left;
                else
                    cur = cur->right;
            }
        }
        return false;
    }
    bool checkInorder(Node *root)
    {
        if (root == NULL)
            return false;

        checkInorder(root->left);
        if (root->data > root->left->data)
            return false;

        checkInorder(root->right);
        if (root->data < root->right->data)
            return false;

        return true;
    }
    void inOrderCheck(Node *root, vector<T> &array)
    {
        if (root == NULL)
            return;

        inOrderCheck(root->left, array);
        array.push_back(root->data);
        inOrderCheck(root->right, array);
    }
    bool checkBST(Node *root)
    {
        vector<T> arr;
        inOrderCheck(root, arr);
        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i] < arr[i - 1])
                return false;
        }
        return true;
    }
    void PreOrder(Node *root)
    {
        if (root != NULL)
        {
            cout << root->data << " ";
            PreOrder(root->left);
            PreOrder(root->right);
        }
    }
    void InOrder(Node *root)
    {
        if (root != nullptr)
        {
            InOrder(root->left);
            cout << root->data << " ";
            InOrder(root->right);
        }
    }
    class Node
    {
    public:
        T data;
        Node *right;
        Node *left;
        Node()
        {
            right = nullptr;
            left = nullptr;
        }
        Node(T value)
        {
            this->data = value;
            this->right = nullptr;
            this->left = nullptr;
        }
    };
};

int main()
{
    int arr[] = {3, 5, 7, 8, 9, 2, 10, 11};
    int size = 8;
    BST<int> bst;
    bst.Insert(arr, size);
    bst.PreOrder(bst.root);
    cout << endl;
    cout << bst.checkBST(bst.root) << endl;

    return 0;
}