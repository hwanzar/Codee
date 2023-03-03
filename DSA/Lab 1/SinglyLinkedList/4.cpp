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
    SLinkedList() : head(NULL), tail(NULL), count(0){};
    ~SLinkedList(){};
    void add(T e)
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
    void add(int index, T e)
    {
        if (index == count)
        {
            add(e);
        }
        else if (index == 0)
        {
            Node *newNode = new Node(e, head);
            head = newNode;
            count++;
        }
        else
        {
            Node *current = head;
            for (int i = 0; i < index - 1; i++)
            {
                current = current->next;
            }
            Node *newNode = new Node(e, current->next);
            current->next = newNode;
            count++;
        }
    }
    int size()
    {
        return count;
    }
    bool empty()
    {
        if (head == nullptr)
            return true;
        return false;
    }
    T get(int index)
    {
        if (index >= count)
            return T();

        Node *p = head;
        for (int i = 0; i < index; i++)
        {
            p = p->next;
        }
        return p->data;
    }
    void set(int index, T e)
    {
        if (index >= count)
            return;
        Node *current = head;
        for (int i = 0; i < index; i++)
        {
            current = current->next;
        }

        current->data = e;
    }
    int indexOf(T item)
    {
        // return the first index whether item appears in list, otherwise return -1;
        return -1;
    }
    bool contains(T item)
    {
        // check if the item appear in the list
        Node *cur = head;
        while (cur != nullptr)
        {
            if (item == cur->data)
            {
                return true;
            }
            cur = cur->next;
        }
        return false;
    }
    string toString()
    {
        if (head == nullptr)
            return "NULL";
        string res = "[";
        Node *p1 = head;
        while (p1 != nullptr)
        {
            res += to_string(p1->data);
            if (p1->next != nullptr)
            {
                res += ",";
            }
            p1 = p1->next;
        }
        res += "]";
        return res;
    }

    T removeAt(int index)
    {
        return T();
    }

    bool removeItem(T item)
    {
    }

    void clear()
    {
    }

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
            next = 0;
        }
        Node(Node *next)
        {
            this->next = next;
        }
        Node(T data, Node *next = NULL)
        {
            this->data = data;
            this->next = next;
        }
    };
};

int main()
{
    // SLinkedList<int> list;
    // int values[] = {10, 15, 2, 6, 4, 7, 40, 8};
    // int index[] = {0, 0, 1, 3, 2, 3, 5, 0};
    // int expvalues[] = {8, 15, 2, 4, 7, 10, 40, 6};

    // for (int idx = 0; idx < 8; idx++)
    // {
    //     list.add(index[idx], values[idx]);
    // }

    // assert(list.size() == 8);

    // for (int idx = 0; idx < 8; idx++)
    // {
    //     assert(list.get(idx) == expvalues[idx]);
    // }
    // cout << list.contains(7) << endl;
    // cout << list.toString();
    SLinkedList<int> list;

    for (int i = 0; i < 10; ++i)
    {
        list.add(i);
    }
    for (int i = 0; i < 10; ++i)
    {
        list.set(i, i + 10);
    }
    for (int i = 0; i < 10; ++i)
    {
        assert(list.get(i) == i + 10);
    }

    cout << list.toString();
    return 0;
}