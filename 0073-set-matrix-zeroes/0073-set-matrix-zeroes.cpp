class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // int row = matrix.size();
        // int col = matrix[0].size();
        // vector<int> v(col, 0);
        // vector<vector<int>> x(row, v);

        // for (int i = 0; i < row; i++)
        //     for (int j = 0; j < col; j++)
        //         if (matrix[i][j] == 0) {
        //             x[i][j] = 1;
        //         }

        // for (int i = 0; i < row; i++)
        //     for (int j = 0; j < col; j++) {
        //         if (x[i][j] == 1) {
        //             for (int a = 0; a < row; a++) {
        //                 matrix[a][j] = 0;
        //             }
        //             for (int b = 0; b < col; b++) {
        //                 matrix[i][b] = 0;
        //             }
        //         }
        //     }


            // better way
            // int n = matrix.size();
            // int m = matrix[0].size();
            // vector<int>row(n, 0);
            // vector<int>col(m, 0);

            // for(int i=0 ; i<n ; i++){
            //     for(int j=0 ; j<m ; j++){
            //         if(matrix[i][j]==0){
            //             row[i] = 1;
            //             col[j] = 1;
            //         }
            //     }
            // }

            // for(int i=0 ; i<n ; i++){
            //     for(int j=0 ; j<m ; j++){
            //         if(row[i]==1 || col[j]==1){
            //             matrix[i][j] = 0;
            //         }
            //     }
            // }


            //optimal way, in constant space
              int n = matrix.size();
            int m = matrix[0].size();
            int col0 = 1;
            
            for(int i=0 ; i<n ; i++){
                for(int j=0 ; j<m ; j++){
                    if(matrix[i][j]==0){
                        matrix[i][0] = 0;

                        if(j!=0) {
                            matrix[0][j] = 0;
                        }else col0 = 0;
                    }
                }
            }

            for(int i=1 ; i<n ; i++){
                for(int j=1 ; j<m ; j++){
                    if(matrix[i][j]!=0){
                        if(matrix[i][0]==0 || matrix[0][j]==0){
                            matrix[i][j] = 0;
                        }
                    }
                }
            }

            if(matrix[0][0]==0) {
                for(int j=0 ; j<m ; j++) matrix[0][j]=0;
            }

            if(col0==0){
                for(int i=0 ; i<n ; i++) matrix[i][0] = 0;
            }
    }
};