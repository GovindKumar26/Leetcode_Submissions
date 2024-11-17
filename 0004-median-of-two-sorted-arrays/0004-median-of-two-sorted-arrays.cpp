class Solution {
    vector<int> sortedAdd(vector<int> nums1, vector<int> nums2) {
        int i = 0, j = 0;
        int k = 0;
        vector<int> v(nums1.size() + nums2.size());
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] >= nums2[j])
                v[k++] = nums2[j++];
            else
                v[k++] = nums1[i++];
        }
        while (i < nums1.size())
            v[k++] = nums1[i++];
        while (j < nums2.size())
            v[k++] = nums2[j++];

        return v;
    }

public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v = sortedAdd(nums1, nums2);
        int n = v.size();

        if (n & 1) {
            return v[n / 2];
        } else
            return (1.0) * (v[n / 2] + v[n / 2 - 1]) / 2;
    }
};