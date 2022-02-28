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

void removeLoop(struct Node *slow, struct Node *head)
{
    // Do for each node of the linked list
    for (Node *curr = head; curr != nullptr; curr = curr->next)
    {
        // start a pointer `ptr` from the `slow` node and check if it meets the current node `curr`
        Node *ptr = slow;
        while (ptr->next != slow && ptr->next != curr)
        {
            ptr = ptr->next;
        }

        /* If `ptr` meets `curr`, then that means there is a loop, and `curr` points to the first node of the loop and `ptr` points to the last node */
        if (ptr->next == curr)
        {
            // set next pointer of `ptr` to `null` to break the chain
            ptr->next = nullptr;
            return;
        }
    }
}

struct Node *detectCycle(struct Node *head)
{
    struct Node *slow = head;
    struct Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            return slow;
        }
    }
    return NULL;
}

void printLinkedList(Node *head)
{
    Node *curr = head;
    while (curr)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
}

int main()
{
    struct Node *n1 = new Node(1);
    struct Node *n2 = new Node(2);
    struct Node *n3 = new Node(3);
    struct Node *n4 = new Node(4);
    struct Node *n5 = new Node(5);
    struct Node *n6 = new Node(6);

    struct Node *head = n1;
    head->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = n3;
    // n6->next = NULL;

    struct Node *ans = detectCycle(head);
    if (ans)
    {
        struct Node *meet = ans;
        struct Node *start = head;
        while (start != meet)
        {
            start = start->next;
            meet = meet->next;
        }
        cout << "Cycle is present at node " << start->data << endl;
        cout << "After removing the cycle the linked list is: ";
        removeLoop(ans, head);
        printLinkedList(head);
    }
    else
    {
        cout << "Cycle is not present";
    }

    return 0;
}