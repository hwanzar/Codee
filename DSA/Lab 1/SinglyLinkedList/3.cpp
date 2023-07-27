#include <bits/stdc++.h>
using namespace std;

class Node
{
    int data;
    Node *next;

public:
    Node() : data(0), next(nullptr) {}

    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }

    int getData()
    {
        return this->data;
    }

    void setData(int data)
    {
        this->data = data;
    }

    Node *getNext()
    {
        return this->next;
    }

    void setNext(Node *next)
    {
        this->next = next;
    }
    static void reduceDuplicate(Node *root)
    {
        Node *cur = root;
        while (cur != nullptr && cur->getNext() != nullptr)
        {
            if (cur->getData() == cur->getNext()->getData())
            {
                Node *tmp = cur->getNext();
                cur->setNext(tmp->getNext());
                delete tmp;
            }
        }
    }
    void printList(Node *head)
    {
    }
};
void reduceDuplicate(Node *head)
{
    Node *cur = head;
    while (cur != nullptr && cur->getNext() != nullptr)
    {
        if (cur->getData() == cur->getNext()->getData())
        {
            Node *tmp = cur->getNext();
            cur->setNext(tmp->getNext());
            delete tmp;
        }
        else
        {
            cur = cur->getNext();
        }
    }
}
void printList(Node *head)
{
    Node *cur = head;
    cout << "HEAD -> ";
    while (cur != nullptr)
    {
        cout << cur->getData() << " ";
        cur = cur->getNext();
        if (cur != nullptr)
        {
            cout << "-> ";
        }
    }
    cout << "-> NULL\n";
}
int main()
{
    Node *node1 = new Node(1, nullptr);
    Node *node2 = new Node(1, node1);
    Node *node3 = new Node(0, node2);
    printList(node3);
    reduceDuplicate(node3);
    printList(node3);
}