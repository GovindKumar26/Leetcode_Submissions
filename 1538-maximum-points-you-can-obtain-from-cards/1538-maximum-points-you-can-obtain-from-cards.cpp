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