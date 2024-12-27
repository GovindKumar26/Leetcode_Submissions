class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size();
        vector<bool> ans(n);

        for (int i = 0; i < n; i++) {
            if (candies[i] + extraCandies >= *max_element(candies.begin(), candies.end())){
                ans[i] = 1;
            } else{
                ans[i] = 0;
            }
        }
        return ans;
    }
};