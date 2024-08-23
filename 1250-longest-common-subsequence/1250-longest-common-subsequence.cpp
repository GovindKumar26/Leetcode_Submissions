class Solution {
public:
     
     int memo(int i1, int i2, string t1, string t2, vector<vector<int>>&dp){
        if(i1<0 || i2<0) return 0;
        
        if(dp[i1][i2]!=-1) return dp[i1][i2];
        int ans;
        if(t1[i1]==t2[i2]){
           ans = 1 + memo(i1-1, i2-1, t1, t2, dp);
        } else
           ans = max(memo(i1-1, i2, t1, t2, dp), memo(i1, i2-1, t1, t2, dp));

          return dp[i1][i2] = ans;

     }

     int tab(string t1, string t2){
         int size1 = t1.length(), size2 = t2.length();
      vector<vector<int>>dp(size1+1, vector<int>(size2+1, 0));
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

     
    int longestCommonSubsequence(string text1, string text2) {
        int size1 = text1.length(), size2 = text2.length();
        vector<vector<int>>dp(size1, vector<int>(size2, -1));
      //  return memo(size1-1, size2-1, text1, text2, dp);
      return tab(text1, text2);
    }
};