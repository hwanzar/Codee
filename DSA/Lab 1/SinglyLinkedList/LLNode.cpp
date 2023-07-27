//#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class LLNode
{
public:
    int val;
    LLNode *next;
    LLNode() : val(0), next(nullptr) {}
    LLNode(int val, LLNode *next) : val(val), next(next) {}

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

    static LLNode* addLinkedList(LLNode* l0, LLNode* l1) {
        LLNode* resHead = new LLNode();
        LLNode* cur = resHead;

        if (!l0 || !l1) {
            return 
        }
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
};

int main()
{
    int arr1[] = {2, 9};
    int arr2[] = {0, 5};
    LLNode *head1 = LLNode::createWithIterators(arr1, arr1 + sizeof(arr1) / sizeof(int));
    LLNode *head2 = LLNode::createWithIterators(arr2, arr2 + sizeof(arr2) / sizeof(int));
    LLNode *newhead = LLNode::addLinkedList(head1, head2);
    LLNode::printList(newhead);
    head1->clear();
    head2->clear();
    newhead->clear();
}