class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> out(2, -1);
        if (nums.size() == 0) {
            return out;
        }
        vector<int>::iterator lit = lower_bound(nums.begin(), nums.end(), target);
        if (lit != nums.end() && *lit == target) {
            vector<int>::iterator uit = upper_bound(nums.begin(), nums.end(), target);
            out[0] = lit - nums.begin();
            out[1] = uit - nums.begin()-1;
        }
        return out;
    }
};
