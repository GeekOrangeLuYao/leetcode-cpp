class Solution {
public:
    int dp[105][105];
    bool vis[105][105];
    int dx[2] = {-1, 0};
    int dy[2] = {0, -1};
    bool isok(int x, int y, int m, int n) {
        return 1 <= x && x <= m && 1 <= y && y <= n;
    }
    int dfs(int m, int n, int M, int N) {
        if(dp[m][n] != -1) return dp[m][n];
        if(m == 1 && n == 1) return dp[m][n] = 1;
        int res = 0;
        for(int k = 0; k < 2;k ++) {
            int mm = m + dx[k];
            int nn = n + dy[k];
            if(!isok(mm, nn, M, N)) continue;
            if(vis[mm][nn]) continue;
            res += dfs(mm, nn, M, N);
        }
        return dp[m][n] = res;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        memset(dp, -1, sizeof dp);
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        memset(vis, false, sizeof vis);
        for(int i = 0; i < m; i ++){
            for(int j = 0; j < n; j ++) {
                if(obstacleGrid[i][j] == 1) vis[i + 1][j + 1] = true;
            }
        }
        if(vis[m][n]) return 0;
        int res = dfs(m, n, m, n);
        return res;
    }
};