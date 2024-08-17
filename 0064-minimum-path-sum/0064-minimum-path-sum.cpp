class Solution {
public:
    
    int solve(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&dp){
       if(i==0 && j==0) return grid[i][j];
       if(i<0 || j<0) return 1e9;
       if(dp[i][j]!=-1) return dp[i][j];
       int up = solve(i-1,j,grid,dp) + grid[i][j];
       int left = solve(i,j-1,grid,dp) + grid[i][j];
       
      return dp[i][j] = min(left,up);
       
    }

    int tab(int m, int n, vector<vector<int>>&obs){
        vector<vector<int>>dp(m,vector<int>(n,-1));
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(i==0 && j==0) dp[i][j] = obs[i][j];
                else {
                    int up = obs[i][j];
                    int left = obs[i][j];
                    
                    if(i>0) up = obs[i][j] + dp[i-1][j];
                    else up = 1e9;
                    if(j>0) left = obs[i][j] + dp[i][j-1];
                    else left = 1e9;

                    dp[i][j] = min(left,up);
                }
            }
        }
        return dp[m-1][n-1];
    }

    int spaceOpt(int m, int n,vector<vector<int>>&obs){
        vector<int>prev(n,0);

        for(int i=0 ; i<m ; i++){
            vector<int>curr(n,0);
            for(int j=0 ; j<n ; j++){
                 if(i==0 && j==0) curr[j] = obs[i][j];
                 else{
                  int  up = obs[i][j], left = obs[i][j];
                    if(i>0) up = obs[i][j] + prev[j];
                    else up = 1e9;
                    if(j>0) left = obs[i][j] + curr[j-1];
                    else left = 1e9;

                    curr[j] = min(left,up);
                 }
            }
            prev = curr;
        }
        return prev[n-1];
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
    //  vector<vector<int>>dp(m,vector<int>(n,-1));
       // return solve(m-1,n-1,grid,dp);
      // return tab(m,n,grid);
       return spaceOpt(m,n,grid);
    }
};