//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool wifiRange(int N, string S, int X){
        // code here
        vector <int> ch(N,0);
        for(int i = 0;i < N;i++)
        {
            if(S[i] == '1')
            {
                int lma = max(0, i - X);
                for(int j = lma;j < i;j++)
                {
                    ch[j] = 1;
                }
                int rma = min(i + X,N - 1);
                for(int j = i;j <=rma;j++)
                {
                    ch[j] = 1;
                }
                ch[i] = 1;
            }
        }
        for(int i = 0;i < N;i++)
        {
            if(ch[i] == 0)
                return false;
        }
        return true;
    }
};

//{ Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N, X;
        string S;
        cin >> N >> X >> S;
        Solution obj;
        cout << obj.wifiRange(N, S, X) << "\n";
    }
}

// } Driver Code Ends