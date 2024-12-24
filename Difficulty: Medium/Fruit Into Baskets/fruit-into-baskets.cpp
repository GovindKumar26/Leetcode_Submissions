//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int totalFruits(vector<int> &fruits) {
         unordered_map<int, int> mpp;

        int i = 0, j = 0, res = 0;
        
        while(j < fruits.size())
        {

            mpp[fruits[j]]++;
            
            if(mpp.size() <= 2) res = max(res, j-i+1);
            
            else
            {
                mpp[fruits[i]]--;

                if(mpp[fruits[i]] == 0) mpp.erase(fruits[i]);

                i++;
            }

            j++;
        }

        return res; 
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore any newline character left in the buffer
    while (t--) {
        string line;
        getline(cin, line); // Read the entire line of input
        stringstream ss(line);
        vector<int> arr;
        int num;

        // Parse the input line into integers and add to the vector
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        int ans = ob.totalFruits(arr);

        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends