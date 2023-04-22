#include <bits/stdc++.h>
#include "../main.h"
using namespace std;
// #define outtext freopen("output.txt", "w", stdout);
class AVL
{
public:
    class Node; // contain key == Result, ID ==

public:
    Node *root;
    int cnt;

public:
    AVL()
    {
        root = nullptr;
        cnt = 0;
    }
    ~AVL()
    {
        while (root != nullptr)
        {
            deleteAVLTree(root->key);
        }
    }

public:
    int height(Node *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int leftHeight = 1 + height(root->left), rightHeight = 1 + height(root->right);
        return max(leftHeight, rightHeight);
    }
    int getBalanceFactor(Node *x)
    {
        if (x == nullptr)
        {
            return 0;
        }
        return height(x->left) - height(x->right);
    }
    Node *rightRotate(Node *x)
    {
        Node *y = x->left;
        x->left = y->right;
        y->right = x;
        y->bal_factor = getBalanceFactor(y);
        x->bal_factor = getBalanceFactor(x);
        return y;
    }
    Node *leftRotate(Node *x)
    {
        Node *y = x->right;
        x->right = y->left;
        y->left = x;
        y->bal_factor = getBalanceFactor(y);
        x->bal_factor = getBalanceFactor(x);
        return y;
    }
    Node *LeftRightRotate(Node *x)
    {
        x->left = leftRotate(x->left);
        return rightRotate(x);
    }
    Node *RightLeftRotate(Node *x)
    {
        x->right = rightRotate(x->right);
        return leftRotate(x);
    }
    Node *balanced(Node *root)
    {
        if (root == nullptr)
        {
            return nullptr;
        }
        root->bal_factor = getBalanceFactor(root);
        if (root->bal_factor > 1)
        {
            if (getBalanceFactor(root->left) > 0)
            {
                root = rightRotate(root);
            }
            else
            {
                root = LeftRightRotate(root);
            }
        }
        else if (root->bal_factor < -1)
        {
            if (getBalanceFactor(root->right) > 0)
            {
                root = RightLeftRotate(root);
            }
            else
            {
                root = leftRotate(root);
            }
        }
        return root;
    }
    Node *addAVL(Node *root, int key, table *tb)
    {
        if (root == nullptr)
        {
            root = new Node(key, tb);
            cnt++;
        }
        else
        {
            if (key < root->key)
            {
                root->left = addAVL(root->left, key, tb);
            }
            else
            {
                root->right = addAVL(root->right, key, tb);
            }
            root = balanced(root);
        }
        return root;
    }
    Node *findMaxValue(Node *x)
    {
        Node *temp = x;
        while (temp->right != nullptr)
        {
            temp = temp->right;
        }
        return temp;
    }
    Node *deleteAVL(Node *root, int key)
    {
        if (root == nullptr)
        {
            return nullptr;
        }
        if (key < root->key)
        {
            root->left = deleteAVL(root->left, key);
        }
        else if (key > root->key)
        {
            root->right = deleteAVL(root->right, key);
        }
        else
        {
            if (root->left == nullptr || root->right == nullptr)
            {
                Node *temp = (root->left == nullptr ? root->right : root->left);
                if (temp == nullptr)
                {
                    temp = root;
                    delete temp;
                    root = nullptr;
                }
                else
                {
                    *root = *temp;
                    delete temp;
                    temp = nullptr;
                }
                cnt--;
            }
            else
            {
                Node *temp = findMaxValue(root->left);
                root->key = temp->key;
                root->left = deleteAVL(root->left, temp->key);
            }
        }
        return balanced(root);
    }
    string toStringPreOrder(Node *root, string ans = "") const
    {
        if (root == nullptr)
        {
            return "";
        }
        ans = ("(key = " + to_string(root->key) + ") " + " (" + to_string(root->tb->id) + ")\n");

        ans += toStringPreOrder(root->left, ans);
        ans += toStringPreOrder(root->right, ans);
        return ans;
    }
    string PrintBFT(Node *root, string ans = "") const
    {
        if (root == nullptr)
            return "Nothing";
        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                Node *curr = q.front();
                q.pop();
                ans += ("Result (KEY): " + to_string(curr->tb->result) + "    " + to_string(curr->tb->id) + "\n");
                if (curr->left != nullptr)
                {
                    q.push(curr->left);
                }
                if (curr->right != nullptr)
                {
                    q.push(curr->right);
                }
            }
            // ans += "\n";
        }
        return ans;
    };

public:
    void addAVLTree(int key, table *tb)
    {
        root = addAVL(root, key, tb);
    }
    void deleteAVLTree(int key)
    {
        root = deleteAVL(root, key);
    }
    int size() const
    {
        return this->cnt;
    }
    string toStringPreOrder() const
    {
        string ans = "==> AREA 2 - AVL <==\n";
        ans += toStringPreOrder(root, ans);
        // ans[ans.length() - 1] = ']';

        return ans + "==================\n";
    }
    string printBFT() const
    {
        string ans = "==> AREA 2 - AVL(BFT) <==\n";

        string answer = PrintBFT(root, ans);
        return answer + "=======================\n";
    }
    bool contains(Node *root, int ID)
    {

        if (root == nullptr)
        {
            return false; // The tree is empty, so the element is not in the tree
        }
        else if (root->tb->id == ID)
        {
            return true; // Found the element
        }

        bool containedLeft = false;
        containedLeft = contains(root->right, ID);
        if (containedLeft == 1)
            return containedLeft;

        bool containedRight = false;
        containedRight = contains(root->left, ID);
        if (containedRight == 1)
            return containedRight;

        return false;
    }
    bool containsID(int ID)
    {
        return contains(root, ID);
    }

public:
    class Node
    {
    public:
        int key;
        table *tb;
        Node *left, *right;
        int bal_factor;
        friend class AVL;

    public:
        Node(int key = 1, table *tb = nullptr, Node *left = nullptr, Node *right = nullptr, int bal_fac = 0)
        {
            this->key = key;
            this->tb = tb;
            this->left = left;
            this->right = right;
            this->bal_factor = bal_fac;
        }
    };
};

// int main()
// {
//     // outtext;
//     AVL avl;
//     // for (int i = 0; i < 12; i++)
//     // {
//     //     table *tb = new table(i, "Gia", i, 1);

//     //     avl.addAVLTree(i, tb);
//     // }
//     table *tb = new table(27, "Gia", 20698, 1);
//     table *tb2 = new table(21, "Gia", 12116, 1);
//     table *tb3 = new table(9, "Gia", 22216, 1);
//     table *tb4 = new table(15, "Gia", 20910, 1);
//     table *tb5 = new table(15, "Gia", 29870, 1);
//     table *tb6 = new table(38, "Gia", 100, 1);
//     table *tb7 = new table(29, "Gia", 30000, 1);
//     avl.addAVLTree(tb->result, tb);
//     avl.addAVLTree(tb2->result, tb2);
//     avl.addAVLTree(tb4->result, tb4);
//     avl.addAVLTree(tb3->result, tb3);
//     avl.addAVLTree(tb5->result, tb5);
//     avl.addAVLTree(tb6->result, tb6);
//     avl.addAVLTree(tb7->result, tb7);
//     cout << avl.toStringPreOrder() << '\n';
//     avl.deleteAVLTree(0);
//     // cout << avl.size();
//     cout << avl.containsID(38);
// }