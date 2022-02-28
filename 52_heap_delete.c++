#include <iostream>
using namespace std;

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

void deleteRoot(int arr[], int &n)
{
    // Get the last element
    int lastElement = arr[n - 1];

    // Replace root with first element
    arr[0] = lastElement;

    // Decrease size of heap by 1
    n = n - 1;

    // heapify the root node
    heapify(arr, n, 0);
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main()
{
    /* Array representation
         10
        / \
	  5   3
     / \
    2  4
    */

    int arr[] = {10, 5, 3, 2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    deleteRoot(arr, n);
    printArray(arr, n);

    return 0;
}
