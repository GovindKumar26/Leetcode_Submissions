//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
         int n = start.size();

        // Combine start and end times into a vector of pairs
        vector<pair<int, int>> meetings;
        for (int i = 0; i < n; i++) {
            meetings.push_back({end[i], start[i]});
        }

        // Sort meetings by their end times
        sort(meetings.begin(), meetings.end());

        int count = 0;   // Count of meetings
        int lastEnd = -1; // Track the end time of the last selected meeting

        // Iterate through the sorted meetings
        for (int i = 0; i < n; i++) {
            if (meetings[i].second > lastEnd) { // If the meeting starts after the last one ends
                count++;
                lastEnd = meetings[i].first; // Update the last meeting's end time
            }
        }

        return count;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> start;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            start.push_back(num);
        }

        vector<int> end;
        getline(cin, input);
        stringstream s22(input);
        while (s22 >> num) {
            end.push_back(num);
        }

        Solution ob;
        int ans = ob.maxMeetings(start, end);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends