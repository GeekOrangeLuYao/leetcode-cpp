class Solution {
public:
    int dp[210][210];
    int minimumTotal(vector<vector<int>>& triangle) {
        for(vector<int> cur: triangle) {
            if(cur.size() == 1) dp[1][1] = cur[0];
            else {
                int step = cur.size();
                dp[step][1] = dp[step - 1][1] + cur[0];
                dp[step][step] = dp[step - 1][step - 1] + cur[step - 1];
                for(int i = 2; i < step; i ++) {
                    dp[step][i] = min(dp[step - 1][i - 1], dp[step - 1][i]) + cur[i - 1];
                }
            }
        }
        int tot = triangle.size();
        int minx = dp[tot][1];
        for(int i = 2; i <= tot;i ++) {
            minx = min(minx, dp[tot][i]);
        }
        return minx;
    }
};