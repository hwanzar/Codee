#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include "main.h"
using namespace std;

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

table *latestTable = nullptr;
int checkREGM = -1;
table *regm_head = nullptr;
int num_regm = 0;
class DLL
{
public:
    class Node
    {
    public:
        int idx;
        int ID;
        string name;
        int age;
        Node *prev;
        Node *next;
        Node(int ID = 0, string name = "", int age = 0, Node *next = nullptr, Node *prev = nullptr) : ID(ID), name(name), age(age), next(next), prev(prev), idx(1) {}

        Node()
        {
            idx = 1;
            ID = 0;
            name = "";
            age = 0;
        }
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

        if (head->next == nullptr)
        {
            head->prev = nullptr;
            head = nullptr;
            tail = nullptr;
        }
        else if (prev == nullptr)
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
    Node *pop_front()
    {
        return removeAt(0);
    }
    Node *pop_back()
    {
        return removeAt(cnt - 1);
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
        cout << "Empty\n";
        return;
    }
    if (index < 0 || index > dll.size())
    {
        throw out_of_range("Index out of range");
    }
    DLL::Node *cur = dll.head;
    for (int i = 0; i < index; i++)
    {
        // cout << i << ": " << cur->ID << " " << cur->name << " " << cur->age << endl;
        cout << cur->idx << cur->name << "\n";
        cur = cur->next;
    }
}

void printReverse(DLL &dll, int index)
{
    if (dll.empty())
    {
        cout << "Empty\n";
        return;
    }
    if (index < 0 || index > dll.size())
    {
        throw out_of_range("Index out of range");
    }
    DLL::Node *cur = dll.tail;
    for (int i = dll.size() - 1; i >= dll.size() - index; i--)
    {
        // cout << i << ": " << cur->ID << " " << cur->name << " " << cur->age << endl;
        cout << cur->idx << cur->name << "\n";
        cur = cur->prev;
    }
}

DLL *getIdxDLL(DLL *dll)
{

    DLL::Node *cur = dll->head;
    for (int i = 0; i < dll->size(); i++)
    {
        cur->idx = i;
        cur = cur->next;
    }
    return dll;
}

string getFirstWord(string input)
{
    // string command;
    size_t pos = input.find(" ");
    string command = input.substr(0, pos);
    return command;
}
int countSpaces(string s)
{
    int count = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s.at(i) == ' ')
        {
            count++;
        }
    }
    return count;
}

int getID(string input)
{
    string command = input.substr(0, 3); // extract first 3 characters
    int cntSpc = -1;
    string id_str = "";
    if (command == "REG")
    {
        cntSpc = countSpaces(input);
        if (cntSpc == 3)
        {
            int start = 4;
            int end = input.find(" ", start);
            id_str = input.substr(start, end - start);
            // cout << id_str << endl;
            return stoi(id_str);
        }
        else
        {
            return -100;
        }
    }
    else if (command == "CLE")
    {
        int pos = input.rfind(" ");
        string id_toCLE = input.substr(pos + 1);
        return stoi(id_toCLE);
    }
    else
    {
        return -100; // not a valid command, return -100
    }
}
int getNum(string input)
{
    // only for regm right?S
    int pos = input.rfind(" ");
    int num = -1;
    if (pos != string::npos)
    {
        string num_str = input.substr(pos + 1);
        num = stoi(num_str);
        cout << "NUM " << num << endl;
    }
    return num;
}
string getName(string input)
{
    // int pos;
    // cout << input << endl;
    if (input.substr(0, 4) == "REG ")
    {
        size_t pos = input.find(" ");
        if (countSpaces(input) == 3)
        {
            // truong hop ko co id
            input = input.substr(pos + 1);
            // cout << id << " " << input << endl;
            pos = input.find(" ");
            input = input.substr(pos + 1);
            pos = input.find(" ");
            input = input.substr(0, pos);
        }
        else
        {
            input = input.substr(pos + 1);
            // cout << input << endl;
            pos = input.find(" ");
            // input = input.substr(pos + 1);
            // pos = input.find(" ");
            input = input.substr(0, pos);
        }
    }
    if (input.substr(0, 4) == "REGM")
    {
        int pos = input.find(" ");
        input = input.substr(pos + 1);
        pos = input.find(" ");
        // cout << input << endl;
        // input = input.substr(pos + 1);

        input = input.substr(0, pos);
    }

    string name = input;
    return name;
}
// int main()
// {
//     string input = "REGM Gia 18 2";
//     string firstWord = getFirstWord(input);
//     cout << "First word: " << firstWord << endl;
//     cout << firstWord.length() << endl;

//     cout << endl;
//     cout << "DEBUG\n\n";
//     // cout << "ID: " << getID(input) << endl;
//     cout << getNum(input) << endl;
//     return 0;
// }

int main()
{
    // DLL *dll = new DLL();
    // dll->add(1, "Alice", 20);
    // dll->add(3, "Bob", 20);
    // dll->add(2, "Diva", 20);
    // dll->add(4, "Davisd", 20);
    // dll->add(5, "Lna0", 20);
    // dll->removeAt(0);
    // cout << "Printing DLL from head to index:" << endl;

    // DLL *dll2 = getIdxDLL(dll);
    // printForward(*dll, 4);
    // // *dll2 = getIdxDLL(dll);
    // cout << endl;

    // // cout << "Printing DLL in reverse from tail to index:" << endl;
    // dll2->removeAt(1);
    // printForward(*dll2, 3);
    // string line = "REG ";
    // line = line + to_string(1) + " " + "Gia" + " " + to_string(19);
    // cout << line;
    string line = "REG 15 pu 90";
    cout << getName(line) << endl;
    cout << getID(line) << endl;
    return 0;
}