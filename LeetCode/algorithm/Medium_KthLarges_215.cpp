class Solution {
public:
    int kthLargestRec(vector<int> &nums, int k, int from, int to) {
        int pivot = nums[to];
        int point = from;
        
        for (int i = from; i < to; ++i) {
            if (nums[i] < pivot) {
                swap(nums[i], nums[point]);
                point++;
            }
        }
        swap(nums[to], nums[point]);
        if (point == to-k)
            return nums[point];
        else if (point < to-k) {
            return kthLargestRec(nums, k, point+1, to);
        } else {
            return kthLargestRec(nums, k-(to-point+1), from, point-1);
        }
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        return kthLargestRec(nums, k-1, 0, nums.size()-1);
    }
};
