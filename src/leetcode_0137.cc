class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(auto n: nums) {
            if(mp.find(n) == mp.end()) mp[n] = 0;
            mp[n] ++;
        }
        int res = nums[0];
        for(auto it = mp.begin(); it != mp.end(); it ++) {
            if(it -> second == 1) {
                res = it -> first;
                break;
            }
        }
        return res;
    }
};