//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        map<long long, int>prefixSumMap;
        long long sum=0;
        int maxLen=0;

        for(int i=0 ; i<N ; i++){
            sum = sum + A[i];
            if(sum==K){
                maxLen = max(maxLen, i+1);
            }
            long long rem = sum - K;
            if(prefixSumMap.find(rem)!=prefixSumMap.end()){
                int len = i - prefixSumMap[rem];
                maxLen = max(maxLen, len);
            }
            if(prefixSumMap.find(sum)==prefixSumMap.end()){
                prefixSumMap[sum] = i;
            }
        }
        return maxLen;

    }
    

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends