//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	
	void dfs(int node, vector<int> adj[], vector<bool> &visited) {
        visited[node] = true;
        for (auto neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited);
            }
        }
    }
	
    //Function to find if the given edge is a bridge in graph.
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        // Step 1: Remove the edge (c, d) from the graph
        auto it = find(adj[c].begin(), adj[c].end(), d);
        if (it != adj[c].end()) adj[c].erase(it);
        
        it = find(adj[d].begin(), adj[d].end(), c);
        if (it != adj[d].end()) adj[d].erase(it);
        
         // Step 2: Check if there is still a path between c and d using DFS
        vector<bool> visited(V, false);
        dfs(c, adj, visited);
        
         // Step 3: Restore the edge (c, d)
        adj[c].push_back(d);
        adj[d].push_back(c);
        
        return !visited[d];
       
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    
cout << "~" << "\n";
}

    return 0;
}


// } Driver Code Ends