#include <bits/stdc++.h>

int MAH(vector<int> &arr)
{
    int n = arr.size();
    vector<int> left(n);
    vector<int> right(n);

    stack<int> s;

    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && arr[s.top()] >= arr[i])
            s.pop();

        if (s.empty())
            left[i] = i + 1;
        else
            left[i] = i - s.top();

        s.push(i);
    }

    while (!s.empty())
    {
        s.pop();
    }

    // nsr
    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && arr[s.top()] >= arr[i])
            s.pop();

        if (s.empty())
            right[i] = n - i;
        else
            right[i] = s.top() - i;

        s.push(i);
    }

    vector<int> width(n), area(n);
    int maxm = 0;
    for (int i = 0; i < n; i++)
    {
        width[i] = left[i] + right[i] - 1;
        area[i] = width[i] * arr[i];
        maxm = max(area[i], maxm);
    }

    return maxm;
}
int getLargestRectangle(int **arr, int n, int m)
{
    // Write your code here
    vector<int> v;

    for (int j = 0; j < m; j++)
    {
        v.push_back(arr[0][j]);
    }
    int mx = MAH(v);

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 0)
                v[j] = 0;
            else
                v[j] = v[j] + arr[i][j];
        }
        mx = max(mx, MAH(v));
    }

    return mx;
}