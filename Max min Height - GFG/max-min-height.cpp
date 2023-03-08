//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
        long long int maximizeMinHeight(int n,int k,int w,vector <int> &a)
        {
            // code here
             long long int l=1,r=1e10,ans=0;int b[n];

           while(l<=r)

           {

               long long int m=(l+r)/2;memset(b,0,sizeof(b));long long int sum=0,d=0;

               for(int i=0;i<n;i++)

               {

                sum-=b[i];

                long long int y=a[i]+sum;

                if(y<m)

                {

                    d+=m-y;sum+=m-y;if(i+w<n)b[i+w]+=m-y;

                }

                if(d>k)

                break;

               }

               if(d>k)

               r=m-1;

               else if(d<=k)

               {

                 ans=m;l=m+1;  

               }

           }

           return ans;

   
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k,w;
        cin>>n>>k>>w;
        vector <int> a(n);
        for(auto &j:a)
            cin>>j;
        Solution s;
        cout<<s.maximizeMinHeight(n,k,w,a)<<endl;
    }
    return 0;
}
// } Driver Code Ends