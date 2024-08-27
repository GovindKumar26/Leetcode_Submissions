class Solution {
public:

     int memo(int i, int buy, vector<int>&prices, int n, int fee, vector<vector<int>>&dp){
        if(i==n) return 0;
        
        if(dp[i][buy]!=-1) return dp[i][buy];

        int profit = 0;
        if(buy){
            profit = max(-prices[i]+memo(i+1, 0, prices, n, fee, dp), memo(i+1, 1, prices, n, fee, dp));
        }
        else {
            profit = max(prices[i] + memo(i+1, 1, prices, n,fee, dp) - fee, memo(i+1, 0, prices, n, fee, dp));
        }

        return dp[i][buy] = profit;
    }

    int maxProfit(vector<int>& prices, int fee) {
         int n = prices.size();
        vector<vector<int>>dp(n, vector<int>(2,-1));
        return memo(0,1, prices, n, fee, dp);
    }
};