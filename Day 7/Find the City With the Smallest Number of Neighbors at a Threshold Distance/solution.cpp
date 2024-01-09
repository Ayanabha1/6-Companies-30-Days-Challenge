class Solution {
public:

    vector<vector<int>> getAllDistances(int n , vector<vector<int>> &edges)
    {
        vector<vector<int>> dist(n,vector<int>(n,1e9));
        for(int i = 0 ; i < edges.size() ; i++)
        {
            int u = edges[i][0] , v = edges[i][1] , cost = edges[i][2];
            dist[u][v] = cost;
            dist[v][u] = cost;
        }

        for(int k = 0 ; k < n ; k++)
        {
            for(int i = 0 ; i < n ; i++)
            {
                for(int j = 0 ; j < n ; j++)
                {
                    dist[i][i] = 0;
                    dist[j][j] = 0;
                    if( (dist[i][j] > dist[i][k] + dist[k][j]) && !(dist[i][k] + dist[k][j] >= 1e9) )
                    {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
        return dist;
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist = getAllDistances(n,edges);
        int minCities = 1e9 , ans = -1;
        for(int i = 0 ; i < n ; i++)
        {
            int cities = 0;
            for(int j = 0 ; j < n ; j++)
            {
                if(dist[i][j] <= distanceThreshold)
                {
                    cities++;
                }
            }
            if(cities < minCities || cities == minCities && i > ans)
            {
                minCities = cities;
                ans = i;
            }
        }
        return ans;
    }
};
