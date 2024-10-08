//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

        int memo(int i, int W, int wt[], int val[], vector<vector<int>>&dp){
        if(i==0){
            if(W>=wt[0]) return ((int)(W/wt[0]))*val[0];
            else return 0;
        }
        
         if(dp[i][W]!=-1) return dp[i][W];
         
        int notTake = 0 + memo(i-1,W,wt,val, dp);
        int take = 0;
        if(wt[i]<=W){
            take = val[i] + memo(i, W-wt[i], wt, val, dp);
        }
        
        return dp[i][W] = max(take, notTake);
    }


    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>>dp(N,vector<int>(W+1, -1));
        return memo(N-1, W, wt, val,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends