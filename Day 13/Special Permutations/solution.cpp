class Solution {
public:
    int mod = 1E9 + 7;
    int solve(int prev , int size , int &visited , vector<int> nums ,vector<vector<int>> &dp)
    {
        if(size == 0)
        {
            return 1;
        }
        if(dp[prev+1][visited] != -1)
        {
            return dp[prev+1][visited];
        }
        int ans = 0;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            if((visited & (1 << i)) || prev == i) continue;
            if(prev == -1 || nums[i] % nums[prev] == 0 || nums[prev] % nums[i] == 0)
            {
                visited |= (1 << i);
                ans += solve(i,size-1,visited,nums,dp);
                ans %= mod;
                visited ^= (1 << i);
            }
        }
        return dp[prev+1][visited] = ans;
    }

    int specialPerm(vector<int>& nums) {
        int mask = 0 , ans = 0;
        vector<vector<int>> dp(nums.size() + 1 , vector<int> (1 << 14 , -1));
        return solve(-1,nums.size(),mask,nums,dp);
    }
};
