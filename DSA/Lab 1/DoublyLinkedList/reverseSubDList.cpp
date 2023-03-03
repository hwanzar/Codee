#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    char val;
    ListNode *next;
    ListNode(char v)
    {
        val = v;
        next = NULL;
    }
};

void insertAtBeginning(ListNode *&head, char data)
{
    ListNode *newNode = new ListNode(data);
    newNode->next = head;
    head = newNode;
}

void printList(ListNode *head)
{
    while (head != NULL)
    {
        cout << " " << head->val;
        head = head->next;
    }
    cout << endl;
}

// reverse “count” nodes starting from head.
// A->B->C->D->E->F->G. If C,3 is passed, function will reverse C->D->E and return {E,F}
pair<ListNode *, ListNode *> reverse(ListNode *head, int count)
{
    ListNode *prev = NULL;
    ListNode *curr = head;
    ListNode *temp = curr->next;
    while (count > 0)
    {
        --count;
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return {prev, temp};
}

ListNode *reverseBetween(ListNode *head, int left, int right)
{
    if (head == NULL || head->next == NULL || left == right)
        return head;
    ListNode *leftNode = head;
    ListNode *beforeLeftNode = NULL;
    for (int i = 1; i < left; ++i)
    {
        beforeLeftNode = leftNode;
        leftNode = leftNode->next;
    }
    auto [rightNode, afterRightNode] = reverse(leftNode, right - left + 1);
    if (beforeLeftNode != NULL)
        beforeLeftNode->next = rightNode;
    else
        head = rightNode;
    leftNode->next = afterRightNode;
    return head;
}

int main()
{
    ListNode *head = NULL;
    insertAtBeginning(head, 'H'); // H
    insertAtBeginning(head, 'G'); // G->H
    insertAtBeginning(head, 'F'); // F->G->H
    insertAtBeginning(head, 'E'); // E->F->G->H
    insertAtBeginning(head, 'D'); // D->E->F->G->H
    insertAtBeginning(head, 'C'); // C->D->E->F->G->H
    insertAtBeginning(head, 'B'); // B->C->D->E->F->G->H
    insertAtBeginning(head, 'A'); // A->B->C->D->E->F->G->H

    cout << "List :";
    printList(head); // A->B->C->D->E->F->G->H
    cout << "Reverse List between position 4 and 7:";
    head = reverseBetween(head, 4, 7);
    printList(head); // A->B->C->G->F->E->D->H

    return 0;
}