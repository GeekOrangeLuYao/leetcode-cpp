class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int tot = 1, flag = 0;
        for(int i = 1;i < nums.size(); i ++) {
            if(nums[i] == nums[tot - 1]) {
                flag ++;
            }
            else {
                flag = 0;
            }
            if(flag < 2) nums[tot ++] = nums[i];
        }
        return tot;
    }
};
