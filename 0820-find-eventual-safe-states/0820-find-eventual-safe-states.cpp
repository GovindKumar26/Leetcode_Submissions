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
        // int V = graph.size();

        // vector<int> vis(V, 0);     // Visited vector
        // vector<int> pathVis(V, 0); // Path visited vector
        // vector<int> safeNodes;
        // vector<int> check(V, 0);

        // for (int i = 0; i < V; i++) {
        //     if (!vis[i]) {
        //         dfsCheck(i, graph, vis, pathVis, check);
        //     }
        // }

        // for (int i = 0; i < V; i++) {
        //     if (check[i] == 1)
        //         safeNodes.push_back(i);
        // }
        // return safeNodes;



        // using toposort

        int V = graph.size();
        vector<vector<int>>revGraph(V);
        vector<int>indegree(V, 0);

        for(int i=0 ; i<V ; i++){
            for(auto it : graph[i]){
                revGraph[it].push_back(i);
                indegree[i]++;
            } 
        }

        queue<int>q;
        vector<int>safeNodes;

        for(int i=0 ; i<V ; i++){
            if(indegree[i]==0) {
                q.push(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);

            for(auto it : revGraph[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }

        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
       
    }
};