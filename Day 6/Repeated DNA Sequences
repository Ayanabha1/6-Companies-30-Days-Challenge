class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.size() < 10)
        {
            return {};
        }
        unordered_set<string> seen , res;
        vector<string> ans;
        for(int i = 0 ; i <= s.size() - 10 ; i++)
        {
            string substr = s.substr(i,10);
            if(seen.find(substr) != seen.end())
            {
                res.insert(substr);
            }
            else
            {
                seen.insert(substr);
            }
        }
        for(auto it : res)
        {
            ans.push_back(it);
        }
        return ans;
    }
};
