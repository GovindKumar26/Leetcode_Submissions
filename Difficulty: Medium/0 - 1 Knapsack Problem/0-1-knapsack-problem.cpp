//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

    int memo(int i, int W, vector<int>&wt, vector<int>&val, vector<vector<int>>&dp){
        if(i==0){
            if(W>=wt[0]) return val[0];
            else return 0;
        }
        
         if(dp[i][W]!=-1) return dp[i][W];
         
        int notTake = 0 + memo(i-1,W,wt,val, dp);
        int take = INT_MIN;
        if(wt[i]<=W){
            take = val[i] + memo(i-1, W-wt[i], wt, val, dp);
        }
        
        return dp[i][W] = max(take, notTake);
    }

    int knapSack(int W, vector<int>& wt, vector<int>& val) {
        int n = wt.size();
        vector<vector<int>>dp(n,vector<int>(W+1,-1));
        return memo(n-1,W, wt, val, dp);
    }
};

//{ Driver Code Starts.

int main() {
    // taking total testcases
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        // reading number of elements and weight
        int n, w;
        vector<int> arr, val, wt, drr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }

        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number) {
            val.push_back(number);
        }

        w = arr[0];
        n = val.size();
        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number) {
            wt.push_back(number);
        }
        Solution ob;
        cout << ob.knapSack(w, wt, val) << endl;
    }
    return 0;
}
// } Driver Code Ends