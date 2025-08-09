class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        
       int xr = 0;
       int n = arr.size();
       
       for(int i=0 ; i<arr.size() ; i++) {
           xr = xr^arr[i]^(i+1);
           
       }
       
       
       int bitNo=0;
       while(1) {
           if(xr & (1<<bitNo)) {
               break;
           }
           bitNo++;
       }
       
       int zero=0, one=0;
       
         // Step 3: Divide arr elements into two groups
        for (int i = 0; i < n; i++) {
            if ((arr[i] & (1 << bitNo)) == 0)
                zero ^= arr[i];
            else
                one ^= arr[i];
        }
        
        
       for(int i=1 ; i<=n ; i++) {
          if((i & (1<<bitNo))==0) {
              zero = zero^i;
          }
          else {
              one = one^i;
          }
       }
       
       int cnt=0;
       for(int i=0 ; i<arr.size() ; i++) {
           if(arr[i]==zero) cnt++;
       } 
    
       if(cnt==2) return {zero, one};
        return {one, zero};
        
    }
};