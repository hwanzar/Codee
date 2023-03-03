#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *left;
    ListNode *right;
    ListNode(int x = 0, ListNode *l = nullptr, ListNode *r = nullptr) : val(x), left(l), right(r) {}
};

ListNode *reverse(ListNode *head, int a, int b)
{
    if (!head || !head->right || a == b)
    {
        return head;
    }

    ListNode *dummy = new ListNode(-1);
    dummy->right = head;

    ListNode *cur = dummy;
    for (int i = 1; i < a; i++)
    {
        cur = cur->right;
    }

    ListNode *prev = cur;
    cur = cur->right;

    for (int i = a; i < b; i++)
    {
        ListNode *next = cur->right;
        cur->right = prev;
        cur->left = next;
        prev->left = cur;
        prev = cur;
        cur = next;
    }

    ListNode *next = cur->right;
    cur->right = prev;
    cur->left = next;
    prev->left = cur;
    next->right = prev;

    ListNode *newHead = dummy->right;
    delete dummy;
    return newHead;
}

ListNode *init(int *arr, int n, unordered_map<ListNode *, int> &nodeValue)
{
    ListNode *head = nullptr, *prev = nullptr;
    for (int i = 0; i < n; i++)
    {
        auto node = new ListNode(arr[i], prev);
        if (!prev)
        {
            head = node;
        }
        else
        {
            prev->right = node;
        }
        nodeValue[node] = arr[i];
        prev = node;
    }
    return head;
}

void printList(ListNode *head, unordered_map<ListNode *, int> &nodeValue)
{
    while (head)
    {
        cout << nodeValue[head] << ' ';
        head = head->right;
    }
    cout << '\n';
}

void freeMem(ListNode *head)
{
    while (head)
    {
        auto next = head->right;
        head->left = nullptr;
        delete head;
        head = next;
    }
}

int main()
{
    int size;
    cin >> size;
    int *list = new int[size];
    for (int i = 0; i < size; i++)
    {
        cin >> list[i];
    }
    int a, b;
    cin >> a >> b;
    unordered_map<ListNode *, int> nodeValue;
    ListNode *head = init(list, size, nodeValue);
    printList(head, nodeValue);
    ListNode *reversed = reverse(head, a, b);
    // try
    // {
    //     printList(reversed, nodeValue);
    // }
    // catch (char const *err)
    // {
    //     cout << err << '\n';
    // }
    printList(reversed, nodeValue);
    freeMem(head);
    delete[] list;
}