class Solution {
public:
    int dp[10000 + 10];

    int dfs(int n) {
        if(dp[n] != -1) return dp[n];
        if(n == 1 || n == 2) return dp[n] = n;
        else return dp[n] = dfs(n - 1) + dfs(n - 2);
    }

    int climbStairs(int n) {
        memset(dp, -1, sizeof(int) * (n + 3));
        return dfs(n);
    }
};