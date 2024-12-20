//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
     int n = grid.size(), m = grid[0].size();
    const int INF = numeric_limits<int>::max();

    // Directions for moving in 4 directions (up, down, left, right)
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    // Check if source or destination is blocked
    if (grid[source.first][source.second] == 0 || grid[destination.first][destination.second] == 0) {
        return -1;
    }

    // Min-heap for Dijkstra's algorithm
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;

    // Distance matrix to store the shortest path cost to each cell
    vector<vector<int>> dist(n, vector<int>(m, INF));

    // Initialize source
    dist[source.first][source.second] = 0; // Cost starts at 0 for source
    pq.push({0, source});

    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();

        int currentCost = top.first;
        int x = top.second.first, y = top.second.second;

        // If we reach the destination, return the cost
        if (x == destination.first && y == destination.second) return currentCost;

        // Skip if this state is outdated
        if (currentCost > dist[x][y]) continue;

        // Explore neighbors
        for (const auto& dir : directions) {
            int nx = x + dir.first, ny = y + dir.second;

            // Check bounds and traversability
            if (nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] == 1) {
                int newCost = currentCost + 1; // Each step has a cost of 1
                if (newCost < dist[nx][ny]) {
                    dist[nx][ny] = newCost;
                    pq.push({newCost, {nx, ny}});
                }
            }
        }
    }

    // If we exhaust the priority queue without reaching the destination
    return -1;
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

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    
cout << "~" << "\n";
}
}

// } Driver Code Ends