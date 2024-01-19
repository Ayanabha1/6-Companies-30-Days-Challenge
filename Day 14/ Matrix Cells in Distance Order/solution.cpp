class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int m, int n, int x, int y) {
        vector<vector<int>> dists , ans;
        for(int i = 0 ; i < m ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                int dist = abs(i-x) + abs(j-y);
                dists.push_back({dist,i,j});
            }
        }
        sort(dists.begin(),dists.end());
        for(auto it : dists)
        {
            ans.push_back({it[1],it[2]});
        }
        return ans;
    }
};

