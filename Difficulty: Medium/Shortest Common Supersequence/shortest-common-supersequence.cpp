//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution
{
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


     int spaceOpt(string t1, string t2){
        int size1 = t1.length(), size2 = t2.length();
        vector<int>prev(size2+1);
        vector<int>curr(size2+1);
         for(int i=0 ; i<=size2 ; i++) prev[i] = 0;
     
      for(int i1=1 ; i1<=size1 ; i1++){
        for(int i2 = 1 ; i2<=size2 ; i2++){
            if(t1[i1-1]==t2[i2-1]){
              curr[i2] = 1 + prev[i2-1];
            } else{
              curr[i2] = max(prev[i2], curr[i2-1]);
            }

        }
        prev = curr;
      }
      return prev[size2];
     }
     
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        return m + n - tab(X, Y);
    }
};

//{ Driver Code Starts.

int main()
{   
    
    int t;
    
    //taking total testcases
    cin >> t;
    while(t--){
    string X, Y;
    //taking String X and Y
	cin >> X >> Y;
	
	//calling function shortestCommonSupersequence()
	Solution obj;
	cout << obj.shortestCommonSupersequence(X, Y, X.size(), Y.size())<< endl;
    }
	return 0;
}


// } Driver Code Ends