class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int m = prices.size();
        if (m == 0)
            return -1;
        
        vector<int> dp(m, -1);
        
        dp[0] = 0;
        //cout << dp[0] << " ";
        for (int i = 1; i < m; ++i) {
            dp[i] = max(dp[i-1], prices[i] - prices[0] - fee);
            //cout << dp[i] << " ";
        }
        //cout << "\n";
        
        for (int i = 1; i < m; ++i) {
            //cout << i << ":";
            //for (int j = 0; j < i; ++j)
            //    cout << "0 ";
            for (int j = i; j < m; ++j) {
                /*if (i == j) {
                    dp[i] = dp[i-1];
                    continue;
                }*/
                dp[j] = max(max(dp[j], dp[j-1]), dp[i] + (prices[j] - prices[i] - fee));
            
                //cout << dp[j] << " ";
            }
            //cout << "\n";
        }
        return dp[m-1];
    }
};
