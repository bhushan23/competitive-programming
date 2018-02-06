class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> out(nums.size(), 0);

        out[0] = 1;
        for (int i = 1; i < nums.size(); ++i) {
            out[i] = out[i-1] * nums[i-1];
        }

        int multiplier = 1;
        for (int i = nums.size()-1; i >= 0; --i) {
            out[i] = out[i] * multiplier;
            multiplier *= nums[i];
        }
        return out;
    }
};
