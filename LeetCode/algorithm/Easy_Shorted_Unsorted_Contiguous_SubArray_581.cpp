class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int start = 0;
        int end = nums.size()-1;
        for (; start < nums.size()-1; ++start) {
            if (nums[start] > nums[start+1]) {
                break;
            }
        }
        if (start == nums.size()-1)
            return 0;
        
        for (; end >= 1; --end) {
            if (nums[end] < nums[end-1]) {
                break;
            }
        }
        
        int minN = INT_MAX;
        int maxN = INT_MIN;
        // cout << start << " " << end << endl;
        for (int i = start; i <= end; ++i) {
            minN = min(minN, nums[i]);
            maxN = max(maxN, nums[i]);
        }
        
        while (start >= 1 && nums[start-1] > minN) 
            start--;
        
        while (end < nums.size()-1 && nums[end+1] < maxN) 
            end++;
        // cout << start << " " << end << endl;
        return end-start+1;        
    }
};
