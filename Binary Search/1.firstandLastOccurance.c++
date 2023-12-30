// meduim problem

class Solution
{

public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> v(2, -1);
        int left = 0;
        int right = nums.size() - 1;
        int mid;

        if (nums.empty())
            return v;

        while (left <= right)
        {
            mid = left + (right - left) / 2;

            if (target == nums[mid])
            {
                v[0] = mid;
                right = mid - 1;
            }
            else if (target > nums[mid])
                left = mid + 1;
            else
                right = mid - 1;
        }

        left = 0;
        right = nums.size() - 1;

        while (left <= right)
        {
            mid = left + (right - left) / 2;

            if (target == nums[mid])
            {
                v[1] = mid;
                left = mid + 1;
            }
            else if (target > nums[mid])
                left = mid + 1;
            else
                right = mid - 1;
        }

        return v;
    }
};