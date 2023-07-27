#include <bits/stdc++.h>
using namespace std;

class LLNode
{
public:
    int val;
    LLNode *next;
    LLNode() : val(0), next(nullptr) {}                     // Constructor: val = 0, next = nullptr
    LLNode(int val, LLNode *next) : val(val), next(next) {} // Constructor with customized data

    static LLNode *createWithIterators(int *begin, int *end)
    {
        LLNode *head = new LLNode();
        LLNode *curr = head;

        for (int *it = begin; it != end; it++)
        {
            curr->next = new LLNode(*it, nullptr);
            curr = curr->next;
        }

        return head->next;
    }

    static void printList(LLNode *head)
    {
        cout << "[";
        // Loop over the linked list and print the value of each node
        while (head)
        {
            cout << head->val;
            if (head->next)
            {
                std::cout << ", ";
            }
            head = head->next;
        }
        cout << "]" << std::endl;
    }

    void clear()
    {
        LLNode *curr = this;
        while (curr != nullptr)
        {
            LLNode *temp = curr;
            curr = curr->next;
            delete temp;
        }
    }

    static LLNode *reverseList(LLNode *head)
    {
        LLNode *newHead = nullptr;
        while (head != nullptr)
        {
            LLNode *nextHead = head->next;
            if (newHead == nullptr)
            {
                newHead = head;
                head->next = nullptr;
            }
            else
            {
                LLNode *tmpNextHead = newHead;
                newHead = head;
                newHead->next = tmpNextHead;
            }
            head = nextHead;
        }
        return newHead;
    }
    static LLNode *foldLinkedList(LLNode *head)
    {
        if (head == nullptr)
        {
            return nullptr;
        }
        int size = 0;
        LLNode *cur = head;
        LLNode *resTurn = nullptr;
        while (cur != nullptr)
        {
            ++size;
            cur = cur->next;
        }
        if (size == 1)
            return head;

        if (size % 2 != 0)
        {
            LLNode *li1 = head;
            cur = head;
            int half = size / 2;
            while (half - 1 > 0)
            {
                cur = cur->next;
                --half;
            }
            LLNode *li2 = cur->next->next;
            LLNode *tempHead = cur->next;
            tempHead->next = nullptr;
            cur->next = nullptr;
            resTurn = tempHead;
            li1 = reverseList(li1);
            LLNode *res = tempHead;
            while (li1 != nullptr)
            {
                res->next = new LLNode(li1->val + li2->val, nullptr);
                li1 = li1->next;
                li2 = li2->next;
                res = res->next;
            }
        }
        else
        {
            LLNode *li1 = head;
            cur = head;
            int half = size / 2;
            while (half - 1 > 0)
            {
                cur = cur->next;
                --half;
            }
            LLNode *li2 = cur->next;
            cur->next = nullptr;
            li1 = reverseList(li1);

            resTurn = new LLNode(li1->val + li2->val, nullptr);
            LLNode *res = resTurn;
            li1 = li1->next;
            li2 = li2->next;
            while (li1 != nullptr)
            {
                res->next = new LLNode(li1->val + li2->val, nullptr);
                li1 = li1->next;
                li2 = li2->next;
                res = res->next;
            }
        }
        return resTurn;
    }
};

int main()
{
    int arr[] = {9, 5, 7, 5, 0};
    LLNode *head = LLNode::createWithIterators(arr, arr + sizeof(arr) / sizeof(int));
    LLNode::printList(head);
    cout << "\n";
    LLNode *newhead = LLNode::foldLinkedList(head);
    LLNode::printList(newhead);
}