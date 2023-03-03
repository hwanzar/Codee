#include <iostream>
using namespace std;

// node structure
struct Node
{
    int data;
    Node *next;
    Node *prev;
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList()
    {
        head = NULL;
    }

    // Add new element at the end of the list
    void push_back(int newElement)
    {
        Node *newNode = new Node();
        newNode->data = newElement;
        newNode->next = NULL;
        newNode->prev = NULL;
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    // delete all nodes of the list
    void deleteAllNodes()
    {
        Node *temp = new Node();
        while (head != NULL)
        {
            temp = head;
            head = head->next;
            free(temp);
        }
        cout << "All nodes are deleted successfully.\n";
    }

    // display the content of the list
    void PrintList()
    {
        Node *temp = head;
        if (temp != NULL)
        {
            cout << "The list contains: ";
            while (temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
        else
        {
            cout << "The list is empty.\n";
        }
    }
    T removeAt(int index)
    {
        Node *temp = head;
        /* Remove element at index and return removed value */
        if (temp == nullptr)
        {
            return 0;
        }
        T ret;
        if (index == 0)
        {
            Node *hold = head->next;
            if (head == tail)
            {
                tail = nullptr;
            }
            ret = head->data;
            delete head;
            head = hold;
            if (head != nullptr)
                head->previous = nullptr;
            // return ret;
        }
        else if (index == count - 1)
        {
            Node *hold = tail->previous;
            ret = tail->data;
            delete tail;
            tail = hold;
            tail->next = nullptr;
            // return ret;
        }
        else
        {
            Node *dummy_head = head;
            for (int i = 0; i < index; i++)
            {
                dummy_head = dummy_head->next;
            }
            Node *temp_prev = dummy_head->previous;
            Node *temp_next = dummy_head->next;
            ret = dummy_head->data;
            delete dummy_head;
            temp_prev->next = temp_next;
            temp_next->previous = temp_prev;
        }
        // T a = temp->data;
        // delete temp;
        count--;
        return res;
    }
};

// test the code
int main()
{
    LinkedList MyList;

    // Add four elements in the list.
    MyList.push_back(10);
    MyList.push_back(20);
    MyList.push_back(30);
    MyList.push_back(40);

    // Display the content of the list.
    MyList.PrintList();

    // delete all nodes of the list
    MyList.deleteAllNodes();

    // Display the content of the list.
    MyList.PrintList();

    return 0;
}