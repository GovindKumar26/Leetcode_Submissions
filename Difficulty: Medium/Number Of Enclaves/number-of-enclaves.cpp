//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
   void dfs(int row, int col, vector<vector<int>>& vis,
             vector<vector<int>>& mat) {
        vis[row][col] = 1;
        int delR[] = {-1, 0, 1, 0}, delC[] = {0, 1, 0, -1};
        int n = mat.size(), m = mat[0].size();

        for (int i = 0; i < 4; i++) {
            int nrow = row + delR[i];
            int ncol = col + delC[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                vis[nrow][ncol] == 0 && mat[nrow][ncol] == 1) {
                dfs(nrow, ncol, vis, mat);
            }
        }
    }
  
  
    int numberOfEnclaves(vector<vector<int>> &board) {
     int n = board.size(), m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int j = 0; j < m; j++) {

            // first row
            if (!vis[0][j] && board[0][j] == 1) {
                dfs(0, j, vis, board);
            }

            // last row
            if (!vis[n - 1][j] && board[n - 1][j] == 1) {
                dfs(n - 1, j, vis, board);
            }
        }

        for (int i = 0; i < n; i++) {

            // first col
            if (!vis[i][0] && board[i][0] == 1) {
                dfs(i, 0, vis, board);
            }

            // last col
            if (!vis[i][m - 1] && board[i][m - 1] == 1) {
                dfs(i, m - 1, vis, board);
            }
        }
        int cnt = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && board[i][j] == 1) {
                    cnt++;
                }
            }

        return cnt;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    
cout << "~" << "\n";
}
}
// } Driver Code Ends