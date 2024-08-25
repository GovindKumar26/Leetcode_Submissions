//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  int tab(string t1, string t2){

         int size1 = t1.length(), size2 = t2.length();
         vector<vector<int>>dp(size1+1, vector<int>(size2+1,0));
      for(int i=0 ; i<=size2 ; i++) dp[0][i] = 0;
      for(int i=0 ; i<=size1 ; i++) dp[i][0] = 0;
       int ans = 0;
      for(int i1=1 ; i1<=size1 ; i1++){
        for(int i2 = 1 ; i2<=size2 ; i2++){
            if(t1[i1-1]==t2[i2-1]){
                dp[i1][i2] = 1 + dp[i1-1][i2-1];
                ans = max(ans, dp[i1][i2]);
            } else{
               dp[i1][i2] = 0;
            }

        }
      }
      return ans;

     }
     
     
    int longestCommonSubstr(string str1, string str2) {
       return tab(str1, str2);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr(s1, s2) << endl;
    }
}
// } Driver Code Ends