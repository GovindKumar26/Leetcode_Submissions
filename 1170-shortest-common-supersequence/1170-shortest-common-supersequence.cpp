class Solution {
public:

 int tab(string t1, string t2, vector<vector<int>>&dp){
         int size1 = t1.length(), size2 = t2.length();
      for(int i=0 ; i<=size2 ; i++) dp[0][i] = 0;
      for(int i=0 ; i<=size1 ; i++) dp[i][0] = 0;
       int ans;
      for(int i1=1 ; i1<=size1 ; i1++){
        for(int i2 = 1 ; i2<=size2 ; i2++){
            if(t1[i1-1]==t2[i2-1]){
                dp[i1][i2] = 1 + dp[i1-1][i2-1];
            } else{
               dp[i1][i2] = max(dp[i1-1][i2], dp[i1][i2-1]);
            }

        }
      }
      return dp[size1][size2];

     }

    string shortestCommonSupersequence(string s1, string s2) {
        int n = s1.length(), m = s2.length();
        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
    	int len = tab(s1, s2, dp);

     

      int i=n, j=m;
      string ans = "";
      while(i>0 && j>0){
        if(s1[i-1]==s2[j-1]){
         ans = ans + s1[i-1];
          i--, j--;
        } else if(dp[i-1][j]>dp[i][j-1]){
          ans = ans + s1[i-1];
          i--;
        } else {
            ans = ans + s2[j-1];
          j--;
        }
      }

      while(i>0) {
        ans = ans + s1[i-1];
        i--;
      }
      
      while(j>0){
        ans = ans + s2[j-1];
        j--;
      }
      
      reverse(ans.begin(), ans.end());
      return ans; 
    }
};