class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int d = 0;
        for(auto n: nums) d ^= n;
        return d;
    }
};