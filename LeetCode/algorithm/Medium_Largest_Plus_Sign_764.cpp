class Solution {
public:
    unordered_set<int> mSet;

    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        vector<vector<int>> dp(N, vector<int>(N, 1));

        for (auto each : mines) {
            mSet.insert(each[0]*N+each[1]);
            dp[each[0]][each[1]] = 0;
        }
        int maxP = 0;
        for (int i = 0; i < N; ++i) {
            int count = 1;
            for (int j = 0; j < N; ++j) {
                if (mSet.find(i*N+j) == mSet.end()) {
                    dp[i][j] = count++;
                } else {
                    dp[i][j] = 0;
                    count = 1;
                }

            }
            count = 1;
            for (int j = N-1; j >= 0; --j) {
                if (mSet.find(i*N+j) == mSet.end()) {
                    dp[i][j] = min(count++, dp[i][j]);
                } else {
                    dp[i][j] = 0;
                    count = 1;
                }
            }
        }

        for (int j = 0; j < N; ++j) {
            int count = 1;
            for (int i = 0; i < N; ++i) {
                if (mSet.find(i*N+j) == mSet.end()) {
                    dp[i][j] = min(count++, dp[i][j]);
                } else {
                    dp[i][j] = 0;
                    count = 1;
                }
            }
            count = 1;
            for (int i = N-1; i>= 0; --i) {
                if (mSet.find(i*N+j) == mSet.end()) {
                    dp[i][j] = min(count++, dp[i][j]);
                } else {
                    dp[i][j] = 0;
                    count = 1;
                }
                maxP = max(maxP, dp[i][j]);
            }
        }
        return maxP;
    }
};
