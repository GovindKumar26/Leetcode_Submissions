class Solution {
public:

    void dfs(int row, int col,int newColor, vector<vector<int>>image, vector<vector<int>>&ans, int iniColor){
        ans[row][col] = newColor;
        
        vector<int> drow = {-1, 0, 1, 0}, dcol = {0, 1, 0, -1};
        int n = image.size(), m = image[0].size();
        for(int i=0 ; i<4 ; i++){
           int nRow = row+drow[i];
          int  nCol = col+dcol[i];
            if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && image[nRow][nCol]==iniColor && ans[nRow][nCol]!=newColor)
            dfs(nRow, nCol, newColor, image, ans, iniColor);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
         int iniColor = image[sr][sc];
      vector<vector<int>> ans = image;
      dfs(sr, sc, color, image, ans, iniColor);
      return ans;
    }
};