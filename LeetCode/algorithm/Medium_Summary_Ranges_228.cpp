class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int from = -1;
        int to = -1;
        vector<string> out;
        for (int i = 0; i < nums.size(); ++i) {
            from = i;
            while (i+1 < nums.size() && nums[i+1] == nums[i]+1)
                i++;
            string tmp = to_string(nums[from]);
            if (i > from) {
                tmp += "->" + to_string(nums[i]);
            }
            out.push_back(tmp);
        }
        return out;
    }
};
