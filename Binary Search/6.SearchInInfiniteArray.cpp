#include <bits/stdc++.h>

int BinarySearch(vector<int> array, int start, int end, int key)
{
    while (start <= end)
    {
        int mid - start + (end - start) / 2;
        if (array[mid] == key)
            return mid;
        else if (key > array[mid])
            start = mid + 1;
        else
            end = mid - 1;
    }
    return -1;
}

vector<int> SearchInfiniteArray(vector<int> array, int n, int k)
{
    // Write your code here.

    int start = 0;
    int end = 1;
    while (k > end)
    {
        strat = end;
        end = end * 2;
    }

    int res = BinarySearch(array, 0, n - 1, k);

    return res;
}