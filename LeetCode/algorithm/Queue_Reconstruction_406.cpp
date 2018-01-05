bool compare(const pair<int, int> &a, const pair<int, int> &b) {
    return (a.first > b.first || a.first == b.first && a.second < b.second);
}

class Solution {
public:
    void printList (vector<pair<int,int>> list) {
        for (auto each : list) {
            cout << each.first << "," << each.second << "  ";
        }
        cout << "\n";
    }

    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        sort(people.begin(), people.end(), compare);
        
        vector<pair<int, int>> out;
        for (auto &each : people) {
            out.insert(out.begin() + each.second, each);
        }
        return out;
    }
};
