//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution

{

    

  public:

  

  long long solve(int p,vector<int> Edge)

  {

      long long sum=p;

      int s=p;

      p=Edge[s];

      

      while(p!=s)

      {

          sum+=p;

          p=Edge[p];

      }

      

      return sum;

      

      

  }

  

  

  long long largestSumCycle(int N, vector<int> Edge)

  {

      

      

    bool visited[N];

    for(int i=0;i<N;i++)

    {

        visited[i]=false;

    }

    

    long long ans=0;

    

    

    for(int i=0;i<Edge.size();i++)

    {

        

        

        if(!visited[i])

        {

            

            unordered_set<int> s;

            //s.clear();

            visited[i]=true;

            s.insert(i);

            int p=Edge[i];

            bool flag=true;

            

            while(s.find(p)==s.end())

            {

                if(p==-1 || visited[p])

                {

                    flag=false;

                    break;

                }

                visited[p]=true;

                s.insert(p);

                p=Edge[p];

            }

            

            if(flag)

            {

                ans=max(solve(p,Edge),ans);

            }

            

            

            

            

            

        }

        

        

    }

    

    if(ans==0)

    {

        return -1;

    }

    

    return ans;

    

    

    

  }

};

//{ Driver Code Starts.
signed main(){
   int tc;
   cin >> tc;
   while(tc--){
      int N;
      cin >> N;
      vector<int> Edge(N);
      for(int i=0;i<N;i++){
        cin>>Edge[i];
      }
      Solution obj;
      long long ans=obj.largestSumCycle(N, Edge);
      cout<<ans<<endl;
   }
   return 0;
}
// } Driver Code Ends