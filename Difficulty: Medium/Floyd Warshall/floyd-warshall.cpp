//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    void shortestDistance(vector<vector<int>>& mat) {
         int n = mat.size();

    // Replace -1 with a large number to represent infinity (no direct path)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == -1 && i != j) {
                mat[i][j] = INT_MAX;
            }
        }
    }

    // Floyd-Warshall algorithm
    for (int k = 0; k < n; k++) {            // Intermediate node
        for (int i = 0; i < n; i++) {        // Source node
            for (int j = 0; j < n; j++) {    // Destination node
                // Check if a path through 'k' exists
                if (mat[i][k] != INT_MAX && mat[k][j] != INT_MAX) {
                    mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
                }
            }
        }
    }

    // Replace INT_MAX back to -1 to indicate no path
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == INT_MAX) {
                mat[i][j] = -1;
            }
        }
    }
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<vector<int>> matrix(n, vector<int>(n, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }
        Solution obj;
        obj.shortestDistance(matrix);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends