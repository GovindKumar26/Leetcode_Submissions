
class Solution {

public:
    int firstOcc(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        
        int first=-1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] == target) {
                first = mid;
                high = mid - 1;
            } else if (nums[mid] > target) {
                high = mid - 1;
            } else
                low = mid + 1;
        }
        return first;
    }

     int lastOcc(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
       
        int last=-1;
        while (low <= high) {
             int mid = (low + high) / 2;
            if (nums[mid] == target) {
                last = mid;
                low = mid + 1;
            } else if (nums[mid] > target) {
                high = mid - 1;
            } else
                low = mid + 1;
        }
        return last;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        // vector<int> v(2, -1);
        // int cnt = 0;
        // int f = -1;
        // for (int i = 0; i < nums.size(); i++) {
        //     if (nums[i] == target) {
        //         cnt++;
        //         if (cnt == 1)
        //             f = i;
        //     }
        // }

        // if (cnt == 0)
        //     return v;
        // int l = f + cnt - 1;
        // v = {f, l};
        // return v;
        // use lowerbound and upper bound for logn

        int first = firstOcc(nums, target);
        if(first==-1) return {-1, -1};

        int last = lastOcc(nums, target);

        return {first, last};

    }
};