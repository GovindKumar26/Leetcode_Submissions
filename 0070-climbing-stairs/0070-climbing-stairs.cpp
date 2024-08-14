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

   int tabSolve(int n){
        vector<int>dp(n+1,0);
        dp[n] = 1;
        dp[n-1] = 1;
        for(int i=n-2 ; i>=0 ; i--){
            int a = 0, b = 0;
            if(i+1<=n) a = dp[i+1];
            if(i+2<=n) b = dp[i+2];

            dp[i] = a + b;

        }
        return dp[0];
    }


    int climbStairs(int n) {
         int dp[n] ;
         for(int i=0;i<n;i++){
            dp[i] = -1;
         }
    //  int ans = solve(n,0,dp);
     int ans = tabSolve(n);
      return ans;
    }
};