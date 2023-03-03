#include <bits/stdc++.h>
using namespace std;
template <class T>
class Node
{
private:
    T data;
    Node *right;
    Node *left;
    friend class DLinkedList<T>;

public:
    Node()
    {
        this->left = NULL;
        this->right = NULL;
    }

    Node(const T &data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
    Node(int val = 0, Node *l = nullptr, Node *r = nullptr) :
};

template <class T>
class DLinkedList
{
public:
protected:
    Node *head;
    Node *tail;
    int count;

public:
    DLinkedList()
    {
        head = nullptr;
        tail = nullptr;
        count = 0;
    }
    ~DLinkedList()
    {
        while (head != nullptr)
        {
            Node *posHead = head;
            head = head->right;
            delete posHead;
        }
        tail = nullptr;
        count = 0;
    }
    void add(const T &e)
    {
        Node *node = new Node(e, tail, tail->left);
        (tail->left)->right = node;
        tail->left = node;
        count++;
    }
    void add(int index, const T &e)
    {
        if ((index < 0) || (index > count))
        {
            throw out_of_range("The index is out of range");
        }
        Node *newNode = new Node(e);
        Node *prevNode = head;
        int cursor = -1;

        while (cursor < index - 1)
        {
            prevNode = prevNode->right;
            cursor++;
        }
        Node *curNode = prevNode->right;
        newNode->right = curNode;
        newNode->left = prevNode;
        prevNode->right = newNode;
        curNode->left = newNode;

        if (index == count)
            tail->left = newNode;
        count += 1;
    }
    int size() { return count; }
    bool empty() { return count == 0; }
    Node getPreviousNodeOf(int index)
    {
        Node *prevNode = 0;
        int cursor;

        int mid = count / 2;
        if (index < mid)
        {
            prevNode = head;
            cursor = -1;
            while (cursor < index - 1)
            {
                prevNode = prevNode->right;
                cursor++;
            }
        }
        else
        {
            prevNode = tail;
            cursor = count;
            while (cursor >= index)
            {
                prevNode = prevNode->left;
                cursor -= 1;
            }
        }
        return prevNode;
    }
    T get(int index)
    {
        if ((index < 0) || (index > count))
            throw out_of_range("This index is out of range");
        Node *prevNode = getPreviousNodeOf(index);
        return prevNode->right->data;
    }
    void set(int index, const T &e)
    {
    }
    int indexOf(const T &item);
    bool contains(const T &item);
};

int main()
{
    DLinkedList<int> list;
    int size = 10;
    for (int idx = 0; idx < size; idx++)
    {
        list.add(idx);
    }
    for (int idx = 0; idx < size; idx++)
    {
        cout << list.get(idx) << " |";
    }
}