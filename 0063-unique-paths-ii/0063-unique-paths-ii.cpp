class Solution {
public:
 int solve(int i, int j,vector<vector<int>>&dp,vector<vector<int>>&a){
        if(i>=0 && j>=0 && a[i][j]==1) return 0;
        if(i==0 && j==0) return 1;
        if(i<0 || j<0) return 0;
         
         if(dp[i][j]!=-1) return dp[i][j];
        int up = solve(i-1,j,dp,a);
        int left = solve(i,j-1,dp,a);

        return dp[i][j] = up+left;

     }

     int tab(int m, int n,vector<vector<int>>&obs){
         vector<vector<int>>dp(m,vector<int>(n,-1));
         
         for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(obs[i][j]==1) dp[i][j] = 0;
              else  if(i==0 && j==0) dp[i][j] = 1;

              else {
                  int up = 0, left = 0;
                if(i>0) up = dp[i-1][j];
                if(j>0) left = dp[i][j-1];
                dp[i][j] = up+left;
              }  
            }
         }
           return dp[m-1][n-1];       
     }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
       
         int m = obstacleGrid.size();
         int n = obstacleGrid[0].size();
         //  vector<vector<int>>dp(m,vector<int>(n,-1));

      //  return solve(m-1,n-1,dp,obstacleGrid);
        return tab(m,n,obstacleGrid);

    }
};