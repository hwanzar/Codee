#include <bits/stdc++.h>
#include "main.h"
using namespace std;
// template <class E>
// class DLL
// {
// public:
//     class Node
//     {
//     public:
//         E data;
//         Node *prev;
//         Node *next;
//         Node(const E &data = E{}, Node *next = nullptr, Node *prev = nullptr) : data(data), next(next), prev(prev) {}
//     };

// public:
//     Node *head;
//     Node *tail;
//     int cnt;

//     DLL() : head(NULL), tail(NULL), cnt(0) {}
//     ~DLL()
//     {
//         clear();
//     }

//     void add(const E &value)
//     {
//         if (cnt == 0)
//         {
//             Node *node = new Node(value);
//             head = node;
//             tail = node;
//             tail->next = nullptr;
//             cnt++;
//             return;
//         }
//         Node *node = new Node(value);
//         node->prev = tail;
//         tail->next = node;
//         node->next = nullptr;
//         tail = node;
//         cnt++;
//         return;
//     }
//     void add(int index, const E &e)
//     {
//         if (index < 0 || index > cnt)
//         {
//             throw out_of_range("Index out of range");
//         }

//         if (cnt == 0)
//         {
//             add(e);
//             return;
//         }
//         if (index == 0)
//         {
//             Node *node = new Node(e);
//             node->next = head;
//             head->prev = node;
//             head = node;
//             cnt++;
//             return;
//         }
//         if (index == cnt)
//         {
//             add(e);
//             return;
//         }
//         Node *cur = head;
//         for (int i = 0; i < index; i++)
//         {
//             cur = cur->next;
//         }
//         // add node
//         Node *addNode = new Node(e, cur->prev, cur);
//         cur->prev->next = addNode;
//         cur->prev = addNode;
//         cnt++;
//     }
//     int size() { return cnt; }
//     bool empty()
//     {
//         return cnt == 0;
//     }
//     void clear()
//     {
//         Node *current = head;
//         while (current != tail)
//         {
//             Node *temp = current;
//             current = current->next;
//             delete temp;
//         }
//         head->next = tail;
//         tail->prev = head;
//         cnt = 0;
//     }
//     E removeAt(int index)
//     {
//         if (cnt == 0 || index < 0 || index >= cnt)
//         {
//             throw std::out_of_range("Invalid index");
//         }
//         Node *cur = head;
//         Node *prev = nullptr;

//         for (int i = 0; i < index; i++)
//         {
//             prev = cur;
//             cur = cur->next;
//         }
//         E res = cur->data;
//         // now delete
//         if (prev == nullptr)
//         {
//             head = head->next;
//             head->prev = nullptr;
//         }
//         else if (cur->next == nullptr)
//         {
//             prev->next = nullptr;
//             tail = prev;
//         }
//         else
//         {
//             prev->next = cur->next;
//             (cur->next)->prev = prev;
//         }
//         delete cur;
//         cnt--;
//         return res;
//     }
//     bool removeItem(const E &item)
//     {
//         Node *temp = head;
//         for (int i = 0; temp != nullptr; i++)
//         {
//             if (temp->data == item)
//             {
//                 removeAt(i);
//                 return true;
//             }
//             temp = temp->next;
//         }
//         return false;
//     }
//     void debug_DLL()
//     {
//         cout << "[";
//         if (head != nullptr)
//         {
//             cout << head->data;
//             Node *current = head->next;
//             while (current != nullptr)
//             {
//                 cout << "," << current->data;
//                 current = current->next;
//             }
//         }
//         cout << "]" << endl;
//     }
// };
// preparation of double linked list for stack and queue

class DLL
{
public:
    class Node
    {
    public:
        int ID;
        string name;
        int age;
        Node *prev;
        Node *next;
        Node(int ID = 0, string name = "", int age = 0, Node *next = nullptr, Node *prev = nullptr) : ID(ID), name(name), age(age), next(next), prev(prev) {}
    };

public:
    Node *head;
    Node *tail;
    int cnt;

    DLL() : head(NULL), tail(NULL), cnt(0) {}
    ~DLL()
    {
        clear();
    }

    void add(int ID, string name, int age)
    {
        // O(1)
        if (cnt == 0)
        {
            Node *node = new Node(ID, name, age);
            head = node;
            tail = node;
            tail->next = nullptr;
            cnt++;
            return;
        }
        Node *node = new Node(ID, name, age);
        node->prev = tail;
        tail->next = node;
        node->next = nullptr;
        tail = node;
        cnt++;
        return;
    }
    void add(int index, int ID, string name, int age)
    {
        // O(index)
        if (index < 0 || index > cnt)
        {
            throw out_of_range("Index out of range");
        }

        if (cnt == 0)
        {
            add(ID, name, age);
            return;
        }
        if (index == 0)
        {
            Node *node = new Node(ID, name, age);
            node->next = head;
            head->prev = node;
            head = node;
            cnt++;
            return;
        }
        if (index == cnt)
        {
            add(ID, name, age);
            return;
        }
        Node *cur = head;
        for (int i = 0; i < index; i++)
        {
            cur = cur->next;
        }
        // add node
        Node *addNode = new Node(ID, name, age, cur->prev, cur);
        cur->prev->next = addNode;
        cur->prev = addNode;
        cnt++;
    }
    int size() { return cnt; }
    bool empty()
    {
        return cnt == 0;
    }
    void clear()
    {
        while (head != nullptr)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
        cnt = 0;
    }
    Node *removeAt(int index)
    {
        if (cnt == 0 || index < 0 || index >= cnt)
        {
            throw std::out_of_range("Invalid index");
        }
        Node *cur = head;
        Node *prev = nullptr;

        for (int i = 0; i < index; i++)
        {
            prev = cur;
            cur = cur->next;
        }
        // now delete
        if (prev == nullptr)
        {
            head = head->next;
            head->prev = nullptr;
        }
        else if (cur->next == nullptr)
        {
            prev->next = nullptr;
            tail = prev;
        }
        else
        {
            prev->next = cur->next;
            (cur->next)->prev = prev;
        }
        cnt--;
        return cur;
    }
};
template <class E>
class Stack
{
public:
    DLL<E> list;

public:
    Stack() {}

    void push(const E &item)
    {
        list.add(item);
    }

    E pop()
    {
        if (list.empty())
        {
            throw runtime_error("Stack is empty");
        }
        return list.removeAt(list.size() - 1);
    }

    E peek()
    {
        if (list.empty())
        {
            throw runtime_error("Stack is empty");
        }
        return list.tail->data;
    }

    int size()
    {
        return list.size();
    }

    bool empty()
    {
        return list.empty();
    }
};

template <class E>
class Queue
{
public:
    DLL<E> list;

public:
    Queue() {}

    void enqueue(const E &item)
    {
        list.add(item);
    }

    E dequeue()
    {
        if (list.empty())
        {
            throw runtime_error("Queue is empty");
        }
        return list.removeAt(0);
    }

    E peek()
    {
        if (list.empty())
        {
            throw runtime_error("Queue is empty");
        }
        return list.head->data;
    }

    int size()
    {
        return list.size();
    }

    bool empty()
    {
        return list.empty();
    }
};

int main()
{
    // create a stack using DLL

    string input1 = "REG 1 Gia 19";
    string input2 = "REG Gia 115";

    DLL<int> list;
    list.add(1);
    list.add(1, 3);
    list.debug_DLL();
    // int id1 = getIDNumber(input1);
    // int id2 = getIDNumber(input2);

    // cout << "ID number for input1: " << id1 << endl;
    // cout << "ID number for input2: " << id2 << endl;
    Stack<int> stk;
    stk.push(1);
    stk.push(2);
    cout << stk.pop() << endl;

    Queue<int> q;
    q.enqueue(12);
    q.enqueue(13);
    q.enqueue(14);
    cout << q.dequeue() << endl;

    Queue<table> waitlist;
    table *tb = new table(10, "Gia", 100, nullptr);
    cout << tb->ID << endl;
    waitlist.enqueue(*tb);
    table tb1 = waitlist.list.head->data;
    cout << tb1.age << endl;

    return 0;
}