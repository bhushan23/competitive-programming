class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> out;
        vector<int> elements = nums;
        if (nums.size() < k || nums.size() == 0)
            return out;
        
        make_heap(nums.begin(), nums.begin()+k);
        int i = 0;
        while (nums.size() >= k) {
            out.push_back(nums.front());
            nums.erase(find(nums.begin(), nums.begin()+k, elements[i++]));
            make_heap(nums.begin(), nums.begin()+k);
        }
        return out;
    }
};
