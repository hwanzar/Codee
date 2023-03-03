#include <bits/stdc++.h>
using namespace std;

template <class T>
class DLinkedList
{
public:
    class Node; // Forward declaration
protected:
    Node *head;
    Node *tail;
    int count;

public:
    DLinkedList()
    {
        this->head = nullptr;
        this->tail = nullptr;
        count = 0;
    }
    ~DLinkedList()
    {
        if ((head != 0) & (tail != 0))
        {
            Node *ptr = head->next;
            while (ptr != tail)
            {
                Node *next = ptr->next;
                delete ptr;
                ptr = next;
            }
        }
        if (head != 0)
            delete head;
        if (tail != 0)
            delete tail;
    }
    void add(const T &e)
    {
        if (count == 0)
        {
            Node *node = new Node(e);
            head = node;
            tail = node;
            tail->next = nullptr;
            count++;
            return;
        }
        Node *node = new Node(e);
        node->previous = tail;
        tail->next = node;
        node->next = nullptr;
        tail = node;
        count++;
        return;
    }
    void add(int index, const T &e)
    {
        if (count == 0)
        {
            add(e);
            return;
        }
        if (index == 0)
        {
            // add head
            Node *node = new Node(e);
            node->next = head;
            head->previous = node;
            head = node;
            count++;
            return;
        }
        if (index == count)
        {
            add(e);
            return;
        }
        Node *prevNode = head;
        int cursor = -1;
        while (cursor < index - 1)
        {
            prevNode = prevNode->next;
            cursor += 1;
        }
        Node *curNode = prevNode->next;
        Node *newNode = new Node(e);

        newNode->next = curNode;
        newNode->previous = prevNode;
        prevNode->next = newNode;
        curNode->previous = newNode;
        return;
    }
    int size() { return count; }
    string toString()
    {
        if (count == 0)
            return "[]";

        cout << head->data << endl;
        string ans = "[";
        ans += to_string(head->data);
        Node *cur = head->next;
        while (cur != nullptr)
        {
            ans += ",";
            ans += to_string(cur->data);
            cur = cur->next;
        }
        ans += "]";
        return ans;
    }

public:
    class Node
    {
    private:
        T data;
        Node *next;
        Node *previous;
        friend class DLinkedList<T>;

    public:
        Node()
        {
            this->previous = NULL;
            this->next = NULL;
        }

        Node(const T &data)
        {
            this->data = data;
            this->previous = NULL;
            this->next = NULL;
        }
    };
};

int main()
{
    DLinkedList<int> list;
    int size = 10;
    for (int idx = 0; idx < size; idx++)
    {
        list.add(idx);
    }
    cout << list.toString();
}