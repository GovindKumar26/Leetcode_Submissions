class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int p = 0, q = 0;
        int i = 0;
        int n = nums.size();

        while (i < nums.size() - 1 && nums[i] < nums[i + 1]) {
            i++;
        }

        p = i;
        if(p==0) return false;

        while (i < nums.size() - 1 && nums[i] > nums[i + 1]) {
            i++;
        }
        q = i;
        if(q==n-1) return false;

        while(i<nums.size()-1 && nums[i]<nums[i+1]) {
            i++;
        }

        return i==n-1;
    }
};