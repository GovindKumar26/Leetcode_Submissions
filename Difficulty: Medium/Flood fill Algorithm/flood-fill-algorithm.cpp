//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
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
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
      int iniColor = image[sr][sc];
      vector<vector<int>> ans = image;
      dfs(sr, sc, newColor, image, ans, iniColor);
      return ans;
      
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> image(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cin >> image[i][j];
        }
        int sr, sc, newColor;
        cin >> sr >> sc >> newColor;
        Solution obj;
        vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
        for (auto i : ans) {
            for (auto j : i)
                cout << j << " ";
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends