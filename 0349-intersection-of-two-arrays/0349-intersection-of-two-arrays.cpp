class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans; int x = INT_MAX;
        sort(nums1.begin(),nums1.end());
      //  sort(nums2.begin(),nums2.end());
        for(int i=0;i<nums1.size();i++){
            if(x!=nums1[i]){

            for(int j=0;j<nums2.size();j++){
            if(nums1[i]==nums2[j]){
                 x = nums1[i];
                ans.push_back(x);
                break;
            }
          }
          }
          }
        
      return ans;  
    }
};