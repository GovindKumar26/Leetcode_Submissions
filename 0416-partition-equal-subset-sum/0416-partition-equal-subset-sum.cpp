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
    bool canPartition(vector<int>& nums) {
          int sum = 0;
          int n = nums.size();
	    for(int i=0 ; i<n ; i++) sum +=nums[i];
		if(sum%2) return false;
		int k = sum/2;
	    vector<vector<int>>dp(n,vector<int>(k+1,-1));
        return func(n-1,k,nums,dp);
    }
};