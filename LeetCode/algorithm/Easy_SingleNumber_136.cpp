class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (auto each : nums) {
            ans = ans ^ each;
        }
        return ans;
    }
};
