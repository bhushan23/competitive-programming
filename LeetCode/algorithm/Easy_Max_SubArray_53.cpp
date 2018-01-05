class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans;
        if (nums.size() > 0) {
            ans = nums[0];
        } else {
            return 0;
        }
        for (int i = 1; i < nums.size(); ++i) {
            nums[i] = max(nums[i], nums[i-1]+nums[i]);
            ans = max(ans, nums[i]);
        }
        return ans;
    }
};
