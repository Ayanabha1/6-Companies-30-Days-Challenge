class Solution {
    static bool comp(vector<int> &a , vector<int> &b)
    {
        if(a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    }

    public:
    int maxEnvelopes(vector<vector<int>>& env) {
        sort(env.begin(),env.end(),comp);
        vector<int> lisArr;
        for(int i = 0 ; i < env.size() ; i++)
        {
            int curr = env[i][1];
            int targetIdx = lower_bound(lisArr.begin(),lisArr.end(),curr) - lisArr.begin();
            if(targetIdx >= lisArr.size())
            {
                lisArr.push_back(curr);
            }
            else
            {
                lisArr[targetIdx] = curr;
            }
        }
        return lisArr.size();
    }
};
