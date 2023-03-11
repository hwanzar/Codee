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

    // static LLNode *foldLinkedList(LLNode *head)
    // {
    //     if (head == nullptr)
    //     {
    //         return head;
    //     }

    //     vector<int> v;
    //     LLNode *tmp = head;
    //     while (tmp != nullptr)
    //     {
    //         v.push_back(tmp->val);
    //         tmp = tmp->next;
    //     }

    //     int lo = 0;
    //     int hi = (int)v.size() - 1;
    //     stack<int> st;
    //     while (lo <= hi)
    //     {
    //         if (lo == hi)
    //         {
    //             st.push(v[lo]);
    //         }
    //         else
    //         {
    //             st.push(v[lo] + v[hi]);
    //         }
    //         lo++;
    //         hi--;
    //     }

    //     vector<LLNode *> ve;
    //     while (!st.empty())
    //     {
    //         ve.push_back(new LLNode(st.top(), nullptr));
    //         st.pop();
    //     }
    //     int n = (int)ve.size();
    //     int i = 1;
    //     LLNode *cur = new LLNode();
    //     cur = ve[0];
    //     while (i < n)
    //     {
    //         // cout << ve[i]->val << endl;
    //         cur->next = new LLNode(ve[i]->val, nullptr);
    //         cur = cur->next;
    //         i++;
    //     }
    //     return ve[0];
    // }
    static LLNode *foldLinkedList(LLNode *head)
    {
        // STUDENT ANSWER
        // if (head == nullptr || head->next == nullptr)
        //     return head;

        LLNode *slow = head;
        LLNode *fast = head;
        // Go to the middle node
        while ((fast->next)->next->next != nullptr)
        {
            slow = slow->next;
            fast = (fast->next)->next;
        }
        // // Reverse the 2nd half
        LLNode *prev = new LLNode();
        LLNode *curr = slow->next;
        LLNode *next = new LLNode();
        while (curr != nullptr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        slow->next = nullptr;
        // Merge
        LLNode *p1 = head;
        LLNode *p2 = prev;
        while (p2 != nullptr)
        {
            p1->val += p2->val;
            p1 = p1->next;
            p2 = p2->next;
        }
        return head;
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