class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int lo, hi;
        lo = 0;
        for (hi = 0; hi < nums.size(); ++hi) {
            if (nums[hi] != 0) {
                nums[lo++] = nums[hi];
            }
        }
        while (lo < nums.size()) {
            nums[lo++] = 0;
        }
    }
};
