bool compare(const pair<int, char> &a, const pair<int, char> &b) {
    return a.first > b.first;
}

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> map;
        for (auto each : s) {
            map[each]++;
        }

        vector<pair<int, char>> data(map.size());
        int i = 0;
        for (auto each : map) {
            data[i].first = each.second;
            data[i].second = each.first;
            i++;
        }
        sort(data.begin(), data.end(), compare);
        string out(s.size(), '-');

        i = 0;
        for (auto each : data) {
            int j = each.first;
            while (j--) {
                out[i++] = each.second;
            }
        }
        return out;
    }
};
