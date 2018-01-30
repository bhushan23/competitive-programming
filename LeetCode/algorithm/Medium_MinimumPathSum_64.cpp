class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = (m > 0 ? grid[0].size() : 0);

        if (m == 0 || n == 0)
            return 0;
        vector<int> sum(n, grid[0][0]);
        for (int i = 1; i < n; ++i) {
            sum[i] = sum[i-1] + grid[0][i];
        }
        for (int i = 1; i < m; ++i) {
            sum[0] += grid[i][0];
            for (int j = 1; j < n; ++j) {
                sum[j] = min(sum[j], sum[j-1]) + grid[i][j];
            }
        }
        return sum[n-1];
    }
};
