#include <bits/stdc++.h>
using namespace std;

template <class T>
class Node
{
public:
    T data;
    Node *next;
    Node(T data)
    {
        this->data = data;
        next = nullptr;
    }
};

template <class T>
class SLinkedList
{
public:
    Node<T> *head;

public:
    SLinkedList()
    {
        head = nullptr;
    }
    void insert(T data)
    {
        Node<T> *newNode = new Node<T>(data);
        if (head == nullptr)
        {
            head = newNode;
            return;
        }
        Node<T> *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    void Delete(T data)
    {
        if (head->data == data)
        {
            Node<T> *temp = head->next;
            delete head;
            head = temp;
        }
        else
        {
            Node<T> *temp = head;
            while (temp->next != nullptr)
            {
                if (temp->next->next != nullptr && temp->next->data == data)
                {
                    Node<T> *curr = temp->next->next;
                    Node<T> *check = temp->next;
                    delete check;
                    temp->next = curr;
                    break;
                }
                temp = temp->next;
            }
        }
    }
    void print()
    {
        Node<T> *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
        }
        cout << endl;
    }
    void Print(T data)
    {
        Node<T> *temp = head;
        bool flag = false;
        while (temp != nullptr)
        {
            if (temp->data == data)
            {
                flag = true;
                break;
            }
            temp = temp->next;
        }
        while (temp != nullptr && flag == true)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    SLinkedList<int> SLL;
    SLL.insert(1);
    SLL.insert(2);
    SLL.insert(3);
    SLL.Print(1);
    SLL.insert(5);
    SLL.insert(6);
    // SLL.print();
    SLL.Print(3);
    SLL.Print(4);
    SLL.Delete(2);
    SLL.Print(1);
}