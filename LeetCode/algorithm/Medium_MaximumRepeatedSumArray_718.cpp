class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        vector<vector<int>> dp(A.size()+1, vector<int>(B.size()+1, 0));

        int ans = 0;
        for (int i = A.size() - 1; i >= 0; --i) {
            for (int j = B.size() - 1; j >= 0; --j) {
                if (A[i] == B[j]) {
                    dp[i][j] = dp[i+1][j+1] + 1;
                    if (ans < dp[i][j])
                        ans = dp[i][j];
                }
            }
        }
        return ans;
    }
};
