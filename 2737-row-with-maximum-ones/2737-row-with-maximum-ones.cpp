class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
         int res = 0, mx = 0;
        for(int i = 0 ; i < mat.size() ; i++) {
            int one = 0;
            for(int j = 0 ; j < mat[0].size() ; j++) one += (mat[i][j] == 1);
            if(one > mx) {
                mx = one;
                res = i;
            }
        }
        return {res, mx};
    }
};