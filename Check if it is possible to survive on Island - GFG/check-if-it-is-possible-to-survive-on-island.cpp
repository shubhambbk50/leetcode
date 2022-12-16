//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minimumDays(int S, int N, int M){
        // code here
        int totalRequiredFood = M*S;
        int noOfDaysShopIsAvailable = S-S/7;
        int totalAvailableFood = N*noOfDaysShopIsAvailable;
        
        if(totalRequiredFood > totalAvailableFood){
            return -1;
        }
        
        //return ceil(totalRequiredFood/(float)N);
        return ceil(totalRequiredFood/(1.0*N));
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int S, N, M;
        cin>> S >> N >> M;
        
        Solution ob;
        cout<<ob.minimumDays(S, N, M)<<endl;
    }
    return 0;
}
// } Driver Code Ends