class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        if (nums.size() == 0)
            return {};
        sort(nums.begin(), nums.end());
        vector<int> maj;
        int count = 1;
        int len = nums.size();
        for (int i = 0; i < len-1; ++i) {
            if (nums[i] == nums[i+1])
                count++;
            else {
                if (count > len/3) {
                    maj.push_back(nums[i]);
                }
                count = 1;
            }
        }
        if (count > len/3) {
            maj.push_back(nums[len-1]);
        }
        return maj;
    }
};
