class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> ans;
        for (auto each:nums) {
            vector<int>::iterator it = lower_bound(ans.begin(), ans.end(), each);
            if (it == ans.end()) 
                ans.push_back(each);
            else
                *it = each;
        }
        return ans.size();
    }
};
