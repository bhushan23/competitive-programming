#define LSOne(X) (X & -X)
class NumArray {
public:
    vector<int> sum;
   
    NumArray(vector<int> nums) {
        int size = nums.size();
        if (nums.size() == 0)
            return;
        
        sum.resize(size+2);
        for (int i = 0; i < size; ++i) {
            for (int k = i+1; k <= size; k+= LSOne(k)) {
                sum[k] += nums[i];
            }
        }
        
       /* for (int i = 1; i <= size; ++i) {
            cout << sum[i] << " ";
        }
        cout << endl;*/
    }
    
    void update(int i, int val) {
        int diff = val - (sumRange(i, i));
        
        //  << "DIFF " << diff << " " << sumRange(i, i) << "\n";  
        for (int k = i+1; k <= sum.size(); k+= LSOne(k)) {
            // cout << "Updating " << k << "from: " << sum[k] << " to " << sum[k]+diff << endl;
            sum[k] += diff;
        }
        /*cout << "Update complete" << endl;
          for (int i = 1; i < sum.size(); ++i) {
            cout << sum[i] << " ";
        }
        cout << endl;*/
    }
    int sumRange(int i) {
        int ans = 0;
        i++;
        for (; i > 0; i-=LSOne(i)) {
            // cout << "Adding: " << i << " " << sum[i] << endl;
            ans += sum[i];
        }
        return ans;
    }
    int sumRange(int i, int j) {
        return sumRange(j) - (i == 0 ? 0 : sumRange(i-1));
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */
