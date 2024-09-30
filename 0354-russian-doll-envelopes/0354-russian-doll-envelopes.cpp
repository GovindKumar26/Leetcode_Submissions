class Solution {
public:
    int LIS(vector<int>& nums) {
        vector<int> temp;
        int len = 1;
        temp.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > temp.back()) {
                temp.push_back(nums[i]);
                len++;
            } else {
                int ind = lower_bound(temp.begin(), temp.end(), nums[i]) -
                          temp.begin();
                temp[ind] = nums[i];
            }
        }
        return len;
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {

        // sort based on width. if same width, descending order of heights
        sort(envelopes.begin(), envelopes.end(),
             [](vector<int>& a, vector<int>& b) {
                 if (a[0] == b[0])
                     return a[1] > b[1];
                 else {
                     return a[0] < b[0];
                 }
             });

        // extract heights
        vector<int> heights;
        for (auto e : envelopes) {
            heights.push_back(e[1]);
        }

        // find LIS based on the heights

        return LIS(heights);
    }
};