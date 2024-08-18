class Solution {
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

bool spaceOpt(int target,vector<int>&arr){
    int n = arr.size();
    vector<bool>prev(target+1,0);
    prev[0] = 1;
   if(arr[0]<=target) prev[arr[0]] = 1;
    
    for(int i=1 ; i<n ; i++){
        vector<bool>curr(target+1,0);
        curr[0] = 1;
        for(int tar =1 ; tar<=target ; tar++){
            bool notPick = prev[tar];
            bool pick = false;
            if(arr[i]<=tar){
                pick = prev[tar-arr[i]];
            }
            
            curr[tar] = pick | notPick;
        }
        prev = curr;
    }
    
    return prev[target];
}

    bool canPartition(vector<int>& nums) {
          int sum = 0;
          int n = nums.size();
	    for(int i=0 ; i<n ; i++) sum +=nums[i];
		if(sum%2) return false;
		int k = sum/2;
	    vector<vector<int>>dp(n,vector<int>(k+1,-1));
     //   return func(n-1,k,nums,dp);
        return spaceOpt(k,nums);
    }
};