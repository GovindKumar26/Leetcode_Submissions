class Solution {
public:

    int largestHist(vector<int>&heights) {
          int n = heights.size();
        stack<int> st;  // stores indices
        int maxArea = 0;

        for (int i = 0; i <= n; i++) {
            int currHeight = (i == n ? 0 : heights[i]);

            // When current bar is smaller than the top, process the stack
            while (!st.empty() && currHeight < heights[st.top()]) {
                int height = heights[st.top()];
                st.pop();

                int right = i;
                int left = st.empty() ? -1 : st.top();
                int width = right - left - 1;

                maxArea = max(maxArea, height * width);
            }
            st.push(i);
        }
        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> pSum(n, vector<int>(m, 0));

        for(int j=0 ; j<m ; j++){
            int sum = 0;
            for(int i=0 ; i<n ; i++){
                sum += matrix[i][j]-'0';
                if(matrix[i][j]=='0') sum = 0;
                pSum[i][j] = sum;
            } 
        }

        int ans = 0;

        for(int i=0 ; i<n ; i++) {
            ans = max(ans, largestHist(pSum[i]));
        }

        return ans;
    }
};