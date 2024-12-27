//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxChildren(vector<int> &greed, vector<int> &cookie) {
        int cookiesNums = cookie.size();
        if(cookiesNums == 0)  return 0;
        sort(greed.begin(), greed.end());
        sort(cookie.begin(), cookie.end());

        int maxNum = 0;
        int cookieIndex = cookiesNums - 1;
        int childIndex = greed.size() - 1;
        while(cookieIndex >= 0 && childIndex >=0){
            if(cookie[cookieIndex] >= greed[childIndex]){
                maxNum++;
                cookieIndex--;
                childIndex--;
            }
            else{
                childIndex--;
            }
        }
        return maxNum;
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
        vector<int> greed;
        int num;
        while (ss >> num)
            greed.push_back(num);
        getline(cin, input);
        ss.clear();
        vector<int> cookie;
        ss.str(input);
        while (ss >> num)
            cookie.push_back(num);

        Solution obj;
        cout << obj.maxChildren(greed, cookie) << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends