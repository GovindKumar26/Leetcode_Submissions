//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

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
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        DisjointSet ds(n*m);
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cnt = 0;
        
        vector<int>ans;
        
        for(auto it : operators){
            int row = it[0], col = it[1];
            if(vis[row][col]==1){
                ans.push_back(cnt);
                continue;
            }
            vis[row][col] = 1;
            cnt++;
            vector<int> dr = {-1, 0, 1, 0}, dc = {0, 1, 0, -1};
            for(int i=0 ; i<4 ; i++){
                int adjR = dr[i] + row;
                int adjC = dc[i] + col;
                if(adjC>=0 && adjC<m && adjR>=0 && adjR<n){
                    if(vis[adjR][adjC]==1){
                        int nodeNo = m*row + col;
                        int adjNodeNo = m*adjR + adjC;
                        if(ds.findParent(nodeNo)!=ds.findParent(adjNodeNo)){
                            cnt--;
                            ds.unionBySize(nodeNo, adjNodeNo);
                        }
                    }
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    
cout << "~" << "\n";
}
}

// } Driver Code Ends