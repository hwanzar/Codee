#include <bits/stdc++.h>
using namespace std;

class LinkedList
{
public:
    class Node;

private:
    Node *head;
    Node *tail;
    int size;

public:
    class Node
    {
    private:
        int value;
        Node *next;
        friend class LinkedList;

    public:
        Node()
        {
            this->next = NULL;
        }
        Node(Node *node)
        {
            this->value = node->value;
            this->next = node->next;
        }
        Node(int value, Node *next = NULL)
        {
            this->value = value;
            this->next = next;
        }
    };
    LinkedList() : head(NULL), tail(NULL), size(0){};
    void add(int value);
    void partition(int k);
    string toString();
};

void LinkedList::add(int value)
{
    Node *newNode = new Node(value);
    if (tail == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
    size++;
}

string LinkedList::toString()
{
    string ans = "[";
    if (head == NULL)
        return "[]";
    Node *cur = head;
    while (cur != NULL)
    {
        ans += to_string(cur->value);
        if (cur != tail)
        {
            ans += ",";
        }
        cur = cur->next;
    }
    return ans + "]";
}

void LinkedList::partition(int k)
{
    Node *head1 = nullptr;
    Node *tail1 = nullptr;
    Node *head2 = nullptr;
    Node *tail2 = nullptr;
    Node *head3 = nullptr;
    Node *tail3 = nullptr;

    Node *cur = head;

    while (cur != nullptr)
    {
        if (cur->value < k)
        {
            if (head1 == nullptr)
            {
                head1 = cur;
                tail1 = cur;
            }
            else
            {
                tail1->next = cur;
                tail1 = cur;
            }
        }
        else if (cur->value > k)
        {
            if (head3 == nullptr)
            {
                head3 = cur;
                tail3 = cur;
            }
            else
            {
                tail3->next = cur;
                tail3 = cur;
            }
        }
        else
        {
            if (head2 == nullptr)
            {
                head2 = cur;
                tail2 = cur;
            }
            else
            {
                tail2->next = cur;
                tail2 = cur;
            }
        }
        cur = cur->next;
    }
    if (head1 != nullptr)
    {
        head = head1;
        if (head2 != nullptr)
        {
            tail1->next = head2;
            if (head3 != nullptr)
            {
                tail2->next = head3;
                tail = tail3;
            }
            else
            {
                tail = tail2;
            }
        }
    }
    else if (head2 != nullptr)
    {
        head = head2;
        if (head3 != nullptr)
        {
            tail2->next = head3;
            tail = tail3;
        }
        else
            tail = tail2;
    }
    else if (head3 != nullptr)
    {
        head = head3;
        tail = tail3;
    }

    if (tail != nullptr)
    {
        tail->next = nullptr;
    }
}

int main()
{
    LinkedList *l1 = new LinkedList();
    l1->add(20);
    l1->add(30);
    l1->add(10);
    l1->add(60);
    l1->add(40);
    l1->add(45);
    l1->add(55);
    l1->partition(45);
    cout << l1->toString() << endl;
}
