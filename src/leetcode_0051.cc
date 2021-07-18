class Solution {
public:
    bool vis1[30], vis2[30], vis3[30];
    string base_string = "";
    void dfs(vector<string> cur,
             int step,
             int n,
             vector<vector<string> > & result)
    {
        if(step >= n) {
            result.push_back(cur);
            return ;
        }
        for(int i = 0; i < n; i ++) {
            if(vis1[i] || vis2[step + i] || vis3[10 + step - i]) continue;
            vis1[i] = vis2[step + i] = vis3[10 + step - i] = true;
            string cur_string(base_string);
            cur_string[i] = 'Q';
            cur.push_back(cur_string);
            dfs(cur, step + 1, n, result);
            cur.pop_back();
            vis1[i] = vis2[step + i] = vis3[10 + step - i] = false;
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        memset(vis1, false, sizeof vis1);
        memset(vis2, false, sizeof vis2);
        memset(vis3, false, sizeof vis3);

        vector<vector<string> > res;
        vector<string> tmp;
        for(int i = 0; i < n; i ++) base_string += ".";
        dfs(tmp, 0, n, res);
        return res;
    }
};