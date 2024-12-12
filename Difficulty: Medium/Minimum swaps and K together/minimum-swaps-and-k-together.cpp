//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Final function implementation
class Solution {
  public:
    int minSwap(vector<int>& arr, int k) {
         int n = arr.size();

        // Step 1: Count elements ≤ k
        int count = 0;
        for (int num : arr) {
            if (num <= k) {
                count++;
            }
        }

        // If no elements are ≤ k, no swaps are needed
        if (count == 0) return 0;

        // Step 2: Find the initial "bad" count in the first window
        int bad = 0;
        for (int i = 0; i < count; i++) {
            if (arr[i] > k) {
                bad++;
            }
        }

        // Step 3: Slide the window and update the "bad" count
        int minSwaps = bad;
        for (int i = 0, j = count; j < n; i++, j++) {
            // Remove the effect of the outgoing element
            if (arr[i] > k) {
                bad--;
            }

            // Add the effect of the incoming element
            if (arr[j] > k) {
                bad++;
            }

            // Update the minimum swaps
            minSwaps = std::min(minSwaps, bad);
        }

        return minSwaps;
    }
};


//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.minSwap(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends