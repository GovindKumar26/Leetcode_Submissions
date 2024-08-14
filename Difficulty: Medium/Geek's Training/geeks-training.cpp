//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  int solve(int n, vector<vector<int>>&points,int last,vector<vector<int>>&dp){
      if(n==0){
          int maximum = 0;
          for(int i=0;i<3;i++){
              if(i!=last)
              maximum = max(maximum,points[n][i]);
          }
          return maximum;
      }
      if(dp[n][last]!=-1) return dp[n][last];
      
      int maximum = 0;
      for(int i=0 ; i<3 ; i++){
          if(i!=last){
              int point = points[n][i] + solve(n-1,points,i,dp);
              maximum = max(point,maximum);
          }
      }
      
      return dp[n][last] = maximum;
  }
    int maximumPoints(vector<vector<int>>& arr, int n) {
        vector<vector<int>>dp(n,vector<int>(4,-1));
        return solve(n-1,arr,3,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> arr;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            arr.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends