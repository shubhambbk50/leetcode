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
    int equalSum(int N, vector<int> &A) {
        // code here
        int totalSum = 0;
    int leftSum = 0;
    
    // Loop through the array A and add each element to the totalSum variable
    // This computes the total sum of all elements in the array
    for (int i = 0; i < N; i++) {
        totalSum += A[i];
    }
    
    // Loop through the array A again
    for (int i = 0; i < N; i++) {
        /* Check if the sum of elements on the left side of the current index is equal to the 
        sum of elements on the right side of the current index
        This is done by checking if leftSum is equal to totalSum - leftSum - A[i], 
        where A[i] is the current element and i is the current index*/
        if (leftSum == totalSum - leftSum - A[i]) {
            // If such an index is found, return i+1, which is the index with 1-based indexing
            return i+1;
        }
        // Update leftSum by adding the current element to it
        leftSum += A[i];
    }
    
    // If no such index is found, return -1
    return -1;
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
        int res = obj.equalSum(N, A);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends