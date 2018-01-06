class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> count(nums.size(), 1);
        int ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int ct = 1;
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j])
                    count[i] = max(count[i], 1+ count[j]);
            }
            ans = max(ans, count[i]); 
        }
        return ans;
    }
};
