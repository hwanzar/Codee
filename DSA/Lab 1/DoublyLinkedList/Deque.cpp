#include <bits/stdc++.h>
using namespace std;

class Deque
{
private:
    class Node
    {
    private:
        int value;
        Node *left;
        Node *right;
        friend class Deque;

    public:
        Node(int val = 0, Node *l = nullptr, Node *r = nullptr) : value(val), left(l), right(r) {}
    };

private:
    Node *head;
    Node *tail;
    int curSize;

public:
    Deque()
    {
        head = nullptr;
        tail = nullptr;
        curSize = 0;
    }
    ~Deque()
    {
        clear();
    }
    int getSize() { return curSize; }
    void pushFront(int item)
    {
        // push item to the left, to head.
        Node *pf = new Node(item, nullptr, head);
        if (head == nullptr)
            tail = pf;
        else
            head->left = pf;
        head = pf; // change the head to be the new Node contain item value.
        curSize++; // ủa vậy, head cũ có còn nhớ ko, tên là gì
    }
    void pushBack(int item)
    {
        Node *pb = new Node(item);
        if (tail == nullptr)
        {
            head = pb;
        }
        else
        {
            tail->right = pb;
        }
        tail = pb;
        curSize++;
    }

    int popFront()
    {
        if (curSize == 0)
        {
            return -1;
        }
        if (curSize == 1)
        {
            int ans = head->value;
            delete head;
            head = nullptr;
            curSize--;
            return ans;
        }
        Node *curr = head;
        head = head->right;
        int ans = curr->value;
        delete curr;
        head->left = nullptr;
        curSize--;
        return ans;
    }
    int popBack()
    {
        if (curSize == 0)
        {
            return -1;
        }
        if (curSize == 1)
        {
            int ans = head->value;
            delete head;
            head = nullptr;
            curSize--;
            return ans;
        }
        Node *curr = head;
    }
    void clear()
    {
        while (head != nullptr)
        {
            Node *posHead = head;
            head = head->right;
            delete posHead;
        }
        tail = nullptr;
        curSize = 0;
    }
    void printDequeReverse()
    {
        Node *cur = tail;
        while (cur != nullptr)
        {
            cout << cur->value << " ";
            cur = cur->left;
        }
        cout << endl;
    }
    void printDeque()
    {
        Node *curNode = head;
        while (curNode != nullptr)
        {
            cout << curNode->value << " ";
            curNode = curNode->right;
        }
        cout << endl;
    }
    string toString()
    {
        if (curSize == 0)
            return "[]";

        string ans = "[";
        ans += head->value;
        Node *cur = head->right;
        while (cur != nullptr)
        {
            ans += ",";
            ans += cur->value;
            cur = cur->right;
        }
        ans += "]";
        return ans;
    }
};
int main()
{
    cout << "Runned" << endl;

    Deque *deque = new Deque();
    vector<int> arr = {223, 1234, 43, 568, 90, 193, 2109};
    for (int i = 0; i < (int)arr.size(); i++)
    {
        if (i < (int)arr.size() / 2)
            deque->pushFront(arr[i]);
        else
        {
            deque->pushBack(arr[i]);
        }
    }
    deque->printDeque();
    cout << deque->getSize();
    delete deque;
};