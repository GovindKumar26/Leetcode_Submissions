//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class DisjointSet{
    vector<int> parent, rank, size;
    
    public : 
    
    DisjointSet(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        size.resize(n+1, 1);
        
        for(int i=0 ; i<=n ; i++) parent[i] = i;
    }
    
    int findParent(int node){
        if(node==parent[node]) return node;
        return parent[node] = findParent(parent[node]);
    }
    
    void unionByRank(int u, int v){
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);
        
        if(ulp_v==ulp_u) return;
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        
        else if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    
      void unionBySize(int u, int v){
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);
        
        if(ulp_v==ulp_u) return;
        
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else if(size[ulp_v] < size[ulp_u]){
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
    
    
};

class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        //  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
         
        //  vector<int> vis(V, 0);
         
        //  // wt, node
        //  pq.push({0, 0});
        //  int sum = 0;
         
        //  while(!pq.empty()){
        //      int node = pq.top().second;
        //      int wt = pq.top().first;
        //      pq.pop();
             
        //      if(vis[node]==1) continue;
             
        //      //add it to the mst
        //      sum += wt;
        //      vis[node] = 1;
        //      for(auto it : adj[node]){
        //          int adjNode = it[0];
        //          int edgeW = it[1];
                 
        //          if(!vis[adjNode]) {
        //              pq.push({edgeW, adjNode});
        //          }
        //      }
        //  }
        //  return sum;
        
        
        
        // using dsu (needs edges)
        
        // converting adj to edges
        vector<pair<int, pair<int, int>>> edges;
        
        for(int i=0 ; i<V ; i++){
            for(auto it : adj[i]){
                int adjNode = it[0];
                int wt = it[1];
                int node = i;
                
                edges.push_back({wt, {node, adjNode}});
            }
        }
        
        DisjointSet ds(V);
        sort(edges.begin(), edges.end());
        
        int mstSum = 0;
        
        for(auto it : edges){
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            
            if(ds.findParent(u) != ds.findParent(v)){
                mstSum += wt;
                ds.unionBySize(u, v);
            }
        }
        return mstSum;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }

        Solution obj;
        cout << obj.spanningTree(V, adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends