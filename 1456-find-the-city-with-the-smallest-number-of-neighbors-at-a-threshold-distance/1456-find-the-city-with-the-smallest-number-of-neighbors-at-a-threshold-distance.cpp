class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        vector<vector<int>> dist(n, vector<int>(n, 1e8)); // Initialize the distance matrix with the
                                     // graph's weights

        for (auto it : edges) {
            int u = it[0], v = it[1], wt = it[2];
            dist[u][v] = wt;
            dist[v][u] = wt;
        }

        for (int i = 0; i < n; i++)
            dist[i][i] = 0;

        // Floyd-Warshall algorithm
        for (int k = 0; k < n; k++) {         // Intermediate node
            for (int i = 0; i < n; i++) {     // Source node
                for (int j = 0; j < n; j++) { // Destination node
                    // If node k is on the shortest path from i to j, update
                    // dist[i][j]
                    if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX)
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        int minCount = n + 1;
        int ansNode = -1;

        for (int i = 0; i < n; i++) {
            int count = -1;
            for (int j = 0; j < n; j++) {
                if (dist[i][j] <= distanceThreshold) {
                    count++;
                }
            }
            if (count < minCount || (count == minCount && i > ansNode)) {
                minCount = count;
                ansNode = i;
            }
        }
        return ansNode;
    }
};