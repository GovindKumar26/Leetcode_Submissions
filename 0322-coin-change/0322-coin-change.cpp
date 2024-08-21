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


    int tab(vector<int>&coins, int amt){
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(amt+1,-1));
        
        for(int a = 0 ; a<=amt ; a++){
            if(a%coins[0]==0) dp[0][a] = a/coins[0];
            else dp[0][a] = 1e9;
        }

        for(int i=1 ; i<n ; i++){
            for(int a=0 ; a<=amt ; a++){
              int notPick = 0 + dp[i-1][a];
              int pick = 1e9;
          if(a>=coins[i]){
                pick = 1 + dp[i][a-coins[i]];
          }
        

         dp[i][a] = min(pick, notPick);
            }
        }
        return dp[n-1][amt];
    }


    


    
    int coinChange(vector<int>& coins, int amount) { 
         int n = coins.size();
         vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        // int ans = memo(n-1, coins,amount, dp);
           int ans = tab(coins, amount);
         if(ans>=1e9) return -1;
         return ans;
    }
};