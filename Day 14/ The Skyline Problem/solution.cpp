class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& arr) {
        vector<vector<int>> h,ans;
        multiset<int> set{0};
        for(int i = 0 ; i < arr.size() ; i++)
        {
            h.push_back({arr[i][0],arr[i][2] * -1});
            h.push_back({arr[i][1],arr[i][2]});
        }
        sort(h.begin(),h.end());

        int prevHeight = 0;
        for(int i = 0 ; i < h.size() ; i++)
        {
            if(h[i][1] < 0)
            {
                // starting point
                set.insert(h[i][1] * -1);
            }
            else
            {
                // ending point
                set.erase(set.find(h[i][1]));
            }

            auto top = *set.rbegin();
            if(prevHeight != top)
            {
                prevHeight = top;
                ans.push_back({h[i][0],top});
            }
        }
        return ans;
    }
};
