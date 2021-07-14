class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int length = nums.size(), tot = 1;
        for(int i = 1; i < length; i ++){
            if(nums[i] != nums[tot - 1]){
                nums[tot] = nums[i];
                tot ++;
            }
        }
        return tot;
    }
};