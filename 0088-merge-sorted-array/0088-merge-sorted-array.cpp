class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0, j = 0, k = m;

        while (i < k && j < n) {

            if (nums1[i] > nums2[j]) {

                for (int a = k; a > i; a--) {
                    nums1[a] = nums1[a - 1];
                }
                k++;
                nums1[i++] = nums2[j++];
                // nums1[k] = nums1[i];k++;
                // nums1[i++] = nums2[j++];
            } 

            else
                i++;
        }
        while (j < n)
            nums1[i++] = nums2[j++];
    }
};