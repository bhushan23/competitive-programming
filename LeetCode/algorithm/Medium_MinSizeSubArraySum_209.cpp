class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.size() <= 0)
            return 0;
        int low = 0;
        int hi = 0;
        int minD = nums.size()+2;
        int sum = nums[0];
        while (low <= hi && hi < nums.size()) {
            // cout << sum << " " << hi << " " << low << endl;
            if (sum >= s) {
                if (minD > hi-low+1) {
                        minD = hi-low+1;
                }
                sum -= nums[low++];
            } else if (sum < s) {
                if (hi < nums.size()-1)
                    sum += nums[++hi];
                else
                    sum -= nums[low++];
            }
        }
        if (minD == nums.size()+2)
            return 0;
        return minD;
    }
};
