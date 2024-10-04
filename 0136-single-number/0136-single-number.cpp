class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xorResult = 0;
        for(auto i : nums){
            xorResult = xorResult^i;
        }
        return xorResult;
    }
};