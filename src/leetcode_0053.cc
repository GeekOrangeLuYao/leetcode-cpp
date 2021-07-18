class Solution {
public:
    int dp[30000 + 10];
    int maxSubArray(vector<int>& nums) {
        memset(dp, 0, sizeof(int) * (nums.size() + 5));
        dp[0] = nums[0];
        int res = dp[0];
        for(int i = 1; i < nums.size(); i ++) {
            if(dp[i - 1] < 0) dp[i] = nums[i];
            else dp[i] = dp[i - 1] + nums[i];
            res = max(res, dp[i]);
        }
        return res;
    }
};