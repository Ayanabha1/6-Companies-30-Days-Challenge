class Solution {
public:

    vector<int> drow = {-1,0,1,0} , dcol = {0,-1,0,1};

    void dfs(int i , int j , vector<vector<int>> &grid , vector<vector<int>> &vis)
    {
        vis[i][j] = 1;
        int m = grid.size() , n = grid[0].size();
        for(int k = 0 ; k < 4 ; k++)
        {
            int nrow = i + drow[k] , ncol = j + dcol[k];
            if(nrow < 0 || nrow >= m || ncol < 0 || ncol >= n || grid[nrow][ncol] == 0 || vis[nrow][ncol] == 1)
            {
                continue;
            }
            dfs(nrow,ncol,grid,vis);
        }
    }


    int countIslands(vector<vector<int>> &grid)
    {
        int m = grid.size() , n = grid[0].size() , islands = 0;
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i = 0 ; i < m ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                if(grid[i][j] == 1 && vis[i][j] == 0)
                {
                    islands++;
                    dfs(i,j,grid,vis);
                }
            }
        }
        return islands;
    }

    int minDays(vector<vector<int>>& grid) {
        int islands = countIslands(grid);        
        if(islands == 0 || islands > 1)
        {
            return 0;
        }
        // check for day 1
        int m = grid.size() , n = grid[0].size();
        for(int i = 0 ; i < m ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                if(grid[i][j] == 0)
                {
                    continue;
                }
                grid[i][j] = 0;
                int islands = countIslands(grid);
                grid[i][j] = 1;
                if(islands > 1 || islands == 0)
                {
                    return 1;
                }
            }
        }
        return 2;
    }
};
