class Solution {
public:

    int searchRec(vector<int> &nums, int target, bool First, int low = 0) {
        int high = nums.size()-1;
        while (low < high) {
            int mid = (high-low)/2 + low;
            if (nums[mid] == target) {
                if (First == true) {
                    if (nums[mid] > nums[mid-1]) {
                        return mid;
                    } else {
                        high = mid-1;
                    }
                } else {
                    if (nums[mid] < nums[mid+1]) {
                        return mid;
                    } else {
                        low = mid+1;
                    }
                }
            } else if (nums[mid] > target) {
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        if (nums[low] == target)
            return low;
        return -1;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> out(2, -1);
        if (nums.size() == 0) {
            return out;
        }
        out[0] = searchRec(nums, target, true, 0);
        if (out[0] == -1)
            out[1] = -1;
        else
            out[1] = searchRec(nums, target, false, out[0]);
        return out;
    }
};
