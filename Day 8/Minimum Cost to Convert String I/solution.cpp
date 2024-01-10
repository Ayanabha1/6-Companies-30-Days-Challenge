class Solution {
public:
    // Coded by Ayanabha Misra
    long long getMinCost(char node , char target , unordered_map<char,vector<pair<char,int>>> &edges)
    {
        long long ans = LONG_MAX;
        vector<long long> vis(26,LONG_MAX);
        queue<pair<char,long long>> q;
        vis[node - 'a'] = 0;
        q.push({node,0});
        while(q.size())
        {
            auto [node , cost] = q.front();
            q.pop();
            for(auto [n,c] : edges[node])
            {
                if(cost + c < vis[n-'a'])
                {
                    q.push({n,cost + c});
                    vis[n - 'a'] = cost + c;
                    if(n == target) ans = min(ans , cost + c); 
                }
            }
        }
        return (ans == LONG_MAX ? -1 : ans);
    }
    
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        unordered_map<char,vector<pair<char,int>>> edges;
        unordered_map<long long ,long long> dp;
        long long ans = 0;
        for(int i = 0 ; i < original.size() ; i++)
        {
            edges[original[i]].push_back({changed[i],cost[i]});
        }
        
        for(int i = 0 ; i < source.size() ; i++)
        {
            if(source[i] == target[i]) continue;
            long long node_hash = (source[i] - 'a') * 100 + (target[i] - 'a');
            if(dp.find(node_hash) != dp.end())
            {
                ans += dp[node_hash];
            }
            else
            {
                int temp = getMinCost(source[i],target[i],edges);
                if(temp == -1)
                {
                    return -1;
                }
                ans += temp;
                dp[node_hash] = temp;
            }
        }
        return ans;
    }
};
