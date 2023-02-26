//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(int vertex,vector<vector<int>>& adj,int val,int &flag, vector<int> &visited,int &cv)

    {

        visited[vertex]=true;

        cv++;

        if(val!=adj[vertex].size())

        {

            flag=true;

        }

        for(auto i:adj[vertex])

        {

            if(!visited[i])

            {

                dfs(i,adj,val,flag,visited,cv);

            }

        }

    }

    int findNumberOfGoodComponent(int V, vector<vector<int>>& adj) {

        

        vector<int> visited(V+1,0);

        int count=0;

        for(int i=1;i<=V;i++)

        {

            if(!visited[i])

            {

                int flag=false;

                int cv=0;

                dfs(i,adj,adj[i].size(),flag,visited,cv);

                

                if(!flag && cv==adj[i].size()+1)

                {

                    count++;

                }

            }

        }

        return count;

    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int E, V;
        cin >> E >> V;
        vector<vector<int>> adj(V + 1, vector<int>());
        for (int i = 0; i < E; i++) {
            int u, v;

            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;

        int res = obj.findNumberOfGoodComponent(V, adj);
        cout << res << "\n";
    }
    return 0;
}
// } Driver Code Ends