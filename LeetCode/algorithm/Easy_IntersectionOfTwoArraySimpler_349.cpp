class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> temp(nums1.begin(), nums1.end());
        vector<int> out;

        for (auto each : nums2) {
            if (temp.find(each) != temp.end()) {
                temp.erase(each);
                out.push_back(each);
            }
        }
        return out;
    }
};
