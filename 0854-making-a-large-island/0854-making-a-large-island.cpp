
class DisjointSet {

public:
    vector<int> parent, rank, size;

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
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n * n);

        // step 1
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 0)
                    continue;
                int dr[] = {-1, 0, 1, 0}, dc[] = {0, 1, 0, -1};
                for (int i = 0; i < 4; i++) {
                    int newR = dr[i] + row;
                    int newC = dc[i] + col;
                    if (newR >= 0 && newR < n && newC >= 0 && newC < n &&
                        grid[newR][newC] == 1) {
                        int nodeNo = row * n + col;
                        int adjNodeNo = newR * n + newC;
                        ds.unionBySize(nodeNo, adjNodeNo);
                    }
                }
            }
        }

        // step 2
        int mx = 0;
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 1)
                    continue;
                int dr[] = {-1, 0, 1, 0}, dc[] = {0, 1, 0, -1};
                set<int> components;

                for (int i = 0; i < 4; i++) {
                    int newR = dr[i] + row;
                    int newC = dc[i] + col;
                    if (newR >= 0 && newR < n && newC >= 0 && newC < n &&
                        grid[newR][newC] == 1) {
                        components.insert(ds.findParent(newR * n + newC));
                    }
                }
                int sizeTotal = 0;
                for (auto it : components) {
                    sizeTotal += ds.size[it];
                }
                mx = max(mx, sizeTotal + 1);
            }
        }

        for (int cellNo = 0; cellNo < n * n; cellNo++) {
            mx = max(mx, ds.size[ds.findParent(cellNo)]);
        }
        return mx;
    }
};