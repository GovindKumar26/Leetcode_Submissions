//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	      int target = 0;
  for(int i=0 ; i<n ; i++) target = target + arr[i];
 
   vector<vector<bool>>dp(n,vector<bool>(target+1,0));
    
    for(int i=0 ; i<n ; i++) dp[i][0] = 1;
     if(arr[0]<=target) dp[0][arr[0]] = 1; // failed because target can be negative in case of negative elements in the set
    
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

  
     
     int mini = 1e9;

     for(int s1 = 0 ; s1<=target ; s1++){
        if(dp[n-1][s1]==true){
             mini = min(mini,abs(s1-(target-s1)));
        }
     }
return mini;
    }
	
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends