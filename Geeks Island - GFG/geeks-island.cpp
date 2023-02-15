//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
   int water_flow(vector<vector<int>> &mat,int n,int m){

    bool in[n][m];

    memset(in,false,sizeof(in));

    queue<pair<int,int>> q;

     for(int i=0;i<n;i++){ in[i][0]=true; q.push({i,0});}

     for(int i=0;i<m;i++){ in[0][i]=true; q.push({0,i});}

     while(!q.empty())

     {

        auto node=q.front();

        q.pop();

        int r=node.first;

        int c=node.second;

        if(r<n-1 && in[r+1][c]==false && mat[r+1][c]>=mat[r][c])

        {

            in[r+1][c]=true; q.push({r+1,c});

        }

         if(c<m-1 && in[r][c+1]==false && mat[r][c+1]>=mat[r][c])

        {

            in[r][c+1]=true; q.push({r,c+1});

        }

         if(r>0 && in[r-1][c]==false && mat[r-1][c]>=mat[r][c])

        {

            in[r-1][c]=true; q.push({r-1,c});

        }

         if(c>0 && in[r][c-1]==false && mat[r][c-1]>=mat[r][c])

        {

            in[r][c-1]=true; q.push({r,c-1});

        }

     }

     bool ar[n][m];

     memset(ar,false,sizeof(ar));

      for(int i=0;i<n;i++){q.push({i,m-1}); ar[i][m-1]=true;}

      for(int i=0;i<m;i++){q.push({n-1,i});ar[n-1][i]=true;}

      while(!q.empty())

      {

        auto node=q.front();

        q.pop();

        int r=node.first;

        int c=node.second;

        if(r<n-1 && ar[r+1][c]==false && mat[r+1][c]>=mat[r][c])

        {

            ar[r+1][c]=true; q.push({r+1,c});

        }

         if(c<m-1 && ar[r][c+1]==false && mat[r][c+1]>=mat[r][c])

        {

            ar[r][c+1]=true; q.push({r,c+1});

        }

         if(r>0 && ar[r-1][c]==false && mat[r-1][c]>=mat[r][c])

        {

            ar[r-1][c]=true; q.push({r-1,c});

        }

         if(c>0 && ar[r][c-1]==false && mat[r][c-1]>=mat[r][c])

        {

            ar[r][c-1]=true; q.push({r,c-1});

        }

      }

      int ans=0;

      for(int i=0;i<n;i++)

      {

          for(int j=0;j<m;j++)

          {

              if(ar[i][j]==true && in[i][j]==true) ans++;

          }

      }

      return ans;

    }
};



//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin>>mat[i][j];
            }
        }
        Solution ob;
        cout << ob.water_flow(mat, n, m) << endl;
        
    }
}


// } Driver Code Ends