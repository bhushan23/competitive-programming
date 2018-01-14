class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int maxCount = 0;
        for (auto each : nums) {
            if (each == 1) {
                count++;
                maxCount = max(count, maxCount);
            } else {
                count = 0;
            }
        }
        return maxCount;
    }
};
