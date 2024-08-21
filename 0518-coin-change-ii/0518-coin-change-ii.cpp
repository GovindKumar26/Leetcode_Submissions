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

    int tab(vector<int>&coins, int amt){
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(amt+1,-1));
        
        for(int a = 0 ; a<=amt ; a++){
            if(a%coins[0]==0) dp[0][a] = 1;
            else dp[0][a] = 0;
        }

        for(int i=1 ; i<n ; i++){
            for(int a=0 ; a<=amt ; a++){
              int notPick = 0 + dp[i-1][a];
              int pick = 0;
          if(a>=coins[i]){
                pick =  dp[i][a-coins[i]];
          }
        

         dp[i][a] =pick + notPick;
            }
        }
        return dp[n-1][amt];
    }

     int spaceOpt(vector<int>&coins, int amt){
        int n = coins.size();
        vector<int>prev(amt+1,0);

        for(int i=0 ; i<=amt ; i++){
           if(i%coins[0]==0) prev[i] = 1;
            else prev[i] = 0;
        }
        
         for(int i=1 ; i<n ; i++){
            vector<int>curr(amt+1,0);
            for(int a=0 ; a<=amt ; a++){
              int notPick = 0 + prev[a];
              int pick = 0;
          if(a>=coins[i]){
                pick = curr[a-coins[i]];
          }
        

         curr[a] = pick + notPick;
            }
            prev = curr;
        }
        return prev[amt];


    }   

    int change(int amount, vector<int>& coins) {
          int n = coins.size();
         vector<vector<int>>dp(n,vector<int>(amount+1,-1));
     //   return memo(n-1, coins,amount, dp);
      //  return tab(coins, amount);
      return spaceOpt(coins, amount);
    }
};