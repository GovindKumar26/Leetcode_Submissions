class Solution {
public:
    bool dfsCheck(int node, vector<vector<int>>& adj, vector<int> &vis,
                  vector<int> &pathVis, vector<int> &check) {
        vis[node] = 1;
        pathVis[node] = 1;

        for (auto it : adj[node]) {
            if (!vis[it]) {
                if (dfsCheck(it, adj, vis, pathVis, check) == true) {
                    check[node] = 0;
                    return true;
                }
            } else if (pathVis[it]) {
                check[node] = 0;
                return true;
            }
        }
        check[node] = 1;
        pathVis[node] = 0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();

        vector<int> vis(V, 0);     // Visited vector
        vector<int> pathVis(V, 0); // Path visited vector
        vector<int> safeNodes;
        vector<int> check(V, 0);

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfsCheck(i, graph, vis, pathVis, check);
            }
        }

        for (int i = 0; i < V; i++) {
            if (check[i] == 1)
                safeNodes.push_back(i);
        }
        return safeNodes;
    }
};