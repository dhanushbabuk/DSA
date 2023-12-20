#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    vector<long long> nextLargerElement(vector<long long> arr, int n)
    {
        stack<long long int> st;
        vector<long long int> nge(n); // Initialize vector with size n and default value -1

        for (long long int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && st.top() <= arr[i])
                st.pop();

            if (!st.empty())
                nge[i] = st.top();
            else
                nge[i] = -1;

            st.push(arr[i]);
        }
        return nge;
    }
};

// circular next greatest number
class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int n = nums.size();
        stack<int> st;
        vector<int> v(n);
        int i;
        for (i = 2 * n - 1; i >= 0; i--)
        {
            while (!st.empty() && st.top() <= nums[i % n])
                st.pop();

            if (st.empty() == true)
                v[i % n] = -1;
            else
                v[i % n] = st.top();

            st.push(nums[i % n]);
        }
        return v;
    }
};