//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    vector<int> getDistinctDifference(int N, vector<int> &A) {
        // code here
        unordered_set<int> left;
        unordered_map<int,int>right;
        
        for(int i=0;i<N;i++)
         right[A[i]]++;
        
        vector<int> ans;
        for(int i=0;i<N;i++) {
            
            if(right.find(A[i])!=right.end())
            {
                right[A[i]]--;
                if(right[A[i]]==0)
                right.erase(A[i]);
            }
            
            int a=left.size()-right.size();
            ans.push_back(a);
            
            left.insert(A[i]);
        } 
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        Array::input(A,N);
        
        Solution obj;
        vector<int> res = obj.getDistinctDifference(N, A);
        
        Array::print(res);
        
    }
}

// } Driver Code Ends