//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    vector<int> nearestSmallerTower(vector<int> arr)
    {
        // code here
         int n = arr.size();
        vector<int>left(n);
        vector<int>right(n);
        stack<int>st;
        
        for(int i =0;i<n;i++){
            if(st.empty()){
                left[i]=-1;
                st.push(i);
            }else{
                while(!st.empty()){
                    if(arr[i]<=arr[st.top()]){
                        st.pop();
                    }else{
                        break;
                    }
                }
                if(st.empty()){
                    left[i]=-1;
                }else{
                    left[i]=st.top();
                }
                st.push(i);
            }
        }
        while(!st.empty()){
            st.pop();
        }
        
        for(int i =n-1;i>=0;i--){
            if(st.empty()){
                right[i]=-1;
                st.push(i);
            }else{
                while(!st.empty()){
                    if(arr[i]<=arr[st.top()]){
                        st.pop();
                    }else{
                        break;
                    }
                }
                if(st.empty()){
                    right[i]=-1;
                }else{
                    right[i]=st.top();
                }
                st.push(i);
            }
        }
        
        vector<int>ans;
        for(int i =0;i<n;i++){
            if(left[i]==-1 && right[i]==-1){
                ans.push_back(-1);
            }else if(left[i]==-1 && right[i]!=-1){
                ans.push_back(right[i]);
            }else if(right[i]==-1 && left[i]!=-1){
                ans.push_back(left[i]);
            }else{
                if(abs(i-left[i])==abs(right[i]-i)){
                    if(arr[left[i]]==arr[right[i]]){
                        ans.push_back(left[i]);
                    }else if(arr[left[i]]>arr[right[i]]){
                        ans.push_back(right[i]);
                    }else if(arr[left[i]]<arr[right[i]]){
                        ans.push_back(left[i]);
                    }
                }else{
                    if(abs(i-left[i])<abs(i-right[i])){
                        ans.push_back(left[i]);
                    }else{
                        ans.push_back(right[i]);
                    }
                }
            }
        }
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
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution ob;
        vector<int> ans = ob.nearestSmallerTower(v);
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends