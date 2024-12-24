//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxScore(vector<int>& cardPoints, int k) {
         int lsum = 0, rsum = 0, maxSum = 0;
        int n = cardPoints.size();

        for(int i=0 ; i<k ; i++) lsum += cardPoints[i];
        maxSum = lsum;
        
        int r = n - 1;
        for(int i=k-1 ; i>=0 ; i--){
            lsum = lsum - cardPoints[i];
            rsum = rsum + cardPoints[r];
            r--;
            maxSum = max(maxSum, lsum+rsum);
        }
        return maxSum;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Consume the newline character

    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        vector<int> cardPoints;
        while (ss >> num)
            cardPoints.push_back(num);

        int k;
        cin >> k;
        cin.ignore(); // Consume the newline character

        Solution ob;
        cout << ob.maxScore(cardPoints, k) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends