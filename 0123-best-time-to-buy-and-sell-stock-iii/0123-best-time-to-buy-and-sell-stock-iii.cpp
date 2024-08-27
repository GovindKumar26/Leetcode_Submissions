class Solution {
public:

     int memo(int i, int buy, vector<int>&prices, int n, int cap, vector<vector<vector<int>>>&dp){
        if(cap==0) return 0;
        if(i==n) return 0;
        
        if(dp[i][buy][cap]!=-1) return dp[i][buy][cap];

        int profit = 0;
        if(buy){
            profit = max(-prices[i]+memo(i+1, 0, prices, n,cap, dp), memo(i+1, 1, prices, n, cap, dp));
        }
        else {
            profit = max(prices[i] + memo(i+1, 1, prices, n, cap-1, dp), memo(i+1, 0, prices, n, cap, dp));
        }

        return dp[i][buy][cap] = profit;
    }



    int maxProfit(vector<int>& prices) {
         int n = prices.size();
     //   vector<vector<int>>dp(n, vector<int>(2,-1));
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return memo(0,1, prices, n, 2, dp);
    }
};