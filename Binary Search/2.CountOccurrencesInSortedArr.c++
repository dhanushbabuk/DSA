// Count Occurrences in Sorted Array
// medium problem coding ninjas
int count(vector<int> &nums, int n, int target)
{
    int left = 0;
    int right = nums.size() - 1;
    int firstOccurrence = -1;
    int lastOccurrence = -1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (target == nums[mid])
        {
            firstOccurrence = mid;
            right = mid - 1;
        }
        else if (target > nums[mid])
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    left = 0;
    right = nums.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (target == nums[mid])
        {
            lastOccurrence = mid;
            left = mid + 1;
        }
        else if (target > nums[mid])
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    if (firstOccurrence == -1 || lastOccurrence == -1)
    {
        // Target element not found in the array
        return 0;
    }
    else
    {
        return lastOccurrence - firstOccurrence + 1;
    }
}
