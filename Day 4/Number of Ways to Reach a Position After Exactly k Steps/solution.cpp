class Solution {
public:
    int mod = 1E9 + 7;
    int solve(int pos, int endPos, int k, vector<vector<int>>& dp) {
        if (pos == endPos && k == 0) {
            return 1;
        }
        if (k <= 0) {
            return 0;
        }
        if (dp[pos + 1000][k] != -1) {
            return dp[pos + 1000][k];
        }

        // Go right
        int right = solve(pos + 1, endPos, k - 1, dp) % mod;

        // Go left
        int left = solve(pos - 1, endPos, k - 1, dp) % mod;
        return dp[pos + 1000][k] = (left + right) % mod;
    }

    int numberOfWays(int startPos, int endPos, int k) {
        vector<vector<int>> dp(3001, vector<int>(k + 1, -1));
        return solve(startPos, endPos, k, dp);
    }
};

/*
    Just a simple dp problem
    Only catch is that pos can be negative
    -999 <= pos <= 2000
    How to handle it in dp?
    => Simple just take the maximum state size of position as 3001
       Now if pos = -999, just put it in dp[-999 + 1000][k]
       On the other hand if pos = 2000, put it in dp[2000 + 1000]
       So basically whatever the position is, add 1000 to it and then store in dp

    dp[3001][k]
    put everything in dp[pos + 1000][k]
*/

