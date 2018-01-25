class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> kMap;

        int sum = 0;
        int count = 0;
        for (auto each : nums) {
            sum += each;
            if (sum == k)
                count++;
            if (kMap.find(sum-k) != kMap.end())
                count += kMap[sum-k];
            kMap[sum]++;
        }
        return count;
    }
};
