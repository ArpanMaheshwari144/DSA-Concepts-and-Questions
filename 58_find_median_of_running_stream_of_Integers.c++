#include <bits/stdc++.h>
using namespace std;

// it is a max-heap
priority_queue<double> maxHeap;

// it is a min-heap
priority_queue<double, vector<double>, greater<double>> minHeap;

void insertNum(double num)
{
    if (maxHeap.empty() || maxHeap.top() >= num)
    {
        maxHeap.push(num);
    }
    else
    {
        minHeap.push(num);
    }

    /* either both the heaps will have equal number of elements or max-heap will have one more element than the min-heap*/
    if (maxHeap.size() > minHeap.size() + 1)
    {
        double top = maxHeap.top();
        maxHeap.pop();
        minHeap.push(top);
    }
    else if (maxHeap.size() < minHeap.size())
    {
        double top = minHeap.top();
        minHeap.pop();
        maxHeap.push(top);
    }
}

double findMedian()
{
    if (maxHeap.size() == minHeap.size())
    {
        // if we have even numbers of elements, take the average of middile two elements
        return maxHeap.top() / 2.0 + minHeap.top() / 2.0;
    }

    // beacuse max-heap will have one more element than the min-heap
    return maxHeap.top();
}

int main()
{
    insertNum(3);
    insertNum(1);
    cout << "The median is: " << findMedian() << endl;
    insertNum(5);
    cout << "The median is: " << findMedian() << endl;
    insertNum(6);
    cout << "The median is: " << findMedian() << endl;
    insertNum(2);
    cout << "The median is: " << findMedian() << endl;
    insertNum(2);
    cout << "The median is: " << findMedian() << endl;

    return 0;
}