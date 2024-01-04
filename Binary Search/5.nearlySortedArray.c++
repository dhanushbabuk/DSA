#include <bits/stdc++.h>
vector<int> nearlySorted(vector<int> array, int n, int k)
{
    // Write your code here.

    int start = 0;
    int end = n - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        int prev = (mid - 1 + n) % n;
        int next = (mid + 1) % n;
        if (array[mid] == k)
            return mid;

        if (array[next] == k)
            return next;

        if (array[prev] == k)
            return prev;

        if (array[mid] >= k)
            end = mid - 2;
        else if (array[mid] <= k)
            start = mid + 2;
    }
    return -1;
}