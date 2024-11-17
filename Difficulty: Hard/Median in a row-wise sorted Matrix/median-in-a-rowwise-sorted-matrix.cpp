//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:

       // Helper function to count the number of elements <= mid in a row
    int countLessEqual(const std::vector<int>& row, int mid) {
        return std::upper_bound(row.begin(), row.end(), mid) - row.begin();
    }

    int median(vector<vector<int>> &matrix, int R, int C){
   

        // Find the minimum and maximum elements in the matrix
        int min = matrix[0][0];
        int max = matrix[0][C - 1];
        for (int i = 1; i < R; i++) {
            if (matrix[i][0] < min) min = matrix[i][0];
            if (matrix[i][C - 1] > max) max = matrix[i][C - 1];
        }

        // The position of the median in the sorted list
        int desiredCount = (R * C) / 2 + 1;

        // Binary search between min and max
        while (min < max) {
            int mid = min + (max - min) / 2;
            int count = 0;

            // Count the number of elements <= mid across all rows
            for (int i = 0; i < R; i++) {
                count += countLessEqual(matrix[i], mid);
            }

            // Adjust the search range based on the count
            if (count < desiredCount) {
                min = mid + 1;
            } else {
                max = mid;
            }
        }

        // The min value at the end of the loop will be the median
        return min;       
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends