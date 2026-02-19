class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
      //  vector<int>ans;
        int n = nums.size();

        int l=0;
        for(int i=0 ; i<n ; i++){
            if(nums[i]%2==0){
                swap(nums[i], nums[l]);
                l++;
            }
        }

        return nums;


    }
};