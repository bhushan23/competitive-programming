class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1) {
            return nums[0];
        }

        int sLast = nums[0];
        int last = max(nums[0], nums[1]);

        for (int i = 2; i < nums.size(); ++i) {
            int temp = max(sLast + nums[i], last);
            sLast = last;
            last = temp;
        }
        return last;
    }
};
