class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size() , index = -1 , maxLen = 0;
        vector<int> dp(n,1) , prev(n,-1) , ans;
        sort(nums.begin(),nums.end());
        
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = i - 1 ; j >= 0 ; j--)
            {
                if(nums[i] % nums[j] != 0) continue;
                if(dp[j] + 1 > dp[i])
                {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
            if(dp[i] > maxLen)
            {
                maxLen = dp[i];
                index = i; 
            }
        }

        while(index != -1)
        {
            ans.push_back(nums[index]);
            index = prev[index];
        }
        return ans;
    }
};
