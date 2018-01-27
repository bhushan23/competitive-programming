class Solution {
public:

    void recSwap(vector<int> &nums, int i) {
        if (i < nums.size() && i+1 != nums[i] && nums[i] > 0 && nums[i]-1 < nums.size() && nums[i] != nums[nums[i]-1]) {
            swap(nums[i], nums[nums[i]-1]);
            recSwap(nums, i);
        }

    }
    int firstMissingPositive(vector<int>& nums) {

        for (int i = 0; i < nums.size(); ++i) {
            if (i < nums.size() && i+1 != nums[i] && nums[i] > 0) {
                recSwap(nums, i);
            }
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (i+1 != nums[i])
                return i+1;
        }
        return nums.size()+1;
    }
};
