#include <bits/stdc++.h>
using namespace std;

struct Node
{
    char data;
    struct Node *next;
    Node(char data)
    {
        this->data = data;
        this->next = NULL;
    }
};

struct Node *findMiddle(struct Node *head)
{
    struct Node *slow = head;
    struct Node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

struct Node *reverse(struct Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    struct Node *newNode = reverse(head->next);
    struct Node *headNext = head->next;
    headNext->next = head;
    head->next = NULL;
    return newNode;
}

bool isPalindrome(struct Node *head)
{
    if (head == NULL)
    {
        return true;
    }

    struct Node *mid = findMiddle(head);
    struct Node *last = reverse(mid->next);
    struct Node *curr = head;
    while (last != NULL)
    {
        if (last->data != curr->data)
        {
            return false;
        }
        last = last->next;
        curr = curr->next;
    }
    return true;
}

int main()
{
    struct Node *n1 = new Node('A');
    struct Node *n2 = new Node('B');
    struct Node *n3 = new Node('C');
    struct Node *n4 = new Node('B');
    struct Node *n5 = new Node('A');

    struct Node *head = n1;
    head->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = NULL;

    bool ans = isPalindrome(head);
    if (ans)
    {
        cout << "Palindrome";
    }
    else
    {
        cout << "Not a Palindrome";
    }

    return 0;
}
