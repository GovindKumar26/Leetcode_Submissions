class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for (int i = 0; i < nums.size() - 1; ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[i] == 0 && nums[j]) {
                    swap(nums[i], nums[j]);
                    break;
                }
            }
        }
    }
};