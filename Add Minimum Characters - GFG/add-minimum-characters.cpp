//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    bool pallindrome(string str)
    {
        for(int i=0;i<str.length()/2;i++)
        if(str[i]!=str[str.length()-1-i])return false;
        return true;
    }
    int addMinChar(string str){    
       if(pallindrome(str))
       return 0;
       
       int ind1=0,cnt=0;

       for(int j=0;j<str.length();j++)
       {
              if(str[j]==str[ind1])
              {
                  if(pallindrome(str.substr(ind1,j+1)))
                  cnt=j+1;
              }
       }
       

       return str.length()-cnt;
    }
};

//{ Driver Code Starts.


int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin >> str;
        
        Solution ob;
        cout << ob.addMinChar(str) << endl;
    }
    return 0; 
} 
// } Driver Code Ends