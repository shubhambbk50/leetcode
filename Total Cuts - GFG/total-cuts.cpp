//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
public:
    int totalCuts(int N,int K,vector<int> &a){
        // Code here
          vector<int>largest;
          vector<int>smallest;
          int lar=INT_MIN;
          for(int i=0;i<N-1;i++){
              if(a[i]>lar){
                  lar=a[i];
              }
              largest.push_back(lar);
          }
          int sma=INT_MAX;
          for(int i=N-1;i>0;i--){
              if(a[i]<sma){
                  sma=a[i];
              }
              smallest.push_back(sma);
          }
          reverse(smallest.begin(),smallest.end());
          int ind=0,i;
          for( i=0;i<largest.size();i++){
              if(largest[i]+smallest[i]>=K){
                  ind=i;
                  break;
              }
          }
          if(i==largest.size()){
              return 0;
          }
          return largest.size()-ind;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N,K;
        cin>>N>>K;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        Solution ob;
        cout<<ob.totalCuts(N,K,A)<<endl;
    }
    return 0;
}
// } Driver Code Ends