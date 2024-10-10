class Solution {
public:
    vector<int>generateRow(int rowN){
        int res = 1;
        vector<int> ansRow;
        ansRow.push_back(1);
        for(int col=1 ; col<rowN ; col++){
            res = res*(rowN-col);
            res = res/col;
            ansRow.push_back(res);
        }
        return ansRow;
    }

    vector<vector<int>> generate(int numRows) {
         vector<vector<int>>ans;

         for(int i=0 ; i<numRows ; i++){
            ans.push_back(generateRow(i+1));
         }

         return ans;
    }
};