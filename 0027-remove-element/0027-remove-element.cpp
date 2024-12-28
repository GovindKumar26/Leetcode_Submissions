class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        
       int k=0; 
        if(!nums.empty()){
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]==val){
                nums.erase(nums.begin()+i);
                i--;
            }
             k = nums.size();
           
            
        }}
    return k;}
};