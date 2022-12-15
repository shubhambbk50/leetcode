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
        int required=S*M;
        vector<int>v(S,N);
        for(int i=0;i<S; i++){
            if((i+1)%7 == 0)
                v[i]=0;
        }
        int sum=0,days=0;
        for(int i=0;i<S;i++){
            if(v[i]!=0){
                sum+=v[i];days++;
            }
            if(sum>=required){
                break;
            }
        }
        if(sum<required){
            return -1;
        }
        else
            return days;
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