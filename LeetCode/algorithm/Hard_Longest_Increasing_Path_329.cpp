class Solution {
public:
    vector<vector<int>> values;
    int m, n;
    int maxPath; 
    
    int backTrack(vector<vector<int>> &matrix, int x, int y) {
        if (values[x][y] != -1)
            return values[x][y];
        
        values[x][y] = 1;
        int ans = 0;
        for (int i = max(0, x-1); i < min(x+2, m); ++i) {
            if (i != x && matrix[i][y] > matrix[x][y]) {
                ans = max(ans, backTrack(matrix, i, y));
            }
        }
        for (int j = max(0, y-1); j < min(y+2, n); ++j) {
             if (j != y && matrix[x][j] > matrix[x][y]) {
                ans = max(ans, backTrack(matrix, x, j));
            }
        }
        values[x][y] += ans;
        maxPath = max(maxPath, values[x][y]);
        return values[x][y];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = (m > 0 ? matrix[0].size() : 0);
        maxPath = INT_MIN;
        
        values.resize(m);
        for (int i = 0; i < m; ++i) {
            values[i].resize(n, -1);
        }
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (values[i][j] == -1) {
                    backTrack(matrix, i, j);
                }           
            }    
        }
        return (maxPath == INT_MIN ? 0 : maxPath);
    }
};
