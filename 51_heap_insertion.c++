#include <iostream>
using namespace std;

// Max size of Heap
#define MAX 1000

void heapify(int arr[], int n, int i)
{
    // Find parent
    int parent = (i - 1) / 2;

    if (arr[parent] > 0)
    {
        // For max-heap if current node is greater than its parent swap both of them and call heapify again for the parent
        if (arr[i] > arr[parent])
        {
            swap(arr[i], arr[parent]);

            // Recursively heapify the parent node
            heapify(arr, n, parent);
        }
    }
}

void insertNode(int arr[], int &n, int Key)
{
    // Increase the size of Heap by 1
    n = n + 1;

    // Insert the element at end of Heap
    arr[n - 1] = Key;

    // Heapify the new node following a bottom-up approach
    heapify(arr, n, n - 1);
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Driver Code
int main()
{
    /* Array representation 
         10
        / \
	  5   3
     / \
    2  4
    */

    int arr[MAX] = {10, 5, 3, 2, 4};
    int n = 5;
    int key = 15;

    insertNode(arr, n, key);
    printArray(arr, n);

    /* Array representation of Max-Heap
          15
        /  \
	  5    10
     / \  /
    2  4 3
    */
    return 0;
}
