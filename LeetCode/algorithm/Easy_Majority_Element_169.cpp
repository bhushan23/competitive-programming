class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> cMap;
        for (auto each : nums) {
            cMap[each]++;
        }
        int ans = 0;
        int count = -1;
        for (auto each : cMap) {
            if (each.second >= nums.size()/2) {
                if (count < each.second) {
                    ans = each.first;
                    count = each.second;
                }
            }
        }
        return ans;
    }
};
