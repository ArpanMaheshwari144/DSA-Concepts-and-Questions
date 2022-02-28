#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    struct Node *down;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->down = NULL;
    }
};

// Using Queue
void converList1(struct Node *head)
{
    if (head == NULL)
    {
        return;
    }

    struct Node *curr = head;
    queue<Node *> q;

    // process all nodes
    while (curr != NULL)
    {
        // last node is reached
        if (curr->next == NULL)
        {
            // dequeue the front node and set it as the next node of the current node
            curr->next = q.front();
            q.pop();
        }

        // if the current node has a child
        if (curr->down != NULL)
        {
            q.push(curr->down);
        }

        // advance the current node
        cout << curr->data << " ";
        curr = curr->next;
    }
}

// Without using Queue
void converList2(struct Node *node)
{
    // Base case
    if (node == NULL)
    {
        return;
    }

    struct Node *temp = NULL;

    // find tail node of first level linked list
    struct Node *tail = node;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }

    // one by one traverse through all nodes of first level linked list till we reach the tail node
    struct Node *curr = node;
    while (curr != NULL)
    {
        // if current node has a down
        if (curr->down != NULL)
        {
            // then append the child al the end of current list
            tail->next = curr->down;

            // and update the tail to new last node
            temp = curr->down;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            tail = temp;
        }

        // change the current node
        cout << curr->data << " ";
        curr = curr->next;
    }
}

int main()
{
    struct Node *one = new Node(1);
    struct Node *two = new Node(2);
    struct Node *three = new Node(3);
    struct Node *four = new Node(4);
    struct Node *five = new Node(5);
    struct Node *six = new Node(6);
    struct Node *seven = new Node(7);
    struct Node *eight = new Node(8);
    struct Node *nine = new Node(9);
    struct Node *ten = new Node(10);
    struct Node *eleven = new Node(11);
    struct Node *twelve = new Node(12);
    struct Node *thirteen = new Node(13);
    struct Node *fourteen = new Node(14);
    struct Node *fifteen = new Node(15);
    struct Node *sixteen = new Node(16);
    struct Node *seventeen = new Node(17);
    struct Node *eightteen = new Node(18);
    struct Node *nineteen = new Node(19);

    struct Node *head = one;

    // set next pointers
    one->next = two;
    two->next = three;
    three->next = four;
    four->next = five;
    six->next = seven;
    seven->next = eight;
    nine->next = ten;
    thirteen->next = fourteen;
    sixteen->next = seventeen;
    seventeen->next = eightteen;

    // set down pointers
    one->down = six;
    four->down = nine;
    seven->down = eleven;
    eight->down = twelve;
    nine->down = thirteen;
    twelve->down = fifteen;
    thirteen->down = sixteen;
    seventeen->down = nineteen;

    cout << "The converted list is: ";
    converList1(head);

    // cout << "The converted list is: ";
    // converList2(head);

    return 0;
}