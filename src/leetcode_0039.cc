class Solution {
public:
    vector<vector<int> > res;

    void dfs(int sum, int index, vector<int> cur, vector<int> candidates, int target) {
        if(sum == target) {
            res.push_back(cur);
            return ;
        }
        if(sum + candidates[index] > target) return ;
        for(int i = index; i < candidates.size(); i ++) {
            int c = candidates[i];
            if(sum + c > target) return ;
            cur.push_back(c);
            dfs(sum + c, i, cur, candidates, target);
            cur.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        res.clear();
        vector<int> cur;
        dfs(0, 0, cur, candidates, target);
        return res;
    }
};