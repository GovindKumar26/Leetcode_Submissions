//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
 vector<int> topologicalSort(vector<vector<int>>& adj, int V) {
       vector<int> topo;
       int indegree[V] = {0};
       
       for(int i=0 ; i<V ; i++){
           for(auto it : adj[i]){
               indegree[it]++;
           }
       }
       
       queue<int>q;
       
       for(int i=0 ; i<V ; i++){
           if(indegree[i]==0){
               q.push(i);
           }
       }
       
       while(!q.empty()){
           int node = q.front();
           q.pop();
           
           topo.push_back(node);
           
           for(auto it : adj[node]){
               indegree[it]--;
               if(indegree[it]==0) q.push(it);
           }
       }
       return topo;
 }
 
  public:
    string findOrder(vector<string> dict, int k) {
        
       int V = k;
       int n = dict.size();
       vector<vector<int>> adj(V);
       
       for(int i=0 ; i<n-1 ; i++){
           string s1 = dict[i];
           string s2 = dict[i+1];
           
           int len = min(s1.size(), s2.size());
           
           for(int ptr=0 ; ptr<len ; ptr++){
               if(s1[ptr]!=s2[ptr]){
                   adj[s1[ptr]-'a'].push_back(s2[ptr]-'a');
                   break;
               }
           }
       }
       
       
       vector<int>topo = topologicalSort(adj, k);
       
       string ans = "";
       for(auto it : topo){
           ans += it+'a';
       }
       
       return ans;
       
       
    }
};

//{ Driver Code Starts.
string order;

bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size())
        return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            a.push_back(number);
        }
        int K;
        cin >> K;
        getchar();
        Solution obj;
        string ans = obj.findOrder(a, K);
        order = "";
        for (int i = 0; i < ans.size(); i++)
            order += ans[i];

        string temp[a.size()];
        std::copy(a.begin(), a.end(), temp);
        sort(temp, temp + a.size(), f);

        bool f = true;
        for (int i = 0; i < a.size(); i++)
            if (a[i] != temp[i])
                f = false;

        if (f)
            cout << "true";
        else
            cout << "false";
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends