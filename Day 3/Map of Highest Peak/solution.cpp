class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& arr) {
        int m = arr.size(), n = arr[0].size();
        vector<vector<int>> heights(m, vector<int>(n, INT_MAX));
        queue<vector<int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (arr[i][j] == 1) {
                    heights[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        vector<int> drow = {-1, 0, 1, 0}, dcol = {0, -1, 0, 1};
        while (!q.empty()) {
            int i = q.front()[0], j = q.front()[1];
            q.pop();
            for (int k = 0; k < 4; k++) {
                int nrow = i + drow[k], ncol = j + dcol[k];
                if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && heights[nrow][ncol] > 1 + heights[i][j]) {
                    heights[nrow][ncol] = 1 + heights[i][j];
                    q.push({nrow, ncol});
                }
            }
        }
        return heights;
    }
};
