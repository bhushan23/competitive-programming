class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = (m > 0 ? matrix[0].size() : 0);
        vector<int> left(n, 0);
        vector<int> right(n, n);
        vector<int> height(n, 0);
        int curLeft, curRight;
        int maxArea = 0;

        for (int i = 0; i < m; ++i) {
            curLeft = 0;
            curRight = n;
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '1') {
                    height[j]++;
                    left[j] = max(left[j], curLeft);
                } else {
                    height[j] = 0;
                    left[j] = 0;
                    curLeft = j+1;
                }
            }

            for (int j = n-1; j >= 0; --j) {
                if (matrix[i][j] == '1') {
                    right[j] = min(right[j], curRight);
                } else {
                    right[j] = n;
                    curRight = j;
                }
            }

             for (int j = 0; j < n; ++j) {
                maxArea = max(maxArea, (right[j] - left[j]) * height[j]);
             }
        }

        return maxArea;
    }
};
