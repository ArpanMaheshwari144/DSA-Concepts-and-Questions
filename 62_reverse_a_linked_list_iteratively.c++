#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void traverse(struct Node *head)
{
    struct Node *current = head;
    while (current != NULL)
    {
        cout << current->data << " ";
        current = current->next;
    }
}

struct Node *reverse(struct Node *head)
{
    struct Node *curr = head;
    struct Node *prev = NULL;
    while (curr != NULL)
    {
        struct Node *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}

int main()
{
    struct Node *n1 = new Node(1);
    struct Node *n2 = new Node(2);
    struct Node *n3 = new Node(3);
    struct Node *n4 = new Node(4);

    struct Node *head = n1;
    head->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = NULL;

    cout << "Before reversing the linked list: ";
    traverse(head);

    struct Node *ans = reverse(head);

    cout << "\nAfter reversing the linked list: ";
    traverse(ans);

    return 0;
}
