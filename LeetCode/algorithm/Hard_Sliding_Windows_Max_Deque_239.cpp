class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> out;
        deque<int> dque;
        
        int i = 0;
        while (i < nums.size()) {
            if (!dque.empty() && dque.front() == i-k)
                dque.pop_front();
            
            while (!dque.empty() && nums[dque.back()] < nums[i])
                dque.pop_back();
            
            dque.push_back(i);
            
            if (i >= k-1)
                out.push_back(nums[dque.front()]);
            i++;
        }
        
        return out;
    }
};
