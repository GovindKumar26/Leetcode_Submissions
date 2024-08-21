class Solution {
public:

    int memo(int i, vector<int>&coins, int amt, vector<vector<int>>&dp){
          if(i==0){
            if(amt%coins[0]==0) return amt/coins[0];
            else return 1e9;
          }
          
          if(dp[i][amt]!=-1) return dp[i][amt];

          int notPick = 0 + memo(i-1, coins, amt, dp);
          int pick = INT_MAX;
          if(amt>=coins[i]){
                pick = 1 + memo(i, coins, amt-coins[i], dp);
          }
        

          return dp[i][amt] = min(pick, notPick);
          
    }
    
    int coinChange(vector<int>& coins, int amount) { 
         int n = coins.size();
         vector<vector<int>>dp(n,vector<int>(amount+1,-1));
         int ans = memo(n-1, coins,amount, dp);
         if(ans>=1e9) return -1;
         return ans;
    }
};