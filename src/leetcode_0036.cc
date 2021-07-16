class Solution {
public:
    int shu[10], heng[10], ge[10];
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9;i ++) {
            for(int j = 0; j < 9;j ++) {
                if(board[i][j] == '.') continue;
                int cur = (int)(board[i][j] - '0');
                // cout << cur << endl;
                if(shu[i] & (1 << cur)) return false;
                if(heng[j] & (1 << cur)) return false;
                if(ge[(i / 3) * 3 + (j / 3) ] & (1 << cur)) return false;
                // cout << i << " " << j << " " << (i / 3) * 3 + (j / 3) << endl;
                shu[i] |= (1 << cur);
                heng[j] |= (1 << cur);
                ge[(i / 3) * 3 + (j / 3)] |= (1 << cur);
            }
        }
        return true;
    }
};