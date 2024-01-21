class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int ans = -1e9;
        for(auto pos : right)
        {
            ans = max(ans,n-pos+1);
        }
        for(auto pos : left)
        {
            ans = max(ans,pos+1);
        }
        return ans - 1;
    }
};
