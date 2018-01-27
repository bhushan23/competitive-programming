class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int ans = 0;
        unordered_map<int, bool> tMap;
        vector<int> ar(2, 0);
        for (auto each : nums) {
            ans = ans ^ each;
        }

        for (auto each : nums) {
            if (tMap.find(each) != tMap.end()) {
                ar[0] = each;
                ar[1] = each ^ ans;
            }
            tMap[each^ans] = true;
        }
        return ar;
    }
};
