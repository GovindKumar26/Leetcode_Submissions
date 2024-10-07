class Solution {
public:
    void sortColors(vector<int>& nums) {
        double cntW=0,cntR=0,cntB = 0;

        for(int i =0;i<nums.size();i++){
            if(nums[i]==0) cntR++;
            else if(nums[i]==1) cntW++;
            else cntB++;
        }

        for(int i=0;i<nums.size();i++){
            if(i<cntR) nums[i] = 0;
            else if(i<cntR+cntW) nums[i] = 1;
            else if(i<cntR+cntW+cntB) nums[i] = 2;
        }
        
    }
};