

class DisjointSet {
    vector<int> parent, rank, size;

public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);

        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int findParent(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findParent(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);

        if (ulp_v == ulp_u)
            return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }

        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        } else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);

        if (ulp_v == ulp_u)
            return;

        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else if (size[ulp_v] < size[ulp_u]) {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

    class Solution {
    public:
        void dfs(int node, vector<vector<int>>& adj, vector<int>& vis) {
            vis[node] = 1;

            for (auto it : adj[node]) {
                if (vis[it] != 1) {
                    vis[it] = 1;
                    dfs(it, adj, vis);
                }
            }
        }

        int findCircleNum(vector<vector<int>>& isConnected) {

            // int n = isConnected.size();
            // vector<vector<int>> adj(n);
            // for (int i = 0; i < n; i++) {
            //     for (int j = 0; j < n; j++) {
            //         if (isConnected[i][j] == 1 && i != j) {
            //             adj[i].push_back(j);
            //             adj[j].push_back(i);
            //         }
            //     }
            // }

            // vector<int> vis(n, 0);
            // int cnt = 0;

            // for (int i = 0; i < n; i++) {
            //     if (vis[i] != 1) {
            //         cnt++;
            //         dfs(i, adj, vis);
            //     }
            // }
            // return cnt;

            // using dsu
            int V = isConnected.size();
            DisjointSet ds(V);

            for (int i = 0; i < V; i++) {
                for (int j = 0; j < V; j++) {
                    if (isConnected[i][j] == 1) {
                        ds.unionBySize(i, j);
                    }
                }
            }

            int cnt = 0;
            for (int i = 0; i < V; i++) {
                if (i == ds.findParent(i))
                    cnt++;
            }

            return cnt;
        }
    };