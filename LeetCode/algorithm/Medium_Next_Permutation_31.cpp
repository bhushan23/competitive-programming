class Solution {
public:
    void PrintNodes(string head, vector<int> &nums) {
        cout << "\n" << head << ": ";
        for (auto i:nums) {
            cout << i << " ";
        }
        cout << "\n";
    }
    void nextPermutation(vector<int>& nums) {
        int i;
        int size = nums.size();
        int j;
        for (i = size - 2; i >= 0; --i) {
            if (nums[i+1] > nums[i])
                break;
        }
        if (i >= 0) {
            for (j = i+1; j < nums.size(); ++j) {
                if (nums[j] <= nums[i]) {
                    break;
                }
            }
            j--;
            swap(nums[i], nums[j]);
        }
        sort(nums.begin() + i + 1, nums.end());
    }
};
