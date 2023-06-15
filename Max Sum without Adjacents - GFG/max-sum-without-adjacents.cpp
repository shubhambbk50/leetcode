//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
    int f(int *a, int n, int *dp){
        if(n == 0){
	       return a[0]; 
	    }
	    if(n < 0){
	        return 0;
	    }
	    
	    if(dp[n] !=0 ) return dp[n];
	    
	    int pick = a[n] + f(a, n - 2, dp); dp[n] = pick;
	    int notpick = 0 + f(a, n - 1, dp);
	    
	    dp[n] = max(pick, notpick);
	    
	    return dp[n];
    }
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *a, int n) {
	    // code here
	    int dp[n+1] = {0};
	    return f(a, n - 1, dp);
	    
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends