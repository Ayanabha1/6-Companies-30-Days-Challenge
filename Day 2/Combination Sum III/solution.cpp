class Solution {
public:

    void solve(int i , int n , int k , vector<int> &temp , vector<vector<int>> &ans)
    {
        if(n == 0 && k == 0)
        {
            ans.push_back(temp);
            return;
        }
        if(n <= 0 || k <= 0 || i == 10)
        {
            return;
        }
        // take
        temp.push_back(i);
        solve(i+1,n-i,k-1,temp,ans);
        temp.pop_back();

        // don't take
        solve(i+1,n,k,temp,ans);

    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(1,n,k,temp,ans);
        return ans;
    }
};
