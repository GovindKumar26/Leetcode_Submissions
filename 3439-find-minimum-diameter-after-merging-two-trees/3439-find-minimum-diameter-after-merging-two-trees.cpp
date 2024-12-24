class Solution {
public:

// Function to perform BFS and return the farthest node and its distance
pair<int, int> bfs(int start, const vector<vector<int>>& adj) {
    int n = adj.size();
    vector<int> dist(n, -1); // Distance array to keep track of visited nodes
    queue<int> q;
    
    q.push(start);
    dist[start] = 0;
    
    int farthestNode = start;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        
        for (int neighbor : adj[node]) {
            if (dist[neighbor] == -1) { // If the neighbor is not visited
                dist[neighbor] = dist[node] + 1;
                q.push(neighbor);
                if (dist[neighbor] > dist[farthestNode]) {
                    farthestNode = neighbor;
                }
            }
        }
    }
    
    return {farthestNode, dist[farthestNode]};
}


// Function to calculate the diameter of a tree
int treeDiameter(const vector<vector<int>>& adj) {
    // Step 1: Perform BFS from any arbitrary node (e.g., node 0)
    pair<int, int> firstBFS = bfs(0, adj);
    
    // Step 2: Perform BFS from the farthest node found in the first BFS
    pair<int, int> secondBFS = bfs(firstBFS.first, adj);
    
    // The diameter is the distance found in the second BFS
    return secondBFS.second;
}

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        vector<vector<int>>adj1(edges1.size()+1);
        vector<vector<int>>adj2(edges2.size()+1);

        for(auto it : edges1){
            adj1[it[0]].push_back(it[1]);
            adj1[it[1]].push_back(it[0]);
        } 

        for(auto it : edges2){
            adj2[it[0]].push_back(it[1]);
            adj2[it[1]].push_back(it[0]);
        }

        int d1 = treeDiameter(adj1);
        int d2 = treeDiameter(adj2);

        return max({d1, d2, (d1+1)/2+(d2+1)/2+1});
    }
};