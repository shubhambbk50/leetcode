//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> makeBeautiful(vector<int> arr) {
        // code here
        vector<int>res;
        for(int i=0 ; i<arr.size() ; i++){
            res.push_back(arr[i]);
        }
        int i=0;
        while(i<res.size()){
            if(i+1<res.size()){
                if((res[i]>=0 && res[i+1]<0) || (res[i]<0 && res[i+1]>=0)){
                    res.erase(res.begin()+i);
                    res.erase(res.begin()+i);
                    if(i!=0)i--;
                }
                else{
                    i=i+1;
                }
            }
            else{
                    i=i+1;
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        Solution obj;
        vector<int> res = obj.makeBeautiful(arr);
        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }

        cout << "\n";
    }
}
// } Driver Code Ends