class Solution {
public:

 
 int firstMissingPositive(vector<int>& nums) {
    int n = nums.size();
     vector<int> a (n,0); 
     for(int i=0;i<n;i++){
         if(nums[i]>0 && nums[i]<=n)
         a[nums[i]-1] = nums[i];
        
     }

     for(int i=0;i<n;i++){
         if(a[i]==0)
         return i+1;

     }
     return n+1;
         

        }

         
};