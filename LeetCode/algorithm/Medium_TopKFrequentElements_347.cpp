class Solution {
public:
    class compare {
        public:
        bool operator()(const pair<int, int> &a, const pair<int, int> &b) {
            return a.first < b.first;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
        unordered_map<int, int> countMap;

        for (auto each : nums) {
            countMap[each]++;
        }

        for (auto each : countMap) {
            pq.push({each.second, each.first});
        }

        vector<int> out(k, 0);
        for (int i = 0; i < k; ++i) {
            out[i] = pq.top().second;
            pq.pop();
        }
        return out;
    }
};
