#include <bits/stdc++.h>
using namespace std;

// Function to find Majority element in an array - TC -> O(nlogn)
int majorityElement(int arr[], int n)
{
    // sort the array in O(nlogn)
    sort(arr, arr + n);

    int count = 0, max_ele = -1, temp = arr[0], element, flag = 0;

    for (int i = 0; i < n; i++)
    {
        // increases the count if the same element occurs otherwise starts counting new element
        if (temp == arr[i])
        {
            count++;
        }
        else
        {
            count = 1;
            temp = arr[i];
        }

        /* sets maximum count and stores maximum occured element so far if maximum count becomes greater than n/2
        it breaks out setting the flag */
        if (max_ele < count)
        {
            max_ele = count;
            element = arr[i];

            if (max_ele > (n / 2))
            {
                flag = 1;
                break;
            }
        }
    }

    // returns maximum occured element if there is no such element, returns -1
    return (flag == 1 ? element : -1);
}

// Driver code
int main()
{
    int arr[] = {1, 1, 2, 1, 3, 5, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Majority Element is: " << majorityElement(arr, n);

    return 0;
}
