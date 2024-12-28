class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();

 
       
        for(int i=0;i<n-1 && nums[i]!=INT_MAX;i++){
            int count=0;
            int temp=nums[i];

            while(i<n-1 &&  temp==nums[i+1] ){
                i++;
                count++;
            }

            for(int j=i-1; count>1;count--,j--){
                nums[j] = INT_MAX;
            }

            


         }
         sort(nums.begin(),nums.end());
         int k=0;

         for(int i=0;i<n;i++){
             if(nums[i]!=INT_MAX) k++;

         }
        return k;
    }
};