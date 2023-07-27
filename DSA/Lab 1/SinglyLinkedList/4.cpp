#include <bits/stdc++.h>
using namespace std;

template <class T>
class SLinkedList
{
public:
    class Node; // Forward declaration
protected:
    Node *head;
    Node *tail;
    int count;

public:
    SLinkedList()
    {
        head = nullptr;
        tail = nullptr;
        count = 0;
    }
    ~SLinkedList()
    {
        Node *cur = head;
        while (cur != nullptr)
        {
            Node *temp = cur;
            cur = cur->next;
            delete temp;
        }
        // delete tail;
    }
    void add(const T &e);
    void add(int index, const T &e);
    T get(int index);
    void set(int index, T e);
    int indexOf(T item);
    bool contains(T item);
    bool empty();
    int size();
    string toString()
    {
        Node *prt = head;
        if (head == nullptr)
            return "[]";

        string ans = "[";
        ans += to_string((int)head->data);
        prt = prt->next;
        for (int i = 1; i < count; i++)
        {
            ans += ",";
            ans += to_string((int)prt->data);
            prt = prt->next;
        }
        return ans + "]";
    }
    T removeAt(int index);
    bool removeItem(T item);
    void clear();

public:
    class Node
    {
    private:
        T data;
        Node *next;
        friend class SLinkedList<T>;

    public:
        Node()
        {
            next = nullptr;
        }
        Node(Node *next)
        {
            this->next = next;
        }
        Node(T data, Node *next = nullptr)
        {
            this->data = data;
            this->next = next;
        }
    };
};

template <class T>
void SLinkedList<T>::add(const T &e)
{
    Node *newNode = new Node(e, nullptr);
    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
    count++;
}

template <class T>
void SLinkedList<T>::add(int index, const T &e)
{
    if (index == count)
    {
        add(e);
    }
    else if (index == 0)
    {
        Node *newNode = new Node(index, head);
        head = newNode;
        count++;
    }
    else
    {
        Node *cur = head;
        for (int i = 0; i < index - 1; i++)
        {
            cur = cur->next;
        }
        Node *newNode = new Node(e, cur->next);
        cur->next = newNode;
        count++;
    }
}

template <class T>
T SLinkedList<T>::get(int index)
{
    // get value of specified index
    if (index >= count)
        return T();
    Node *cur = head;
    for (int i = 0; i < index; i++)
    {
        cur = cur->next;
    }
    return cur->data;
}
template <class T>
void SLinkedList<T>::set(int index, T e)
{
    if (index >= count)
        return;
    Node *cur = head;
    for (int i = 0; i < index; i++)
    {
        cur = cur->next;
    }
    cur->data = e;
    return;
}
template <class T>
int SLinkedList<T>::indexOf(T item)
{
    // get index;
    if (head == nullptr)
    {
        return -1;
    }
    Node *cur = head;
    for (int i = 0; i < count; i++)
    {
        if (cur->data == item)
        {
            return i;
        }
        cur = cur->next;
    }
    return -1;
}

template <class T>
int SLinkedList<T>::size()
{
    return count;
}

template <class T>
T SLinkedList<T>::removeAt(int index)
{
    if (index >= count)
        return T();
    Node *cur = head;
    Node *prev = nullptr;
    for (int i = 0; i < index; i++)
    {
        prev = cur;
        cur = cur->next;
    }
    T removeValue = cur->data;
    if (prev == nullptr)
    {
        head = cur->next;
    }
    else
    {
        prev->next = cur->next;
    }
    if (cur == tail)
    {
        tail = prev;
    }
    delete cur;
    count--;
    return removeValue;
}

template <class T>
bool SLinkedList<T>::removeItem(T item)
{
    Node *cur = head;
    Node *prev = nullptr;

    while (cur != nullptr)
    {
        if (cur->data == item)
        {
            if (prev == nullptr)
            {
                head = cur->next;
            }
            else
            {
                prev->next = cur->next;
            }
            if (cur == tail)
            {
                tail = prev;
            }

            delete cur;
            count--;
            return true;
        }
        prev = cur;
        cur = cur->next;
    }
    return false;
}

template <class T>
void SLinkedList<T>::clear()
{
    for (int i = 0; i < count; i++)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    count = 0;
    return;
}

int main()
{

    SLinkedList<int> list;

    for (int i = 0; i < 10; ++i)
    {
        list.add(i);
    }
    assert(list.get(9) == list.removeAt(9));
    list.clear();
    cout << list.toString();
}