//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
  void dfs(int node, vector<vector<int>>& adj, int vis[], vector<int>&dfsVec){
      vis[node] = 1;
      dfsVec.push_back(node);
      
      for(auto it : adj[node]){
          if(vis[it]!=1){
              vis[it] = 1;
              dfs(it, adj, vis, dfsVec);
          }
      }
  }
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(vector<vector<int>>& adj) {
       int size = adj.size();
       int vis[size] = {0};
       int start = 0;
       vector<int>dfsVec;
       
       dfs(start, adj, vis, dfsVec);
       return dfsVec;
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(
            V); // Use vector of vectors instead of array of vectors.

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        Solution obj;
        vector<int> ans = obj.dfsOfGraph(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends