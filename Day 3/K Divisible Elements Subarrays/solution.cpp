class Solution {
    long mod = (LONG_MAX - 200) / 201;
    long base = 201;
public:

    int countDistinct(vector<int>& nums, int k, int p) {
        unordered_set<int> set;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            long hash = 0;
            for(int j = i , cnt = 0 ; j < nums.size() ; j++)
            {
                if(cnt == k && nums[j] % p == 0) break;
                if(nums[j] % p == 0) cnt++;
                hash = (hash * base + nums[j]) % mod;
                set.insert(hash);
            }
        }
        return set.size();
    }
};
