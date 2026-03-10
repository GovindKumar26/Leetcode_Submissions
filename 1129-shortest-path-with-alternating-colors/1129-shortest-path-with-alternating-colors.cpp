class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {

        vector<vector<pair<int,int>>> adj(n);

        for(auto &e : redEdges)
            adj[e[0]].push_back({e[1],0}); // red

        for(auto &e : blueEdges)
            adj[e[0]].push_back({e[1],1}); // blue

        vector<vector<bool>> vis(n, vector<bool>(2,false));
        vector<int> dist(n, -1);

        queue<tuple<int,int,int>> q;
        q.push({0,-1,0}); // node, last_color, distance

        while(!q.empty()){

            auto [node, lastColor, d] = q.front();
            q.pop();

            if(dist[node] == -1)
                dist[node] = d;

            for(auto &[next, color] : adj[node]){

                if(color != lastColor && !vis[next][color]){

                    vis[next][color] = true;
                    q.push({next, color, d+1});
                }
            }
        }

        return dist;
    }
};