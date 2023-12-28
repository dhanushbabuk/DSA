
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
            while (!s.empty() && s.top().first <= price[i])
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

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int i, a[n];
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution obj;
        vector<int> s = obj.calculateSpan(a, n);

        for (i = 0; i < n; i++)
        {
            cout << s[i] << " ";
        }
        cout << endl;
    }
    cout << "Press Enter to continue...";
    cin.get(); // Wait for user input

    return 0;
}
