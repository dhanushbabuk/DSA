
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to calculate the span of stockâ€™s price for all n days.
    vector<int> calculateSpan(int price[], int n)
    {
        stack<pair<int, int>> s;
        vector<int> v(n);
        // Your code here
        for (int i = 0; i < n; i++)
        {
            while (!s.empty() && s.top().first < price[i])
                s.pop();

            if (s.empty())
            {
                v[i] = -1;
            }
            else
            {
                v[i] = s.top().second;
            }

            s.push({price[i], i});
        }

        for (int i = 0; i < v.size(); i++)
            v[i] = i - v[i];

        return v;
    }
};

// 2.code

// code without pairs that is with direct index

vector<int> findStockSpans(vector<int> &prices)
{
    // Write your code here.
    int n = prices.size();

    vector<int> v(n);

    stack<int> s;

    for (int i = 0; i < n; i++)
    {

        while (!s.empty() && prices[s.top()] < prices[i])
            s.pop();

        if (s.empty())
            v[i] = i + 1; // no NGL available i.e, -1
        else
            v[i] = i - s.top();

        s.push(i);
    }

    return v;
}