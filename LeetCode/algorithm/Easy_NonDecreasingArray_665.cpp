class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int nonDecreasing = 0;
        if (nums.size() < 2)
            return true;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i-1] > nums[i]) {
                
                if (i > 1 && nums[i-2] > nums[i]) {
                    nums[i] = nums[i-1];
                    nonDecreasing++;
                } else if (i > 1 && nums[i-2] < nums[i]) {
                    nums[i-1] = nums[i-2];
                    nonDecreasing++;
                } else if (nums[i-1] > nums[i]) {
                    nums[i-1] = nums[i];
                    nonDecreasing++;
                }
                if (nonDecreasing > 1)
                    return false;
                
            }
        }
        return (nonDecreasing <= 1);
    }
};
