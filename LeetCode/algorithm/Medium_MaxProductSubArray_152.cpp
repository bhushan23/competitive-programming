class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int base = nums[0];
        int maxN, minN;

        maxN = minN = base;

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < 0) {
                swap(maxN, minN);
            }

            maxN = max(nums[i], maxN*nums[i]);
            minN = min(nums[i], minN*nums[i]);
            base = max(base, max(maxN, minN));
        }
        return base;
    }
};
