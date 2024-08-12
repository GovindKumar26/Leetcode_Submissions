class Solution {
public:
   
   int func(int i, int j , vector<vector<int>>&mat,vector<vector<int>>&dp){
        if(j<0 || j>=mat[0].size()) return 1e8;

        if(i==0) return mat[0][j];

        if(dp[i][j]!=-1) return dp[i][j];

       int up = func(i-1,j,mat,dp) + mat[i][j];
       int right = func(i-1,j+1,mat,dp) + mat[i][j];
       int left = func(i-1,j-1,mat,dp) + mat[i][j];

     dp[i][j] = min(up,min(right,left));
     return dp[i][j];
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n =   matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));

        for(int i=0 ; i<n ; i++){
            dp[0][i] = matrix[0][i];
        }

        for(int i=1 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                 int up = dp[i-1][j] + matrix[i][j];
                 int right = matrix[i][j];

             if(j+1<m)  right = dp[i-1][j+1] + right;
             else  right = right + 1e8;
                 
                 int left = matrix[i][j];
                if(j-1>=0)  left = dp[i-1][j-1] + left;
                  else left = left + 1e8;

                   dp[i][j] = min(up,min(right,left));
            }
        }

        int maximum = 1e8;
        for(int j=0 ; j<m ; j++){
            int ans = dp[n-1][j];
            maximum = min(maximum,ans);
        }
        return maximum;
    }
};