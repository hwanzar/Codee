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
    void add(int n)
    {
        // add n to node
        Node *newNode = new Node(n, nullptr);
        if (head == nullptr)
        {
            head = newNode;
            tail = head;
        }
        else
        {
            // exist a linked list, so make a current node to traverse.
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }
    string toString()
    {
        string ans = "[";
        while (head)
        {
            ans += head->value;
            if (head->next)
            {
                ans += ", ";
            }
            head = head->next;
        }
        ans += "]";
        return ans;
    }
    void replace(LinkedList *linked_list, int low, int high)
    {
        if(low < 0) low = 0;
        if (high >= size) high = size - 1;
        if(low > high) return;


        // node procedure
    
    }
};

int main()
{
    LinkedList *l1 = new LinkedList();
    LinkedList *l2 = new LinkedList();
    l1->add(10);
    l1->add(20);
    l1->add(30);
    l1->add(40);
    l1->add(50);
    l2->add(55);
    l2->add(45);
    l2->add(42);
    l1->replace(l2, -1, 2);
    cout << l1->toString() << "\n";
}