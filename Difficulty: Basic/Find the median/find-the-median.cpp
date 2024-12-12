//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int findMedian(vector<int> &arr) {
       sort(arr.begin(), arr.end());
        
        // Step 2: Find the median
        int n = arr.size();
        if (n % 2 == 1) {
            // If odd, return the middle element
            return arr[n / 2];
        } else {
            // If even, return the average of the two middle elements
            return (arr[n / 2 - 1] + arr[n / 2]) / 2;
    }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        vector<int> arr;
        while (ss >> num)
            arr.push_back(num);

        Solution ob;
        cout << ob.findMedian(arr) << endl;
    }
}

// } Driver Code Ends