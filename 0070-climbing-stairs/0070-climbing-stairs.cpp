class Solution {
public:

    int solve(int n, int i,int dp[]){
        if(i==n){
            return 1;
        }
        if(i>n){
            return 0;
        }
      if(dp[i]!=-1){
        return dp[i];
      }

      int a =  solve(n,i+1,dp);
       int b =  solve(n,i+2,dp);
       dp[i] = a + b;
       return dp[i];

    }

    int climbStairs(int n) {
         int dp[n] ;
         for(int i=0;i<n;i++){
            dp[i] = -1;
         }
      int ans = solve(n,0,dp);
     
      return ans;
    }
};