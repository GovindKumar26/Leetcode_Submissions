class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
         int n = intervals.size();

        // Combine start and end times into a vector of pairs
        vector<pair<int, int>> meetings;
        for (int i = 0; i < n; i++) {
            meetings.push_back({intervals[i][1], intervals[i][0]});
        }

        // Sort meetings by their end times
        sort(meetings.begin(), meetings.end());

        int count = 1;   // Count of meetings
        int lastEnd = meetings[0].first; // Track the end time of the last selected meeting

        // Iterate through the sorted meetings
        for (int i = 1; i < n; i++) {
            if (meetings[i].second >= lastEnd) { // If the meeting starts after the last one ends
                count++;
                lastEnd = meetings[i].first; // Update the last meeting's end time
            }
        }

        return n - count;
    }
};