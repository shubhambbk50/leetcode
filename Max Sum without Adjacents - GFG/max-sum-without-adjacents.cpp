//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	     vector<int>dp(n+3,-1);

     dp[n]=0;

     dp[n+1]=0;

     dp[n+2]=0;

     for(int i=n-1;i>=0;i--){

        int a=dp[i+2]+arr[i];

        int b=dp[i+3]+arr[i];

        dp[i]=max(a,b);

     }

     return max(dp[0],dp[1]);
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