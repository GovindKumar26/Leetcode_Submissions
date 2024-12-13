class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        int rows = grid.size();
        int cols = grid[0].size();

        // Boundary and water checks
        if (i < 0 || j < 0 || i >= rows || j >= cols || grid[i][j] == '0') {
            return;
        }

        // Mark the current cell as visited (set to '0')
        grid[i][j] = '0';

        // Explore the 4 possible directions: up, down, left, right
        dfs(grid, i - 1, j); // Up
        dfs(grid, i + 1, j); // Down
        dfs(grid, i, j - 1); // Left
        dfs(grid, i, j + 1); // Right
    }

    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        if (rows == 0)
            return 0; // Edge case: empty grid
        int cols = grid[0].size();

        int count = 0;

        // Traverse the grid
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                // Start a DFS if we find a '1'
                if (grid[i][j] == '1') {
                    count++;         // Found an island
                    dfs(grid, i, j); // Perform DFS to mark the entire island
                }
            }
        }

        return count; // Total number of islands
    }
};