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
        // Create a dummy node for the result
        LLNode *dummy = new LLNode();
        // Create a pointer to the result node
        LLNode *cur = dummy;
        // Initialize carry to zero
        int carry = 0;

        // Loop over the two input lists until both are exhausted
        while (l0 != nullptr || l1 != nullptr)
        {
            // Extract the values of the current nodes and compute the sum
            int v0 = (l0 != nullptr) ? l0->val : 0;
            int v1 = (l1 != nullptr) ? l1->val : 0;
            int sum = v0 + v1 + carry;

            // Compute the carry for the next iteration
            carry = sum / 10;

            // Create a new node for the current digit
            cur->next = new LLNode(sum % 10, nullptr);

            // Update the pointers to the current nodes
            if (l0 != nullptr)
                l0 = l0->next;
            if (l1 != nullptr)
                l1 = l1->next;
            cur = cur->next;
        }

        // If there is a carry at the end, add a new node for it
        if (carry > 0)
        {
            cur->next = new LLNode(carry, nullptr);
        }

        // Return the result node
        return dummy->next;
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