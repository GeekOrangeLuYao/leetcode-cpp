class Solution {
public:
    int mySqrt(int x) {
        if(x == 0) return 0;
        if(x <= 3) return 1;
        int res = (int)sqrt((double)x) - 1;
        while(res <= x / res) res ++;
        return res - 1;
    }
};