class Solution {
public:

    bool solve(int i , string s , unordered_set<string> &set , vector<int> &dp)
    {
        if(i == s.size() - 1)
        {
            string temp = "";
            temp += s[i];
            if(set.count(temp))
            {
                return true;
            }
            return false;
        }

        if(dp[i] != -1) return dp[i];

        for(int j = i ; j < s.size() ; j++)
        {
            string temp = s.substr(i,j-i+1);
            if(j == s.size() - 1)
            {
                return set.count(temp);
            }
            if(set.count(temp))
            {
                if(dp[i] = solve(j+1,s,set,dp))
                {
                    return true;
                }
            }
        }
        return dp[i] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> set;
        vector<int> dp(s.size(),-1);
        for(auto x : wordDict) set.insert(x);
        return solve(0,s,set,dp);
    }
};
