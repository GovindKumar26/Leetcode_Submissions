class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int pivot = 0;
        
        for(int i=0 ; i<arr.size()-1;  i++) {
            if(arr[i]>arr[i+1]) {
                pivot = i+1;
                break;
            }
        }
        return pivot;
    }
};
