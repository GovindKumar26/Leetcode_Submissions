class Solution {
public:
    int memo(int i, int buy, vector<int>& prices, int n,
             vector<vector<int>>& dp) {
        if (i == n)
            return 0;

        if (dp[i][buy] != -1)
            return dp[i][buy];

        int profit = 0;
        if (buy) {
            profit = max(-prices[i] + memo(i + 1, 0, prices, n, dp),
                         memo(i + 1, 1, prices, n, dp));
        } else {
            profit = max(prices[i] + memo(i + 1, 1, prices, n, dp),
                         memo(i + 1, 0, prices, n, dp));
        }

        return dp[i][buy] = profit;
    }

    int tab(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int buy = 0; buy <= 1; buy++) {
                int profit = 0;
                if (buy==1) {
                    profit = max(-prices[i] + dp[i+1][0],
                                dp[i+1][1]);
                } else {
                    profit = max(prices[i] + dp[i+1][1],
                                dp[i+1][0]);
                }

                dp[i][buy] = profit;
            }
        }

        return dp[0][1];
    }

    int maxProfit(vector<int>& prices) {
        //  int max = 0;
        // int start = prices[0];
        // int n = prices.size();
        // for(int i = 1;i<n; i++){
        //     if(start < prices[i]){
        //         max = max + prices[i] - start;
        //     }
        //     start = prices[i];
        // }
        // return max;
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return tab(prices);
        return memo(0, 1, prices, n, dp);
    }
};