class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int eMax = -1;
        int sMax = -1;
        int mIndex = -1;
        
        if (nums.size() == 0)
            return -1;
        
        eMax = nums[0];
        mIndex = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (eMax < nums[i]) {
                sMax = eMax;
                mIndex = i;
                eMax = nums[i];
            } else if (sMax < nums[i]) {
                sMax = nums[i];
            }
        }
        if (eMax >= 2*sMax) {
            return mIndex;
        }
        return -1;
    }
};
