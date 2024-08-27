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
    
    int spaceOpt(vector<int>&prices, int &fee){
         int n = prices.size();
         vector<int>ahead(2, 0), curr(2, 0);

          for (int i = n - 1; i >= 0; i--) {
            for (int buy = 0; buy <= 1; buy++) {
                int profit = 0;
                if (buy==1) {
                    profit = max(-prices[i] + ahead[0],
                                ahead[1]);
                } else {
                    profit = max(prices[i] + ahead[1] -fee,
                              ahead[0]);
                }

                curr[buy] = profit;
            }

            ahead = curr;
        }

        return ahead[1];

    }

    int maxProfit(vector<int>& prices, int fee) {
         int n = prices.size();
        vector<vector<int>>dp(n, vector<int>(2,-1));
        return spaceOpt(prices, fee);
      //  return memo(0,1, prices, n, fee, dp);
    }
};