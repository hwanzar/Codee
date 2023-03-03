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

    // 3.cpp
    bool empty()
    {
        return (count == 0) ? true : false;
    }
    T get(int index)
    {
        if (index < 0 || index >= count)
        {
            throw std::out_of_range("Index out of bounds");
        }

        Node *cur;
        if (index < count / 2)
        {
            cur = head;
            for (int i = 0; i < index; i++)
            {
                cur = cur->next;
            }
        }
        else
        {
            cur = tail;
            for (int i = count - 1; i > index; i--)
            {
                cur = cur->previous;
            }
        }

        return cur->data;
    }

    void set(int index, const T &e)
    {
        if (index < 0 || index >= count)
        {
            throw std::out_of_range("Index out of bounds");
        }

        Node *cur;
        if (index < count / 2)
        {
            cur = head;
            for (int i = 0; i < index; i++)
            {
                cur = cur->next;
            }
        }
        else
        {
            cur = tail;
            for (int i = count - 1; i > index; i--)
            {
                cur = cur->previous;
            }
        }

        cur->data = e;
    }
    int indexOf(const T &item)
    {
        // return the first index whether item appears in list, otherwise rt -1.

        Node *cur = head;
        int i = 0;
        while (cur != nullptr)
        {
            if (cur->data == item)
            {
                return i;
            }
            cur = cur->next;
            i++;
        }
        return -1;
    }
    bool contains(const T &item)
    {
        // check if item appears in the list
        return (indexOf(item) != -1);
    }

    T removeAt(int index)
    {
        // remove element at index and return removed value
        if (count == 0 || index < 0 || index >= count)
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
        T res = cur->data;
        // now delete
        if (prev == nullptr)
        {
            head = head->next;
            head->previous = nullptr;
        }
        else if (cur->next == nullptr)
        {
            prev->next = nullptr;
            tail = prev;
        }
        else
        {
            prev->next = cur->next;
            (cur->next)->previous = prev;
        }
        delete cur;
        count--;
        return res;
    }
    bool removeItem(const T &item)
    {
        // remove the first appearance of item in list, return true, or false;
        // if(cur->data == item) return true
        // else return false;
    }
    void clear()
    {
        Node *clr = head;
        while (clr != nullptr)
        {
            Node *tmp = clr->next;
            delete clr;
            clr = tmp;
        }
        head = nullptr;
        tail = nullptr;
        count = 0;
        // Node *temp = head;
        // while (head != nullptr)
        // {

        //     temp = head;
        //     head = head->next;

        //     delete temp;
        // }

        // cout << "delete success \n";
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
    // DLinkedList<int> list;
    // int size = 10;
    // for (int idx = 0; idx < size; idx++)
    // {
    //     list.add(idx);
    // }
    // cout << list.toString() << endl;

    // for (int idx = 0; idx < size; idx++)
    // {
    //     cout << list.get(idx) << "|";
    // }
    // DLinkedList<int> list;
    // int size = 10;
    // int value[] = {2, 5, 6, 3, 67, 332, 43, 1, 0, 9};
    // for (int idx = 0; idx < size; idx++)
    // {
    //     list.add(idx);
    // }
    // for (int idx = 0; idx < size; idx++)
    // {
    //     list.set(idx, value[idx]);
    // }
    // cout << list.toString() << endl;
    // list.clear();
    // cout << list.toString() << endl;
    // // list.add(12);
    // // cout << list.toString();
    DLinkedList<int> list;
    int size = 10;
    int value[] = {2, 5, 6, 3, 67, 332, 43, 1, 0, 9};

    for (int idx = 0; idx < size; idx++)
    {
        list.add(value[idx]);
    }
    cout << list.toString() << endl;
    list.removeAt(5);
    cout << list.toString();
}