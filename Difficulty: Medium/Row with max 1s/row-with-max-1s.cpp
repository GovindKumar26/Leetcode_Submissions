// User function template for C++
class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        int res = -1;
        int index = INT_MAX;
        for(int i=0 ; i<arr.size() ; i++) {
            
            if(index > lower_bound(arr[i].begin(), arr[i].end(), 1) - arr[i].begin()) {
                index = lower_bound(arr[i].begin(), arr[i].end(), 1)- arr[i].begin();
                res = i;
            }
        }
        
        return res;
    }
};