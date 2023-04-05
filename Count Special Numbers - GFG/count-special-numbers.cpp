//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countSpecialNumbers(int N, vector<int> arr) {
        // Code here
          int mx=*max_element(arr.begin(),arr.end())+1;
        vector<bool>sieve(mx,0);
        sort(arr.begin(),arr.end());
        int ans=0;
        for(int i=0;i<N;i++){
            if(arr[i]==1)return arr[i]==arr[i+1]?N:N-1;
            if(!sieve[arr[i]]){
                if(i<N-1 && arr[i]==arr[i+1])ans++;
                for(int j=arr[i];j<mx;j+=arr[i])sieve[j]=1;
            }
            else ans++;
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.countSpecialNumbers(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends