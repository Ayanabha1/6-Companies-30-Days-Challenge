class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int sum = 0 , prev = 0 , ans = INT_MIN , n = nums.size();
        for(int i = 0 ; i < n ; i++)
        {
            sum += nums[i];
            prev += (i * nums[i]);
        }
        ans = max(ans,prev);
                
        for(int i = 1 ; i < n ; i++)
        {
            prev = prev + sum - (n * nums[n - i]);
            ans = max(ans,prev);
        }
        return ans;
    }
};
