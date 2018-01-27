class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> st;
        vector<int> mins(nums.size());
        int tMin = INT_MAX;
        for (int i = 0; i < nums.size(); ++i) {
            tMin = min(tMin, nums[i]);
            mins[i] = tMin;
        }

        if (nums.size() <= 2)
            return false;
        st.push(nums[nums.size()-1]);
        for (int i = nums.size()-2; i >= 0; --i) {
            // cout << nums[i] << " " << mins[i] << endl;
            if (nums[i] > mins[i]) {
                // cout << "STACK: ";
                while (!st.empty() && st.top() <= mins[i]) {
                    // cout << st.top() << " ";
                    st.pop();
                }
                // cout << endl;
                if (!st.empty() && st.top() > mins[i] && st.top() < nums[i])
                    return true;
            }
            st.push(nums[i]);

        }
        return false;
    }
};
