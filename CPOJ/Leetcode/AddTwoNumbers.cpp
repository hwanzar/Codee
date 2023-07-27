#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *result = new ListNode();
    ListNode *tmp = result;
    int carry = 0;
    while (l1 != NULL || l2 != NULL || carry)
    {
        int sum = 0;
        if (l1 != NULL)
        {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2 != NULL)
        {
            sum += l2->val;
            l2 = l2->next;
        }
        sum += carry;
        carry = sum / 10;
        ListNode *newNode = new ListNode(sum % 10);
        tmp->next = newNode;
        tmp = tmp->next;
    }
    return result->next;
}
int main()
{
    ListNode *l1 = new ListNode();
    l1->val = 2;
    l1->next = nullptr;
    ListNode *node1 = new ListNode(4);
    l1->next = node1;
    ListNode *node2 = new ListNode(3);
    node1->next = node2;
    for (int i = 0; i < 3; i++)
    {
        cout << l1->val;
        l1 = l1->next;
    }
    return 0;
}
