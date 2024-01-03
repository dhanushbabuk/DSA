// 33. Search in Rotated Sorted Array
//  leetcode medium problem

class Solution
{
public:
    int indexOfMinElement(vector<int> &nums, int n)
    {
        int start = 0;
        int end = nums.size() - 1;

        while (start < end)
        {
            int mid = start + (end - start) / 2;

            if (nums[mid] > nums[end])
                start = mid + 1;
            else
                end = mid;
        }
        return start;
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