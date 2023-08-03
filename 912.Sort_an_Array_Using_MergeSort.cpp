// Q: // Q: https://leetcode.com/problems/sort-an-array/description/
class Solution
{
public:
    void merge(vector<int> &nums, int l, int m, int r)
    {
        int leftSize = m - l + 1, rightSize = r - m;
        int *leftArr = new int[leftSize + 1];
        int *rightArr = new int[rightSize + 1];
        for (int i = 0; i < leftSize; i++)
            leftArr[i] = nums[l + i];
        for (int i = 0; i < rightSize; i++)
            rightArr[i] = nums[m + 1 + i];
        leftArr[leftSize] = rightArr[rightSize] = INT_MAX;
        int lp = 0, rp = 0;

        for (int i = l; i <= r; i++)
        {
            if (leftArr[lp] <= rightArr[rp])
                nums[i] = leftArr[lp++];
            else
                nums[i] = rightArr[rp++];
        }
        delete[] leftArr;
        delete[] rightArr;
    }
    void mergesort(vector<int> &nums, int l, int r)
    {
        if (l >= r)
            return;
        int mid = (l + r) / 2;
        mergesort(nums, l, mid);
        mergesort(nums, mid + 1, r);
        merge(nums, l, mid, r);
    }
    vector<int> sortArray(vector<int> &nums)
    {
        mergesort(nums, 0, nums.size() - 1);
        return nums;
    }
};
