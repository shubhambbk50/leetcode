//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int inSequence(int a, int b, int c){
        // code here
        int sum=0;

        if(a==b)

        return 1;

        if(a!=b&&c==0)

        {

            return 0;

        }

        sum=((b-a)/c);

        if(sum<0)

        return 0;

        if((b-a)%c==0)

       return 1;

       else

       return 0;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int A, B, C;
        cin>>A>>B>>C;
        
        Solution ob;
        cout<<ob.inSequence(A, B, C)<<endl;
    }
    return 0;
}
// } Driver Code Ends