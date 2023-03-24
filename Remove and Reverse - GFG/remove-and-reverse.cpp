//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    string removeReverse(const string &s) {
        
        array<uint32_t, 128> counter;
        counter.fill(0);
        
        const size_t s_len = s.size();
        vector<bool> included(s_len, true);
        
        std::for_each(s.cbegin(), s.cend(), [&](const char c){ counter[c] += 1; });
        
        size_t left = 0;
        size_t right = s_len - 1;
        bool rev = false;
        
        while(left <= right) {
            const char first = s[left];
            const char last = s[right];
            
            if(!rev) {
                if(counter[first] > 1) {
                    --counter[first];
                    rev = !rev;
                    included[left] = false;
                }
                ++left;
            } else {
                if(counter[last] > 1) {
                    --counter[last];
                    rev = !rev;
                    included[right] = false;
                }
                --right;
            }
        }
        
        string res;
        res.reserve(s_len);
        for(size_t i = 0; i < s_len; ++i) {
            if(included[i]) {
                res += s[i];
            }
        }
        
        
        if(rev) {
            std::reverse(res.begin(), res.end());
        }
        
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        Solution obj;
        auto ans = obj.removeReverse(S);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends