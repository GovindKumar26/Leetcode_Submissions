class Solution {
public:
    vector<vector<int>> ans;
    
    void backtrack(vector<int>& nums, int index) {
        if (index == nums.size()) {
            ans.push_back(nums);
            return;
        }
        
        unordered_set<int> seen; // track duplicates at this level
        for (int i = index; i < nums.size(); i++) {
            if (seen.count(nums[i])) continue; // skip if already tried this number at this index
            
            seen.insert(nums[i]);
            swap(nums[index], nums[i]);
            backtrack(nums, index + 1);
            swap(nums[index], nums[i]); // backtrack
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        backtrack(nums, 0);
        return ans;
    }
};

