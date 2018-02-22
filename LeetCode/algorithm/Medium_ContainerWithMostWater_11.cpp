class Solution {
public:
    int maxArea(vector<int>& height) {
        int l, r;
        l = 0;
        r = height.size()-1;
        int maxAns = 0;
        while (l < r) {
            maxAns = max(maxAns, min(height[l], height[r]) * (r-l));
            if (height[l] < height[r]) {
                l++;
            } else {
                r--;
            }
        }
        return maxAns;
    }
};
