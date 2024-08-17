class Solution {
public:
    
    int solve(int i,int j, vector<vector<int>>&triangle,int n,vector<vector<int>>&dp){
        if(i==n-1) return triangle[i][j];
       
        if(dp[i][j]!=-1) return dp[i][j];

        int down = solve(i+1,j,triangle,n,dp) + triangle[i][j];
        int diagonal = solve(i+1,j+1,triangle,n,dp) + triangle[i][j];

        return dp[i][j] = min(down,diagonal);
    }

    int tab(int i, int j, vector<vector<int>>&triangle){
        int n = i;
          vector<vector<int>>dp(n,vector<int>(n,-1));
          for(int j=0 ; j<n ; j++) dp[n-1][j] = triangle[n-1][j];

          for(int i=n-2 ; i>=0 ; i--){
            for(int j=i ; j>=0 ; j--){
                int down = 0, diagonal =0;
             if(i+1>=0)    down = triangle[i][j] + dp[i+1][j];
             if(i+1>=0 && j+1>=0)    diagonal = triangle[i][j] + dp[i+1][j+1];

                dp[i][j] = min(down,diagonal);
            }
          }
          return dp[0][0];
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
       // return solve(0,0,triangle,n,dp);
       return tab(n,n,triangle);
    }
};