class Solution {
public:

    int solve(int i , string &str , unordered_set<string> &set , vector<int> &dp)
    {
        if(i == str.size()) return 0;
        if(dp[i] != -1) return dp[i];
        int minExtra = 1 + solve(i+1,str,set,dp);
        string word = "";
        for(int j = i ; j < str.size() ; j++)
        {
            word += str[j];
            if(set.find(word) != set.end())
            {
                int take = solve(j+1,str,set,dp);
                minExtra = min(minExtra,take);
            }
        }

        
        return dp[i] = minExtra;
    }

    int minExtraChar(string s, vector<string>& dict) {
        unordered_set<string> set;
        vector<int> dp(s.size(),-1);
        for(auto it : dict) set.insert(it);
        return solve(0,s,set,dp);
    }
};
