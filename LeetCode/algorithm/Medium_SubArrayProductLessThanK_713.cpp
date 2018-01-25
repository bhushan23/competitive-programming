class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int left = 0;
        int count = 0;
        int prod = 1;

        if (k <= 1)
            return 0;
        for (int i = 0; i < nums.size(); ++i) {
            prod *= nums[i];

            while (prod >= k && left <= i) {
                prod /= nums[left++];
            }
            count += (i-left+1);
        }
        return count;
    }
};
