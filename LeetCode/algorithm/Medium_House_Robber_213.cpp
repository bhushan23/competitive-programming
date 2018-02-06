class Solution {
public:
    int robbed(vector<int> &nums, int lo, int hi) {
        int sLast = nums[lo];
        int last = max(nums[lo], nums[lo+1]);
        for (int i = lo+2; i < hi; ++i) {
            int temp = max(sLast + nums[i], last);
            sLast = last;
            last = temp;
        }
        return last;
    }
    int rob(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1) {
            return nums[0];
        }

        int last = robbed(nums, 0, nums.size()-1);
        int first = robbed(nums, 1, nums.size());
        return max(last, first);
    }
};
