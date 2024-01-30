class Solution {
public:

    int checkValidSubtree(int node , int &mask , int &maxDist , unordered_map<int,vector<int>> &edges)
    {
        // mark visited (make the bit 0)
        if(!(mask & (1 << (node-1)))) return 0;
        mask = mask ^ (1 << (node-1));
        int fmax = 0 , smax = 0;

        for(auto it: edges[node])
        {
            int val = checkValidSubtree(it,mask,maxDist,edges);
            if(val >= fmax)
            {
                smax = fmax;
                fmax = val;
            }
            else if(val > smax)
            {
                smax = val;
            }
        }
        maxDist = max(maxDist,fmax+smax);
        return fmax + 1;
    }

    int getMaxDist(int mask , unordered_map<int,vector<int>> &edges)
    {
        // get a source
        int source = -1;
        for(int i = 0 ; i <= 15 ; i++)
        {
            if(mask & (1 << i))
            {
                source = i + 1;
                break;
            }
        }
        int subtreeCities = 0;
        int maxDist = 0;
        checkValidSubtree(source,mask,maxDist,edges);
        if(mask == 0 && maxDist > 0)
        {
            return maxDist;
        }
        return -1;
    }

    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        vector<int> ans(n-1,0);
        unordered_map<int,vector<int>> adj;
        for(auto it: edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        for(int i = 1 ; i < (1<<n) ; i++)   
        {
            if(((i - 1) & i) == 0) continue;
            int mask = i;
            int maxDistInSubtree = getMaxDist(mask,adj);
            if(maxDistInSubtree != -1 && maxDistInSubtree < n)
            {
                ans[maxDistInSubtree-1]++;
            }
        }
        return ans;
    }
};
