class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int ans = 0;
        int left = values[0]; 
        int n = values.size();

        for(int i=1 ; i<n ; i++){
            int right = values[i] - i;
            ans = max(ans, right+left);
            left = max(left, values[i]+i);
        }
        return ans;
    }
};