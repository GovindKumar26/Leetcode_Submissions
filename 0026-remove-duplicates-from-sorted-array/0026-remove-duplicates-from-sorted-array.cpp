class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n =nums.size();
        vector<char>v(n,'_');
        int j=0;
        for(int i=0;i<n-1;i++){
            if(nums[i]!=nums[i+1]){
               v[j++] = nums[i];
            }
        }
        v[j++] = nums[n-1];
        int count=j;
// for(int k=0;k<n;k++){
//     if(v[k]!='_'){
//         count++;
//     }
// }
        //int k=0, count=0;
    //    while(k<n && v[k]!='_'){
           
    //            count++;
    //            k++;
           
    //    }
            for(int i=0;i<count;i++){
                nums[i] = v[i];
            }
      return count;  
    }
};