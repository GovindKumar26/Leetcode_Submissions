class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();

        // vector<int>left(n);
        // left[0] = 1;
        // vector<int>right(n);
        // right[n-1] = 1;

        // for(int i=1 ; i<n ; i++){
        //     if(ratings[i] > ratings[i-1]){
        //         left[i] = left[i-1] + 1;
        //     } else{
        //         left[i] = 1;
        //     }
        // }

        
        // for(int i=n-2 ; i>=0 ; i--){
        //     if(ratings[i] > ratings[i+1]){
        //         right[i] = right[i+1] + 1;
        //     } else{
        //         right[i] = 1;
        //     }
        // }
        // int sum = 0;
        // for(int i=0 ; i<n ; i++){
        //     sum += max(right[i], left[i]);
        // }

        // return sum;

        // slope concept
        int i = 1, sum = 1;
        while(i<n){
            if(ratings[i]==ratings[i-1]){
                sum++; i++; continue;
            }
            int peak = 1;
            while(i<n && ratings[i] > ratings[i-1]){
                peak += 1; sum += peak; i++;
            }

            int down = 1;
            while(i<n && ratings[i-1] > ratings[i]){
                sum += down; down++; i++;
            }

            if(down > peak) {
                sum += down-peak;
            }
        }
        return sum;
    }
};