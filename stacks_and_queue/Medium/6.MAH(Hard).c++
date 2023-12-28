//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// Your code here
class Solution
{
public:
    // Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        vector<long long int> left(n);
        vector<long long int> right(n);

        stack<long long int> s;

        for (long long int i = 0; i < n; i++)
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
        for (long long int i = n - 1; i >= 0; i--)
        {
            while (!s.empty() && arr[s.top()] >= arr[i])
                s.pop();

            if (s.empty())
                right[i] = n - i;
            else
                right[i] = s.top() - i;

            s.push(i);
        }

        vector<long long int> width(n), area(n);

        for (long long i = 0; i < n; i++)
        {
            width[i] = left[i] + right[i] - 1;
            area[i] = width[i] * arr[i];
        }

        long long int maxm = area[0];
        for (long long i = 1; i < n; i++)
        {
            if (area[i] > maxm)
                maxm = area[i];
        }
        // or
        //   long long int maxm = *max_element(area.begin(), area.end());

        return maxm;
    }
};
