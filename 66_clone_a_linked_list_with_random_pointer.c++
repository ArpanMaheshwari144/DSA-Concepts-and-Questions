#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    struct Node *random;
    Node(int data)
    {
        this->data = data;
        this->next = this->random = NULL;
    }
};

struct Node *duplicate(struct Node *head)
{
    struct Node *curr = head;

    // inserting new nodes in between
    while (curr != NULL)
    {
        struct Node *temp = curr->next;
        curr->next = new Node(curr->data);
        curr->next->next = temp;
        curr = temp;
    }
    curr = head;

    // setting random pointers of new node
    while (curr != NULL)
    {
        if (curr->next != NULL)
        {
            curr->next->random = (curr->random != NULL) ? curr->random->next : curr->random;
        }
        curr = curr->next ? curr->next->next : curr->next;
    }

    struct Node *original = head, *copy = head->next;
    struct Node *temp = copy;

    // seperating both the linked lists
    while (original != NULL && copy != NULL)
    {
        original->next = original->next ? original->next->next : original->next;
        copy->next = copy->next ? copy->next->next : copy->next;
        original = original->next;
        copy = copy->next;
    }
    return temp;
}

void printLinkedList(Node *head)
{
    Node *ptr = head;
    while (ptr)
    {
        cout << "Data = " << ptr->data << ", Random  = "
             << ptr->random->data << endl;
        ptr = ptr->next;
    }
}

int main()
{
    struct Node *n1 = new Node(1);
    struct Node *n2 = new Node(2);
    struct Node *n3 = new Node(3);
    struct Node *n4 = new Node(4);
    struct Node *n5 = new Node(5);

    struct Node *head = n1;
    n1->next = n2;
    n1->random = n3;
    n2->next = n3;
    n2->random = n1;
    n3->next = n4;
    n3->random = n5;
    n4->next = n5;
    n4->random = n5;
    n5->next = NULL;
    n5->random = n2;

    cout << "Original Linked List ==>" << endl;
    printLinkedList(head);

    struct Node *ans = duplicate(head);

    cout << "\nClone Linked List ==>" << endl;
    printLinkedList(ans);

    return 0;
}