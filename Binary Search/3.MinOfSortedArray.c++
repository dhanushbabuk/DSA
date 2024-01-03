// medium leetcode 153. Find Minimum in Rotated Sorted Array
// according to my observations ---if asked...the Number of Times a Sorted array is Rotated. then return the minimum element index---if asked ...the minimum element return element

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int n = nums.size();
        int start = 0;
        int end = n - 1;

        while (start <= end)
        {

            if (nums[start] < nums[end])
                return nums[start];

            int mid = start + (end - start) / 2;
            int next = (mid + 1) % n;
            int prev = (mid - 1 + n) % n;

            if (nums[mid] <= nums[prev] && nums[mid] <= nums[next])
                return nums[mid];

            if (nums[start] <= nums[mid])
                start = mid + 1;
            else if (nums[mid] <= nums[end])
                end = mid - 1;
        }

        return nums[start];
        // or 0 or -1
    }
};
