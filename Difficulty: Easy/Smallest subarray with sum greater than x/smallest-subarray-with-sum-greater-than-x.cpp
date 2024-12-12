//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int smallestSubWithSum(int x, vector<int>& arr) {
           int currSum = 0, res = INT_MAX;  // Use INT_MAX to represent a large number
        int start = 0;
        
        // Traverse the array
        for (int end = 0; end < arr.size(); ++end) {
            currSum += arr[end];
            
            // Try to minimize the subarray when currSum is >= target
            while (currSum > x) {
                res = min(res, end - start + 1);  // Update result
                currSum -= arr[start++];         // Shrink window from the left
            }
        }
        
        // If res wasn't updated, return 0 as no valid subarray was found
        return (res == INT_MAX) ? 0 : res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t

    while (t--) {
        vector<int> arr;
        int x;

        cin >> x;
        cin.ignore(); // Ignore the newline character after x

        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution obj;
        cout << obj.smallestSubWithSum(x, arr) << "\n~\n";
    }

    return 0;
}
// } Driver Code Ends