class Solution
{
public:
    int searchInsert(vector<int> &a, int key)
    {
        int l = 0;
        // int key;
        int n = a.size();
        int high = n - 1;
        int mid;
        while (l <= high)
        {
            mid = (l + high) / 2;
            if (a[mid] == key)
                return mid;
            else if (a[mid] > key)
                high = mid - 1;
            else
                l = mid + 1;
        }
        return l;
    }
};