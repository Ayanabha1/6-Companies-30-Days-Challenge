class Solution
{
public:
    void wiggleSort(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int idx = n - 1;
        vector<int> temp(n);
        for (int i = 1; i < n; i += 2)
        {
            temp[i] = nums[idx--];
        }

        for (int i = 0; i < n; i += 2)
        {
            temp[i] = nums[idx--];
        }
        nums = temp;
    }
};
