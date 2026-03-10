class Solution {
public:

    int dfs(int node, vector<vector<int>>& adj, vector<int>& vis) {

        vis[node] = 1;
        int count = 1;

        for(int nei : adj[node]) {
            if(!vis[nei]) {
                count += dfs(nei, adj, vis);
            }
        }

        return count;
    }

    int maximumDetonation(vector<vector<int>>& bombs) {

        int n = bombs.size();

        vector<vector<int>> adj(n);

        // build graph
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){

                if(i==j) continue;

                long long dx = bombs[i][0] - bombs[j][0];
                long long dy = bombs[i][1] - bombs[j][1];
                long long r  = bombs[i][2];

                if(dx*dx + dy*dy <= r*r) {
                    adj[i].push_back(j);
                }
            }
        }

        int ans = 0;

        for(int i=0;i<n;i++) {

            vector<int> vis(n,0);

            ans = max(ans, dfs(i, adj, vis));
        }

        return ans;
    }
};