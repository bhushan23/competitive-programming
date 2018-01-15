class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double avg = 0;
        double maxAvg;
        if (nums.size() < k)
            return 0;
        for (int i = 0; i < k; ++i) {
            avg += nums[i];
        }
        avg /= k;
        maxAvg = avg;
        for (int i = k; i < nums.size(); ++i) {
            avg = (avg*k-nums[i-k] + nums[i])/k;
            maxAvg = max(maxAvg, avg);
        }
        return maxAvg;
    }
};
