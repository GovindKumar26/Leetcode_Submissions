class Solution {
public:

        int memo(int i, vector<int>&coins, int amt, vector<vector<int>>&dp){
          if(i==0){
            if(amt%coins[0]==0) return 1;
            else return 0;
          }
          
          if(dp[i][amt]!=-1) return dp[i][amt];

          int notPick = 0 + memo(i-1, coins, amt, dp);
          int pick = 0;
          if(amt>=coins[i]){
                pick =  memo(i, coins, amt-coins[i], dp);
          }
        

          return dp[i][amt] = pick+notPick;
          
    }


    int change(int amount, vector<int>& coins) {
          int n = coins.size();
         vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return memo(n-1, coins,amount, dp);
    }
};