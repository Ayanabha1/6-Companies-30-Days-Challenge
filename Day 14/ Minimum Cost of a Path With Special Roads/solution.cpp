

class Solution {
public:
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& sr) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        int n = sr.size() , ans = abs(start[0] - target[0]) + abs(start[1] - target[1]);
        vector<int> dist(n,1e9);
        for(int i = 0 ; i < n ; i++)
        {
            dist[i] = abs(start[0] - sr[i][0]) + abs(start[1] - sr[i][1]) + sr[i][4];
            pq.push({dist[i],i});
        }

        while(!pq.empty())
        {
            auto [currDist,i] = pq.top();
            pq.pop();
            ans = min(ans,currDist + abs(target[0] - sr[i][2]) + abs(target[1] - sr[i][3]));
            for(int j = 0 ; j < n ; j++)
            {
                int newDist = abs(sr[i][2] - sr[j][0]) + abs(sr[i][3] - sr[j][1]) + sr[j][4];
                if(currDist + newDist < dist[j])
                {
                    dist[j] = currDist + newDist;
                    pq.push({dist[j],j});
                }
            }
        }
        return ans;
    }
};
