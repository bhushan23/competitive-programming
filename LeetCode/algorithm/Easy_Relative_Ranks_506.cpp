bool compare(const pair<int, int> &a, const pair<int, int> &b) {
    return (a.first > b.first);
}

class Solution {
public:
    
    void printList(vector<pair<int, int>> l) {
        for (int i = 0; i < l.size(); ++i) {
            cout << l[i].first << "(" << l[i].second <<") ";
        }
        cout << "\n";
    }
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<pair<int, int>> numsP(nums.size());
        vector<string> out(nums.size());
        
        for (int i = 0; i < nums.size(); ++i) {
            numsP[i].first = nums[i];
            numsP[i].second = i;
        }
        sort(numsP.begin(), numsP.end(), compare);
        
        for (int i = 0; i < nums.size(); ++i) {
            switch(i) {
                case 0:
                    out[numsP[i].second] = "Gold Medal";
                    break;
                 case 1:
                    out[numsP[i].second] = "Silver Medal";
                    break;
                 case 2:
                    out[numsP[i].second] = "Bronze Medal";
                    break;
                 default:
                    out[numsP[i].second] = to_string(i+1);
                    break;
                    
            }
        }
        
        return out;
    }
};
