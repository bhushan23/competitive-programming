class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = (m > 0 ? matrix[0].size() : 0);
        
        int i = m-1;
        int j = 0;
        
        while (i >= 0 && j < n) {
            if (matrix[i][j] > target) {
                i--; 
            } else if (matrix[i][j] == target) {
                return true;
            } else {
                j++;
            }
        }
        return false;
    }
};
