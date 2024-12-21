//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges, int distanceThreshold) {
       
    vector<vector<int>> dist(n, vector<int>(n, 1e8)); // Initialize the distance matrix with the graph's weights

    for(auto it : edges){
        int u = it[0], v = it[1], wt = it[2];
        dist[u][v] = wt;
        dist[v][u] = wt;
    }
    
    for(int i=0 ; i<n ; i++) dist[i][i] = 0;
    
    // Floyd-Warshall algorithm
    for (int k = 0; k < n; k++) {            // Intermediate node
        for (int i = 0; i < n; i++) {        // Source node
            for (int j = 0; j < n; j++) {    // Destination node
                // If node k is on the shortest path from i to j, update dist[i][j]
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    
    int minCount = n+1;
    int ansNode = -1;
    
    for(int i=0 ; i<n ; i++){
         int count = -1;
        for(int j=0 ; j<n ; j++){
            if(dist[i][j]<=distanceThreshold){
                count++;
            }
        }
        if(count < minCount || (count == minCount && i > ansNode)){
                minCount = count;
                ansNode = i;
            }
    }
    return ansNode;
    
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;
        // n--;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    
cout << "~" << "\n";
}
}

// } Driver Code Ends