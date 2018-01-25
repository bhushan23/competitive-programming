bool comparator(const pair<int, int> &a, const pair<int, int>&b) {
    return a.first < b.first || a.second < b.second;
}
class Solution {
public:
    vector<int> partitionLabels(string S) {
        unordered_map<char, pair<int, int>> lMap;

        for (int i = 0; i < S.size(); ++i) {
            if (lMap.find(S[i]) == lMap.end()) {
                lMap[S[i]] = {i, i};
            } else {
                lMap[S[i]].second = i;
            }
        }

        vector<pair<int, int>> all;

        for (auto each : lMap) {
            all.push_back(each.second);
            // cout << each.first << " " << each.second.first << " " << each.second.second << endl;
        }
        sort(all.begin(), all.end());
        // cout << endl;

        vector<pair<int, int>> merged;
        merged.push_back(all[0]);
        for (int i = 1; i < all.size(); ++i) {
            // cout << i << " " << all[i].first << " " << all[i].second << endl;
            if (all[i].first > merged[merged.size()-1].second) {
                merged.push_back(all[i]);
            } else {
                merged[merged.size()-1].second = max(merged[merged.size()-1].second, all[i].second);
            }
        }
        vector<int> ans(merged.size());
        // cout << "Merged" << endl;
        for (int i = 0; i < merged.size(); ++i) {
            // cout << merged[i].first << "," << merged[i].second << " " << endl;
            ans[i] = merged[i].second - merged[i].first + 1;
        }
        return ans;
    }
};
