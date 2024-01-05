class Solution {
public:
    int mod = 1E9 + 7;
    int solve(int pos , int endPos , int k , vector<vector<int>> &dp)
    {
        if(pos == endPos && k == 0)
        {
            return 1;
        }
        if(k <= 0)
        {
            return 0;
        }
        if(dp[pos+1000][k] != -1)
        {
            return dp[pos+1000][k];
        }

        // Go right
        int right = solve(pos + 1 , endPos , k - 1 , dp) % mod;

        // Go left
        int left = solve(pos - 1 , endPos , k - 1 , dp) % mod;
        return dp[pos+1000][k] = (left + right) % mod;
    }

    int numberOfWays(int startPos, int endPos, int k) {
        vector<vector<int>> dp(3001,vector<int>(k+1,-1));
        return solve(startPos,endPos,k,dp);
    }
};


/*
    -1000 <= pos <= 2000
    dp[3001][k]
    put everything in dp[pos + 1000]
*/
