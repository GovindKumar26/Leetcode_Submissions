class Solution {

    bool check(int start, vector<vector<int>>& graph, int color[]) {
        queue<int> q;
        q.push(start);

        color[start] = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto it : graph[node]) {

                if (color[it] == -1) {
                    color[it] = !color[node];
                    q.push(it);
                } else if (color[it] == color[node]) {
                    return false;
                }
            }
        }

        return true;
    }


    bool dfs(int node, vector<vector<int>>& graph, int color[], int col){
        color[node] = col;

        for(auto it : graph[node]){
            if(color[it]==-1){
                if(dfs(it, graph, color, !col)==false) return false;
            }
            else if(color[it]==col){
                return false;
            }
        }
        return true;
    }
    
public:
    bool isBipartite(vector<vector<int>>& graph) {
        // int V = graph.size();
        // int color[V];

        // for (int i = 0; i < V; i++)
        //     color[i] = -1;

        // for (int i = 0; i < V; i++) {
        //     if (color[i] == -1) {
        //         if (check(i, graph, color) == false)
        //             return false;
        //     }
        // }
        // return true;

       // using dfs traversal
         int V = graph.size();
        int color[V];

        for (int i = 0; i < V; i++)
            color[i] = -1;

        for (int i = 0; i < V; i++) {
            if (color[i] == -1) {
                if (dfs(i, graph, color, 0) == false)
                    return false;
            }
        }
        return true;
    }



 
};