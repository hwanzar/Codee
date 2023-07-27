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

    static LLNode *addLinkedList(LLNode *l0, LLNode *l1)
    {
        LLNode *resHead = new LLNode();
        LLNode *cur = resHead;
        if (!l0 || !l1)
            return nullptr;

        int carry = 0;
        while (l0 != nullptr || l1 != nullptr)
        {
            int res0 = (l0 != nullptr) ? l0->val : 0;
            int res1 = (l1 != nullptr) ? l1->val : 0;
            int sum = res0 + res1 + carry;

            carry = sum / 10;
            cur->next = new LLNode(sum % 10, nullptr);
            cur = cur->next;
            if (l0 != nullptr)
                l0 = l0->next;
            if (l1 != nullptr)
                l1 = l1->next;
        }
        if (carry > 0)
        {
            cur->next = new LLNode(carry, nullptr);
            cur = cur->next;
        }
        return resHead->next;
    }

    void clear(LLNode *head)
    {
        LLNode *curr = head;
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
    int arr1[] = {1, 7, 2};
    int arr2[] = {0, 5};
    LLNode *head1 = LLNode::createWithIterators(arr1, arr1 + sizeof(arr1) / sizeof(int));
    LLNode *head2 = LLNode::createWithIterators(arr2, arr2 + sizeof(arr2) / sizeof(int));
    LLNode *newhead = LLNode::addLinkedList(head1, head2);
    LLNode::printList(newhead);
    head1->clear(head1);
    head2->clear(head2);
    newhead->clear(newhead);
    // arr1[3] = {};
    // arr2[2] = {};
    // delete head1;
    // delete head2;
    // delete newhead;
}