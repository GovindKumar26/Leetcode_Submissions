class Solution {
public:

    // void findComb(int idx,vector<int>&arr, int target, vector<int>&ds,vector<vector<int>>&ans){
    //      if(arr.size()==idx){
    //         if(target==0){
    //             sort(ds.begin(),ds.end());
    //             for(auto x : ans){
    //                 if(x==ds)
    //                 return;
    //             }
    //             ans.push_back(ds);
    //         }
    //         return ;
    //      }

    //      //pick
    //      ds.push_back(arr[idx]);
    //      findComb(idx+1,arr,target-arr[idx],ds,ans);

    //      //not pick
    //      ds.pop_back();
    //      findComb(idx+1,arr, target,ds,ans);
    // }

    void findComb(int idx,vector<int>&arr, int target, vector<int>&ds,vector<vector<int>>&ans){
         if(target==0){
            ans.push_back(ds);
            return;
         }

         for(int i=idx;i<arr.size();i++){
            if(i>idx && arr[i]==arr[i-1]) continue;
            if(target<arr[i]) break;

            ds.push_back(arr[i]);
            findComb(i+1,arr,target-arr[i],ds,ans);
            ds.pop_back();
         }
        
    }


    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    //     vector<vector<int>> ans ;
    //    sort(candidates.begin(),candidates.end());

    //     vector<int> ds;
    //     int idx = 0;
    //     findComb(idx,candidates,target,ds,ans);

    //     return ans;

    vector<vector<int>>ans;
    sort(candidates.begin(),candidates.end());
    vector<int>ds;
    int idx = 0;
    findComb(idx,candidates,target,ds,ans);
   
   return ans; }
};