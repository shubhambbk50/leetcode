//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countWaystoDivide(int N, int K) {
        // Code here
        int dp[N + 1][K + 1];
        for (int i = 0; i <= N; i++)
            for (int j = 0; j <= K; j++)
                dp[i][j] = 0;
        dp[0][0] = 1;
        for (int val = 1; val <= N; val++)
        {
            for (int i = val; i <= N; i++)
            {
                for (int j = 1; j <= K; j++)
                {
                    dp[i][j] += (dp[i - val][j - 1]);
                }
            }
        }
        return dp[N][K];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        Solution ob;
        cout << ob.countWaystoDivide(N, K) << endl;
    }
}
// } Driver Code Ends