// 33. Search in Rotated Sorted Array
//  leetcode medium problem

// first the index of minimum element is found and it is used as a start index and n-1 as end index to find the target element which is part of right array now for the left array  0 is used as a start index and index - 1 is used as end index to find the target element any one of the binary search will return the index other will return -1 if both are  -1 then target is  not found.
class Solution
{
public:
    int indexOfMinElement(vector<int> &nums, int n)
    {
        int start = 0;
        int end = n - 1;

        while (start <= end)
        {
            //  Handling the base case when the array is not rotated
            if (nums[start] < nums[end])
                return start; // return the first element

            int mid = start + (end - start) / 2;
            int next = (mid + 1) % n;
            int prev = (mid - 1 + n) % n;

            if (nums[mid] <= nums[prev] && nums[mid] <= nums[next])
                return mid;

            if (nums[start] <= nums[mid])
                start = mid + 1;
            else if (nums[mid] <= nums[end])
                end = mid - 1;
        }

        return start;
        // or 0 or -1
    }

    int binarySearch(vector<int> &nums, int target, int start, int end)
    {
        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                start = mid + 1;
            else
                end = mid - 1;
        }
        return -1;
    }

    int search(vector<int> &nums, int target)
    {
        int n = nums.size();
        int index = indexOfMinElement(nums, n);

        int leftArray = binarySearch(nums, target, 0, index - 1);
        int rightArray = binarySearch(nums, target, index, n - 1);

        if (leftArray == -1)
            return rightArray;
        else
            return leftArray;

        return -1;
    }
};