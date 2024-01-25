class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        int i = 0 , ans = 0;
        for(int j = 0 ; j < nums.size() ; j++)
        {
            freq[nums[j]]++;
            while(freq[nums[j]] > k)
            {
                freq[nums[i]]--;
                i++;
            }
            ans = max(ans,j-i+1);
        }
        return ans;
    }
};
