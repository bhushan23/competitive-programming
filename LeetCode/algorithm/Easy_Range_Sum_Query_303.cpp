class NumArray {
public:
    vector<int> sum;
    NumArray(vector<int> nums) {
        sum.resize(nums.size());
        if (nums.size() == 0)
            return;
        sum[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            sum[i] = sum[i-1] + nums[i];
        }
    }
    
    int sumRange(int i, int j) {
       if (sum.size() == 0)
            return -1;
        return sum[j] - sum[i-1];    
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
