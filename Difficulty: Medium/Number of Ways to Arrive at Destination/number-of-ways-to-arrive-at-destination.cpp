//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
    int mod = 1e9 + 7;
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n);

        for(auto it : roads){
            int u = it[0], v = it[1], wt = it[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});

        vector<int> dist(n, INT_MAX); 
        dist[0] = 0;
        vector<int> ways(n, 0);
        ways[0] = 1;


        while(!pq.empty()){
            int node = pq.top().second;
            int dis = pq.top().first;
            pq.pop();

             if (dis > dist[node]) continue;

            for(auto it : adj[node]){
                int edgeW = it.second;
                int adjNode = it.first;

                if(dis+edgeW < dist[adjNode]){
                    dist[adjNode] = dis + edgeW;
                    pq.push({dis+edgeW, adjNode});
                    ways[adjNode] = ways[node];
                }
               else if(dis+edgeW==dist[adjNode]){
                  ways[adjNode] = (ways[adjNode] + ways[node]) % mod;

                }
            }
        }

       return ways[n-1] % mod;

    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    
cout << "~" << "\n";
}

    return 0;
}
// } Driver Code Ends