// User code template

class Solution {
  public:
    vector<int> getFloorAndCeil(int x, vector<int> &arr) {
        // code here
        
       int floor = -1, ceil = -1;
        int n = arr.size();
        int lowerBound = n; // Initially, assume no element >= x

        sort(arr.begin(), arr.end());

        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] >= x) {
                lowerBound = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        // If we found a valid lowerBound
        if (lowerBound != n) {
            ceil = arr[lowerBound];
            floor = (ceil == x) ? ceil : (lowerBound > 0 ? arr[lowerBound - 1] : -1);
        } else {
            // No element >= x, so ceil = -1 and floor is largest element
            floor = arr[n - 1];
            ceil = -1;
        }

        return {floor, ceil};
       
       
       
    
      // return {floor, ceil};
    }
};