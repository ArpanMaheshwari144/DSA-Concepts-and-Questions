#include <iostream>
using namespace std;

// Max size of Heap
#define MAX 1000

void heapify(int arr[], int n, int i)
{
    int largest = i;   // Initialize largest as root
    int l = 2 * i;     // left child
    int r = 2 * i + 1; // right child

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
    {
        largest = l;
    }

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
    {
        largest = r;
    }

    // If largest is not root
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest); // Recursively heapify the affected sub-tree
    }
}

void bulidHeap(int arr[], int n)
{
    // indexing start from 0
    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
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
        /  \
	  30   50
     / \   /
    20 35 15
    */

    int arr[MAX] = {10, 30, 50, 20, 35, 15};
    int n = 6;

    bulidHeap(arr, n);
    printArray(arr, n);

    /* Array representation of Max-Heap
          50
        /  \
	  35    30
     / \   /
    20 10 15
    */
    return 0;
}
