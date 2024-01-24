class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        for(auto it : queries)
        {
            vector<pair<string,int>> pairs;
            for(int i = 0 ; i < nums.size() ; i++)
            {
                string trimmed_num = nums[i].substr(nums[i].size() - it[1]);
                pairs.push_back({trimmed_num,i});
            }
            sort(pairs.begin(),pairs.end());
            ans.push_back(pairs[it[0] - 1].second);
        }
        return ans;
    }
};
