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
    
    void update(int i, int val) {
        int diff;
        if (i == 0) {
            diff = val - sum[i];
            sum[i] = val;
            
        } else {
            diff = val - (sum[i] - sum[i-1]);
            sum[i] = sum[i-1] + val;
        }
        for (int j = i+1; j < sum.size(); ++j) {
            sum[j] += diff;
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
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */
