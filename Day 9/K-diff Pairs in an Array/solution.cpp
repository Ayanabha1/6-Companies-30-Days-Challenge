class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int i = 0 , j = 1 , ans = 0;
        while(j < nums.size())
        {
            if(nums[j] - nums[i] == k && i < j)
            {
                ans++;
                int a = nums[i] , b = nums[j];
                while(j < nums.size() && nums[j] == b) j++;
                while(i < j && nums[i] == a) i++;
            }
            else if(nums[j] - nums[i] > k)
            {
                i++;
            }
            else
            {
                j++;
            }
        }
        return ans;
    }
};
