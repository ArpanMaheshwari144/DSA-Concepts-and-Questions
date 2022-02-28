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

int main()
{
    struct Node *n1 = new Node(10);
    struct Node *n2 = new Node(20);
    struct Node *n3 = new Node(30);

    struct Node *head = n1;
    head->next = n2;
    n2->next = n3;
    n3->next = NULL;

    traverse(head);

    return 0;
}
