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

    void printInorderNode(Node *root)
    {
        if (root != NULL)
        {
            printInorderNode(root->pLeft);

            cout << root->data << " ";

            printInorderNode(root->pRight);
        }
    }

    void printInorder()
    {
        printInorderNode(root);
    }

    bool searchNode(Node *root, const T &value)
    {
        if (root == NULL)
            return false;
        if (root->data == value)
            return true;
        return searchNode(root->pLeft, value) || searchNode(root->pRight, value);
    }

    bool search(const T &value)
    {
        return searchNode(root, value);
    }
    // Helping functions
    Node *rightRotate(Node *y)
    {
        Node *x = y->pLeft;
        Node *temp = x->pRight;

        // Perform rotation
        x->pRight = y;
        y->pLeft = temp;

        // Return new root
        return x;
    }

    Node *leftRotate(Node *x)
    {
        Node *y = x->pRight;
        Node *temp = y->pLeft;

        // Perform rotation
        y->pLeft = x;
        x->pRight = temp;

        // Return new root
        return y;
    }

    int getBalance(Node *node)
    {
        if (node == NULL)
            return 0;
        return getHeightRec(node->pLeft) - getHeightRec(node->pRight);
    }

    Node *insertNode(Node *root, const T &value)
    {
        if (root == NULL)
            return new Node(value);

        if (value < root->data)
            root->pLeft = insertNode(root->pLeft, value);
        else if (value >= root->data)
            root->pRight = insertNode(root->pRight, value);

        int balance = getBalance(root);

        // Left Left Case
        if (balance > 1 && value < root->pLeft->data)
            return rightRotate(root);

        // Right Right Case
        if (balance < -1 && value >= root->pRight->data)
            return leftRotate(root);

        // Left Right Case
        if (balance > 1 && value > root->pLeft->data)
        {
            root->pLeft = leftRotate(root->pLeft);
            return rightRotate(root);
        }

        // Right Left Case
        if (balance < -1 && value < root->pRight->data)
        {
            root->pRight = rightRotate(root->pRight);
            return leftRotate(root);
        }

        /* return the (unchanged) node pointer */
        return root;
    }

    void insert(const T &value)
    {
        this->root = insertNode(this->root, value);
    }

    void rotR(Node *&node)
    {
        // Node *p = node->pLeft;
        // node->pLeft = p->pRight;
        // p->pRight = node;
        Node *p = node;
        node = node->pLeft;
        p->pLeft = node->pRight;
        node->pRight = p;
    }
    void rotL(Node *&node)
    {
        // Node *p = node->pRight;
        // node->pRight = p->pLeft;
        // p->pLeft = node;
        Node *p = node;
        node = node->pRight;
        p->pRight = node->pLeft;
        node->pLeft = p;
    }
    void rotRL(Node *&node)
    {
        rotR(node->pRight);
        rotL(node);
    }
    void rotLR(Node *&node)
    {
        rotL(node->pLeft);
        rotR(node);
    }
    bool balanceLeft(Node *&node)
    {
        if (node->balance == EH)
        {
            node->balance = LH;
            return true;
        }
        else if (node->balance == RH)
        {
            node->balance = EH;
            return false;
        }
        else
        {
            if (node->pLeft->balance == LH)
            {
                rotR(node);
                node->balance = EH;
                node->pRight->balance = EH;
                return false;
            }
            else if (node->pLeft->balance == EH)
            {
                rotR(node);
                node->balance = RH;
                node->pRight->balance = LH;
                return true;
            }

            rotLR(node);
            node->pLeft->balance = EH;
            node->pRight->balance = EH;
            if (node->balance == LH)
            {
                node->pRight->balance = RH;
            }
            else if (node->balance == RH)
            {
                node->pLeft->balance = LH;
            }
            node->balance = EH;
            return false;
        }
    }
    bool balanceRight(Node *&node)
    {
        if (node->balance == EH)
        {
            node->balance = RH;
            return true;
        }
        else if (node->balance == LH)
        {
            node->balance = EH;
            return false;
        }
        else
        {
            if (node->pRight->balance == RH)
            {
                rotL(node);
                node->balance = EH;
                node->pLeft->balance = EH;
                return false;
            }
            else if (node->pRight->balance == EH)
            {
                rotL(node);
                node->balance = LH;
                node->pLeft->balance = RH;
                return true;
            }

            rotRL(node);
            node->pRight->balance = EH;
            node->pLeft->balance = EH;
            if (node->balance == RH)
            {
                node->pLeft->balance = LH;
            }
            else if (node->balance == LH)
            {
                node->pRight->balance = RH;
            }
            node->balance = EH;
            return false;
        }
    }

    bool remove(Node *&curr, const T &value)
    {
        if (curr == NULL)
            return false;
        if (curr->data == value)
        {
            if (curr->pLeft == NULL && curr->pRight == NULL)
            {
                delete curr;
                curr = nullptr;
                return true;
            }
            else if (!curr->pRight)
            {
                Node *p = curr;
                curr = curr->pLeft;
                delete p;
                return true;
            }
            else if (!curr->pLeft)
            {
                Node *p = curr;
                curr = curr->pRight;
                delete p;
                return true;
            }
            Node *tmp = curr->pRight;
            while (tmp->pLeft)
            {
                tmp = tmp->pLeft;
            }
            curr->data = tmp->data;
            if (remove(curr->pRight, curr->data))
                return !balanceLeft(curr);
            return false;
        }
        if (value < curr->data)
        {
            if (remove(curr->pLeft, value))
                return !balanceRight(curr);
            return false;
        }
        else
        {
            if (remove(curr->pRight, value))
                return !balanceLeft(curr);
            return false;
        }
    }
    // bool remove(Node *&curr, const T &value)
    // {
    //     if (curr == nullptr)
    //     {
    //         return false;
    //     }

    //     if (value < curr->data)
    //     {
    //         if (remove(curr->pLeft, value))
    //         {
    //             return !balanceRight(curr);
    //         }
    //         return false;
    //     }
    //     else if (value > curr->data)
    //     {
    //         if (remove(curr->pRight, value))
    //         {
    //             return !balanceLeft(curr);
    //         }
    //         return false;
    //     }
    //     else
    //     { // curr->data == value
    //         if (curr->pLeft == nullptr && curr->pRight == nullptr)
    //         { // Case 1: Leaf node
    //             delete curr;
    //             curr = nullptr;
    //         }
    //         else if (curr->pRight == nullptr)
    //         { // Case 2a: Single child (left)
    //             Node *temp = curr;
    //             curr = curr->pLeft;
    //             delete temp;
    //         }
    //         else if (curr->pLeft == nullptr)
    //         { // Case 2b: Single child (right)
    //             Node *temp = curr;
    //             curr = curr->pRight;
    //             delete temp;
    //         }
    //         else
    //         { // Case 3: Two children
    //             Node *minNode = curr->pRight;
    //             while (minNode->pLeft != nullptr)
    //             {
    //                 minNode = minNode->pLeft;
    //             }
    //             curr->data = minNode->data;
    //             if (remove(curr->pRight, minNode->data))
    //             {
    //                 return !balanceLeft(curr);
    //             }

    //             return false;
    //         }
    //         return true;
    //     }
    // }

    void remove(const T &value)
    {
        // TODO
        remove(root, value);
        balanceLeft(root);
        // balanceRight(root);
    }

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
    // int arr[] = {10, 7, 15, 5, 9};
    for (int i = 0; i < 10; i++)
    {
        avl.insert(arr[i]);
    }
    avl.printTreeStructure();
    cout << endl;
    avl.remove(92);
    avl.printTreeStructure();
    cout << endl;
    avl.remove(5);
    avl.printTreeStructure();
}