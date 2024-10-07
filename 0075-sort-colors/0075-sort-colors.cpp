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


        // dutch national flag algorithm
        // int low = 0, mid = 0, high = n-1;
        // while(mid<=high){
        //     if(nums[mid]==0){
        //         swap(nums[mid], nums[low]);
        //         mid++;
        //         low++;
        //     }
        //     if(nums[mid]==1){
        //          mid++;
        //     }
        //     if(nums[mid]==2){
        //          swap(nums[mid],nums[high]);
        //          high--;
        //     }
        //} 
        
    }
};