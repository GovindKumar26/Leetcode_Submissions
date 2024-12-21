class Solution {
public:
    
   // int mod = 1e9 + 7;

    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;
        
        // Build adjacency list
        vector<vector<pair<int, int>>> adj(n);
        for (auto& road : roads) {
            int u = road[0], v = road[1], weight = road[2];
            adj[u].push_back({v, weight});
            adj[v].push_back({u, weight});
        }
        
        // Dijkstra's algorithm
        vector<long long> dist(n, LLONG_MAX);  // Long long to prevent overflow
        vector<long long> ways(n, 0);
        
        // Min-heap for Dijkstra's algorithm
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});  // (distance, node)
        
        while (!pq.empty()) {
            long long d = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            // If this path is not the shortest, skip it
            if (d > dist[node]) continue;
            
            // Explore neighbors
            for (auto& neighbor : adj[node]) {
                int nextNode = neighbor.first;
                int weight = neighbor.second;
                
                // Relax the edge and update distances
                if (dist[node] + weight < dist[nextNode]) {
                    dist[nextNode] = dist[node] + weight;
                    ways[nextNode] = ways[node];  // Reset the count to the count from current node
                    pq.push({dist[nextNode], nextNode});
                }
                // If another shortest path is found, add the number of ways
                else if (dist[node] + weight == dist[nextNode]) {
                    ways[nextNode] = (ways[nextNode] + ways[node]) % MOD;
                }
            }
        }
        
        // Return the number of ways to reach the last node (node n-1)
        return ways[n-1] % MOD;
    }
};