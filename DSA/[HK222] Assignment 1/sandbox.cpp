#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include "main.h"
using namespace std;

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

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
    void push_front(int ID, string name, int age)
    {
        add(0, ID, name, age);
    }
    void push_back(int ID, string name, int age)
    {
        add(ID, name, age);
    }
    void pop_front()
    {
        removeAt(0);
    }
    void pop_back()
    {
        removeAt(cnt - 1);
    }

    Node *front()
    {
        if (cnt == 0)
        {
            throw out_of_range("Deque is empty");
        }
        return head;
    }
    Node *back()
    {
        if (cnt == 0)
        {
            throw out_of_range("Deque is empty");
        }
        return tail;
    }
};
void printForward(DLL &dll, int index)
{
    if (dll.empty())
    {
        cout << "Deque is empty" << endl;
        return;
    }
    if (index < 0 || index >= dll.size())
    {
        throw out_of_range("Index out of range");
    }
    DLL::Node *cur = dll.head;
    for (int i = 0; i <= index; i++)
    {
        cout << i << ": " << cur->ID << " " << cur->name << " " << cur->age << endl;
        cur = cur->next;
    }
}

void printReverse(DLL &dll, int index)
{
    if (dll.empty())
    {
        cout << "Deque is empty" << endl;
        return;
    }
    if (index < 0 || index >= dll.size())
    {
        throw out_of_range("Index out of range");
    }
    DLL::Node *cur = dll.tail;
    for (int i = dll.size() - 1; i >= index; i--)
    {
        cout << i << ": " << cur->ID << " " << cur->name << " " << cur->age << endl;
        cur = cur->prev;
    }
}

int main()
{
    DLL dll;
    dll.add(1, "Alice", 20);
    dll.add(2, "Bob", 25);
    dll.add(3, "Charlie", 30);
    dll.add(4, "David", 35);
    dll.add(5, "Eva", 40);

    cout << "Printing DLL from head to index:" << endl;
    printForward(dll, 3);

    cout << endl;

    cout << "Printing DLL in reverse from tail to index:" << endl;
    printReverse(dll, 2);

    return 0;
}
