class Solution {
public:
    bool vis1[30], vis2[30], vis3[30];
    int res = 0;
    void dfs(int step,
             int n){
        if(step >= n) {
            res ++;
            return ;
        }
        for(int i = 0; i < n; i ++) {
            if(vis1[i] || vis2[step + i] || vis3[10 + step - i]) continue;
            vis1[i] = vis2[step + i] = vis3[10 + step - i] = true;
            dfs(step + 1, n);
            vis1[i] = vis2[step + i] = vis3[10 + step - i] = false;
        }
    }

    int totalNQueens(int n) {
        memset(vis1, false, sizeof vis1);
        memset(vis2, false, sizeof vis2);
        memset(vis3, false, sizeof vis3);
        res = 0;
        dfs(0, n);
        return res;
    }
};