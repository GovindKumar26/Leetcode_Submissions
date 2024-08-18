//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


#define mod 1000000007
class Solution {
  public:
  

int func(int i, int target, vector<int>&arr,vector<vector<int>>&dp){
       
        if(i==0) {
            if(arr[0]==0 && target==0) return 2;
            else if(target==0 || target==arr[0]) return 1;
			 return 0;
        } 

        if(dp[i][target]!=-1) return dp[i][target];

        int notPick = func(i-1,target,arr,dp)%mod;
        int pick = 0;
        if(arr[i]<=target) {
            pick = func(i-1,target-arr[i],arr,dp)%mod;
        }

        return dp[i][target] = (pick + notPick)%mod;
}
    int countPartitions(int n, int d, vector<int>& arr) {
        
         
         int sum = 0;
         for(auto a : arr) sum += a;
         
         if((sum-d)%2 || (sum-d)<0) return 0;
         
         int k = (sum-d)/2;
         
         vector<vector<int>>dp(n,vector<int>(k+1,-1));
      return func(n-1,k,arr,dp);
      
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends