class Solution {
public:
    double myPow(double x, int n) {
        double res = 1.0;
        long long nn = (long long)n;
        int flag = 1;
        if(nn < 0) {
            flag = -1;
            nn = -nn;
        }
        while(nn) {
            if(nn & 1) res *= x;
            x = x * x;
            nn >>= 1;
        }
        return flag == 1 ? res : 1.0 / res;
    }
};