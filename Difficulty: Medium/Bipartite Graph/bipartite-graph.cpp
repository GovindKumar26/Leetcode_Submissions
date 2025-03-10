//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isBipartite(vector<vector<int>>& adj) {
       queue<int>q;
       q.push(0);
       int V = adj.size();
       int color[V];
       
       for(int i=0 ; i<V ; i++) color[i] = -1;
       color[0] = 0;
       
       while(!q.empty()){
           int node = q.front();
           q.pop();
           
           for(auto it : adj[node]){
               
               if(color[it]==-1){
                   color[it] = !color[node];
                   q.push(it);
               } else if(color[it]==color[node]){
                   return false;
               }
           }
       }
       
       return true;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isBipartite(adj);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends