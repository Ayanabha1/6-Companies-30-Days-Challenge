class Solution {
public:

    static bool comp(vector<int> &a , vector<int> &b)
    {
        return a[1] < b[1];
    }

    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<vector<int>> pairs , tempAns;
        vector<int> ans;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            pairs.push_back({nums[i],i});
        }

        sort(pairs.begin(),pairs.end());

        for(int i = nums.size() - 1; i >= max(0 , (int)nums.size() - k) ; i--)
        {
            tempAns.push_back(pairs[i]);
        }
        sort(tempAns.begin() , tempAns.end() , comp);
        for(auto it: tempAns) ans.push_back(it[0]);
        
        return ans;
    }
};
