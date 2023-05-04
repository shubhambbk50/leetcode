//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<vector<int>> dp;
  
    int binarySearch(int i, int j,int end, vector<vector<int>> &ranges){
        int res=ranges.size();
        while(i<=j){
            int mid=(i+j)/2;
            if(ranges[mid][0]>=end){
                res=mid;
                j=mid-1;
            }else{
                i=mid+1;
            }
        }
        return res;
    }

 


    int solve(int i, int rem, vector<vector<int>> &ranges){
        if(i==ranges.size() || rem==0) return 0;
        if(dp[i][rem]!=-1) return dp[i][rem];
        int notTake=solve(i+1, rem, ranges);
        int take=ranges[i][2];
        int ind=binarySearch(i+1, ranges.size()-1, ranges[i][1], ranges);
        take+=solve(ind, rem-1, ranges);
        return dp[i][rem]=max(take, notTake);
    }

 


    int maxCoins(int n,vector<vector<int>> &ranges){
        // Code here
        sort(ranges.begin(), ranges.end());
        dp=vector<vector<int>>(ranges.size(), vector<int> (3, -1));
        
        return solve(0, 2, ranges);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>> a(n,vector<int>(3));
        for(int i=0;i<n;i++){
            cin>>a[i][0]>>a[i][1]>>a[i][2];
        }
        Solution ob;
        cout<<ob.maxCoins(n,a)<<endl;
    }
    return 0;
}
// } Driver Code Ends