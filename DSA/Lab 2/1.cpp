// Implement all methods in class Stack with template type T. The description of each method is written as comment in frame code.
#include <bits/stdc++.h>
using namespace std;

template <class T>
class DLinkedList
{
public:
    class Node
    {
    public:
        T data;
        Node *prev;
        Node *next;
        Node(const T &d = T{}, Node *p = nullptr, Node *n = nullptr)
            : data{d}, prev{p}, next{n} {}
    };

public:
    Node *head;
    Node *tail;
    int count;

public:
    DLinkedList() : head{nullptr}, tail{nullptr}, count{0} {}
    ~DLinkedList() { clear(); }
    void add(const T &e)
    {
        Node *node = new Node(e);
        if (count == 0)
        {
            head = node;
            tail = node;
            count++;
            return;
        }
        node->prev = tail;
        tail->next = node;
        tail = node;
        count++;
        // delete node;
    }
    void add(int index, const T &e)
    {
        if ((index < 0) || (index > count))
        {
            throw out_of_range("The index is out of range");
        }
        Node *node = new Node(e);
        if (head == nullptr)
        {
            add(e);
            return;
        }
        Node *cur = head;
        Node *pre = head;
        for (int i = 0; i < index; i++)
        {
            pre = cur;
            cur = cur->next;
        }
        pre->next = node;
        node->prev = pre;
        node->next = cur;
        cur->prev = node;
        count += 1;
    }

    T removeAt(int index)
    {
        if (index < 0 || index >= count)
            throw std::out_of_range("Index out of range");
        Node *p = head;
        Node *cur = head;
        for (int i = 0; i < index; i++)
        {
            p = cur;
            cur = cur->next;
        }
        T data = cur->data;
        // if (p->prev)
        //     p->prev->next = p->next;
        // else
        //     head = p->next;
        // if (p->next)
        //     p->next->prev = p->prev;
        // else
        //     tail = p->prev;
        // delete p;
        if (cur != tail)
        {
            p->next = cur->next;
            cur->next->prev = p;
        }
        else
        {
            p->next = nullptr;
            tail = p;
        }
        // delete cur;
        count--;
        return data;
    }
    bool removeItem(const T &removeItem)
    {
        Node *p = head;
        while (p)
        {
            if (p->data == removeItem)
            {
                if (p->prev)
                    p->prev->next = p->next;
                else
                    head = p->next;
                if (p->next)
                    p->next->prev = p->prev;
                else
                    tail = p->prev;
                delete p;
                count--;
                return true;
            }
            p = p->next;
        }
        return false;
    }
    bool empty() { return count == 0; }
    int size() { return count; }
    void clear()
    {
        while (head->next != nullptr)
        {
            Node *p = head;
            head = head->next;
            delete p;
        }
        // delete head;
        count = 0;
    }
    T get(int index)
    {
        if (index < 0 || index >= count)
            throw std::out_of_range("Index out of range");
        Node *p = head;
        for (int i = 0; i < index; i++)
            p = p->next;
        return p->data;
    }
    void set(int index, const T &e)
    {
        if (index < 0 || index >= count)
            throw std::out_of_range("Index out of range");
        Node *p = head;
        for (int i = 0; i < index; i++)
            p = p->next;
        p->data = e;
    }
    int indexOf(const T &item) const
    {
        Node *curr = head;
        int index = 0;
        while (curr != nullptr)
        {
            if (curr->data == item)
            {
                return index;
            }
            curr = curr->next;
            index++;
        }
        return -1;
    }
};

template <class T>
class Stack
{
protected:
    DLinkedList<T> list;

public:
    Stack() {}
    void push(T item)
    {
        list.add(item);
    }
    T pop()
    {
        return list.removeAt(list.size() - 1);
    }
    T top()
    {
        return list.get(list.size() - 1);
    }
    bool empty()
    {
        return list.empty();
    }
    int size()
    {
        return list.size();
    }
    void clear()
    {
        list.clear();
    }
};

int main()
{
    Stack<int> stack;

    int item[] = {3, 1, 4, 5, 2, 8, 10, 12};
    for (int idx = 0; idx < 8; idx++)
        stack.push(item[idx]);

    assert(stack.top() == 12);

    stack.pop();
    stack.pop();

    cout << stack.top();
}