//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        // code here 
        S+='.'; int cnt=0;
        for(int i=0;i<S.size();i++){
            if(S[i]=='.'){
                cnt++;
            }
        }
        vector<string>v(cnt); string str=""; int p=0;
        for(int i=0;i<S.size();i++){
            if(S[i]=='.'){
                v[cnt-(p+1)]=str;
                str.clear();
                p++;
            }
            else{
                str+=S[i];
            }
        }
        string ans="";
        for(int i=0;i<v.size();i++){
            ans+=v[i];
            ans.push_back('.');
        }
        ans.pop_back();
        return ans;
        
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends