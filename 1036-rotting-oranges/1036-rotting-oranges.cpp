class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        queue<pair<pair<int, int>, int>> q;
        int cntFresh = 0;
        
        // Initialize the queue and the fresh orange count
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {  // Rotten orange
                    q.push({{i, j}, 0});
                } else if (grid[i][j] == 1) {  // Fresh orange
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
                    grid[newRow][newCol] == 1) {
                    grid[newRow][newCol] = 2;  // Mark as rotten
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