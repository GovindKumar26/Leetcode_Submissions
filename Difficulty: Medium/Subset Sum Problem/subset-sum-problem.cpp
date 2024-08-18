//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:

bool func(int i, int target, vector<int>&arr,vector<vector<int>>&dp){
        if(target==0) return true;
        if(i==0) {
            if(arr[0]==target) return true;
                   else return false;
        } 

        if(dp[i][target]!=-1) return dp[i][target];

        bool notPick = func(i-1,target,arr,dp);
        bool pick = false;
        if(arr[i]<=target) {
            pick = func(i-1,target-arr[i],arr,dp);
        }

        return dp[i][target] = pick | notPick;
}


bool tab(int target, vector<int>&arr){
    int n = arr.size();
   vector<vector<bool>>dp(n,vector<bool>(target+1));
    
    for(int i=0 ; i<n ; i++) dp[i][0] = 1;
    dp[0][arr[0]] = 1;
    
     for(int i=1 ; i<n ; i++){
         for(int tar = 1 ; tar<=target ; tar++){
             
        bool notPick = dp[i-1][tar];
        bool pick = false;
        if(arr[i]<=tar) {
            pick = dp[i-1][tar-arr[i]];
        }

        dp[i][tar] = pick | notPick;
         }
     }
      return dp[n-1][target];
     
}

    bool isSubsetSum(vector<int>arr, int sum){
        int n  = arr.size();
         vector<vector<int>>dp(n,vector<int>(sum+1,-1));
 //  return func(n-1,sum,arr,dp);
   return tab(sum,arr);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends