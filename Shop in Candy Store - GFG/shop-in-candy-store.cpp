//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        sort(candies,candies+N);
        int left=0, right=N-1, sum1=0;
        while(left<=right){
            sum1+=candies[left];
            left++;
            right-=K;
        }
        sort(candies,candies+N,greater<int>());
        left=0, right=N-1;int sum2=0;
        while(left<=right){
            sum2+=candies[left];
            left++;
            right-=K;
        }
        return {sum1,sum2};
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}
// } Driver Code Ends