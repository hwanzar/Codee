#include <iostream>
#include <math.h>
#include <queue>
using namespace std;
#define SEPARATOR "#<ab@17943918#@>#"

enum BalanceValue
{
    LH = -1,
    EH = 0,
    RH = 1
};

void printNSpace(int n)
{
    for (int i = 0; i < n - 1; i++)
        cout << " ";
}

void printInteger(int &n)
{
    cout << n << " ";
}

template <class T>
class AVLTree
{
public:
    class Node;

private:
    Node *root;

protected:
    int getHeightRec(Node *node)
    {
        if (node == NULL)
            return 0;
        int lh = this->getHeightRec(node->pLeft);
        int rh = this->getHeightRec(node->pRight);
        return (lh > rh ? lh : rh) + 1;
    }

public:
    AVLTree() : root(nullptr) {}
    ~AVLTree() {}
    int getHeight()
    {
        return this->getHeightRec(this->root);
    }
    void printTreeStructure()
    {
        int height = this->getHeight();
        if (this->root == NULL)
        {
            cout << "NULL\n";
            return;
        }
        queue<Node *> q;
        q.push(root);
        Node *temp;
        int count = 0;
        int maxNode = 1;
        int level = 0;
        int space = pow(2, height);
        printNSpace(space / 2);
        while (!q.empty())
        {
            temp = q.front();
            q.pop();
            if (temp == NULL)
            {
                cout << " ";
                q.push(NULL);
                q.push(NULL);
            }
            else
            {
                cout << temp->data;
                q.push(temp->pLeft);
                q.push(temp->pRight);
            }
            printNSpace(space);
            count++;
            if (count == maxNode)
            {
                cout << endl;
                count = 0;
                maxNode *= 2;
                level++;
                space /= 2;
                printNSpace(space / 2);
            }
            if (level == height)
                return;
        }
    }
    Node *rotRight(Node *x)
    {
        Node *y = x->pLeft;
        Node *tmp = y->pRight;

        y->pRight = x;
        x->pLeft = tmp;
        return y;
    }
    Node *rotLeft(Node *x)
    {
        Node *y = x->pRight;
        Node *tmp = y->pLeft;

        y->pLeft = x;
        x->pLeft = tmp;
        return y;
    }

    int getBalance(Node *node)
    {
        if (node == nullptr)
        {
            return 0;
        }
        return getHeightRec(node->pLeft) - getHeightRec(node->pRight);
    }
    Node *insertNode(Node *root, const T &value)
    {
        if (root == nullptr)
            return root;
        if (value < root->data)
        {
            root->pLeft = insertNode(root->pLeft, value);
        }
        if (value >= root->data)
        {
            root->pRight = insertNode(root->pRight, value);
        }

        int balance = getBalance(root);
        if (balance > 1 && root->pLeft->data > value)
        {
            return rotRight(root);
        }
        if (balance > 1 && root->pLeft->data < value)
        {
            root->pLeft = rotLeft(root->pLeft);
            return rotRight(root);
        }
        if (balance < -1 && root->pRight->data < value)
        {
            return rotLeft(root);
        }
        if (balance < -1 && root->pRight->data > value)
        {
            root->pRight = rotRight(root->pRight);
            return rotLeft(root);
        }
        return root;
    }
    void insert(const T &value)
    {
        this->root = insertNode(this->root, value);
    }
    // Node *removeNode(Node *root, const T &value)
    // {
    //     if (root == nullptr)
    //     {
    //         return root;
    //     }
    //     if (value < root->data)
    //     {
    //         root->pLeft = removeNode(root->pLeft, value);
    //     }
    //     else if (value > root->data)
    //     {
    //         root->pRight = removeNode(root->pRight, value);
    //     }
    //     else
    //     {
    //         if (root->pLeft == nullptr || root->pRight == nullptr)
    //         {
    //             Node *child = (root->pLeft) ? root->pLeft : root->pRight;
    //             if (child == nullptr)
    //             {
    //                 child = root;
    //                 root = nullptr;
    //             }
    //             else
    //             {
    //                 *root = *child;
    //             }
    //             delete child;
    //         }
    //         else
    //         {
    //             // max Right delete
    //             Node *maxRight = root->pLeft;
    //             while (maxRight->pRight != nullptr)
    //             {
    //                 maxRight = maxRight->pRight;
    //             }
    //             Node *tmp = maxRight;
    //             root->data = tmp->data;

    //             root->pLeft = removeNode(root->pLeft, tmp->data);
    //         }
    //     }

    //     int balance = getHeightRec(root->pLeft) - getHeightRec(root->pRight);
    //     if (balance > 1 && getBalance(root->pLeft) >= 0)
    //     {
    //         return rightRotate(root);
    //     }
    //     if (balance < -1 && getBalance(root->pRight) <= 0)
    //     {
    //         return leftRotate(root);
    //     }
    //     if (balance > 1 && getBalance(root->pLeft) < 0)
    //     {
    //         root->pLeft = leftRotate(root->pLeft);
    //         return rightRotate(root);
    //     }
    //     if (balance < -1 && getBalance(root->pRight) > 0)
    //     {
    //         root->pRight = rightRotate(root->pRight);
    //         return leftRotate(root);
    //     }
    //     return root;
    // }
    Node *removeNode(Node *root, const T &value)
    {
        if (root == nullptr)
            return root;
        if (value < root->data)
        {
            root->pLeft = removeNode(root->pLeft, value);
        }
        else if (value > root->data)
            root->pRight = removeNode(root->pRight, value);
        else{
            if(root->pLeft == nullptr || root->pRight == nullptr){
                Node *child = (root->pLeft) ? root->pLeft : root->pRight;
                if(child == nullptr){
                    child = root;
                    root = nullptr;
                }
                else{
                    *root = *child;
                }
                delete child;
            }
            else{
                // find max Right; (min right)
                Node *maxR = root->pLeft;
                while(maxR->pRight != nullptr){
                    maxR = maxR->pRight;
                }
                Node *tmp = maxR;
                root->data = tmp->data;
                root->pLeft = removeNode(root->pLeft, tmp->data);
            }
        }
        int balance = getBalance(root);
        if(balance > 1 && getBalance(root->pLeft) >= 0){
            return rotRight(root);
        }
        if(balance > 1 && getBalance(root->pLeft) < 0){
            root->pLeft = rotLeft(root->pLeft);
            return rotRight(root);
        }
        if(balance < -1 && getBalance(root->pRight) >= 0){
            return rotLeft(root);
        }
        if(balance < -1 && getBalance(root->pRight) < 0){
            root->pRight = rotRight(root->pRight);
            return rotRight(root);
        }
        return root;
    }
    void remove(const T &value)
    {
        this->root = removeNode(this->root, value);
        // updateBalance(this->root);
    }
    void updateBalance(Node *&root)
    {
        if (root == nullptr)
        {
            return;
        }
        int balanceVal = getHeightRec(root->pLeft) - getHeightRec(root->pRight);
        if (balanceVal == -1)
        {
            root->balance = RH;
        }
        else if (balanceVal == 0)
        {
            root->balance = EH;
        }
        else
        {
            updateBalance(root->pLeft);
            updateBalance(root->pRight);
        }
    }
    // TODO
    class Node
    {
    private:
        T data;
        Node *pLeft, *pRight;
        BalanceValue balance;
        friend class AVLTree<T>;

    public:
        Node(T value) : data(value), pLeft(NULL), pRight(NULL), balance(EH) {}
        ~Node() {}
    };
};
int main()
{
    AVLTree<int> avl;
    int arr[] = {10, 52, 98, 32, 68, 92, 40, 13, 42, 63};
    for (int i = 0; i < 10; i++)
    {
        avl.insert(arr[i]);
    }
    avl.remove(10);
    avl.printTreeStructure();
}