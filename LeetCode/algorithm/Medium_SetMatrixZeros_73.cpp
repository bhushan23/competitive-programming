class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> row, col;
        int m = matrix.size();
        int n = (m > 0 ? matrix[0].size() : 0);
        if (m == 0)
            return;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    row.insert(i);
                    col.insert(j);
                }
            }
        }

        for (auto el : row) {
            for (int j = 0; j < n; ++j) {
                matrix[el][j] = 0;
            }
        }
        for (auto el : col) {
            for (int j = 0; j < m; ++j) {
                matrix[j][el] = 0;
            }
        }
    }
};
