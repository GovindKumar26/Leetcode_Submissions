class Solution {
public:
    
    int memo(int i, int j, string &s, string &t, vector<vector<int>>&dp){
         if(j<0) return 1;
         if(i<0) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]){
            return dp[i][j] = memo(i-1, j-1, s, t, dp) + memo(i-1,j, s, t, dp);
        }

        return dp[i][j] = memo(i-1, j, s, t, dp);
    }

    int tab(string &s, string &t){
        int n = s.length();
        int m = t.length();
        vector<vector<double>>dp(n+1, vector<double>(m+1,-1));

        for(int i=0;i<=n;i++) dp[i][0] = 1;
        for(int j=1;j<=m;j++) dp[0][j] = 0;

        for(int i=1 ; i<=n ; i++){
            for(int j=1 ; j<=m ; j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                } else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return (int)dp[n][m];
         

    }

    int spaceOpt(string &s, string &t){
        int n = s.length();
        int m = t.length();
        vector<double>prev(m+1,0), curr(m+1,0);
        prev[0] = curr[0] = 1;

        for(int i=1 ; i<=n ; i++){
            for(int j=1 ; j<=m ; j++){
                if(s[i-1]==t[j-1]){
                    curr[j] = prev[j-1] + prev[j];
                } else{
                    curr[j] = prev[j];
                }
            }
            prev = curr;
        }
        return (int)prev[m];
    }

    int spaceOpt1(string &s, string &t){
         int n = s.length();
        int m = t.length();
        vector<double>prev(m+1,0);
        prev[0] = 1;

        for(int i=1 ; i<=n ; i++){
            for(int j=m ; j>=1 ; j--){
                if(s[i-1]==t[j-1]){
                    prev[j] = prev[j-1] + prev[j];
                }
            }
        }
        return (int)prev[m];
    }

    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        vector<vector<int>>dp(n, vector<int>(m,-1));
     //  return memo(n-1, m-1, s, t, dp);
     //  return tab(s,t);
       return spaceOpt(s, t);
    }
};