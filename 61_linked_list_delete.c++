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

void deleteNode(struct Node *head, int pos)
{
    int count = 0;
    struct Node *curr = head;
    while (curr != NULL)
    {
        count++;
        curr = curr->next;
    }

    if (pos > count)
    {
        cout << "\nPlease check your position of deletion of element";
        exit(0);
    }

    if (pos == 0)
    {
        head = head->next;
        return;
    }

    struct Node *prev = head;
    for (int i = 0; i < pos - 1; i++)
    {
        prev = prev->next;
    }
    prev->next = prev->next->next;
}

void traverse(struct Node *head)
{
    struct Node *current = head;
    while (current != NULL)
    {
        cout << current->data << " ";
        current = current->next;
    }
}

int main()
{
    struct Node *n1 = new Node(5);
    struct Node *n2 = new Node(10);
    struct Node *n3 = new Node(15);
    struct Node *n4 = new Node(24);
    struct Node *n5 = new Node(40);

    struct Node *head = n1;
    head->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = NULL;

    cout << "Before deletion: ";
    traverse(head);

    deleteNode(head, 2);

    cout << "\nAfter deleteion: ";
    traverse(head);

    return 0;
}
