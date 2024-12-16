//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find minimum time required to rot all oranges.
    int orangesRotting(vector<vector<int>>& mat) {
         int n = mat.size(), m = mat[0].size();

        queue<pair<pair<int, int>, int>> q;
        int cntFresh = 0;
        
        // Initialize the queue and the fresh orange count
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 2) {  // Rotten orange
                    q.push({{i, j}, 0});
                } else if (mat[i][j] == 1) {  // Fresh orange
                    cntFresh++;
                }
            }
        }

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        int tm = 0;
        int cnt = 0;

        // Perform BFS
        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();

            tm = max(tm, t);  // Track maximum time

            // Explore 4 neighbors
            for (int i = 0; i < 4; i++) {
                int newRow = r + delRow[i];
                int newCol = c + delCol[i];

                // Check if the new position is valid and a fresh orange
                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m &&
                    mat[newRow][newCol] == 1) {
                    mat[newRow][newCol] = 2;  // Mark as rotten
                    q.push({{newRow, newCol}, t + 1});  // Add to queue
                    cnt++;  // Count how many fresh oranges rot
                }
            }
        }

        // If not all fresh oranges are rotted, return -1
        if (cntFresh != cnt) {
            return -1;
        }

        return tm;  
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        int ans = obj.orangesRotting(mat);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends