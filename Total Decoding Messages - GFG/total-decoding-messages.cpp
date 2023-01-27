//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		int CountWays(string str){
		    // Code here
		     const unsigned int M = 1000000007;
		     int n=str.size();

     if(n==0 or str[0]=='0'){

         return 0;

     }

     vector<long long>dp(n+1);

     dp[n]=1;

     if(str[n-1]>'0' and str[n-1]<='9'){

         dp[n-1]=1;

     }else{

         dp[n-1]=0;

     }

     for(int i=n-2;i>=0;i--){

         if(str[i]=='0'){

             dp[i]=0;

         }else

         if(str[i]=='1' or (str[i]=='2' and str[i+1]<='6')){

             dp[i]=(dp[i+1]+dp[i+2])%M;

         }else{

             if(dp[i+1]==0){

                 return 0;

             }

             dp[i]=0+dp[i+1];

         }

     }

     return dp[0];

		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends