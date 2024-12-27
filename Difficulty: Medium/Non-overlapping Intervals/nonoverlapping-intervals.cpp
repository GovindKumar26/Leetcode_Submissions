//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minRemoval(vector<vector<int>> &intervals) {
        int n = intervals.size();

        // Sort intervals by their end times
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int count = 0;   // Count of overlapping intervals
        int lastEnd = INT_MIN; // Initialize the end time of the last included interval

        // Iterate through the sorted intervals
        for (int i = 0; i < n; i++) {
            if (intervals[i][0] >= lastEnd) {
                // Include the current interval
                lastEnd = intervals[i][1];
            } else {
                // Overlapping interval, increment the count
                count++;
            }
        }

        return count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<vector<int>> intervals(N, vector<int>(2));
        for (int i = 0; i < N; i++) {
            cin >> intervals[i][0] >> intervals[i][1];
        }
        Solution obj;
        cout << obj.minRemoval(intervals) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends