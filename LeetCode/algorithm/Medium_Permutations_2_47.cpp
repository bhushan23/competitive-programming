class Solution {
public:
    vector<vector<int>> allPermute;
        
    void getAllPermute(vector<int> nums, int index) {
        
        if (index == nums.size()) {
            allPermute.push_back(nums);
            return;
        }        
        for (int i = index; i < nums.size(); ++i) {
            if (index != i && nums[index] == nums[i])
                continue;
            swap(nums[index], nums[i]);
            getAllPermute(nums, index+1);
        }
        return;        
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> numArray;
        unordered_map<int, int> numCount;
        int Count = 1;
       
        getAllPermute(nums, 0);
        
       return allPermute;
    }
};
